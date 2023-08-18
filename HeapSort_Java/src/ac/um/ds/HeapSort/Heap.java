// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: Kamaledin Ghiasi-Shirazi
//		  	Ali Moghaddaszadeh

package ac.um.ds.HeapSort;

public class Heap< T extends Comparable< T > > implements PriorityQueue< T > {
    private int mSize;
    private T[] mData;

    public int getSize() {
        return mSize;
    }

   public void initialize(T[] data, int n) {
        // Write your code here
                
                 this.mSize =n ;
        	int i ; 
		for(i =n/2 -1 ;  i>=0 ; i--){
	        heapyfy(data , n , i  ) ;			
			
		}
             this.mData = data ;
               
    }

    public T findMax() {
        return mData[0];
    }

    public void insert(T data) {
        // Write your code here
                
            
        	
		this.mSize ++ ;
		this.mData[this.mSize -1 ] = data ;
		initialize(this.mData, this.mSize) ; 
    }

    public T deleteMax() {
        // Write your code here
    //    System.out.println("jjjj") ;
		T ioo = this.mData[0 ] ;
        	this.mData[0 ] = this.mData[this.mSize-1] ;
                
                this.mSize -- ;
                heapyfy(this.mData , this.mSize , 0) ;
                return ioo ;
         
    }
    
    public void heapyfy(T data[] , int n  , int   i ){
    int largest = i; 
    int l =2 * i + 1; 
    int r = 2 * i + 2; 
 
   
    if (l < n && data[l].compareTo(data[largest])==1){
	
        largest = l;
}
    
    if (r < n && data[r].compareTo( data[largest])==1){
	
        largest = r;
}
    
    if (largest != i) {
    	
    	T io ; 
    	io = data[i] ;
    	data[i] = data[largest] ;
    	data[largest] = io ;
        
 
     
        heapyfy(data, n, largest);
    }
    }
    
}
