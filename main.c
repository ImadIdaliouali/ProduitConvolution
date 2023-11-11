#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "matrice.h"

int main()
{
    srand(time(0));

    int t1 = 7;
    int **matrice = get_random_matrice(t1);
    print_matrice(matrice, t1);

    int t2 = 3;
    int **filtre = get_random_matrice(t2);
    print_matrice(filtre, t2);

    int **convolution = conv_matrices(matrice, t1, filtre, t2);
    print_matrice(convolution, t1);
    return 0;
}
