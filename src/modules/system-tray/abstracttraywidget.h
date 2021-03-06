/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#pragma once

#include <QWidget>

class QDBusMessage;
class AbstractTrayWidget: public QWidget
{
    Q_OBJECT
public:
    explicit AbstractTrayWidget(QWidget *parent = Q_NULLPTR, Qt::WindowFlags f = Qt::WindowFlags());
    virtual ~AbstractTrayWidget();

    virtual void setActive(const bool active) = 0;
    virtual void updateIcon() = 0;
    virtual void sendClick(uint8_t, int, int) = 0;
    virtual const QImage trayImage() = 0;

Q_SIGNALS:
    void iconChanged();

protected:
    void mouseReleaseEvent(QMouseEvent *e) Q_DECL_OVERRIDE;
};

