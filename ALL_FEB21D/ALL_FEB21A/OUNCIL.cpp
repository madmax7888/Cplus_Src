#include "stdafx.h"
#include "stdafx.h"
#include <iostream>
#include <Windows.h>
#include <string>
#include <deque>
#include <condition_variable>
#include <thread>
#include <exception>
#include <vector>
#include <fstream>
#include "KUPAL.h"
#include <assert.h>
#include <sstream>
#include "OUNCIL.h"


COUNCIL::COUNCIL(string cname, int cid, int cntr)
{
	name = cname;
	id = cid;
	count = count + cntr;
	cout << "Object :" << name << "    Count = " << count << endl;
}

void COUNCIL::display(void)
{
	cout << "Name : " << name << "\t" << "ID : " << id << "\t" << "Count = " << count << endl;
}

void COUNCIL::disp(void)
{
	cout << "Static method only accepts static variable" << endl;
	cout << "Static Method - Count = " << count << endl;
}

int COUNCIL::count = 0;