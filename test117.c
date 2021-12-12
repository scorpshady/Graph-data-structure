#include<stdio.h>
#include<stdlib.h>

struct Node
{
	int data;
	struct Node* next;
};

struct Head
{
	struct Node* track;
};

struct Graph
{
	int V;
	struct Head* array;
};


struct Graph*  creategraph(int vertices)
{
	struct Graph* graph = (struct Graph*) malloc(sizeof(struct Graph));
	graph->V = vertices;
	graph->array = (struct Head*) malloc(vertices * sizeof(struct Head));

	int i;

	for(i = 0; i < vertices; i ++)
	{
		graph->array[i].track = NULL;
	}
	return graph;
}

//making for undirected graph
void addedge(struct Graph* graph , int src , int dest)
{
	struct Node* check = NULL;
	struct Node* nd = (struct Node*) malloc(sizeof(struct Node));
	nd->data = dest;
	nd->next = NULL;

	if(graph->array[src].track == NULL)
	{
		graph->array[src].track = nd;
	}
	else
	{
		check = graph->array[src].track;
		while(check->next != NULL)
		{
			check = check->next;
		}
		check->next = nd;
	}


	//since this is undirected graph so we will make directions from both side ie from src to dest and from dest to src
	struct Node* nd1 = (struct Node*) malloc(sizeof(struct Node));
	nd1->data = src;
	nd1->next = NULL;

	if(graph->array[dest].track == NULL)
	{
		graph->array[dest].track = nd1;
	}
	else
	{
		check = graph->array[dest].track;
		while(check->next != NULL)
		{
			check = check->next;
		}
		check->next = nd1;
	}
}

void printgraph(struct Graph* graph)
{
	int i;
	struct Node* check = NULL;
	for(i = 0; i < graph->V; i++)
	{
		printf("\nTrack[%d]", i);
		check = graph->array[i].track;
		while(check != NULL)
		{
			printf(" -> %d", check->data);
			check = check->next;
		}

	}
}


void main()
{
	
	int v = 5;
	
	struct Graph* graph = creategraph(v);
	
	 addedge(graph, 0, 1);
    addedge(graph, 0, 4);
    addedge(graph, 1, 2);
    addedge(graph, 1, 3);
    addedge(graph, 1, 4);
    addedge(graph, 2, 3);
    addedge(graph, 3, 4);
	
	printgraph(graph);
}

//done graph using adjacency list




