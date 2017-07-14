#include <stdio.h>
#include <deque>
using namespace std;

class GraphNode{
public:
  int vertex;
  deque<int>adjacency;

  GraphNode(int _vertex){
    vertex = _vertex;
  }
  void dump(){
    printf("%Vertex: %d, I'm adjacent to: ", vertex);
    int i;
    for(i = 0; i<adjacency.size(); i++){
      printf("%d", adjacency[i]);
    }
    printf("\n");
  }
};

int main(){
  int vertex_count, edge_count;
  scanf("%d %d", &vertex_count, &edge_count);
  deque<GraphNode*> NodeList;
  int i, j;
  for(i = 0; i<vertex_count; i++){
    NodeList.push_back(new GraphNode(i));
  }
  for(j = 0; j<edge_count; j++){
    int vertex_1, vertex_2;
    NodeList[vertex_1]->adjacency.push_back(vertex_2);
    NodeList[vertex_2]->adjacency.push_back(vertex_1);
  }
  for(i = 0; i<NodeList.size(); i++){
    NodeList[i]->dump();
  }
}
