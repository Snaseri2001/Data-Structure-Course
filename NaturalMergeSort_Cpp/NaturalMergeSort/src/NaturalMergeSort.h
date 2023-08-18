// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: 	Kamaledin Ghiasi-Shirazi
//				Behzad Shomali

#pragma once
#include "ISort.h"
#include <queue>
#include <iostream>
using std::queue;
using namespace std;
template <class T>
class NaturalMergeSort: public ISort<T>{

public:
	virtual void Sort (T* arr, int n){
		temp = new T[n];
		queue<int> points = queue<int>();
		FindBorders(arr, n, points);
	

		//Write your code here
	
		int p  ; 
		int q ; 
		int r ;
		int   o ; 
		int yq ; 
		int oo = points.size() ;
		while(oo > 4){
		
		
		int  u  = points.size() ; 
		p = points.front() ;
		//<<p <<"ff"<<endl ;
		points.pop() ;
	
	//cout<<p<<"ff"<<q<<"ff"<<endl;
		while(points.size() > 2){
		
		q = points.front() ;
		points.pop() ;
		
	
		r = points.front() ;
		points.pop() ;  
	
		Merge( arr,  p,  q, r) ;

		p = r ;
	
}
	FindBorders(arr, n, points);
	oo = points.size() ;
}
	Merge( arr,  0, r , n ) ;

		delete[] temp;
	}

protected:
	void FindBorders(T* arr, int n, queue<int> &points){
		//Write your code here
		
		
		int i  ;
		T min  = arr[0] ;
		points.push(0) ;
	    for(i =  1 ; i <= n-1 ; i ++ ) { 
		   if(arr[i] >= min ){
		   	min = arr[i] ;
		   }else{
		   	min = arr[i] ;
		   	points.push(i) ;
		   	
		   	
		   	
		   	
		   }
	
		 } 
		points.push(n) ;
	//	 points.push(arr[n-1]) ;
		
		
		
		
	}

	void Merge(T* arr, int p, int q, int r) {
		//Write your code here
		
			int 	m = r  ; 
			int     n =   q;
			int  i=p;
		    int j=q; 
			int  k=p; 
			 
		 while (i < n && j < m){      
		   if (arr[i] <= arr[j])          
		      {temp[k] = arr[i] ; 
			  i++;
			  k++;
			  }else            
			    {temp[k] = arr[j];
				j++;
				k++;
				} 
				}
						 while (i < n)    
				         {temp[k] = arr[i];i++;k++;}
						  while (j  < m)   
					    {temp[k] = arr[j];j++;k++;} 

		int u ;
//		int y ;
//		for(y= p ; y <= m+n+p-1; y++){
//			cout<<temp[y]<<endl ;
//		}
		for(u = p ; u <= r-1 ; u++){
			arr[u] = temp[u] ;
			
		}
	
	}
	
	T* temp;
};
