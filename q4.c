#include <stdio.h>

int main()
{
    double SP = 67836.43;
    double RJ = 36678.66;
    double MG = 29229.88;
    double ES = 27165.48;
    double Outros = 19849.53;

    double total = SP + RJ + MG + ES + Outros;

    printf("Percentual de SP: %.2f%%\n", (SP / total) * 100);
    printf("Percentual de RJ: %.2f%%\n", (RJ / total) * 100);
    printf("Percentual de MG: %.2f%%\n", (MG / total) * 100);
    printf("Percentual de ES: %.2f%%\n", (ES / total) * 100);
    printf("Percentual de Outros: %.2f%%\n", (Outros / total) * 100);

    return 0;
}
