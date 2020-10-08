#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
}

int TableModel::rowCount(const QModelIndex &) const
{
    return 10;
}

int TableModel::columnCount(const QModelIndex &) const
{
    return 3;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole
            && index.row() >= 0
            && index.row() < rowCount()
            && index.column() >= 0
            && index.column() < columnCount())
        return QString("Some text");
    return QVariant();
}
