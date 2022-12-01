#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#define DELIM "------------------------------------------------------------\n"

typedef struct element
{
    int g, p;
} element;

typedef struct backpack
{
    int gmax, N;
    int currentWeight;
    int currentProfit;
    element *objects;
} backpack;

backpack *createBackpack(FILE *);
void deleteBackpack(backpack *);
void swap(element *, element *);
float efficiency(element);
void printSolution(backpack *, int *, FILE *);
int partition(element *, int, int);
void quicksort(element *, int, int);
FILE *openFile(const char *, const char *);
bool isFull(backpack *, int);
int upperbound(backpack *, int);
void BackTrack(backpack *, int,  int *, int *);
void multipleSolution(backpack *, int, int, FILE *);
bool isSafe(backpack *, int, int *, int, int);