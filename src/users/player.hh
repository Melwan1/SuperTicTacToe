//
// Created by Melwan Chevassus on 19/05/2024.
//

#pragma once

#include <string>

/*
 * =================
 * The Player Class.
 * =================
 *
 * A player is represented by their first name and last name.
 * This class does not contain any information about the board as it is the Board's responsibility
 * to compute if a player has won or not.
 */

class Player {
public:
    Player() = default;
    Player(const std::string&, const std::string&);
private:
    const std::string first_name_;
    const std::string last_name_;
};
