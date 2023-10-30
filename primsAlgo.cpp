#include <iostream>
#include <vector>
#include <queue> 
#include <functional> 
using namespace std;

typedef pair<int, int> Pair; 
const int numVertices = 4; 
vector <bool> visitedVertex(numVertices, false);

void createAndAddEdge(vector <Pair> adjList[], int u, int weight, int v){
  adjList[u].push_back(make_pair(weight, v));
  adjList[v].push_back(make_pair(weight, u)); 
} 

void PrimsAlgorithm(vector <Pair> adjList[], int source){
  priority_queue<Pair, vector<Pair>, greater<Pair> > PQ; 
  Pair info;
  int minCost = 0;
  PQ.push(make_pair(0, source)); 
  while (!PQ.empty()){
    info = PQ.top(); 
    source = info.second; 
    PQ.pop(); 
    if (visitedVertex.at(source)) 
      continue; 
    visitedVertex.at(source) = true; 
    cout << "Mark vertex " << info.second << " and add weight " << info.first << endl;
    minCost += info.first;
    for (vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++) 
      if (!visitedVertex.at(it->second)) 
        PQ.push(make_pair(it->first, it->second));
  } 
   cout << "Minimum cost to connect all vertices : " << minCost << endl;
} 

int main (void){
  
  int source = 0;
  vector<Pair> adjList[numVertices]; 
  createAndAddEdge(adjList, 0, 1, 1);
  createAndAddEdge(adjList, 0, 2, 3);
  createAndAddEdge(adjList, 1, 4, 2);
  createAndAddEdge(adjList, 1, 3, 3);
  createAndAddEdge(adjList, 2, 5, 3);
  PrimsAlgorithm(adjList, source); 
  // Minimum Cost should be 7;
    return 0;
} 