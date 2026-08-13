#include<iostream>
using namespace std;
int main()
{
int m;
cout<<"enter size of m  : ";
cin>>m;

int n;
cout<<"enter the size of n : ";
cin>>n;
int arr[m+n];
for(int i=0; i<m+n; i++)
{
    cin>>arr[i];
}

int ar[n];
for(int i=0; i<n; i++)
{
    cin>>ar[i];
}

cout<<"first array are : "<<endl;
for(int i=0; i<m+n; i++)
{
    cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"second array are : ";
for(int i=0; i<n; i++)
{
    cout<<ar[i]<<" ";
}
cout<<endl;

for(int i=0; i<n; i++)
{
    arr[(m+n-1)-i]=ar[i];
}
cout<<"unsorted array are : "<<endl;
for(int i=0; i<m+n; i++)
{
    cout<<arr[i]<<" ";
}

for(int i=0; i<m+n; i++)
{
    for(int j=0; j<m+n; j++)
    {
        if(arr[i]>arr[j])
        {
int temp=arr[i];
arr[i]=arr[j];
arr[j]=temp;

      }
    }
}

cout<<endl;
cout<<"sorted array are : "<<endl;
for(int i=0; i<m+n; i++)
{
    cout<<arr[i]<<" ";
}

    return 0;
}
