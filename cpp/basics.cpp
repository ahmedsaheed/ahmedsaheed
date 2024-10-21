#include <algorithm>
#include <array>
#include <iostream>
#include <map>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/**
 * Struct Example
 * A struct is a user-defined data type that groups related variables under one
 * name The variables can be of different types The struct can be used to create
 * objects
 * */
struct Person {
  string name;
  int age;
  double salary;
  bool isMale;
};

void take_person(Person per) {
  const std::string gender = per.isMale ? "Male" : "Female";
  std::cout << "Name: " << per.name << "\n";
  std::cout << "Age: " << per.age << "\n";
  std::cout << "Salary: " << gender << "\n";
}

unsigned int factorial(unsigned int n) {
  if (n == 0) {
    return 1;
  }
  return n * factorial(n - 1);
}

void some_function() {
  // type conversion example
  double x;
  int y = 7;
  x = x + y;
  y = x * y;
}

/**
 *  Constants Example `const` and `constexpr`
 *  Constants are immutable values that cannot be changed
 *  Constants can be created using the `const` keyword
 *  Constants can be created using the `constexpr` keyword
 *  Constants can be used to define immutable values
 * */
void test_constants() {
  const int dmv = 17; // immutable value dmv
  // constexpr double max1 = 1.4 * square(dmv); // immutable max1 value
}

/**
 *  Arrays Example `[]`
 *  Arrays are fixed size and can be initialized with a fixed size
 *  We can use the `std::array` to create an array of fixed size
 *  To get the size of an array we can use `sizeof(arr) / sizeof(arr[0])`
 * */
void arrays() {
  char char_arr[10] = {'A', 'E', 'I', 'O',
                       'U'}; // an array of fixed 10 size (0-9)
  int char_arr_size =
      sizeof(char_arr) / sizeof(char_arr[0]); // returns the size of the array
  std::array<std::string, 10> family_members = {"Mom", "Dad", "Son"};
  family_members.size();

  std::cout << "Before Sort: " << " ";

  for (auto w : family_members) {
    std::cout << w << " ";
  }

  // sort takes an iterator to the first and last element as args and sorts
  // within that range
  std::sort(family_members.begin(), family_members.end());
  std::cout << "After Sort: " << " ";
  for (string word : family_members) {
    cout << word << ", ";
  }
}

/**
 * Pointers Example `*` and `&` and `nullptr`
 *
 * Here the pointer is used to access the second element in the array
 * The `*` symbol means `content of` and the `&` symbol means `address of`
 * The `nullptr` keyword is used to represent a null pointer
 *
 * Pointers should always point to a valid object in memory so dereferencing the
 * object would be valid When a pointer is not pointing to a valid object or no
 * object is available - it should be set to nullptr
 */
string *pointers() {
  string array_of_strings[2] = {"Mom", "Dad"};
  string *second_element_in_array = &array_of_strings[1];

  int *unsure_object = nullptr;
  return second_element_in_array;
}
/*
 * When a pointer is passed as an arg,
 * It is wise to check if the pointer actually points to a valid object like the
 * example below
 */
int check_pointer(char *p, char q) {
  // count number of occurences of q in p[]
  int count = 0;
  while (p) {
    if (*p == q)
      count++;
    p++;
  }
  return count;
}

/**
 * References Example `&`
 *
 * A reference is deduced using the `&` symbol
 * Here the unsorted vector passed in as an arguement is a reference
 * The reference is used to modify the original vector without creating a new
 * copy When not trying to modify an argument, use const reference like so
 * `const vector<double> &unsorted`
 */
void sort(vector<double> &unsorted) {
  int temp;
  bool swapped = false;
  const int data_size = unsorted.size();
  for (int i = 0; i < data_size; ++i) {
    swapped = false;
    for (int j = 0; j < data_size - i - 1; j++) {
      if (unsorted[j] > unsorted[j + 1]) {
        swap(unsorted[j], unsorted[j + 1]);
        swapped = true;
      }
    }

    if (!swapped)
      break;
  }

  cout << "\nAfter Sort: \n";
  for (auto y : unsorted) {
    cout << y << ",";
  }
}
void copy_elem() {
  int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
  int new_arr[10];

  int arr_size = sizeof(arr) / sizeof(arr[0]);
  for (int i = 0; i < arr_size; i++) {
    new_arr[i] = arr[i];
  }

  for (int el : new_arr) {
    cout << el << "\n";
  }
}

bool accept() {
  cout << "Do you want to proceed? Y/N \n";
  char answer = 0;
  map<char, bool> answerMap = {{'y', true}, {'n', false}};
  cin >> answer;

  auto it = answerMap.find(answer);
  if (it != answerMap.end()) {
    cout << "got response " << it->second;
    return it->second;
  }
  cout << "I'd have to assume that's a no!";
  return false;
}

std::pair<int, double> get_x_and_y_axis() { return {0, 1.2}; }

int main() {
  arrays();
  string test_pointer = *pointers();
  copy_elem();
  vector<double> unsorted = {1.2, 1.0, 0.5, 2.0, 2.4, 2.1, 1.1};
  sort(unsorted);
  cout << get_x_and_y_axis().first << " " << get_x_and_y_axis().second;
  accept();
}
