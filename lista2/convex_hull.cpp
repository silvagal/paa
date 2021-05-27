#include <ctime>
#include <iostream>
#include <cstdlib>
#include <vector>
#include <math.h>

typedef struct point{
    int x;
    int y;
}Point;

typedef std::vector<Point> Plane;

enum{CCW = -1, COLINEAR, CW};

Point generatePoint(){
    Point new_point;
    new_point.x = rand() % 100;
    new_point.y = rand() % 100;
    return new_point;
}

void generatePlane(Plane& plane, int& n){
    for (int i = 0; i < n; ++i)
        plane.push_back(generatePoint());
}

int leftMostPoint(Plane& S){
    int left_most_idx = 0;
    for (int i = 1; i < S.size(); ++i)
        if (S[left_most_idx].x > S[i].x)
            left_most_idx = i;
    return left_most_idx;
}

int pointDirection(Point P, Point Q, Point I){
    int orientation = (Q.y - P.y) * (I.x - Q.x) - (Q.x - P.x) * (I.y - Q.y);
    if (orientation == 0)
        return COLINEAR;
    else if (orientation > 0)
        return CW;
    else
        return CCW;
}

int mostClockwisePoint(Plane S, int& n, int& p, int& q){
    for (int i = 0; i < n; i++)
        if (pointDirection(S[p], S[q], S[i]) == CCW)
            q = i;
}

float pointDistance(Point& A, Point& B, Point& P){
    // a*x - y + c = 0
    float a = (float) (B.y - A.y) / (float) (B.x - A.x);
    float c = (float)A.y - a * (float)A.x;
    float b = -1;                                        //-y -> (-1)*y
    float distance = abs((a*(float)P.x + b*(float)P.y + c)) / sqrt((pow(a,2) + pow(b,2)));
    return distance;
}

void printPoints(Plane& plane){
    for (auto & i : plane)
        std::cout << i.x << "; " << i.y << std::endl;
}

void convexHull(Plane& S, Plane& convex_hull){
    int n = S.size();
    if (n < 3)
        return;

    int left_most_point_idx = leftMostPoint(S);
    int p = left_most_point_idx;
    int q = 0;

    do{
        convex_hull.push_back(S[p]);
        q = (p + 1) % n;
        mostClockwisePoint(S, n, p, q);
        p = q;

    } while (p != left_most_point_idx); 
}

int main() {
    srand((unsigned) time(nullptr));
    Plane convex_hull; //save the index of the points of the edge of the convex hull
    int n = 6, cont = 1;
    Plane S;

    generatePlane(S, n);
    printPoints(S);

    convexHull(S, convex_hull);
    std::cout << std::endl << "Convex Hull: " << std::endl;
    for ( auto i : convex_hull)
        std::cout << cont++ << " - (" << i.x << ", " << i.y << ")\n";
    return 0;
}