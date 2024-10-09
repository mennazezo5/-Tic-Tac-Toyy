#include <iostream>
#include<fstream>
#include<time.h>

using namespace std;

char mark;
int pl = 1;
char s[10];
void initialization() {
    char w = '0';
    for (int i = 0;i < 10;i++) {
        s[i] = w;
        w++;
    }
    pl = 1;
}
void Win(char j) {
    if (j == 'X') { cout << "\a  CONGRATULATIONS You WIN!\n";}
    else { cout << "\a  CONGRATULATIONS Computer WIN!\n"; }  
}
int check() {
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
        else
        {
            cout << "invalid move";
            pl--;
        }
        pl++;
    } while (check() == -1);
    board();
    if (check() == 1) { Win(mark); }

    else {
        initialization();
        Game();
    }

}

