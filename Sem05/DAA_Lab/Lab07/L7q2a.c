#include <stdio.h>
#include <stdlib.h>

typedef struct Edge {
  int u, v, weight;
} Edge;

typedef struct UnionFind {
  int *parent;
  int *size;
} UnionFind;

void union_find_init(UnionFind *uf, int n) {
  uf->parent = malloc(sizeof(int) * n);
  uf->size = malloc(sizeof(int) * n);
  for (int i = 0; i < n; i++) {
    uf->parent[i] = i;
    uf->size[i] = 1;
  }
}

int union_find_find(UnionFind *uf, int v) {
  if (uf->parent[v] == v) {
    return v;
  } else {
    return union_find_find(uf, uf->parent[v]);
  }
}

void union_find_union(UnionFind *uf, int u, int v) {
  int u_root = union_find_find(uf, u);
  int v_root = union_find_find(uf, v);

  if (uf->size[u_root] > uf->size[v_root]) {
    uf->parent[v_root] = u_root;
    uf->size[u_root] += uf->size[v_root];
  } else {
    uf->parent[u_root] = v_root;
    uf->size[v_root] += uf->size[u_root];
  }
}

int compare_edges(const void *p, const void *q) {
  Edge *e1 = (Edge *)p;
  Edge *e2 = (Edge *)q;
  return e1->weight - e2->weight;
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);

  Edge *edges = malloc(sizeof(Edge) * m);
  for (int i = 0; i < m; i++) {
    scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
  }

  // Sort the edges in increasing order of weight.
  qsort(edges, m, sizeof(Edge), compare_edges);

  // Initialize the union-find data structure.
  UnionFind uf;
  union_find_init(&uf, n);

  // Create the minimum spanning tree.
  int total_cost = 0;
  for (int i = 0; i < m; i++) {
    int u = edges[i].u;
    int v = edges[i].v;

    if (union_find_find(&uf, u) != union_find_find(&uf, v)) {
      total_cost += edges[i].weight;
      union_find_union(&uf, u, v);
    }
  }

  // Print the total cost of the minimum spanning tree.
  printf("%d\n", total_cost);

  // Free the allocated memory.
  free(edges);
  free(uf.parent);
  free(uf.size);

  return 0;
}
