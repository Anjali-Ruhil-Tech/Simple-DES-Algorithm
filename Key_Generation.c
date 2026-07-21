#include <stdio.h>

#define KEY_SIZE 10
#define HALF_SIZE 5
#define SUBKEY_SIZE 8

// Prints a 10-bit array
void printArray(int arr[KEY_SIZE]) {
    for (int i = 0; i < KEY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
}

// Prints an 8-bit subkey
void printKey(int arr[SUBKEY_SIZE]) {
    for (int i = 0; i < SUBKEY_SIZE; i++) {
        printf("%d ", arr[i]);
    }
}

// Applies the P8 permutation to generate an 8-bit subkey
void applyP8(int arr[SUBKEY_SIZE], int arr1[KEY_SIZE]) {
    arr[0] = arr1[5];
    arr[1] = arr1[2];
    arr[2] = arr1[6];
    arr[3] = arr1[3];
    arr[4] = arr1[7];
    arr[5] = arr1[4];
    arr[6] = arr1[9];
    arr[7] = arr1[8];
}

// Applies the P10 permutation to the original 10-bit key
void applyP10(int arr[KEY_SIZE], int arr1[KEY_SIZE]) {
    arr[0] = arr1[2];
    arr[1] = arr1[4];
    arr[2] = arr1[1];
    arr[3] = arr1[6];
    arr[4] = arr1[3];
    arr[5] = arr1[9];
    arr[6] = arr1[0];
    arr[7] = arr1[8];
    arr[8] = arr1[7];
    arr[9] = arr1[5];
}

int main() {

    // Stores the original key entered by the user
    int originalkey[KEY_SIZE];

    // Stores the key after applying P10
    int newkey[KEY_SIZE];

    // Left and right halves of the key
    int left_half[HALF_SIZE];
    int right_half[HALF_SIZE];

    // Arrays after the first left shift (LS1)
    int left_shift1[HALF_SIZE];
    int right_shift1[HALF_SIZE];

    // Combined key after LS1
    int newarr[KEY_SIZE];

    // First generated subkey
    int key1[SUBKEY_SIZE];

    // Arrays after the second left shift (LS2)
    int left_shift2[HALF_SIZE];
    int right_shift2[HALF_SIZE];

    // Combined key after LS2
    int newarr1[KEY_SIZE];

    // Second generated subkey
    int key2[SUBKEY_SIZE];

    // Read the original 10-bit key
    printf("Enter 10 bits (0 or 1): ");

    for (int i = 0; i < KEY_SIZE; i++) {
        scanf("%d", &originalkey[i]);
    }

    // Apply P10 permutation
    applyP10(newkey, originalkey);

    printf("\nNew key after applying P10: ");
    printArray(newkey);

    // Divide the key into left and right halves
    printf("\n\nLeft half values: ");
    for (int i = 0; i < HALF_SIZE; i++) {
        left_half[i] = newkey[i];
        printf("%d ", left_half[i]);
    }

    printf("\nRight half values: ");
    for (int i = 0; i < HALF_SIZE; i++) {
        right_half[i] = newkey[i + HALF_SIZE];
        printf("%d ", right_half[i]);
    }

    // Perform LS1 on the left half
    left_shift1[0] = left_half[1];
    left_shift1[1] = left_half[2];
    left_shift1[2] = left_half[3];
    left_shift1[3] = left_half[4];
    left_shift1[4] = left_half[0];

    printf("\n\nAfter LS1 (Left Half): ");
    for (int i = 0; i < HALF_SIZE; i++) {
        printf("%d ", left_shift1[i]);
    }

    // Perform LS1 on the right half
    right_shift1[0] = right_half[1];
    right_shift1[1] = right_half[2];
    right_shift1[2] = right_half[3];
    right_shift1[3] = right_half[4];
    right_shift1[4] = right_half[0];

    printf("\nAfter LS1 (Right Half): ");
    for (int i = 0; i < HALF_SIZE; i++) {
        printf("%d ", right_shift1[i]);
    }

    // Combine both halves after LS1
    for (int i = 0; i < HALF_SIZE; i++) {
        newarr[i] = left_shift1[i];
    }

    for (int i = 0; i < HALF_SIZE; i++) {
        newarr[i + HALF_SIZE] = right_shift1[i];
    }

    printf("\n\nKey After LS1: ");
    printArray(newarr);

    // Apply P8 to generate Key1
    applyP8(key1, newarr);

    printf("\nKey1: ");
    printKey(key1);

    // Perform LS2 on the LS1 result (shift by two more positions)
    left_shift2[0] = left_shift1[2];
    left_shift2[1] = left_shift1[3];
    left_shift2[2] = left_shift1[4];
    left_shift2[3] = left_shift1[0];
    left_shift2[4] = left_shift1[1];

    printf("\n\nAfter LS2 (Left Half): ");
    for (int i = 0; i < HALF_SIZE; i++) {
        printf("%d ", left_shift2[i]);
    }

    right_shift2[0] = right_shift1[2];
    right_shift2[1] = right_shift1[3];
    right_shift2[2] = right_shift1[4];
    right_shift2[3] = right_shift1[0];
    right_shift2[4] = right_shift1[1];

    printf("\nAfter LS2 (Right Half): ");
    for (int i = 0; i < HALF_SIZE; i++) {
        printf("%d ", right_shift2[i]);
    }

    // Combine both halves after LS2
    for (int i = 0; i < HALF_SIZE; i++) {
        newarr1[i] = left_shift2[i];
    }

    for (int i = 0; i < HALF_SIZE; i++) {
        newarr1[i + HALF_SIZE] = right_shift2[i];
    }

    printf("\n\nKey After LS2: ");
    printArray(newarr1);

    // Apply P8 to generate Key2
    applyP8(key2, newarr1);

    printf("\nKey2: ");
    printKey(key2);
   
    printf("\n");
    
    return 0;
}