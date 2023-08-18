// Copyright (C) Kamaledin Ghiasi-Shirazi, Ferdowsi Univerity of Mashhad, 2020 (1399 Hijri Shamsi)
//
// Authors: Behnam ‌Bakhshi
//          Ali Moghaddaszadeh

#pragma once
#include "ISelect.h"
#include <iostream>

using namespace std;

template <class T>
class DSelect : public ISelect<T> {
private:
    const int mBlockSize;

public:
    DSelect(void): mBlockSize(5) {}
    virtual ~DSelect(void) {}

    virtual T select(T* A, int p, int r, int i) {
        int q1, q2;
        if (r - p > 25) {
            T pk = choosePivot(A, p, r);
            threeWayPartition(A, pk, p, r, q1, q2);
            if (q1 - p + 2 <= i && i <= q2 - p) {
                return A[q1 + 1];
            } else {
                if (i < q1 + 2 - p) {
                    select(A, p, q1, i);
                } else {
                    if (i > q2 - p) {
                        select(A, q2, r, i + p - q2);
                    }
                }
            }
        } else {
            sortBlock(A, p, r);
            return A[p + i - 1];
        }
    }

protected:
    virtual void threeWayPartition(T* A, T pivot, int p, int r, int& q1, int& q2) {
        q1 = p - 1;
        int j = p;
        q2 = r + 1;
        while (j <= q2 - 1) {
            if (A[j] == pivot) {
                j++;
            } else {
                if (A[j] < pivot) {
                    T op = A[j];
                    A[j] = A[q1 + 1];
                    A[q1 + 1] = op;
                    q1++;
                    j++;
                } else {
                    if (A[j] > pivot) {
                        T po = A[j];
                        A[j] = A[q2 - 1];
                        A[q2 - 1] = po;
                        q2--;
                    }
                }
            }
        }
    }

    virtual void sortBlock(T* A, int p, int r) {
        T max;
        for (int i = r; i >= p + 1; i--) {
            int ss = p;
            for (int j = p + 1; j < i; j++) {
                if (A[j] > A[ss]) {
                    ss = j;
                }
            }
            if (A[ss] > A[i]) {
                max = A[ss];
                A[ss] = A[i];
                A[i] = max;
            }
        }
    }

    virtual T choosePivot(T* A, int p, int r) {
        int e = r - mBlockSize;
        int i;
        int counter = 0;
        for (i = p; i <= e; i += mBlockSize) {
            sortBlock(A, i, i + mBlockSize - 1);
            counter++;
        }

        int size = counter;
        T* C = new T[size];
        int j = 0;

        for (i = p + mBlockSize / 2; i <= r - mBlockSize; i += mBlockSize) {
            C[j] = A[i];
            j++;
        }

        T pivot = select(C, 0, size - 1, (size - 1) / 2 + 1);
        delete[] C;
        return pivot;
    }
};

