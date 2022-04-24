#include <iostream>
#include <fstream>
#include <chrono>

using namespace std;
using namespace std::chrono;

template<class t>
t partition(t arr[],int left,int right) {
	int i, j,pivot;
	i= left;
	pivot = arr[left];
	for (j = left + 1; j < right+1; j++) {
		if (arr[j] < pivot) {
			i = i + 1;
			swap(arr[i], arr[j]);
		}
	}
	swap(arr[i], arr[left]);//swap the arr[i] with the pivot
	return i;  //return pivot position
}

template<class t>
void quicksort(t arr[],int left, int right) {
	if (left < right) {
		int pivot=partition(arr,left,right);
		quicksort(arr,left,pivot-1);
		quicksort(arr,pivot+1,right);
	}
}

template<class t>
void display(t arr[],int size) {
	for (int i = 0; i < size; i++) {
		cout <<arr[i]<< " ";
	}
	cout << endl;
}

template<class t>
void file(string filename, t arr[], int size) {
	ifstream myfile(filename, ios::in);
	int num;
	for (int i = 0; i < size - 1; i++) {
		myfile >> num;
		arr[i] = num;
	}
	myfile.close();
}

int main() {
	int arr1[500] = { 0 };
	file("numbers500.txt", arr1, 500);
	auto start = high_resolution_clock::now();
	quicksort(arr1, 0, 499);
	auto stop = high_resolution_clock::now();
	auto duration = duration_cast<microseconds>(stop - start);
	cout << "Time taken quick sort to sort 500 numbers: " << duration.count() << " microseconds" << endl;
	cout << "===============================================================\n";

	int arr2[10000] = { 0 };
	file("numbers10000.txt", arr2, 10000);
	auto start1 = high_resolution_clock::now();
	quicksort(arr2, 0, 9999);
	auto stop1 = high_resolution_clock::now();
	auto duration1 = duration_cast<microseconds>(stop1 - start1);
	cout << "Time taken quick sort to sort 10000 numbers: " << duration1.count() << " microseconds" << endl;
	cout << "===============================================================\n";

	int arr3[100000] = { 0 };
	file("numbers100000.txt", arr3, 100000);
	auto start2 = high_resolution_clock::now();
	quicksort(arr3, 0, 99999);
	auto stop2 = high_resolution_clock::now();
	auto duration2 = duration_cast<microseconds>(stop2 - start2);
	cout << "Time taken quick sort to sort 100000 numbers: " << duration2.count() << " microseconds" << endl;
	cout << "===============================================================";
}

