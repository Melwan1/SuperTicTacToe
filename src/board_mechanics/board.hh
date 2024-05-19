//
// Created by Melwan Chevassus on 19/05/2024.
//

#pragma once

#include <vector>

#include "../users/player.hh"

/*
 * ================
 * The Board Class.
 * ================
 *
 * To understand the goal of this class, we first need to know what we want to do, that is a SuperTicTacToe.
 * Essentially, a SuperTicTacToe is a 9x9 grid composed of 9 grids of size 3x3, which themselves are composed of 9 tiles.
 * However, we might want to change this later. For instance, a SuperTicTacTeo might be a grid of 9 grids of size 9x9 (so a 27x27 grid),
 * which are themselves composed of 9 grids of size 3x3, and so on.
 * There is no limit on the depth level of the tiles.
 *
 * Therefore, a Tile will be a child of Board (in terms of classes), and a Board will be composed of 9 boards (which can be individual Tiles).
 *
 * Besides, the size of the board might not be 3 for later uses of the game. So we do not want to hardcode the size,
 * but set it to 3 if no other sizes are passed in the constructor.
 */

class Board {
public:
    Board() = default;
    Board(int size);

    const std::vector<Board *> &getGridElements() const;
    int getSize() const;
    Player *getWinner() const;
    Board* getElementAtIndex(int index);
    Board* getElementAtPosition(int i, int j);

    void setElement(int index, Board* board);
    void setWinner(Player* player);

private:
    std::vector<Board*> grid_elements_;
    int size_ = 3;
    Player* winner_ = nullptr;
};
