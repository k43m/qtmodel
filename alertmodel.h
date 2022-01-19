#ifndef ALERTMODEL_H
#define ALERTMODEL_H

#include "listitem.h"
#include "listmodel.h"

enum Roles {
    AlertIdRole,
    SectorNameRole,
    TypeRole,
    DetectionTimeRole,
    IsAcknowledgedRole,
    IsVisibleRole
};

class AlertItem: public ListItem {
    Q_OBJECT

public:
    AlertItem(): ListItem() {}
    ~AlertItem() {}
    AlertItem(QString alertId, QString date, QString sectorName, bool acknowledged, QObject *parent=nullptr) :
                                                                                                                 ListItem(parent),
                                                                                                                 m_alertId(alertId),
                                                                                                                 m_sectorName(sectorName),
                                                                                                                 m_detectionTime(date),
                                                                                                                 m_isAcknowledged(acknowledged),
                                                                                                                 m_targetCount(0)
    {
    }
    // setters
    void setType(int val) { m_type = val; emit dataChanged(); }
    // getters
    QString alertId(){return m_alertId;}
    int getType(){return m_type;}
    QString sectorName() { return m_sectorName;}
    int type() { return m_type;}
    QString detectionTime() {return m_detectionTime;}
    bool IsAcknowledged() { return m_isAcknowledged;}

    inline QString id() const { return m_alertId; }
    inline QVariant serverId() const { return "m_host"; }

    void appendSubItem(ListItem* item);
    void appendSubItems(const QList<ListItem*> &items);
    void removeSubItem(QString id);
    int subItemCount() { return m_targetCount; }

    QVariant data(int role) const {
        switch(role) {
        case AlertIdRole:
            return m_alertId;
        case SectorNameRole:
            return m_sectorName;
        case TypeRole:
            return m_type;
        case DetectionTimeRole:
            return m_detectionTime;
        case IsAcknowledgedRole:
            return m_isAcknowledged;
        default:
            return QVariant();
        }
    }


private:
    QString                   m_alertId;
    QString                   m_sectorName;
    int                       m_type;
    QString                   m_detectionTime;
    bool                      m_isAcknowledged;
    int                       m_targetCount;
};


class AlertListModel : public ListModel
{
    Q_OBJECT

public:

    explicit AlertListModel(QObject *parent = nullptr):
                                                         ListModel(new AlertItem, parent)
    {}

    QHash<int, QByteArray> roleNames() const
    {
        QHash<int, QByteArray> roles;
        roles[AlertIdRole]          = "alertId";
        roles[SectorNameRole]       = "sectorName";
        roles[TypeRole]             = "type";
        roles[DetectionTimeRole]    = "detectionTime";
        roles[IsAcknowledgedRole]   = "isAcknowledged";
        roles[IsVisibleRole]        = "isVisible";
        return roles;
    }

    Q_INVOKABLE void dissmissed(const QString &alertId) const{ emit dissmissed(alertId); }
    Q_INVOKABLE void showHistoryPage(){ emit showHistory(); }
    Q_INVOKABLE void showVersionWindow(){ emit showVersionWdw(); }

signals:
    void dissmissed(QString);
    void showHistory();
    void showVersionWdw();

};

#endif // ALERTMODEL_H
