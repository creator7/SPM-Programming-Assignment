#ifndef MERGESORT_H
#define MERGESORT_H

#include<vector>

using namespace std;

class MergeSort{
private:
	static void merge(int* arr, int l, int m, int r);
public:
	static void sort(int* array, int l, int r);
};

#endif