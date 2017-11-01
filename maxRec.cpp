#include<iostream>
#include<stack>
#include<vector>

using namespace std;

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size(), maxRec = 0;
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

private:
    int helper(vector<int> height){
        int maxTmp = 0;
        stack<int> stk;
        for(int i = 0; i < height.size(); i++){
            if(stk.empty() || height[i] >= height[stk.top()]){
                stk.push(i);
            }
            else{
                int width = height[stk.top()];
                stk.pop();
                int height = stk.empty() ? i : i - 1 - stk.top();
                maxTmp = max(maxTmp, width*height);
                i--;
            }
        }
        return maxTmp;
    }
};

int main(){
	Solution T;
	vector<vector<char>> matrix = {{'1','0','1','1','0'},{'1','0','1','1','1'},{'1','1','1','1','1'},{'1','0','1','1','0'}};
	int res = T.maximalRectangle(matrix);
	cout << res << endl;
	return 0;
}