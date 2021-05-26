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

enum{LEFT = -1, COLINEAR, RIGHT};

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

void maxMinX(Plane& convex_hull, Plane& S){
    //maxmins_xy....[0] >> idx x min....[1] >> idx x max
    int max_idx = 0, min_idx = 0;
    for (int i = 1; i < S.size(); ++i) {
        if (S[max_idx].x < S[i].x)
            max_idx = i;
        else if (S[min_idx].x > S[i].x)
            min_idx = i;
    }
    convex_hull.push_back(S[max_idx]);
    convex_hull.push_back(S[min_idx]);
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

int pointDirection(Point A, Point B, Point P){
    // subtracting co-ordinates of point A from
    // B and P, to make A as origin
    B.x -= A.x;
    B.y -= A.y;
    P.x -= A.x;
    P.y -= A.y;

    // Determining cross Product
    int cross_product = B.x * P.y - B.y * P.x;

    // return RIGHT if cross product is positive
    if (cross_product > 0)
        return RIGHT;

    // return LEFT if cross product is negative
    if (cross_product < 0)
        return LEFT;

    // return ZERO if cross product is zero.
    return COLINEAR;
}

void dividePlane(Plane& s, Plane& S1, Plane& S2, Point A, Point B){
    int point_direction = 0;
    for (auto i : s) {
        point_direction = pointDirection(A, B, i);
        if(point_direction == RIGHT)
            S1.push_back(i);
        else if (point_direction == LEFT)
            S2.push_back(i);
    }
}

void dividePlane(Plane& S, Plane& S1, Point A, Point B){
    int point_direction = 0;
    for (auto i : S) {
        point_direction = pointDirection(A, B, i);
        if(point_direction == RIGHT)
            S1.push_back(i);
    }
}

void findHull(Plane& S, Plane& convex_hull, Point P, Point Q){
    if (S.empty())
        return;
    Plane S1;
    Plane S2;
    Point new_point;
    int max_idx = 0;
    float max_distance = pointDistance(P, Q, S[0]);
    float distance;
    for (int i = 1; i < S.size(); ++i) {
        distance = pointDistance(P, Q, S[i]);
        if(max_distance < distance){
            max_distance = distance;
            max_idx = i;
        }
    }
    new_point = S[max_idx];
    convex_hull.push_back(new_point);
    dividePlane(S, S1, P, new_point);
    dividePlane(S, S2, new_point, Q);
    findHull(S1, convex_hull, P, new_point);
    findHull(S2, convex_hull, new_point, Q);
}

void quickHull(Plane& S, Plane& convex_hull){
    Plane S1;
    Plane S2;
    maxMinX(convex_hull, S);
    Point A = convex_hull[0];       // min X
    Point B = convex_hull[1];       // max X
    dividePlane(S, S1, S2, A, B);
    findHull(S1, convex_hull, A , B);
    findHull(S2, convex_hull, B , A);
}

int main() {
    srand((unsigned) time(nullptr));
    Plane convex_hull; //save the index of the points of the edge of the convex hull
    int n = 6, cont = 1;
    Plane S;

    generatePlane(S, n);
    printPoints(S);

    quickHull(S, convex_hull);
    std::cout << std::endl << "Convex Hull: " << std::endl;
    for ( auto i : convex_hull)
        std::cout << cont++ << " - (" << i.x << ", " << i.y << ")\n";
    return 0;
}