#include <iostream>
#include <string>

using std::string;

int edit_distance(const string &str1, const string &str2) {
  //write your code here
  int len1 = str1.size();
  int len2 = str2.size();
  int distance[len1+1][len2+1];
  for(int i=0;i<=len1;i++) {
    distance[i][0] = i;
  }
  for(int i=0;i<=len2;i++) {
    distance[0][i] = i;
  }
  for(int i=1;i<=len1;i++) {
    for(int j=1; j<=len2; j++) {
      int misMatch = str1[i-1] == str2[j-1] ? distance[i-1][j-1] : distance[i-1][j-1] + 1;
      distance[i][j] = std::min(
        distance[i-1][j] + 1,
        distance[i][j-1] + 1
      );
      distance[i][j] = std::min(
        distance[i][j],
        misMatch
      );
    }
  }
  return distance[len1][len2];
}

int main() {
  string str1;
  string str2;
  std::cin >> str1 >> str2;
  std::cout << edit_distance(str1, str2) << std::endl;
  return 0;
}
