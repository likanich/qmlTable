#include "tablemodel.h"

TableModel::TableModel(QObject *parent)
    : QAbstractTableModel(parent)
{
    readFromFile();
}

int TableModel::rowCount(const QModelIndex &) const
{
    return _contactsList.size();
}

int TableModel::columnCount(const QModelIndex &) const
{
    return COLUMN_COUNT;
}

QVariant TableModel::data(const QModelIndex &index, int role) const
{
    if(role == Qt::DisplayRole
            && index.row() >= 0
            && index.row() < rowCount()
            && index.column() >= 0
            && index.column() < columnCount())
        return _contactsList[index.row()].at(index.column());
    return QVariant();
}

void TableModel::readFromFile()
{
    QFile contactsFile(":/contacts.txt");
    if ((contactsFile.exists())&&(contactsFile.open(QIODevice::ReadOnly | QIODevice::Text)))
    {
        QString str="";
        while(!contactsFile.atEnd())
            {
                str=contactsFile.readLine();
                _contactsList.append(str.split(";", Qt::SkipEmptyParts));
            }
    }
    contactsFile.close();
}
