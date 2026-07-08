#include <iostream>
#include <queue>
using namespace std;

class Heap {
public:
  int *arr;
  int size;
  int index;

  Heap(int capacity) {
    size = capacity;
    arr = new int[size];
    index = 0;
  }

  void printHeap() {
    for(int i=0; i<size; i++) {
      if(i == 0) {
        cout << "X" << " ";
      }
      else {
        cout << arr[i] << " ";
      }
    }
    cout << endl;
  }

  void insert(int value) {
    // overflow
    if (index == size - 1) {
      cout << "Overflow" << endl;
      return;
    }
    // insert logic
    index++;
    arr[index] = value;
    // correction position
    int childIndex = index;

    while (childIndex > 1) {

      int parentIndex = childIndex / 2;

      if (arr[childIndex] > arr[parentIndex]) {
        swap(arr[childIndex], arr[parentIndex]);
        // log bhul jaaate h
        childIndex = parentIndex;
      } else {
        // parent > child
        break;
      }
    }
  }

  void deleteFromHeap() {
    swap(arr[1], arr[index]);
    index--;
    //correct postition -> 1 index - new element
    //int capacity = index;
    //heapify(arr, capacity, 1);
  }

  

  

};

void heapify(int *arr, int capacity, int currIndex) {
  int i  = currIndex;
  int leftChild = 2*i;
  int rightChild = 2*i+1;
  //now target is to find the largest index
  int largestIndex = i;
  //check for leftIndex
  if(leftChild <= capacity && arr[leftChild] > arr[largestIndex] ) {
    largestIndex = leftChild;
  }
  //check for rightIndex
  if(rightChild <= capacity && arr[rightChild] > arr[largestIndex]) {
    largestIndex = rightChild;
  }
  //agar yaha tk aagye , iska mtlb largestIndex, 
  //teeno me se sabse badi value pr hoga 

  //agar current elemnt hi largest h , toh kuch krne ki need hi nahi h 
  //agar current element largest nahi h toh operations perform krte h 
  if(largestIndex != i) {
    //current elemtn is not largesst
    swap(arr[i], arr[largestIndex]);
    i = largestIndex;
    //1 case toh maijne solve krdia 
    //baaki recursion sambhal legaa
    heapify(arr, capacity, i);
  }
}

void buildHeap(int *arr, int n) {
  for(int i=n/2; i>=1; i--) {
    heapify(arr,n,i);
  }
}

void heapSort(int *arr, int n) {
  while(n > 1) {
    swap(arr[1], arr[n]);
    n--;
    heapify(arr,n,1);
  }
}

int main() {
  int arr[] = {-1,10,20,30,40,50};
  int n = 5;

  buildHeap(arr, n);

  cout << "Printing Heap: " << endl;
  for(int i=0; i<=n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;

  heapSort(arr,n);

  cout << "Printing array after heapsort call: " << endl;
  for(int i=0; i<=n; i++) {
    cout << arr[i] << " ";
  }
  cout << endl;
  

  
  
  
  // pq.insert(5);
  // pq.insert(7);
  // pq.insert(8);
  // pq.insert(2);
  // pq.insert(4);
  // cout << "Printing Heap: " << endl;
  // pq.printHeap();

  // pq.deleteFromHeap();
  // cout << "Printing Heap: " << endl;
  // pq.printHeap();

  

  // //min-heap
  // priority_queue<int,vector<int>, greater<int> > pq;
  // pq.push(5);
  // pq.push(7);
  // pq.push(8);
  // pq.push(2);
  // pq.push(4);

  // cout << pq.top() << endl;
  // pq.pop();
  // cout << pq.top() << endl;

  // max-heap
  //  priority_queue<int> pq;
  //  //insert
  //  pq.push(5);
  //  pq.push(7);
  //  pq.push(8);
  //  pq.push(2);
  //  pq.push(4);
  //  //size
  //  //cout << pq.size() << endl;
  //  //empty
  //  //cout << pq.empty() << endl;
  //  //top
  //  //cout << pq.top();
  //  //delete - highest element - max heap
  //  pq.pop();
  //  cout << pq.top() << endl;

  return 0;
}