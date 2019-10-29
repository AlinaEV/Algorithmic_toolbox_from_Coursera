#include <algorithm>
#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

int get_majority_element(vector<int> &a, int iLeft, int iRight) {
	//std::cout << "left=" << iLeft << " right=" << iRight<< std::endl;
  if (iLeft == iRight) return a[iLeft];
  if (iLeft + 1 == iRight) {
	  if(a[iLeft] == a[iRight]){
		  return a[iLeft];
	  }else return 0;
  }
  //if (iLeft == iRight) return -1;
  //if (iLeft + 1 == iRight) return a[iLeft];
  //write your code here
  int mid = iLeft + (iRight - iLeft) / 2;
  int b = get_majority_element(a, iLeft, mid);
  int c = get_majority_element(a, mid + 1, iRight);
  //std::cout << "left=" << iLeft << " right=" << iRight<< std::endl;
  if(c || b){
	  //std::cout << c << " ";
	return 1;
  }
  //std::cout << "c=" << c << " b=" << b << " ";
  return 0;
}

void test_algo(){
	assert(get_majority_element(vector<int> (5) = {2,3,9,2,2}, 0, 4) == 1);
	std::cout << "\nok" << std::endl;
	assert(get_majority_element(vector<int> (4) = {1,2,3,4}, 0, 3) == 0);
	std::cout << "\nok" << std::endl;
	assert(get_majority_element(vector<int> (5) = {1,2,1,1,3}, 0, 4) == 1);
	std::cout << "\nok" << std::endl;
	std::cout << "All OK!\n";
}

int main() {
  int n;
  std::cin >> n;
  vector<int> a(n);
  for (size_t i = 0; i < a.size(); ++i) {
    std::cin >> a[i];
  }
  std::cout << (get_majority_element(a, 0, a.size()) != -1) << '\n';
  
  //test_algo();
}
