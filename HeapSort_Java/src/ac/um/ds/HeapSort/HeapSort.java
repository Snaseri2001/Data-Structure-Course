// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: Kamaledin Ghiasi-Shirazi
//		  	Ali Moghaddaszadeh

package ac.um.ds.HeapSort;

public class HeapSort< T extends Comparable< T > > implements ISort< T > {
    public void sort(T[] data, int n) {
        // Write your code here

        
     
        for (int i=n-1; i>=0; i--) 
        { 
            // Move current root to end 
            T temp = data[0]; 
           data[0] = data[i]; 
            data[i] = temp; 
  
            // call max heapify on the reduced heap 
            heapify(data, i, 0); 
        } 
        
    }
    void heapify(T arr[], int n, int i) 
    { 
        int largest = i; 
        int l = 2*i + 1;  
        int r = 2*i + 2;  
  
        
        if (l < n && arr[l].compareTo(arr[largest])==1){ 
            largest = l; 
        }
       
        if (r < n && arr[r].compareTo(arr[largest])==1) {
            largest = r; 
        }

        if (largest != i) 
        { 
            T swap = arr[i]; 
            arr[i] = arr[largest]; 
            arr[largest] = swap; 
  
            
            heapify(arr, n, largest); 
        } 
    } 

    
}
