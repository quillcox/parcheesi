//
// Created by Curtis Wilcox on 2019-03-04.
//

#ifndef PARCHEESI_DIE_H
#define PARCHEESI_DIE_H

#include <QWidget>

class Die : public QWidget {
Q_OBJECT
private:
    int value;
public:
    const std::string name;

    explicit Die(const std::string& name, QWidget *parent = nullptr);

    void roll();

    int getValue();

    void setValue(int);

    void paintEvent(QPaintEvent *event) override;

    friend int operator+(const Die &lhs, const Die &rhs);

    friend bool operator==(const Die &lhs, const Die &rhs);

    friend bool operator!=(const Die &lhs, const Die &rhs);

    friend bool operator<=(const Die &lhs, const Die &rhs);

    friend bool operator<(const Die &lhs, const Die &rhs);

    friend bool operator>(const Die &lhs, const Die &rhs);

    friend bool operator>=(const Die &lhs, const Die &rhs);
};


#endif //PARCHEESI_DIE_H
