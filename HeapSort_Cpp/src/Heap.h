// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: Kamaledin Ghiasi-Shirazi
//		  	Ali Moghaddaszadeh

#pragma once
#include "PriorityQueue.h"
#include <iostream>
#include <time.h>
#include <cstdlib>
using namespace std;
template <class T>
class Heap : public PriorityQueue<T>
{
public:
	Heap(){};
	~Heap(){};

	int size(){
		return mSize;
	}

	void initialize(T* data, int n)
	{
		// Write your code here
		int i ; 
		this->mSize =  n ; 
		for(i =n/2 -1 ;  i>=0 ; i--){
			
			 heapyfy(data , n , i  ) ;			
		
		}
		this->mData = data ;
		}
		
		
		virtual void	 heapyfy(T * data , int n , int i  ){
			
			
//			
//			int l  = (i+1)*2 -1 ;
//			int r = (i+1) *2 ;
//			if(l<= n-1){
//				if(r<= n-1){
//				if(data[r] > data[l] && data[r] > data[i]){
//				T io ; 
//				io = data[i] ;
//				data[i] = data[r] ; 
//				data[r] = io ;
//				i = r ;
//				heapyfy(data , n , i ) ;
//				return ; 
//				
//				}else{
//					if(data[l] > data[r] && data[l] > data[i]){
//						T io ;
//						io = data[i] ;
//						data[i] = data[l] ;
//						data[l] = io ;
//						i = l ; 
//						heapyfy(data   , n , i ) ;
//						return ;
//					}
//				}
//				}
//				if(data[l] > data[i] ){
//					T io ; 
//					io = data[i] ;
//					data[i] = data[l] ;
//					data[l] = io ;
//					heapyfy(data , n , i) ;
//					
//				}
//			}
			
			 
			
 	int largest = i; 
    int l =2 * i + 1; 
    int r = 2 * i + 2; 
 
   
    if (l < n && data[l] > data[largest]){
	
        largest = l;
}
    
    if (r < n && data[r] > data[largest]){
	
        largest = r;
}
    
    if (largest != i) {
    	
    	T io ; 
    	io = data[i] ;
    	data[i] = data[largest] ;
    	data[largest] = io ;
        
 
     
        heapyfy(data, n, largest);
    }
			
//			
			
//		int i ; 
//		T io ;
//		int j ;
//		for(j = 0 ; j <=n/2 -1 ; ){
		
//		cout<<j<<endl<<endl ;
//		for(i = (n-2) / 2  ; i >= j ; i--){	
//			int max ; 
//			if (data[2*(i+1)] < data[2*(i+1)-1]){
//		
//				if(data[i] <data[2*(i+1)-1]){
//				io = data[i] ;
//				data[i] = data[2*(i+1)-1] ;
//				data[2*(i+1)-1] = io ;
//			}
//			}else{
//			if(data[i] <data[2*(i+1)]){
//				io = data[i] ;
//				data[i] = data[2*(i+1)] ;
//			data[2*(i+1)] = io ;
//			}
//			}	
//}
//
//j= j*2 +1 ;
//}
}
	

	virtual T findMax(){
		return mData[1];
	}

	virtual T deleteMax()
	{
		// Write your code here
		int s = mSize-1 ; 
			
    	T f = mData[s]; 
		
   	    mData[0] = f; 
   		
  		this->mSize  = s ; 
  	
   		heapyfy(mData, this->mSize, 0); 
		return mData[0] ;
	}

	virtual void insert(const T& data)
	{
		// Write your code here
		
	int y = 	this->mSize +1;
		this->mSize = y ;
		this->mData[this->mSize -1 ] = data ;
		initialize(this->mData   , this->mSize ) ;
	}

private:
	int mSize;
	T* mData;
};

