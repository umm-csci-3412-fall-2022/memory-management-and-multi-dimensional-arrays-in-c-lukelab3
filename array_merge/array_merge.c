#include "array_merge.h"
#include "../mergesort/mergesort.h"
#include <stdlib.h>

int total(int length, int* numArray){
	int total = 0;
	for(int x = 0; x < length; x++){
		total += numArray[x];
	}
	return total;
}

int* combineArrays(int num_arrays, int* sizes, int** values){
	int arrayLength = total(num_arrays, sizes);
	int* completeArray = (int*) calloc(arrayLength, sizeof(int));
	int index = 0;

	for(int x = 0; x < num_arrays; x++){
		for(int y = 0; y < sizes[x]; y++){
			completeArray[index] = values[x][y];
			index++;
		}
	}
	return completeArray;
}

int unique(int length, int* values){
	if(length == 0){
		return 0;
	}
	
	int uniqueNums = 1;
	int previous = values[0];

	for(int x = 1; x < length; x++){
		if(values[x] != previous){
			uniqueNums++;
			previous = values[x];
		}
	}

	return uniqueNums;
}

int* deduplicate(int length, int* values){
	int uniqueNums = unique(length, values);
	int* finalArray = (int*) calloc(uniqueNums + 1, sizeof(int));
	finalArray[0] = uniqueNums;

	if(length == 0){
		return finalArray;
	}

	finalArray[1] = values[0];
	int previous = values[0];
	int index = 2;

	for(int x = 1; x < length; x++){
		if(values[x] != previous){
			finalArray[index] = values[x];
			previous = values[x];
			index++;
		}
	}

	return finalArray;
}

int* array_merge(int num_arrays, int* sizes, int** values) {
  	int* combinedArray = combineArrays(num_arrays, sizes, values);
	int arrayLength = total(num_arrays, sizes);
	mergesort(arrayLength, combinedArray);
	int* finalArray = deduplicate(arrayLength, combinedArray);
	free(combinedArray);
  	return finalArray;
}
