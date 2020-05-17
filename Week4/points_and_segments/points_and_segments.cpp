#include <iostream>
#include <vector>

using std::vector;

int searchByX(vector<int> elems, int point) {
  int l=0, r = elems.size()-1;
  int pos = -1;
  while(r>=l) {
    if(l==r) {
      if(elems.at(l) <= point)
        return l;
      break;
    }
    int mid = (l+r)/2;
    if(elems.at(mid) <= point) {
      pos = mid;
      l = mid+1;
    } else {
      r = mid;
    }
  }
  return pos;
}

int searchByY(vector<int> elems, int point) {
  int l=0, r=elems.size()-1;
  int pos = -1;
  while(r>=l) {
    if(l==r) {
      if(elems.at(l)>=point)
        return l;
      break;
    }
    int mid = (l+r)/2;
    if(elems.at(mid) >= point) {
      pos = mid;
      r = mid-1;
    } else {
      l = mid+1;
    }
  }
  return pos;
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  sort(starts.begin(), starts.end());
  sort(ends.begin(), ends.end());
  //write your code here
  for(int i=0;i<points.size();i++) {

    int xpos = searchByX(starts, points[i]);
    if(xpos!=-1) {
      int ypos = searchByY(ends, points[i]);
      int count = ypos != -1 ? xpos + 1 - ypos : 0;
      cnt.at(i) = count;
    } else {
      cnt.at(i) = 0;
    }
  }

  return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}


int main() {
  int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = fast_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
}
