#include "include.h"

int main()
{
    cout << "[!] Starting up system\n";
    Vision vision;
    Connect4Board emptyBoard;
    Player startingPlayer = Player::USER; // USER (user) or BOT (system)

    GameTheorie gameTheorie(emptyBoard, startingPlayer, 7, GameTheorie::Level::HARD, true);
    SystemControl systemControl;
    InverseKinematica inverseKinematica;

    systemControl.goHome();

    vision.updateBoard(emptyBoard);

    bool run = true;

    while (run)
    {
        vision.waitUntilUpdated();
        Connect4Board board = vision.getState();
        Column bestMove = gameTheorie.getBestMove();
        bool win = board.dropDisc(bestMove, Player::BOT);

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