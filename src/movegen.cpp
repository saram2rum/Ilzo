#include "movegen.h"

namespace Movegen {
    Bitboard getWhitePawnPushes(const Position& pos) {
        return (pos.pieces[WHITE][PAWN] << 8) & ~pos.allPieces;
    }
    Bitboard getBlackPawnPushes(const Position& pos) {
        return (pos.pieces[BLACK][PAWN] >> 8) & ~pos.allPieces;
    }

    Bitboard getWhitePawnLeftAttacks(const Position& pos) {
        return (pos.pieces[WHITE][PAWN] << 7) & NOT_A_FILE; & pos.colors[BLACK];
    }

    Bitboard getWhitePawnRigthAttacks(const Position& pos) {
        return (pos.pieces[WHITE][PAWN] << 9) & NOT_H_FILE; & pos.colors[BLACK];
    }

    Bitboard getBlackPawnLeftAttacks(const Position& pos) {
        return (pos.pieces[BLACK][PAWN] >> 9) & NOT_A_FILE & pos.colors[BLACK];
    }
    
    Bitboard getBlackPawnRightAttacks(const Position& pos) {
        return (pos.pieces[BLACK][PAWN] >> 7) & NOT_H_FILE & pos.colors[WHITE];
    }
}