#pragma once
#include <cstdint>
#include <string>
#include "types.h"

class Position {
private:
    constexpr inline void putPiece(Color c, Piece p, int square) {
        setBit(pieces[c][p], square);
        setBit(colors[c], square);
        setBit(allPieces, square);
    }

public:
    Bitboard pieces[COLOR_NB][PIECE_NB];
    Bitboard colors[COLOR_NB];
    Bitboard allPieces;
    
    void initStartPos();
    void loadFEN(const std::string& fen);
    void printBitboard(Bitboard bb);
    void printBoard();
    
};