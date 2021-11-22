#include "gamestate.h"

#include <cstdint>
#include <iostream>
#include <string>
#include <vector>

#include "constants.h"
#include "utilities.h"

namespace Gamestate {

namespace Initializers {
    Position StartingPosition() {
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

        position.white_to_play = true;

        position.can_black_castle_kingside = true;
        position.can_black_castle_queenside = true;
        position.can_white_castle_kindside = true;
        position.can_white_castle_queenside = true;

        position.halfmove_clock = 0;
        position.fullmove_clock = 1;

        return position;
    }

    Position PositionFromFenString(std::string fen_string) {
        Position position;
        std::vector<std::string> fen_tokens = Utilities::StringHandlers::TokenizeByDelimiter(fen_string, " ");

        uint64_t location = 1;
        // first token shows the piece positions so set them in the Gamestate::Position
        for (auto character : fen_tokens.at(0)) {
            switch (character) {
                case '/':
                    continue;
                case 'P':
                    position.white_pawns = position.white_pawns | location;
                    break;
                case 'R':
                    position.white_rooks = position.white_rooks | location;
                    break;
                case 'N':
                    position.white_knights = position.white_knights | location;
                    break;
                case 'B':
                    position.white_bishops = position.white_bishops | location;
                    break;
                case 'Q':
                    position.white_queens = position.white_queens | location;
                    break;
                case 'K':
                    position.white_king = position.white_king | location;
                    break;
                case 'p':
                    position.black_pawns = position.black_pawns | location;
                    break;
                case 'r':
                    position.black_rooks = position.black_rooks | location;
                    break;
                case 'n':
                    position.black_knights = position.black_knights | location;
                    break;
                case 'b':
                    position.black_bishops = position.black_bishops | location;
                    break;
                case 'q':
                    position.black_queens = position.black_queens | location;
                    break;
                case 'k':
                    position.black_king = position.black_king | location;
                    break;
                default:
                    // 0 is 48 in char
                    // shift by 1 less than char val to account for loop shift
                    location = location << (character - 49);
                    break;
            }
            location = location << 1;
        }

        // second token shows "w" for white turn
        position.white_to_play = fen_tokens.at(1) == "w";

        // third token gives castling rights and - denotes no castling rights
        for (auto character : fen_tokens.at(2)) {
            switch (character) {
                case 'K':
                    position.can_white_castle_kindside = true;
                    break;
                case 'Q':
                    position.can_white_castle_queenside = true;
                    break;
                case 'k':
                    position.can_black_castle_kingside = true;
                    break;
                case 'q':
                    position.can_black_castle_queenside = true;
                    break;
                default:
                    continue;
            }
        }

        // fourth token handles en passant rights
        // set our enpassant board to high in the location given in the token
        // example: a1 -> sets location 0 to high (0 - 63)
        std::string enpassant_location = fen_tokens.at(3);

        if (enpassant_location != "-") {
            int enpassant_location_as_int = (enpassant_location[0] - 97) + ((8 - (enpassant_location[1] - 48)) * 8);
            position.enpassant = Constants::int_to_uint.at(enpassant_location_as_int);
        } else {
            position.enpassant = 0;
        }

        // 5th token is the halfmove clock
        position.halfmove_clock = std::stoi(fen_tokens.at(4));

        // 6th token is the fullmove number, starts at 1
        position.fullmove_clock = std::stoi(fen_tokens.at(5));

        return position;
    }
}  // namespace Initializers

namespace Output {
    void PrintPosition(Position position) {
        char piece_locations[64]{};
        uint64_t binary_position;

        for (int i = 0; i < 64; i++) {
            binary_position = 1;
            binary_position = binary_position << i;

            if (Helpers::PieceUint64HasPieceAtLocation(position.white_pawns, binary_position)) {
                piece_locations[i] = 'P';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.white_rooks, binary_position)) {
                piece_locations[i] = 'R';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.white_knights, binary_position)) {
                piece_locations[i] = 'N';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.white_bishops, binary_position)) {
                piece_locations[i] = 'B';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.white_queens, binary_position)) {
                piece_locations[i] = 'Q';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.white_king, binary_position)) {
                piece_locations[i] = 'K';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.black_pawns, binary_position)) {
                piece_locations[i] = 'p';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.black_rooks, binary_position)) {
                piece_locations[i] = 'r';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.black_knights, binary_position)) {
                piece_locations[i] = 'n';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.black_bishops, binary_position)) {
                piece_locations[i] = 'b';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.black_queens, binary_position)) {
                piece_locations[i] = 'q';
            }

            if (Helpers::PieceUint64HasPieceAtLocation(position.black_king, binary_position)) {
                piece_locations[i] = 'k';
            }
        }

        std::cout << (position.white_to_play ? "White" : "Black") << " to play.\n";
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
    bool PieceUint64HasPieceAtLocation(uint64_t piece_64bit_locations, uint64_t location_to_check) {
        return (piece_64bit_locations & location_to_check) > 0;
    }
}  // namespace Helpers

}  // namespace Gamestate
