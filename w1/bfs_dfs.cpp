#include<iostream>
#include<string>
using namespace std;

class Stack{										//Creating class Stack
private:
	int top;
	int max;
	int arr[50];
public:
	Stack(){									//Stack Constructor
		top = -1;
		max = 50;
	};
	
	void push(int x){								//Function to add Element to stack
		if(top+1 < max)
			arr[++top] = x;
		else
			cout<<"Stack Overflow"<<endl;
	};

	int pop(){									//Function to remove Element from stack
		if(top == -1){
			cout<<"Stack Empty"<<endl;
			return -1;}
		else
			return arr[top--];
	};

	bool isEmpty(){
		if (top == -1)
			return true;
		return false;
	};

};


class Queue{										//Creating class Queue
private:
	int front,rear,size,capacity;
	int arr[50];
public:
	Queue(){									//Queue Constructor
		front = 0;
		size = 0;
		capacity = 50;
		rear = capacity - 1;
	};

	bool isFull(){
		return (size == capacity);
	};

	bool isEmpty(){
		return (size == 0);
	};

	void enQueue(int x){								//Enqueue function
		if(isFull())
			cout<<"Queue is full"<<endl;
		else{
			//cout<<x<<" is enqueued"<<endl;
			rear = (rear+1) % capacity;
			arr[rear] = x;
			size = size + 1;}
	};
	
	int deQueue(){									//Dequeue function
		if(isEmpty()){
			cout<<"Queue is Empty"<<endl;
			return -1;}
		else{
			int x;
			x = arr[front];
			//cout<<x<<" is dequeued"<<endl;
			front = (front + 1) % capacity;
			size = size - 1;
			return x;}
	};

};


class Graph{										//Graph class
private:
	int adj_mat[10][10] = {};							//Assigning adjency matrix to 0
	int visited[10] = {};								//Assigning visited state of nodes to 0
	int nodes;

public:
	Graph(){									//Graph constructor
		//adj_mat = {0};
		//visited = {0};
		cout<<"Enter the number of nodes in graph"<<endl;
		cin>>nodes;
		cout<<"\nNodes are"<<endl;
		for(int i = 0; i < nodes; i++)
			cout<<i<<"  ";
		cout<<endl;
	};

	bool add_edge(int u ,int v){							//Function to Add edge to graph return true if edge is added							
		if(u > nodes -1 || v > nodes -1){
			cout<<"\nSorry node not present\nPlease try again"<<endl;
			return false;
		}	
		else if(adj_mat[u][v] == 1){
			cout<<"\nNode already present\nPlease try again"<<endl;
			return false;
		}	
		adj_mat[u][v] = 1;
		adj_mat[v][u] = 1;
		return true;
	};

	void show_graph(){								//Function to show adjency matrix
		cout<<"\n Adjacency Matrix is :\n"<<endl;
		for(int i = 0;i < nodes; i++){
			for(int j = 0;j < nodes; j++)
				cout<<adj_mat[i][j]<<"    ";
		cout<<endl;
		}
	};

	void bfs(){									//BFS function
		for(int i = 0;i < nodes; i++)						//Reassigning all the node to not visited state
			visited[i] = 0;		
		Stack s;
		int x;
		int starting_node = 0;							//Starting node is 0
		s.push(starting_node);
		while(!s.isEmpty()){
			x = s.pop();
			if(visited[x] == 0){
				visited[x] = 1;
				cout<<x<<"   ";
				for(int i = 0; i < nodes; i++){
					if(adj_mat[x][i] == 1 && visited[i] == 0)
						s.push(i);
				}
			}

		}
		for(int i = 0;i < nodes; i++){						//Checking for disconnected graph
			if(visited[i] == 0){
				starting_node = i;
				s.push(starting_node);
				while(!s.isEmpty()){
					x = s.pop();
					if(visited[x] == 0){
						visited[x] = 1;
						cout<<x<<"   ";
						for(int i = 0; i < nodes; i++){
							if(adj_mat[x][i] == 1 && visited[i] == 0)
								s.push(i);
						}
					}
				}

			}
		}

	};

	void dfs(){									//DFS function
		for(int i = 0;i < nodes; i++)						//Reassigning all the node to not visited state
			visited[i] = 0;
		Queue q;
		int x;
		int starting_node = 0;							//Starting node is 0
		q.enQueue(starting_node);
		while(!q.isEmpty()){
			x = q.deQueue();
			if(visited[x] == 0){
				visited[x] = 1;
				cout<<x<<"   ";
				for(int i = 0; i < nodes; i++){
					if(adj_mat[x][i] == 1 && visited[i] == 0)
						q.enQueue(i);
				}
			}

		}
		for(int i = 0;i < nodes; i++){						//Checking for disconnected graph
			if(visited[i] == 0){
				starting_node = i;
				q.enQueue(starting_node);
				while(!q.isEmpty()){
					x = q.deQueue();
					if(visited[x] == 0){
						visited[x] = 1;
						cout<<x<<"   ";
						for(int i = 0; i < nodes; i++){
							if(adj_mat[x][i] == 1 && visited[i] == 0)
								q.enQueue(i);
						}
					}

				}
			}
		}

	};

};




int main(){
	Graph g;
	int temp1,temp2;
	bool edge;
	cout<<"Enter two nodes to add edge and 0, 0 to exit"<<endl;
	while(true){								//Adding edges to graph
		cin>>temp1;
		cin>>temp2;
		if(temp1 == -1 && temp2 == -1)					//If both entered nodes is -1 and -1 exit the loop
			break;

		edge = g.add_edge(temp1,temp2);
		if(edge)							//Show adjacency matrix only if edge is added
			g.show_graph();
		cout<<"\nEnter next edge"<<endl;
	}
	g.show_graph();
	cout<<"\n BFS :\n\t";
	g.bfs();
	cout<<endl;
	cout<<"\n DFS :\n\t";
	g.dfs();
	cout<<endl;



}
