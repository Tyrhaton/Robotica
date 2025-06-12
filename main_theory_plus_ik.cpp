#include "include.h"

int main()
{
    cout << "[!] Starting up system\n";

    RobotArm robotArm;
    Connect4Board emptyBoard;
    Player startingPlayer = Player::USER;
    GameTheorie brain(emptyBoard, startingPlayer, 7, GameTheorie::Level::HARD, true);

    brain.printBoard();
    bool run = true;
    string move;

    while (run)
    {
        cout << "User: Enter your move (A-G) or 'exit' to quit: ";
        getline(cin, move);
        if (move == "exit" || move == "Exit" || move == "quit" || move == "q")
        {
            break;
        }

        Column userCol = Connect4Board::charToColumn(move[0]);
        bool userWin = brain.playMove(userCol, Player::USER);
        cout << "[+] User played in column: " << Connect4Board::colToChar(userCol) << endl;

        brain.printBoard();

        if (userWin)
        {
            cout << "[!] User won!" << endl;
            break;
        }

        cout << "[+] Calculating best move for bot..." << endl;
        Column bestMove = brain.getBestMove();
        cout << "[+] Bot chose column: " << Connect4Board::colToChar(bestMove) << endl;

        // Haal doelpositie op
        // StandardPositions::Position p = StandardPositions::getPosition((int)bestMove);
        StandardPositions::Position p = StandardPositions::getPosition((int)bestMove);

        cout << "[+] Moving robot arm to play the move..." << endl;
        robotArm.moveTo(p.pos, p.orientation);
        cout << "[+] Move physically executed." << endl;

        // Sla hoeken op NA het bewegen
        std::vector<float> finalAngles;
        for (const Joint &joint : robotArm.joints)
        {
            finalAngles.push_back(joint.getAngle());
        }
        std::string filename = "/home/nout/ros2_ws/joints.txt";
        writeToFile(finalAngles, filename);

        // Pas de zet toe op het virtuele bord
        bool botWin = brain.playMove(bestMove, Player::BOT);
        cout << "[+] Bot played in column: " << Connect4Board::colToChar(bestMove) << endl;

        brain.printBoard();

        if (botWin)
        {
            cout << "[!] Bot won!" << endl;
            break;
        }

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

    return 0;
}
