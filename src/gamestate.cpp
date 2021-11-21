#include "gamestate.h"

#include <iostream>

namespace Gamestate {

namespace Initializers {
    Position InitNewGameState() {
        Position position;
        position.white_pawns = 71776119061217280U;
        position.white_rooks = 9295429630892703744U;
        position.white_knights = 4755801206503243776U;
        position.white_bishops = 2594073385365405696U;
        position.white_queens = 576460752303423488U;
        position.white_king = 1152921504606846976U;

        position.black_pawns = 65280U;
        position.black_rooks = 129U;
        position.black_knights = 66U;
        position.black_bishops = 36U;
        position.black_queens = 8U;
        position.black_king = 16U;

        return position;
    }
}  // namespace Initializers

namespace Output {
    void PrintGamestate(Position position) {
        char piece_locations[64]{};
        uint64_t binary_position;

        for (int i = 0; i < 64; i++) {
            binary_position = 1;
            binary_position = binary_position << i;

            if (Helpers::HasPieceAtBinaryLocation(position.white_pawns, binary_position)) {
                piece_locations[i] = 'P';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.white_rooks, binary_position)) {
                piece_locations[i] = 'R';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.white_knights, binary_position)) {
                piece_locations[i] = 'N';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.white_bishops, binary_position)) {
                piece_locations[i] = 'B';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.white_queens, binary_position)) {
                piece_locations[i] = 'Q';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.white_king, binary_position)) {
                piece_locations[i] = 'K';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.black_pawns, binary_position)) {
                piece_locations[i] = 'p';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.black_rooks, binary_position)) {
                piece_locations[i] = 'r';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.black_knights, binary_position)) {
                piece_locations[i] = 'n';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.black_bishops, binary_position)) {
                piece_locations[i] = 'b';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.black_queens, binary_position)) {
                piece_locations[i] = 'q';
            }

            if (Helpers::HasPieceAtBinaryLocation(position.black_king, binary_position)) {
                piece_locations[i] = 'k';
            }
        }

        std::cout << (position.whiteToPlay ? "White" : "Black") << " to play.\n";
        std::cout << "  ---------------------------------\n";

        for (int i = 0; i < 8; i++) {
            std::cout << 8 - i << " |";
            for (int j = 0; j < 8; j++) {
                if (piece_locations[(i * 8) + j] > 0) {
                    std::cout << " " << piece_locations[(i * 8) + j] << " |";
                } else {
                    // std::cout << "   |";
                    std::cout << "   |";
                }
            }
            std::cout << "\n  ---------------------------------\n";
        }

        std::cout << "    A   B   C   D   E   F   G   H\n";
    }
}  // namespace Output

namespace Helpers {
    bool HasPieceAtBinaryLocation(uint64_t binary_location, uint64_t binary_position) {
        return (binary_position & binary_location) > 0;
    }
}  // namespace Helpers

}  // namespace Gamestate
