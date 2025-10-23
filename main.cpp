#include "GameWindow.hpp"
#include "SnakeGame.hpp"

#include<iostream>
#include<memory>


using namespace std;

int main() {

    unique_ptr<GameWindow> sg = make_unique<SnakeGame>();

    sg->start();


    return 0;
    
}