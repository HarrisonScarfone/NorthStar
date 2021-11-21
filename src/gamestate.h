#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdint>

namespace Gamestate {
struct Position {
    uint64_t white_pawns;
    uint64_t white_rooks;
    uint64_t white_knights;
    uint64_t white_bishops;
    uint64_t white_queens;
    uint64_t white_king;
    uint64_t black_pawns;
    uint64_t black_rooks;
    uint64_t black_knights;
    uint64_t black_bishops;
    uint64_t black_queens;
    uint64_t black_king;
    uint64_t enpassant;

    bool can_black_castle_kingside;
    bool can_black_castle_queenside;
    bool can_white_castle_kindside;
    bool can_white_castle_queenside;

    bool whiteToPlay;
};

namespace Initializers {
    Position InitNewGameState();
}

namespace Output {
    void PrintGamestate(Gamestate::Position position);
}  // namespace Output

namespace Helpers {
    bool HasPieceAtBinaryLocation(uint64_t binary_location, uint64_t binary_position);
}  // namespace Helpers
}  // namespace Gamestate

#endif
