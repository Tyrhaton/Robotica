#include "include.h"

int main()
{
    cout << "[!] Starting up system\n";

    // Maak een instantie van de fysieke robotarm
    // Deze klasse beheert alle bewegingen en toegang tot de gewrichten van de arm
    RobotArm robotArm;

    // Initialiseer een leeg Connect Four-bord
    Connect4Board emptyBoard;

    // Stel in dat de gebruiker (mens) mag beginnen
    Player startingPlayer = Player::USER;

    // Maak het spelbrein aan: dit object beheert het spel, AI-logica en bordstatus
    // Parameters: bord, wie begint, zoekdiepte, moeilijkheidsgraad, gebruik van advanced pruning
    GameTheorie brain(emptyBoard, startingPlayer, 7, GameTheorie::Level::HARD, true);

    // Toon het startbord in de terminal
    brain.printBoard();

    bool run = true;
    string move;

    while (run)
    {
        // === Gebruiker voert zet in ===
        cout << "User: Enter your move (A-G) or 'exit' to quit: ";
        getline(cin, move);
        if (move == "exit" || move == "Exit" || move == "quit" || move == "q")
            break;

        // Zet van gebruiker wordt verwerkt
        Column userCol = Connect4Board::charToColumn(move[0]);
        bool userWin = brain.playMove(userCol, Player::USER);

        cout << "[+] User played in column: " << Connect4Board::colToChar(userCol) << endl;
        brain.printBoard();

        // Check of gebruiker gewonnen heeft
        if (userWin)
        {
            cout << "[!] User won!" << endl;
            break;
        }

        // Check op gelijkspel
        if (brain.getBoard().full())
        {
            cout << "[!] The board is full, it's a draw!" << endl;
            break;
        }

        // === Bot bepaalt en speelt zijn zet ===
        cout << "[+] Calculating best move for bot..." << endl;
        Column bestMove = brain.getBestMove();
        cout << "[+] Bot chose column: " << Connect4Board::colToChar(bestMove) << endl;

        // Haal fysieke doelpositie op op basis van kolomnummer
        StandardPositions::Position p = StandardPositions::getPosition(static_cast<int>(bestMove));

        // Laat robotarm fysiek bewegen naar doelpositie
        cout << "[+] Moving robot arm to play the move..." << endl;
        robotArm.moveTo(p.pos, p.orientation);
        cout << "[+] Move physically executed." << endl;

        // Sla de huidige gewrichtshoeken op naar bestand
        std::vector<float> finalAngles;
        for (const Joint& joint : robotArm.joints)
            finalAngles.push_back(joint.getAngle());

        writeToFile(finalAngles, "/home/nout/ros2_ws/joints.txt");

        // Voer de zet ook uit op het interne spelbord
        bool botWin = brain.playMove(bestMove, Player::BOT);
        cout << "[+] Bot played in column: " << Connect4Board::colToChar(bestMove) << endl;
        brain.printBoard();

        // Check of bot gewonnen heeft
        if (botWin)
        {
            cout << "[!] Bot won!" << endl;
            break;
        }

        // Check opnieuw op gelijkspel (na botzet)
        if (brain.getBoard().full())
        {
            cout << "[!] The board is full, it's a draw!" << endl;
            break;
        }
    }

    // === Einde van het spel ===
    cout << "[!] Game over!" << endl;
    cout << "[!] Printing game history:\n";
    brain.printHistory();
    cout << "[!] Shutting down\n";

    return 0;
}
