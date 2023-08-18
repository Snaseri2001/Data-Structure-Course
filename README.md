# Data-Structure-Course
In this repository, I intend to present the exercises that I have completed during my Data Structure course. The explanation of the problems can be seen below.

## Hash Table CPP
The code of this problem is located [Here.]((https://github.com/Snaseri2001/Data-Structure-Course/blob/main/HashTable_Cpp-1/src/HashTable.h))
In this exercise, we have to write the functions below which are located in HashTable.h file:
![Screenshot from 2023-08-19 00-15-49](https://github.com/Snaseri2001/Data-Structure-Course/assets/60386309/e4e5e909-c989-4bb0-a781-a7b026c430a0)
The features of the mentioned functions are:<br>
1.mCapacity which define the capability of the HashTable.<br>
2.mSize which define the number of data that are in the HashTable.<br>
3.mTable, which is actually the same array as HashTable, the type of this array is pair is that the first entry is the key data and the second value is the data value itself.<br>
4.mStateTable This array is the same as HashTable's capacity and specifies which The houses are empty.<br>
5.key (K) (*hashFunc) which is actually a pointer to a function that Its job is to hash the key The function has an input of template type, which is marked with K here. This is the same key that returns the hash value by giving it to this function And you can get the desired index by taking its remainder compared to the capacity Find mTable.<br>
6.mMaxLoadingFactor that specifies how many percent of the HashTable or mTable is filled SizeThe arrays (mTable and mStateTable) should be bigger The number must be between zero and one.Also, it cannot be zero and one.<br>

assign function that receives the key and data, and puts it in its proper place mTable places. On the other hand, the value corresponding to that house mStateTable should also be true, because that house is filled.<br>
**A point that you should keep in mind when implementing this function Change the size of the array. When mSize is specified as a percentage
The capacity reached (mMaxLoadingFactor) must be resized, so to change The size is twice the previous value (mCapacity) and increase it to the first number d Let's get to the next first.For example, if the initial capacity is 8, then the new capacity It should be 17. (We choose the first number because it is optimal in storage and recovery It is more and the possibility of overlapping keys is less<br>
After changing the size, don't forget that the previous values must be in the array again They should be standardized and in their correct place
Create a HashTable placeholder.<br>
**To change the size of the arrays: you have to change the array by changing the array Create the target in the heap memory and after transfer
Old data to new arrays, with the help of ][delete the previous array Remove not in use to get more memory
After deletion, it is enough for the fields to point to the new array which is bigger .
The remove function takes the key of a data and removes it from the HashTable. It is necessary that after deletion, the values after the key
checked and if necessary, moved to an empty place It continues when we reach the empty house
Note that the HashTable should never be completely filled see HashTable)
Finally, you need to implement the ][ operator, which is like calling A house works in an array, except that
Instead of the house number, we put the desired data in the form of the key and the operator It returns a reference of the value of that key. Example[hashTable] 5, which is the value of key 5 (key of type int). Note that this value may be objectAyaz is another type whose key is number 5.
