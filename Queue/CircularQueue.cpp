#include<iostream>
using namespace std;
class Cqueue{
    int *queue;
    int first, last, n, count;
    public:
    Cqueue(const int& size){
        n = size;
        first = -1;
        last = -1;
        count = 0;
        queue = new int[n];
    }
    ~Cqueue(){ delete[] queue;}
    bool isFull() const;
    bool isEmpty() const;
    void enqueue(const int&);
    void dequeue();
    int peek() const;
    int size() const;
    int& operator[](int index) const;
};

bool Cqueue::isFull() const{
    return count == n;
}

bool Cqueue::isEmpty() const{
    return count == 0;
}

void Cqueue::enqueue(const int& value){
    if(isFull()){
        cout<<"Queue is full cannot add new element!";
        exit(1);
    }
    if(isEmpty()){
        first++;
        last++;
    }
    else last = (last + 1) % n;
    queue[last] = value;
    count++;
}

void Cqueue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty!";
        exit(1);
    }
    first = (first + 1) % n;
    count--;
}

int Cqueue::peek() const{
    return queue[first];
}

int Cqueue::size() const{
    return count;

}

int &Cqueue::operator[](int index) const{
    if(index < 0 || index >= size()){
        cout<<"Index out of range";
        exit(1);
    }
    return queue[(first + index) % n];
}

int main(){
    Cqueue q(5);
    for(int i = 1; i < 6; i++) q.enqueue(i);
    cout<<q.size();
    cout<<"The queue elements are: \n";
    for(int i = 0; i < q.size(); i++) cout<<q[i]<<" ";
    cout<<endl;
    q.dequeue();
    q.enqueue(6);
    cout<<"The queue elements are: \n";
    for(int i = 0; i < q.size(); i++) cout<<q[i]<<" ";
    cout<<endl;
    return 0;
}