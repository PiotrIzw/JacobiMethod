#include <iostream>
#include <fstream>
#include <cstdlib>
#include <string>
using namespace std;
const int SIZE = 100;

class JacobiMethod {
private:
	float a[SIZE][SIZE], x[SIZE], b[SIZE], c[SIZE];
	int n, liczba_iteracji;
	void loadData(string filename);
public:
	void calculate(string file);
	void showMatrix(float arr[SIZE][SIZE]);
	void showB(float arr[SIZE]);
};


void JacobiMethod::loadData(string filename) {
	ifstream file{ filename };
	if (file.is_open()) {
		file >> n;

		for (int i = 0; i < n; i++) {

			for (int j = 0; j < n; j++) {

				file >> a[i][j];
				if (j == n - 1) {
					file >> b[i];
				}
			}
		}
		file >> liczba_iteracji;
	}
	cout << "Value of n: " << n << endl;
	cout << "Number of iterations: " << liczba_iteracji << endl;
	cout << "Matrix a: " << endl;
	showMatrix(a);
	cout << "Values of B: " << endl;
	showB(b);
}

void JacobiMethod::calculate(string file) {

	loadData(file);
	int m = 0;
	while (m < liczba_iteracji) {
		for (int i = 0; i < n; i++) {
			c[i] = b[i];
			for (int j = 0; j < n; j++) {
				if (i != j) {
					c[i] = c[i] - a[i][j] * x[j];
				}
			}
		}
		for (int i = 0; i < n; i++) {
			x[i] = c[i] / a[i][i];
		}
		m++;
	}
	cout << "Final Solution:" << endl;
	for (int i = 0; i < n; i++) {
		cout << "x(" << i << ") = " << x[i] << endl;
	}
	cout << "Number of used iterations: " << m << endl;
}

void JacobiMethod::showMatrix(float arr[SIZE][SIZE]) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << arr[i][j] << "\t";
		}
		cout << endl;
	}
	cout << endl;
}

void JacobiMethod::showB(float arr[SIZE]) {
	for (int i = 0; i < n; i++) {
		cout << arr[i] << "\t";
	}
	cout << endl;

}

int main()
{
	JacobiMethod test;
	string file = "input20pkt.txt";
	test.calculate(file);
}