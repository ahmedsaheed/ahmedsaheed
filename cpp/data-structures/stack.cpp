#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

class Stack {
public:
  Stack() : elements(new vector<int>()) {}
  ~Stack() { delete elements; }
  void push(int el) { elements->emplace(elements->begin(), el); }
  void pop() { elements->erase(elements->begin()); }
  int size() { return elements->size(); }
  int peek() {
    if (!elements->empty()) {
      return elements->front();
    }
    return -1;
  }
  void print() {
    cout << '[';
    for (int el : *elements) {
      cout << el << ",";
    }
    cout << ']';
  }

  int find(int el) {
    if (!elements->empty()) {
      auto it = std::find(elements->begin(), elements->end(), el);
      if (it != elements->end()) {
        return it - elements->begin() + 1;
      }
      return -1;
    }
    return -1;
  }

private:
  vector<int> *elements;
};

int main() {

  Stack stack;
  stack.push(1);
  stack.push(2);
  stack.push(3);
  cout << stack.find(3) << "\n";
  stack.push(4);
  cout << "Stack size is: " << stack.size() << "\n";
  stack.print();
  stack.pop();
  stack.pop();
  cout << "Stack size after pop: " << stack.size() << "\n";
  stack.print();
  cout << "Peek: " << stack.peek() << "\n";
  return 0;
}
