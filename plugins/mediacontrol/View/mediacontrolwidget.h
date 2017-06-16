#ifndef MEDIACONTROLWIDGET_H
#define MEDIACONTROLWIDGET_H

#include "mediacontrol.h"
#include "textticker.h"
#include "DBus/dbusinterface.h"
#include "DBus/dbusmediaplayer2.h"
#include <QFrame>
#include <QLabel>
#include <QPropertyAnimation>

using DBusMPRIS = DBusMediaPlayer2;

class MediaControlWidget : public QFrame
{
    Q_OBJECT
public:
    explicit MediaControlWidget(QWidget *parent = nullptr);
    void initMpris();

private slots:
    void onNameOwnerChanged(const QString &name, const QString &oldOwner, const QString &newOwner);
    void loadMPRISPath(const QString &path);
    void removeMPRISPath(const QString &path);

protected:
    void enterEvent(QEvent *event) Q_DECL_OVERRIDE;
    void leaveEvent(QEvent *event) Q_DECL_OVERRIDE;

private:
    MediaControl *m_mediaControl;
    DBusMediaPlayer2 *m_mprisInter;
    TextTicker *m_mediaTitle;
    QPropertyAnimation *m_hoverControlAni;
    QPropertyAnimation *m_showControlAni;
    DBusInterface *m_dbusInter;
    QString m_lastPath;
    QStringList m_mprisPaths;
};

#endif // MEDIACONTROLWIDGET_H
