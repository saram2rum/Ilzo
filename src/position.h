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
    // 태어날 때 무조건 0으로 꽉 채워서 초기화 (아예 기물도 안올린 체스판)
    Bitboard pieces[COLOR_NB][PIECE_NB] = {0};
    Bitboard colors[COLOR_NB] = {0};
    Bitboard allPieces = 0ULL;
    
    void initStartPos();
    void loadFEN(const std::string& fen);
    void printBitboard(Bitboard bb);
    void printBoard();
    
};