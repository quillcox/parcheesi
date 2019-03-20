//
// Created by Curtis Wilcox on 2019-03-04.
//

#include <numeric>

#include "Player.h"

using namespace std;

Pawn::Pawn(PawnColor color) : color(color) {}

int Player::numPawnsStart() {
    return accumulate(pawns.begin(), pawns.end(), 0, [&](const Pawn &pawn) { return pawn.status == PawnStatus::START; });
}

int Player::numPawnsHome() {
    return accumulate(pawns.begin(), pawns.end(), 0, [&](const Pawn &pawn) { return pawn.status == PawnStatus::HOME; });
}