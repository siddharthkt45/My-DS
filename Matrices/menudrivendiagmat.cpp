#include<iostream>
using namespace std;

class Diagonal {
    private:
        int *A, n;
        Diagonal(int n);
        void create();
        int get(int i, int j);
        void set(int i, int j, int x);
        void display();
        ~Diagonal();
};

Diagonal::Diagonal(int n) {
    this -> n = n;
    A = new int[n];
}

Diagonal::~Diagonal() {
    delete []A;
}

void Diagonal::create() {
    int x;
    for(i = 1; i <= n; i++) {
        for(j = 1; j <= n; j++) {
            cout << "Enter the element to insert: ";
            cin >> x;
            if(i == j)
                A[i-1] = x;
            // for Lower Triangular matrix
            // if(i >= j)
            //     A[i * (i-1)/2 + j-1] = x;
            // for Lower Triangular matrix
            // A[(i-1)*n-((i-2)*(i-1))/2+j-i] = x;
        }
    }
}

void Diagonal::display() {
    for (i = 1; i <= n; i++)
    {
        for (j = 1; j <= n; j++)
        {
            if (i == j)
                cout << A[i-1] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}
void main() {
    int *A, n, ch, x, i, j;
    cout << "Enter Dimensions: ";
    cin >> n;
    A = new int[n];
    // for Lower & Upper Triangular matrix, you should write
    // A = new int[n*(n+1)/2];

    do {
        cout << "1. Create\n
                 2. Get\n
                 3. Set\n
                 4. Display\n";

        switch (ch) {
            case 1:
                for (i = 1; i <= n; i++)
                    cin >> A[i-1];
                
                break;
            case 2:
                cout << "Enter indices: ";
                cin >> i >> j;
                
                if (i == j)
                    cout << A[i-1];
                else
                    cout << "0";

                break;
            case 3:
                cout << "Enter row, column and element";
                cin >> i >> j >> x;

                if (i == j)
                    A[i-1] = x;

                break;
            case 4:
                for (i = 1; i <= n; i++) {
                    for (j = 1; j <= n; j++) {
                        if (i == j) {
                            cout << A[i-1] << " ";
                        } 
                        else {
                            cout << "0 ";
                        }
                    }
                    cout << endl;
                }

                break;
        }
    } while ();
}

int get(int X[], int i, int j) {

}

void set(int X[], int i, int j, int x) {

}