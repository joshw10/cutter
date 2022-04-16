#ifndef SEARCHTHREAD_H
#define SEARCHTHREAD_H

#include <QThread>
#include <QMutex>
#include "AddressableItemList.h"

class SearchThread : public QThread
{
    Q_OBJECT
public:
    explicit SearchThread(QObject *parent = 0);
    void run();
    void setVariables(QList<SearchDescription> search, QString si, QString sf, QString ss);

signals:
    void searched(QList<SearchDescription>);

public slots:

private:

    QList<SearchDescription> sch;
    QString searchI;
    QString searchF;
    QString searchS;    
};

#endif // SEARCHTHREAD_H
