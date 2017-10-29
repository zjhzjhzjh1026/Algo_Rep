#include<iostream>
#include<string>
#include<math.h>

using namespace std;

class Solution{
public:
	double str2flt(string s){
		double res = 0;
		int i = 0;
		while(s[i] == ' ')  i++;
		bool pos = true;
		if(s[i] == '+' || s[i] == '-'){
			if(s[i] == '-')  pos = false;
			i++;
		}
		int dot_cnt = 0, num_cnt = 0, shift = 0;
		while(s[i] <= '9' && s[i] >= '0' || s[i] == '.'){
			if(s[i] == '.'){
				dot_cnt++;
				shift = 0;
			}else{
				int tmp = s[i] - '0';
				res = res*10+tmp;
				num_cnt++;
				shift++;
			}
			i++;
		}
		if(dot_cnt > 1 || num_cnt < 1)  throw "Exception";
		while(s[i] == ' ') i++;
		if(s[i] != '\0')  throw "Exception";
		res /= pow(10, shift);
		res = pos ? res : -res;
		return res;
	}
};

int main(){
	Solution T;
	double res = T.str2flt("-1234.59");
	cout << res << endl;
	return 0;
}