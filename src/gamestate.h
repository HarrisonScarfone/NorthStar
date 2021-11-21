#ifndef GAMESTATE_H
#define GAMESTATE_H

#include <cstdint>

namespace Gamestate {
    struct Gamestate {
        uint64_t p;
        uint64_t r;
        uint64_t n;
        uint64_t b;

        uint64_t q;
        uint64_t k;
        uint64_t white_pieces;
        uint64_t black;
        uint64_t enpassant;
        bool can_black_castle_kingside;
        bool can_black_castle_queenside;
        bool can_white_castle_kindside;

        bool can_white_castle_queenside;
        bool whiteToPlay;
    };
}  // namespace Gamestate

#endif