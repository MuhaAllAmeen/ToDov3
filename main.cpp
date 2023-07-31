#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "todomodel.h"
#include "todolist.h"
#include <QQmlContext>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
    QGuiApplication app(argc, argv);

    qmlRegisterType<ToDoModel>("ToDo", 1, 0, "ToDoModel");
    qmlRegisterUncreatableType<ToDoList>("ToDo", 1, 0, "ToDoList",
                                         QStringLiteral("ToDoList should not be created in QML"));

    ToDoList toDoList;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QStringLiteral("toDoList"), &toDoList);
    engine.load(QUrl(QLatin1String("qrc:/ToDov3/Main.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
//qrc:/ToDov3/Main.qml
