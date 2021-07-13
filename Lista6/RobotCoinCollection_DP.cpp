#include <iostream>
#include <ctime>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

void generateMatrixCoin(matrix& coins, int& lines, int& columns){
    for (int i = 0; i < lines; ++i)
        for (int j = 0; j < columns; ++j)
            coins[i][j] = rand() % 2;
}

void printMatrix(matrix& coins, int& lines, int& columns){
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j)
            std::cout << coins[i][j] << " ";
        std::cout << std::endl;
    }
}

int max(int f1, int f2){
   return (f1 > f2) ? f1: f2;
}

int coinCollection(matrix& coins, int& lines, int& columns){
    matrix F = coins;
    F[0][0] = coins[0][0];
    for (int j = 1; j < columns; ++j)
        F[0][j] = F[0][j - 1] + coins[0][j];
    for (int i = 1; i < lines; ++i) {
        F[i][0] = F[i - 1][0] + coins[i][0];
        for (int j = 1; j < columns; ++j)
            F[i][j] = max(F[i - 1][j], F[i][j - 1]) + coins[i][j];
    }
    return F[lines - 1][columns - 1];
}

int main(){
    srand((unsigned) time(nullptr));
    int lines = 5;
    int columns = 6;
    int max_coins = 0;
//    matrix coins{
//            {0,0,0,0,1,0},
//            {0,1,0,1,0,0},
//            {0,0,0,1,0,1},
//            {0,0,1,0,0,1},
//            {1,0,0,0,1,0}};
    matrix coins(lines , std::vector<int> (columns, 0));
    generateMatrixCoin(coins, lines, columns);
    printMatrix(coins, lines, columns);
    max_coins = coinCollection(coins, lines, columns);
    std::cout << "Max coins: " << max_coins;
    return 0;
}