#include <iostream>
#include <vector>

using std::vector;
struct Items
{
  int weight;
  int value;

  bool operator()(Items const& a, Items const& b) {
    return (double)a.weight/a.value < (double)b.weight/b.value;
  }

};

double get_optimal_value(int capacity, vector<Items> items) {
  double value = 0.0;
  sort(items.begin(), items.end(), Items());
  for(auto &a : items) {
    if(capacity >= a.weight) {
      capacity -= a.weight;
      value += a.value;
    } else {
      value += (double)capacity/a.weight*a.value;
      return value;
    }
  }
      // write your code here

  return value;
}

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<Items> items(n);
  for (int i = 0; i < n; i++) {
    std::cin >> items[i].value >> items[i].weight;
  }


  double optimal_value = get_optimal_value(capacity, items);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  return 0;
}
