#include <iostream>

#include "board_mechanics/board.hh"

#include <memory>

int main() {
    std::shared_ptr<Board> board = std::make_shared<Board>(Board(4));
    return 0;
}
