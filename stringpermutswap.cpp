#include<iostream>
using namespace std;

void perm(char s[], int l, int h) {
    int i;
    if(l == h) {
        printf("%s\n", s);
    } else {
        for(i = l; i <= h; i++) {
            swap(s[l], s[i]);
            perm(s, l+1, h);
            swap(s[i], s[l]);
        }
    }
}

void swap(char a, char b) {
    char temp = a;
    a = b;
    b = temp;
}

int main() {
    char s[] = "ABC";
    perm(s, 0, 2);
    return 0;
}