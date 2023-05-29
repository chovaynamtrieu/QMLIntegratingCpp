#include "back_end.h"

BackEnd::BackEnd(QObject *parent) :
    QObject(parent)
{

}

void BackEnd::login(const QString &userName,const QString &passWord)
{
    if(userName != "phamtung"){
        emit loginFail();
        setStatus("User Name is not correct!!!");
        return;
    }
    if(passWord != "phamtung"){
        emit loginFail();
        setStatus("Pass Word is not correct!!!");
        return;
    }
    emit loginSucess();
    setStatus("Signed In!!!");
}

QString BackEnd::status() const
{
    return m_status;
}

void BackEnd::setStatus(const QString &status)
{
    if (status == m_status){
        return;
    }
    m_status = status;
    emit StatusChanged();
}
