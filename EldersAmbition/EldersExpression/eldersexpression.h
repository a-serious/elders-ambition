#ifndef ELDERSEXPRESSION_H
#define ELDERSEXPRESSION_H

#include "../eldersmap.h"
#include "eldersoperation.h"

#include <QStack>
#include <QFile>
#include <QStringList>
#include <QTextStream>

class EldersExpression // forgot: why EldersHalt...
{
    static void goForIt(QString, EldersMap *, QTextStream *);
    static void initAll();
    static EldersExpression *final();

public:
    EldersExpression *next;
    EldersExpression();
    virtual void run(EldersMap *);
    virtual void setNext(EldersExpression *);

    static EldersExpression *input(QString, EldersMap *);
    static void process(QTextStream &, int, EldersMap *);

    static EldersDisplayObject *environment;
    static void setEnvironment(EldersDisplayObject *);

    static QStringList onList, atList;
};

#endif // ELDERSEXPRESSION_H
