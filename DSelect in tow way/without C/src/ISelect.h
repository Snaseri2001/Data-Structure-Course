// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: Behnam ‌Bakhshi
//		  	Ali Moghaddaszadeh

#pragma once

template <class T>
class ISelect{

public:
	// A[p..r] inclusive.
	// Select the i'th order statistic.
	virtual T select (T* A, int p, int r, int i   ) = 0;

protected:
	virtual void threeWayPartition (T* A, T pivot, int p, int r, int& q1, int& q2 , int step1 = 1 )=0;
};
