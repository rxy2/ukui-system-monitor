/*
 * Copyright (C) 2020 KylinSoft Co., Ltd.
 *
 * Authors:
 *  Kobe Lee    xiangli@ubuntukylin.com/kobe24_lixiang@126.com
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef MYSEARCHEDIT_H
#define MYSEARCHEDIT_H

#include <QFrame>
#include <QSize>
#include <QLineEdit>
#include <QPropertyAnimation>
#include <QLabel>
#include <QStyleOption>
#include <QPainter>
#include <QPainterPath>
#include <QPushButton>
#include <QWidgetAction>
#include <qgsettings.h>
#include <QApplication>

#include "shell/customstyle.h"
#include "../shell/macro.h"

#include "mytristatebutton.h"

class QGsettings;

class MySearchEdit : public QFrame
{
    Q_OBJECT
public:
    explicit MySearchEdit(QWidget *parent = 0);
    ~MySearchEdit();

    void setPlaceHolder(const QString &text);
    const QString searchedText() const;
    QLineEdit *getLineEdit() const;
    void initThemeMode();
    void initFontSize();

public slots:
    void clearEdit();
    void setEditFocus();
    void setText(const QString & text);
    void clearAndFocusEdit();
private slots:
    void textChageSlots(const QString &text);

signals:
    void textChanged();

protected:
    void resizeEvent(QResizeEvent *event);
    bool event(QEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
    bool eventFilter(QObject *object, QEvent *event);
//    void paintEvent(QEvent *event);

private:
    QPropertyAnimation *m_animation = nullptr;
    QEasingCurve m_showCurve;
    QEasingCurve m_hideCurve;
    QSize m_size;
    QLineEdit *m_edit = nullptr;
    QLabel *m_searchBtn = nullptr;
    QLabel *m_placeHolder = nullptr;
    MyTristateButton *m_clearBtn = nullptr;
    QPushButton *m_pClearTextButton =nullptr;
    QPixmap drawSymbolicColoredPixmap(const QPixmap &source);

    float fontSize;

    QGSettings *qtSettings;
    QGSettings *fontSettings;
    QString currentThemeMode;
};

#endif // MYSEARCHEDIT_H
