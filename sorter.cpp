#include "sorter.h"
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

//constructor
sorter::sorter(){
	bubble_cmp = select_cmp = insert_cmp = quick_cmp = merge_cmp = 0;
	size = 0;
	for(int i = 0; i < size; i++){
		list5[i] = list4[i] = list3[i] = list2[i] = list1[i] = 0;
	}
}

//initialize elements in the list
void sorter::init_list(int usize){
	size = usize;
	srand(time(NULL));
	for(int i = 0; i < size; i++){
		list1[i] = rand() % 100 + 1;
		list2[i] = list1[i];
		list3[i] = list1[i];
		list4[i] = list1[i];
		list5[i] = list1[i];
	}
}

//print selected list
void sorter::print(int list){
	if(list == 1){
		cout << "Bubble Sort:" << endl;
		for(int i = 0; i < size; i++){
			cout << list1[i] << " ";
			if((i + 1) % 15 == 0){
				cout << endl;
			}
		}
		cout << endl << endl;
	}else if(list == 2){
		cout << "Insertion Sort:" << endl;
		for(int i = 0; i < size; i++){
			cout << list2[i] << " ";
			if((i + 1) % 15 == 0){
				cout << endl;
			}
		}
		cout << endl << endl;
	}else if(list == 3){
		cout << "Selection Sort:" << endl;
		for(int i = 0; i < size; i++){
			cout << list3[i] << " ";
			if((i + 1) % 15 == 0){
				cout << endl;
			}
		}
		cout << endl << endl;
	}else if(list == 4){
		cout << "Quick Sort:" << endl;
		for(int i = 0; i < size; i++){
			cout << list4[i] << " ";
			if((i + 1) % 15 == 0){
				cout << endl;
			}
		}
		cout << endl << endl;
	}else if(list == 5){
		cout << "Merge Sort:" << endl;
		for(int i = 0; i < size; i++){
			cout << list5[i] << " ";
			if((i + 1) % 15 == 0){
				cout << endl;
			}
		}
		cout << endl << endl;
	}else if(list == 6){
		cout << "Unsorted List:" << endl;
		for(int i = 0; i < size; i++){
			cout << list1[i] << " ";
			if((i + 1) % 15 == 0){
				cout << endl;
			}
		}
		cout << endl << endl;
	}else{
		cout << "Incorrect print choice. Choose 1, 2, 3, 4, 5, 6.";
	}
}

//bubble sort algorithm
void sorter::bubble_sort(){
	bool sorted;
	for(int i = 0; i < size && !sorted; i++){
		sorted = true;
		for(int j = size - 1; j > i; j--){
			if(list1[j] < list1[j - 1]){
				swap(list1[j], list1[j - 1]);
				sorted = false;
			}
			bubble_cmp++;
		}
	}
}

//insertion sort algorithm
void sorter::insertion_sort(){
	int first_unsorted = 1;
	for(int i = first_unsorted; i < size; i++){
		for(int j = i; j > 0; j--){
			if(list2[j] < list2[j - 1]){
				swap(list2[j], list2[j - 1]);
			}
			insert_cmp++;
		}
	}
}

//selction sort algorithm
void sorter::selection_sort(){
	int min_index;
	for(int i = 0; i < size; i++){
		min_index = i;
		for(int j = i + 1; j < size; j++){
			if(list3[min_index] > list3[j]){
				min_index = j;
			}
			select_cmp++;
		}
		swap(list3[i], list3[min_index]);
	}
}

//quick sort algorithm
void sorter::quick_sort(int first, int last){
	if(first <= last){
		int pivot_index;
		partition(first, last, pivot_index);
		quick_sort(first, pivot_index - 1);
		quick_sort(pivot_index + 1, last);
	}
}
//partitioning function used for quick sort
void sorter::partition(int first, int last, int& pivot_index){
	int pivot = list4[first];
	int last1 = first;
	int first_unknown;
	for(first_unknown = first + 1; first_unknown <= last; first_unknown++){
		if(list4[first_unknown] < pivot){
			last1++;
			swap(list4[first_unknown], list4[last1]);
		}else{
			quick_cmp++;
		}
	}
	swap(list4[first], list4[last1]);
	pivot_index = last1;
}

//merge sort algorithm
void sorter::merge_sort(int first, int last){
	
	if(first < last){
		int mid = (first + last) / 2;
		merge_sort(first, mid);
		merge_sort(mid + 1, last);
		merge(first, last);
	}
}
//function used to merge merge-sort list back together
void sorter::merge(int first, int last){
	int mid = (first + last) / 2;
	int i1 = 0;
	int i2 = first;
	int i3 = mid + 1;
	int temp[last - first + 1];
	
	while(i2 <= mid && i3 <= last){
		if(list5[i2] < list5[i3]){
			temp[i1++] = list5[i2++];
		}else{
			temp[i1++] = list5[i3++];
		}
		merge_cmp++;
	}
	while(i2 <= mid){
		temp[i1++] = list5[i2++];
		merge_cmp++;
	}
	while(i3 <= last){
		temp[i1++] = list5[i3++];
		merge_cmp++;
	}
	for(int i = first; i <= last; i++){
		list5[i] = temp[i - first];
	}
}

void sorter::print_cmp(){
	cout << "SORTING COMPARISON RESULTS: \n\n";
	cout << "Algorithm" << "\t" <<"Comparisons\n";
	cout << "Bubble\t\t" << bubble_cmp << endl;
	cout << "Insert\t\t" << insert_cmp << endl;
	cout << "Select\t\t" << select_cmp << endl;
	cout << "Quick\t\t" << quick_cmp << endl;
	cout << "Merge\t\t" << merge_cmp << endl;
}

void sorter::start(){
	int size;
	cout << "Size of array(Maximum 100): ";
	cin >> size;
	
	init_list(size);
	print(6);
	
	bubble_sort();
	print(1);
	
	insertion_sort();
	print(2);
	
	selection_sort();
	print(3);
	
	quick_sort(0, size - 1);
	print(4);
	
	merge_sort(0, size - 1);
	print(5);
	
	cout << endl;
	print_cmp();
	
} 
