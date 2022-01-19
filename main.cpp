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

    int vals[] {1, 2, 3, 4, 5};

        for (auto val : vals) {

            AlertItem *myItem = new AlertItem(QString::number(val),"Secteur Nord",false);
            myModel->appendRow(myItem);
        }

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
