#include "mergesort.h"

int noOverflow(int a, int b){
	return a/2 + b/2 + (a%2 + b%2)/2;
}

void joinArray(int first, int mid, int last, int values[]){
	int sorted[last - first];
	int sortIndex = 0;
	int firstIndex = first;
	int secondIndex = mid;

	while(firstIndex < mid && secondIndex < last){
		if(values[firstIndex] < values[secondIndex]){
			sorted[sortIndex] = values[firstIndex];
			firstIndex++;
			sortIndex++;
		}
		else{
			sorted[sortIndex] = values[secondIndex];
			secondIndex++;
			sortIndex++;
		}
	}

	while(firstIndex < mid){
		sorted[sortIndex] = values[firstIndex];
		firstIndex++;
		sortIndex++;
	}

	while(secondIndex < last){
		sorted[sortIndex] = values[secondIndex];
		secondIndex++;
		sortIndex++;
	}

	for(int x = 0; x < last - first; x++){
		values[x + first] = sorted[x];
	}
}

void partition(int first, int last, int values[]){
	if (last - first <= 1){
		return;
	}
	else{
		int mid = noOverflow(first,last);
		partition(first, mid, values);
		partition(mid, last, values);
		joinArray(first, mid, last, values);
	}
}

void mergesort(int size, int values[]) {
  partition(0, size, values);
}
