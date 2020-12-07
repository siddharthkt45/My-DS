#include<iostream>
using namespace std;

class UpperTriCol {
    private:
        int *A;
        int n;
    public:
        UpperTriCol() {
            int n = 2;
            A = new int[2 * (2 + 1) / 2];
        }
        UpperTriCol(int n) {
            this -> n = n;
            A = new int[this];
        }
        ~UpperTriCol() {
            delete []A;
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};