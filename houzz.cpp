#include<iostream>
#include<vector>
#include<stack>
#include<sstream>
#include<string>
#include<math.h>

using namespace std;

class Solution{
public:
	vector<int> prime(int m){
		vector<int> res;
		for(int i = 2; i <= m; i++){
			while(m % i == 0){
				res.push_back(i);
				m /= i; 
			}
		}
		for(int i = 0; i < res.size(); i++){
			int cnt = 0, j = i;
			while(j < res.size() && res[i] == res[j]){
				j++;
				cnt++;
			}
			cout << res[i] << "^" << cnt << endl;
			i = j - 1;
		}
		return res;
	}

	vector<int> randKElement(vector<int> stream, int k){
		int len = stream.size();
		vector<int> res(k);
		for(int i = 0; i < k; i++){
			res[i] = stream[i];
		}
		srand(time(NULL));
		for(int i = k; i < len; i++){
			int dice = rand()%(i+1);
			if(dice < k){
				res[dice] = stream[i];
			}
		}
		for(auto p : res)
			cout << p << " ";
		cout << endl;
		return res;
	}

	int base10ToBase9(int num){
		int res = 0;
		long long mask = 1;
		while(num){
			res += num % 9 * mask;
			num /= 9;
			mask *= 10;
		}
		return res;
	}

	int convert(int num){
		int base9num = base10ToBase9(num);
		long long mask = 1;
		int res = base9num;
		while(base9num){
			int lastDigit = base9num % 10;
			if(lastDigit >= 4)  res += mask;
			mask *= 10;
			base9num /= 10;
		}
		return res;
	}

	int maximalRectangle(vector<vector<char>>& matrix){
		int maxRec = 0;
		int m = matrix.size();
		if(!m)  return 0;
		int n = matrix[0].size();
		vector<int> height(n + 1, 0);
		for(int i = 0; i < m; i++){
			for(int j = 0; j < n; j++){
				if(matrix[i][j] == '0')
					height[j] = 0;
				else
					height[j]++;
			}
			maxRec = max(maxRec, helper(height));
		}
		return maxRec;
	}

	int helper(vector<int>& height){
		int maxTmp = 0;
		stack<int> stk;
		for(int i = 0; i < height.size(); i++){
			if(stk.empty() || height[i] >= height[stk.top()])  stk.push(i);
			else{
				int width = height[stk.top()];
				stk.pop();
				int length = stk.empty() ? i : i - stk.top() - 1;
				maxTmp = max(maxTmp, width * length);
				i--;
			}
		}
		return maxTmp;
	}

	string addDay(string date){
		vector<int> nums(3);
		istringstream ss(date);
		string tmp;
		int i = 0;
		while(ss >> tmp){
			nums[i] = stoi(tmp);
			i++;
		}
		vector<int> dayOfMonth = {31,28,31,30,31,30,31,31,30,31,30,31};
		if((nums[0] % 4 == 0 && nums[0] % 100 != 0) || nums[0] % 400 == 0){
			dayOfMonth[1] = 29;
		}
		else 
			dayOfMonth[1] = 28;
	 	nums[2]++;
	 	if(nums[2] > dayOfMonth[nums[1] - 1]){
	 		nums[1]++;
	 		nums[2] = 1;
	 		if(nums[1] > 12){
	 			nums[1] = 1;
	 			nums[0]++;
	 		}
	 	}
 		return to_string(nums[0]) + " " + to_string(nums[1]) + " " + to_string(nums[2]);
 	}

 	double convert(string s){
 		int i = 0;
 		double res = 0;
 		while(s[i] == ' ') i++;
 		bool positive = true;
 		if(s[i] == '+' || s[i] == '-'){
 			if(s[i] == '-')  positive = !positive;
 			i++;
 		}
 		int num_cnt = 0, dot_cnt = 0, order = 0;
 		while(s[i] <= '9' && s[i] >= '0' || s[i] == '.'){
 			if(s[i] == '.'){
 				dot_cnt++;
 				order = 0;
 			}
 			else{
 				num_cnt++;
 				res = res * 10 + (s[i] - '0');
 				order++;
 			}
 			i++;
 		}
 		if(num_cnt < 1 || dot_cnt > 1)  throw "Exception";
 		while(s[i] == ' ') i++;
 		if(s[i] != '\0')  throw "Exception";
 		res /= pow(10, order);
 		res = positive ? res : -res;
 		return res;
 	}
};

int main(){
	Solution T;
	// //randomly pick k elems
	// vector<int> stream = {1,2,3,4,5,6,7,8,9};
	// T.randKElement(stream, 4);

	// //Get the prime factors
	// T.prime(1024);

	// Number to Chinese Number
	// for(int i = 0; i < 1000; i++)
	// 	cout << i << "->" << T.convert(i) << endl;

	//Maximal Rectangle
	// vector<vector<char>> matrix = {{'1','0','1','1','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','1','1','0'}};
	// int res = T.maximalRectangle(matrix);
	// cout << res << endl;

	// //Add day
	// cout << T.addDay("1900 2 28") << endl;

	double res = T.convert("-1234.59");
	cout << res << endl;

	
	return 0;
}