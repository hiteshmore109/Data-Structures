/*Program to sort array elements using merge sort*/
#include<iostream>
using namespace std;
void selectionSort(int arr[], int n)
{
	for(int i = 0; i < n - 1; i ++)//n-1 because j = i+1
	{
		int min = arr[i];
		for(int j = i + 1; j < n; j++)
			if(arr[j] < min)
			{
				min = arr[j];
				/**(arr + j) = *(arr + i);
				*(arr + i) = min; */
				arr[j] = arr[i];
				arr[i] = min;
			}
	}
}
int main()
{
	int n;
	cout<<"Enter the number of elements: ";
	cin>> n;
    int arr[n];
	cout<<"Enter array elements: ";
	for(int i = 0; i < n; i++)
		cin>>arr[i];
	selectionSort(arr, n);
    cout<<"The sorted array is: ";
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
    return 0;
}