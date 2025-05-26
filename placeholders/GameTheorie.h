#ifndef GT_H
#define GT_H

#include "../include.h"

class GameTheorie
{
public:
    GameTheorie()
    {
    }

    /**
     * Get the best move for the current player
     * @param board The current state of the board
     * @param player The current player
     * @return The best move as a Column
     */
    Column getBestMove(Connect4Board board, Player player)
    {
        return Column::A;
    }
};

#endif