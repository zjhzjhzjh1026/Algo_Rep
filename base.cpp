#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class Solution{
public:
	int base10ToBase9(int input){
		int res = 0;
		long long mask = 1;
		while(input >= mask){
			mask *= 9;
		}
		mask /= 9;
		while(mask){
			res = res*10 + input / mask;
			input %= mask;
			mask /= 9;
		}
		return res;
	}
};

int main(){
	Solution T;
	int res = T.base10ToBase9(17);
	cout << res << endl;
	return 0;
}