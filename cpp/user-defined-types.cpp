#include <iostream>
#include <map>
#include <string>
using namespace std;
/*
 * Here we will learn about user-defined types in C++.
 * Types built out of basic built-in types are called user-defined types.
 * They can be in the form of:
 * 1. Structures (aka structs)
 * 2. Classes
 * 3. Unions
 * 4. Enumerations
 */

/*
 * A struct is a user-defined type that groups together variables of different
 * types. The variables are called members of the struct. The struct is a way to
 * group variables together under a single name.
 */
struct Vector_Struct {
  int size;         // number of elements
  double *elements; // a pointer to the elements
};

Vector_Struct
    vec; // new vector but it doent point to anything at the moment not useful

/*
 * To make our defined vector type useful,
 * We must give the vec some elements to point to.
 * Like So:
 */
void construct_vector(Vector_Struct &v, int size) {
  v.size = size;
  // note: a new pointer is produced by the new operator/keyword below
  v.elements = new double[size]; // allocate an double arr of the given size
}

double read_and_sum_vector(unsigned int s) {
  Vector_Struct vec;
  construct_vector(vec, s);
  for (int i = 0; i != s; ++i) {
    cout << "Enter a double to add at index " + to_string(i) + ": ";
    cin >> vec.elements[i];
  }

  double sum = 0.0;
  for (int j = 0; j != s; ++j) {
    sum += vec.elements[j];
  }

  return sum;
}

/*
 * A class is a user-defined type that groups together variables and functions
 * Classes can encapsulate data and functions that operate on the data
 * Classes can have private and public members
 * Private members are only accessible within the class
 * Public members are accessible from outside the class
 */
class Vector_Class {

  // private members are only accessible within the class
private:
  int size;
  double *elements;
  void say_hello() { cout << "Hello, World!"; }

  // public members are accessible from outside the class
public:
  // the constructor - it must be same name as the class name
  Vector_Class(int size) : size{size}, elements{new double[size]} {}
  // some public function memebers of the vector_class
  double &operator[](int i) { return elements[i]; }
  int get_size() { return size; }
  double read_and_sum_vector(int s) {
    Vector_Class vec(
        s); // construct a new vector by calling the constructor method
    for (int i = 0; i != vec.size; ++i) {
      cout << "Enter a double to add at index " + to_string(i) + ": ";
      cin >> vec.elements[i];
    }
    double sum = 0.0;
    for (int j = 0; j != vec.size; ++j) {
      sum += vec.elements[j];
    }
    return sum;
  }
};

enum Type { str, num };
struct Entry {
  string name;
  Type t;
  string s;
  int i;
};

void f(Entry *e) {
  if (e->t == str) {
    cout << e->s;
  }
}

enum class Traffic_light { Green, Yellow, Red };
enum class Primary_color { Red, Blue, Yellow };

Primary_color col_yellow = Primary_color::Yellow;
auto wait_for_traffic = Traffic_light::Red;

Traffic_light &operator++(Traffic_light &light) {
  switch (light) {
  case Traffic_light::Red:
    return light = Traffic_light::Yellow;
  case Traffic_light::Green:
    return light = Traffic_light::Red;
  case Traffic_light::Yellow:
    return light = Traffic_light::Green;
  }
}

Traffic_light &operator--(Traffic_light &light) {
  switch (light) {
  case Traffic_light::Red:
    return light = Traffic_light::Green;
  case Traffic_light::Green:
    return light = Traffic_light::Yellow;
  case Traffic_light::Yellow:
    return light = Traffic_light::Red;
  }
}

string to_string(Traffic_light light) {

  std::map<Traffic_light, string> light_map = {
      {Traffic_light::Red, "Red"},
      {Traffic_light::Green, "Green"},
      {Traffic_light::Yellow, "Yellow"}};

  return light_map.find(light)->second;
}

// test vector_class
Vector_Class vec_class(5);

int main() {
  // cout << to_string(read_and_sum_vector(5));
  cout << to_string(vec_class.get_size());
  Traffic_light next_light = ++wait_for_traffic;
  cout << to_string(next_light);
}
