#include <iostream>
#include <stdlib.h>
#include <unistd.h>

bool gameOver;
int MAX_WIDTH  = 20; 
int MAX_HEIGHT = 20;

void setup() {
    gameOver = false;
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
    while (!gameOver) {
        draw();
        
        sleep(10);
    }

    return 0;
}