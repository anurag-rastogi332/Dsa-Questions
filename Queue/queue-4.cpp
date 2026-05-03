#include <iostream>
using namespace std;

class Deque{
public:
  int *arr;
  int size;
  int front;
  int rear;

  Deque(int capacity) {
    arr  = new int[capacity];
    size = capacity;
    front = -1;
    rear = -1;
  }

  void pushFront(int value) {
    //3 cases: overflow, empty Queue me insert - single element, normal
    if(front == 0) {
      cout << "Oveflow " << endl;
    }
    else if(front==-1 && rear==-1) {
      front++;
      rear++;
      arr[front] = value;
    }
    else {
      front--;
      arr[front] = value;
    }
  }

  void pushBack(int value) {
    //3 cases: overflow, empty Queue me insert - single element, normal
    if(rear == size - 1 ){
      cout << "Oveflow " << endl;
    }
    else if(front==-1 && rear==-1) {
      front++;
      rear++;
      arr[rear] = value;
    }
    else {
      rear++;
      arr[rear] = value;
    }

  }

  void popFront() {
    //3 cases: underflow, single element, normal pop
    if(front == -1 && rear == -1) {
      cout << "Underflow" << endl;
    }
    else if(front == rear) {
      arr[front] = -1;
      front = -1;
      rear = -1; 
    }
    else {
      arr[front] = -1;
      front++;
    }
  }

  void popBack() {
    //3 cases: underflow, single element, normal pop
    if(front == -1 && rear == -1) {
        cout << "Underflow" << endl;
    }
    else if(front == rear) {
        arr[rear] = -1;
        front = -1;
        rear = -1; 
    }
    else {
      arr[rear] = -1;
      rear--;
    }

  }

  void print() {
    for(int i=0; i<size; i++) {
      cout << arr[i] << " ";
    }
    cout << endl;
  }

};



int main() {
  Deque dq(7);

  dq.print();
  dq.pushFront(10);
  dq.pushBack(12);
  dq.pushBack(14);
  dq.pushBack(16);
  dq.print();

  dq.popFront();
  dq.print();

  dq.popBack();
  dq.print();

  dq.pushFront(100);
  dq.print();

  dq.pushBack(200);
  dq.print();

  return 0;
}