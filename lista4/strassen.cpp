#include <ctime>
#include <iostream>
#include <stdlib.h>
#include <vector>

typedef std::vector<std::vector<int>> matrix;

matrix generateMatrix(int& n){
    matrix random_matrix(n, std::vector<int>(n));
    for(int i = 0; i<n; i++)
        for(int j = 0; j<n; j++) {
            random_matrix[i][j] = rand() % 10;
        }
    return random_matrix;
}

matrix add(matrix& x, matrix& y){
    int n = x.size();
    matrix xy_addition(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            xy_addition[i][j] = x[i][j] + y[i][j];
    return xy_addition;
}

matrix subtract(matrix& x, matrix& y){
    int n = x.size();
    matrix xy_subtraction(n, std::vector<int>(n));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            xy_subtraction[i][j] = x[i][j] - y[i][j];
    return xy_subtraction;
}

void partition(matrix& x, matrix& a, matrix& b, matrix& c, matrix& d, int& n2){
    for(int i = 0; i < n2; i++) {
        for (int j = 0; j < n2; j++) {
            a[i][j] = x[i][j];
            b[i][j] = x[i][n2 + j];
            c[i][j] = x[n2 + i][j];
            d[i][j] = x[n2 + i][n2 + j];
        }
    }
}

matrix buildMatrix(matrix& r, matrix& s, matrix& t, matrix& u, int& n2){
    matrix result(2*n2, std::vector<int>(2*n2));
    for(int i = 0; i < n2; i++) {
        for(int j = 0; j < n2; j++) {
            result[i][j] = r[i][j];
            result[i][j+n2] = s[i][j];
            result[n2+i][j] = t[i][j];
            result[n2+i][n2+j] = u[i][j];
        }
    }
    return result;
}

void printMatrix(matrix& x, int& n){
    for(int i = 0; i < n; i++) {
        for(int j = 0; j < n; j++) {
            std::cout << x[i][j] << " ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}

matrix strassen(matrix& x, matrix& y, int n){
    if (n == 1){
        matrix c(n, std::vector<int>(n));
        c[0][0] = x[0][0] * y[0][0];
        return c;
    }
    int n2 = n / 2;
    matrix a(n2, std::vector<int>(n2));
    matrix b(n2, std::vector<int>(n2));
    matrix c(n2, std::vector<int>(n2));
    matrix d(n2, std::vector<int>(n2));
    matrix e(n2, std::vector<int>(n2));
    matrix f(n2, std::vector<int>(n2));
    matrix g(n2, std::vector<int>(n2));
    matrix h(n2, std::vector<int>(n2));

    matrix p1(n2, std::vector<int>(n2));
    matrix p2(n2, std::vector<int>(n2));
    matrix p3(n2, std::vector<int>(n2));
    matrix p4(n2, std::vector<int>(n2));
    matrix p5(n2, std::vector<int>(n2));
    matrix p6(n2, std::vector<int>(n2));
    matrix p7(n2, std::vector<int>(n2));

    matrix r(n2, std::vector<int>(n2));
    matrix s(n2, std::vector<int>(n2));
    matrix t(n2, std::vector<int>(n2));
    matrix u(n2, std::vector<int>(n2));

    matrix result;
    matrix result2;

    partition(x, a, b, c, d, n2);
    partition(y, e, f, g, h, n2);

    result = subtract(f, h);
    p1 = strassen(a, result, n2);

    result = add(a, b);
    p2 = strassen(result, h, n2);

    result = add(c, d);
    p3 = strassen(result, e, n2);

    result = subtract(g, e);
    p4 = strassen(d, result, n2);

    result = add(a, d);
    result2 = add(e, h);
    p5 = strassen(result, result2, n2);

    result = subtract(b,d);
    result2 = add(g, h);
    p6 = strassen(result, result2, n2);

    result = subtract(a,c);
    result2 = add(e,f);
    p7 = strassen(result, result2, n2);

    result = add(p5, p4);
    result2 = subtract(result, p2);
    r = add(result2, p6);

    s = add(p1, p2);
    t = add(p3, p4);

    result = add(p5, p1);
    result2 = subtract(result, p3);
    u = subtract(result2, p7);

    return buildMatrix(r, s, t, u, n2);
}

int main() {
    srand((unsigned) time(nullptr));

    matrix x(2, std::vector<int>(2));
    matrix y(2, std::vector<int>(2));
    matrix z(2, std::vector<int>(2));

    int n = 4;

    std::cout << "Matrix 1: \n";
    x = generateMatrix(n);
    printMatrix(x, n);
    std::cout << "Matrix 2: \n";
    y = generateMatrix(n);
    printMatrix(y, n);
    z = strassen(x, y, n);
    printMatrix(z, n);
    return 0;
}
