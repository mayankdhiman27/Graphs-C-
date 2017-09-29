#include<stdio.h>
#include<unistd.h>

int R=11,C=25;
char matFill[11][25];

//FloodFill using DFS(recursion)
void FloodFill(int i,int j,char c,char r){		//i: row number, j:col number to start filling in..and r is char to replace with
	if(i<0||j<0||i>=R+R||j>=C+R|| matFill[i][j]!=c){
		return;
	}
	else{
		matFill[i][j]=r;
		//sleep(1);
		/*for(int i=0;i<R;i++){					//You can uncomment this to have a look that how flood fill works
		  for(int j=0;j<C;j++){
		  printf("%c",matFill[i][j]);
		  }
		  }
		  printf("\n");*/
		FloodFill(i+1,j,c,r);
		FloodFill(i,j+1,c,r);
		FloodFill(i-1,j,c,r);
		FloodFill(i,j-1,c,r);
	}
}

//Driver Code
void main(){

	//char *mat;
	//mat=&matFill[0][0];
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			scanf("%c",&matFill[i][j]);
		}
	}

	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			printf("%c",matFill[i][j]);
		}
	}
	printf("\n");

	//print(mat);
	FloodFill(5,8,'.','R');
	//print(mat);
	for(int i=0;i<R;i++){
		for(int j=0;j<C;j++){
			printf("%c",matFill[i][j]);
		}
	}
	printf("\n");
}
