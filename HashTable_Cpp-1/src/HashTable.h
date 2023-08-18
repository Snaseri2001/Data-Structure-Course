// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: Kamaledin Ghiasi-Shirazi
//		  	Ali Moghaddaszadeh

#pragma once
#include "Map.h"
#include<iostream>
using namespace std;

template <class K, class V>
class HashTable :
	public Map<K, V>
{
public:
	HashTable(int (*hashFunc) (K), float maxLoadingFactor=0.7, int initCapacity=7) {
		// Write your code here
			this->hashFunc = *hashFunc ;
		this->mCapacity =initCapacity   ;
		this->mStateTable = new bool[this->mCapacity];
		this->mTable = new pair<K, V>[this->mCapacity];
	
		this->mSize = 0 ;
		this->mMaxLoadingFactor = maxLoadingFactor;
		int s ;
			for(s= 0 ; s< this->mCapacity ; s++){
			this->mStateTable[s] = false ;
		}
	
		
	}
	virtual ~HashTable()
	{
		delete[] mTable;
		delete[] mStateTable;
	}

	virtual  void assign(K key, V value)
	{
		// Write your code here

		
		
		int ff = this->mMaxLoadingFactor*10 ;
		int uu = (this->mCapacity*(ff+1))/10 ;
	
		
		if(this->mSize >= uu){
			
			
			pair<K  , V > *firstTable = new pair<K,V>[this->mCapacity] ;
			bool *secind = new bool[this->mCapacity];
			int j ;
			int sh = this->mCapacity ;
			for(j = 0 ; j < this->mCapacity ; j++){
				firstTable[j] = this->mTable[j] ;
			}
			int ji ;
			for(ji= 0 ; ji< this->mCapacity ; ji++){
				secind[ji] = this->mStateTable[ji] ;
			}
			
			delete[] mTable ;
			delete[] mStateTable ;
		
			int capa = 2*this->capacity() ;
			int counter = 0 ;
			
			
			while(true){
				int i ;
				counter = 0 ;
				for(i = 1 ; i<= capa ; i++){
					if(capa %i ==0){
						counter ++ ;
					}
						}
						if(counter==2){break;
						}
		capa++ ;
			
		}
		
		this->mCapacity = capa ;
		
		//	cout<<this->capacity() <<"dddddddd"<<endl;
		this->mTable = new pair<K , V>[this->mCapacity] ;
		this->mStateTable = new bool[this->mCapacity] ;
		
		int s ;
		for(s= 0 ; s< this->mCapacity ; s++){
			this->mStateTable[s] = false ;
		}
	this->mSize  = 0 ;
		int ui ;
		for(ui = 0 ; ui < sh; ui ++){
			if(secind[ui] == true){
			
			assign(firstTable[ui].first , firstTable[ui].second) ;
		}
		}
		
		assign(key , value) ;
		
	
//	
		
	}else{
		//..............................................
	int shomare = this->hashFunc(key) ;
	 shomare = shomare% this->mCapacity;
	 //	cout<<"fffffffffffffffffffffff" ;
	 bool e = true ;
	while(true){
	
		if(this->mStateTable[shomare] == false){
		this->mStateTable[shomare] = true ;
		this->mTable[shomare] = make_pair(key,value) ;
		break ;
		
		}
		if(shomare < this->mCapacity -1 ){
			shomare++ ;
		}else{
			shomare = 0 ;
		}
		
	}
		
		
		
		
		
		//...............................................
	}
	this->mSize = this->mSize+1 ;	
		
		
	
		
 }

	virtual  void remove(K key)
	{
		// Write your code here
		int key1 = this->hashFunc(key) ;
		key1 = key1 % this->mCapacity  ;
			
		
		this->mStateTable[key1] = false ;
		
		
	
		int counter =0 ; 
		if(key1 < this->mCapacity-1){
			counter = key1 +1 ;
		}else{
			counter = 0 ;
		}
		cout<<"dddd" ;
		while(this->mStateTable[counter] != false){
		pair<K , V> io = 	 this->mTable[counter] ;
		K op = io.first ;
			int y = this->hashFunc(op) ;
			y= y%this->mCapacity ;
			if(y > key1){
				if(counter+1 < this->mCapacity -1 ){
					counter ++ ;
				}else{
					counter = 0  ;
				}
					
				}else{
					//.............
					this->mTable[key1] = this->mTable[counter] ;
					this->mStateTable[key1] = true ;
				remove(op) ;
				break ; 
					
					
					
					//................
				}
			
		}
		
		
		
		
			}

	virtual int capacity() {
		return mCapacity;
	}

	//V& get(K key);
	virtual  V& operator[] (K key)
	{
		// Write your code here
	}

	void print()
	{
		for (int i = 0; i < mCapacity; i++)
			cout << i << "\t";
		cout << endl;

		for (int i = 0; i < mCapacity; i++)
		{
			if (mStateTable[i])
				cout << mTable[i].second << "\t";
			else
				cout << "*" << "\t";
		}
		cout << endl;
	}

protected:
	int mCapacity;
	int mSize;
	std::pair<K, V>* mTable;
	bool	  *	mStateTable; // 0 => empty ,  1 => full
	int	 (*hashFunc)(K key);
	float mMaxLoadingFactor;
};

