#include<iostream>
#include<vector>

using namespace std;

class Solution{
public:
	vector<int> primeSet(int num){
		vector<int> res;  //在这里加unordered_map记录prime factor出现次数
		for(int i = 2; i <= num; i++){
			while(num % i == 0){
				res.push_back(i);
				num /= i;
			}
		}
		return res;
	}
};

int main(){
	Solution T;
	vector<int> ans;
	int i;
	while(1){
		cin >> i;
		ans = T.primeSet(i);
		// for(auto elem : ans)
		// 	cout << elem << endl;
		for(int i = 0; i < ans.size();){
			int elem = ans[i];
			int cnt = 0;
			while(i < ans.size() && ans[i] == elem){
				i++;
				cnt++;
			}
			cout << elem << "^" << cnt << endl;
		}
	}
	return 0;
}