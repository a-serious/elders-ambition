#include "eldersreference.h"
#include "eldersexpression.h"
#include "../eldersobject.h"
#include "EldersAnimate/eldersinputbox.h"

#include <QList>

EldersReference::EldersReference(QString Label, QString Id, QList<QString> Class, QString property)
{
    objectLabel = Label, objectId = Id, objectClass = Class, this->property = property;
}

EldersVarient EldersReference::getValue(EldersMap *map)
{
    if (objectLabel == "this")
        return (*(EldersExpression::environment))[property];

    if (objectLabel == "input")
    {
        int len = property.length();
        QStringList l = property.mid(1, len - 2).split(QRegExp("\\\"\\s*,\\s*\\\""));
        for (auto i = l.begin(); i != l.end(); i++)
            if ((*i).startsWith("\""))
                i = l.erase(i);

        QString message = *l.begin();
        l.erase(l.begin());

        map->appendAnimate(new EldersInputBox(map, message, l), true);
        return (*map)["input"];
    }

    QList<EldersObject *>target = map->findDisplayObject(objectLabel, objectId, objectClass);
    if (!target.empty())
        return (*target.first())[property];
    else
    {
        QString err = "<EldersReference::getValue(EldersMap *)> Cannot find object : " + objectLabel + (objectId != "" ? "#" + objectId : "");// + (objectClass != "" ? "." + objectClass : "");
        throw err;
    }
}

#include <QDebug>

EldersVarient EldersReference::setValue(EldersVarient x, EldersMap *map)
{
    if (objectLabel == "this")
    {
        (EldersExpression::environment)->setProperty(property, x);
        return x;
    }

    QList<EldersObject *>target = map->findDisplayObject(objectLabel, objectId, objectClass);
    if (!target.empty())
        for (QList<EldersObject *>::iterator i = target.begin(); i != target.end(); i++)
            (*i)->setProperty(property, x);
    else
    {
        QString err = "<EldersReference::setValue(EldersMap *)> Cannot find object : " + objectLabel + (objectId != "" ? "#" + objectId : "");// + (objectClass != "" ? "." + objectClass : "");
        throw err;
    }
    return x;
}
