#include <iostream>
#include<queue>
#include<stack>
using namespace std;


void reverseQueue(queue<int> &q) {
  //push all element of q into stack 
  stack<int> s;
  while(!q.empty()) {
    int element = q.front();
    q.pop();
    s.push(element);
  }
  //push all element of stack into q
  while(!s.empty()) {
    int element = s.top();
    s.pop();
    q.push(element);
  }
}

void reverseQueueUsingRecursion(queue<int> &q ) {
  //base case
  if(q.empty()) {
    return;
  }
  //1 case main solve karunga baaki recursion sambhal lega 
  int element = q.front();
  q.pop();
  //baaki recursion
  reverseQueueUsingRecursion(q);
  //backtracking
  q.push(element);
}

void printQueue(queue<int> q) {

  while(!q.empty()) {
    cout << q.front() << " ";
    q.pop();
  }  
  cout << endl;

}

//unUsedElementCount = q.size() -> initialse
void reverseInKGroup(queue<int> &q, int k, int unUsedElementCount) {
  //let's find out whther we have any k elemnts to reverse or nor
  if(unUsedElementCount >= k ) {
    //I have a k group to reverse
    //reverse it 
    // 1 case main solve krunga
    stack<int> s;
    for(int i=0; i<k; i++) {
      int element = q.front();
      q.pop();
      s.push(element);
    }
    for(int i=0; i<k; i++) {
      int element = s.top();
      s.pop();
      q.push(element);
    }
    //baaki recursion sambal lega 
    reverseInKGroup(q,k, unUsedElementCount - k);
  }
  else {
    //I dont have a k group to reverse
    //as it is elemnt ko push krna tha 
    for(int i=0; i<unUsedElementCount; i++) {
      int element = q.front();
      q.pop();
      q.push(element);
    }
    
  }
}

int main() {
  queue<int> q;

  q.push(1);
  q.push(2);
  q.push(3);
  q.push(4);
  q.push(5);
  q.push(6);
  q.push(7);
  q.push(8);
 // q.push(5);
  int k = 3;

  // reverseQueueUsingRecursion(q);
  // cout << "Printing Queue: "<< endl;
  // printQueue(q);

  reverseInKGroup(q,k,q.size());
  printQueue(q);



  return 0;
}