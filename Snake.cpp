#include <iostream>
#include <curses.h>
#include <sys/ioctl.h>
#include <termios.h>
//#include <termios.h>
//#include <unistd.h>
//#include <fcntl.h>

using namespace std;

// define variables
bool gameOver;
const int width = 20;
const int height = 20;
int x, y, fruitX, fruitY, score;
enum eDirection {STOP, LEFT, RIGHT, UP, DOWN};
eDirection dir; 

// declara las funciones
bool kbhit()
{
    termios term;
    tcgetattr(0, &term);

    termios term2 = term;
    term2.c_lflag &= ~ICANON;
    tcsetattr(0, TCSANOW, &term2);

    int byteswaiting;
    ioctl(0, FIONREAD, &byteswaiting);

    tcsetattr(0, TCSANOW, &term);

    return byteswaiting > 0;
}

void Setup() {
    gameOver = false;
    dir = STOP;
    x = width / 2;
    y = height / 2;
    score = 0;  
}

void Draw() {
    system("clear");
    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;

    for (int i = 0; i < height; i++) {
        for (int j = 0; j < width; j++) {
            if (j == 0)
                cout << "#";
            if (i == y && j == x)
                cout << "O";
            else if (i == fruitY && j == fruitX)
                cout << "F";
            else {
                cout << " ";
            }

            if (j == width-1)
                cout << "#";            
        }

        cout << endl;
    }

    for (int i = 0; i < width+2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " << score << endl;    
}

void Input() {
    //enable_raw_mode();
    if (kbhit()) {
        switch (getch()) {
            case 'x':
                gameOver = true;
                break;
        }
    }
    //disable_raw_mode;
    //tcflush(0, TCIFLUSH);
}

void Logic() {

}

int main() {
    Setup();
    while (!gameOver) {
        Draw();
        Input();
        Logic();
        //sleep(10);
    }

    return 0;
}