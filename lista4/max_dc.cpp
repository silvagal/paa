#include <iostream>
#include <vector>
#include <ctime>

void generateIntValues(std::vector<int>& instances){
    for (int i = 0; i < instances.size(); ++i)
        instances[i] = rand() % 100;
}

template <class T>
int maximumValue(std::vector<T>& numbers, int& begin_idx, int& end_idx){
    if (begin_idx == end_idx)
        return begin_idx;
    int half_idx = end_idx / 2;
    if (half_idx < begin_idx)
        half_idx = begin_idx;
    int max1_idx = maximumValue(numbers, begin_idx, half_idx);
    half_idx++;
    int max2_idx = maximumValue(numbers, half_idx, end_idx);
    if( numbers[max1_idx] > numbers[max2_idx])
        return max1_idx;
    else
        return max2_idx;
}

int main() {
    srand((unsigned) time(nullptr));
    
    int n = 40;                                //vector size
    std::vector<int> instances(n, 0);
    generateIntValues(instances);

    std::cout << "Instances: " << std::endl;
    for (auto i : instances)
        std::cout << i << " ";
    std::cout << std::endl;

    int begin_idx = 0;
    int end_idx = instances.size() - 1;
    int max_idx = maximumValue(instances, begin_idx, end_idx);
    std::cout << "Greatest: " << instances[max_idx] << " Index: " << max_idx;
    return 0;
}
