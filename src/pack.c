#include <backpack.h>

backpack *createBackpack(FILE *input)
{
    backpack *pack = (backpack *)malloc(sizeof(backpack));
    int i;
    fscanf(input, "%d%d", &pack->gmax, &pack->N);
    pack->objects = (element *)malloc(pack->N * sizeof(element));
    pack->currentWeight = 0;
    pack->currentProfit = 0;
    if (pack->objects)
        for (i = 0; i < pack->N; i++)
            fscanf(input, "%d%d", &pack->objects[i].g, &pack->objects[i].p);
    else
    {
        printf("ERROR while allocating memory.\n");
        exit(1);
    }
    quicksort(pack->objects, 0, pack->N - 1);
    return pack;
}

/*
*   Afiseaza in output toate obiectele introduse integral in rucsac.
*/

void printSolution(backpack *pack, int *result, FILE *output)
{
    int i = 0;
    for (i = 0; i < pack->N; i++)
        if (result[i])
            fprintf(output, "(%d, %d)\n", pack->objects[i].g, pack->objects[i].p);
}

/*
*   Functia returneaza raportul profit-greutate unui obiect.
*/

float efficiency(element x)
{
    return (float)x.p / x.g;
}

/*
*   Eliberarea memoriei
*/

void deleteBackpack(backpack *pack)
{
    free(pack->objects);
    free(pack);
    pack = NULL;
}

/*
*   Deschide un fisier si returneaza un pointer catre fisier.
*/

FILE *openFile(const char *filename, const char *mode)
{
    FILE *file = fopen(filename, mode);
    if (!file)
    {
        printf("Fisierul <%s> nu a putut fi deschis!", filename);
        exit(1);
    }
    return file;
}