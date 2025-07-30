#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int removeDuplicates(int* nums, int numsSize) {
    int pointer = 0;
    int i = 1;
    int j = 1;
    int differentNums = 1;
    int * nonDuplicatedNums = calloc(numsSize, sizeof(int));
    nonDuplicatedNums[0] = nums[0];

    while (i < numsSize){
        pointer = nums[i - 1];
        while (pointer == nums[i]){
            if (i == (numsSize -1)){
                break;
            }
            nums[i] = 0;
            i++;
        } 
        if (pointer != nums[i]) {
            nonDuplicatedNums[j] = nums[i];
            differentNums++;
            j++;
        }
        i++;
    }

    printf("\nUnique Numbers: ");
    for (i = 0; i < numsSize; i++){
        nums[i] = nonDuplicatedNums[i];
        printf("%d ", nums[i]);
    }

    free(nonDuplicatedNums);
    nonDuplicatedNums = NULL;

    return differentNums;
}

void print_usage(char * argv[]){
    printf("Usage: %s -n <Array-of-Numbers> -s <Size-of-array>\n", argv[0]);
    printf("Example: %s -n 0,1,1,2,2,2,3 -s 7\n", argv[0]);
}

int main (int argc, char * argv[]){
    int c = 0;
    char * numsChar = NULL;
    char * numsSizeChar = NULL;

    while ((c = getopt(argc,argv,"n:s:")) != -1){
        switch (c){
            case 'n':
                numsChar = optarg;
                break;
            case 's':
                numsSizeChar = optarg;
                break;
            case '?':
                break;
            
            default:
                return -1;
        }
    }

    if (numsChar && numsSizeChar){
        char *endptr = NULL;
        errno = 0;

        int numsSize = strtol(numsSizeChar, &endptr, 10);
        int * nums = calloc(numsSize, sizeof(int));

        if (errno != 0){
            perror("strtol");
            exit(EXIT_FAILURE);
        }

        for (int i = 0; i < numsSize; i++){
            if (i == 0){
                errno = 0;
                nums[i] = strtol(strtok(numsChar,","), &endptr, 10);
                if (errno != 0){
                    perror("strtol");
                    exit(EXIT_FAILURE);
                }
            } else {
                errno = 0;
                nums[i] = strtol(strtok(NULL,","), &endptr, 10);
                if (errno != 0){
                    perror("strtol");
                    exit(EXIT_FAILURE);
                }
            }
        }

        int return_value = removeDuplicates(nums, numsSize);
        printf("\nNumber of unique numbers in array: %d\n", return_value);
        return 0;

    } else {
        print_usage(argv);
        return 0;
    }
    
}
