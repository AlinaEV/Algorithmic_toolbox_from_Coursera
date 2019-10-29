#include <iostream>
#include <vector>
#include <cassert>

using std::cin;
using std::cout;
using std::vector;
using std::max;

int compute_min_refills(int dist, int tank, vector<int> & stops) {
    // write your code here
	int n = 0;
	stops.push_back(dist);
	for (int i = 0; i < (stops.size() - 1); ++i){
		if((dist == 0) || (dist < tank)){
			return n;
		}
		//cout << stops[i] << " " << stops[i + 1] << std::endl;
		if((stops[i] <= tank) && (stops[i + 1] > (tank*n))){
			dist -= stops[i];
			n++;
		}
		
		//cout << stops[i] << " n=" << n << std::endl;
	}
	//cout << "dist=" << dist << " nn=" << n <<  "\n";
	if((dist == 0) || ((dist - tank) <= 0)){
		return n;
	}else 
    return -1;
}

void test_algo(){
	assert(compute_min_refills(950, 400, vector<int>(4) = {200, 375, 550, 750}) == 2);
	assert(compute_min_refills(10, 3, vector<int>(4) = {1, 2, 5, 9}) == -1);
	assert(compute_min_refills(200, 250, vector<int>(2) = {100, 150}) == 0);
	cout << "All OK!\n";
}

int main() {
    int d = 0;
    cin >> d;
    int m = 0;
    cin >> m;
    int n = 0;
    cin >> n;

    vector<int> stops(n);
    for (size_t i = 0; i < n; ++i)
        cin >> stops.at(i);

    cout << compute_min_refills(d, m, stops) << "\n";
	
	//test_algo();
    return 0;
}
