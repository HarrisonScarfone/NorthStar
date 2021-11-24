#ifndef MOVE_H
#define MOVE_H

struct Move {
    int from_square;
    int to_square;

    bool is_capture;
    // use 1 hot encoding on 6 bit int for piece type for a fast & to determine which peice
    // we have -> 100000 (P) -> R -> N -> B -> Q -> K (000001)
    int captured_piece;

    // 1 hot encoding on 4 bit int
    // 1000 (kingside white castle rights) -> (qswc) -> (bskc) -> (bsqc)
    int is_castle_move;
    int remove_castling_rights;

    bool is_promotion;
    // promo piece use same 1 hot encoding as captured piece
    int promotion_piece;
};

#endif