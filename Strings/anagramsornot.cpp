#include<iostream>
using namespace std;

int main() {
    char A[] = "decimal";
    char B[] = "medical";
    int flag, i, j;

    for(i = 0; A[i] != '\0'; i++) {}
    for(j = 0; B[j] != '\0'; j++) {}

    if(i != j) {
        cout << "Not Anagrams" << endl;
    } else {
        for (i = 0; A[i] != '\0'; i++) {
            flag = 1;
            for (j = 0; B[j] != '\0'; j++) {
                if (A[i] == B[j]) {
                    flag = 1;
                    A[i] = 0;
                    B[j] = 0;
                    break;
                }
                else {
                    flag = 0;
                }
            }
        }

        if (flag == 0) {
            cout << "Not anagrams" << endl;
        }
        else {
            cout << "Anagrams" << endl;
        }
    }
    return 0;
}