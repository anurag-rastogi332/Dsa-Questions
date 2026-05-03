#include <iostream>
#include<queue>
using namespace std;

int main() {
  
  //creation
  queue<int> q;
  //insert
  q.push(5);
  q.push(51);
  q.push(52);
  q.push(53);
  //check size
  cout << "Size: "<< q.size() << endl;
  //check empty
  if(q.empty() ) {
    cout << "Queue is empty" << endl;
  }
  else {
    cout << "Queue is not empty" << endl;
  }
  //front element
  cout << q.front() << endl;
  //last element
  cout << q.back() << endl;
  //remove element 
  q.pop();
  cout << q.size() << endl;



  return 0;
}