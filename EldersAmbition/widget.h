
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
    void loadMap(int foreSound, QString);
    void saveRec(QString);
    void loadRec(int foreSound, QString);

public slots:
    void animate();

protected:
    void paintEvent(QPaintEvent *event);

private:
    EldersMap *mMap;
    QString mapToLoad;
    QString recToLoad;
    QString recToSave;
    int foreSoundEnabled = 1;
};

#endif
