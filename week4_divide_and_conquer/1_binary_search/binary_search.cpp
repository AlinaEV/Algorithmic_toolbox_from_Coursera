#include <iostream>
#include <cassert>
#include <vector>
#include <cassert>

using std::vector;

int binary_search(const vector<int> &a, int x) {
  int left = 0, right = (int)a.size(); 
  //write your code here
  int mid;
  while(left <= right){
	mid = left + (right - left) / 2;
    if (a[mid] == x){
		return mid;
	}else if (a[mid] > x){
		right = mid - 1;
	}else{
		left = mid + 1;
	}
  }
  return -1;
}

int linear_search(const vector<int> &a, int x) {
  for (size_t i = 0; i < a.size(); ++i) {
    if (a[i] == x) return i;
  }
  return -1;
}


void test_algo(){
	vector<int> a {1,5,8,12,13};
	vector<int> b {8,1,23,1,11};
	for (int i = 0; i < 5; ++i) {
		std::cout << i << " = " << linear_search(a, b[i]) << " " <<
		binary_search(a, b[i]) << '\n';
		assert(linear_search(a, b[i]) == binary_search(a, b[i]));
	}
	std::cout << "All OK!\n";
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  int m;
  std::cin >> m;
  vector<int> b(m);
  for (int i = 0; i < m; ++i) {
    std::cin >> b[i];
  }
  for (int i = 0; i < m; ++i) {
    //replace with the call to binary_search when implemented
    std::cout << binary_search(a, b[i]) << ' ';
  }
  //test_algo();
}
