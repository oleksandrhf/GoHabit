#include "notificationclient.h"

#include <QtAndroidExtras/QAndroidJniObject>

NotificationClient::NotificationClient(QObject *parent)
    : QObject(parent)
{
    connect(this, SIGNAL(notificationChanged()), this, SLOT(updateAndroidNotification()));
    m_notification = "";
}

void NotificationClient::setNotification(QString notification)
{
    if (m_notification == notification)
        return;

    m_notification = notification;
    emit notificationChanged();
}

QString NotificationClient::notification() const
{
    return m_notification;
}

void NotificationClient::updateAndroidNotification()
{
    QAndroidJniObject javaNotification = QAndroidJniObject::fromString(m_notification);
    QAndroidJniObject::callStaticMethod<void>("org/qtproject/example/notification/NotificationClient",
                                       "notify",
                                       "(Ljava/lang/String;)V",
                                       javaNotification.object<jstring>());
}
