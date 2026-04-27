#pragma once
#include <cstdint>

using Bitboard = uint64_t;

enum Color { WHITE, BLACK, COLOR_NB };
enum Piece { PAWN, KNIGHT, BISHOP, ROOK, QUEEN, KING, PIECE_NB };

constexpr inline void setBit(Bitboard& bb, int square) { bb |= (1ULL << square); }
constexpr inline void clearBit(Bitboard& bb, int square) { bb &= ~(1ULL << square); }
constexpr inline bool checkBit(Bitboard bb, int square) { return (bb & (1ULL << square)) != 0; }

const Bitboard NOT_A_FILE = 0xfefefefefefefefeULL; // A열만 모두 0인 마스크
const Bitboard NOT_H_FILE = 0x7f7f7f7f7f7f7f7fULL; // H열만 모두 0인 마스크
const Bitboard RANK_4     = 0x000000FF00000000ULL; // 백색 폰 2칸 전진 도착지