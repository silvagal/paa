#include <iostream>
#include <vector>
#include <ctime>

void generateInstances(std::vector<int>& instances){
    for (int i = 0; i < instances.size(); ++i)
        instances[i] = rand() % 100;
}

template <class T>
T maximumValue(std::vector<T>& numbers){
    int n = numbers.size();
    if (n == 1)
        return numbers[0];
    auto first = numbers.cbegin();
    auto last = numbers.cbegin() + n / 2;
    std::vector<T> new_vec1(first, last);


    first = numbers.cbegin() + n / 2;
    last = numbers.cend();
    std::vector<T> new_vec2(first, last);

    T value1 = maximumValue(new_vec1);
    T value2 = maximumValue(new_vec2);
    if( value1 > value2)
        return value1;
    else
        return value2;
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

    int max = maximumValue(instances);
    std::cout << "Greatest: " << max;
    return 0;
}
