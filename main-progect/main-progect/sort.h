#pragma once
#include "tel.h"
#include <vector>
void Heap_sort(std::vector<phone_call*>& arr);
bool operator >(const phone_call& a, const phone_call& b);

bool compare_duration(const phone_call& a, const phone_call& b);
void Quick_sort(std::vector<phone_call*>& arr, int left, int right);