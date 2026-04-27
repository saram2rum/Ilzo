#include <iostream>
#include <string>
#include "types.h"
#include "position.h"
#include "movegen.h"

int main() {
    std::ios_base::sync_with_stdio(false);

    Position pos;
    pos.initStartPos(); 
    
    Bitboard valid_pushes = Movegen::getBlackPawnPushes(pos);
    
    std::cout << "< Black Pawn Pushes >";
    pos.printBitboard(valid_pushes);

    return 0;
}