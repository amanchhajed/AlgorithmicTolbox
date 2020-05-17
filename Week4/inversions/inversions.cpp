#include <iostream>
#include <vector>

using std::vector;

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
  long long number_of_inversions = 0;
  if (right <= left + 1) return number_of_inversions;
  size_t ave = left + (right - left) / 2;
  number_of_inversions += get_number_of_inversions(a, b, left, ave);
  number_of_inversions += get_number_of_inversions(a, b, ave, right);
  //write your code here
  return number_of_inversions;
}

int Merge(vector<int>& a, int l, int mid, int r) {
  int i=0, j=0, k=l, count=0;
    int n1 = mid-l+1;
    int n2 = r - mid;
    int left[n1], right[n2];
    for(int i=0;i<n1;i++)
      left[i] = a[l+i];
    for(int i=0;i<n2;i++)
      right[i] = a[mid+i+1];
    
    while(i<n1 && j<n2) {
        if(left[i] <= right[j]) {
            a[k++] = left[i++];
        } else {
            count += n1-i;
            a[k++] = right[j++];
        }
    }
    while(i<n1)
      a[k++] = left[i++];
    while(k<n2)
      a[k++] = right[j++];
    return count;
}
int MergeSort(vector<int>& a, int l, int r) {
  int count = 0;
  if(r>l) {
    int mid = (l+r)/2;
    count += MergeSort(a, l, mid);
    count += MergeSort(a, mid+1, r);
    count += Merge(a, l, mid, r);
    return count;
  }
  return count;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  // vector<int> b(a.size());
  std::cout << MergeSort(a, 0, a.size()-1) << '\n';
  // for(int& temp: a)
  //   std::cout << temp << " ";
}
