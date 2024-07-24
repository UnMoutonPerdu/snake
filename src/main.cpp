#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include "../include/kbhit.h"

#define MAX_WIDTH  20
#define MAX_HEIGHT 20

bool gameOver;
int score;
int xFruit;
int yFruit;
int xHead;
int yHead;
std::vector<std::pair<int,int>> tail;

enum Directions {UP, DOWN, RIGHT, LEFT};
Directions dir;

void setup() {
    gameOver = false;
    score = 0;

    xFruit = rand()%(MAX_WIDTH) + 1;
    yFruit = rand()%(MAX_HEIGHT-1) + 1;

    xHead = MAX_WIDTH/2;
    yHead = MAX_HEIGHT/2;

    tail.push_back(std::pair<int, int>(xHead, yHead));
    dir = Directions::UP;
}

void draw() {
    std::system("clear");
    for(int i=0; i<MAX_WIDTH; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for(int j=0; j<MAX_HEIGHT; j++) {
        for(int i=0; i<MAX_WIDTH; i++) {
            if (i%(MAX_WIDTH-1) == 0) {
                std::cout << "#";
            }

            else if (i == xFruit and j == yFruit)
            {
                std::cout << "\u25A1";
            }

            else if (std::find(tail.begin(), tail.end(), std::pair<int, int>(i, j)) != tail.end())
            {
                std::cout << "\u25C9";
            }
            
            else {
                std::cout << " ";
            }
        }
        std::cout << std::endl;
    }

    for(int i=0; i<MAX_WIDTH; i++) {
        std::cout << "#";
    }
    std::cout <<std::endl;
}

void logic() {
    if (xHead == xFruit && yHead == yFruit) {
        score += 1;
        xFruit = rand()%(MAX_WIDTH) + 1;
        yFruit = rand()%(MAX_HEIGHT-1) + 1;
        tail.push_back(std::pair<int, int>(xHead, yHead));
    }

    if (_kbhit()) {
        char kInput = getchar(); 
        switch (dir)
        {
        case Directions::UP:
            switch (kInput)
            {
                case 'a':
                    dir = Directions::LEFT;
                    break;

                case 'd':
                    dir = Directions::RIGHT;
                    break;

                case 'm':
                    exit(0);
                    break;
                
                default:
                    break;
            }
            break;

        case Directions::DOWN:
            switch (kInput)
            {
                case 'a':
                    dir = Directions::LEFT;
                    break;

                case 'd':
                    dir = Directions::RIGHT;
                    break;

                case 'm':
                    exit(0);
                    break;
                
                default:
                    break;
            }
            break;

        case Directions::LEFT:
            switch (kInput)
            {
                case 'w':
                    dir = Directions::UP;
                    break;

                case 's':
                    dir = Directions::DOWN;
                    break;

                case 'm':
                    exit(0);
                    break;
                
                default:
                    break;
            }
            break;

        case Directions::RIGHT:
            switch (kInput)
            {
                case 'w':
                    dir = Directions::UP;
                    break;

                case 's':
                    dir = Directions::DOWN;
                    break;

                case 'm':
                    exit(0);
                    break;
                
                default:
                    break;
            }
            break;
        
        default:
            break;
        }
    }

    switch (dir)
    {
    case Directions::UP:
        yHead--;
        break;

    case Directions::DOWN:
        yHead++;
        break;

    case Directions::LEFT:
        xHead--;
        break;

    case Directions::RIGHT:
        xHead++;
        break;
    
    default:
        break;
    }

    if (xHead <= 0 || xHead >= MAX_WIDTH-1 || yHead < 0 || yHead >= MAX_HEIGHT) {
        gameOver = true;
    }

    tail.erase(tail.begin());
    tail.push_back(std::pair<int, int>(xHead, yHead));
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        std::cout << "Score: " << score << std::endl;
        std::cout << xFruit << " " << yFruit << std::endl;
        logic();
        usleep(130000);
    }

    return 0;
}

