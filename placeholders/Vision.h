#ifndef VISION_H
#define VISION_H

#include "../include.h"

class Vision
{
public:
    Connect4Board currentBoard;

    Vision()
    {
    }

    /**
     * Update the current board
     */
    void updateBoard(Connect4Board newBoard)
    {
        currentBoard = newBoard;
    }

    /**
     * Sleep until there is a new board
     */
    void waitUntilUpdated()
    {
        while (getState() == currentBoard)
        {
            sleep(1);
        }
    }

    /**
     * Sleep until the current board is finished
     */
    void waitUntilFinished()
    {

        while (getState() != currentBoard)
        {
            sleep(1);
        }
    }

    /**
     * Get the current state of the board using the Vision system
     * @return The current state of the board
     */
    Connect4Board getState()
    {
        Connect4Board board = Connect4Board();
        return board;
    }
};

#endif