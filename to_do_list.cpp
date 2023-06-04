#include "to_do_list.h"
#include <QModelIndex>
#include <QDebug>

ToDoItem::ToDoItem(const QString &content, const bool &isDone)
{
    m_content = content;
    m_isDone = isDone;
}

QString ToDoItem::content() const
{
    return m_content;
}

bool ToDoItem::isDone() const
{
    return m_isDone;
}

bool ToDoItem::setContent(const QString &content)
{
    m_content = content;
    return true;
}

bool ToDoItem::setIsDone(const bool &isDone)
{
    m_isDone = isDone;
    return true;
}

ToDoList::ToDoList(QObject *parent):
    QAbstractListModel(parent)
{
    m_ToDoList.append(ToDoItem("abs", false));
    m_ToDoList.append(ToDoItem("xyz", true));
}

int ToDoList::rowCount(const QModelIndex &parent) const
{
    return m_ToDoList.length();
}

QVariant ToDoList::data(const QModelIndex &index, int role) const
{
    if(!index.isValid()){
        return QVariant();
    }

    const ToDoItem &item = m_ToDoList[index.row()];
    switch (role) {
    case ContentRole:
        return item.content();
    case IsDoneRole:
        return item.isDone();
    default:
        return QVariant();
    }
}

bool ToDoList::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (!index.isValid()){
        return false;
    }

    ToDoItem &item = m_ToDoList[index.row()];
    switch (role) {
    case ContentRole:
        return item.setContent(value.toString());
    case IsDoneRole:
        return item.setIsDone(value.toBool());
    default:
        return false;
    }
}

void ToDoList::addItem()
{
    beginInsertRows(QModelIndex(), rowCount(QModelIndex()), rowCount(QModelIndex()));
    m_ToDoList.append(ToDoItem("", true));
    //qDebug() << rowCount(QModelIndex());
    endInsertRows();
}

void ToDoList::removeItem(const int &index)
{
    beginRemoveRows(QModelIndex(), index, index);
    m_ToDoList.remove(index, 1);
    endRemoveRows();
}

QHash<int, QByteArray> ToDoList::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[ContentRole] = "noidung";
    roles[IsDoneRole] = "trangthai";
    return roles;
}
