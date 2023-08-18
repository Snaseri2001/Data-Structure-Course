// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: Kamaledin Ghiasi-Shirazi
//		  	Ali Moghaddaszadeh

#pragma once
#include "ISort.h"
#include "Heap.h"

template<class T>
class HeapSort :
	public ISort<T>
{
public:
	virtual void sort(T* data, int n)
	{
		// Write your code here
		
		  int ff ;
      for ( ff = n / 2 - 1; ff >= 0; ff--){
      heapyfi(data, n, ff);   
      }
//		
   int j ; 
    for ( j = n - 1; j > 0; j--) {
        T io ;
        io = data[j] ; 
        data[j] = data[0] ;
        data[0] = io ;
        
        
      
 
       
        heapyfi(data, j, 0);
    }
		
	}
	
		virtual void	 heapyfi(T * data , int n , int i  ){
			
			
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
        
 
     
        heapyfi(data, n, largest);
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
};

