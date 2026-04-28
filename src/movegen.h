#pragma once
#include "position.h"

namespace Movegen {
    Bitboard getWhitePawnPushes(const Position& pos);
    Bitboard getBlackPawnPushes(const Position& pos);
    Bitboard getWhitePawnLeftAttacks(const Position& pos);
    Bitboard getWhitePawnRigthAttacks(const Position& pos);
    Bitboard getBlackPawnLeftAttacks(const Position& pos);
    Bitboard getBlackPawnRightAttacks(const Position& pos);
    Bitboard getWhitePawnDoublePushes(const Position& pos);
    Bitboard getBlackPawnDoublePushes(const Position& pos);
    Bitboard getKnightMoves(const Position& pos, Color c);
}