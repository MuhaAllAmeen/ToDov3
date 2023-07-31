#include "todomodel.h"
#include "todolist.h"

ToDoModel::ToDoModel(QObject *parent)
    : QAbstractListModel(parent),mList(nullptr)
{
}




int ToDoModel::rowCount(const QModelIndex &parent) const
{
    // For list models only the root node (an invalid parent) should return the list's size. For all
    // other (valid) parents, rowCount() should return 0 so that it does not become a tree model.
    if (parent.isValid() || !mList)
        return 0;
    return mList->data().size();
    // FIXME: Implement me!
}




QVariant ToDoModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || !mList)
        return QVariant();

    const Data data = mList->data().at(index.row());
    if (role==DescriptionRole){
        qDebug()<<role;
        return QVariant(data.toDo);
    }
    return QVariant();
}

bool ToDoModel::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!mList){return false;}
    Data data = mList->data().at(index.row());
    if (role==DescriptionRole){
        data.toDo = value.toString();
    }
    if (mList->setItemAt(index.row(),data)) {
        // FIXME: Implement me!
        emit dataChanged(index, index, QVector<int>() << role);
        return true;
    }
    return false;
}

Qt::ItemFlags ToDoModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;

    return QAbstractItemModel::flags(index) | Qt::ItemIsEditable; // FIXME: Implement me!
}

QHash<int, QByteArray> ToDoModel::roleNames() const
{
    QHash <int,QByteArray> mapped;
    mapped[DescriptionRole]="toDo";
    return mapped;
}

ToDoList *ToDoModel::list() const
{
    return mList;
}

void ToDoModel::setList(ToDoList *list)
{
    beginResetModel();
    if(mList){
        mList->disconnect(this);
    }
    mList = list;
    if (mList){
        connect(mList, &ToDoList::preItemAppended,this,[=](){
            const int index = mList->data().size();
            beginInsertRows(QModelIndex(),index,index);
        });
        connect(mList, &ToDoList::postItemAppended,this,[=](){
            endInsertRows();
        });
        connect(mList, &ToDoList::preItemRemoved,this,[=](int index){
            beginRemoveRows(QModelIndex(),index,index);
        });
        connect(mList, &ToDoList::postItemRemoved,this,[=](){
            endRemoveRows();
        });
    }
    endResetModel();
}


