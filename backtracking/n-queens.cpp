#include <iostream>

using namespace std;

void printQ(int *,int);
bool poda(int*,int);
bool queen(int*,int,int,int &,int);

int main(int argc, char const *argv[]) {

	int n = 0; // space of the chessboard
	int m = 0; // max solutions to calculate
	int s = 0;

	cout << "Enter the size of the chessboard and the queens\n"
		 << "chessboard size: nxn, number of queens: n\n"
		 << "n: ";
	cin >> n;
	cout << "Enter the max number of solutions to calculate: ";
	cin >> m;

	int *queens = new int[n];
	for(int i = 0; i < n; i++)
		queens[i] = n;
	queen(queens,0,n,s,m);

	return 0;
}

bool queen(int * queens,int nQueen,int n,int & s, int m){
	if(nQueen == n){
		cout << " Solution " << s + 1 << ":" << endl;
		printQ(queens,n);
		s++;
		return true;
	}
	else{
		bool solucion = false;
		int columna = 0;
		while(columna < n && s < m){
			queens[nQueen] = columna;
			if(!poda(queens,nQueen))
				solucion = queen(queens,nQueen + 1, n,s,m);
			columna++;
		}
		return solucion;
	}
}

bool poda(int *queens,int nQueen){
	for(int j = 0; j < nQueen; j++)
		if(queens[j] == queens[nQueen] || nQueen - j == abs(queens[nQueen]-queens[j]))
			return true;

	return false;
}

void printQ(int * queens,int n){
	for(int i = 0; i < n; i++){
		cout << "        ";
		for(int j = 0; j < n; j++){
			if(j == queens[i]){
				cout << "X";
			}
			else{
				cout << "o";
			}

		}
		cout  << endl;
	}
	cout << endl;
}
