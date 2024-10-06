#include <algorithm>
#include <array>
#include <iostream>
#include <string>
#include <vector>

 struct Person {
    std::string name;
    int age;
    double salary;
    bool isMale;
 };

double square(double x) {
    return x * x;
}

void print_square(double x) {
    std::cout << "the square of " << x << " is " << square(x) << "\n";
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

void check_auto() {
  Person p = {"John", 25, 1000.0, true};
  std::cout << p.name << "\n";
}


void test_constants() {
    const int dmv = 17; // immutable value dmv
    // constexpr double max1 = 1.4 * square(dmv); // immutable max1 value
}


/***Pointers, Arrays & References***/
void arrays() {
    char char_arr[10] = { 'A', 'E', 'I', 'O', 'U'  }; // an array of fixed 10 size (0-9)
    std::array<std::string, 10> string_array = { "Mom", "Dad", "Son" };
    std::cout << "Before Sort: " << " "; 
    for (auto w : string_array) { 
        std::cout << w << " "; 
    }
    auto f = string_array.begin(); // begins gives iterator to the first element
    auto e = string_array.end(); // end gives iterator to the last element
    
    // sort the array
    // it is a template function that takes two iterators and sorts the elements between them
    std::sort(f, e); 

    for(std::string word : string_array) {
        std::cout << word << " "; 
    } 
}

void pointers(){
    char* p; 
}


int main() {
    std::cout << "Hello, World!\n";
    print_square(1.234);
    std::vector<int> arr;
    arr.push_back(1);
    arr.push_back(2);
    arr.push_back(3);
    arr.push_back(4);
    arr.insert(arr.begin(), 0);
    check_auto();
    arrays();
}


