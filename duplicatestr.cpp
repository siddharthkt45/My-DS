#include<iostream>
using namespace std;

int main() {
    char a[] = "finding";

    int n = sizeof(a)/ sizeof(a[0]);
    int i, j;
    char lastduplicate = '\0';

    for (i = 0; i < n-1; i++) {

        for (j = i+1; j < n; j++) {

            if (a[i] == a[j] && a[i] != lastduplicate) {
                cout << a[i] << endl;
                a[j] = 0;
                lastduplicate = a[i];
            }

        }
        
    }
    return 0;
}