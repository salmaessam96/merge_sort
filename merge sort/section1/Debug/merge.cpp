#include <iostream>
#include <chrono>
#include<fstream>

using namespace std;
using namespace std::chrono;

template<class t>
void merge(t array[], int left, int middle, int right) {
	int i, j, k;
	int array1 = middle - left+1;
	int array2 = right - middle;
	t* l = new t [array1];
	t* r = new t[array2];

	for (i=0; i <array1 ; i++)
		l[i] = array[left+i];

	for(j=0; j <array2 ; j++)
		r[j] =array[middle+1+j] ;

	i = j = 0;
	k = left;

	while (i < array1 && j < array2) {
		if (l[i] <= r[j]) {
			array[k] = l[i];
			i++;
		}
		else {
			array[k] = r[j];
			j++;
		}
		k++;
	}
	while (i < array1) {
		array[k] = l[i];
		i++;
		k++;
	}
	while (j < array2) {
		array[k] = r[j];
		j++;
		k++;
	}
}

template<class t>
void mergesort(t array[], int left, int right) {
	if (left< right) {
		int middle =( left+(right-1)) / 2;
		mergesort(array, left, middle);
		mergesort(array, middle + 1, right);
		merge(array, left, middle, right);
	}
}

template<class t>
void display(t array[],int size) {
	for (int i = 0; i <size ; i++) {
		cout << array[i] << " ";
	}
	cout << endl;
}

template<class t>
void file(string filename,t arr[],int size){
	ifstream myfile(filename, ios::in);
	int num;
	for (int i = 0; i < size-1; i++) {
		myfile >> num;
		arr[i] = num;
	}
	myfile.close();
}

int main(){
	int arr1[500] = { 0 };
	file("numbers500.txt", arr1 ,500);
	auto start = high_resolution_clock::now();
	mergesort(arr1, 0, 499);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken merge sort to sort 500 numbers: "<< duration.count() << " microseconds" << endl;
	cout << "===============================================================\n";

	int arr2[10000] = { 0 };
	file("numbers10000.txt", arr2, 10000);
	auto start1 = high_resolution_clock::now();
	mergesort(arr2, 0, 9999);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "Time taken merge sort to sort 10000 numbers: " << duration1.count() << " microseconds" << endl;
	cout << "===============================================================\n";

	int arr3[100000] = { 0 };
	file("numbers100000.txt", arr3, 100000);
	auto start2 = high_resolution_clock::now();
	mergesort(arr3, 0, 99999);
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "Time taken merge sort to sort 100000 numbers: " << duration2.count() << " microseconds" << endl;
	cout << "===============================================================";

}
