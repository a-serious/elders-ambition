#ifndef ELDERSHELPER_H
#define ELDERSHELPER_H

class EldersMap;

#include "eldersdisplayobject.h"

#include <QString>
#include <QHash>

class EldersHelper
{
    static QHash<QString, QString> alias;

public:
    static EldersDisplayObject *createObject(QString, QString, QList<QString>, int, int, int, EldersMap *);
};

#endif // ELDERSHELPER_H
