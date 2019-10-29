#include <algorithm>
#include <iostream>
#include <climits>
#include <vector>
#include <cassert>
//#include <unordered_set>

using std::vector;

struct Segment {
  int start, end;
};

void swapSegments(vector<Segment> & a, int i, int j){
	Segment tmp = a[i];
	a[i] = a[j];
	a[j] = tmp;
}

/*vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
	if (nums1.empty() || nums2.empty()){
		return std::vector<int>();
	}
	std::unordered_set<int> set{nums1.cbegin(), nums1.cend()};
	std::vector<int> intersections;
	for (auto n: nums2){
		if (set.erase(n) > 0){ // if n exists in set, then 1 is returned and n is erased; otherwise, 0.
			intersections.push_back(n);
		} 
	}
	return intersections;
}*/

vector<int> optimal_points(vector<Segment> &segments) {
  vector<int> points;
  //write your code here
  //1. Sort by end
  for (size_t i = 0; i < (segments.size()-1); ++i) {
	  for(int j = i+1; j < segments.size(); ++j){
		  if(segments[i].end > segments[j].end){
			  swapSegments(segments, i, j);
		  }
	  }
  }
  
  //2.Take first end point
  int point = segments[0].end;
  points.push_back(point);
  
  //3.Find all en points
  for(int i = 1; i < segments.size(); ++i){
	  if(point < segments[i].start || point > segments[i].end){
		  point = segments[i].end;
		  points.push_back(point);
	  }
  }
  
  //0. Find all points from all segments
  /*for (size_t i = segments[0].start; i <= segments.back().end; ++i) {
	  points.push_back(i);
  }*/
  
  //1. Find intersections(пересечения) of segments
  
  /*for (size_t i = 0; i < (segments.size() - 1); ++i) {
	  vector<Segment> intersections;
	  for (size_t j = i + 1; j < segments.size(); ++j) {
		  vector<int> tmpVec;
		  for (int a = segments[i].start; a <= segments[i].end; ++a) {
			  for (int b = segments[j].start; b <= segments[j].end; ++b) {
				if (a == b){
				  tmpVec.push_back(b);
				}
			  }
		  }
		  if(tmpVec.size()){
			Segment tmp; 
			tmp.start = tmpVec.front();
			tmp.end = tmpVec.back();
			//if((intersections.size()>0)&&(tmp.start <= intersections.back().end)){
			//	intersections.back().end = tmp.end;
			//}else{
				intersections.push_back(tmp);
			//}
			std::cout << " " << tmp.start << ":" << tmp.end << ", ";
		  }
	  }
	  if(intersections.size() <= 0){
		  points.push_back(segments[i].end);
	  }else {
		  for(int j = 0; j < (intersections.size() - 1); ++j){
			  vector<int> tmpVec;
			  for (int a = intersections[j].start; a <= intersections[j].end; ++a) {
				  for (int b = intersections[j+1].start; b <= intersections[j+1].end; ++b) {
					if (a == b){
					  tmpVec.push_back(b);
					}
				  }
			  }
			  if(tmpVec.size()){
				  if(points.size() <= 0){
					  points.push_back(tmpVec[j]);
				  }else if(points.back() != tmpVec[j]){
					  points.push_back(tmpVec[j]);
				  }
			  }
			  //if(intersections[j].end >= intersections[j].start)
			  //points.push_back(intersections[i].start);
			  //points.push_back(intersections[i].end);
		  }
		  
	  }
  }*/
  
  //2. Find all segments ends
  /*for (size_t i = 0; i < (intersections.size() - 1); ++i) {
	  vector<int> tmp;
	  for (size_t j = i + 1; j < intersections.size(); ++j) {
		  
		  for (int a = intersections[i].start; a <= intersections[i].end; ++a) {
			  for (int b = intersections[j].start; b <= intersections[j].end; ++b) {
				if (a == b){
				  tmp.push_back(b);
				}
			  }
		  }
	  }
	  if(tmp.size() <= 0){
		  points.push_back(intersections[i].end);
	  }else{
		  //points = tmp;
		  for (size_t j = 0; j < tmp.size(); ++j){
			  if(points.size() <= 0){
				  points.push_back(tmp[j]);
			  }else if(points.back() != tmp[j]){
				  points.push_back(tmp[j]);
			  }
		  }
	  }
  }*/

  /*for (size_t i = 0; i < intersections.size(); ++i) {
    points.push_back(intersections[i].start);
    points.push_back(intersections[i].end);
  }*/
  /*for (size_t i = 0; i < segments.size(); ++i) {
    points.push_back(segments[i].start);
    points.push_back(segments[i].end);
  }*/
  return points;
}

void test_algo(){
	//1
	vector<Segment> segments = {{1,3}, {2,5}, {3,6}};
	vector<int> points = optimal_points(segments);
	std::cout << points.size() << ": ";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
	std::cout << std::endl;
	assert(points.size() == 1);
	//2
	segments = {{4,7},{1,3},{2,5},{5,6}};
	points = optimal_points(segments);
	std::cout << points.size() << ": ";
	for (size_t i = 0; i < points.size(); ++i) {
		std::cout << points[i] << " ";
	}
	std::cout << std::endl;
	assert(points.size() == 2);
	std::cout << "All OK!\n";
}

int main() {
  int n;
  std::cin >> n;
  vector<Segment> segments(n);
  for (size_t i = 0; i < segments.size(); ++i) {
    std::cin >> segments[i].start >> segments[i].end;
  }
  vector<int> points = optimal_points(segments);
  std::cout << points.size() << "\n";
  for (size_t i = 0; i < points.size(); ++i) {
    std::cout << points[i] << " ";
  }
  
  //test_algo();
}
