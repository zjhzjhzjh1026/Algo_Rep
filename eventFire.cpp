#include <iostream>
#include <queue>
#include <thread>

using namespace std;

class CallBack{
public:
	string name;
	CallBack(){}

	CallBack(string tmp){
		name = tmp;
	}

	void call(){
		cout << "CallBack Event " << name << " is running now..." << endl; 
	}
	
};

class EventFire{
public:
	EventFire(){
		isFired = false;
	}

	void reg_cb(CallBack cb){
		m.lock();
		// cout << boolalpha << isFired << endl;
		if(isFired){
			m.unlock();
			cb.call();
		}
		else{
			q.push(cb);
			m.unlock();
		}
	}

	void event_fired(){
		m.lock();
		isFired = true;
		cout << "FIRE!!" << endl;
		while(!q.empty()){
			auto t = q.front();
			q.pop();
			m.unlock();
			t.call();
			m.lock();
		}
		m.unlock();
	}

private:
	queue<CallBack> q;
	bool isFired;
	mutex m;
};

int main(){
	thread threads[4];
	CallBack s1("s1"), s2("s2"), s3("s3");
	EventFire T;
	threads[0] = thread([&T, &s1]{
		T.reg_cb(s1);
		// cout << "thread 0 runs.." << endl;
	});
	threads[1] = thread([&T, &s2]{
		T.reg_cb(s2);
		// cout << "thread 1 runs.." << endl;
	});
	// T.reg_cb(s1);
	// T.reg_cb(s2);
	threads[2] = thread([&T]{
		T.event_fired();
		// cout << "thread 2 runs.." << endl;
	});
	
	cout << endl;

	threads[3] = thread([&T, &s3]{
		T.reg_cb(s3);
		// cout << "thread 3 runs.." << endl;
	});
	for(int i = 0; i < 4; i++)  threads[i].join();
	return 0;
}