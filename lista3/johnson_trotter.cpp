#include <iostream>
#include <vector>

#define LEFT_TO_RIGHT 1
#define RIGHT_TO_LEFT 0

using namespace std;

int getLargestMobile(vector<int> & perm, int& n, int& mobile){
    for (int i = 0; i < n; i++)
        if (perm[i] == mobile)
            return i + 1;
}

int getMobile(vector<int>& perm, vector<bool>& dir, int& n){
    int mobile_prev = 0, mobile = 0;
    for (int i = 0; i < n; i++){
        if (dir[perm[i]-1] == RIGHT_TO_LEFT && i!=0){
            if (perm[i] > perm[i-1] && perm[i] > mobile_prev){
                mobile = perm[i];
                mobile_prev = mobile;
            }
        }
        if (dir[perm[i]-1] == LEFT_TO_RIGHT && i!=n-1){
            if (perm[i] > perm[i+1] && perm[i] > mobile_prev){
                mobile = perm[i];
                mobile_prev = mobile;
            }
        }
    }

    if (mobile == 0 && mobile_prev == 0)
        return 0;
    else
        return mobile;
}

int factorial(int n){
    int factorial = 1;
    for (int i = 1; i <= n; i++)
        factorial = factorial * i;
    return factorial;
}

void printPermutations(int& n){
    vector<int> perm;                                     // variable that stores current permutation
    vector<bool>  dir;                                     // variable that stores current directions

    // printing first permutation and setting first direction to right to left
    for (int i = 0; i < n; i++){
        dir.push_back(RIGHT_TO_LEFT);
        perm.push_back(i + 1);
        cout << perm[i];
    }
    cout << " ";

    // generating the other permutations
    for (int i = 1; i < factorial(n); i++) {                    // n! is the number of possible permutations
        int mobile = getMobile(perm, dir, n);
        int pos = getLargestMobile(perm, n, mobile);

        // swapping the elements according to the direction
        if (dir[perm[pos - 1] - 1] ==  RIGHT_TO_LEFT)
            swap(perm[pos-1], perm[pos-2]);

        else if (dir[perm[pos - 1] - 1] == LEFT_TO_RIGHT)
            swap(perm[pos], perm[pos-1]);

        // changing the directions for elements greater than largest mobile integer
        for (int i = 0; i < n; i++){
            if (perm[i] > mobile){
                if (dir[perm[i] - 1] == LEFT_TO_RIGHT)
                    dir[perm[i] - 1] = RIGHT_TO_LEFT;
                else if (dir[perm[i] - 1] == RIGHT_TO_LEFT)
                    dir[perm[i] - 1] = LEFT_TO_RIGHT;
            }
        }

        for (int i = 0; i < n; i++)
            cout << perm[i];
        cout << " ";
    }
}

int main(){
    int n = 3;
    printPermutations(n);
    return 0;
}