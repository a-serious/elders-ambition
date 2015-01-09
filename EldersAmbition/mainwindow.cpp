#include "mainwindow.h"
#include "widget.h"
#include "EldersAnimate/eldersmessage.h"

#include <QGridLayout>
#include <QLabel>
#include <QMenuBar>
#include <QFileDialog>
#include <QFontDatabase>
#include <QDeclarativeView>
#include <QQuickView>
#include <QProcess>
#include <QDebug>
#include <QDesktopServices>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("长者的野望"));

    mapFileName = ":/maps/map/HAHA_8 V2.2 - medium.m++";

    this->setFixedSize(800, 600);

    createMenus();

    mWidget = new Widget(this);
    mStatus = new Status(mWidget->getMap(), this);
    //QWidget *testWidget = new QWidget(this);
    //ymj
    //QDeclarativeView *View = new QDeclarativeView;
    //View->setSource(QUrl("qrc:/UI/MainWindowNew.qml"));
    //View->show();

    //QWidget *widgetNew = new QWidget(this);
    //QVBoxLayout *layout = new QVBoxLayout(widget);
    //widget->addWidget(qmlView);
    //ymj

    //ymj
    this->setAutoFillBackground(true); // 这句要加上, 否则可能显示不出背景图.
    QPalette palette = this->palette();
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/assets/Images/backgroundV1.3.jpg").scaled(
                this->size(),Qt::IgnoreAspectRatio,Qt::SmoothTransformation))); // 使用平滑的缩放方式
    this->setPalette(palette); // 至此, 已给widget加上了背景图.
    //ymj

    QGridLayout *layout = new QGridLayout;
    //layout->addWidget(View);//ymj
    layout->addWidget(mWidget, 0, 1);//ymj
    layout->addWidget(mStatus, 0, 0);//ymj
    //layout->addWidget(testWidget, 0, 2);

    layout->setContentsMargins(2,10,0,0);//ymj
    layout->setSpacing(22);

    QWidget *widget = new QWidget(this);

    widget->setLayout(layout);

    //widget->addWidget(qmlView);//ymj

    setCentralWidget(widget);

    QFontDatabase::addApplicationFont(":/fonts/微软雅黑");

    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), mWidget, SLOT(animate()));
    connect(timer, SIGNAL(timeout()), mStatus, SLOT(animate()));
    timer->start(20);
}

void MainWindow::createMenus()
{
    openAct = new QAction(tr("读取地图(&M)"), this);
    saveAct = new QAction(tr("存档(&S)"), this);
    loadAct = new QAction(tr("读档(&R)"), this);
    rechargeAct = new QAction(tr("充值(&C)"), this);
    exitAct = new QAction(tr("退出(&E)"), this);

    restartAct = new QAction(tr("重新开始(&L)"), this);
    hardAct = new QAction(tr("困难"), this);
    mediumAct = new QAction(tr("中等"), this);
    easyAct = new QAction(tr("简单"), this);
    foresoundAct = new QAction(tr("音效开关(&O)"), this);

    manualAct = new QAction(tr("用户手册(&U)"), this);
    aboutAct = new QAction(tr("关于(&A)"), this);

    fileMenu = menuBar()->addMenu(tr("文件(&F)"));
    settingMenu = menuBar()->addMenu(tr("游戏设置(&G)"));
    helpMenu = menuBar()->addMenu(tr("帮助(&H)"));

    fileMenu->addAction(openAct);
    openAct->setShortcut(QKeySequence("Ctrl+m"));
    fileMenu->addSeparator();
    fileMenu->addAction(saveAct);
    saveAct->setShortcut(QKeySequence("Ctrl+s"));
    fileMenu->addAction(loadAct);
    loadAct->setShortcut(QKeySequence("Ctrl+r"));
    fileMenu->addSeparator();
    fileMenu->addAction(rechargeAct);
    rechargeAct->setShortcut(QKeySequence("Ctrl+c"));
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    exitAct->setShortcut(QKeySequence("Ctrl+e"));

    settingMenu->addAction(restartAct);
    restartAct->setShortcut(QKeySequence("Ctrl+l"));
    settingMenu->addSeparator();
    difficultyMenu = settingMenu->addMenu(tr("选择难度(&D)"));
    settingMenu->addSeparator();
    settingMenu->addAction(foresoundAct);
    foresoundAct->setCheckable(true);
    foresoundAct->setChecked(true);
    foresoundAct->setShortcut(QKeySequence("Ctrl+o"));

    difficultyMenu->addAction(hardAct);
    hardAct->setCheckable(true);
    hardAct->setChecked(false);
    difficultyMenu->addAction(mediumAct);
    mediumAct->setCheckable(true);
    mediumAct->setChecked(true);
    difficultyMenu->addAction(easyAct);
    easyAct->setCheckable(true);
    easyAct->setChecked(false);

    helpMenu->addAction(manualAct);
    manualAct->setShortcut(QKeySequence("Ctrl+u"));
    helpMenu->addAction(aboutAct);
    aboutAct->setShortcut(QKeySequence("Ctrl+a"));

    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(load()));
    connect(rechargeAct, SIGNAL(triggered()),this, SLOT(recharge()));

    connect(restartAct, SIGNAL(triggered()), this, SLOT(restart()));
    connect(hardAct, SIGNAL(triggered()), this, SLOT(hard()));
    connect(mediumAct, SIGNAL(triggered()), this, SLOT(medium()));
    connect(easyAct, SIGNAL(triggered()), this, SLOT(easy()));
    connect(foresoundAct, SIGNAL(triggered()), this, SLOT(foresound()));

    connect(manualAct, SIGNAL(triggered()), this, SLOT(manual()));
    connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("打开地图文件"), "", tr("Elders Map++ (*.m++)"));
    mapFileName = filename;
    isRecord = false;
    mediumAct->setChecked(false);
    easyAct->setChecked(false);
    hardAct->setChecked(false);
    mWidget->loadMap((int)foresoundAct->isChecked(), filename);
}

