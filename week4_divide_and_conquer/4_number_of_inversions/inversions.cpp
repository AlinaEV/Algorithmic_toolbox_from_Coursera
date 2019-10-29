#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

long long merge(vector<int> &a, vector<int> &b, size_t left, size_t right){
	long long k = 0;
	int tmp;
	//std::cout << left << ":" << right << " ";
	for(int i = left; i < right; ++i){
		if(a[i] > a[i + 1]){
			k++;
			//std::cout <<"i=" << i << " ";
			tmp = a[i];
			a[i] = a[i + 1];
			a[i + 1] = tmp;
			//b.push_back(a[i + 1]);
			//b.push_back(a[i]);
		}else{
			//b.push_back(a[i]);
			//b.push_back(a[i + 1]);
		}
	}
	//std::cout << "k=" << k << " ";
	return k;
}

long long get_number_of_inversions(vector<int> &a, vector<int> &b, size_t left, size_t right) {
	//std::cout << left << ":" << right << " ";
	long long number_of_inversions = 0;
	if (right <= left + 1){
		return number_of_inversions;
	}
	size_t ave = left + (right - left) / 2;
	number_of_inversions += get_number_of_inversions(a, b, left, ave);
	number_of_inversions += get_number_of_inversions(a, b, ave, right);
	//write your code here
	number_of_inversions += merge(a, b, left, right);
	//std::cout << " num=" << number_of_inversions << "\n";
	return number_of_inversions;
}

void test_algo(){
	assert(get_number_of_inversions(vector<int> (5) = {2,3,9,2,9}, 
		vector<int> (5) = {0}, 0, 4) == 2);
	std::cout << "All OK!\n";
}

int main() {
	int n;
	std::cin >> n;
	vector<int> a(n);
	for (size_t i = 0; i < a.size(); i++) {
		std::cin >> a[i];
	}
	vector<int> b(a.size());
	std::cout << get_number_of_inversions(a, b, 0, a.size()) << '\n';
	
	//test_algo();
}
