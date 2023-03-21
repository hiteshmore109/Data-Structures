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
    int n, start, edges, u, v;
    cout<<"Enter the number of vertices: ";
    cin>>n;
    //queue to keep track of vertex yet to be explored
    Cqueue explorationq(n);
    //to keep track whether the vertex is visited or not
    int visited[n];
    for(int i = 0; i < n; i ++)
        visited[i] = 0;
    //adjacency matrix for the graph
    int adjacencym[n][n];
    for(int i = 0; i < n; i ++)
        for(int j = 0; j < n; j++)
            adjacencym[i][j] = 0;
    //number of edges present in the graph if undirected double the number
    cout<<"Enter the number of edges: ";
    cin>>edges;
    //input edges ex: if 1 connected to 2 then input: "1 2"
    for (int i = 0; i < edges; i++) {
        cout << "Enter the edges (u v): ";
        cin >> u >> v;
        adjacencym[u-1][v-1] = 1;
        // for undirected graph uncomment the next line and also half the number of edges since the connection will be made between 2 using the next line
        // adjacencym[v-1][u-1] = 1; 
    }
    cout<<"\nEnter the element from which breadth first search starts: ";
    cin>>start;
    cout<<start<<" ";
    start--;
    visited[start] = 1;
    explorationq.enqueue(start);
    while(!explorationq.isEmpty()){
        //take the first element from the queue for exploration
        int node = explorationq.peek();
        explorationq.dequeue();
        for(int j = 0; j < n; j++){
            //if the vertices are connected with each other and is visiting the vertex for first time
            if(adjacencym[node][j] == 1 && visited[j] == 0){
                //then print its connected vertices
                cout<<j+1<<" ";
                //mark visited 
                visited[j] = 1;
                //add the vertex for exploration
                explorationq.enqueue(j);
            }
        }
    }
    return 0;
}