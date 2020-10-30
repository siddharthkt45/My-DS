#include<iostream>
using namespace std;

int main() {

    char A[] = "madam";
    char B[6];

    int i, j;
    for (j = 0; A[j] != '\0'; j++) {
        continue;
    }
    j = j - 1;

    for (i = 0; j >= 0; i++) {
        B[i] = A[j];
        j--;
    }

    for (i = 0; A[i] != '\0'; i++)
    {
        if(A[i] != B[i]) {
            cout << "not palindrome" << endl;
            break;
        } else {
            continue;
        }
    }
    return 0;
}