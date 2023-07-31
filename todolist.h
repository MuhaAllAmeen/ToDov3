#ifndef TODOLIST_H
#define TODOLIST_H

#include <QObject>

struct Data{
//    Data(){}
//    Data(const QString(&toDo)):toDo(toDo){}
    QString toDo;

};
class ToDoList : public QObject
{
    Q_OBJECT
public:
    explicit ToDoList(QObject *parent =0);
    QVector <Data> data() const;
    bool setItemAt (int index, const Data &data);
signals:
    void preItemAppended();
    void postItemAppended();

    void preItemRemoved(int index);
    void postItemRemoved();

public slots:
    void appendItem();
    void removeCompletedItems();
private:
    QVector<Data> m_data;
};

#endif // TODOLIST_H
