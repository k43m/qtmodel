#ifndef LISTITEM_H
#define LISTITEM_H


#include <QAbstractItemModel>

class ListItem: public QObject {
  Q_OBJECT

public:
  ListItem(QObject* parent = nullptr) : QObject(parent) {}
  virtual ~ListItem() {}
  virtual QString id() const = 0;
  virtual QVariant serverId() const = 0;
  virtual QVariant data(int role) const = 0;

signals:
  void dataChanged();
};

#endif // LISTITEM_H
