#include <algorithm>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>

using std::vector;
using std::string;

bool isGreaterOrEqual(string a, string b){
	//compare two combinations
	return (a.append(b) >= b.append(a)) ? true : false;
}

string largest_number(vector<string> a) {
  //write your code here
  //Sort
  for(int i = 0; i < (a.size() - 1); ++i){
	  for(int j = i + 1; j < a.size(); ++j){
		  if(!isGreaterOrEqual(a[i], a[j])){
			string tmp = a[i];
			a[i] = a[j];
			a[j] = tmp;
		  }
	  }
  }
  //
  std::stringstream ret;
  for (size_t i = 0; i < a.size(); i++) {
    ret << a[i];
  }
  string result;
  ret >> result;
  return result;
}

int main() {
  int n;
  std::cin >> n;
  vector<string> a(n);
  for (size_t i = 0; i < a.size(); i++) {
    std::cin >> a[i];
  }
  std::cout << largest_number(a);
}
