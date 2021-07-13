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

int coinCollection(matrix& coins, int l, int c){
    if(l == 0 || c == 0)
        return coins[l][c];
    return max(coinCollection(coins, l - 1, c), 
        coinCollection(coins, l, c - 1)) + coins[l][c];
}

int main(){
    srand((unsigned) time(nullptr));
    int lines = 5;
    int columns = 6;
    int max_coins = 0;
//    matrix coins{             //expected coins: 5
//        {0,0,0,0,1,0},
//        {0,1,0,1,0,0},
//        {0,0,0,1,0,1},
//        {0,0,1,0,0,1},
//        {1,0,0,0,1,0}};
//    matrix coins{               //expected coins: 8
//        {0,0,0,0,1,1},
//        {0,1,1,1,0,1},
//        {1,0,0,1,0,1},
//        {1,0,1,1,1,0},
//        {0,0,1,1,1,1}};
    matrix coins(lines , std::vector<int> (columns, 0));
    generateMatrixCoin(coins, lines, columns);
    printMatrix(coins, lines, columns);
    max_coins = coinCollection(coins, lines - 1, columns - 1);
    std::cout << "Max coins: " << max_coins;
    return 0;
}