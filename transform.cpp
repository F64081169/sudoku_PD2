#include"sudoku.h"
#include<string.h>

using namespace std;

int main() {
    sudoku sudo;
    sudo.set();
    int order[4];
    for(int num = 0; num<4; num++) {
        cin>>order[num];
        if(cin.get() == '\n') {
            break;
        }
    }
    while(order[0] !=0) {
        switch(order[0]) {
        case 1:
            sudo.swapNum(order[1],order[2]);
            break;
        case 2:
            sudo.swapRow(order[1],order[2]);
            break;
        case 3:
            sudo.swapCol(order[1],order[2]);
            break;
        case 4:
            order[1]%=4;
            sudo.rotate(order[1]);
            break;
        case 5:
            sudo.flip(order[1]);
            break;
        }
        for(int num=0; num<4; num++) {
            cin>>order[num];
            if(cin.get() =='\n') {
                break;
            }
        }
    }
    sudo.print();

    return 0;
}
