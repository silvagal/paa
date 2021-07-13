#include <iostream>
#include <vector>

#define DIMENSION 5

typedef std::vector<std::vector<int>> matrix;

void printMatrix(matrix& m, int lines, int columns){
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}

bool isAvailable(matrix& chessboard, const int line, const int column){
    int l, c;
    //searching a queen in the column
    for (l=line-1;l>=0;l--)
        if (chessboard[l][column] == 1)
            return false;

    //searching a queen in the main diagonal
    l = line - 1; c = column - 1;
    while(l >= 0 && c >= 0){
        if (chessboard[l][c] == 1)
            return false;
        l--;c--;
    }

    //searching a queen in the secondary diagonal
    l = line - 1; c = column + 1;
    while(l >= 0 && c < DIMENSION){
        if (chessboard[l][c])
            return false;
        l--;c++;
    }
    return true;
}

bool nQueen(matrix& chessboard, int line){
    if (line == DIMENSION)
        return true;
    for (int c = 0; c < DIMENSION; ++c) {
        if (isAvailable(chessboard, line, c)) {
            chessboard[line][c] = 1;
            if(nQueen(chessboard, line + 1))
                return true;
            chessboard[line][c] = 0;
        }
    }
    return false;
}

int main(){
    matrix chessboard(DIMENSION, std::vector<int> (DIMENSION, 0));

    if (!nQueen(chessboard, 0))
        std::cout << "Impossible to find a solution";
    else
        printMatrix(chessboard, DIMENSION, DIMENSION);

    return 0;
}