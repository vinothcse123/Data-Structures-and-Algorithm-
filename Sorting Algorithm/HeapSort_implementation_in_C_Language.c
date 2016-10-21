#include "stdio.h"

#define GETARRAYSIZE(a) sizeof(a)/sizeof(a[0])
/*
	10
	/  \
14     6
/ \   / \
19  25 20  9   
	
*/

void swap(int *a,int *b)
{
	if(a && b)
	{
		int temp=*a;
		*a=*b;
		*b=temp;
	}
}

void heapify(int completeBinarytree[],int p_noOfElementInTree,int currentPos)
{
	int leftNodePos=currentPos*2+1; //+1 because index(or)Root Node start with zero
	int rightNodePos=currentPos*2+2; //+2 because index(or)Root Node start with zero 
	int largestValuepos=currentPos;
	
	if(leftNodePos <= p_noOfElementInTree && completeBinarytree[leftNodePos] > completeBinarytree[currentPos])
	{
		largestValuepos = leftNodePos;
	}
	
	if(rightNodePos <= p_noOfElementInTree && completeBinarytree[rightNodePos] > completeBinarytree[currentPos])
	{
		largestValuepos = rightNodePos;
	}
	
	if(largestValuepos != currentPos)
	{
		swap(&completeBinarytree[currentPos],&completeBinarytree[largestValuepos]);
		heapify(completeBinarytree,p_noOfElementInTree,currentPos);
	}
}


void heapSort(int completeBinarytree[],int p_noOfElementInTree)
{
	
	for(int i=(p_noOfElementInTree/2);i>=0;i--)
	{
		heapify(completeBinarytree,p_noOfElementInTree,i);
	}
	
	int noOfElementInTree=p_noOfElementInTree;
	
	printf("Sorted Array is: ");
	
	while(noOfElementInTree >= 0) // Looping until no elements in the tree
	{
		/* swapping the root and last element in tree and removing the last element in tree */
		
		
		swap(&completeBinarytree[0],&completeBinarytree[noOfElementInTree]);				
		printf("%d ",completeBinarytree[noOfElementInTree]);
		
		/* After we call the heapify, root element is the max element in the tree because we have applied max heap property */
		/* To sort in ascending order, use the min heap property */
		heapify(completeBinarytree,--noOfElementInTree,0); 
		
	}
	
	printf("\n");
	
}


int main()
{	

	int completeBinarytree[]={10,14,6,19,25,20};
	int noOfElementInTree = GETARRAYSIZE(completeBinarytree)-1;	//Doing -1 because 0 is also considered as 1 element
	heapSort(completeBinarytree,noOfElementInTree);
	
	return 0;
}