#ifndef SUDOKU_H
#define SUDOKU_H
#include<iostream>
#include<vector>
#include<algorithm>
#include<fstream>
#include<string.h>

using namespace std;
/***************************************************
 * Finish your .cpp according to this header file. *
 * You can modify this file if needed.             *
 ***************************************************/

class sudoku {
  public:
    sudoku();
    // generate
    static sudoku generate();

    // transform
    void set();
    void print();
    void swapNum(int x, int y);
    void swapRow(int x, int y);
    void swapCol(int x, int y);
    void rotate(int x);
    void flip(int x);

    // solve

  private:
    int sudo[9][9];
    bool Y[9][9][10];
};

#endif // SUDOKU_H
