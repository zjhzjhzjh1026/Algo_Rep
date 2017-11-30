#include<iostream>
#include<vector>
#include<sstream>

using namespace std;

class Solution{
public:
	string addDay(string date){
		vector<int> nums;
		istringstream ss(date);
		string tmp;
		while(ss >> tmp){
			nums.push_back(stoi(tmp));
		}
		int year = nums[0], month = nums[1], day = nums[2];
		vector<int> dayOfMonth = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
		if((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
			dayOfMonth[1]++;
		day++;
		if(day > dayOfMonth[month - 1]){
			month++;
			day = 1;
			if(month > 12){
				year++;
				month = 1;
			}
		}
		return to_string(year) + " " + to_string(month) + " " + to_string(day);
	}
	
};

int main()
{
	/* code */
	Solution T;
	cout << T.addDay("2000 12 31") << endl;
	return 0;
}