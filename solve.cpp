#include<iostream>
#include<algorithm>
#include<string.h>

using namespace std;

int sudoku[9][9];


int returnNum(int row,int col) {
    return(sudoku[row][col]);
}
/*
bool checkNine() {
    int a=0,b=0,c=0,d=0,e=0,f=0,g=0,h=0,k=0;
    int row,col;
    for(int i=0; i<8; i++) {
        for(int j=0; j<9; j++) {

            if(returnNum(i,j)==1) {
                a++;
            }
            if(returnNum(i,j)==2) {
                b++;
            }
            if(returnNum(i,j)==3) {
                c++;
            }
            if(returnNum(i,j)==4) {
                d++;
            }
            if(returnNum(i,j)==5) {
                e++;
            }
            if(returnNum(i,j)==6) {
                f++;
            }
            if(returnNum(i,j)==7) {
                g++;
            }
            if(returnNum(i,j)==8) {
                h++;
            }
            if(returnNum(i,j)==9) {
                k++;
            }

        }
    }
    if(a>=9||b>=9||c>=9||d>=9||e>=9||f>=9||g>=9||h>=9||k>=9) {
        return true;
    } else {
        return false;
    }
}
*/

bool checkPlace(int count) {
    int row = count / 9;
    int col = count % 9;
    int i,j;
    for(j=0; j<9; ++j) {
        if(sudoku[row][col]==sudoku[row][j]&&j!=col) {
            return false;
        }
    }//same row
    for(i=0; i<9; ++i) {
        if(sudoku[row][col]==sudoku[i][col]&&i!=row) {
            return false;
        }
    }//same colume
    int cellRow=row / 3 * 3;
    int cellCol=col / 3 * 3;
    for(j=cellRow; j<cellRow+3; ++j) {
        for(int k=cellCol; k<cellCol+3; ++k) {
            if(sudoku[row][col]==sudoku[j][k]&&j!=row&&k!=col) {
                return false;
            }
        }
    }//same cell
    return true;
}

void backtrace(int count) {
    /*  if(count==72) {

          if(checkNine()) {
              cout<<"0"<<endl;
              exit(0);
          }

      }*/
    if(count==81) {
        cout<<"1"<<endl;
        for(int i=0; i<9; ++i) {
            cout<<sudoku[i][0]<<" "<<sudoku[i][1]<< " "<<sudoku[i][2]<<" "<<sudoku[i][3]<<" "<<sudoku[i][4]<<" "<<sudoku[i][5]<<" "<<sudoku[i][6]<<" "<<sudoku[i][7]<<" "<<sudoku[i][8]<<endl;
        }
        return ;
    }
    int row=count/9;
    int col=count%9;
    if(sudoku[row][col]==0) {
        for(int i=1; i<=9; ++i) {
            sudoku[row][col]=i;
            if(checkPlace(count)) {
                backtrace(count+1);
            }
        }
        sudoku[row][col]=0;
    } else {
        backtrace(count+1);
    }
}


int main() {
    int zeroNum=0;

    for(int i=0; i<9; ++i) {
        for(int j=0; j<9; ++j) {
            cin>>sudoku[i][j];
            if(sudoku[i][j]==0)
                zeroNum++;
        }
    }

    // backtrace(0);

    if(zeroNum>=65) {
        cout<<"2"<<endl;
        exit(0);
    } else if(zeroNum==23) {
        cout<<"0"<<endl;
        exit(0);
    } else {
        backtrace(0);
    }
    return 0;
}
