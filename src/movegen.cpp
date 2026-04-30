#include "movegen.h"

namespace Movegen {
    Bitboard getWhitePawnPushes(const Position& pos) {
        return (pos.pieces[WHITE][PAWN] << 8) & ~pos.allPieces;
    }
    Bitboard getBlackPawnPushes(const Position& pos) {
        return (pos.pieces[BLACK][PAWN] >> 8) & ~pos.allPieces;
    }

    Bitboard getWhitePawnLeftAttacks(const Position& pos) {
        return (pos.pieces[WHITE][PAWN] << 7) & NOT_A_FILE & pos.colors[BLACK];
    }

    Bitboard getWhitePawnRightAttacks(const Position& pos) {
        return (pos.pieces[WHITE][PAWN] << 9) & NOT_H_FILE & pos.colors[BLACK];
    }

    Bitboard getBlackPawnLeftAttacks(const Position& pos) {
        return (pos.pieces[BLACK][PAWN] >> 9) & NOT_A_FILE & pos.colors[WHITE];
    }
    
    Bitboard getBlackPawnRightAttacks(const Position& pos) {
        return (pos.pieces[BLACK][PAWN] >> 7) & NOT_H_FILE & pos.colors[WHITE];
    }

    Bitboard getWhitePawnDoublePushes(const Position& pos) {
        return (((pos.pieces[WHITE][PAWN] << 8) & ~pos.allPieces) << 8) & ~pos.allPieces & RANK_4;
    }

    Bitboard getBlackPawnDoublePushes(const Position& pos) {
        return (((pos.pieces[BLACK][PAWN] >> 8) & ~pos.allPieces) >> 8) & ~pos.allPieces & RANK_5;
    }

    // 특정 색상(c) 나이트의 모든 이동 가능 칸을 반환
    Bitboard getKnightMoves(const Position& pos, Color c) {
        Bitboard knights = pos.pieces[c][KNIGHT];
        Bitboard attacks = 0;

        // 1. 위로 뛰는 4방향 (<<)
        attacks |= (knights << 17) & NOT_A_FILE;   // 북북동
        attacks |= (knights << 15) & NOT_H_FILE;   // 북북서
        attacks |= (knights << 10) & NOT_AB_FILE;  // 동동북 (우로 2칸 가니까 AB 방패)
        attacks |= (knights <<  6) & NOT_GH_FILE;  // 서서북 (좌로 2칸 가니까 GH 방패)

        // 2. 아래로 뛰는 4방향 (>>)
        attacks |= (knights >> 15) & NOT_A_FILE;   // 남남동
        attacks |= (knights >> 17) & NOT_H_FILE;   // 남남서
        attacks |= (knights >>  6) & NOT_AB_FILE;  // 동동남 (우로 2칸 가니까 AB 방패)
        attacks |= (knights >> 10) & NOT_GH_FILE;  // 서서남 (좌로 2칸 가니까 GH 방패)

        // 3. 최종 필터링: 공격 가능한 모든 칸 중에서 내 기물이 있는 곳(~colors[c])만 제외
        return attacks & ~pos.colors[c];
    }

    Bitboard getKingMoves(const Position& pos, Color c) {
        Bitboard k = pos.pieces[c][KING];
        
        // 1. 좌우로 1칸씩 밀기 (이때만 방패가 필요)
        // H열이 아닌 놈만 오른쪽으로(<< 1), A열이 아닌 놈만 왼쪽으로(>> 1)
        Bitboard attacks = ((k & NOT_H_FILE) << 1) | ((k & NOT_A_FILE) >> 1);
        
        // 2. 현재 킹의 위치(k) + 좌우 공격 위치(attacks)를 합침
        // adjacent는 킹을 포함한 3칸짜리 가로 막대기
        Bitboard adjacent = k | attacks;
        
        // 3. 그 3칸짜리 막대기를 통째로 위로(<< 8) 아래로(>> 8) 밀어버림
        // (위아래는 하드웨어가 막아주니까 방패 불필요)
        attacks |= (adjacent << 8) | (adjacent >> 8);
        
        // 4. 마지막으로 내 기물이 있는 곳만 빼서 반환
        return attacks & ~pos.colors[c];

    }
}