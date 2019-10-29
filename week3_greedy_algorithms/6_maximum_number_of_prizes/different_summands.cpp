#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

vector<int> optimal_summands(int n) {
	vector<int> summands;
	//write your code here
	int a = 1;
	while(n){
		if(a >= (n - a)){
			summands.push_back(n);
			return summands;
		}else{
			summands.push_back(a);
			n -= a;
			++a;
		}
	}
	return summands;
}

void test_algo(){
	//1
	vector<int> summands = optimal_summands(6);
	std::cout << summands.size() << ": ";
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << " ";
	}
	std::cout << '\n';
	assert(summands.size() == 3);
	//2
	summands = optimal_summands(8);
	std::cout << summands.size() << ": ";
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << " ";
	}
	std::cout << '\n';
	assert(summands.size() == 3);
	//3
	summands = optimal_summands(2);
	std::cout << summands.size() << ": ";
	for (size_t i = 0; i < summands.size(); ++i) {
		std::cout << summands[i] << " ";
	}
	std::cout << '\n';
	assert(summands.size() == 1);
}

int main() {
  int n;
  std::cin >> n;
  vector<int> summands = optimal_summands(n);
  std::cout << summands.size() << '\n';
  for (size_t i = 0; i < summands.size(); ++i) {
    std::cout << summands[i] << ' ';
  }
  //test_algo();
}
