#include "SearchThread.h"
#include <QDebug>

//Constructor to register QList<SearchDescription> as a Meta Type to retrieve data between threads
SearchThread::SearchThread(QObject *parent) :
    QThread(parent)
{
    qRegisterMetaType<QList<SearchDescription>>("QList<SearchDescription>");
}

//Set variables that will be used to search 
void SearchThread::setVariables(QList<SearchDescription> search, QString si, QString sf, QString ss)
{

    sch = search;
    searchI = si;
    searchF = sf;
    searchS = ss;
}

//Run thread to search based on users input
void SearchThread::run()
{
    sch = Core()->getAllSearch(searchF, searchS, searchI);
    emit searched(sch);
}
