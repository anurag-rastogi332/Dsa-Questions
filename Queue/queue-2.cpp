#include <iostream>
#include<queue>
using namespace std;

int main() {
  //creation 
  deque<int> dq;
  //insert
  dq.push_front(5);
  dq.push_back(10);
  //size
  cout << dq.size() << endl;
  //pop
  dq.pop_back();
  dq.pop_front();
  //check empty
  if(dq.empty()) {
    cout << "dq is empty" << endl;
  }
  else {
    cout << "dq is not empty" << endl;
  }
  return 0;
}