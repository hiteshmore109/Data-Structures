#include<iostream>
using namespace std;
void printArray(int arr[], int n){
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    cout<<endl;
}
void swap(int arr[], int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int low, int high){
    int pivot = arr[high];
    int i = low - 1;
    for(int j = low; j < high; j++){
        if(arr[j] < pivot){
            i++;
            swap(arr, i, j);
        }
    }
    swap(arr, i + 1, high);
    return i+1;
}
void QuickSort(int arr[], int low, int high)
{
    if(low < high){
        int p1 = partition(arr, low, high);
        QuickSort(arr, low, p1-1);
        QuickSort(arr, p1+1, high);
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in the array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" array elements: ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    cout<<"Unsorted array: ";
    printArray(arr, n);
    QuickSort(arr, 0, n-1);
    cout<<"Sorted array: ";
    printArray(arr, n);
    return 0;
}