#include <iostream>
#include <vector>

using std::vector;

int optimal_weight(int W, const vector<int> &w) {
  //write your code here
  int current_weight = 0;
  vector<int> weights(w.size()+1);
  weights.push_back(0);
  for(int a:w)
    weights.push_back(a);
  
  int weightMatrix[weights.size()][W+1];
  for(int i=0;i<weights.size();i++)
    weightMatrix[i][0] = 0;
  for(int i=0;i<W+1;i++)
    weightMatrix[0][i] = 0;
  
  for(int i=1;i<weights.size();i++) {
    for(int j=1; j<=W;j++) {
      weightMatrix[i][j] = weightMatrix[i-1][j];
      if(weights[i]<=j) {
        int temp = weightMatrix[i-1][j-weights[i]] + weights[i];
        if(temp>weightMatrix[i][j])
          weightMatrix[i][j] = temp;   
      }
    }
  }
  return weightMatrix[weights.size()-1][W];  
}

int main() {
  int n, W;
  std::cin >> W >> n;
  vector<int> w(n);
  for (int i = 0; i < n; i++) {
    std::cin >> w[i];
  }
  std::cout << optimal_weight(W, w) << '\n';
}
