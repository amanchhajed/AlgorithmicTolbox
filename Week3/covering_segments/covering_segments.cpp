#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>

using std::vector;

struct Segment {
  int start, end;
  bool operator()(Segment const& a, Segment const& b) {
    return a.end < b.end;
  }
};

vector<int> optimal_points(vector<Segment> &segments) {
  sort(segments.begin(), segments.end(), Segment());
  vector<int> points;
  for(int i=0;i<segments.size()-1;) {
    int j = i+1;
    while(j < segments.size() && segments[i].end >= segments[j].start)
      j+=1;
    points.push_back(segments[i].end);
    i = j;
  }
  return points;
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
}
