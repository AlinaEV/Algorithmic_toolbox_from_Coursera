#include <iostream>
#include <cassert>

int fibonacci_sum_naive(long long n) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;
    long long sum      = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = tmp_previous + current;
        sum += current;
    }

    return sum % 10;
}

int fibonacci_sum_fast(long long n) {
    if (n <= 1)
        return n;

    int previous = 0;
    int current  = 1;
    long long sum = 1;

    for (long long i = 0; i < n - 1; ++i) {
        int tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % 10;
        sum += current;
    }

    return sum % 10;
}

void algo_test(){
	assert(fibonacci_sum_fast(3) == 4);
	assert(fibonacci_sum_fast(100) == 5);
	for (long long i = 0; i < 1000000000000000000; ++i){
		std::cout << i << ": " << fibonacci_sum_naive(i) << " " << fibonacci_sum_fast(i) << std::endl;
        assert(fibonacci_sum_naive(i) == fibonacci_sum_fast(i));
	}
	std::cout << "All OK!\n";
}

int main() {
    long long n = 0;
    std::cin >> n;
    std::cout << fibonacci_sum_fast(n);
	//algo_test();
}
