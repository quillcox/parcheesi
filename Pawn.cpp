//
// Created by Curtis Wilcox on 2019-04-05.
//

#include <iostream>

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


#pragma clang diagnostic pop

///////////////////////////////////////////////////////////////////////////
// Pawn methods
///////////////////////////////////////////////////////////////////////////

Pawn::Pawn(const Dimensions &d, QColor c, QWidget *parent) : dimensions(d), color(std::move(c)),
                                                             QWidget(parent) {
}

void Pawn::mouseReleaseEvent(QMouseEvent *event) {
    cout << "Pressed Pawn color (" << color.red() << ", " << color.green() << ", " << color.blue() << ")!" << endl;
}

void Pawn::paintEvent(QPaintEvent *event) {
    QPainter painter(this);
    QRect rect;
    rect.setRect(0, 0, dimensions.width, dimensions.height);
    painter.setPen(QPen(QBrush(Qt::black), 1));
    painter.drawRect(rect);
    painter.fillRect(rect, color);
}

bool operator==(const Pawn &lhs, const Pawn &rhs) {
    return lhs.color == rhs.color; // also know position?
}

bool operator!=(const Pawn &lhs, const Pawn &rhs) {
    return !(lhs == rhs);
}