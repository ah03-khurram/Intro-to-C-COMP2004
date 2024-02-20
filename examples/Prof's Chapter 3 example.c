#include <stdio.h>
#include <stdlib.h>

float getCircleArea(float radius) {
    float area = 3.14159 * radius * radius;
    return area;
}

float getCylinderVolume(float radius, float height) {
    float baseArea = getCircleArea(radius);
    float volume = baseArea * height;

    // create a stack array of size 5
    int stackArray[5] = {1, 2, 3, 4, 5};

    // create a heap array of size 5
    int* heapArray = (int*)malloc(5 * sizeof(int));

    // initialize the heap array
    for (int i = 0; i < 5; i++) {
        heapArray[i] = i;
    }

    // free the heap array
    free(heapArray);

    return volume;
}

int* getNumbersSquared(int n) {
    int* heapArray = (int*)malloc(n * sizeof(int));

    for (int i = 0; i < n; i++) {
        heapArray[i] = (i + 1) * (i + 1);
    }

    return heapArray;
}

void getNumbersCubed(int n, int* stackArray) { // Pass the array as an argument
    for (int i = 0; i < n; i++) {
        stackArray[i] = (i + 1) * (i + 1) * (i + 1);
    }
}


int main() {
    
    float radius = 3;
    float height = 5;

    float volume = getCylinderVolume(radius, height);
    printf("Volume: %.2f\n", volume);

    int* squaredNumbers = getNumbersSquared(5);
    for (int i = 0; i < 5; i++) {
        printf("%d\t", squaredNumbers[i]);
    }

    printf("\n");

    int cubedNumbers[5]; // Declare the array in main
    getNumbersCubed(5, cubedNumbers); // Pass the array to the function
    for (int i = 0; i < 5; i++) {
        printf("%d\t", cubedNumbers[i]);
    }

    return 0;
}



// int* getNumbersCubed(int n) {
//     int stackArray[n];

//     for (int i = 0; i < n; i++) {
//         stackArray[i] = (i + 1) * (i + 1) * (i + 1);
//     }

//     return stackArray;
// }


    // int* cubedNumbers = getNumbersCubed(5);
    // for (int i = 0; i < 5; i++) {
    //     printf("%d\t", cubedNumbers[i]);
    // }