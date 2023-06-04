#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "back_end.h"
#include "to_do_list.h"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;
    const QUrl url(QStringLiteral("qrc:/main.qml"));

// load backend
    qmlRegisterType<BackEnd>("tungpt.BackEnd", 1, 0, "BackEnd");
    qmlRegisterType<ToDoList>("tungpt.ToDoList", 1, 0, "ToDoList");


    QObject::connect(&engine, &QQmlApplicationEngine::objectCreated,
        &app, [url](QObject *obj, const QUrl &objUrl) {
            if (!obj && url == objUrl)
                QCoreApplication::exit(-1);
        }, Qt::QueuedConnection);

//    qmlRegisterType<TodoModel>("dientului.TodoModel",1,0,"TodoModel");

    engine.load(url);

    return app.exec();
}
