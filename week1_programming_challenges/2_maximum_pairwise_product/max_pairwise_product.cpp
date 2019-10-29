#include <cstdlib>
#include <iostream>
#include <vector>
//#include <algorithm>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const std::vector<int>& numbers) {
    long long max_product = 0;
	int n = numbers.size();

    for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			//if((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
			//	max_index2 = j;
			//max_product = std::max(max_product,(long long)numbers[i] * numbers[j]);
			if(((long long)numbers[i])* numbers[j] > max_product){
				max_product = ((long long)numbers[i])* numbers[j];
			}
        }
    }

    return max_product;
}

long long MaxPairwiseProductFast(const std::vector<int>& numbers) {
    int n = numbers.size();

	int max_index1 = -1;
    for (int i = 0; i < n; ++i) {
        if((max_index1 == -1) || (numbers[i] > numbers[max_index1])){
			max_index1 = i;
		}
    }
	int max_index2 = -1;
	for (int j = 0; j < n; ++j) {
		if((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2]))){
			max_index2 = j;
		}
        //max_product = std::max(max_product,(long long)numbers[i] * numbers[j]);
        }

	cout << max_index1 << ' ' << max_index2 << "\n";
    return ((long long)((long long)numbers[max_index1]) * numbers[max_index2]);
}

int main() {
    /*int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
    }*/
	
	//::Stress Test::
	while(true){
		int n = rand() % 1000 +2;
		cout << n << "\n";
		vector<int> a;
		for(int i = 0; i < n; ++i){
			a.push_back(rand() % 10000);
		}
		for(int i = 0; i < n; ++i){
			cout << a[i] << ' ';
		}		
		cout << "\n";
		long long res1 = MaxPairwiseProduct(a);
		long long res2 = MaxPairwiseProductFast(a);
		if(res1 != res2){
			cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
			break;
		}
		else{
			cout << "OK" << "\n";
		}
	}
	int n;
    std::cin >> n;
    std::vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        std::cin >> numbers[i];
	}
	//std::cout << MaxPairwiseProductFast(std::vector<int>(100000, 0)) << "\n";
    return 0;
}
