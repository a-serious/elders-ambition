#ifndef ELDERSOBJECT_H
#define ELDERSOBJECT_H

class EldersMap;

#include "EldersExpression/eldersvarient.h"

#include <QHash>
#include <QSet>
#include <QVariant>
#include <QObject>
#include <QTextStream>

class EldersObject
{
    QSet<QString> mClass;

public:
    EldersObject();

    QHash<QString, EldersVarient> property;

    bool inClass(QString);
    bool inClass(QList<QString>);
    void appendClass(QString);
    void appendClass(QList<QString>);

    virtual EldersVarient &operator[](QString);
    virtual const EldersVarient &operator[](QString) const;
    virtual void setProperty(QString, EldersVarient, bool = true);

    void saveProperty(QTextStream *);
    void loadProperty(QTextStream *, EldersMap * = NULL);
};

#endif // ELDERSOBJECT_H
