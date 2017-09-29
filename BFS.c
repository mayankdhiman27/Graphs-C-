#include<stdio.h>
#include<stdlib.h>

//Node structure to store vertex and its reachable vertices.
struct node{
	int data;		
	struct node *next;
};
struct node *A[10];		//Array of structure
int visited[10]={0};		//Visited array, to mark the nodes which we visit


//Add Edge function to add edge
void addEdge(int u,int v){
	struct node *new=(struct node *)malloc(sizeof(struct node*));
	new->data=v;
	new->next=NULL;
	//printf("%d -> %d\n",new->data,new->next);
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	temp=A[u];
	//printf("temp= %d->%d\n",temp->data,temp->next);
	while(temp->next!=NULL){
		temp=temp->next;
	}
	temp->next=new;
}

int q[100];
int front=0,rear=0;
//Insert in a queue
void insert(int data){
	if(rear==100){
		printf("data Overflow\n");
	}
	else{
		q[rear++]=data;
	}
}



//Delete from a queue and return that element
int delete(){
	int ans=0;
	if(front==rear){
		ans=-1;
	}
	else{
		ans=q[front++];
	}
	return ans;
}

//IsEmpty Function to check whether queue is empty or not
int isEmpty(){
	return rear==front;
}

//Print
void print(){
	struct node *temp=(struct node *)malloc(sizeof(struct node *));
	for(int i=0;i<10;i++){
		temp=A[i];
		printf("%d -> ",temp->data);
		while(temp->next!=NULL){
			temp=temp->next;
			printf("%d -> ",temp->data);
		}
		printf("\n");
	}
}


//BFS
void BFS(int data){
	printf("*****************BFS Traversal***********************\n");
	struct node *tmp=(struct node *)malloc(sizeof(struct node *));
	tmp=A[data];
	insert(data);
	visited[data]=1;
	while(!isEmpty()){
		int n=delete();
		tmp=A[n];
		printf("%d -> ",n);
		while(tmp->next!=NULL){
			tmp=tmp->next;
			if(visited[tmp->data]!=1){
				insert(tmp->data);
				visited[tmp->data]=1;
			}
		}
	}
	printf("\n");
}

//Stack
int stack[100];
int top=-1;
void push(int data){
	if(top==100){
		printf("Overflow\n");
	}
	else{
		stack[++top]=data;
	}
}

int visited_DFS[10]={0};		//Visited array to mark visited nodes
int pop(){
	int element;
	if(top==-1){
		element=-1;
	}
	else{
		element=q[top--];
	}
	return element;
}

int isStackEmpty(){
	return top==-1;
}



//DFS Driver
void DFSrecursive(int data){
	struct node * tmp=(struct node *)malloc(sizeof(struct node *));
	tmp=A[data];
	printf("%d -> ",data);
	visited_DFS[data]=1;
	while(tmp!=NULL){
		data=tmp->data;
		if(visited_DFS[tmp->data]!=1){
			DFSrecursive(data);
		}
		tmp=tmp->next;
	}
}

int visitedDFS[15]={0};
//DFS using stack implementation
void DFS(int data){
	struct node * temp=(struct node *)malloc(sizeof(struct node *));
	struct node *new=(struct node *)malloc(sizeof(struct node *));
	temp=A[data];
	printf("%d -> ",data);
	visitedDFS[data]=1;
	push(data);
	while(!isStackEmpty()){
		while(temp!=NULL){
			//temp=temp->next;
			if(visitedDFS[temp->data]!=1){
				printf("%d -> ",temp->data);
				push(temp->data);
				visitedDFS[temp->data]=1;
				new=A[temp->data];
				while(new!=NULL){
					//new=new->next;
					if(visitedDFS[new->data]!=1){
						printf("%d -> ",new->data);
						push(new->data);
						visitedDFS[new->data]=1;
						new=A[new->data];
					}
					else{
						new=new->next;
					}
				}
			}
			else{
				temp=temp->next;
			}
		}
		int n=pop();
		temp=A[n];
	}
	printf("\n");
}

//Driver Code
void main(){
	int n=10;				//Number of vertices to input

	//scanf("%d",&n);
	//printf("Hello\n");
	for(int i=0;i<10;i++){
		A[i]=(struct node *)malloc(sizeof(struct node *));
		A[i]->data=i;
		A[i]->next=NULL;
		//printf("%d->",A[i]->data);
		//printf("%d\n",A[i]->next);
	}

	addEdge(0,1);
	addEdge(0,2);
	addEdge(1,0);
	addEdge(2,0);
	addEdge(2,3);
	addEdge(2,5);
	addEdge(3,2);
	addEdge(3,4);
	addEdge(3,6);
	addEdge(3,9);
	addEdge(4,3);
	addEdge(5,2);
	addEdge(5,7);
	addEdge(6,3);
	addEdge(6,7);
	addEdge(7,5);
	addEdge(7,6);
	addEdge(7,8);
	addEdge(8,7);
	addEdge(8,9);
	addEdge(9,3);
	addEdge(9,8);
	print();
	BFS(0);
	printf("\n*****************DFS Traversal(Recursively)******************\n");
	DFSrecursive(0);
	printf("\n");
	printf("\n*****************DFS Traversal*******************************\n");
	DFS(0);
}
