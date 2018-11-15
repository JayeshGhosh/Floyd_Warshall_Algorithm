#include<stdio.h>
int N, M[10][10];
int min(int a,int b)
{
	if(a<b)
	return a;
	else
	return b;
}

void floydWarshallAlgo()
{
	int k,i,j;
	for(k=0; k<N; k++)
	{
		printf("\n D[%d] matrix is :\n",k);
		for(i=0;i<N;i++)
		{
			for(j=0;j<N;j++)
			if(M[i][j]>= 32760)//32760 since some bug occured at 32765
			printf(" [INF] ");
			else
			printf(" [%d] ",M[i][j]);
		printf("\n");
		}
		for(i=0; i<N;i++)
		{
			for(j=0; j<N; j++)
			{
			M[i][j]=min(M[i][j],M[i][k]+M[k][j]);
			}
		}	
		
	}
	printf("\n Final D[%d] matrix is :\n",N);
	for(i=0;i<N;i++)
	{
		for(j=0;j<N;j++)
		if(M[i][j]>= 32760)
		printf(" [INF] ");
		else
		printf(" [%d] ",M[i][j]);
	printf("\n");
	}
}

int main()
{
	int i,j;
	printf("\nEnter the size of the matrix : ");
	scanf("%d",&N);
	printf("Enter the matrix of the size %d (Enter 32767 for infinity):\n",N);
	for(i=0;i<N;i++)
	for(j=0;j<N;j++)
	scanf("%d",&M[i][j]);
	floydWarshallAlgo(); //passing original matrix and the size	
	return 0;
}
