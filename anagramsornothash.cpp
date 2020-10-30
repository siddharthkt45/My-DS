#include<iostream>
using namespace std;

int main() {
    char A[] = "verbosee";
    char B[] = "observe";
    int H[26] = {0}, i, j;

    for (i = 0; A[i] != '\0'; i++) {}
    for (j = 0; B[j] != '\0'; j++) {}

    if (i != j)
    {
        cout << "Not Anagrams" << endl;
    }
    else
    {
        for (i = 0; A[i] != '\0'; i++)
        {
            H[A[i] - 97]++;
        }

        for (i = 0; B[i] != '\0'; i++)
        {
            H[B[i] - 97]--;
            if (H[B[i] - 97] < 0)
            {
                cout << "Not anagrams" << endl;
                break;
            }
        }

        if (B[i] == '\0')
        {
            cout << "Anagrams" << endl;
        }
    }
    return 0;
}