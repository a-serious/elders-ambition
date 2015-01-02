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

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    setWindowTitle(tr("Elders Tower"));

    this->resize(800, 600);

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
    palette.setBrush(QPalette::Window, QBrush(QPixmap(":/images/assets/Images/UIDesignV1.3.jpg").scaled(
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
    openAct = new QAction(tr("Load &Map"), this);
    saveAct = new QAction(tr("&Save record"), this);
    loadAct = new QAction(tr("L&oad record"), this);
    exitAct = new QAction(tr("E&xit"), this);

    fileMenu = menuBar()->addMenu(tr("&Elders Tower"));
    fileMenu->addAction(openAct);
    openAct->setShortcut(QKeySequence("Ctrl+m"));
    fileMenu->addSeparator();
    fileMenu->addAction(saveAct);
    saveAct->setShortcut(QKeySequence("Ctrl+s"));
    fileMenu->addAction(loadAct);
    loadAct->setShortcut(QKeySequence("Ctrl+o"));
    fileMenu->addSeparator();
    fileMenu->addAction(exitAct);
    exitAct->setShortcut(QKeySequence("Ctrl+w"));

    connect(exitAct, SIGNAL(triggered()), this, SLOT(close()));
    connect(openAct, SIGNAL(triggered()), this, SLOT(open()));
    connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));
    connect(loadAct, SIGNAL(triggered()), this, SLOT(load()));
}

void MainWindow::open()
{
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "", tr("Elders Map++ (*.m++)"));
    mWidget->loadMap(filename);
}

void MainWindow::save()
{
    QString filename = QFileDialog::getSaveFileName(this, tr("Open File"), "save0.rec", tr("Elders Record (*.rec)"));
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
    QString filename = QFileDialog::getOpenFileName(this, tr("Open File"), "save0.rec", tr("Elders Record (*.rec)"));
    if (filename.isEmpty())
        return;
    mWidget->loadRec(filename);
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
