#include <iostream>
#include <cassert>
#include <string>
#include <vector>

using std::vector;
using std::string;
using std::max;
using std::min;

long long eval(long long a, long long b, char op) {
  if (op == '*') {
    return a * b;
  } else if (op == '+') {
    return a + b;
  } else if (op == '-') {
    return a - b;
  } else {
    assert(0);
  }
}
std::pair<long long , long long> minAndMax(vector<vector<int> > minArray, vector<vector<int> > maxArray, vector<char> operators, int i, int j) {
  if(i==j) {
    return std::make_pair(minArray[i][i], maxArray[i][i]);
  }
  long long minVal = INT64_MAX;
  long long maxVal = INT64_MIN;
  for(int k=i; k<j;k++) {
    minVal = std::min({
      minVal,
      eval(minArray[i][k], minArray[k+1][j], operators[k]),
      eval(maxArray[i][k], minArray[k+1][j], operators[k]),
      eval(minArray[i][k], maxArray[k+1][j], operators[k]),
      eval(maxArray[i][k], maxArray[k+1][j], operators[k])
    });
    maxVal = std::max({
      maxVal,
      eval(minArray[i][k], minArray[k+1][j], operators[k]),
      eval(maxArray[i][k], minArray[k+1][j], operators[k]),
      eval(minArray[i][k], maxArray[k+1][j], operators[k]),
      eval(maxArray[i][k], maxArray[k+1][j], operators[k])
    });
  }
  return std::make_pair(minVal, maxVal);
}
long long get_maximum_value(const string &exp) {
  if(exp.size()<=1)
    return std::stoi(exp);
  //write your code here
  int numDigits = exp.size()/2 + 1;
  int numOps = exp.size()/2;
  vector<int> digits;
  for(int i=0;i<exp.size();i+=2) {
    digits.push_back(int(exp[i] - '0'));
  }
  vector<char> operators;
  for(int i=1;i<exp.size(); i+=2)
    operators.push_back(exp[i]);
  vector<vector<int> > minVal(numDigits, vector<int>(numDigits, 0));
  vector<vector<int> > maxVal(numDigits, vector<int>(numDigits, 0));
  for(int i=0;i<numDigits;i++) {
    minVal[i][i] = digits[i];
    maxVal[i][i] = digits[i];
  }
  for(int s=1; s<numDigits; s++) {
    for(int i=0; i<numDigits-s; i++) {
      int j = i+s;
      auto intPair = minAndMax(minVal, maxVal, operators, i, j);
      minVal[i][j] = intPair.first;
      maxVal[i][j] = intPair.second;
    }
  }
  return maxVal[0][numDigits-1];
}

int main() {
  string s;
  std::cin >> s;
  std::cout << get_maximum_value(s) << '\n';
}
