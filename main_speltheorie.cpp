#include "include.h"

int main()
{
    cout << "[!] Starting up system\n";
    Vision vision;
    Connect4Board emptyBoard;
    Player startingPlayer = Player::USER; // USER (user) or BOT (system)

    GameTheorie brain = GameTheorie(emptyBoard, startingPlayer, 7, GameTheorie::Level::HARD, true);
    // SystemControl systemControl;
    InverseKinematica inverseKinematica;

    // systemControl.goHome();

    vision.updateBoard(emptyBoard);

    brain.printBoard();
    bool run = true;

    while (run)
    {
        cout << "[!] Waiting for user input...\n";
        vision.waitUntilUpdated();

        cout << "[+] User input received, updating board state\n";
        Connect4Board updatedBoard = vision.getState();

        cout << "[!] Fetching what move the user played\n";
        Connect4Board::MoveInfo mi = Connect4Board::getMoveDifference(brain.getBoard(), updatedBoard);
        bool userWin = brain.playMove(mi.column, mi.player);

        cout << "[+] User played in column: " << Connect4Board::colToChar(mi.column) << endl;

        if (userWin)
        {
            // end Game
            cout << "[!] User won!" << endl;
            break;
        }

        cout << "[+] calculating best move for bot..." << endl;
        Column bestMove = brain.getBestMove();
        bool botWin = brain.playMove(bestMove, Player::BOT);

        cout << "[+] Bot played in column: " << Connect4Board::colToChar(bestMove) << endl;

        if (botWin)
        {
            // end Game
            cout << "[!] Bot won!" << endl;
            break;
        }
        cout << "[+] Updated board state for vision system" << endl;
        vision.updateBoard(brain.getBoard());

        cout << "[+] Bot played its move, now running the system control to play the move physically..." << endl;
        // systemControl.run(bestMove, inverseKinematica);

        cout << "[+] Waiting until the bot has physically played the move..." << endl;
        vision.waitUntilFinished();

        if (brain.getBoard().full())
        {
            cout << "[!] The board is full, it's a draw!" << endl;
            break;
        }
    }

    cout << "[!] Game over!" << endl;
    cout << "[!] Printing game history:\n";
    brain.printHistory();

    cout << "[!] Shutting Down" << endl;
}