void MainWindow::save()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("选择保存位置"), "save0.rec", tr("Elders Record (*.rec)"));
    if (filename.isEmpty())
        return;
    try
    {
        mWidget->saveRec(filename);
    }
    catch (const char *e)
    {
        mWidget->getMap()->appendAnimate(new EldersMessage(mWidget->getMap(), QString(e)), false);
    }
}

void MainWindow::load()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("打开存档文件"), "save0.rec", tr("Elders Record (*.rec)"));
    if (filename.isEmpty())
        return;
    mapFileName = filename;
    isRecord = true;
    mediumAct->setChecked(false);
    easyAct->setChecked(false);
    hardAct->setChecked(false);
    mWidget->loadRec((int)foresoundAct->isChecked(), filename);
}

void MainWindow::recharge()
{
    (getMap()->Tom())->property["RMB"] = (getMap()->Tom())->property["RMB"]+50;
}

void MainWindow::restart()
{
    if(isRecord)
        mWidget->loadRec((int)foresoundAct->isChecked(), mapFileName);
    else
        mWidget->loadMap((int)foresoundAct->isChecked(), mapFileName);
}

void MainWindow::hard(){
    if(!hardAct->isChecked())
    {
        hardAct->setChecked(true);
        return;
    }
    mediumAct->setChecked(false);
    easyAct->setChecked(false);
    mapFileName = ":/maps/map/HAHA_8 V2.2 - hard.m++";
    isRecord = false;
    mWidget->loadMap((int)foresoundAct->isChecked(), ":/maps/map/HAHA_8 V2.2 - hard.m++");
}

void MainWindow::medium(){
    if(!mediumAct->isChecked())
    {
        mediumAct->setChecked(true);
        return;
    }
    hardAct->setChecked(false);
    easyAct->setChecked(false);
    mapFileName = ":/maps/map/HAHA_8 V2.2 - medium.m++";
    isRecord = false;
    mWidget->loadMap((int)foresoundAct->isChecked(), ":/maps/map/HAHA_8 V2.2 - medium.m++");
}

void MainWindow::easy()
{
    if(!easyAct->isChecked())
    {
        easyAct->setChecked(true);
        return;
    }
    hardAct->setChecked(false);
    mediumAct->setChecked(false);
    mapFileName = ":/maps/map/HAHA_8 V2.2 - easy.m++";
    isRecord = false;
    mWidget->loadMap((int)foresoundAct->isChecked(), ":/maps/map/HAHA_8 V2.2 - easy.m++");
}

void MainWindow::foresound()
{
    if(foresoundAct->isChecked())
        getMap()->foreSoundEnabled = true;
    else
        getMap()->foreSoundEnabled = false;
}

void MainWindow::manual()
{
    QDesktopServices::openUrl(QUrl("file:///d:/1.pdf"));
    //QProcess* process = new QProcess();
    //QString pdf = "start acrord32";
    //qDebug() << pdf << endl;
        //process->start(pdf);
    //TODO
}

void MainWindow::about()
{
    //TODO
}

EldersMap *MainWindow::getMap()
{
    return mWidget->getMap();
}

Widget *MainWindow::getWidget()
{
    return mWidget;
}

MainWindow::~MainWindow()
{
}

void MainWindow::keyPressEvent(QKeyEvent *e)
{
    mWidget->keyPressEvent(e);
}
