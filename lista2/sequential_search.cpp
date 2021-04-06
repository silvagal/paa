#include <iostream>
#include <vector>
using namespace std;

template <class T>   
void swap(int &min_idx, int &i, vector<T>& v){ 
    int aux = v[i]; 
    v[i] = v[min_idx]; 
    v[min_idx] = aux; 
} 

template <class T>  
T sequentialSearch(vector<T>& v, T &k, int &n){
   int i=0, found=0;
   while( i < n && !found ){
      if( v[i] == k )
         found = 1;
      else
         i++;
   }
   if( !found ) 
    i = -1;
   return i;
}
  
template <class T>
void printArray(vector<T>& v, int &n){
    for (int i = 0; i < n; i++) 
        cout << v[i] << " "; 
    cout << endl;
}
// Driver program to test above functions 
int main() 
{ 
     vector<int> instances = {67, 74, 85, 4, 71,96, 48, 52, 48, 63, 61, 64, 62, 97, 61, 12, 40, 4, 90, 36, 48, 17, 38, 40, 
                            20, 78, 87, 1, 1, 49, 97, 60, 37, 78, 76, 63, 83, 6, 18, 87, 30, 87, 15, 82, 15, 60, 74, 35, 
                            34, 48, 77, 25, 12, 7, 75, 99, 73, 20, 82, 12, 96, 45, 80, 73, 5, 14, 0, 40, 11, 6, 82, 22, 
                            36, 38, 34, 57, 60, 17, 30, 99, 80, 25, 39, 75, 82, 45, 65, 15, 32, 41, 67, 69, 86, 4, 30, 
                            85, 51, 71, 70, 42};  
                            
    int n = instances.size();                        
    auto k = 0;
    
    cout << "Digite um número de 1 a 100" << endl;
    cin >> k;
    
    auto value = sequentialSearch(instances, k, n); 
    if (value != -1)
        cout << "Valor encontrado!! :D" << endl;
    else
        cout << "Valor não encontrado!! :(" << endl;

    return 0; 
} 