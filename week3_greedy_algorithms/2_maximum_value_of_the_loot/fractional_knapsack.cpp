#include <iostream>
#include <vector>
#include <cassert>

using std::vector;

double get_optimal_value(int capacity, vector<int> weights, vector<int> values) {
	double value = 0.0;
	// write your code here

	//std::sort(weights.begin(), weights.end());
	//std::min_element(weights.begin(), weights.end());
	
	/*for(int i = 1; i != weights.size(); ++i){
		if(capacity == 0){
			return value;
		}

		if(weights[i] < capacity){
			weight = weights[i];
		}else {
			weight = capacity;
		}
		value += weight * values[i] / weights[i];
		weights[i] -= weight;
		capacity -= weight;
	}*/
	
	//Sorting 
	for(int i = 0; i < weights.size(); ++i){
		for(int j = i + 1; j < weights.size(); ++j){
			float a = values[i]/weights[i],
					b = values[j]/weights[j];
			if(a < b){
				int v = values[j], w = weights[j];
				values[j] = values[i];
				weights[j] = weights[i];
				values[i] = v;
				weights[i] = w;
			}
		}
	}
	
	//Find Max Value
	for(int i = 0; i < weights.size(); ++i){
		if(capacity == 0){
			return value;
		}
		//std::cout << i << ": v=" << values[i] << "\n";
		if(weights[i] < capacity){
			capacity -= weights[i];
			value += values[i];
		}else{
			value += ((double)(capacity * values[i])/ weights[i]);
			weights[i] -= capacity;
			capacity = 0;
		}
	}
	
	return value;	//maximal value of fractions of items that fit into the knapsack
}

 void test_algo(){
	double optimal_value = get_optimal_value(50, vector<int> {20, 50, 30}, 
											vector<int> {60, 100, 120});
	assert((optimal_value - 180.0000) <= 0.001);
	optimal_value = get_optimal_value(10, vector<int> {30}, vector<int> {500});
	//std::cout.precision(10);
	//std::cout << optimal_value << "\n";
	assert((optimal_value - 166.6667) <= 0.001);
	std::cout << "All OK!\n";
 }

int main() {
  int n;
  int capacity;
  std::cin >> n >> capacity;
  vector<int> values(n);
  vector<int> weights(n);
  for (int i = 0; i < n; i++) {
    std::cin >> values[i] >> weights[i];
  }
  
  double optimal_value = get_optimal_value(capacity, weights, values);

  std::cout.precision(10);
  std::cout << optimal_value << std::endl;
  //test_algo();
  return 0;
}
