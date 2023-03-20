/*C++ program to traverse a graph using Breadth First Search*/
#include<iostream>
using namespace std;
//used my program of circular queue to understand it goto: https://github.com/hiteshgithub109/Data-Structures/blob/master/Queue/CircularQueue.cpp
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
    void enqueue(const int&);
    void dequeue();
    bool isEmpty() const;
    int peek() const;
};

void Cqueue::enqueue(const int& value){
    if(count == n){
        cout<<"Queue is full cannot add new element!";
        exit(1);
    }
    if(count == 0){
        first++;
        last++;
    }
    else last = (last + 1) % n;
    queue[last] = value;
    count++;
}

void Cqueue::dequeue(){
    if(count == 0){
        cout<<"Queue is Empty!";
        exit(1);
    }
    first = (first + 1) % n;
    count--;
}

bool Cqueue::isEmpty() const{
    return count == 0;
}

int Cqueue::peek() const{
    return queue[first];
}

int main(){
    //queue to keep track of vertex yet to be explored
    Cqueue exploration(7);
    //to keep track whether the vertex is visited or not
    int visited[7] = {0, 0, 0, 0, 0, 0, 0};
    //adjacency list for the graph
    //for visual graph refer to site: https://www.researchgate.net/profile/Clive-Elphick-2/publication/236834786/figure/fig1/AS:619619178016768@1524740132217/Graph-on-7-vertices-with-degree-sequence-4-4-4-3-3-3-3-ph-2-m-3503.png
    int adjacencyl[7][7] = {
        {0, 1, 1, 1, 1, 0, 0},
        {1, 0, 1, 1, 0, 1, 0},
        {1, 1, 0, 0, 1, 0, 1},
        {1, 1, 0, 0, 0, 1, 0},
        {1, 0, 1, 0, 0, 0, 1},
        {0, 1, 0, 1, 0, 0, 1},
        {0, 0, 1, 0, 1, 1, 0}
    };
    //starting from the 6 vertex(index 5 in list)
    int i = 5;
    //marking vertex 5 as visited
    visited[i] = 1;
    exploration.enqueue(i);
    cout<<i<<" ";
    while(!exploration.isEmpty()){
        //take the first element from the queue for exploration
        int n = exploration.peek();
        exploration.dequeue();
        for(int j = 0; j < 7; j++){
            //if the vertices are connected with each other is visiting the vertex n for first time
            if(adjacencyl[n][j] == 1 && visited[j] == 0){
                //then print its connected vertices
                cout<<j<<" ";
                //mark visited 
                visited[j] = 1;
                //add the vertex for exploration
                exploration.enqueue(j);
            }
        }
    }
    return 0;
}
