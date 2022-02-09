#define SIZE 100
#include <iostream>
using namespace std;

class sorter{
	private:
		int size;
		int list1[SIZE], list2[SIZE], list3[SIZE], list4[SIZE], list5[SIZE];
		
		int bubble_cmp;
		int insert_cmp;
		int select_cmp;
		int quick_cmp;
		int merge_cmp;
		
	public:
		sorter();//constructor
		void init_list(int);//initialize all the list, parameter size of elements in list
		
		void print(int);//print selected list
		
		void start();//start all sorting algorithms
		
		void bubble_sort();//bubble sort algorithm
		
		void insertion_sort();//insertion sort algorithm
		
		void selection_sort();//selection sort algorithm
		
		void quick_sort(int, int);//quick sort algorithm
		void partition(int, int, int&);//function used for quick sort
		
		void merge_sort(int, int);//merge sort algorithm
		void merge(int, int);//function used to merge merge-sort list back together
		
		void print_cmp();//print the counts of all comparisons of sorting algorithms
};
