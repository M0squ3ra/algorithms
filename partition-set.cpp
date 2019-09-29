#include <iostream>
#include <algorithm>

using namespace std;

bool partition(int*,int,int,bool*,int,int);
void printS(int*,bool*,int);

int main(int argc, char const *argv[]) {

	int n;
	cout << "How many elements will you add: ";
	cin >> n;
	int arr[n];
	cout << "Add the elements: " << endl;
	for(int i = 0; i < n; i++)
		cin >> arr[i];

	sort(arr,n + arr);

	int ta = 0;
	for(int i = 0; i < n; i++)
		ta += arr[i];

	if(ta % 2 == 1){
		cout << "does not exist solution, the total amount is odd" << endl;
	}
	else{
		bool s[n];
		for(int i = 0; i < n; i++)
			s[i] = false;

		if(!partition(arr,n,ta/2,s,0,0))
			cout << "does not exist solution" << endl;
	}


	return 0;
}

bool partition(int *arr,int n,int half,bool *s,int amount,int i){
	if(half == amount){
		printS(arr,s,n);
		return true;
	}
	else{
		bool solution = false;

		if(i < n && amount < half){
			s[i] = true;
			solution = partition(arr,n,half,s,amount+arr[i],i+1);
			if(solution)
				return solution;

			s[i] = false;
			partition(arr,n,half,s,amount,i+1);
			if(solution)
				return solution;
		}
		else{
			return solution;
		}
	}
}

void printS(int *arr,bool *s,int n){
	cout << "Solution:" << endl;
	cout << "    set 1: ";
	for(int i = 0; i < n; i++){
		if(s[i])
			cout << arr[i] << " ";
	}
	cout << endl;
	cout << "    set 2: ";
	for(int i = 0; i < n; i++){
		if(!s[i])
			cout << arr[i] << " ";
	}
	cout << endl;
}
