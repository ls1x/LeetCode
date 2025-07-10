#include <stdio.h>
#include <getopt.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

int findLucky(int* arr, int arrSize) {
    int freq[501] = {0};
    int diffNums[501] = {0};
    int i = 0;
    int j = 0;
    int k = 0;
    int luckyNum = -1;

    // Original Array.
    printf("Array Orig: ");
    for (i = 0; i < arrSize; i++){
        printf("%d ", arr[i]);   
    }

    // Different numbers inside original array.
    diffNums[0] = arr[0];
    j = 0;
    for (i = 0; i < arrSize; i++){
        while (arr[i] == diffNums[j]){
            if (i == arrSize - 1){
                break;
            }
            i++;
        }
        if (arr[i] != diffNums[j]){
            j = 0;
            while (diffNums[j] != arr[i]){
                if (diffNums[j] == 0){
                    diffNums[j] = arr[i];
                    break;
                }
                if (diffNums[j] == arr[i]){
                    break;
                }
                j++;
            }
        }
    }

    // Printing different nums:
    printf("\nDifferent Nums: ");
    i = 0;
    while (diffNums[i] != 0){
        printf("%d ", diffNums[i]);
        i++;
    }

    // Frequency of each different number.
    j = 0;
    for (i = 0; i < arrSize; i++){
        j = 0;
        while (diffNums[j] != arr[i]){
             j++;
        }
        if (diffNums[j] == arr[i]){
            freq[j]++;
        }
    }

    // Printing the frequency of each number.
    i = 0;
    printf("\nFrequency Arr: ");
    while (freq[i] != 0){
        printf("%d ", freq[i]);
        i++;
    }

    // Finding the Lucky Number
    i = 0;
    while (diffNums[i] != 0 && freq[i] != 0){
        printf("\nNum: %d | Frequency: %d ",diffNums[i], freq[i]);
        if (diffNums[i] == freq[i]){
            if (diffNums[i] > luckyNum){
                luckyNum = diffNums[i];
            }
        }
        i++;
    }

    printf("\nLucky Number: %d\n", luckyNum);
    return luckyNum;
}

void print_usage(char * argv[]){
    printf("Usage: %s -n <Numbers> -s <NumSize>\n", argv[0]);
    printf("Example: %s -n 1,2,2,3,3,3,4 -s 7\n", argv[0]);
}

int main (int argc, char * argv[]){
    int c;
    int i = 0;
    char * arrChar = NULL;
    char * arrSizeChar = NULL;
    char * endptr = NULL;
    char * arrChar_strtoked = NULL;
    int arrSize = 0;

    while ((c = getopt(argc,argv,"n:s:")) != -1){
        switch (c){
            case 'n':
                arrChar = optarg;
                break;
            case 's':
                arrSizeChar = optarg;
                break;
            case '?':
                break;

            default:
                return -1;
        }
    }

    if (arrChar && arrSizeChar){
        // String to Long - ArrSizeChar - arrSize
        errno = 0;
        arrSize = strtol(arrSizeChar, &endptr, 10);
        if (errno != 0){
            perror("strtol");
            exit(EXIT_FAILURE);
        }
        int * arr = calloc(arrSize, sizeof(int));
        
        // String to Long - arrChar - arr
        arr[0] = strtol(strtok(arrChar,","), &endptr, 10);
        if (errno != 0){
            perror("strtol");
            exit(EXIT_FAILURE);
        }

        for (i = 1; i < arrSize; i++){
            arr[i] = strtol(strtok(NULL,","), &endptr, 10);
            if (errno != 0){
                perror("strtol");
                exit(EXIT_FAILURE);
            }
        }
        int LuckyNumber = 0;
        LuckyNumber = findLucky(arr, arrSize);
        free(arr);
        arr = NULL;
        return 0;
    } else {
        printf("Number and NumSize are required arguments.\n");
        print_usage(argv);
        return 0;
    }
}
