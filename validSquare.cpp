#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

class Solution{
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        unordered_set<int> s({d(p1,p2), d(p1,p3), d(p1,p4), d(p2,p3), d(p2,p4), d(p3,p4)});
        return !s.count(0) && s.size() == 2;
    }

    bool validSquareBF(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4){
    	vector<vector<int>> comb({p1,p2,p3,p4});
    	return checkPerm(comb, 0);
    }

private:
    int d(vector<int>& a, vector<int>& b){
        return (a[0]-b[0]) * (a[0]-b[0]) + (a[1]-b[1]) * (a[1]-b[1]);
    }

    bool checkPerm(vector<vector<int>>& comb, int level){
    	if(level == 4){
    		return check(comb);
    	}
    	else{
    		bool res = false;
    		for(int i = level; i < 4; i++){
    			swap(comb[i], comb[level]);
    			res |= checkPerm(comb, level + 1);
    			swap(comb[i], comb[level]);
    		}
    		return res;
    	}
    	return true;
    }

    bool check(vector<vector<int>>& comb){
    	auto p1 = comb[0], p2 = comb[1], p3 = comb[2], p4 = comb[3];
    	return d(p1, p2) > 0 && d(p1, p2) == d(p2, p3) && d(p2, p3) == d(p3, p4) && d(p3, p4) == d(p4, p1) && d(p1, p3) == d(p2, p4);
    }
};

int main(){
	vector<int> p1({0,0}), p2({0,1}), p3({1,0}), p4({1,1});
	Solution T;
	bool res = T.validSquareBF(p1, p2, p3, p4);
	cout << "OUTPUT: " << res << endl;
	return 0;
}