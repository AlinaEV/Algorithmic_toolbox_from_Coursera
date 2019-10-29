#include <iostream>
#include <cassert>

int get_change(int m) {
  //write your code here
  int tens = (int)(m / 10);
  int fives = (int)((m % 10) / 5);
  int ones = ((m % 10) % 5);
  return tens + fives + ones;
}

void test_algo(){
	assert(get_change(2) == 2);
	assert(get_change(28) == 6);
	std::cout << "All OK!\n";
}

int main() {
  //int m;
  //std::cin >> m;
  //std::cout << get_change(m) << '\n';
  test_algo();
  
}
