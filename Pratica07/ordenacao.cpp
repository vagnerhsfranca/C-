/*
 * ordenacao.cpp
 *
 *  Created on: 20 de out de 2017
 *      Author: ramide
 */

#include <iostream>
#include <stdlib.h>
#include <chrono>

using namespace std;

int validate(int * data, int size) {
	for (int i = 0; i < size - 1; i++) {
		if (data[i] > data[i + 1]) return 0;
	}
	return 1;
}

void print(int * data, int size) {
	for (int i = 0; i < size; i++) {
		cout << data[i] << " ";
	}
	cout << endl;
}

int * clone(int * array, int size) {
	int * copy = new int[size];
	for (int i = 0; i < size; i++) { copy[i] = array[i]; }
	return copy;
}

void swap(int &a, int &b) {
	int tmp = a;
	a = b;
	b = tmp;
}

void noopsort(int * array, int size) {

}


void bubblesort(int * array, int size) {
	int ult_des = size-1;
	int troca;

    for (int i = 1; i < size; i++) {
        for (int j = 0; j < ult_des - 1; j++) {
            if (array[j] > array[j + 1]) {
                troca = array[j];
                array[j] = array[j + 1];
                array[j+1] = troca;
            }
        }
        ult_des--;
    }
}


void selectionsort(int * array, int size) {
	int min,troca;
	for(int i = 0; i < size; i++){
        min = i;
        for(int j = i+1; j < size; j++){
            if(array[min] > array[j])
                min = j;
        }
        troca = array[min];
        array[min] = array[i];
        array[i] = troca;
	}
}


void insertionsort(int * array, int size) {
	int j, temp;
	for(int i = 1; i < size; i++){
        temp = array[i];
        j = i-1;
        while(array[j] > temp && j >= 0){
            array[j+1] = array[j];
            j--;
        }
        array[j+1] = temp;
	}
}

void merge(int * target, int * buffer, int start, int mid, int finish) {

    int esquerda = start;
    int direita = mid;

    for(int i = start; i <= finish; i++){
        if(esquerda <= (mid-1)){
            if(direita <= finish){
                if(buffer[esquerda] < buffer[direita])
                    target[i] = buffer[esquerda++];
                else
                    target[i] = buffer[direita++];

            }else{
                target[i] = buffer[esquerda++];
            }
        }else
            target[i] = buffer[direita++];
    }

}

void mergesort(int * target, int * buffer, int start, int finish) {
	if (start >= finish) return;

	int mid = (start + finish)/2;

	mergesort(buffer, target, start, mid);
	mergesort(buffer, target, mid + 1, finish);

	merge(target, buffer, start, mid + 1, finish);
}

void mergesort(int * array, int size) {
	int * copy = clone(array, size);
	mergesort(array, copy, 0, size - 1);
	delete [] copy;
}

int partition(int * array, int start, int finish) {
	int pivo = array[finish];//pivo da particao
	int p = start - 1;
	int temp;

	for(int i = start; i <= finish; i++){
        if(array[i] <= pivo){
            p++;
            temp = array[i];
            array[i] = array[p];
            array[p] = temp;
        }

	}
	return p;
}

void quicksort(int * array, int start, int finish) {
	if (finish <= start) return;
	int pivot = partition(array, start, finish);
	quicksort(array, start, pivot - 1);
	quicksort(array, pivot + 1, finish);
}

void quicksort(int * array, int size) {
	quicksort(array, 0, size - 1);
}



void show(int * array, int size, const char * name, void function(int *, int), int printFlag) {
	int * copy = clone(array, size);
	auto start = std::chrono::high_resolution_clock::now();

	function(copy, size);

	auto finish = std::chrono::high_resolution_clock::now();
	long elapsed = std::chrono::duration_cast<std::chrono::nanoseconds>(finish-start).count() / 1000;

	int valid = validate(copy, size);
	cout << name << ": " << (valid?"ok":"erro") << " (tempo[us] = " << elapsed << ") ";

	if (printFlag) print(copy, size);
	delete [] copy;
}

int main() {
	int size = 10;
	int print = 1;

	int * array = new int[size];

	for (int i = 0; i < size; i++) {
		array[i] = rand() % size;
	}

	show(array, size, "NoOpSort     ", noopsort, print);
	show(array, size, "BubbleSort   ", bubblesort, print);
	show(array, size, "SelectionSort", selectionsort, print);
	show(array, size, "InsertionSort", insertionsort, print);
	show(array, size, "MergeSort    ", mergesort, print);
	show(array, size, "QuickSort    ", quicksort, print);

	delete [] array;
}






