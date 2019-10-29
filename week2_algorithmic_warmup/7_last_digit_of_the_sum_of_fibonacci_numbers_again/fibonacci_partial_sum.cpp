#include <iostream>
#include <vector>
#include <cassert>
using std::vector;

long long get_fibonacci_partial_sum_naive(long long from, long long to) {
    long long sum = 0;

    long long current = 0;
    long long next  = 1;

    for (long long i = 0; i <= to; ++i) {
        if (i >= from) {
            sum += current;
        }

        long long new_current = next;
        next = next + current;
        current = new_current%10;
    }

    return sum % 10;
}
void test_algo(){
	assert(get_fibonacci_partial_sum_naive(3, 7) == 1);
	assert(get_fibonacci_partial_sum_naive(10, 10) == 5);
	assert(get_fibonacci_partial_sum_naive(10, 200) == 2);
	/*for (long long i = 0; i < 1000000000000000000; ++i)
		for (long long i = 0; i < 1000000000000000000; ++i){
			std::cout << i << ": " << fibonacci_sum_naive(i) << " " << fibonacci_sum_fast(i) << std::endl;
			assert(fibonacci_sum_naive(i) == fibonacci_sum_fast(i));
		}*/
	std::cout << "All OK!\n";
}

int main() {
    /*long long from, to;
    std::cin >> from >> to;
    std::cout << get_fibonacci_partial_sum_naive(from, to) << '\n';*/
	test_algo();
}
