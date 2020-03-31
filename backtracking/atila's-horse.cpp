#include <iostream>
#include <utility>
#include <iomanip>

#define SIZE_GARDEN 6

using namespace std;

void movements(int[][SIZE_GARDEN],int*,pair<int,int>);
bool travel(int[][SIZE_GARDEN],pair<int,int>,int,int);
bool start(int[][SIZE_GARDEN],pair<int,int>);

int main(int argc, char const *argv[]) {

	int garden[][SIZE_GARDEN] = {{0,0,0,0,0,0},
					   			 {0,0,0,0,0,0},
					   			 {-1,-1,0,0,0,0},
					   			 {-1,-1,0,0,0,0},
							 	 {0,0,0,0,0,0},
							 	 {0,0,0,0,0,0}}; //-1: the horse floor the area

	int p = 0;
	for(int i = 0; i < SIZE_GARDEN; i++)
		for(int j = 0; j < SIZE_GARDEN; j++)
			if(garden[i][j] == 0)
				p++;


	pair<int,int> horse = {1,0}; //initial position
	garden[horse.first][horse.second] = 1;


	if(!travel(garden,horse,1,p))
		cout << "does'n have solution" << endl;

	return 0;
}

bool travel(int garden[][SIZE_GARDEN],pair<int,int> position,int tread,int p){
	garden[position.first][position.second] = tread;

	bool solution = false;


	if(p == tread && start(garden,position)){ // agregar comprobacion de si algun adyacente es igual a 1
		cout << "Solution: " << endl;
		for(int i = 0; i < SIZE_GARDEN; i++){
			for(int j = 0; j < SIZE_GARDEN; j++)
				if(garden[i][j] != -1)
					cout  << "   " << setw(2) << garden[i][j];
				else
					cout  << "   " << setw(2) << "x";
			cout << endl;
		}
		return true;
	}
	else{
		int adjacent[4]; //{up,down,left,right}
						  //0: can step on
		movements(garden,adjacent,position);

		pair<int,int> next;

		if(adjacent[0] == 0 && solution == false){
			next.first = position.first - 1;
			next.second = position.second;
			solution = travel(garden,next,tread + 1,p);
		}
		if(adjacent[1] == 0 && solution == false){
			next.first = position.first + 1;
			next.second = position.second;
			solution = travel(garden,next,tread + 1,p);
		}
		if(adjacent[2] == 0 && solution == false){
			next.first = position.first;
			next.second = position.second - 1;
			solution = travel(garden,next,tread + 1,p);
		}
		if(adjacent[3] == 0 && solution == false){
			next.first = position.first;
			next.second = position.second + 1;
			solution = travel(garden,next,tread + 1,p);
		}

	}
	garden[position.first][position.second] = 0;
	return solution;
}

bool start(int garden[][SIZE_GARDEN],pair<int,int> position){
	if(position.first > 0)
		if(garden[position.first-1][position.second] == 1)
			return true;

	if(position.first < SIZE_GARDEN - 1)
		if(garden[position.first+1][position.second] == 1)
			return true;

	if(position.second > 0)
		if(garden[position.first][position.second-1] == 1)
			return true;

	if(position.second < SIZE_GARDEN - 1)
		if(garden[position.first][position.second + 1] == 1)
			return true;

	return false;
}

void movements(int garden[][SIZE_GARDEN],int* adjacent,pair<int,int> position){
	for(int i = 0;i < 4; i++)
		adjacent[i] = 1;

	if(position.first > 0)
		adjacent[0] = garden[position.first-1][position.second];

	if(position.first < SIZE_GARDEN - 1)
		adjacent[1] = garden[position.first+1][position.second];

	if(position.second > 0)
		adjacent[2] = garden[position.first][position.second-1];

	if(position.second < SIZE_GARDEN - 1)
		adjacent[3] = garden[position.first][position.second+1];
}
