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

bool Board::wonRow(int row, Player *player) {
    for (int col = 0; col < size_; col++) {
        if (grid_elements_.at(row * size_ + col)->getWinner() != player) {
            return false;
        }
    }
    return true;
}

bool Board::wonColumn(int column, Player *player) {
    for (int row = 0; row < size_; row++) {
        if (grid_elements_.at(row * size_ + column)->getWinner() != player) {
            return false;
        }
    }
    return true;
}

bool Board::wonDiagonal(enum Board::Diagonal diagonal, Player* player) {
    // we need to check indices 0, size + 1, 2 * (size + 1), ... if diagonal == PRINCIPAL
    // and size - 1, 2 * (size - 1), 3 * (size - 1), ... if diagonal == ANTI_DIAGONAL
    for (int row = 0; row < size_; row++) {
        if (diagonal == PRINCIPAL && grid_elements_.at(row * (size_ + 1))->getWinner() != player) {
            return false;
        }
        if (diagonal == ANTI_DIAGONAL && grid_elements_.at((row + 1) * (size_ - 1))->getWinner() != player) {
            return false;
        }
    }
    return true;
}

bool Board::wonBoard(Player* player) {
    if (winner_) {
        return winner_ == player;
    }
    for (int index = 0; index < size_; index++) {
        if (wonRow(index, player)) {
            return true;
        }
        if (wonColumn(index, player)) {
            return true;
        }
    }
    if (wonDiagonal(Board::Diagonal::PRINCIPAL, player)) {
        return true;
    }
    if (wonDiagonal(Board::Diagonal::ANTI_DIAGONAL, player)) {
        return true;
    }
    return false;
}

bool Board::checkBoard() {
    if (winner_) {
        return true;
    }
    for (Player* player : players_) {
        if (wonBoard(player)) {
            winner_ = player;
            return true;
        }
    }
    return false;
}