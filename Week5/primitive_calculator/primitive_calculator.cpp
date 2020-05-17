#include <iostream>
#include <vector>
#include <algorithm>

using std::vector;

vector<int> optimal_sequence(int n) {
  vector<int> minOperations(n+1);
  minOperations[0] = 0;
  minOperations[1] = 0;
  for(int i=2;i<=n;i++) {
    int mini = minOperations[i-1];
    if(i%2 == 0)
      mini = std::min(mini, minOperations[i/2]);
    if(i%3 == 0)
      mini = std::min(mini, minOperations[i/3]);
    minOperations[i] = mini + 1;
  }
  vector<int> sequence(minOperations[n]+1);
  int key = n;
  int j = minOperations[n];
  while(key!=1) {
    sequence[j] = key;
    j--;
    int newKey = key-1;
    if(key%2 == 0 && minOperations[key/2] < minOperations[newKey])
      newKey = key/2;
    if(key%3 == 0 && minOperations[key/3] < minOperations[newKey])
      newKey = key/3;
    key = newKey;
  }
  sequence[j] = 1;
  return sequence;
}

int main() {
  int n;
  std::cin >> n;
  vector<int> sequence = optimal_sequence(n);
  std::cout << sequence.size() - 1 << std::endl;
  for (size_t i = 0; i < sequence.size(); ++i) {
    std::cout << sequence[i] << " ";
  }
}
