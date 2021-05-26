#include <iostream>
#include <vector>
#include <ctime>

typedef struct Maxmin{
    int min;
    int max;
} Maxmin;

void generateInstances(std::vector<int>& instances){
    for (int i = 0; i < instances.size(); ++i)
        instances[i] = rand() % 100;
}

template <class T>
Maxmin maximumValue(std::vector<T>& numbers){
    Maxmin result;
    int n = numbers.size();
    if (n == 1) {
        result.min = numbers[0];
        result.max = numbers[0];
        return result;
    }
    auto first = numbers.cbegin();
    auto last = numbers.cbegin() + n / 2;
    std::vector<T> new_vec1(first, last);


    first = numbers.cbegin() + n / 2;
    last = numbers.cend();
    std::vector<T> new_vec2(first, last);

    Maxmin value1 = maximumValue(new_vec1);
    Maxmin value2 = maximumValue(new_vec2);
    if( value1.min > value2.min)
        result.min = value2.min;
    else
        result.min = value1.min;

    if( value1.max < value2.max)
        result.max = value2.max;
    else
        result.max = value1.max;

    return result;
}

int main() {
    srand((unsigned) time(nullptr));
    int n = 40;
    std::vector<int> instances(n, 0);
    generateInstances(instances);

    std::cout << "Instances: " << std::endl;
    for (auto i : instances)
        std::cout << i << " ";
    std::cout << std::endl;

    Maxmin values = maximumValue(instances);
    std::cout << "Greatest: " << values.max << std::endl;
    std::cout << "Smallest: " << values.min << std::endl;
    return 0;
}
