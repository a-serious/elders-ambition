
#ifndef WIDGET_H
#define WIDGET_H

#include "eldersmap.h"

#include <QWidget>
#include <QString>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent);
    void keyPressEvent(QKeyEvent *);
    EldersMap *getMap();
    void loadMap(QString);
    void saveRec(QString);
    void loadRec(QString);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    EldersMap *mMap;
    QString mapToLoad;
    QString recToLoad;
    QString recToSave;
};

#endif
