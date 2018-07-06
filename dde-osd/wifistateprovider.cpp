/*
 * Copyright (C) 2011 ~ 2018 Deepin Technology Co., Ltd.
 *
 * Author:     sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
 *
 * Maintainer: sbw <sbw@sbw.so>
 *             kirigaya <kirigaya@mkacg.com>
 *             Hualet <mr.asianwang@gmail.com>
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

#include "wifistateprovider.h"

WifiStateProvider::WifiStateProvider(QObject *parent)
    : AbstractOSDProvider(parent)
{
    m_suitableParams << "WLANOn" << "WLANOff";
}

int WifiStateProvider::rowCount(const QModelIndex &) const
{
    return 1;
}

QVariant WifiStateProvider::data(const QModelIndex &, int role) const
{
    const bool decoration = role == Qt::DecorationRole;
    if (decoration) {
        if (m_param == "WLANOn") {
            return ":/icons/OSD_wifi_on.svg";
        } else if (m_param == "WLANOff") {
            return ":/icons/OSD_wifi_off.svg";
        }
    }
    return QVariant();
}

void WifiStateProvider::paint(QPainter *painter, const QStyleOptionViewItem &option, const QModelIndex &index) const
{
    QVariant pixPath = index.data(Qt::DecorationRole);

    DrawHelper::DrawImage(painter, option, pixPath.toString());
}

QSize WifiStateProvider::sizeHint(const QStyleOptionViewItem &, const QModelIndex &) const
{
    return QSize(ImageTextItemWidth, ImageTextItemHeight);
}

bool WifiStateProvider::match(const QString &param)
{
    m_param = param;
    return m_suitableParams.contains(param);
}
