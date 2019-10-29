#include <iostream>
#include <cassert>

long long lcm_naive(int a, int b) {
  for (long l = 1; l <= (long long) a * b; ++l)
    if (l % a == 0 && l % b == 0)
      return l;

  return (long long) a * b;
}

long long lcm_fast(int a, int b) {
	if(a == 0)
		return b;
	if(b == 0)
		return a;
	if(a == b)
		return a;
	if(a < b){
		for(int i = 1; i <= b; ++i){
			long tmp = (a*i);
			if(tmp % b == 0){
				//std::cout << tmp << "\n";
				return tmp;
			}
		}
	}else{
		for(int i = 1; i <= a; ++i){
			long tmp = (b*i);
			if(tmp % a == 0){
				//std::cout << tmp << "\n";
				return tmp;
			}
		}
	}
	//std::cout << (long long) a * b << "\n";
  return (long long) a * b;
}

long long gcd(int a, int b){
	if(a == 0)
		return b;
	return gcd(b % a, a);
}

long long lcm_fast2(int a, int b) {
	return a * b / gsd(a,b);
}

void test_algo(){
	assert(lcm_fast(6, 8) == 24);
	assert(lcm_fast(28851538, 1183019) == 1933053046);
	for (int i = 1; i < 200000; ++i)
		for (int j = 1; j < 200000; ++j){
		//std::cout << i << " " << j << " | " << lcm_fast(i, j) << " " << lcm_naive(i, j) << "\n";
        assert(lcm_fast(i, j) == lcm_naive(i, j));
		}
	std::cout << "All OK!\n";
}

int main() {
  int a, b;
  //std::cin >> a >> b;
  //std::cout << lcm_naive(a, b) << std::endl;
  test_algo();
  return 0;
}
