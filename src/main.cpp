#include <iostream>

#include "gamestate.h"
#include "utilities.h"

int main() {
    // Gamestate::Position position = Gamestate::Initializers::GameState();
    Gamestate::Position position =
        Gamestate::Initializers::PositionFromFenString("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");
    Gamestate::Output::PrintPosition(position);
}
