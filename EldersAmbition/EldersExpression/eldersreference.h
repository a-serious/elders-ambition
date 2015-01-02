#ifndef ELDERSREFERENCE_H
#define ELDERSREFERENCE_H

#include "eldersoperand.h"

#include <QString>
#include <QList>

class EldersReference : public EldersOperand
{
    QString objectLabel, objectId, property;
    QList<QString> objectClass;

public:
    EldersReference(QString, QString, QList<QString>, QString);

    virtual EldersVarient getValue(EldersMap *);
    EldersVarient setValue(EldersVarient, EldersMap *);
};

#endif // ELDERSREFERENCE_H
