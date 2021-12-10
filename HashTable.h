#pragma once
#include <iostream>
#include <string>
using namespace std;
struct List
	{
		string key;
		string element;
		List* next=nullptr;
		bool state=false;
		bool duplicate=false;
	};

class HashT
{	
	double reHashIndex = 0.75;
	int size = 0;
	int capacity = 8;
	List** hashArr;
public:
	HashT();
	bool Add(string key, string value, int* table);
	string Search(string key, int* table);
	int HashF(string key, int* table);
	void Delete(string key, int* table);
	void ReHash(int* table);
	void PrintMap();
};