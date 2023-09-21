#include <iostream>
#include <conio.h>


using namespace std;

bool gameOver;
const int width = 20;
const int height =10;
int x,y; //the snake
int fruitX, fruitY;
int score;
int tailX[100], tailY[100];//tail coodinates
int nTail;
enum eDirection {STOP=0, LEFT, RIGHT, UP, DOWN};
eDirection dir;


void Setup(){
gameOver = false;
dir = STOP;
x = width/2;
y = height/2;
fruitX = rand() % width;
fruitY = rand() % height;
score = 0;
}

void Draw(){
    system("cls"); //clear console

    //draw top border
    for(int i=0; i<width + 2; i++)
        cout << "#";
    cout << endl;

    for (int i=0; i < height; i++){
        for (int j =0; j < width; j++){
            if(j == 0)
                cout << "#"; // left border
            if (i == y && j == x)
                cout << "0"; // snake head
            else if (I == fruitY && j == fruitX)
                cout << "F"; // fruit
            else {
                bool print = false;
                for (int k =0; k < nTail; k++){
                        if (tailX[k] == j && tailY[k]){
                            cout << "o";//snake tail
                            print = true
                        }
                }
                if(!print)
                    cout << " ";
            }
            if(j == width - 1)
                cout << "#";//right border
        }
        cout << endl
    }

    // bottom border
    for (int i = 0; i < width + 2; i++)
        cout << "#";
    cout << endl;
    cout << "Score: " <<score << endl;
}

//input
void Input() {
    if (_kbhit()){
        switch (_getch()){
        case 'a':
            dir = LEFT;
            break;
        case 'd':
            dir = RIGHT;
            break;
        case 'w':
            dir = UP;
            break;
        case 's':
            dir = DOWN;
            break;
        case 'x':
            gameOver = true;
            break;
        }
    }
}

//logic
void Logic() {
    int prevX = tailX[0];
    int prevY = tailY[0];
    int prev2X, prev2Y;
    tailX[0] = x;
    tailY[0] = y;
    for (int i=1; i < nTail; i++){
        prev2X = tailX[i];
        prev2Y = tailY[i];
        tailX[i] = prevX;
        tailY[i] = prevY;
        prevX = prev2X;
        prevY = prev2Y;
    }
    switch (dir){
    case LEFT:
        x--;
        break;
    case RIGHT:
        x++;
        break;
    case UP:
        y--;
        break;
    case DOWN:
        y++;
        break;
    default:
        break;
    }

    //check collisions
    if (x >= width) x = 0; else if (x < 0) x = width - 1;
    if (y >= height) y =0; else if (y <0 ) y = height -1;

    for (int i = 0; i< nTail; i++)
        if (tailX[i] == x && tailY[i] == y)
            gameOver = true;
    if (x == fruitX && y == fruitY){
        score += 10;
        fruitX = rand() %width;
        fruitY = rand() %height;
        nTail++;
    }
}

int main()
{
    Setup();
    while (!gameOver){
        Draw();
        Input();
        Logic();
    }

    return 0;
}
