#include <backpack.h>

int main(int argc, char **argv)
{
    backpack *pack;
    FILE *input, *output;
    input = openFile(argv[1], "rt");
    output = openFile(argv[2], "wt");
    pack = createBackpack(input);
    fclose(input);

    int finalP = 0, finalW = 0;
    BackTrack(pack, 0, &finalP, &finalW);
    fprintf(output, "maximum profit is %d\nand final weight is %d\n", finalP, finalW);

    pack->currentProfit = 0;
    pack->currentWeight = 0;
    fprintf(output, "\nAll possible optimal solutions are:\n");
    fprintf(output, "%s", DELIM);
    multipleSolution(pack, finalP, finalW, output);

    fclose(output);
    deleteBackpack(pack);
    return 0;
}
