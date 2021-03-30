#include <iostream>
using namespace std;

int main() 
{ 
    int instances[] = {67, 74, 85, 4, 71,96, 48, 52, 48, 63, 61, 64, 62, 97, 61, 12, 40, 4, 90, 36, 48, 17, 38, 40, 
                        20, 78, 87, 1, 1, 49, 97, 60, 37, 78, 76, 63, 83, 6, 18, 87, 30, 87, 15, 82, 15, 60, 74, 35, 
                        34, 48, 77, 25, 12, 7, 75, 99, 73, 20, 82, 12, 96, 45, 80, 73, 5, 14, 0, 40, 11, 6, 82, 22, 
                        36, 38, 34, 57, 60, 17, 30, 99, 80, 25, 39, 75, 82, 45, 65, 15, 32, 41, 67, 69, 86, 4, 30, 
                        85, 51, 71, 70, 42}; 

    /*calculando o tamanho do array, para um tamanho de bytes desconhecidos*/                    
    int n = sizeof(instances)/sizeof(instances[0]); 
    
    /*Bubble sort*/
    for (int i = 0; i < n-1; i++)     
        for (int j = 0; j < n-i-1; j++) 
            if (instances[j] > instances[j+1]) {
                 int temp = instances[j]; 
                instances[j] = instances[j+1]; 
                instances[j+1] = temp;
            }

    /*Mostrar o array*/        
    cout<<"Array ordenado: \n"; 
    int i; 
    for (i = 0; i < n; i++) 
        cout << instances[i] << " "; 
    cout << endl;
    return 0; 
} 