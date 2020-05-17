#include <iostream>
#include <vector>

using std::vector;

int lcs3(vector<int> &a, vector<int> &b, vector<int> &c) {
  //write your code here
  vector<vector<vector<int>>> lcs(a.size()+1, vector<vector<int>>(b.size()+1, vector<int>(c.size()+1, 0)));
  for(int i=0;i<=a.size();i++) {
    for(int j=0;j<=b.size();j++) {
      for(int k=0;k<=c.size();k++) {
        if(i==0 || j==0 || k==0)
          lcs[i][j][k] = 0;
        else if(a[i-1]==b[j-1] && a[i-1]==c[k-1])
          lcs[i][j][k] = lcs[i-1][j-1][k-1] + 1;
        else
          lcs[i][j][k] = std::max({
            lcs[i-1][j][k],
            lcs[i][j-1][k],
            lcs[i][j][k-1]
          });
      }
    }
  }
  return lcs[a.size()][b.size()][c.size()];
}

int main() {
  size_t an;
  std::cin >> an;
  vector<int> a(an);
  for (size_t i = 0; i < an; i++) {
    std::cin >> a[i];
  }
  size_t bn;
  std::cin >> bn;
  vector<int> b(bn);
  for (size_t i = 0; i < bn; i++) {
    std::cin >> b[i];
  }
  size_t cn;
  std::cin >> cn;
  vector<int> c(cn);
  for (size_t i = 0; i < cn; i++) {
    std::cin >> c[i];
  }
  std::cout << lcs3(a, b, c) << std::endl;
}
