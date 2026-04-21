//binary search is use to find vale fast it tack mid of array (add first add last no in array)
#include<iostream>
using namespace std;
int main()
{
    int arr[1000];
    cout<<"enter size of array ";
    int n;
    cin>>n;
    cout<<"enter elements of array ";
    for(int i=0;i<n;i++)
    cin>>arr[i];
    cout<<"enter target";
    int target;
    cin>>target;

    int last=n-1,start=0,mid;
    while(start<=last)
    {
       mid=start+last/2;
       if(arr[mid]==target)
       {
          return mid;
          break;
       }
       else if(arr[mid]<target)
       start=mid+1;
       else
       last=mid-1; 
    }
    cout<<mid;

}