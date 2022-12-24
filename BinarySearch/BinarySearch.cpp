#include<iostream>
using namespace std;
// added SortArray method because binary search is implemented only in sorted arrays
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
        //loop will run until  the element is found
         RecursiveSearch(arr, element, middle + 1, high);
    else if(element < middle)
        //loop will run until  the element is found
         RecursiveSearch(arr, element, low, middle -1);
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
    //Sorting the array given by the user
    SortArray(arr, size);
    cout<<"\nThe sorted array is: ";
    for(int i = 0; i < size; i++)
        cout<<arr[i]<<" ";
    int method, element;
    cout<<"\nEnter the element to be searched: ";
    cin>>element;
    //choice of the user to choose recursive or Iterative search
    cout<<"\nEnter the searching technique: \n1: Recursive search\n2: Iterative\n";
    cin>>method;
    int high = size - 1, low = 0, middle = (low + high)/2;
    //using switch case to implement search using either method
    switch (method){
        case 1:
            RecursiveSearch(arr, element, low, high);
            break;
        case 2:
            //loop will run only until low and high have same values and low do not exceed high
            while(low <= high){
                //if found the element print the position and break down the loop to prevent infinity loop
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