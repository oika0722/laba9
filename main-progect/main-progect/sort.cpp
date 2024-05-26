#include "sort.h"
#include <algorithm>
#include <queue>
#include <vector>
#include <string> 

bool operator >(const phone_call& a, const phone_call& b) {
    int const num_a = std::stoll(a.number);
    int const num_b = std::stoll(b.number);
    if (num_a == num_b) {
        return a.cost > b.cost; // по возрастанию стоимости разговора
    }
    return num_a > num_b; // по убыванию номера телефона
}


void Heap_sort(std::vector<phone_call*>& arr) {
    std::priority_queue<phone_call, std::vector<phone_call>, std::greater<phone_call>> heap; // Используйте std::greater<> для создания минимальной кучи

    // Добавляем все элементы в кучу
    for (auto& item : arr) {
        heap.push(*item);
    }

    // Извлекаем элементы из кучи в массив
    for (auto& item : arr) {
        *item = heap.top();
        heap.pop();
    }
}

bool compare_duration(const phone_call& a, const phone_call& b) {
    int const duration_a = a.duration.hour * 3600 + a.duration.minute * 60 + a.duration.second;
    int const duration_b = b.duration.hour * 3600 + b.duration.minute * 60 + b.duration.second;
    return duration_a > duration_b;
}

void Quick_sort(std::vector<phone_call*>& arr, int left, int right) {
    int i = left, j = right;
    phone_call* pivot = arr[(left + right) / 2];

    while (i <= j) {
        while (arr[i] != nullptr && compare_duration(*arr[i], *pivot))
            i++;
        while (arr[j] != nullptr && compare_duration(*pivot, *arr[j]))
            j--;
        if (i <= j) {
            std::swap(arr[i], arr[j]);
            i++;
            j--;
        }
    }

    if (left < j)
        Quick_sort(arr, left, j);
    if (i < right)
        Quick_sort(arr, i, right);
}