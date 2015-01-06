#include "mainwindow.h"
#include <QApplication>
#include <QDir>
#include <QGuiApplication>
#include <QQmlEngine>
#include <QQmlFileSelector>
#include <QQuickView>

#include "EldersExpression/eldersexpression.h"

void test(MainWindow *pW)
{
    pW->getWidget()->loadMap(1, ":/maps/map/HAHA_8 V2.2.m++");
}

int main(int argc, char *argv[])
{
    //QGuiApplication a(argc,argv);

    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    test(&w);

    //return a.exec();
    /*QDeclarativeView view;
    QDeclarativeContext *context = view.rootContext();
    view.setSource(QUrl::fromLocalFile("MainWindowNew.qml"));
    view.show();*/
    /*QQuickView view;\
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

    return app.exec();\*/

    //QQuickView view;
    //view.setSource(QUrl("qrc:/UI/MainWindowNew.qml"));
    //view.show();
    return a.exec();
    //QObject *object = view.rootObject();

}

