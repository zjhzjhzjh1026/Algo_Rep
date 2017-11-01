#include <iostream>

using namespace std;

class Solution{
public:
	int convert(int input){
		int base9num = base10To9(input);
		long long mask = 1;
		int tmp = base9num;
		while(tmp){
			int lastDigit = tmp % 10;
			if(lastDigit >= 4) base9num += mask;
			mask *= 10;
			tmp /= 10;
		}
		return base9num;
	}

	int base10To9(int num){
		int res = 0;
		long long mask = 1;
		while(num){
			//cout << num << mask << endl;
			res = res + (num % 9) * mask;
			mask *= 10;
			num /= 9;
		}
		return res;
	}
};

int main(){
	Solution T;
	for(int i = 0; i <= 1000; i++)
		cout << i << " -> " << T.convert(i) << endl;
	return 0;
}