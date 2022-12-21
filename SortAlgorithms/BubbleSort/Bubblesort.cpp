#include<iostream>
using namespace std;
void BubbleSort(int arr[], int n){
    for(int i = 0; i < n; i++)
    {
        int temp = arr[i];
        for(int j = i + 1; j < n; j++){
            if(arr[j] < arr[i]){
                temp = arr[j];
                arr[j] = arr[i];
                arr[i] = temp;
            }
        }
    }
}
int main()
{
    int n;
    cout<<"Enter the number of elements in array: ";
    cin>>n;
    int arr[n];
    cout<<"Enter "<<n<<" array elements: ";
    for(int i = 0; i < n; i++)
        cin>>arr[i];
    BubbleSort(arr, n);
    cout<<"The sorted array is: \n";
    for(int i = 0; i < n; i++)
        cout<<arr[i]<<" ";
    return 0;
}