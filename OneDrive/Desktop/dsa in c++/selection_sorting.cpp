#include<iostream>
using namespace std;
int main()
{
   int arr[1000];
   cout<<"enter the size of arr";
   int n;
   cin>>n;
   cout<<"enter the arr elements";
   for(int i=0;i<=n-1;i++)
   cin>>arr[i];

   for(int i=0;i<n-1;i++)
   {
       int index = i;                    
       for(int j=i+1;j<n;j++)
       {
         if(arr[index]>arr[j])
         index = j;
       } 
         swap(arr[i],arr[index]);
   }
   for(int i=0;i<n;i++)
   cout<<arr[i]<<" ";
}