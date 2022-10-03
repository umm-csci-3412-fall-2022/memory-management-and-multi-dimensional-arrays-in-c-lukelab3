#include "mergesort.h"

void mergesort(int size, int values[]) {
  partition(0, size, values);
}

void partition(int first, int last, int values[]){
	if (last - first <= 1){
		return;
	}
	else{
		int mid = (first + last)/2;
		partition(first, mid, values);
		partition(mid, last, values);
		joinArray(int first, int mid, int last, int values[]);
	}
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

	for(int x = 0; x < end - start; x++){
		values[x + start] = sorted[x];
	}
}
