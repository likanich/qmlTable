#include <QAbstractTableModel>
#include <QVector>
#include <QFile>

class TableModel : public QAbstractTableModel
{
    Q_OBJECT

    //number of columns in a table
    const int COLUMN_COUNT = 3;

public:
    explicit TableModel(QObject *parent = nullptr);

    int rowCount(const QModelIndex & = QModelIndex()) const override;
    int columnCount(const QModelIndex & = QModelIndex()) const override;

    //return data to fill the table
    QVariant data(const QModelIndex &index, int role) const override;

    void readFromFile();

private:
    QVector<QStringList> _contactsList;
};
