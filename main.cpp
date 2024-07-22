#include <iostream>
#include <stdlib.h>
#include <unistd.h>
#include <conio.h>

#define MAX_WIDTH  20
#define MAX_HEIGHT 20

bool gameOver;
int xFruit;
int yFruit;
int xHead;
int yHead;

void setup() {
    gameOver = false;

    xFruit = rand()%(MAX_WIDTH) + 1;
    yFruit = rand()%(MAX_HEIGHT) + 1;

    xHead = MAX_WIDTH/2;
    yHead = MAX_HEIGHT/2;
}

void input() {

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

            else if (i == xHead and j == yHead)
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

}

int main() {
    setup();

    while (!gameOver) {
        draw();
        char key = getch();

        std::count << key << std::endl;
        
        sleep(10);
    }

    return 0;
}