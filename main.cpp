#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>

#include <listmodel.h>
#include "alertmodel.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

    AlertListModel *myModel = new AlertListModel();
    AlertItem *myItem = new AlertItem("0","1/1/2021","Secteur Nord",false);
    myModel->appendRow(myItem);

    AlertItem *myItem2 = new AlertItem("1","2/1/2021","Secteur Sud",true);
    myModel->appendRow(myItem2);

    QQmlContext *ctxt = engine.rootContext();
    ctxt->setContextProperty("alertModel", QVariant::fromValue(myModel));

    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
                     &app, [url](QObject *obj, const QUrl &objUrl) {
        if (!obj && url == objUrl)
            QCoreApplication::exit(-1);
    }, Qt::QueuedConnection);
    engine.load(url);

    return app.exec();
}
