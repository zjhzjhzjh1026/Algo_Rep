#include <iostream>
#include <vector>

using namespace std;

void foo(vector<int> &counts){
	for(auto &c : counts){
		c++;
	}
}

int main(){
	vector<int> cnt(4000000, 1);
	foo(cnt);
	return 0;
}