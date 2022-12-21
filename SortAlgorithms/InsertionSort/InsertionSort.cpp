#include<iostream>
using namespace std;
void BubbleSort(int arr[], int n){
    for(int i = 1; i < n; i++)
	{
		int temp = arr[i];
		int j = i - 1;
		while(j >= 0 && temp < arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = temp;
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