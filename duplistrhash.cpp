// This code is only for lower case alphabets till now
// We also do have to add the code for upper case letters

#include<iostream>
using namespace std;

int main() {
    char A[] = "finding";
    int H[26], i;

    for(i = 0; i < 26; i++) {
        H[i] = 0;
    }

    for(i = 0; A[i] != '\0'; i++) {
        H[A[i] - 97]++;
    }

    for(i = 0; i < 26; i++) {
        if(H[i] > 1) {
            printf("The alphabet %c has occured %d times\n", i+97, H[i]);
        }
    }

    return 0;
}