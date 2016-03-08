#include <stdio.h>


#define INFINITY ((1 << (sizeof(int)*8-2))-1)

typedef struct _Edge {
    int source;
    int dest;
    int weight;
} Edge;


int main() {
    int i, j, nodecount, edgecount;
    int source;

    for(i = 0; i < nodecount; i++) {
        if(i == source)
            distance[i] = 0;
        else
            distance[i] = INFINITY;
    }

    for(i = 0; i < nodecount; i++) {
        for(j = 0; j < edgecount; j++) {
            /*
             * Note that INFINITY is actually a finite number in this code, so because of overflow
             * "distance[edges[j].source] + edges[j].weight" can be a very small number,
             * in fact smaller than "distance[edges[j].dest]".
             *
             * One solution is to skip the following if-statement,
             * if "distance[edges[j].source]" == INFINITY
             */
            if(distance[edges[j].dest] > distance[edges[j].source] + edges[j].weight) {
                distance[edges[j].dest] = distance[edges[j].source] + edges[j].weight;
            }
        }
    }

    for(i = 0; i < edgecount; i++) {
        if(distance[edges[i].dest] > distance[edges[i].source] + edges[i].weight) {
            printf("Error occured. Negative edge weight cycles detected");
            break;
        }
    }

    for(i = 0; i < nodecount; i++) {
        printf("The shortest distance between nodes %i and %i is %i\n", source, i, distance[i]);
    }

    return 0;
}
