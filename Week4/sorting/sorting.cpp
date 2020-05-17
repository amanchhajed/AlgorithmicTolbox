#include <iostream>
#include <vector>
#include <cstdlib>
#include <map>
using std::vector;
using std::swap;
using std::pair;
int partition2(vector<int> &a, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
    }
  }
  swap(a[l], a[j]);
  return j;
}

pair<int, int> partition3(vector<int>& a, int l, int r) {

  if(r-l <= 1) {
    if(a[r]<a[l])
      swap(a[r], a[l]);
    return pair<int, int>{l, r};
  }

  int pivot = a[r];
  int mid = l;
  while(mid<=r) {
    if(a[mid] < pivot) {
      swap(a[mid], a[l]);
      l++;
      mid++;
    } else if (a[mid] == pivot) {
      mid++;
    } else {
      swap(a[mid], a[r]);
      r--;
    }
  }
  return pair<int, int>{l-1, mid};
}

void randomized_quick_sort(vector<int> &a, int l, int r) {
  if (l >= r) {
    return;
  }

  int k = l + rand() % (r - l + 1);
  swap(a[l], a[k]);
  pair<int, int> temp = partition3(a, l, r);

  randomized_quick_sort(a, l, temp.first);
  randomized_quick_sort(a, temp.second, r);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  // vector<int> temp{1,2, 3, 4, 5, 0, 0, -1, -2, -3, 0, 0, 0};

  // partition3(temp, 0, temp.size()-1);
  // for(int &a : temp)
  //   std::cout << a << " ";
  randomized_quick_sort(a, 0, a.size() - 1);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cout << a[i] << ' ';
  }
}
