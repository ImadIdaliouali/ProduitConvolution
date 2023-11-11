int **reserve_memoire(int n)
{
    int **matrice = (int **)malloc(n * sizeof(int *));
    int **p, *q;
    for (p = matrice; p < matrice + n; p++)
        *p = (int *)malloc(n * sizeof(int));
    return matrice;
}

int **get_random_matrice(int n)
{
    int **matrice = reserve_memoire(n);
    int **p, *q;
    for (p = matrice; p < matrice + n; p++)
    {
        for (q = *p; q < *p + n; q++)
            *q = rand() % 10;
    }
    return matrice;
}

void print_matrice(int **matrice, int n)
{
    int **p, *q;
    printf("----------------------------\n");
    for (p = matrice; p < matrice + n; p++)
    {
        for (q = *p; q < *p + n; q++)
            printf("%d ", *q);
        printf("\n");
    }
}

int trace_matrice(int **matrice, int n)
{
    int i, trace = 0;
    for (i = 0; i < n; i++)
        trace += matrice[i][i];
    return trace;
}

int **conv_matrices(int **A, int n, int **B, int m)
{
    int **C = reserve_memoire(n);
    int i, j, k, l;
    int milieu = (m - 1) / 2;
    int x, y;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            C[i][j] = 0;
            for (k = 0; k < m; k++)
            {
                for (l = 0; l < m; l++)
                {
                    x = i + k - milieu;
                    y = j + l - milieu;
                    if (x < 0 || x >= n || y < 0 || y >= n)
                        continue;
                    C[i][j] += A[x][y] * B[k][l];
                }
            }
        }
    }
    return C;
}
