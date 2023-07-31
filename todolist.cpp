#include "todolist.h"
#include "QtCore/qdebug.h"

ToDoList::ToDoList(QObject *parent): QObject(parent)
{
    m_data.append({QStringLiteral("Buy")});
//    m_data.push_back(Data("Buy"));
    }

QVector<Data> ToDoList::data() const
{
    qDebug()<<m_data.data();
    return m_data;
}

bool ToDoList::setItemAt(int index, const Data &data)
{
    if(index < 0 || index>m_data.size()){
        return false;
    }
    m_data[index] = data;
    qDebug()<<&m_data[index];
    return true;

}

void ToDoList::appendItem()
{
    emit preItemAppended();

    Data newItem;
//    newItem.toDo = "grocery";
    m_data.append(newItem);

    emit postItemAppended();
}

void ToDoList::removeCompletedItems()
{

}
