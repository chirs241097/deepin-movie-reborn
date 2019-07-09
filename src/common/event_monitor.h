/* 
 * (c) 2017, Deepin Technology Co., Ltd. <support@deepin.org>
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License as
 * published by the Free Software Foundation; either version 3 of the
 * License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful, but
 * is provided AS IS, WITHOUT ANY WARRANTY; without even the implied
 * warranty of MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE, and
 * NON-INFRINGEMENT.  See the GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, see <http://www.gnu.org/licenses/>.
 *
 * In addition, as a special exception, the copyright holders give
 * permission to link the code of portions of this program with the
 * OpenSSL library under certain conditions as described in each
 * individual source file, and distribute linked combinations
 * including the two.
 * You must obey the GNU General Public License in all respects
 * for all of the code used other than OpenSSL.  If you modify
 * file(s) with this exception, you may extend this exception to your
 * version of the file(s), but you are not obligated to do so.  If you
 * do not wish to do so, delete this exception statement from your
 * version.  If you delete this exception statement from all source
 * files in the program, then also delete it here.
 */
#ifndef EVENTMONITOR_H
#define EVENTMONITOR_H

#include <QThread>

namespace dmr {

// Virtual button codes that are not defined by X11.
#define Button1			1
#define Button2			2
#define Button3			3
#define WheelUp			4
#define WheelDown		5
#define WheelLeft		6
#define WheelRight		7
#define XButton1		8
#define XButton2		9

class EventMonitor : public QThread
{
    Q_OBJECT

public:
    EventMonitor(QObject *parent = 0);
    void handleRecordEvent(void *);

    void resumeRecording();
    void suspendRecording();
    
signals:
    void buttonedPress(int x, int y);
    void buttonedDrag(int x, int y);
    void buttonedRelease(int x, int y);

protected:
    void run();
    
private:
    bool isPress;
    QAtomicInt _recording {1};
};

}
#endif
