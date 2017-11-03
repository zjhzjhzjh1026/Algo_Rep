#include<iostream>
#include<unordered_map>
#include<sstream>
#include<queue>

using namespace std;


class Solution{
public:
	void parse(vector<string>& tt){
		for(auto str : tt){
			stringstream ss(str);
			vector<string> bin(4);
			for(int i = 0; i < 4; i++){
				ss >> bin[i];
			}
			adj[bin[1]].push_back(make_pair(bin[0],make_pair(stoi(bin[2]), stoi(bin[3]))));
		}
	}

	int findEarliest(string start, string end){
		auto comp = [](const pair<string, int> A, const pair<string, int> B){return A.second < B.second;};
		priority_queue< pair<string, int>, vector<pair<string, int>>, decltype(comp)> pq(comp);
		unordered_map<string, int> earlyTime;
		for(auto elem : adj[end]){
			pq.push(make_pair(elem.first, elem.second.first));
		}
		while(!pq.empty()){
			auto front = pq.top();
			pq.pop();
			earlyTime[front.first] = front.second;
			for(auto elem : adj[front]){
				if(elem.second.second <= front.second){
					pq.push(make_pair(elem.first, elem.second.first));
					if(elem.first == start)
						return elem.second.first;
				}
			}
		}
		return -1;
	}

private:
	unordered_map<string, vector<pair<string, pair<int, int>>>> adj;
};

int main(){
	Solution T;
	vector<string> timetable = {"A B 1000 1050", "B C 1100 1230", "A C 1130 1250"};
	T.parse(timetable);
	int res = T.findEarliest("A", "C");
	cout << res << endl;
	return 0;
}