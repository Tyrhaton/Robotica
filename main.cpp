#include "include.h"

int main()
{
    cout << "[!] Starting up system\n";
    Vision vision;
    Connect4Board emptyBoard;
    Player me = Player::PLAYER2;

    GameTheorie gameTheorie(emptyBoard, me, Player::PLAYER1, 2, GameTheorie::Level::EASY);
    SystemControl systemControl;
    InverseKinematica inverseKinematica;

    systemControl.goHome();

    vision.updateBoard(emptyBoard);

    bool run = true;

    while (run)
    {
        vision.waitUntilUpdated();
        Connect4Board board = vision.getState();
        Column bestMove = gameTheorie.getBestMove(board, me);
        bool win = board.dropDisc(bestMove, me);

        if (win)
        {
            // end Game
            break;
        }
        vision.updateBoard(board);

        systemControl.run(bestMove, inverseKinematica);
        vision.waitUntilFinished();
    }
    cout << "[!] Shutting Down";
}