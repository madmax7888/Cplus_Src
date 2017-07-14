
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
#include <boost/chrono/thread_clock.hpp>
#include <boost/algorithm/string.hpp>
#include <map>
#include <boost/date_time/posix_time/posix_time.hpp>
#include <boost/date_time/gregorian/greg_month.hpp>
#include <set>
#include <regex>
using namespace std;
using namespace boost::algorithm;
using namespace boost::posix_time;
//##############################################################################
const int LOOP = 10;
const int MIN = 100;
const int MAX = 400;
const int DELAY = 50;
#define compilex = 1
//##############################################################################
std::mutex MU1;
std::mutex MU2;
std::condition_variable COND;
std::deque<int> RANVAL;
std::deque<unsigned int> BLG;
//##############################################################################
bool TRULSE;
//##############################################################################
inline void NEWL()
{
	cout << endl << endl;
}
//##############################################################################
inline void space(int limit)
{
	int cntr;
	for (cntr = 0; cntr < limit; cntr++)
	{
		cout << endl;
	}
}
//##############################################################################
inline void marker(string s)
{
	cout << "-------------------- " << s << " --------------------" << endl;
}
//##############################################################################
struct SREC
{
	string name;
	int id;
	int grades;
};
//##############################################################################
auto PLUS = [](int x)
            {
				return x + 32;
            };
