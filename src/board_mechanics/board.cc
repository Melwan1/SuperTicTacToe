//
// Created by Melwan Chevassus on 19/05/2024.
//

#include "board.hh"

Board::Board(int size)
    : size_(size)
{}

const std::vector<Board *> &Board::getGridElements() const {
    return grid_elements_;
}

int Board::getSize() const {
    return size_;
}

Player *Board::getWinner() const {
    return winner_;
}

void Board::setElement(int index, Board *element) {
    grid_elements_[index] = element;
}

void Board::setWinner(Player* player) {
    winner_ = player;
}

Board* Board::getElementAtIndex(int index) {
    return grid_elements_.at(index);
}

Board* Board::getElementAtPosition(int i, int j) {
    return grid_elements_.at(i * size_ + j);
}