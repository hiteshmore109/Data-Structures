/*Program to sort array elements using merge sort*/
#include<iostream>
using namespace std;
void merge(int arr[], int low, int mid, int high){
	int c[high];
	int i = low;
	int k = 0;
	int j = mid + 1;
	while(i <= mid && j <= high){
		if(arr[i] < arr[j]){
			c[k] = arr[i];
			k++;
			i++;
		}
		else{
			c[k] = arr[j];
			k++;
			j++;
		}
	}
	while(i <= mid){
		c[k] = arr[i];
		i++;
		k++;
	}
	while(j <= high){
		c[k] = arr[j];
		j++;
		k++;
	}
	for(i = low; i <= high; i++)
	{
	       arr[i] = c[i-low];
	}
}
void mergeSort(int arr[], int low, int high){
	int mid;
	if(low < high){
		mid = (low + high)/2;
		mergeSort(arr, low, mid);
		mergeSort(arr, mid + 1, high);
		merge(arr, low, mid, high);
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
	mergeSort(arr, 0, n-1);
	for(int i = 0; i < n; i++)
		cout<<arr[i]<<" ";
    return 0;
}