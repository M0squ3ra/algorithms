#include<iostream>
using namespace std;

int division_based(int a, int b){
	while(b != 0){
		int t = b;
		b = a % b;
		a = t;
	}
	return a;
}

int subtraction_based(int a, int b){
	while(a != b){
		if(a > b){
			a = a - b;
		}
		else{
			b = b - a;
		}
	}
	return a;
}

int recursive(int a, int b){
	if(b == 0){
		return a;
	}
	else{
		return recursive(b, a % b);
	}
}
