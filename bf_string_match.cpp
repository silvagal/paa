#include <cstring>
#include <iostream>
#include <vector>

std::vector<int> bruteForceStringMatch(char* T, char* P){
    int j = 0;
    int n = strlen(T);
    int m = strlen(P);
    std::vector<int> index;
    for (int i = 0; i <= n - m; i++) {
        j = 0;
        while (j < m && P[j] == T[i+j])
            j++;
        if(j == m) {
            std::cout << "Pattern found at index " << i << std::endl;
            index.push_back(i);
        }
    }
    return index;
}

int main() {
    char text[] = "ZLHGHJMNOGHJPQRGHJ";
    char pattern[] = "GHJ";
    std::vector<int> index = bruteForceStringMatch(text, pattern);


    return 0;
}