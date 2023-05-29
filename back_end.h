#ifndef BACKEND_H
#define BACKEND_H

#include <QObject>
#include <QString>

class BackEnd: public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString status READ status WRITE setStatus NOTIFY StatusChanged)

public:
    explicit BackEnd(QObject *parent = nullptr);
    Q_INVOKABLE void login(const QString &userName, const QString &passWord);
    QString status() const;
    void setStatus(QString const &status);

signals:
    void loginSucess();
    void loginFail();
    void StatusChanged();

private:
    QString m_status;

};

#endif // BACKEND_H
