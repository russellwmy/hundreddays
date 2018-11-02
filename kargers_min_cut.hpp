
#include <iostream>
#include <stdlib.h>
#include <time.h>

struct Edge
{
  int src, dest;
};

struct Graph
{
  int V, E;
  Edge *edge;
};

struct subset
{
  int parent;
  int rank;
};

int find(struct subset subsets[], int i);
void Union(struct subset subsets[], int x, int y);

int karger_min_cut(struct Graph *graph)
{
  int V = graph->V, E = graph->E;
  Edge *edge = graph->edge;

  struct subset *subsets = new subset[V];

  for (int v = 0; v < V; ++v)
  {
    subsets[v].parent = v;
    subsets[v].rank = 0;
  }

  int vertices = V;

  while (vertices > 2)
  {
    int i = rand() % E;

    int subset1 = find(subsets, edge[i].src);
    int subset2 = find(subsets, edge[i].dest);

    if (subset1 == subset2)
      continue;

    else
    {
      printf("Contracting edge %d-%d\n",
             edge[i].src, edge[i].dest);
      vertices--;
      Union(subsets, subset1, subset2);
    }
  }

  int cutedges = 0;
  for (int i = 0; i < E; i++)
  {
    int subset1 = find(subsets, edge[i].src);
    int subset2 = find(subsets, edge[i].dest);
    if (subset1 != subset2)
      cutedges++;
  }

  return cutedges;
}

int find(struct subset subsets[], int i)
{
  if (subsets[i].parent != i)
    subsets[i].parent =
        find(subsets, subsets[i].parent);

  return subsets[i].parent;
}

void Union(struct subset subsets[], int x, int y)
{
  int xroot = find(subsets, x);
  int yroot = find(subsets, y);

  if (subsets[xroot].rank < subsets[yroot].rank)
    subsets[xroot].parent = yroot;
  else if (subsets[xroot].rank > subsets[yroot].rank)
    subsets[yroot].parent = xroot;

  else
  {
    subsets[yroot].parent = xroot;
    subsets[xroot].rank++;
  }
}

struct Graph *create_graph(int V, int E)
{
  Graph *graph = new Graph;
  graph->V = V;
  graph->E = E;
  graph->edge = new Edge[E];
  return graph;
}