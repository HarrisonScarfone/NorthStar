#include <iostream>

#include "gamestate.h"

int main() {
    Gamestate::Position position = Gamestate::Initializers::InitNewGameState();
    Gamestate::Output::PrintGamestate(position);
}
