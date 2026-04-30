#pragma once
#include "types.h"

namespace Bitboards {
    // 나이트 & 킹 (매직 비트보드 안 씀)
    extern Bitboard KnightAttacksTable[64];
    extern Bitboard KingAttacksTable[64];

    // 룩 & 비숍 마스크 (occ에 & 연산할 때 사용)
    extern Bitboard RookMasks[64];
    extern Bitboard BishopMasks[64];

    // 룩 & 비숍 공격 정답지 테이블
    extern Bitboard RookAttacksTable[64][4096];
    extern Bitboard BishopAttacksTable[64][512];

    // 룩 & 비숍 매직 넘버와 시프트 값
    extern const Bitboard RookMagics[64];
    extern const Bitboard BishopMagics[64];
    extern const int RookShifts[64];
    extern const int BishopShifts[64];

    void init();

    inline Bitboard getKnightAttacks(int sq) {
        return KnightAttacksTable[sq];
    }

    inline Bitboard getKingAttacks(int sq) {
        return KingAttacksTable[sq];
    }

    inline Bitboard getRookAttacks(int sq, Bitboard occ) {
        occ &= RookMasks[sq];
        occ *= RookMagics[sq];
        occ >>= RookShifts[sq];
        return RookAttacksTable[sq][occ];
    }


    inline Bitboard getBishopAttacks(int sq, Bitboard occ) {
        occ &= BishopMasks[sq]; 
        occ *= BishopMagics[sq];
        occ >>= BishopShifts[sq];
        return BishopAttacksTable[sq][occ];
    }
}