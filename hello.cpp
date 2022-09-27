#include <SDL.h>
#include <iostream>

const int WIDTH = 800, HEIGHT = 600;
// This allows us to use cout without 
// having to write std::cout or std::endl
// std stands for standard
using namespace std;

int main(int argc, char* argv[]) {

    // cout stands for Character OUTput.
    // the endl passes a condition to the application that the 
    //curser should move to the next line and so it prints what is behind
    cout << "Welcome to kano" << endl;
    // I let the std here to see how it works
    std::cin.get();

    return 0;
}   