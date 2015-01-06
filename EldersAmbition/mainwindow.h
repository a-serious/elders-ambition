#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "widget.h"
#include "eldersbacksound.h"
#include "eldersmap.h"
#include "status.h"

#include <QMainWindow>
#include <QTimer>
#include <QKeyEvent>
#include <QString>

class MainWindow : public QMainWindow
{
    Q_OBJECT

    Widget *mWidget;
    Status *mStatus;

    void createMenus();
    QMenu *fileMenu;//文件
    QMenu *settingMenu;//游戏设置
    QMenu *difficultyMenu;//选择难度
    QMenu *helpMenu;//帮助

    QAction *openAct;//打开地图
    QAction *saveAct;//存档
    QAction *loadAct;//读档
    QAction *rechargeAct;//充值
    QAction *exitAct;//退出

    QAction *restartAct;//重新开始
    QAction *hardAct;//高难度
    QAction *mediumAct;//中难度
    QAction *easyAct;//低难度
    QAction *foresoundAct;//音效开关

    QAction *manualAct;//用户手册
    QAction *aboutAct;//关于

    QString mapFileName;
    bool isRecord;

private slots:
    void open();
    void save();
    void load();
    void recharge();
    void restart();
    void hard();
    void medium();
    void easy();
    void foresound();
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
