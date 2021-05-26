#include <iostream>
#include <vector>
#include <ctime>

typedef struct Maxmin{
    int min_idx;
    int max_idx;
} Maxmin;

void generateIntValues(std::vector<int>& instances){
    for (int i = 0; i < instances.size(); ++i)
        instances[i] = rand() % 100;
}

template <class T>
Maxmin maximumValue(std::vector<T>& numbers, int& begin_idx, int& end_idx){
    Maxmin result;
    if (begin_idx == end_idx) {
        result.min_idx = begin_idx;
        result.max_idx = begin_idx;
        return result;
    }
    int half_idx = end_idx / 2;
    if (half_idx < begin_idx)
        half_idx = begin_idx;
    Maxmin maxmin1 = maximumValue(numbers, begin_idx, half_idx);
    half_idx++;
    Maxmin maxmin2 = maximumValue(numbers, half_idx, end_idx);
    if( numbers[maxmin1.min_idx] > numbers[maxmin2.min_idx])
        result.min_idx = maxmin2.min_idx;
    else
        result.min_idx = maxmin1.min_idx;

    if( numbers[maxmin1.max_idx] < numbers[maxmin2.max_idx])
        result.max_idx = maxmin2.max_idx;
    else
        result.max_idx = maxmin1.max_idx;

    return result;
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
    Maxmin maxmin = maximumValue(instances, begin_idx, end_idx);

    std::cout << "Greatest: " << instances[maxmin.max_idx] << " Index: " << maxmin.max_idx << std::endl;
    std::cout << "Smallest: " << instances[maxmin.min_idx] << " Index: " << maxmin.min_idx;

    return 0;
}
