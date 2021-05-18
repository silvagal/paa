#include <iostream>
#include <vector>

using namespace std;

template <class T>
void merge(vector<T>& b, vector<T>& c, vector<T>& a){
    int i = 0, j = 0, k = 0, p = b.size(), q = c.size();
    while (i < p && j < q){
        if (b[i] <= c[j])
            a[k] = b[i++];
        else
            a[k] = c[j++];
        k++;
    }
    if (i == p)
        for(j; j < q; j++)
            a[k++] = c[j];
    else
        for(i; i < p; i++)
            a[k++] = b[i];
}

template <class T>
void mergeSort(vector<T>& a){
    int n = a.size();
    if (n > 1) {
        auto first = a.cbegin();
        auto last = a.cbegin() + n / 2;
        vector<T> b(first, last);

        first = a.cbegin() + n / 2;
        last = a.cend();
        vector<T> c(first, last);

        mergeSort(b);
        mergeSort(c);
        merge(b, c, a);
    }
}

int main() {
//    vector<int> instances = {78, 9, 61, 75, 3, 6, 80, 8, 98, 53, 72, 21, 50, 25, 76, 96, 21,
//                             98, 16, 72, 35, 91, 77, 33, 71, 27, 59, 100, 4, 4, 33, 56, 46,
//                             77, 2, 61, 3, 77, 47, 80, 75, 5, 62, 1, 88, 18, 40, 32, 13, 72};

    vector<char> instances = {'E', 'X', 'A', 'M', 'P', 'L', 'E'};

    mergeSort(instances);
    
    for (auto& i : instances) 
        cout << i << " ";
    
    return 0;
}
