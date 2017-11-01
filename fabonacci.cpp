#include<iostream>

using namespace std;

class Solution{
public:
	int fab1(int n){
		if(!n)  return 0;
		if(n == 1)  return 1;
		return fab1(n-1) + fab1(n-2); 
	}

	int fab2(int n){
		if(!n) return 0;
		int now = 1, pre = 0;
		for(int i = 0; i < n - 1; i++){
			pre = now + pre;
			swap(now, pre);
		}
		return now;
	}
};

int main(){
	Solution T;
	for(int i = 0; i < 20; i++)
		cout << T.fab2(i) << endl;
	return 0;
}