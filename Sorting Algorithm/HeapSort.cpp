#include<iostream>
#define EMPTY_NODE -1


/*
	 10
	/  \
  14     6
  / \   / \
 19  25 20  9   
	
*/


void buildTree(int completeBinarytree[])
{
	/* Initializing tree */
	for(int i=0;i<100;i++)
	{
		completeBinarytree[i]=EMPTY_NODE; 
	}
	
	completeBinarytree[0]=10;
	completeBinarytree[1]=14;
	completeBinarytree[2]=6;
	completeBinarytree[3]=19;
	completeBinarytree[4]=25;
	completeBinarytree[5]=20;
	completeBinarytree[6]=9;
}


void heapify(int completeBinarytree[], int treeMaxSize,int currentPos)
{
	/* Recursively calling heapify until we reach the parent of last node in tree */
	if(currentPos < treeMaxSize/2-1 )
	{
		heapify(completeBinarytree,treeMaxSize,currentPos+1);
	}
	

	/* Applying the max heap property for the given node */

	int *leftNodePtr=completeBinarytree+(currentPos*2)+1;
	int *rightNodePtr=completeBinarytree+(currentPos*2)+2;
	
	
	
	int temp;
	
	if(completeBinarytree[currentPos] < *leftNodePtr)
	{
		temp=completeBinarytree[currentPos];
		completeBinarytree[currentPos]=*leftNodePtr;
		*leftNodePtr=temp;
	}
	
	if(completeBinarytree[currentPos] < *rightNodePtr)
	{
		temp=completeBinarytree[currentPos];
		completeBinarytree[currentPos]=*rightNodePtr;
		*rightNodePtr=temp;
	}	 

}


void heapSort(int completeBinarytree[],int p_treeMaxSize)
{
	int treeMaxSize=p_treeMaxSize;
	
	std::cout<<"Sorted Array is: ";
	
	while(completeBinarytree[0] != EMPTY_NODE) // Looping until no elements in the tree
	{
		/* After we call the heapify, root element is the max element in the tree because we have applied max heap property */
		/* To sort in ascending order, use the min heap property */
		heapify(completeBinarytree,treeMaxSize,0); 
		

		/* Swapping the root and last element in tree and removing the last element in tree */
		
		int temp=completeBinarytree[0];
		completeBinarytree[0]=completeBinarytree[treeMaxSize];
		completeBinarytree[treeMaxSize]=EMPTY_NODE;
		
		treeMaxSize--;
		
		std::cout<<temp<<" ";
	}
	
	std::cout<<std::endl;
	
}


int main()
{	
	int completeBinarytree[100];
	
	buildTree(completeBinarytree);
	
	int treeMaxSize=6;	
	heapSort(completeBinarytree,treeMaxSize);
	
	return 0;
}