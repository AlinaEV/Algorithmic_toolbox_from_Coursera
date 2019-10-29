#include <iostream>
#include <cassert>

long long get_fibonacci_huge_naive(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
    }
    return current % m;
}

long long get_fibonacci_huge_Pisano(long long n, long long m) {
    if (n <= 1)
        return n;

    long long previous = 0;
    long long current  = 1;

    for (long long i = 0; i < n - 1; ++i) {
        long long tmp_previous = previous;
        previous = current;
        current = (tmp_previous + current) % m;
		//std::cout << i << ": " << tmp_previous << " " << previous << " " << current << "\n";
		if((previous == 0) && (current == 1)){
			//std::cout << i + 1 << ": " << tmp_previous << " " << previous << " " << current << "\n";
			return get_fibonacci_huge_Pisano((n % (i+1)), m);
		}
    }
	//std::cout << n - 1 << ": " << (current % m) << "\n";
    return current % m;
}

void test_algo(){
	assert(get_fibonacci_huge_Pisano(239, 1000) == 161);
	assert(get_fibonacci_huge_Pisano(2015, 3) == 1);
	assert(get_fibonacci_huge_Pisano(2816213588, 239) == 151);
	for (long long i = 1; i < 1000000000000000000; ++i)
		for (int j = 2; j < 1000; ++j){
		//std::cout << i << " " << j << " | " << get_fibonacci_huge_naive(i, j) << " " << get_fibonacci_huge_Pisano(i, j) << "\n";
        assert(get_fibonacci_huge_naive(i, j) == get_fibonacci_huge_Pisano(i, j));
		}
	std::cout<<"All OK!\n";
	}

int main() {
    /*long long n, m;
    std::cin >> n >> m;
    std::cout << get_fibonacci_huge_naive(n, m) << '\n';*/
	test_algo();
}

