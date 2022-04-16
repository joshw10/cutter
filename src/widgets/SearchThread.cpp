#include "SearchThread.h"
#include <QDebug>

SearchThread::SearchThread(QObject *parent) :
    QThread(parent)
{
    qRegisterMetaType<QList<SearchDescription>>("QList<SearchDescription>");
}

void SearchThread::setVariables(QList<SearchDescription> search, QString si, QString sf, QString ss)
{

    sch = search;
    searchI = si;
    searchF = sf;
    searchS = ss;
}

void SearchThread::run()
{
    sch = Core()->getAllSearch(searchF, searchS, searchI);
    emit searched(sch);
}
