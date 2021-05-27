#include <iostream>
#include <vector>

float weight(std::vector<int>& coins, int begin_idx, int end_idx){
    float weight = 0.0;
    for (int i = begin_idx; i <= end_idx; ++i)
        weight += coins[i];
    return weight;
}

int fakeCoin(std::vector<int>& coins){
    int middle_idx = 0, coin_left_idx = -1, begin_idx = 0;
    int n = coins.size();
    int end_idx = n - 1;
    float weight_pile1 = 0.0, weight_pile2 = 0.0;
    bool flag = false;

    if (n % 2 != 0) {
        coin_left_idx = end_idx;
        end_idx--;
    }
    while (begin_idx != end_idx) {
        middle_idx = (begin_idx + end_idx) / 2;
        weight_pile1 = weight(coins, begin_idx, middle_idx);
        weight_pile2 = weight(coins, middle_idx + 1, end_idx);
        if (weight_pile1 < weight_pile2) {
            end_idx = middle_idx;
        }else if (weight_pile2 < weight_pile1) {
            middle_idx++;
            begin_idx = middle_idx;
        } else{
            flag = true;
            break;
        }

        if (flag)
            return coin_left_idx;
        else
            return middle_idx;
    }
}

int main() {
    std::vector<int> coins = {5,5,5,5,4,5,5};
    
    std::cout << fakeCoin(coins);
    return 0;
}
