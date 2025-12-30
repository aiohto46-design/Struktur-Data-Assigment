#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
using namespace std;

typedef char infoGraph;
typedef struct ElmNode *adrNode;
typedef struct ElmEdge *adrEdge;

struct ElmNode {
    infoGraph info;         // Menyimpan data node (misal: char/int)
    int visited;            // Penanda untuk traversal (0/1)
    adrEdge firstEdge;      // Pointer ke edge pertama yang terhubung
    adrNode Next;           // Pointer ke node berikutnya dalam graph
};

struct ElmEdge {
    adrNode Node;           // Pointer yang menunjuk ke lokasi node tujuan
    adrEdge Next;           // Pointer ke edge berikutnya
};

struct Graph {
    adrNode First;          // Pointer ke node pertama dalam list graph
};

void CreateGraph(Graph &G);                         // Set first = NULL
adrNode AlokasiNode(infoGraph data);                // Alokasi node baru
adrEdge AlokasiEdge(adrNode nodeTujuan);            // Alokasi edge baru

void InsertNode(Graph &G, infoGraph data);          // Menambahkan node
adrNode FindNode(Graph G, infoGraph data);         // Mencari node
void ConnectNode(Graph &G, infoGraph info1, infoGraph info2);                  // Menghubungkan node
void DisconnectNode(Graph &G, infoGraph info1, infoGraph info2);               // Memutus hubungan node
void DeleteNode(Graph &G, infoGraph X);             // Menghapus node dan edge

void PrintInfoGraph(Graph G);                       // Menampilkan adjacency list
void ResetVisited(Graph &G);                        // Reset visited
void PrintBFS(Graph G, infoGraph StartInfo);        // Traversal BFS
void PrintDFS(Graph G, infoGraph StartInfo);        // Traversal DFS

#endif