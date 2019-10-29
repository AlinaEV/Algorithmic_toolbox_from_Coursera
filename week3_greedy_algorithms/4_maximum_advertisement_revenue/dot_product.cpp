#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

void swapEl(vector<int> & a, int i, int j){
	int tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

long long max_dot_product(vector<int> a, vector<int> b) {
  // write your code here
  //1. Sort a[]
  for(size_t i = 0; i < (a.size() - 1); ++i){
	  if(a[i] < a[i + 1]){
		  swapEl(a, i, i + 1);
	  }
  }
  long long result = 0;
  //2. Find max[a[i]*b[i]
  for(size_t i = 0; i < a.size(); ++i){
	  int maxMult = ((long long) a[i]) * b[0];
	  for (size_t j = 1; j < b.size(); j++) {
		  long long m = ((long long) a[i]) * b[j]; 
		  if(m > maxMult){
			  maxMult = m;
			  b.erase(b.begin() + j);
		  }
	  }
	  //3. Find Sum
	  result += maxMult;
  }
  //3. Find Sum
  /*long long result = 0;
  for (size_t i = 0; i < a.size(); i++) {
    result += ((long long) a[i]) * b[i];
  }*/
  
  return result;
}

void test_algo(){
	assert(max_dot_product(vector<int> {23}, vector<int> {39}) == 897);
	assert(max_dot_product(vector<int> {1, 3, -5}, vector<int> {-2, 4, 1}) == 23);
	std::cout << "All OK!\n";
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> a(n), b(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> a[i];
  }
  for (size_t i = 0; i < n; i++) {
    std::cin >> b[i];
  }
  std::cout << max_dot_product(a, b) << std::endl;
  
  //test_algo();
}
