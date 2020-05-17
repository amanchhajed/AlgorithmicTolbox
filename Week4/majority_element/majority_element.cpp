#include <algorithm>
#include <iostream>
#include <vector>

using std::vector;

int get_majority_element(vector<int> &a, int left, int right) {
  if (left == right) return -1;
  if (left + 1 == right) return a[left];
  //write your code here
  int count = 0;
  int majority_element = a.at(left);
  for(int i=left;i<right;i++) {
    if(a.at(i) == majority_element)
      count++;
    else if(count==1)
      majority_element = a.at(i);
  }

  int n = 0;
  for(int i=left; i<right;i++)
    if(a.at(i)==majority_element)
      n++;
  int majority_count = (right-left)/2 + 1;
  return n>=majority_count ? 1 : -1;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
}
