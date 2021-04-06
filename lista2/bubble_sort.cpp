#include <iostream>
#include <vector>

using namespace std;

template <class T>
void bubbleSort(vector<T>& v){
    /*calculando o tamanho do array, para um tamanho de bytes desconhecidos*/                    
    int n = v.size(); 
    for (int i = 0; i < n-1; i++) {    
        for (int j = 0; j < n-i-1; j++) {
            if (v[j] > v[j+1]) {
                int temp = v[j]; 
                v[j] = v[j+1]; 
                v[j+1] = temp;
            }
        }
    }    
}

template <class T>
void printArray(vector<T>& v){
    int n = v.size();
    for (int i = 0; i < n; i++) 
        cout << v[i] << " "; 
    cout << endl;
}

int main() 
{ 
    vector<int> instances = {67, 74, 85, 4, 71,96, 48, 52, 48, 63, 61, 64, 62, 97, 61, 12, 40, 4, 90, 36, 48, 17, 38, 40, 
                            20, 78, 87, 1, 1, 49, 97, 60, 37, 78, 76, 63, 83, 6, 18, 87, 30, 87, 15, 82, 15, 60, 74, 35, 
                            34, 48, 77, 25, 12, 7, 75, 99, 73, 20, 82, 12, 96, 45, 80, 73, 5, 14, 0, 40, 11, 6, 82, 22, 
                            36, 38, 34, 57, 60, 17, 30, 99, 80, 25, 39, 75, 82, 45, 65, 15, 32, 41, 67, 69, 86, 4, 30, 
                            85, 51, 71, 70, 42}; 

    /*Mostrar o array desordenado*/        
    cout << "Array deordenado: \n"; 
    printArray(instances);
    
    /*Bubble sort*/
    bubbleSort(instances);

    /*Mostrar o array ordenado*/        
    cout << "Array ordenado: \n"; 
    printArray(instances);
    
    return 0; 
} 
