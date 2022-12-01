#include <backpack.h>

bool isFull(backpack *pack, int index)
{
    if (pack->currentWeight + pack->objects[index].g > pack->gmax)
        return true;
    else
        return false;
}

bool isSafe(backpack *pack, int k, int *temp, int optimalP, int optimalW)
{
    int j, p = 0, g = 0;
    for (j = 0; j <= k; j++)
        if (temp[j])
        {
            p += pack->objects[j].p;
            g += pack->objects[j].g;
        }
    if (p > optimalP || g > optimalW)
        return false;
    if ((k == pack->N - 1) && (p != optimalP || g != optimalW))
        return false;
    return true;
}

int upperbound(backpack *pack, int index)
{
    int i, p, g;
    p = pack->currentProfit;
    g = pack->currentWeight;
    for (i = index; i < pack->N; i++)
    {
        g += pack->objects[i].g;
        if (g < pack->gmax)
            p += pack->objects[i].p;
        else
            return (p + (g - pack->gmax) * efficiency(pack->objects[i]));
    }
    return p;
}

void BackTrack(backpack *pack, int k, int *finalP, int *finalW)
{
    if (!isFull(pack, k))
    {
        pack->currentProfit += pack->objects[k].p;
        pack->currentWeight += pack->objects[k].g;
        if (k < pack->N - 1)
            BackTrack(pack, k + 1, finalP, finalW);
        if (pack->currentProfit + pack->objects[k].p > *finalP && k == pack->N - 1)
        {
            *finalP = pack->currentProfit;
            *finalW = pack->currentWeight;
        }
    }
    if (upperbound(pack, k) >= *finalP)
    {
        if (k < pack->N - 1)
            BackTrack(pack, k + 1, finalP, finalW);
        if (pack->currentProfit > *finalP && k == pack->N - 1)
        {
            *finalP = pack->currentProfit;
            *finalW = pack->currentWeight;
        }
    }
}

void multipleSolution(backpack *pack, int optimalP, int optimalW, FILE *output)
{
    int j = 0;
    int *temp = (int *)calloc(pack->N, sizeof(int));
    temp[j] = -1;
    while (j > -1)
    {
        while (temp[j] < 1)
        {
            temp[j]++;
            if (isSafe(pack, j, temp, optimalP, optimalW))
            {
                if (j == pack->N - 1)
                {
                    printSolution(pack, temp, output);
                    fprintf(output, "%s", DELIM);
                }
                else
                    temp[++j] = -1;
            }
        }
        j--;
    }
    free(temp);
}
