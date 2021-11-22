#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdint>
#include <string>

namespace Gamestate {
struct Position {
    uint64_t white_pawns = 0;
    uint64_t white_rooks = 0;
    uint64_t white_knights = 0;
    uint64_t white_bishops = 0;
    uint64_t white_queens = 0;
    uint64_t white_king = 0;
    uint64_t black_pawns = 0;
    uint64_t black_rooks = 0;
    uint64_t black_knights = 0;
    uint64_t black_bishops = 0;
    uint64_t black_queens = 0;
    uint64_t black_king = 0;
    uint64_t enpassant = 0;

    bool white_to_play = false;

    bool can_black_castle_kingside = false;
    bool can_black_castle_queenside = false;
    bool can_white_castle_kindside = false;
    bool can_white_castle_queenside = false;

    int halfmove_clock = 0;
    int fullmove_clock = 0;
};

namespace Initializers {
    Position StartingPosition();
    Position PositionFromFenString(std::string fen_string);
}  // namespace Initializers

namespace Output {
    void PrintPosition(Gamestate::Position position);
}  // namespace Output

namespace Helpers {
    bool PieceUint64HasPieceAtLocation(uint64_t piece_64bit_locations, uint64_t location_to_check);
}  // namespace Helpers
}  // namespace Gamestate

#endif
