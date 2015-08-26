
/*visitor_pattern_template_using_Dijkstras_algorithm.cpp */

class VisitorInterface;

class GraphInterface
{
  public:
    virtual void accept(VisitorInterface*)=0;
};


class VisitorInterface
{
  public:
    virtual void visit(GraphInterface*)=0;
};


class Graph : public GraphInterface
{

  public:
    void accept(VisitorInterface* p_visitor)
    {
      p_visitor->visit(this);
    }
};



class DijstraksVisitor : public VisitorInterface
{
  void visit(GraphInterface *p_graph)
  {
    // perform dijstraks algorithm for finding the min distance here.
  }
};

int main()
{
  GraphInterface *graph=new Graph;
  VisitorInterface *dijkstraAlgorithm=new DijstraksVisitor;

  graph->accept(dijkstraAlgorithm);



}
