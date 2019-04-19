//
// Created by Curtis Wilcox on 2019-04-05.
//

#include <iostream>
#include <QSettings>

#include "Pawn.h"

using namespace std;

///////////////////////////////////////////////////////////////////////////
// Dimensions operators
///////////////////////////////////////////////////////////////////////////

#pragma clang diagnostic push
#pragma ide diagnostic ignored "bugprone-narrowing-conversions" // suppress warnings

void Dimensions::operator*=(double multiplier) {
    this->height *= multiplier;
    this->width *= multiplier;
}

void Dimensions::operator/=(int multiplier) {
    this->height *= ((double) 1 / multiplier);
    this->width *= ((double) 1 / multiplier);
}

void Dimensions::operator^=(int multiplier) {
    int tmpHeight = height;
    height = width;
    width = tmpHeight;
}

#pragma clang diagnostic pop

QSettings settings("CS205", "Parcheesi");

///////////////////////////////////////////////////////////////////////////
// Pawn methods
///////////////////////////////////////////////////////////////////////////

Pawn::Pawn(const Dimensions &d, int currentTileNum, int id, QColor c, QWidget *parent) : dimensions(d), color(std::move(c)),
            MAX_TILE((c == QColor(231, 0, 48)) ? 59 : c == Qt::GlobalColor::yellow
                                               ? 25 : c == Qt::GlobalColor::darkGreen
                                               ? 42 : 8),
                                               currentTileNum(currentTileNum),
                                               id(id),
                                               QWidget(parent) {
}

void Pawn::mouseReleaseEvent(QMouseEvent *event) {
    cout << "Pressed Pawn color (" << color.red() << ", " << color.green() << ", " << color.blue() << ")!" << endl;
    if (color.red() == 153 && color.green() == 153) {
        team = "Yellow";
    } else if (color.green() == 102) {
        team = "Green";
    } else if (color.blue() == 153) {
        team = "Blue";
    } else {
        team = "Red";
    }
    cout << team << " number " << id << endl;
}

void Pawn::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect;
    rect.setRect(0, 0, dimensions.width, dimensions.height);
    painter.setPen(QPen(QBrush(Qt::black), 1));
    painter.drawRect(rect);
    painter.fillRect(rect, color);
}