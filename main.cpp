#include <QApplication>
#include <QQmlApplicationEngine>
#include <appcontroller.h>
#include <QQmlContext>
#include <QIcon>

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    app.setWindowIcon(QIcon(":/assets/logo.png"));
    QQmlApplicationEngine engine;
    AppController controller;

    engine.rootContext()->setContextProperty("appController", &controller);

    QObject::connect(
        &engine,
        &QQmlApplicationEngine::objectCreationFailed,
        &app,
        []() { QCoreApplication::exit(-1); },
        Qt::QueuedConnection);
    engine.loadFromModule("PhotoSpinner", "Main");

    return app.exec();
}
