#include <iostream>
#include <vector>

#define NUMBER_OF_ITEMS 5
#define KNAPSACK_CAPACITY 5

typedef std::vector<std::vector<int>> matrix;

void initializeFMatrix(matrix& F){
    for (int i = 0; i < NUMBER_OF_ITEMS; ++i)
        F[i][0] = 0;
    for (int j = 0; j < KNAPSACK_CAPACITY + 1; ++j){
        F[0][j] = 0;
    }
}

void printMatrix(matrix& m, int lines, int columns){
    for (int i = 0; i < lines; ++i) {
        for (int j = 0; j < columns; ++j)
            std::cout << m[i][j] << " ";
        std::cout << std::endl;
    }
}

int max(int f1, int f2){
    return (f1 > f2) ? f1: f2;
}

int MFKnapsack(matrix& F, const std::vector<int>& weights, const std::vector<int>& values, int i, int j){
    int value = 0;
    if(F[i][j] < 0){
        if (j < weights[i])
            value = MFKnapsack(F, weights, values, i - 1, j);
        else
            value = max(MFKnapsack(F, weights, values, i - 1, j),
                        values[i] + MFKnapsack(F, weights, values, i - 1, j - weights[i]));
        F[i][j] = value;
    }
    return F[i][j];
}

int main(){
    int max_weight;
    std::vector<int> weights = {0,2,1,3,2};
    std::vector<int> values = {0,12,10,20,15};
    matrix F(NUMBER_OF_ITEMS, std::vector<int> (KNAPSACK_CAPACITY + 1, -1));

    initializeFMatrix(F);
    printMatrix(F, NUMBER_OF_ITEMS, KNAPSACK_CAPACITY + 1);
    max_weight = MFKnapsack(F, weights, values, NUMBER_OF_ITEMS - 1, KNAPSACK_CAPACITY);

    std::cout << std::endl;
    printMatrix(F, NUMBER_OF_ITEMS, KNAPSACK_CAPACITY + 1);
    std::cout << "\nMax weight: " << max_weight << std::endl;

    return 0;
}