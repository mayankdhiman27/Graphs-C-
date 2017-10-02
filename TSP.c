#include<stdio.h>

int tsp_cost[4][4]={
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};

int n=4;
//TSP function(Recursion) using BIT masking(0000) for n cities. Here n=4.
int TSP(int mask, int curr_pos){

	//Base Case(When all nodes get visited, means all bits are set)
	if(mask == ((1<<n)-1)){
		return tsp_cost[curr_pos][0];		//Distance from current node to starting node(0)
	}
	
	int min_cost=10000;			//Variable to contain min cost of path
	//Otherwise case
	//loop to visit all other cities
	for(int place=0;place<n;place++){
		if((mask & (1<<place))==0){		//Mask to check the unvisited places
			//This | operation sets the new visited place with the old one(eg, 0001 | 1000 means A and D visited)
			int new_cost=tsp_cost[curr_pos][place]+TSP(mask | (1<<place),place);
			min_cost=(min_cost < new_cost ? min_cost : new_cost);				//MIN defined as macro
		}
	}
	return min_cost;
}


//Driver Code
int main(){

	printf("Min Travel Cost = %d\n",TSP(1,0));			//1 is 0001(A visited and starting node)

return 0;
}
