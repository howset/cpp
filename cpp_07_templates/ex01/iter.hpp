#pragma once
# include <iostream>

template <typename T>
void iter(T *arr, int len, void (*func)(T&)){
	if (!arr || !func )
		return ;
	for (int i = 0; i < len; i++)
		func(arr[i]);
}

//print array
template <typename T>
void printArr(T &i) {
	std::cout << i << " ";
}

//bubble sort array (any type that support >)
template <typename T>
void sortArr(T *arr, int len) {
	if (!arr)
		return;
	for (int i = 0; i < len - 1; i++) {
		for (int j = 0; j < len - i - 1; j++) {
			if (arr[j] > arr[j + 1]) {
				T tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
			}
		}
	}
}

//increment array
template <typename T>
void incrArr(T &i) {
	i++;
}
