#include "sort.h"
#include <algorithm>
#include <queue>
#include <vector>
#include <string> 

bool operator >(const phone_call& a, const phone_call& b) {
	int num_a = std::stoll(a.number);
	int num_b = std::stoll(b.number);
	if (num_a == num_b) {
		return a.cost > b.cost; //    
	}
	return num_a > num_b; //    
}


void Heap_sort(std::vector<phone_call*>& arr) {
	std::priority_queue<phone_call, std::vector<phone_call>, std::greater<phone_call>> heap; //  std::greater<>    

	//     
	for (auto& item : arr) {
		heap.push(*item);
	}

	//      
	for (auto& item : arr) {
		*item = heap.top();
		heap.pop();
	}
}

bool compare_duration(const phone_call& a, const phone_call& b) {
	int duration_a = a.duration.hour * 3600 + a.duration.minute * 60 + a.duration.second;
	int duration_b = b.duration.hour * 3600 + b.duration.minute * 60 + b.duration.second;
	return duration_a > duration_b;
}

void Quick_sort(std::vector<phone_call*>& arr, int left, int right) {
	int i = left, j = right;
	phone_call pivot = *arr[(left + right) / 2];

	while (i <= j) {
		while (compare_duration(*arr[i], pivot))
			i++;
		while (compare_duration(pivot, *arr[j]))
			j--;
		if (i <= j) {
			if (arr[i] != nullptr && arr[j] != nullptr) {
				std::swap(arr[i], arr[j]);
				i++;
				j--;
			}
		}
	}

	if (left < j)
		Quick_sort(arr, left, j);
	if (i < right)
		Quick_sort(arr, i, right);
}
