#include <iostream>
#include <vector>


/*
	10
	/  \
14     6
/ \   / \
19  25 20  9   
	
*/

class Node
{
	public:
		Node(int p_value):m_value(p_value)	{}
		int m_value;	
};

class Tree
{
	public:
		std::vector<Node> m_tree_container;
		
		Tree(std::vector<int> p_tree_array)
		{
			for_each(p_tree_array.begin(),p_tree_array.end(), [](int p_node_value)
			{
				m_tree_container.push_back(p_node_value);
			});
		}
};

class HeapSort
{
	private:
		heapify(Tree &completeBinarytree,int p_noOfElementInTree,int currentPos);
	public:
		sort(Tree &completeBinarytree,int p_noOfElementInTree);	
};

void HeapSort::heapify(Tree &completeBinarytree,int p_noOfElementInTree,int currentPos)
{
	int leftNodePos=currentPos*2+1; //+1 because index(or)Root Node start with zero
	int rightNodePos=currentPos*2+2; //+2 because index(or)Root Node start with zero 
	int largestValuepos=currentPos;
	
	if(leftNodePos <= p_noOfElementInTree && completeBinarytree.m_tree_container[leftNodePos].m_value > completeBinarytree.m_tree_container[currentPos].m_value)
	{
		largestValuepos = leftNodePos;
	}
	
	if(rightNodePos <= p_noOfElementInTree && completeBinarytree.m_tree_container[rightNodePos].m_value > completeBinarytree.m_tree_container[currentPos].m_value)
	{
		largestValuepos = rightNodePos;
	}
	
	if(largestValuepos != currentPos)
	{
		swap(&completeBinarytree.m_tree_container[currentPos].m_value,&completeBinarytree.m_tree_container[largestValuepos]);
		heapify(completeBinarytree.m_tree_container,p_noOfElementInTree,currentPos);
	}
}


void HeapSort::sort(Tree &completeBinarytree,int p_noOfElementInTree)
{
	
	for(int i=(p_noOfElementInTree/2);i>=0;i--)
	{
		heapify(completeBinarytree.m_tree_container,p_noOfElementInTree,i);
	}
	
	int noOfElementInTree=p_noOfElementInTree;
	
	printf("Sorted Array is: ");
	
	while(noOfElementInTree >= 0) // Looping until no elements in the tree
	{
		/* swapping the root and last element in tree and removing the last element in tree */
		
		
		swap(&completeBinarytree.m_tree_container[0],&completeBinarytree.m_tree_container[noOfElementInTree]);
		printf("%d ",completeBinarytree.m_tree_container[noOfElementInTree]);
		
		/* After we call the heapify, root element is the max element in the tree because we have applied max heap property */
		/* To sort in ascending order, use the min heap property */
		heapify(completeBinarytree.m_tree_container,--noOfElementInTree,0);
	}
	
	printf("\n");
}


int main()
{	
	
	Tree l_complete_binary_tree({10,14,6,19,25,20});
	
	int noOfElementInTree = l_complete_binary_tree.m_tree_container.size();	//Doing -1 because 0 is also considered as 1 element
	
	HeapSort l_sort;
	l_sort.sort(l_complete_binary_tree,noOfElementInTree);
	
	return 0;
}