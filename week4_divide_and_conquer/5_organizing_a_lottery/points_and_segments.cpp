#include <iostream>
#include <vector>
#include <cassert>

using std::vector;
using std::swap;

/*int* partition3(vector<int> &a, vector<int> &b, int l, int r) {
  int x = a[l];
  int j = l;
  static int m[2] = {0};
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
	  swap(b[i], b[j]);
    }
	if (a[i] == x){
		m[1]++;
	}
  }
  swap(a[l], a[j]);
  swap(b[l], b[j]);
  m[0] = j;
  return m;
}*/

int partition2(vector<int> &a, vector<int> &b, int l, int r) {
  int x = a[l];
  int j = l;
  for (int i = l + 1; i <= r; i++) {
    if (a[i] <= x) {
      j++;
      swap(a[i], a[j]);
	  swap(b[i], b[j]);
    }
  }
  swap(a[l], a[j]);
  swap(b[l], b[j]);
  return j;
}

void randomized_quick_sort(vector<int> &a, vector<int> &b, int l, int r) {
  if (l >= r) {
    return;
  }
  //int k = l + rand() % (r - l + 1);
  //swap(a[l], a[k]);
  int m = partition2(a, b, l, r);
  randomized_quick_sort(a, b, l, m - 1);
  randomized_quick_sort(a, b, m + 1, r);
}

vector<int> fast_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
	vector<int> cnt(points.size());
	//write your code here
	/*while(i < starts.size()){
		if(points[j] < starts[i]){
			++j;
		}else if(points[j] > ends[i]){
			++i;
		}
		if(points[j] >= starts[i]){
			if(points[j] <= ends[i]){
				++(cnt[j]);
				++i;
			}else{
				++i;
			}
		}
		std::cout <<"i=" << i << " cnt=" << cnt[j] <<"\n";
	}*/
	vector<int> indices(points.size());
	for(int i = 0; i < points.size(); ++i){
		indices[i] = i;
		std::cout << points[i] << "." << indices[i] << " ";
	}
	//std::cout <<"\n";
	randomized_quick_sort(points, indices, 0, points.size() - 1);
	for(int i = 0; i < indices.size(); ++i){
		std::cout << points[i] << "." << indices[i] << " ";
	}
	vector<int> all(starts.begin(), starts.end());
	vector<int> b(starts.size(), 0);//b:0-start,1-end,2-point
	all.insert(all.end(), ends.begin(), ends.end());
	b.insert(b.end(), ends.size(), 1);
	all.insert(all.end(), points.begin(), points.end());
	b.insert(b.end(), points.size(), 2);
	randomized_quick_sort(all, b, 0, all.size()-1);
	for(int i = 0; i < all.size(); ++i){
		std::cout << all[i] << "_" << b[i] << " ";
	}
	std::cout <<  std::endl;
	int j = 0; //iterator in pointers
	int c = 0;
	for(int i = 0; i < all.size(), j < points.size(); ++i){
		switch(b[i]){
			case 0:
				c += 1;
				break;
			case 1:
				c -= 1;
				break;
			case 2:
				cnt[indices[j]] += c;
				std::cout << i << ":" << j << " cnt=" << cnt[indices[j]]<< "\n";
				++j;
				break;
			default: break;
		}
		std::cout << i << ":" << j << "\n";
	}
	for(int i = 0; i < cnt.size(); ++i){
		std::cout << cnt[i] <<" ";
	}
	return cnt;
}

vector<int> naive_count_segments(vector<int> starts, vector<int> ends, vector<int> points) {
  vector<int> cnt(points.size());
  for (size_t i = 0; i < points.size(); i++) {
    for (size_t j = 0; j < starts.size(); j++) {
      cnt[i] += starts[j] <= points[i] && points[i] <= ends[j];
    }
  }
  return cnt;
}

void test_algo(){
	assert(fast_count_segments(vector<int> (2) = {0,7}, vector<int> (2) = {5,10}, 
		vector<int> (3) = {1,6,11}) == (vector<int> (3) = {1,0,0}));
		std::cout << "\nok" << std::endl;
	assert(fast_count_segments(vector<int> (1) = {-10}, vector<int> (1) = {10}, 
		vector<int> (3) = {-100,100,0}) == (vector<int> (3) = {0,0,1}));
		std::cout << "\nok" << std::endl;
	assert(fast_count_segments(vector<int> (3) = {0,-3,7}, vector<int> (3) = {5,2,10}, 
		vector<int> (2) = {1,6}) == (vector<int> (2) = {2,0}));
	std::cout << "All OK!\n";
}

int main() {
  /*int n, m;
  std::cin >> n >> m;
  vector<int> starts(n), ends(n);
  for (size_t i = 0; i < starts.size(); i++) {
    std::cin >> starts[i] >> ends[i];
  }
  vector<int> points(m);
  for (size_t i = 0; i < points.size(); i++) {
    std::cin >> points[i];
  }
  //use fast_count_segments
  vector<int> cnt = naive_count_segments(starts, ends, points);
  for (size_t i = 0; i < cnt.size(); i++) {
    std::cout << cnt[i] << ' ';
  }
  */
  test_algo();
}