//##############################################################################
void prod_consume_thread(void);
void produce(void);
void consume(void);
int get_irandom(void);
void class_thread(void);
void run_cthread(KUPAL *CPTR);
void another_thread(void);
void shared_thread(string name, int index);
void thread1(void);
void thread2(void);
void run_vector(void);
void load_vector(std::vector<int> &ivec);
void read_vector(std::vector<int> &ivec);
void vector_pushback(std::vector<int> &ivec);
void run_deque(void);
void load_deck(std::deque<int> &cdeck);
void read_deck(std::deque<int> &cdeck);
void reload_deck(std::deque<int> &cdeck);
void run_pointer(void);
void load_ptr(int *ptr);
void read_ptr(int *ptr);
void run_struct(void);
void run_files(void);
void test_true(bool tf);
void append_file(fstream &ap, ifstream &rd);
void rd_append(string fname);
bool is_file_exist(const std::string& name);
bool is_file_exist2(std::string name);
void class_static(void);
void run_lambda(void);
void test_lambda(void);
void pass_string_ref(void);
void pass_ref(int * icopy, string *scopy);
int getMaxInt(vector<int>& v);
int getMinInt(vector<int>& v);
void run_stream(void);
void run_list(void);
void run_size(void);
template <typename tt>
int getsize(const tt &ivar);
void show_pointers_int(void);
void show_pointers_double(void);
void show_pointers_heap(void);
template<typename tz>
void display_arr(const tz *ptr);
void run_maps(void);
void run_set(void);
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//##############################################################################
int _tmain(int argc, _TCHAR* argv[])
{
	const ptime start = microsec_clock::local_time();
	SetConsoleTitle(TEXT("ALL_FEB21D"));
	int A, B;

	A = 0;
	B = 2;

	if (!(A))
	{
		cout << "Flag1" << endl;
	}
	else
	{
		cout << "Flag3333" << endl;
	}


	prod_consume_thread();
	class_thread();
	another_thread();
	run_vector();
	run_deque();
	pass_string_ref();
	run_pointer();
	run_struct();
	run_files();
	class_static();
	run_lambda();
	run_stream();
	run_list();
	run_size();
	show_pointers_int();
	show_pointers_double();
	show_pointers_heap();
	run_maps();
	run_set();
	NEWL();
	marker("");

	cout << "Methods of passing to a function by reference " << endl;
	cout << "Vectors ------> void load_vector(std::vector<int> &ivec);" << endl;
	cout << "deque --------> void load_deck(std::deque<int> &cdeck) " << endl;
	cout << "int arrays ---> void pass_array(int *arrnew, int limit)  to pass to a function " << endl;
	cout << "string  ------> void pass_ref(int *icopy, string *scopy)" << endl;
	cout << "fstream ------> void append_file(ifstream &rdptr, fstream &apptr) " << endl;
	cout << "Thread  ------> void funcf(Threadz *CPTR) - pass a pointer  --> Threadz *PTR1; " << endl;
	cout << "const to function --------> bool is_file_exist(const std::string& name)" << endl;
	NEWL();

	const ptime stop = microsec_clock::local_time();
	const time_duration elapsed = stop - start;
	cout << "Elapsed Time = "<< elapsed <<endl;

	system("pause");
  	return 0;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_set(void)
{
	int cntr;
	string stra;
	set<string> words;

	stra = "This is a sentence that is very sucky and yucky";
	smatch m;
	//regex e("\s*[[:w:]]+\s*", regex_constants::icase);
	regex e("\s*([[:w:]]+)\s*", regex_constants::icase);
	bool found = regex_search(stra, m, e);
	cout << "m.size = " << m.size() << endl;
	cout << m[0].str() << endl;
	cout << m[1].str() << endl;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_maps(void)
{
	NEWL();
	marker("maps");
	stringstream stm;
	string sval, stra;
	int ival;
	map<string, int> students;
	students["allen"] = 95;
	students["teddy"] = 89;
	students["axle"] = 93;

	stm << "Student1 = " << students["allen"] << endl;
	sval = stm.str();
	cout << sval << endl;
	stm.str("");
	map<string, int>::iterator iter = students.begin();
	while (iter != students.end())
	{
		sval = iter->first;
		ival = iter->second;
		iter++;
		stm << "First : " << sval << "   Second = " << ival << endl;
		stra = stm.str();
		cout << stra;
		stm.str("");
	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void show_pointers_int(void)
{
	NEWL();
	marker("Show address pointer of integer");
	int arr[5];
	int *ptr1;
	int cntr, rval, ilen;

	for (cntr = 0; cntr < 5; cntr++)
	{
		rval = get_irandom();
		arr[cntr] = rval;
	}

	ilen = sizeof(arr[0]);
	cout << "Array of int Size = " << ilen << endl;
	ptr1 = &arr[0];
	display_arr<int>(ptr1);
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void show_pointers_double(void)
{
	NEWL();
	marker("Show address pointer of float");
	double arr[5] = { 23.45, 13.67, 67.12, 98.345, 45.98};
	double *ptr1;
	int cntr, rval, ilen;


	ilen = sizeof(arr[0]);
	cout << "Array of int Size = " << ilen << endl;
	ptr1 = &arr[0];
	display_arr<double>(ptr1);
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void show_pointers_heap(void)
{
	NEWL();
	marker("Show address pointer in heap");
	int cntr, ilen;
	int *ptr3 = new int[5]; // need to initialize when not init to an array
	for (cntr = 0; cntr < 5; cntr++)
	{
		*(ptr3 + cntr) = cntr + 1;
	}
	ilen = sizeof(*(ptr3 + 0));
	cout << "Array of int Size = " << ilen << endl;
	display_arr<int>(ptr3);
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <typename tz>
void display_arr(const tz *ptr)
{
	int cntr, rval;
	int addr;
	stringstream stm;
	string sval;
	for (cntr = 0; cntr < 5; cntr++)
	{
		stm << "Address : " << (ptr + cntr) << "   Value = " << *(ptr + cntr);
		sval = stm.str();
		cout << sval << endl;
		stm.str("");
	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_size(void)
{
	int flen, ilen, slen, dlen, llen, clen, blen;
	int inum;
	float fnum;
	double dnum;
	long lnum;
	char cnum;
	short snum;
	byte bnum;

	stringstream stm;
	string stra;

	NEWL();
	marker("sizeof");
	inum = 1;
	fnum = 22.30;
	dnum = 234.44;
	lnum = 4565;
	cnum = 'f';
	snum = 0xffee;
	bnum = 0xfe;

	ilen = getsize<int>(inum);
	flen = getsize<float>(fnum);
	dlen = getsize<double>(dnum);
	llen = getsize<long>(dnum);
	clen = getsize<char>(cnum); 
	slen = getsize<short>(snum);
	blen = getsize<byte>(bnum);

	stm << "ilen = " << ilen << "\nflen = " << flen << "\ndlen = " << dlen
		<< "\nllen = " << llen << "\nclen = " << clen << "\nslen = " << slen 
		<< "\nblen = " << blen << endl;

	stra = stm.str();
	cout << stra;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
template <typename tt>
int getsize(const tt &ivar)
{
	int rslt;
	rslt = sizeof(ivar);
	return rslt;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_list(void)
{
	NEWL();
	marker("list");
	list<string> names;
	string xname;
	names.push_back("allen");
	names.push_back("teddy");
	names.push_back("mom");
	names.push_back("axle");
	list<string>::iterator iter = names.begin();
	while (iter != names.end())
	{
		xname = *iter;
		cout << xname << endl;
		iter++;
	}

	cout << "\n\nreverse list" << endl;
	names.reverse();
	list<string>::iterator iter1 = names.begin();
	while (iter1 != names.end())
	{
		xname = *iter1;
		cout << xname << endl;
		iter1++;
	}

	cout << "\n\nsort list" << endl;
	names.sort();
	list<string>::iterator iter2 = names.begin();
	while (iter2 != names.end())
	{
		xname = *iter2;
		cout << xname << endl;
		iter2++;
	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_stream(void)
{
	NEWL();
	marker("stringstream");
	string sgrades = "89.654 90.234 80.2345 70.76 76.347";
	stringstream stm, stmx;
	int igrade, total, cntr;
	total = 0;
	stm << sgrades;
	for (cntr = 0; cntr < 5; cntr++)
	{
		stm >> igrade;   // convert to integer
		total += igrade;
	}
	float ave = float(total / 5);
	stmx << "The Average = "  << ave;
	cout << stmx.str() << endl;
	cout << stm.str() << endl;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_lambda(void)
{
	NEWL();
	auto x = PLUS(2);
	cout << "value of lambda = " << x << endl;
	test_lambda();
}
//##############################################################################
void test_lambda(void)
{
	int newval;
	newval = 3;

	auto kups = [newval](int x)
	{
		return x + newval;
	};

	auto burat = kups(3);
	cout << "newval = " << burat << endl;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void class_static(void)
{
	COUNCIL OBJ1("teddy", 0367, 2);
	COUNCIL OBJ2("ringo", 3147, 1);
	COUNCIL *PTR1, *PTR2;
	COUNCIL *PTR3 = new COUNCIL("Paul", 8618, 3); // Create a pointer to class in Heap
	space(2);
	PTR1 = &OBJ1;
	PTR2 = &OBJ2;

	PTR1->display();
	PTR1->disp();
	space(2);
	PTR2->display();
	PTR2->disp();
	space(2);
	PTR3->display();
	PTR3->disp();
	space(2);
	COUNCIL::disp();
	PTR3 = NULL;
	delete PTR3;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_files(void)
{
	bool tf;
	string wrfile, rdfile, apfile, strdata, newstr, appx;
	int arrnum[LOOP] = {10, 11, 12, 13, 14, 15, 16, 17, 18, 19};
	int rval, cntr;
	std::stringstream buffer;
	wrfile = "srcfile.txt";
	rdfile = "srcfile.txt";
	apfile = "appfile.txt";
	appx = "xfile.txt";

	NEWL();
	tf = is_file_exist("kupal.txt");
	tf = is_file_exist("appfile.txt");
	tf = is_file_exist(apfile);

	ifstream rd(rdfile, ios::in);
	if (rd.is_open() == true)
	{
		rd.close();
		remove("srcfile.txt");
	}

	ofstream wr(wrfile, ios::out);
	tf = wr.is_open();
	test_true(tf);
	for (cntr = 0; cntr < LOOP; cntr++)
	{
		rval = arrnum[cntr];
		newstr = to_string(rval);
		wr << newstr << endl;
	}
	wr.close();

	fstream ap(apfile, ios::out | ios::app);
	tf = ap.is_open();
	test_true(tf);

	ifstream rd2(rdfile, ios::in);
	tf = rd2.is_open();
	test_true(tf);
	append_file(ap, rd2);
	rd2.close();
	ap.close();
	rd_append(apfile);
}
//##############################################################################
void append_file(fstream &ap, ifstream &rd)
{
	string strdata, stra;
	stra = strdata = "";
	while (rd.good())
	{
		getline(rd, stra);
		stra.append("\n");
		strdata = strdata + stra;
	}
	ap << strdata;
	ap << "new data\n";
}
//##############################################################################
void rd_append(string fname)
{
	bool tf;
	std::stringstream buffer;
	string newstr;
	int len;

	ifstream rd(fname, ios::in);
	tf = rd.is_open();
	test_true(tf);
	cout << "reading entire file" << endl;
	buffer << rd.rdbuf();
	newstr = buffer.str();
	cout << newstr;
	rd.close();
	len = newstr.length();
	if (len > 1000)
	{
		remove("appfile.txt");
		cout << "remove appfile.txt" << endl;
	}
}
//##############################################################################
void test_true(bool tf)
{
	assert(tf == true);
	cout << "Files Test : OK !!!" << endl;
}

void test_false(bool tf)
{
	assert(tf == false);
	cout << "Files Test : OK !!!" << endl;
}
//&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&&
bool is_file_exist(const string &name)
{
	ifstream infile(name);
	return infile.good();
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_struct(void)
{
	SREC OBJ2;
	SREC *sptr1 = new SREC();
	SREC *sptr2 = new SREC();

	OBJ2.name = "teddy aquino";
	OBJ2.id = 23;
	OBJ2.grades = 76;
	sptr1 = &OBJ2;

	NEWL();
	cout << "Name : " << sptr1->name << endl;
	cout << "ID : " << sptr1->id << endl;
	cout << "Grades : " << sptr1->grades << endl;

	sptr2->name = "ringo";
	sptr2->id = 245;
	sptr2->grades = 90;

	NEWL();
	cout << "Name : " << sptr2->name << endl;
	cout << "ID : " << sptr2->id << endl;
	cout << "Grades : " << sptr2->grades << endl;

	sptr1 = sptr2 = NULL;
	delete sptr1;
	delete sptr2;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void pass_string_ref(void)
{
	string sorig;
	int iorig;
	NEWL();
	iorig = 29;
	sorig = "teddy aquino";
	cout << "orig name : " << sorig << "  orig value : " << iorig << endl;
	pass_ref(&iorig, &sorig);
	cout << "copy name : " << sorig << "  copy value : " << iorig << endl;

}
//******************************************************************************
void pass_ref(int * icopy, string * scopy)
{
	*scopy = "ringo starr";
	*icopy = 43;
	cout << *scopy << endl;
}

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_pointer(void)
{
	int arrnum[LOOP];
	int *ptr1 = new int[];
	int *ptr2 = new int[];
	int *ptr3 = new int[10]; // need to initialize when not init to an array

	NEWL();
	ptr2 = &arrnum[0];
	*ptr2 = 10;

	ptr2++;
	*ptr2 = 11;

	ptr2 = (arrnum + 2);
	*ptr2 = 12;

	ptr2 = &arrnum[3];
	*ptr2 = 13;

	ptr2 = &arrnum[0];
	ptr2[4] = 14;

	ptr2 = &arrnum[0];
	*(ptr2 + 5) = 15;

	space(2);
	ptr2 = &arrnum[0];
	read_ptr(ptr2); 
	Sleep(20);

	space(2);
	ptr1 = &arrnum[0];
	load_ptr(ptr1);
	read_ptr(ptr1);
	Sleep(200);

	space(2);
	cout << "ptr3 not initialized" << endl;
	load_ptr(ptr3);
	read_ptr(ptr3);
	Sleep(20);

	delete []ptr3;
	ptr3 = nullptr;


}
//##############################################################################
void load_ptr(int *ptr)
{
	int cntr, rval;
	try
	{
		cout << "Load ptr to array " << endl;
		for (cntr = 0; cntr < LOOP; cntr++)
		{
			rval = get_irandom();
			*(ptr + cntr) = rval;
			cout << "*(ptr + cntr) = " << rval << endl;
		}
	}
	catch (exception& e)
	{
		cout << "Error loading to ptr : " << e.what() << endl;
	}
}
//##############################################################################
void read_ptr(int *ptr)
{
	int cntr, rval;
	try
	{
		cout << "read back ptr" << endl;
		//for (cntr = 0; cntr < LOOP; cntr++)
		//{
		//	rval = *(ptr + cntr);
		//	cout << rval << " = *(ptr + cntr)" << endl;
		//}
		for (cntr = 0; cntr < LOOP; cntr++)
		{
			rval = ptr[cntr];
			cout << rval << " = *(ptr + cntr)" << endl;
		}
	}
	catch (exception& e)
	{
		cout << "error reading ptr : " << e.what() << endl;
	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_deque(void)
{
	NEWL();
	cout << "run deque" << endl;
	space(1);
	std::deque<int> mdeck;
	load_deck(mdeck);
	read_deck(mdeck);
	reload_deck(mdeck);
	read_deck(mdeck);
	Sleep(20);
}
//##############################################################################
void load_deck(std::deque<int> &cdeck)
{
	int cntr, rval;
	cout << "Write to deque" << endl;
	for (cntr = 0; cntr < LOOP; cntr++)
	{
		rval = get_irandom();
		cdeck.push_back(rval);
		cout << rval << " = cdeck.push_back()  @ index : " << cntr << endl;
	}
}
//##############################################################################
void read_deck(std::deque<int> &cdeck)
{
	int dsize, cntr, rval;
	dsize = cdeck.size();
	try
	{
		cout << "Read back deque" << endl;
		for (cntr = 0; cntr < dsize; cntr++)
		{
			rval = cdeck.front();
			cdeck.pop_front();
			cout << rval << " = cdeck.front()  @ index : " << cntr << endl;
		}
	}
	catch (exception& e)
	{
		cout << "Error reading deque = " << e.what() << endl;
	}
}
//##############################################################################
void reload_deck(std::deque<int> &cdeck)
{
	int rval, cntr;
	cdeck.resize(LOOP);
	try
	{
		space(2);
		cout << "Reload deque using .at(rval) " << endl;
		for (cntr = 0; cntr < LOOP; cntr++)
		{
			rval = get_irandom();
			cdeck.at(cntr) = rval;
			cout << "deck.at(" << cntr << ") = " << rval << endl;
		}
	}
	catch (exception& e)
	{
		cout << "error in reload_deck : " << e.what() << endl;
	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void run_vector(void)
{
	int index, rval, vmin, vmax;
	std::vector<int> mvector;
	load_vector(mvector);
	read_vector(mvector);
	Sleep(DELAY);
	vector_pushback(mvector);
	read_vector(mvector);
	vmax = getMaxInt(mvector);
	vmin = getMinInt(mvector);
	NEWL();
	cout << "Max Int = " << vmax << "   Min Int = " << vmin << endl;
	cout << "Done Vector" << endl;
	Sleep(DELAY);
}
//##############################################################################
void vector_pushback(std::vector<int> &ivec)
{
	int cntr, rval, icap, isize;
	try
	{
		ivec.clear();
		ivec.reserve(LOOP + 10);
		NEWL();
		cout << "Using ivec.push_back(rval)" << endl;
		cout << "Do not use ivec.resize(LOOP) when using ivec.push_back(rval)" << endl;
		space(1);
		icap = ivec.capacity();
		isize = ivec.size();
		cout << "Vector Capacity = " << icap << endl;
		cout << "Vector Size = " << isize << endl;
		ivec.begin();
		for (cntr = 0; cntr < LOOP; cntr++)
		{
			rval = get_irandom();
			ivec.push_back(rval);
			cout << "ivec.push_back(rval) = " << rval << endl;
		}
	}
	catch (exception& e)
	{
		cout << e.what() << endl;
	}

}
//##############################################################################
void load_vector(std::vector<int> &ivec)
{
	int isize, icap, rval, cntr;
	ivec.reserve(LOOP + 5);
	ivec.resize(LOOP);
	icap = ivec.capacity();
	isize = ivec.size();
	NEWL();
	cout << "Vector Capacity = " << icap << endl;
	cout << "Vector Size = " << isize << endl;
	try
	{
		for (cntr = 0; cntr < LOOP; cntr++)
		{
			rval = get_irandom();
			ivec.at(cntr) = rval;
			cout << "ivec.at(" << cntr << ") = " << rval << endl;
		}
	}
	catch (exception& e)
	{
		cout << "Error in Vector = " << e.what();
	}
}
//##############################################################################
void read_vector(std::vector<int> &ivec)
{
	int cntr, rval;
	try
	{
		for (cntr = 0; cntr < LOOP; cntr++)
		{
			rval = ivec.at(cntr);
			cout << rval << " = ivec.at(" << cntr << ")" << endl;
		}
	}
	catch (exception& e)
	{
		cout << "fail read = " << e.what() << endl;
	}
}
//##############################################################################
int getMaxInt(vector<int>& v) 
{
	return *max_element(v.begin(), v.end());
}
// ##############################################################################
int getMinInt(vector<int>& v) 
{
	return *min_element(v.begin(), v.end());
}

//##############################################################################
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void another_thread(void)
{
	int cntr;
	std::thread t1(thread1);
	std::thread t2(thread2);
	for (cntr = 0; cntr < LOOP; cntr++)
	{
		shared_thread("main   ", cntr);
	}
	t1.join();
	t2.join();
	cout << "Threading between 3 process - Done" << endl;
	NEWL();
	Sleep(DELAY);
}
//##############################################################################
void shared_thread(string name, int index)
{
	std::unique_lock<mutex> lockx(MU2, defer_lock);
	lockx.lock();
	cout << "Thread Name : " << name << "     Index = " << index << endl;
	Sleep(10);
	lockx.unlock();
	std::this_thread::sleep_for(chrono::milliseconds(50));
}
//##############################################################################
void thread1(void)
{
	int cntr;
	for (cntr = 0; cntr < LOOP; cntr++)
	{
		shared_thread("thread1", cntr);
	}
}
//##############################################################################
void thread2(void)
{
	int cntr;
	for (cntr = 0; cntr < LOOP; cntr++)
	{
		shared_thread("thread2", cntr);
	}
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void class_thread(void)
{
	int cntr;
	KUPAL OBJ("Teddya", 1);
	KUPAL *CPTR;
	CPTR = &OBJ;
	std::thread cthread(run_cthread, CPTR);
	for (cntr = 0; cntr < LOOP; cntr++)
	{
		CPTR->shared_thread("Main   ", cntr);
	}
	cthread.join();
	cout << "Class Thread - Done ";
	NEWL();
	Sleep(DELAY);
}
//##############################################################################
void run_cthread(KUPAL *CPTR)
{
	int cntr;

	for (cntr = 0; cntr < LOOP; cntr++)
	{
		CPTR->shared_thread("cthread", cntr);
	}
}
//##############################################################################


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
void prod_consume_thread(void)
{
	std::thread tprod(produce);
	std::thread tcons(consume);
	tprod.join();
	tcons.join();
	cout << "Produce and Consume Thread - Done";
	NEWL();
	Sleep(DELAY);
}
//##############################################################################
void produce(void)
{
	int rval;
	unsigned int cntr;
	TRULSE = false;
	cntr = LOOP;
	try
	{
		while (cntr > 0)
		{
			std::unique_lock<mutex> locker(MU1);
			rval = get_irandom();
			RANVAL.push_front(rval);
			BLG.push_front(cntr);
			TRULSE = true;
			locker.unlock();
			COND.notify_one();
			std::this_thread::sleep_for(chrono::milliseconds(50));
			cntr--;
		}
	}
	catch (exception& e)
	{
		cout << "Exception = " << e.what() << endl;
	}
}
//##############################################################################
void consume(void)
{
	int rval;
	unsigned int cntr;
	cntr = 99;
	try
	{
		while (cntr != 1)
		{
			std::unique_lock<mutex> locker(MU1); 
			COND.wait(locker, [] {return TRULSE == true;  });
			rval = RANVAL.back();
			cntr = BLG.back();
			cout << "RANVAL = " << rval << "    Index = " << cntr << endl;
			TRULSE = false;
			RANVAL.pop_back();
			BLG.pop_back();
			locker.unlock();
			std::this_thread::sleep_for(chrono::milliseconds(50));
		}
	}
	catch (exception& e)
	{
		cout << "Error in consume : " << e.what() << endl;
	}
	cout << "Done Produce and Consume Thread " << endl;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@


//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
int get_irandom(void)
{
	int rval, min, max;
	min = MIN;
	max = MAX;
	rval = min + (rand() % (int)(max - min + 1));
	return rval;
}
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@
//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@

//@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@