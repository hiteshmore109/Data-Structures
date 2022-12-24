#include<iostream>
#include<vector>
using namespace std;
void display(vector<int> &vec1){
    for(int i = 0; i < vec1.size(); i++){
        cout<<vec1[i]<<" ";
    }
}
void SortArray(vector<int> &vec1, int size){
    for(int i = 0; i < size; i++){
        int min = vec1[i];
        for(int j = i + 1; j < size; j++){
            if(vec1[j] < min){
                vec1[i] = vec1[j];
                vec1[j] = min;
                min = vec1[i];
            }
        }
    }
}
int RecursiveSearch(vector<int> &vec1, int element, int low, int high){
    int middle = (low + high)/2;
    while(low <= high){
        if(vec1[middle] == element)
           return middle+1;
        else if(vec1[middle] < element)
            RecursiveSearch(vec1, element, low, middle - 1);
        else if(vec1[middle] > element)
            RecursiveSearch(vec1, element, middle + 1, high);
    }
    return -1;
}
int main(){
    int size;
    cout<<"Enter the size of array(vector)";
    cin>>size;
    vector<int> vec1;
    for(int i =0; i < size; i++){
        int element;
        cin>>element;
        vec1.push_back(element);
    }
    display(vec1);
    cout<<"\nSorted array: "<<endl;
    SortArray(vec1, size);
    display(vec1);
    int element;
    cout<<"\nEnter the element to be searched: ";
    cin>>element;
    int position = RecursiveSearch(vec1, element, 0, size);
    cout<<"Element is at position: "<<position;
    return 0;
}