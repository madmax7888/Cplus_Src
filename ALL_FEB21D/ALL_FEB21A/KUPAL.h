#pragma once
#include <string>
#include <thread>
#include <mutex>
using namespace std;

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
class KUPAL
{
	string tname1,  tnmae2;
	int index;
	std::mutex CMU;

public:
	KUPAL(string sname, int num);
	void shared_thread(string sname, int num);
};

