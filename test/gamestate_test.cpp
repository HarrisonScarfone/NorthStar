#include "../src/gamestate.h"

#include <gtest/gtest.h>

#include <cstdint>

// Tech Debt: The starting position initialized by Gamestate::Initializers::StartingPosition
// is assumed to create the correct starting position. Can be tested later if deemed necessary.
// Testing of PrintPosition is also omitted

namespace {
TEST(GamestateTest, location_has_piece_and_returns_true) {
    // use A file for piece locations and check a square in A file
    uint64_t piece_64bit_locations = 0x101010101010101L;
    uint64_t location_to_check = 1;

    EXPECT_TRUE(Gamestate::Helpers::PieceUint64HasPieceAtLocation(piece_64bit_locations, location_to_check));
}

TEST(GamestateTest, starting_position_initializes_properly_from_fen_string) {
    Gamestate::Position starting_position = Gamestate::Initializers::StartingPosition();
    Gamestate::Position starting_position_from_fen_string =
        Gamestate::Initializers::PositionFromFenString("rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq - 0 1");

    EXPECT_EQ(starting_position.black_bishops, starting_position_from_fen_string.black_bishops);
    EXPECT_EQ(starting_position.white_queens, starting_position_from_fen_string.white_queens);
    EXPECT_EQ(starting_position.enpassant, starting_position_from_fen_string.enpassant);
    EXPECT_EQ(starting_position.halfmove_clock, starting_position_from_fen_string.halfmove_clock);
    EXPECT_EQ(starting_position.fullmove_clock, starting_position_from_fen_string.fullmove_clock);
}

TEST(GamestateTest, position_initializes_properly_from_fen_string_with_hyphon) {
    // b6 -> 17 -> 131072 (uint64_t)
    std::string fen_string_under_test = "rnbqkbnr/pppppppp/8/8/8/8/PPPPPPPP/RNBQKBNR w KQkq b6 0 1";

    Gamestate::Position position = Gamestate::Initializers::PositionFromFenString(fen_string_under_test);

    EXPECT_EQ(position.enpassant, 131072);
}
}  // namespace
