#include <iostream>
#include <vector>
#include <limits>

void min(int minimum_coin, int& temp){
    if(minimum_coin < temp)
        temp = minimum_coin;
}

int changeMaking(std::vector<int>& coins, std::vector<int>& minimum_coin, int& amount){
    int m = coins.size();
    for (int i = 1; i <= amount; ++i) {
        int temp = std::numeric_limits<int>::max();
        int j = 0;
        while (j < m && i >= coins[j]){
            min(minimum_coin[i - coins[j]], temp);
            j++;
        }
        minimum_coin[i] = temp + 1;
    }
    return minimum_coin[amount];
}

int main(){
    int min_coins;
    int amount = 11;
    std::vector<int> coins = {1, 2, 5};
    std::vector<int> minimum_coin (amount++, 0);
    min_coins = changeMaking(coins, minimum_coin, amount);
    std::cout << "number of coins: " << min_coins;

    return 0;
}