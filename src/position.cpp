#include "position.h"
#include <iostream>
#include <cstring>
#include <string>

void Position::initStartPos() {
    std::memset(pieces, 0, sizeof(pieces));
    std::memset(colors, 0, sizeof(colors));
    allPieces = 0ULL;
    putPiece(WHITE, ROOK, 0);
    putPiece(WHITE, KNIGHT, 1);
    putPiece(WHITE, BISHOP, 2);
    putPiece(WHITE, QUEEN, 3);
    putPiece(WHITE, KING, 4);
    putPiece(WHITE, BISHOP, 5);
    putPiece(WHITE, KNIGHT, 6);
    putPiece(WHITE, ROOK, 7);
    putPiece(WHITE, PAWN, 8);
    putPiece(WHITE, PAWN, 9);
    putPiece(WHITE, PAWN, 10);
    putPiece(WHITE, PAWN, 11);
    putPiece(WHITE, PAWN, 12);
    putPiece(WHITE, PAWN, 13);
    putPiece(WHITE, PAWN, 14);
    putPiece(WHITE, PAWN, 15);
    putPiece(BLACK, PAWN, 48);
    putPiece(BLACK, PAWN, 49);
    putPiece(BLACK, PAWN, 50);
    putPiece(BLACK, PAWN, 51);
    putPiece(BLACK, PAWN, 52);
    putPiece(BLACK, PAWN, 53);
    putPiece(BLACK, PAWN, 54);
    putPiece(BLACK, PAWN, 55);
    putPiece(BLACK, ROOK, 56);
    putPiece(BLACK, KNIGHT, 57);
    putPiece(BLACK, BISHOP, 58);
    putPiece(BLACK, QUEEN, 59);
    putPiece(BLACK, KING, 60);
    putPiece(BLACK, BISHOP, 61);
    putPiece(BLACK, KNIGHT, 62);
    putPiece(BLACK, ROOK, 63);
}

void Position::loadFEN(const std::string& fen) {
    // 1. 일단 기존 체스판을 싹 비웁니다.
    std::memset(pieces, 0, sizeof(pieces));
    std::memset(colors, 0, sizeof(colors));
    allPieces = 0ULL;

    // 2. FEN은 8랭크(맨 윗줄) A열부터 시작합니다.
    int rank = 7;
    int file = 0;

    for (char c : fen) {
        if (c == ' ') break; // 기물 배치 파트가 끝나면 일단 스톱!

        if (c == '/') {
            rank--;   // 다음 줄로 넘어감
            file = 0; // 다시 A열부터 시작
        } 
        else if (std::isdigit(c)) {
            file += (c - '0'); // '3' 같은 문자에서 '0'을 빼면 실제 정수 3이 됩니다. 그만큼 칸 건너뛰기!
        } 
        else {
            // 대문자면 WHITE, 아니면 BLACK
            Color col = std::isupper(c) ? WHITE : BLACK;
            Piece pc;
            
            // 대소문자 상관없이 기물 판별하기 위해 소문자로 통일해서 검사
            char lower = std::tolower(c);
            if (lower == 'p') pc = PAWN;
            else if (lower == 'n') pc = KNIGHT;
            else if (lower == 'b') pc = BISHOP;
            else if (lower == 'r') pc = ROOK;
            else if (lower == 'q') pc = QUEEN;
            else if (lower == 'k') pc = KING;

            // 판별된 기물을 체스판에 박아넣고, 다음 칸으로 이동
            putPiece(col, pc, rank * 8 + file);
            file++;
        }
    }
}

void Position::printBitboard(Bitboard bb) {
    std::cout << '\n';
    for (int rank = 7; rank >= 0; --rank) {
        std::cout << rank + 1 << "  ";
        for (int file = 0; file <= 7; ++file) {
            std::cout << checkBit(bb, rank * 8 + file) << ' ';
        }
        std::cout << '\n';
    }
    std::cout << "\n   A B C D E F G H\n\n";
}

// 외부(cpp)에서 구현할 때는 반드시 소속(Position::)을 밝혀줍니다!
void Position::printBoard() {
    const char pieceChars[COLOR_NB][PIECE_NB] = {
        {'P', 'N', 'B', 'R', 'Q', 'K'}, // WHITE
        {'p', 'n', 'b', 'r', 'q', 'k'}  // BLACK
    };

    std::cout << "\n  +---+---+---+---+---+---+---+---+\n";
    for (int rank = 7; rank >= 0; --rank) {
        std::cout << rank + 1 << " |";
        
        for (int file = 0; file <= 7; ++file) {
            int square = rank * 8 + file;
            char c = ' '; // 기본은 빈칸

            // 12개의 비트보드를 뒤져서 기물을 찾음
            for (int color = WHITE; color < COLOR_NB; ++color) {
                for (int piece = PAWN; piece < PIECE_NB; ++piece) {
                    if (checkBit(pieces[color][piece], square)) {
                        c = pieceChars[color][piece];
                    }
                }
            }
            std::cout << " " << c << " |";
        }
        std::cout << "\n  +---+---+---+---+---+---+---+---+\n";
    }
    std::cout << "    A   B   C   D   E   F   G   H\n\n";
}