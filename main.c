#include <stdio.h>
#include <stdlib.h>
#include <memory.h>

int count = 0;

const int QUEEN_COUNT = 8;
const char INIT_MARK = 'X';
const char QUEEN_MARK = 'Q';
const char WHITE_MARK = ' ';

static char eight_queen_row_col[QUEEN_COUNT] = { INIT_MARK };
void print(){

    for (int i = 0; i < QUEEN_COUNT; i++){
        for (int j = 0; j < QUEEN_COUNT; j ++)

			printf("%c%c", j == eight_queen_row_col[i] ? QUEEN_MARK : INIT_MARK, j == QUEEN_COUNT - 1 ? '\n' : WHITE_MARK);
    }
}

int check_pos_valid(int row, int col){

    for (int i = 0; i < row; i++){

        int c = eight_queen_row_col[i];
        if (col == c || (i + c) == (row + col) || (i - c) == (row - col))
            return 0;
    }
    return 1;
}

void eight_queen(int row){

    for (int col = 0; col < QUEEN_COUNT; col++){

        if (check_pos_valid(row, col)){

            eight_queen_row_col[row] = col;
            if (row == QUEEN_COUNT - 1){

                printf("%d\n", ++ count);
                print();
                eight_queen_row_col[row] = 0;
                return;
            }
            eight_queen(row + 1);
            eight_queen_row_col[row] = 0;
        }
    }
}

int main(int argc, char *argv[]) {

	eight_queen(0);
    return 0;
}