#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "widget.h"
#include "eldersbacksound.h"
#include "eldersmap.h"
#include "status.h"

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Widget *mWidget;
    Status *mStatus;

    void createMenus();
    QMenu *fileMenu;
    QMenu *settingMenu;
    QMenu *difficultyMenu;
    QMenu *helpMenu;

    QAction *openAct;
    QAction *saveAct;
    QAction *loadAct;
    QAction *exitAct;

    QAction *hardAct;
    QAction *mediumAct;
    QAction *easyAct;
    QAction *propertyAct;

    QAction *manualAct;
    QAction *aboutAct;

private slots:
    void open();
    void save();
    void load();
    void hard();
    void medium();
    void easy();
    void property();
    void manual();
    void about();

public:
    MainWindow(QWidget *parent = 0);
    QTimer *timer;
    EldersMap *getMap();
    Widget *getWidget();

    ~MainWindow();
    void keyPressEvent(QKeyEvent *);
};

#endif // MAINWINDOW_H
