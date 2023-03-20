#include<iostream>
using namespace std;
class Queue{
    int *queue;
    int first, last, n;
    public:
    Queue(const int& size){
        n = size;
        first = -1;
        last = -1;
        queue = new int[n];
    }
    bool isFull() const;
    bool isEmpty() const;
    void enqueue(const int&);
    void dequeue();
    int peek() const;
    int size() const;
    int availableSlots() const;
    int& operator[](int index) const;
};

bool Queue::isFull() const{
    if(last >= n) return true;
    return false;
}

bool Queue::isEmpty() const{
    if(first == -1 || last == -1) return true;
    return false;
}

void Queue::enqueue(const int& value){
    if(isFull()){
        cout<<"Queue is full cannot add new element!";
        exit(1);
    }
    else if(isEmpty()) {
        queue[0] = value;
        first++;
        last++;
    }
    else{
        last++;
        queue[last] = value;
    }
}

void Queue::dequeue(){
    if(isEmpty()){
        cout<<"Queue is Empty!";
        exit(1);
    }
    for(int i = 0; i < size() - 1; i++)
        queue[i] = queue[i + 1];
    last--;
}

int Queue::peek() const
{
    return queue[first];
}

int Queue::size() const{
    if(isEmpty()) return 0;
    return (last - first) + 1;
}

int Queue::availableSlots() const{
    return n - (last - first + 1);
}

int &Queue::operator[](int index) const{
    if(index < 0 || index >= size()){
        cout<<"Index out of range";
        exit(1);
    }
    return (index == 0) ? queue[0] : (index == last) ? queue[last] : queue[index];
}

int main(){
    Queue q(10);
    for(int i = 5; i > 0; i--) q.enqueue(i);
    for(int i = 0; i < q.size(); i++) cout<<q[i]<<" ";
    q[3] = 10;
    cout<<"\nAfter changing the element at index 3 the queue is: \n";
    for(int i = 0; i < q.size(); i++) cout<<q[i]<<" ";
    cout<<endl;
    cout<<"\nThe size of the queue is: "<<q.size()<<" more "<<q.availableSlots()<<" elements can be added in the queue.\n";
    q.dequeue();
    q.dequeue();
    cout<<"\nAfter removing 2 elements from the queue the size is: "<<q.size()<<"\nThe elements in the queue are: ";
    cout<<endl;
    for(int i = 0; i < q.size(); i++){
        cout<<q[i]<<" ";
    }
    return 0;
}