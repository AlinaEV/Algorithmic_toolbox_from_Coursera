#include <iostream>
#include <cassert>

int fibonacci_sum_squares_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current * current;
    }

    return sum % 10;
}
int fibonacci_sum_squares_naive2(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 100;
        sum += (current * current);
		sum %= 1000;
    }
	//std::cout << sum << std::endl;
    return sum % 10;
}
int fibonacci_sum_squares_fast(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 100;
    }
	sum = (previous * current) % 10;
	//std::cout << sum << std::endl;
    return sum;
}

void test_algo(){
	assert(fibonacci_sum_squares_fast(7) == 3);
	assert(fibonacci_sum_squares_fast(5) == 0);
	assert(fibonacci_sum_squares_fast(73) == 1);
	assert(fibonacci_sum_squares_fast(1234567890) == 0);
	for (long long i = 0; i < 1000000000000000000; ++i)
		for (long long i = 0; i < 1000000000000000000; ++i){
			//std::cout << i << ": " << fibonacci_sum_squares_naive2(i) << " " << fibonacci_sum_squares_fast(i) << std::endl;
			assert(fibonacci_sum_squares_naive2(i) == fibonacci_sum_squares_fast(i));
		}
	std::cout << "All OK!\n";
}

int main() {
    /*long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_squares_naive(n);*/
	test_algo();
}
