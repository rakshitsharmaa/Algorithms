#include <iostream>
#include <vector>
#include <queue> 
#include <functional>
using namespace std;

typedef pair<int, int> Pair; 
const int numVertices = 6; 
vector <bool> visitedVertex(numVertices, false);
int ShortestPath[numVertices]; 

void createAndAddEdge(vector <Pair> adjList[], int u, int weight, int v){
  adjList[u].push_back(make_pair(weight, v));
}

void DijkstrasAlgorithm(vector <Pair> adjList[], int source){
  priority_queue<Pair, vector<Pair>, greater<Pair> > PQ; 
  Pair info;
  int weight;
  ShortestPath[source] = 0; 

  for (int i = 0; i < numVertices; i++)
    if (i != source)
      ShortestPath[i] = 100000; 

  PQ.push(make_pair(0, source)); 

  while (!PQ.empty()){
    info = PQ.top(); 
    PQ.pop(); 
    source = info.second; 
    weight = info.first; 

    if (visitedVertex.at(source)) 
      continue; 

    visitedVertex.at(source) = true; 

    for (vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
       if ((weight + (it->first)) < ShortestPath[it->second]){ 
         ShortestPath[it->second] = weight + (it->first); 
         PQ.push(make_pair(ShortestPath[it->second], it->second)); 
       }
  } 
} 


int main (void){

  int source = 0;
  vector<Pair> adjList[numVertices]; 
  createAndAddEdge(adjList, 0, 5, 1);
  createAndAddEdge(adjList, 0, 10, 3);
  createAndAddEdge(adjList, 1, 2, 2);
  createAndAddEdge(adjList, 1, 10, 5);
  createAndAddEdge(adjList, 1, 5, 4);
  createAndAddEdge(adjList, 2, 1, 3);
  createAndAddEdge(adjList, 2, 5, 4);
  createAndAddEdge(adjList, 2, 3, 0);
  createAndAddEdge(adjList, 4, 2, 5);
  DijkstrasAlgorithm(adjList, source);

  cout << "Shortest path from source vertex " << source << ": ";
  for (int i = 0; i < numVertices; i++)
    cout << ShortestPath[i] << " ";
  cout << endl;

} 