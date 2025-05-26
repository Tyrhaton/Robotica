#include "include.h"

int main()
{
    cout << "[!] Starting up system\n";
    Vision vision = Vision();
    GameTheorie gameTheorie = GameTheorie();
    SystemControl systemControl = SystemControl();
    InverseKinematica inverseKinematica = InverseKinematica();

    Player me = Player::PLAYER2;

    systemControl.goHome();

    Connect4Board emptyBoard = Connect4Board();
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