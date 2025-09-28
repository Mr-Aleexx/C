#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

double largestTriangleArea(int** points, int pointsSize, int* pointsColSize) {
    double maxArea;

    for (int i = 0; i < pointsSize ; i++) {
        for (int j = i + 1 ; j < pointsSize ; j++)  {
            for (int k = j + 1 ; k < pointsSize ; k++) {
                int x1 = points[i][0], y1 = points[i][1];
                int x2 = points[j][0], y2 = points[j][1];
                int x3 = points[k][0], y3 = points[k][1];
                
                double area = fabs(
                    x1 * (y2 - y3) +
                    x2 * (y3 - y1) +
                    x3 * (y1 - y2)
                ) / 2.0;
                
                if (maxArea < area) {
                    maxArea = area;
                }
            }
            
            
        }
    }

    return maxArea;
}

int main() {
    int data[5][2] = {{0,0},{0,1},{1,0},{0,2},{2,0}};
    int* points[5];
    for (int i = 0; i < 5; i++) {
        points[i] = data[i];
    }
    int pointsColSize[5] = {2,2,2,2,2};

    double ans = largestTriangleArea(points, 5, pointsColSize);
    printf("Largest Area: %f\n", ans);

    return 0;
}