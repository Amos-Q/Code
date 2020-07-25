#include <iostream>
#include <unordered_set>
#include <unordered_map>
#include <map>
#include <set>
#include <string>
using namespace std;

#include <time.h>

void test_unordered_map_set()
{
	unordered_set<int> us; // Java HashSet
	us.insert(4);
	us.insert(2);
	us.insert(1);
	us.insert(5);
	us.insert(6);
	us.insert(2);
	us.insert(2);

	// È¥ÖØ
	unordered_set<int>::iterator it = us.begin();
	while (it != us.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	set<int> s;  // Java TreeSet
	s.insert(4);
	s.insert(2);
	s.insert(1);
	s.insert(5);
	s.insert(6);
	s.insert(2);
	s.insert(2);

	// ÅÅĞò+È¥ÖØ
	set<int>::iterator sit = s.begin();
	while (sit != s.end())
	{
		cout << *sit << " ";
		++sit;
	}
	cout << endl;

	unordered_map<string, string> dict;
	//map<string, string> dict;
	dict.insert(make_pair("sort", "ÅÅĞò"));
	dict["string"] = "×Ö·û´®";
	dict.insert(make_pair("left", "×ó±ß"));
	unordered_map<string, string>::iterator dit = dict.begin();
	//map<string, string>::iterator dit = dict.begin();
	while (dit != dict.end())
	{
		cout << dit->first << ":" << dit->second << endl;
		++dit;
	}
	cout << endl;
}

void test_op()
{
	unordered_set<int> us;
	set<int> s;

	const int n = 1000000;
	vector<int> v;
	v.reserve(n);
	srand(time(0));
	for (size_t i = 0; i < n; ++i)
	{
		v.push_back(rand());
	}

	size_t begin2 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.insert(v[i]);
	}
	size_t end2 = clock();
	cout << "set insert:" << end2 - begin2 << endl;


	size_t begin1 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.insert(v[i]);
	}
	size_t end1 = clock();
	cout << "unorded_set insert:" << end1 - begin1 << endl;


	size_t begin3 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.find(v[i]);
	}
	size_t end3 = clock();
	cout << "set find:" << end3 - begin3 << endl;


	size_t begin4 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.find(v[i]);
	}
	size_t end4 = clock();
	cout << "unorded_set find:" << end4 - begin4 << endl;


	size_t begin5 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		s.erase(v[i]);
	}
	size_t end5 = clock();
	cout << "set erase:" << end5 - begin5 << endl;


	size_t begin6 = clock();
	for (size_t i = 0; i < n; ++i)
	{
		us.erase(v[i]);
	}
	size_t end6 = clock();
	cout << "unorded_set erase:" << end6 - begin6 << endl;
}
#include "HashTable.h"
#include "MyUnorderedSet.h"
#include "MyUnorderedMap.h"

int main()
{
	//test_unordered_map_set();
	//test_op();

	//OPEON_HASH::TestHashTable1();
	//OPEON_HASH::TestHashTable2();
	bit::test_unordered_set();
	//bit::test_unordered_map();

	return 0;
}