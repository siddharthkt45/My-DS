#include <iostream>
using namespace std;

class Diagonal {
private:
	int n;
	int *A;

public:
	Diagonal(int n) {
		this -> n = n;
		A = new int[n];
	}

	void set(int i, int j, int x);
	int get(int i, int j);
	void Display();

	~Diagonal() {
		delete []A;
	} // Destructor
};

void Diagonal :: set(int i,  int j, int x) {
	if(i == j)
		A[i-1] = x;
}

int Diagonal :: get(int i, int j) {
	if(i == j)
		return A[n-1];
	return 0;
}

void Diagonal :: Display() {
	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			if(i == j)
				cout << A[i-1] << " ";
			else
				cout << "0 ";
		}
		cout << endl;
	}
}

int main() {
	int n;
	cout << "Enter dimensions ";
	cin >> n;
	Diagonal dm(n);
	
	int x;
	cout << "Enter all elements";

	for(int i = 1; i <= n; i++) {
		for(int j = 1; j <= n; j++) {
			printf("\nfor i=%d & j=%d - ", i, j);
			cin >> x;
			dm.set(i, j, x);
		}
	}

	dm.Display();
	return 0;
}