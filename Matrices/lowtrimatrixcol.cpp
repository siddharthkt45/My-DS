#include<iostream>
using namespace std;

class LowerTriangularCol {
    private:
        int *A;
        int n;
    public:
        LowerTriangularCol() {
            n = 2;
            A = new int[2*(2+1)/2];
        }
        LowerTriangularCol(int n) {
            this -> n = n;
            A = new int[n*(n+1)/2];
        }
        ~LowerTriangularCol() {
            delete []A;
        }

        void set(int i, int j, int x);
        int get(int i, int j);
        void Display();
        int getDimension() { return n; }
};

void LowerTriangularCol :: set(int i, int j, int x) {
    if(i >= j) {
        A[(n * (j - 1) - (j - 1) * (j - 2) / 2) + (i - j)] = x;
    }
}

int LowerTriangularCol :: get(int i, int j) {
    if(i >= j)
        return A[(n * (j - 1) - (j - 1) * (j - 2) / 2) + (i - j)];
    return 0;
}

void LowerTriangularCol :: Display() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i >= j) {
                cout << A[(n * (j - 1) - (j - 1) * (j - 2) / 2) + (i - j)] << " ";
            } else {
                cout << "0 ";
            }
        }
        cout << endl;
    }
}

int main() {
    int d;
    cout << "Enter Dimensions - ";
    cin >> d;

    LowerTriangularCol lm(d);

    int x;
    cout << "Enter all elements" << endl;
    for(int i = 1; i <= d; i++) {
        for(int j = 1; j <= d; j++) {
            cin >> x;
            lm.set(i,j,x);
        }
    }

    lm.Display();

    return 0;
}