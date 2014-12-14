#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>

#include "MagicExpression/magicexpression.h"

void test(MainWindow *pW)
{
    pW->getWidget()->loadMap(":/maps/beta");
}

int main(int argc, char *argv[])
{
    QGuiApplication app(argc,argv);
    /*MainWindow w;
    w.show();

    test(&w);*/
    /*QDeclarativeView view;
    QDeclarativeContext *context = view.rootContext();
    view.setSource(QUrl::fromLocalFile("MainWindowNew.qml"));
    view.show();*/
    QQuickView view;\
    if (qgetenv("QT_QUICK_CORE_PROFILE").toInt()) {\
        QSurfaceFormat f = view.format();\
        f.setProfile(QSurfaceFormat::CoreProfile);\
        f.setVersion(4, 4);\
        view.setFormat(f);\
    }\
    view.connect(view.engine(), SIGNAL(quit()), &app, SLOT(quit()));\
    new QQmlFileSelector(view.engine(), &view);\
    view.setSource(QUrl("qrc:/UI/MainWindowNew.qml")); \
    view.setResizeMode(QQuickView::SizeRootObjectToView);\
    view.show();\

    return app.exec();\
}

