#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <vector>
#include <algorithm>
#include "../include/kbhit.h"

bool gameOver;
int score;
int xFruit;
int yFruit;
int xHead;
int yHead;
int gridSize;
std::vector<std::pair<int,int>> tail;

enum Directions {UP, DOWN, RIGHT, LEFT};
Directions dir;

void setup() {
    std::cout << "Choose a grid size (at least 6): ";
    std::cin >> gridSize;
    while (gridSize < 6) {
        std::cout << "Choose a grid size (at least 6): ";
        std::cin >> gridSize;
    }

    srand(time(0));
    gameOver = false;
    score = 0;

    xFruit = rand()%(gridSize-2) + 1;
    yFruit = rand()%(gridSize-2) + 1;

    xHead = gridSize/2;
    yHead = gridSize/2;

    dir = Directions::UP;
}

void draw() {
    std::system("clear");
    for(int i=0; i<gridSize; i++) {
        std::cout << "#";
    }
    std::cout << std::endl;

    for(int j=1; j<gridSize-1; j++) {
        for(int i=0; i<gridSize; i++) {
            if (i%(gridSize-1) == 0) {
                std::cout << "#";
            }

            else if (i == xFruit and j == yFruit)
            {
                std::cout << "\u25A1";
            }

            else if (i == xHead and j == yHead)
            {
                std::cout << "\u25C9";
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

    for(int i=0; i<gridSize; i++) {
        std::cout << "#";
    }
    std::cout <<std::endl;
}

void logic() {
    if (xHead == xFruit && yHead == yFruit) {
        score += 1;
        xFruit = rand()%(gridSize-2) + 1;
        yFruit = rand()%(gridSize-2) + 1;
        while (std::find(tail.begin(), tail.end(), std::pair<int, int>(xFruit, yFruit)) != tail.end() || (xFruit == xHead && yFruit == yHead)) {
            xFruit = rand()%(gridSize-2) + 1;
            yFruit = rand()%(gridSize-2) + 1;
        }
        tail.push_back(std::pair<int, int>(xHead, yHead));
    }
    else {
        if (std::find(tail.begin(), tail.end(), std::pair<int, int>(xHead, yHead)) != tail.end()) {
            gameOver = true;
        }
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

    if (score > 0) {
        tail.erase(tail.begin());
        tail.push_back(std::pair<int, int>(xHead, yHead));
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

    if (xHead <= 0 || xHead >= gridSize-1 || yHead <= 0 || yHead >= gridSize-1) {
        gameOver = true;
    }
}

int main() {
    setup();

    while (!gameOver) {
        draw();
        std::cout << "Score: " << score << std::endl;
        std::cout << "Press (m) to quit" << std::endl;
        logic();
        usleep(140000);
    }

    return 0;
}

