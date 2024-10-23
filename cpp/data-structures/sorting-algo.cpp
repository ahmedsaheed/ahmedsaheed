#include <algorithm>
#include <chrono>
#include <cstddef>
#include <iomanip>
#include <iostream>
#include <ratio>
#include <utility>
#include <vector>

using namespace std;
using std::chrono::duration;
using std::chrono::duration_cast;
using std::chrono::high_resolution_clock;
using std::chrono::milliseconds;

int get_array_size(int (&arr)[10]) { return sizeof(arr) / sizeof(arr[0]); }

void bubble_sort(int (&arr)[10]) {
  const int array_size = get_array_size(arr);
  for (int i = 0; i < array_size; ++i) {
    for (int j = 1; j < array_size - 1; ++j) {
      if (arr[j - 1] > arr[j]) {
        swap(arr[j], arr[j - 1]);
      }
    }
  }
}

void selection_sort(int (&arr)[10]) {
  const int array_size = get_array_size(arr);
  for (int i = 0; i < array_size; i++) {
    int current_min = i;
    for (auto j = i + 1; j < array_size; j = j + 1) {
      if (arr[j] < arr[current_min]) {
        current_min = j;
      };
    }

    swap(arr[i], arr[current_min]);
  }
}

void insertion_sort(int (&arr)[10]) {
  const int array_size = get_array_size(arr);
  int j = 0;
  while (j < array_size) {
    int key = j;
    while (key > 0 && arr[key] < arr[key - 1]) {
      swap(arr[key], arr[key - 1]);
      key = key - 1;
    }
    ++j;
  }
}

void merge(int (&arr)[10], int lower_b, int mid, int upper_b) {
  int i = lower_b;
  int j = upper_b;
  int temp[upper_b - lower_b];
  int t = 0;

  while (i < mid && j < upper_b) {
    if (arr[i] <= arr[j]) {
      temp[t] = arr[i];
      i++;
      t++;
    } else {
      temp[t] = arr[j];
      j++;
      t++;
    }
  }

  while (i < mid) {
    temp[t] = arr[i];
    i++;
    t++;
  }

  while (j < upper_b) {
    temp[t] = arr[j];
    j++;
    t++;
  }

  i = lower_b;
  t = 0;
  while (t < (sizeof(temp) / sizeof(temp[0]))) {
    arr[i] = temp[t];
    i++;
    t++;
  }
}

void merge_sort(int (&arr)[10], int lower_b, int upper_b) {
  if (lower_b + 1 < upper_b) {
    int mid = (lower_b + upper_b) / 2;
    merge_sort(arr, lower_b, mid);
    merge_sort(arr, mid, upper_b);
    merge(arr, lower_b, mid, upper_b);
  }
}

double convert_time(chrono::time_point<chrono::high_resolution_clock> start,
                    chrono::time_point<chrono::high_resolution_clock> end) {
  duration<double, std::milli> duration = end - start;
  return duration.count();
}

int main() {
  int arr[10] = {3, 5, 1, 8, 2, 7, 4, 8, 9, 10};
  auto start_time = high_resolution_clock::now();
  bubble_sort(arr);
  auto end_time = high_resolution_clock::now();

  cout << "Sort finished in " << convert_time(start_time, end_time) << "ms\n";

  for (int el : arr) {
    cout << el << "\n";
  }

  int arr2[10] = {3, 5, 1, 8, 2, 7, 4, 8, 9, 10};
  auto start_time2 = high_resolution_clock::now();
  selection_sort(arr2);
  auto end_time2 = high_resolution_clock::now();

  cout << "Sort finished in " << convert_time(start_time2, end_time2)
       << "ms \n";
}
