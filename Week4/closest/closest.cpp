#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>

using std::vector;
using std::string;
using std::pair;
using std::min;
struct Point {
  int x, y;
};
struct SortByX {
  bool operator()(Point const& a, Point const& b) {
    return a.x>b.x;
  }
};

struct SortByY {
  bool operator()(Point const& a, Point const& b) {
    return a.y>b.y;
  }
};

double computeDistance(Point& p1, Point& p2) {
  return sqrt( (p1.x - p2.x)*(p1.x - p2.x) +  
                (p1.y - p2.y)*(p1.y - p2.y)  
            );
}
double bruteForce(Point points[], int n) {
  double minDistance=(double)INT_MAX;
  for(int i=0; i<n;i++) {
    for(int j = i+1; j<n; j++)
      minDistance = min(minDistance, computeDistance(points[i], points[j]));
  }
  return minDistance;
}

double closestStrip(Point points[], int size, double d) {
  double minDistance = d;
  std::sort(points, points+size, SortByY());
  for(int i=0;i<size;i++) {
    for(int j=i+1; j<size && (points[j].y - points[i].y < d); j++)
      minDistance = computeDistance(points[i], points[j]);
      minDistance = min(d, minDistance);
  }
  return minDistance;
}
double minimal_distance(Point points[], int n) {
  //write your code here
  if(n<=3) {
    return bruteForce(points, n);
  }
  int mid = n/2;
  
  double dl = minimal_distance(points, mid);
  double dr = minimal_distance(points + mid, n - mid);

  double d = min(dl, dr);

  Point strip[n];
  int j=0;
  for(int i=0;i<n-1;i++) {
    if(abs(points[i].x - points[mid].x) < d) {
      strip[j++] = points[i];
    }
  }
  d = closestStrip(strip, j, d);
  return d;
}

int main() {
  size_t n;
  std::cin >> n;
  Point points[n];
  for (size_t i = 0; i < n; i++) {
    std::cin >> points[i].x >> points[i].y;
  }
  std::sort(points, points+n, SortByX());
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(points, n) << "\n";
}
