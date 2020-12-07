#include<iostream>
using namespace std;

class UpperTriRow {
    private:
        int *A;
        int n;
    public:
        UpperTriRow() {
            int n = 2;
            A = new int[2 * (2 + 1) / 2];
        }
        UpperTriRow(int n) {
            this -> n = n;
            A = new int[n * (n + 1) / 2];
        }
        ~UpperTriRow() {
            delete []A;
        }
        void set(int i, int j, int x);
        int get(int i, int j);
        void display();
};

void UpperTriRow :: set(int i, int j, int x) {
    if(i <= j)
        A[(n * (i - 1) - (i - 2) * (i - 1) / 2) + j - i] = x;
}

int UpperTriRow :: get(int i, int j) {
    if(i <= j)
        return A[(n * (i - 1) - (i - 2) * (i - 1) / 2) + j - i];
    return 0;
}

void UpperTriRow :: display() {
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            if(i <= j)
                cout << A[(n * (i - 1) - (i - 2) * (i - 1) / 2) + j - i] << " ";
            else
                cout << "0 ";
        }
        cout << endl;
    }
}

int main() {
    int d;
    cout << "Enter dimensions - ";
    cin >> d;
    
    int x; 
    UpperTriRow um(d);
    cout << "Enter all the elements" << endl;
    for(int i = 1; i <= d; i++) {
        for(int j = 1; j <= d; j++) {
            cin >> x;
            um.set(i,j,x);
        }
    }

    um.display();

    return 0;
}