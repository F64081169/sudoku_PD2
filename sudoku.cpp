#include"sudoku.h"

using namespace std;

sudoku::sudoku() {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            sudo[i][j]=0;
            for(int k=0; k<10; k++) {
                Y[i][j][k]=true;
            }
        }
    }
}

void sudoku::set() {
    for(int i=0; i<9; i++) {
        cin>>sudo[i][0]>>sudo[i][1]>>sudo[i][2]>>sudo[i][3]>>sudo[i][4]>>sudo[i][5]>>sudo[i][6]>>sudo[i][7]>>sudo[i][8];
    }
}
void sudoku::print() {
    for(int i=0; i<9; i++) {
        cout<<sudo[i][0]<<" "<<sudo[i][1]<<" "<<sudo[i][2]<<" "<<sudo[i][3]<<" "<<sudo[i][4]<<" "<<sudo[i][5]<<" "<<sudo[i][6]<<" "<<sudo[i][7]<<" "<<sudo[i][8]<<endl;
    }
}
void sudoku::swapNum(int x,int y) {
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            if(sudo[i][j]==x) {
                sudo[i][j]=y;
            } else if(sudo[i][j]==y) {
                sudo[i][j]=x;
            }
        }
    }
}

void sudoku:: swapRow(int x, int y) {
    x*=3;
    y*=3;
    for(int j=0; j<9; j++) {
        int tempOne=sudo[y][j];
        sudo[y][j]=sudo[x][j];
        sudo[x][j]=tempOne;
        int tempTwo=sudo[y+1][j];
        sudo[y+1][j]=sudo[x+1][j];
        sudo[x+1][j]=tempTwo;
        int tempThr=sudo[y+2][j];
        sudo[y+2][j]=sudo[x+2][j];
        sudo[x+2][j]=tempThr;

    }
}
void sudoku::swapCol(int x,int y) {
    x*=3;
    y*=3;
    for(int i=0; i<9; i++) {
        int tempOne=sudo[i][y];
        sudo[i][y]=sudo[i][x];
        sudo[i][x]=tempOne;
        int tempTwo=sudo[i][y+1];
        sudo[i][y+1]=sudo[i][x+1];
        sudo[i][x+1]=tempTwo;
        int tempThr=sudo[i][y+2];
        sudo[i][y+2]=sudo[i][x+2];
        sudo[i][x+2]=tempThr;
    }
}
void sudoku::rotate(int x) {
    int **ptr = new int*[9];
    for(int i=0; i<9; i++) {
        ptr[i]=new int[9];
    }
    for(int i=0; i<9; i++) {
        for(int j=0; j<9; j++) {
            ptr[i][j]=sudo[i][j];
        }
    }
    switch(x) {
    case 0:
        break;
    case 1:
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sudo[i][j]=ptr[8-j][i];
            }
        }
        break;
    case 2:
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sudo[i][j]=ptr[8-i][8-j];
            }
        }
        break;
    case 3:
        for(int i=0; i<9; i++) {
            for(int j=0; j<9; j++) {
                sudo[i][j]=ptr[j][8-i];
            }
        }
        break;
    }
    for(int i=0; i<9; i++) {
        delete []ptr[i];
    }
    delete []ptr;
}
void sudoku::flip(int x) {
    switch(x) {
    case 0:
        for(int j=0; j<9; j++) {
            for(int i=0; i<4; i++) {
                int tempOne=sudo[i][j];
                sudo[i][j]=sudo[8-i][j];
                sudo[8-i][j]=tempOne;
            }
        }
        break;
    case 1:
        for(int i=0; i<9; i++) {
            for(int j=0; j<4; j++) {
                int tempTwo=sudo[i][j];
                sudo[i][j]=sudo[i][8-j];
                sudo[i][8-j]=tempTwo;
            }
        }
        break;
    }
}
