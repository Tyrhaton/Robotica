#ifndef CONNECT4_BOARD_H
#define CONNECT4_BOARD_H

#include "../include.h"

/*
 * Represent the Columns of the board
 */
enum Column
{
    A = 0,
    B = 1,
    C = 2,
    D = 3,
    E = 4,
    F = 5,
    G = 6
};

/*
 * Player options for the tiles
 */
enum Player
{
    EMPTY = 0,
    PLAYER1 = 1,
    PLAYER2 = 2
};

class Connect4Board
{
public:
    static constexpr int ROWS = 6;
    static constexpr int COLS = 7;

    array<array<Player, COLS>, ROWS> grid;

    Connect4Board()
    {
        for (auto &row : grid)
        {
            row.fill(Player::EMPTY);
        }
    }

    /**
     * Drop a disk in the lowest empty tile of a Column
     * @param column The column to drop the disc in
     * @param player The player dropping the disc
     */
    bool dropDisc(Column column, Player player)
    {
    }

    /**
     * Check if a player has 4 in a row on the board
     * @param player The player to check for
     * @return true if the player has 4 in a row, false otherwise
     */
    bool checkWin(Player player)
    {
    }

    /**
     * Adds functionality to compare 2 boards their grid
     * @return true if the grids are equal, false otherwise
     */
    bool operator==(const Connect4Board &other) const
    {
        return this->grid == other.grid;
    }

    /**
     * Adds functionality to check if 2 boards their grid are not equal
     * @return true if the grids are not equal, false otherwise
     */
    bool operator!=(const Connect4Board &other) const
    {
        return !(*this == other);
    }
};

#endif // CONNECT4_BOARD_H
