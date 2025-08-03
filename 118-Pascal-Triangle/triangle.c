#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <errno.h>


int** generate(int numRows, int* returnSize, int** returnColumnSizes) {
    int * columnSize = calloc(numRows, sizeof(int));
    int ** triangle = calloc(numRows, sizeof(int *));
    int i = 0;
    int j = 0;

    for (i = 0; i < numRows; i++){
        columnSize[i] = i+1;
        triangle[i] = calloc(columnSize[i], sizeof(int));
        for (j = 0; j < columnSize[i]; j++){
            if (j == 0){
                triangle[i][j] = 1;
            } else {
                triangle[i][j] = (triangle[i][j-1] * columnSize[i-j]) / j;
            }
        }
    }

    *returnSize = numRows;
    returnColumnSizes = &columnSize;

    return triangle; 
}

void print_usage(char * argv[]){
    printf("Usage: %s -n <Number-of-Rows>\n", argv[0]);
    printf("Example: %s -n 10\n", argv[0]);
}

int main(int argc, char *argv[]){
    int returnSize = 0;
    int c = 0;
    char * numRowsChar = NULL;
    int numRows = 0;

    while ((c = getopt(argc,argv,"n:")) != -1){
        switch (c){
            case 'n':
                numRowsChar = optarg;
                break;
            case '?':
                break;

            default:
                return -1;
        }
    }
   
    if (numRowsChar){
        char * endptr = NULL;
        errno = 0;
        numRows = strtol(numRowsChar, &endptr, 10);
        int i = 0;
        int j = 0;

        // Checking Errors
        if (errno != 0){
            perror("strtol");
            exit(EXIT_FAILURE);
        }

        int * columnSize = calloc(numRows, sizeof(int)); // Must be freed later;
        int ** triangle = calloc(numRows, sizeof(int *)); // Must be freed later;
   
        triangle = generate(numRows, &returnSize, &columnSize);

        for (i = 0; i < numRows; i++){
            columnSize[i] = i+1;
            printf("\n");
            for (j = 0; j < columnSize[i]; j++){
                printf("%d | ", triangle[i][j]);
            }
        }          
        printf("\n");

        // Freeing Memory
        free(columnSize);
        for (i = 0; i < returnSize; i++){
            free(triangle[i]);
        }
        free(triangle);        
        numRowsChar = NULL;
        endptr = NULL;

    } else {
        print_usage(argv);
        return 0;
    }

    return 0;
}
