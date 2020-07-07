#include"sudoku.h"

using namespace std;

int main() {
    // finish your generate code...
    int generate[9][9]= {{1,2,0,5,0,0,0,0,3},
        {6,0,3,0,8,0,0,0,0},
        {0,5,0,0,0,6,0,2,8},
        {3,8,7,0,0,1,4,0,9},
        {0,0,5,0,0,0,3,0,0},
        {2,0,6,9,0,0,7,8,5},
        {5,3,0,4,0,0,0,7,0},
        {0,0,0,0,1,0,9,0,4},
        {4,0,0,0,0,3,0,5,1}
    };

    int i, j;
    for(i=0; i<9; ++i) {
        for(j=0; j<9; ++j) {
            cout<<generate[i][j]<<' ';
        }
        cout<<'\n';
    }

    return 0;
}
