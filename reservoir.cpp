#include<iostream>
#include<vector>
#include<time.h>

using namespace std;

class Solution{
public:
	vector<int> k_elements(vector<int> stream, int k){
		vector<int> res(k);
		for(int i = 0; i < k; i++){  //Copy the first k elements
			res[i] = stream[i]; 
		}
		srand(time(NULL));
		for(int i = k; i < stream.size(); i++){
			int dice = rand() % (i + 1);
			if(dice < k){
				res[dice] = stream[i];
			}
		}
		return res;
	}
};

int main(){
	Solution T;
	vector<int> stream = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};
	vector<int> ans;
	ans = T.k_elements(stream, 5);
	for(auto p : ans)
		cout << p << endl;
	return 0;
}