#include <iostream>
#include <vector>
using namespace std;

template <class T> 
void insertionSort(vector<T>& v, int& n){
    int pivot, j;
    for (int i = 1; i < n; i++){
        pivot = v[i];
        j = i - 1;
        while (j >= 0 && v[j] > pivot){
            v[j + 1] = v[j];
            j = j - 1;
        }
        v[j + 1] = pivot;
    }
}

template <class T>  
void printArray(vector<T>& v, int& n){
    for (int i = 0; i < n; i++)
        cout << v[i] << " ";
    cout << endl;
}
 

int main()
{
    vector<int> instances = {53, 90, 50, 8, 2, 13, 5, 19, 50, 99, 100, 52, 42, 88, 30, 88, 
                            83, 48, 18, 46, 58, 75, 99, 74, 67, 79, 90, 93, 52, 40, 48, 53, 
                            3, 80, 4, 57, 27, 83, 3, 7, 7, 54, 19, 53, 68, 96, 22, 75, 79, 87};

    int n = instances.size();
    insertionSort(instances, n);
    printArray(instances, n);
 
    return 0;
}