#include<iostream>
using namespace std;

int main() {
    char a[] = "madam";
    int i, j;

    for(j = 0; a[j] != '\0'; j++) {
        
    }
    j = j - 1;
    i = 0;

    while (i < j) {
        if(a[i] == a[j]) {
            i++;
            j--;
            continue;
        } else {
            cout << "not palindrome";
            break;
        }
    }
    return 0;
}
