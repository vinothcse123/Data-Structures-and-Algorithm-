/* Implementation of Dijkstra's algorithm to find the shortest path in graph */


    class Vertex
    {
    public:
    	int m_id;
    	unsigned int m_cost;
    	bool m_isVisited;
    	
    	std::map<int,unsigned int> m_edgeList; // map to store neighbour nodes and cost to reach them
    
    	void findMinDistance(std::vector<Vertex>&);
    
    	Vertex(int p_id)
    	{
    		m_id= p_id;
    		if(p_id == 0)
    		{
    			m_cost=0;
    		}
    		else
    		{
    			m_cost=UINT_MAX; // Assigning Infinite cost
    		}
    		m_isVisited=false;
    	}
    
    	Vertex()
    	{			
    	}
    };
    
    void Vertex::findMinDistance(std::vector<Vertex> &p_vertex)
    {
    	
    	m_isVisited= true;
    	// Looping throgh the neighbour list and update cost 
    	for(std::map<int,unsigned int>::iterator iter = m_edgeList.begin();
    		iter!=m_edgeList.end(); iter++)
    	{
    		//If cost of picked neighbour is greater than current_vertex+new cost then replace cost
    		if ( p_vertex.at(iter->first).m_isVisited == false && p_vertex.at(iter->first).m_cost > m_cost+(iter->second))
    		{
    			p_vertex.at(iter->first).m_cost=m_cost+iter->second;
    
    			std::cout<<"\nVertex Id : "<<p_vertex.at(iter->first).m_id;
    			std::cout<<"\nExisting Cost  : "<<p_vertex.at(iter->first).m_cost;			
    			std::cout<<"\nNew Cost : "<<p_vertex.at(iter->first).m_cost;
    		}
    	}
    }
    
    int main()
    {
    	std::vector<Vertex> l_vertex;
    
    	for(int i=0; i<7;i++)
    	l_vertex.push_back(Vertex(i)); // Push Vertex to vector container
    
    	// updating the edges and cost to respective node
    	// The below model is similar to priority queue.
    
    	l_vertex.at(0).m_edgeList.insert(std::make_pair((l_vertex.at(5).m_id),14));
    	l_vertex.at(0).m_edgeList.insert(std::make_pair((l_vertex.at(2).m_id),9));
    	l_vertex.at(0).m_edgeList.insert(std::make_pair((l_vertex.at(1).m_id),7));
    	
    	
    	l_vertex.at(1).m_edgeList.insert(std::make_pair((l_vertex.at(0).m_id),7));
    	l_vertex.at(1).m_edgeList.insert(std::make_pair((l_vertex.at(2).m_id),10));
    	l_vertex.at(1).m_edgeList.insert(std::make_pair((l_vertex.at(3).m_id),15));
    
    	l_vertex.at(2).m_edgeList.insert(std::make_pair((l_vertex.at(0).m_id),9));
    	l_vertex.at(2).m_edgeList.insert(std::make_pair((l_vertex.at(5).m_id),2));
    	l_vertex.at(2).m_edgeList.insert(std::make_pair((l_vertex.at(3).m_id),11));
    	l_vertex.at(2).m_edgeList.insert(std::make_pair((l_vertex.at(1).m_id),10));
    
	l_vertex.at(5).m_edgeList.insert(std::make_pair((l_vertex.at(0).m_id),14));
	l_vertex.at(5).m_edgeList.insert(std::make_pair((l_vertex.at(2).m_id),2));
	l_vertex.at(5).m_edgeList.insert(std::make_pair((l_vertex.at(4).m_id),9));

	l_vertex.at(4).m_edgeList.insert(std::make_pair((l_vertex.at(5).m_id),9));
	l_vertex.at(4).m_edgeList.insert(std::make_pair((l_vertex.at(3).m_id),6));

	l_vertex.at(3).m_edgeList.insert(std::make_pair((l_vertex.at(4).m_id),6));
	l_vertex.at(3).m_edgeList.insert(std::make_pair((l_vertex.at(2).m_id),11));
	l_vertex.at(3).m_edgeList.insert(std::make_pair((l_vertex.at(1).m_id),15));


	
	// updating cost of each vertex by calling findMinDistance

	for(std::vector<Vertex>::iterator iter = l_vertex.begin(); iter != l_vertex.end(); iter++)
	{
		(*iter).findMinDistance(l_vertex);
	}

	for(int i=0;i<6;i++)
	std::cout<<"\n\nshortest "<<i<<" "<<l_vertex.at(i).m_cost;

	return 0;
    }
