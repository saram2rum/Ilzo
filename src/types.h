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
const Bitboard NOT_AB_FILE = 0xfcfcfcfcfcfcfcfcULL; // A열과 B열 - 나이트 용
const Bitboard NOT_GH_FILE = 0x3f3f3f3f3f3f3f3fULL; // G열과 H열 - 나이트 용
const Bitboard RANK_4 = 0x00000000FF000000ULL; // 백색 폰 2칸 전진 도착지
const Bitboard RANK_5 = 0x000000FF00000000ULL; // 흑색 폰 2칸 전진 도착지