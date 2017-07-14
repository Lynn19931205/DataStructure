#include <stdio.h>
#include <deque>
using namespace std;

class GraphNode{
public:
  int vertex;
  deque<int>adjacency;
  int dfs_started;
  int dfs_done;

  GraphNode(int _nid){
    vertex = _nid;
    dfs_started = 0;
    dfs_done = 0;
  }
  void dump(){
    printf("Vertex: %d, I'm adjacent to: ", vertex);
    int i;
    for(i = 0; i<adjacency.size(); i++){
      printf("%d", adjacency[i]);
    }
    printf("\n");
  };
};


int DFS(int vertex){
  GraphNode * current = NodeList[vertex];
  printf("Entering node: %d\n", vertex);
  current->dfs_started = 1;
  int i;
  int next_vertex;
  for(i = 0; i<current->adjacency.size(); i++){
    next_vertex = current->adjacency[i];
    if(NodeList[next_vertex]->dfs_started == 0){
      printf("Found neighbor %d of %d.\n", next_vertex, vertex);
      DFS(next_vertex);
      printf("Returned from %d to %d.\n", next_vertex, vertex);
    }
    else{
      printf("Node %d has already been visited\n", next_vertex);
    }
  }
  current->dfs_done = 1;
  printf("Entering node: %d\n", vertex);
  return 0;
};

int main(){
  int vertex_count, edge_count;
  scanf("%d %d", &vertex_count, &edge_count);
  deque<GraphNode*> NodeList;

  int i, j;
  for(i = 0; i<vertex_count; i++){
    //GraphNode * node = new GraphNode();
    //node->vertex = i;
    //NodeList.push_back(node);
    NodeList.push_back(new GraphNode(i));
  }
  for(j = 0; j<edge_count; j++){
    int vertex_1, vertex_2;
    scanf("%d %d", &vertex_1, &vertex_2);
    NodeList[vertex_1]->adjacency.push_back(vertex_2);
    NodeList[vertex_2]->adjacency.push_back(vertex_1);
  }
  for(i = 0; i<NodeList.size(); i++){
    NodeList[i]->dump();
    DFS(NodeList[i]);
  }
  printf("\n");
  return 0;
}







/*

class GraphNode{
public:
  int vertex;
  deque<int> adjacency;

  void dump(){
    int i;
    printf("VErtex: %d, I'm adjacent to: ", vertex);
    for(i = 0; i<adjacency.size(); i++){
      printf("%d", adjacency[i]);
    }
    printf("\n");
  }
};

int main(){
  int vertex_count, edge_count;
  scanf("%d %d", &vertex_count, &edge_count);
  deque <GraphNode*> NodeList;

  int i;
  for(i = 0; i<vertex_count; i++){
    GraphNode * node = new GraphNode();
    node->vertex = i;
    NodeList.push_back(node);
  }
  int j;
  for(j = 0; j<edge_count; j++){
    int dot, neighbor;
    scanf("%d %d", &dot, &neighbor);
    NodeList[dot]->adjacency.push_back(neighbor);
    NodeList[neighbor]->adjacency.push_back(dot);
  }
  for(i = 0; i<NodeList.size(); i++){
    NodeList[i]->dump();
  }
  printf("\n");
  return 0;
}
*/
