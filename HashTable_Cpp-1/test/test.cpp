/* Copyright (C) Ali Moghaddaszadeh, Ferdowsi Univerity of Mashhad
 * 28 Ordibehesht 1399(Hijri shamsi)
 * 17 Jun 2020
 * Author: Ali Moghaddaszadeh
*/

#include <iostream>
#include "../src/HashTable.h"
#include "I.cpp"

using namespace std;

int hashFunc(int index)
{
	return index;
}

int main() {

	int test[12] = {6, 12, 34, 29, 28, 11, 23, 7, 0, 33, 30, 45};
	int deleteItems[3] = {0, 34, 29};
	int capacity[12] = {8, 8, 8, 8, 8, 8, 17, 17, 17, 17, 17, 17};
	int result[12][17] = {{-1, -1, -1, -1, -1, -1, 6, -1},
							{-1, -1, -1, -1, 12, -1, 6, -1},
							{-1, -1, 34, -1, 12, -1, 6, -1},
							{-1, -1, 34, -1, 12, 29, 6, -1},
							{-1, -1, 34, -1, 12, 29, 6, 28},
							{-1, -1, 34, 11, 12, 29, 6, 28},
							{34, -1, -1, -1, -1, -1, 6, 23, -1, -1, -1, 11, 12, 29, 28, -1, -1},
							{34, -1, -1, -1, -1, -1, 6, 23, 7, -1, -1, 11, 12, 29, 28, -1, -1},
							{34, 0, -1, -1, -1, -1, 6, 23, 7, -1, -1, 11, 12, 29, 28, -1, -1},
							{34, 0, -1, -1, -1, -1, 6, 23, 7, -1, -1, 11, 12, 29, 28, -1, 33},
							{34, 0, -1, -1, -1, -1, 6, 23, 7, -1, -1, 11, 12, 29, 28, 30, 33},
							{34, 0, 45, -1, -1, -1, 6, 23, 7, -1, -1, 11, 12, 29, 28, 30, 33}};
	int deleteResult[3][17] = {{0, -1, 45, -1, -1, -1, 6, 23, 7, -1, -1, 11, 12, 29, 28, 30, 33},
								{-1, -1, 45, -1, -1, -1, 6, 23, 7, -1, -1, 11, 12, 29, 28, 30, 33},
								{-1, -1, 45, -1, -1, -1, 6, 23, 7, -1, -1, 11, 29, 30, 28, -1, 33}};

	HashTable<int, int> *hashTable;
	hashTable = new HashTable<int, int>(hashFunc, .7, 8);

	for (int i=0; i<12; i++) {
		cout << "Added: " << test[i] << endl;
		hashTable->assign(test[i], test[i]);

		cout << "Capacity is: " << hashTable->capacity() << endl;
		cout << "             " << capacity[i] << " <<Answer" << endl;

		hashTable->print();
		for(int j=0; j < capacity[i]; j++) {
			if (result[i][j] != -1)
				cout << result[i][j] << "\t";
			else 
				cout << "*" << "\t";
		}
		cout << "<<Answer" <<endl<<endl;
	}

	for (int i=0; i<3; i++) {
		cout << "Removed: " << deleteItems[i] << endl;
		hashTable->remove(deleteItems[i]);
		
		hashTable->print();
		for(int j=0; j < 17; j++) {
			if (deleteResult[i][j] != -1)
				cout << deleteResult[i][j] << "\t";
			else 
				cout << "*" << "\t";
		}
		cout << "<<Answer" <<endl<<endl;
	}

	int test2 [5] = {10, 2, 3, 6, 11};
	int capacity2[5] = {5, 5, 5, 11, 11};

	HashTable<int, I> *hashTable2 = new HashTable<int, I>(hashFunc, .5, 5);
	for (int i=0; i<5; i++) {
		cout << "Added: " << test2[i] << endl;
		hashTable2->assign(test2[i], I(test2[i]));

		cout << "Capacity is: " << hashTable2->capacity() << endl;
		cout << "             " << capacity2[i] << " <<Answer" << endl << endl;
	}

	cout << "Get: " << endl;
	cout << (*hashTable2)[10].getValue() << endl;
	cout << 110 << "<<Answer" << endl << endl;
	
	cout << (*hashTable2)[2].getValue() << endl;
	cout << 102 << "<<Answer" << endl;

	getchar();
}
