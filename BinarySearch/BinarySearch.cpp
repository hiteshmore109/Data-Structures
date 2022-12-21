#include<iostream>
using namespace std;
void SortArray(int arr[], int size){
    for(int i = 0; i < size; i++){
        int min = arr[i];
        for(int j = i + 1; j < size; j++){
            if(arr[j] < min){
                arr[i] = arr[j];
                arr[j] = min;
                min = arr[i];
            }
        }
    }
}
void RecursiveSearch(int arr[], int element, int low, int high){
    int middle = (low + high)/2;
    if(arr[middle] == element)
        cout<<"Element found at position(not index) "<<middle +1;
    else if(element > middle)
         RecursiveSearch(arr, element, middle + 1, high);
    else if(element < middle)
         RecursiveSearch(arr, element, low, middle);
    else
        cout<<"Element not found";
}
int main(){
    int size;
    cout<<"Enter the number of array elements: ";
    cin>>size;
    int arr[size];
    cout<<"Enter "<<size<<" array elements: ";
    for(int i = 0; i < size; i++)
        cin>>arr[i];
        SortArray(arr, size);
    cout<<"\nThe sorted array is: ";
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    int method, element;
    cout<<"\nEnter the element to be searched: ";
    cin>>element;
    cout<<"\nEnter the searching technique: \n1: Recursive search\n2: Iterative\n";
    cin>>method;
    int high = size - 1, low = 0, middle = (low + high)/2;
    switch (method)
    {
    case 1:
        RecursiveSearch(arr, element, low, high);
        break;
    case 2:
        while(low <= high){
            if(element == arr[middle]){
                cout<<element<<" found at position "<< middle + 1;
                break;
            }
            else if(element < arr[middle]){
                high = middle - 1;
                middle = (low + high)/2;
            }
            else if(element > arr[middle]){
                low = middle + 1;
                middle = (low + high)/2;
            }
            else
                cout<<element<<" not found in the array ";
        }
    default:
        break;
    }
    return 0;
}