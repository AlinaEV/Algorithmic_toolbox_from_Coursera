#include <algorithm>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>
#include <string>
#include <cmath>
#include <cassert>

using std::vector;
using std::string;
using std::pair;
using std::min;

//Calculate distance between two points
double distance(int x1, int y1, int x2, int y2){
	return (double)sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
}


void outXY(vector<int> x, vector<int> y, int left, int right){
	std::cout << "Points: ";
	for(auto i = left; i <= right; ++i){
		std::cout << x[i] << ":" << y[i] << " ";
	}
	std::cout << "\n";
}

//Sort by x-coordinate
double mergeX(vector<int> &x, vector<int> &y, size_t left, size_t right, size_t ave){
	vector<int> x1;
	vector<int> y1;
	size_t i = left, j = ave + 1;
	while((i <= ave) && (j <= right)){
		if(x[i] <= x[j]){
			x1.push_back(x[i]);
			y1.push_back(y[i]);
			i++;
		}else{
			x1.push_back(x[j]);
			y1.push_back(y[j]);
			j++;
		}
	}
	//rest elements
	while(i <= ave){
		x1.push_back(x[i]);
		y1.push_back(y[i]);
		i++;
	}
	while(j <= right){
		x1.push_back(x[j]);
		y1.push_back(y[j]);
		j++;
	}
	for(i = left, j = 0; i <= right; ++i){
		x[i] = x1[j];
		y[i] = y1[j++];
	}
	return distance(x[left], y[left], x[right], y[right]);
	//min(distance(x[left], y[left], x[ave], y[ave]), 
				//distance(x[ave], y[ave], x[right], y[right]));
}

//Merge sort algorithm
double mergeSort(vector<int> &x, vector<int> &y, size_t left, size_t right, double dist) {
	double d = dist;
	//std::cout << left << "-" << right << " ";
	if (left < right){
		auto ave = ((left + right) >> 1);
		d = min(d, mergeSort(x, y, left, ave, dist));
		d = min(d, mergeSort(x, y, ave + 1, right, dist));
		d = min(d, mergeX(x, y, left, right, ave));
	}
	//std::cout << left << "-" << right << " ";
	//std::cout << "min_dist=" << d << "\n";
	return d;
}

//Filter set by x-distances to the mid < d
void filter(double d, vector<int> &x, vector<int> &y, size_t left, size_t right){
	int mid = x[x.size() / 2];	//middle line
	for(auto i = left; i <= right; ++i){
		if(abs(x[i] - mid) > d){
			x.erase(x.begin() + i);
			y.erase(y.begin() + i);
			--right;
		}
	}
}

double scan7points(vector<int> x, vector<int> y, size_t left, size_t right, double dist){
	double d = dist;
	for(auto i = left; i <= right; ++i){
		for(auto j = left; j <= right; ++j){
			if((abs(i - j) <= 7)&&(i!=j)){
				d = min(d, distance(x[i], y[i], x[j], y[j]));
			}
		}
	}
	return d;
}

double minimal_distance(vector<int> x, vector<int> y) {
  //write your code here
  double d = distance(x[0], y[0], x[x.size() - 1], y[x.size() - 1]);
  //outXY(x,y,0,x.size()-1);
  if(x.size() > 2){
	  //Sort by x - coord 
	  d = mergeSort(x, y, 0, x.size() - 1, d);
	  //std::cout << "After sorting:\n";
	  //outXY(x,y,0,x.size()-1);
	  //std::cout << "d min=" << std::setprecision(9) << d << "\n";
	  //Filter set by x-distances to the mid < d
	  filter(d, x, y, 0, x.size() - 1);
	  //std::cout << "After filtering:\n";
	  //outXY(x,y,0,x.size()-1);
	  //Sort by y - coord
	  d = min(d, mergeSort(y, x, 0, y.size() - 1, d));
	  //std::cout << "After sorting:\n";
	  //outXY(x,y,0,x.size()-1);
	  //std::cout << "d merge=" << std::setprecision(9) << d << "\n";
	  //Scan resulting list: compute 7 distances and min d'
	  d = min(d, scan7points(x, y, 0, y.size() - 1, d));
  }else {
	  d = mergeSort(x, y, 0, 1, d);
  }
  return d;
}

void test_algo(){
	double result;
	result = minimal_distance(vector<int> {0,3}, vector<int> {0,4});
	std::cout << std::fixed;
	std::cout << std::setprecision(9) << result << " Ok\n";
	assert(result == 5.0f);
	result = minimal_distance(vector<int> {7,1,4,7}, vector<int> {7,100,8,7});
	std::cout << std::fixed;
	std::cout << result << " Ok\n";
	assert(result == 0.0f);
	result = minimal_distance(vector<int> {4,-2,-3,-1,2,-4,1,-1,3,-4,-2}, 
								vector<int> {4,-2,-4,3,3,0,1,-1,-1,2,4});
	std::cout << result << "\n";
	assert((result - 1.414213f) <= 0.001);
	std::cout << "All OK!\n";
}

int main() {
  size_t n;
  std::cin >> n;
  vector<int> x(n);
  vector<int> y(n);
  for (size_t i = 0; i < n; i++) {
    std::cin >> x[i] >> y[i];
  }
  std::cout << std::fixed;
  std::cout << std::setprecision(9) << minimal_distance(x, y) << "\n";
  
  //test_algo();
}


/*int* partition3(vector<int> &x, vector<int> &y, int l, int r) {
  int a = x[l];
  int j = l;
  static int m[2] = {0};
  for (int i = l + 1; i <= r; i++) {
    if (x[i] <= a) {
      j++;
      std::swap(x[i], x[j]);
	  std::swap(y[i], y[j]);
    }
	if (x[i] == a){
		m[1]++;
	}
  }
  std::swap(x[l], x[j]);
  std::swap(y[l], y[j]);
  m[0] = j;
  return m;
}

void randomized_quick_sort(vector<int> &x, vector<int> &y, int l, int r) {
  if (l >= r) {
    return;
  }
  int k = l + rand() % (r - l + 1);
  std::swap(x[l], x[k]);
  int m = partition2(x, y, l, r);
  randomized_quick_sort(x, y, l, m - 1);
  randomized_quick_sort(x, y, m + 1, r);
}*/