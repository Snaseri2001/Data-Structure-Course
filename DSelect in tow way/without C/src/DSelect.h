virtual T select(T* A, int p, int r, int i ){
	T po ; 
	po = select2(A , p , r , i  , 1) ;
	return po ;
}

virtual T select2(T* A, int p, int r, int i , int step  ){
	int q1 , q2  ;
	if((r-p)/step>25){
		T  pk = choosePivot2( A , p , r ,5*step)  ;
		threeWayPartition( A ,  pk , p ,  r ,  q1 ,  q2 , step ) ;
		if (q1-p+step+step <= i*step && i*step<= q2-p){
			return A[q1+step] ;
		}else{
			if(i*step<q1+step+step-p){
				select2( A ,  p , q1 ,  i , step) ;
			}else{
				if(i*step>q2-p ){
					select2( A  , q2 , r , i - (q2-p )/step   , step) ;
				}
			}
		}
	}else{
		sortBlock( A,  p,  r , step);	
		return A[p+i*step- step] ;
	}
}

virtual void threeWayPartition(T* A, T pivot, int p, int r, int& q1, int& q2 , int step1){
	q1 = p-step1;   
	int j  = p; 
	q2 = r +step1 ; 
	while (j <= q2-step1 ) {
		if(A[j] == pivot){
   			j += step1 ;
		}else{
			if(A[j] < pivot){
				T op  = A[j] ;
				A[j] = A[q1+step1] ;
				A[q1+step1] = op ; 
				q1 = q1+ step1 ;
				j = j+step1 ;
			}else{
				if(A[j] > pivot){
					T po = A[j] ;
					A[j] = A[q2-step1] ;
					A[q2-step1] = po ; 
					q2 = q2 - step1 ; 
				}
			}
		}
	} 
}

virtual void sortBlock(T* A, int p, int r  , int step  ) {
	T max ;
	for(int i = r  ; i >=p+step  ; i -= step){
		int ss = p; 
		for(int j =p+step  ; j < i   ;j +=step) {
			if(A[j] > A[ss]){ 
				ss = j ;	
			}
		}
		if(A[ss] > A[i]){
			max = A[ss]  ;
			A[ss] = A[i] ;
			A[i] = max ; 
		}
	}
}

virtual T choosePivot2(T* A, int p, int r,int step){
	T pivot;
	int e = r-step;
	int i;
	int counter =0 ; 
	int step1 = step/5 ;
	for (i = p; i <= e; i += step) {
		sortBlock(A, i, i+step-step1 , step1);
		counter++ ;
	}
	pivot = select2( A , p+(2)*step1 ,  p+ (counter-1)*step +(2)*step1 , (counter-1)/2 + 1 ,step ) ;
	return pivot;
}
		
virtual T choosePivot(T* A, int p, int r){
	T pivot ;
	pivot = choosePivot2(A,  p,  r , 5) ;
	return pivot ;
}	
