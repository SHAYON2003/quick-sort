#include <iostream>
using namespace std;

int partition(int arr[],  int s, int e){
    
   int pivotIndex = s;
    int pivotElement = arr[s];
   
  
  // pivot element ko apne sahi jagah pe rakhna hai -> we will maintain a count varaible , jitna count aaya  plus (s) krdenge so that hame correct index mil jaega pivot element ka.
   int count = 0;
   for(int i = s+1;i<=e;i++){
       if(arr[i]<=pivotElement){
               count++;
       }
       }
    // pivot index janne k liye maine right index calculate kra jisme (s+count) krdiya
    // loop se bahar aate hi mere pass pivot ki right index mil chuki hai
    int rightIndex = s+count;
   swap(arr[pivotIndex], arr[rightIndex]);
    pivotIndex = rightIndex;

  // abh wrong elements check kro
  // how to check wrong elements?
  // wrong elements -> pivot ke left side values agar koi bhi badi hai and right side me koi bhi value choti hai to wo wrong elements hai.( left half of the array me values pivot se less than honi chahiye and right half of the array me values pivot se more than honi chahiye)
  // To remove wrong elements -> we have to swap between left half large element with the right half of the array small element.

 int i = s;
  int j = e;
   

 while(i< pivotIndex && j> pivotIndex){
     if(arr[i]<=pivotElement){
         i++;
     }
   if(arr[j]> pivotElement){
     j--;
   }
 
 // 2 case bante hai 
 // 1. Swap krna padh sakta hai
 // 2. swap krna nai padh sakta
 
  if(i< pivotIndex && j> pivotIndex){
       swap(arr[i], arr[j]);
  }
 }

return pivotIndex;
}

void quicksort(int arr[], int n, int s, int e){
    // base case
   if(s>=e) 
     return;
    // partioning logic 
     int p = partition(arr, s , e);
  
   //left call -> left array ko sort krdo
     quicksort(arr, n,s,p-1);

     // right call -> Right array ko sort krdo
     quicksort(arr,n,p+1,e);}


int main() {
  int arr[] = {8,3,1,4,20,50,30};
  int n = 7;
  int s = 0;
  int e = n-1;
 
  quicksort(arr, n,s, e);
  for(int i = 0;i<n;i++){
    cout<<arr[i]<<" ";
  }
 cout<<endl;
  return 0;
}