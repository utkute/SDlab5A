#include "HashTable.h"

bool HashT::Add(string key, string value, int* table)
{
	if (double(size/capacity)>reHashIndex)
	{
		ReHash(table);
	}
	int hash = HashF(key, table);	
	List* temp = new List;
	if (hashArr[hash]==nullptr or !hashArr[hash]->state)
	{
		temp->element = value;
		temp->key = key;
		temp->state = true;
		hashArr[hash] = temp;
	}
	else
	{
		List* lastIn = new List;
		lastIn = hashArr[hash];
		while (lastIn->next != nullptr)
		{
			if (lastIn->key == key && lastIn->element == value)
			{
				return false;
			}
			if (lastIn->key == key)
			{
				lastIn->duplicate = true;
				temp->duplicate = true;
			}
			lastIn = lastIn->next;
		}
		temp->element = value;
		temp->key = key;
		temp->state = true;
		lastIn->next = temp;
	}
	size++;
	return true;
}

HashT::HashT()
{
	int i;
	hashArr = new List * [capacity];
	for (i=0;i<capacity;i++)
	{
		hashArr[i] = nullptr;
	}
}

string HashT::Search(string key, int* table)
{
	string result;
	int hash = HashF(key, table);
	if (hashArr[hash] != nullptr) {
		if (hashArr[hash]->state)
		{
			List* temp = new List;
			temp = hashArr[hash];
			while (temp->next != nullptr)
			{
				if (temp->duplicate)
				{
					if (temp->key == key)
					{
						result += temp->element;
						result += ', ';
					}
				}
				else
				{
					if (temp->key == key)
					{
						result += temp->element;
						break;
					}
				}
				temp = temp->next;
			}
		}
	}
	else
	{
		result = "Wrong key";
	}
	return result;
}

int HashT::HashF(string key, int* table)
{
	int hash = key.length() % 256;
	int i;
	for (i = 0; i <= key.length(); i++)
	{
		hash = table[(hash + int(key[i])) % 256];
	}
	return hash;
}

void HashT::Delete(string key, int* table)
{
	int hash = HashF(key, table);
	List* temp = new List;
	temp = hashArr[hash];
	if (hashArr[hash] != nullptr) {
		if (hashArr[hash]->state)
		{
			while (temp->next != nullptr)
			{
				if (temp->duplicate)
				{
					if (temp->key == key)
					{
						temp->state = false;
						size--;
					}
				}
				else
				{
					if (temp->key == key)
					{
						temp->state = false;
						size--;
						break;
					}
				}
				temp = temp->next;
			}
		}
	}
}

void HashT::ReHash(int *table)
{
	int pastCapacity = capacity;
	capacity *= 2;
	int i;
	List** swaper;
	List** supArr = new List * [capacity];
	int* newtable = new int[capacity];
	for (i = 0; i < capacity; i++)
	{
		supArr[i] = nullptr;
		newtable[i] = rand() % capacity;
	}
	delete[] table;
	table = newtable;
	swaper = hashArr;
	hashArr = supArr;
	supArr = swaper;
	for (i = 0; i < pastCapacity; i++)
	{
		if (supArr[i] != nullptr) 
		{
			if (supArr[i]->state)
			{
				while (supArr[i]->next!=nullptr)
				{
					Add(supArr[i]->key, supArr[i]->element, table);
					supArr[i] = supArr[i]->next;
				}
				Add(supArr[i]->key, supArr[i]->element, table);
			}
		}
	}
	for (int i = 0; i < pastCapacity; i++) 
	{
		if (supArr[i])
		{
			delete supArr[i];
		}
	}
	delete[] supArr;
}


void HashT::PrintMap()
{
	int couter=0;
	int i;
	List* temp = new List;
	for (i = 0; i < capacity; i++)
	{
		if (hashArr[i] != nullptr)
		{
			if (hashArr[i]->state)
			{
				couter++;
				temp = hashArr[i];
				while (temp->next != nullptr)
				{
					cout << temp->key << " - " << temp->element << endl;
					temp = temp->next;
				}
				cout << temp->key << " - " << temp->element << endl;
			}
		}
	}
	if (couter == 0)
	{
		cout << "Map is empty";
	}
}
