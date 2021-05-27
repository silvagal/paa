#include <iostream>
#include <vector>
#include <limits>
#include <math.h>

typedef struct points{
    int x;
    int y;
} Point;

typedef std::vector<Point> Plane;

Point generatePoint(){
    Point new_point;
    new_point.x = rand() % 100;
    new_point.y = rand() % 100;
    return new_point;
}

void generatePlane(Plane& P, int& n){
    for (int i = 0; i < n; ++i)
        P.push_back(generatePoint());
}

void printPoints(Plane& plane){
    for (auto & i : plane)
        std::cout << i.x << "; " << i.y << std::endl;
}

float bruteForceClosestPair(Plane& P){
    srand((unsigned) time(nullptr));
    int n = P.size();
    if (n < 2)
        return -1;
    float d = std::numeric_limits<float>::max();
    float distance = 0.0;
    for (int i = 1; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            distance = sqrt(pow((P[i].x - P[j].x), 2) + pow((P[i].y - P[j].y), 2));
            d = std::min(d, distance);
        }
    }
    return d;
}

int main() {
    int n = 5;     //number of points
    Plane plane;
    generatePlane(plane, n);
    printPoints(plane);
    std::cout << "\nDistance between the closest pair of points: " << bruteForceClosestPair(plane);
    return 0;
}