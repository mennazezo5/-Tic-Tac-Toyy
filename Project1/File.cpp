#include <iostream>
#include<fstream>
#include<time.h>

using namespace std;
int wins = 0, loses = 0;
char mark;
int pl = 1;
char s[10];
int NOG = 1;
int End = 1;
void initialization() {
    char w = '0';
    for (int i = 0;i < 10;i++) {
        s[i] = w;
        w++;
    }
    pl = 1;
}
void saveResults(int p) {

    fstream file;
    file.open("score.csv", ios::app);
    if (p == 1) { file << "game " << NOG << ":," << "WINS!\n"; }
    else { file << "game " << NOG << ":, " << "LOSE\n"; }
    NOG++;
}
void clearResults() {
    wins = 0, loses = 0;
    NOG = 1;
    ofstream file("score.csv", ios::trunc);
    if (file.is_open()) {
        cout << "History cleared.\n";
        file.close();
    }
    else { cout << "Unable to open file"; }
}
void showResults( ) {
 cout<< "Wins:" << wins << " \nLoses:"<<  loses ;
   
}
void Win(char j) {
    if (j == 'X') {
        pl = 1;
        wins++;
        cout << "\a  CONGRATULATIONS You WIN!\n";}
    else {
        pl = 2;
        loses++;
        cout << "\a  CONGRATULATIONS Computer WIN!\n"; } 
    saveResults(pl);
}
int check() {
    if (End == 0) { return -2; }
    else {
        if (s[1] == s[2] && s[2] == s[3]) { return 1; }
        else if (s[4] == s[5] && s[5] == s[6]) { return 1; }
        else if (s[7] == s[8] && s[8] == s[9]) { return 1; }
        else if (s[1] == s[4] && s[4] == s[7]) { return 1; }
        else if (s[2] == s[5] && s[5] == s[8]) { return 1; }
        else if (s[3] == s[6] && s[6] == s[9]) { return 1; }
        else if (s[1] == s[5] && s[5] == s[9]) { return 1; }
        else if (s[3] == s[5] && s[5] == s[7]) { return 1; }
        else if (s[1] != '1' && s[2] != '2' && s[3] != '3'
            && s[4] != '4' && s[5] != '5' && s[6] != '6'
            && s[7] != '7' && s[8] != '8' && s[9] != '9')
        {
            return 0;
        }
        else { return -1; }
    }
}
void board() {
    system("cls");
    cout << "\n\n      tic tac toy game \n\n";
    cout << "        player 1 (X) - player 2 (o)" << endl << endl << endl;
    cout << "           " << s[1] << " | " << s[2] << " | " << s[3] << endl;
    cout << "          ___|___|___" << endl;
    cout << "           " << s[4] << " | " << s[5] << " | " << s[6] << endl;
    cout << "          ___|___|___" << endl;
    cout << "           " << s[7] << " | " << s[8] << " | " << s[9] << endl;
    cout << "             |   |   " << endl << endl;
    cout << "Enter [0] to end game or continue \n";
}
void Game() {
    int cho;
    do
    {
        board();
        pl = (pl % 2) ? 1 : 2;
        cout << "        player " << pl << "  enter the num:";
        if (pl == 1) { cin >> cho; }
        else
        {
            srand(time(NULL));
            cho = rand() % 9+1;
        }
        mark = (pl == 1) ? 'X' : 'o';
        if (cho == 1 && s[1] == '1') { s[1] = mark; }
        else if (cho == 2 && s[2] == '2') { s[2] = mark; }
        else if (cho == 3 && s[3] == '3') { s[3] = mark; }
        else if (cho == 4 && s[4] == '4') { s[4] = mark; }
        else if (cho == 5 && s[5] == '5') { s[5] = mark; }
        else if (cho == 6 && s[6] == '6') { s[6] = mark; }
        else if (cho == 7 && s[7] == '7') { s[7] = mark; }
        else if (cho == 8 && s[8] == '8') { s[8] = mark; }
        else if (cho == 9 && s[9] == '9') { s[9] = mark; }
        else if (cho == 0) { End = 0;}
        else
        {
            cout << "invalid move";
            pl--;
        }
        pl++;
    } while (check() == -1);
    board();
    if (check() == 1) { Win(mark);
    
    }
    else if (check() == -2) {}
    else {
        initialization();
        Game();
    }

}
void showMenu() {
   
    int choice;
    while (End != 0) {
        cout << "\nChoose an option:\n";
        cout << "[1]: New Game\n";
        cout << "[2]: History\n";
        cout << "[3]: Clear History\n";
        cin >> choice;
        if (choice == 1) {
            initialization();
            Game();
        }
        else if (choice == 2) {
            cout << "\nHistory:\n";
            showResults();
            cout << "\nChoose an option:\n";
            cout << "[1]:Back to main menu\n";
            cout << "[2]: New Game\n";
            cout << "[3]: Clear History\n";
            cin >> choice;
            if (choice == 1) {
                showMenu();
            }
            else if (choice == 2) {
                initialization();
                Game();
            }
            else if (choice == 3) {
                clearResults();
            }
        }
        else if (choice == 3) {
            clearResults();
        }
    }
}
