#include <iostream>
#include <cassert>

int gcd_naive(int a, int b) {
  int current_gcd = 1;
  for (int d = 2; d <= a && d <= b; d++) {
    if (a % d == 0 && b % d == 0) {
      if (d > current_gcd) {
        current_gcd = d;
      }
    }
  }
  return current_gcd;
}

int EuclidGCD(int a, int b) {
	int remainder = 0;
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(a % b)
		remainder = a % b;
	//std::cout << b << "\n";
	return EuclidGCD(b, remainder);
}

int EuclidGCD1(int a, int b) {
	if (a == 0) 
        return b; 
    return EuclidGCD1(b % a, a); 
}

int EuclidExtended(int a, int b, int *x, int *y) {
	int tmp = *x;
	if (a == 0) {
		*x = 0;
		*y = 1;
        return b; 
	}
	*x = *y - b/a * (*x);
	*y = *x;
    return EuclidExtended(b % a, a, x, y); 
}

void test_algo(){
	/*assert(EuclidGCD(18, 35) == 1);
	assert(EuclidGCD(30, 20) == 10);
	assert(EuclidGCD(35, 15) == 5);
	assert(EuclidGCD(1344, 217) == 7);
	assert(EuclidGCD(28851538, 1183019) == 17657);
	for (int i = 1; i < 200; ++i)
		for (int j = 0; j < 200; ++j){
		//std::cout << i << " " << j << " | " << EuclidGCD(i, j) << " " << EuclidGCD1(i, j) << "\n";
        assert(EuclidGCD(i, j) == EuclidGCD1(i, j));
		}*/
	int x, y;
	assert(EuclidExtended(18, 35, &x, &y) == 1);
	assert(EuclidExtended(30, 20, &x, &y) == 10);
	assert(EuclidExtended(35, 15, &x, &y) == 5);
	assert(EuclidExtended(1344, 217, &x, &y) == 7);
	assert(EuclidExtended(28851538, 1183019, &x, &y) == 17657);
	for (int i = 1; i < 200; ++i)
		for (int j = 0; j < 200; ++j){
		std::cout << i << " " << j << " | " << EuclidExtended(i, j, &x, &y) << " " << EuclidGCD1(i, j) << "\n";
        assert(EuclidExtended(i, j, &x, &y) == EuclidGCD1(i, j));
		}
	std::cout << "All OK!";
}

int main() {
  int a, b;
  std::cin >> a >> b;
  //std::cout << gcd_naive(a, b) << std::endl;
  //test_algo();
  std::cout << EuclidGCD(a, b) << std::endl;
  return 0;
}
