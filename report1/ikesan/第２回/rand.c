#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void shuffle(int array[], int size, double probability);

int main(int argc, char *argv[]) {

    int values[1024];
    int k;
    int size = sizeof(values) / sizeof(int);
    double probability = atof(argv[1]) / 100;
    
    for ( k = 0; k < 1024; k++ ) {
        values[k]=k;
    }
    
    shuffle(values, size, probability);

    printf("%d\n", size);
    for (int i = 0; i < size; i++) {
        printf("%d ", values[i]);
    }
    printf("\n");
    return 0;
}

void shuffle(int array[], int size, double probability) {

    int i = size;

    srand(time(NULL));

    while (i > 1) {
        if ((double)rand()/RAND_MAX < probability) {
            srand(time(NULL));
            int j = rand() % i;
            i--;
            int t = array[i];
            array[i] = array[j];
            array[j] = t;
        } else {
            i--;
        }
    }
}