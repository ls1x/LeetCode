#include <stdio.h>
#include <getopt.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int missingNumber(int* nums, int numsSize) {
    int i = 0;
    int total = numsSize;
    int current = 0;
    
    for (i = 0; i < numsSize; i++){
        total = i + total;
        current = nums[i] + current;
    }
    total = total - current;
    
    return total;
}

void print_usage(char *argv[]){
    printf("Usage: %s -n <Numbers> -s <NumsSize>\n", argv[0]);
    printf("Example: %s -n 1,2,3,5,6,7 -s 6\n", argv[0]);
}

int main (int argc, char * argv[]){
    int c;
    int result = 0;
    int numsSize = 0;
    char * numsChar = NULL;
    char * endptr = NULL;
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

    if (numsChar){
        numsSize = strtol(numsSizeChar, &endptr, 10);
        int * nums = calloc(numsSize, sizeof(int));
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
        result = missingNumber(nums, numsSize);
        free(nums);
        nums = NULL;
        printf("The missing number is: %d\n", result);
    } else {
        print_usage(argv);
        return 0;
    }
    
    return 0;
}
