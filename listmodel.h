#ifndef LISTMODEL_H
#define LISTMODEL_H

#include <QAbstractListModel>

#include "listitem.h"


class ListModel : public QAbstractListModel
{
  Q_OBJECT

public:
  explicit ListModel(ListItem* prototype, QObject* parent = 0);
  ~ListModel();
  int rowCount(const QModelIndex &parent = QModelIndex()) const;
  QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const;
  void appendRow(ListItem* item);
  void appendRows(const QList<ListItem*> &items);
  void insertRow(int row, ListItem* item);
  void sort(int role, Qt::SortOrder order = Qt::AscendingOrder);
  bool removeRow(int row, const QModelIndex &parent = QModelIndex());
  bool removeRows(int row, int count, const QModelIndex &parent = QModelIndex());
  ListItem* takeRow(int row);
  ListItem* itemAt(int row);
  ListItem* find(const QString &id) const;
  QModelIndex indexFromItem( const ListItem* item) const;
  void clear();
  void removeAll();

  Q_INVOKABLE QVariant at(int index, int role);

private slots:
  void handleItemChange();

private:
  QList<ListItem*>  m_list;
  ListItem*         m_prototype;
};

#endif // LISTMODEL_H
