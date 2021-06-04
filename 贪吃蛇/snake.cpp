#include <iostream>
#include <windows.h> //#include <unistd.h>
#include <conio.h>
#include <stdlib.h>
using namespace std;

int mmap[205][205], flag = 1, sn[50000][2] = {{0, 0}, {10, 9}, {10, 10}, {10, 11}}, lon = 3, ind = 2, dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0}, kbnum, xx, yy, add, eat = 1;

void move(){
	if(!add){
		for(int i = lon; i >= 2; i--){
			sn[i][0] = sn[i - 1][0];
			sn[i][1] = sn[i - 1][1];
		}
	} else {
		for(int i = lon; i >= 1; i--){
			sn[i + 1][0] = sn[i][0];
			sn[i + 1][1] = sn[i][1];
		}
		sn[1][0] = xx;
		sn[1][1] = yy;
		lon++;
		eat = 1;
		add = 0;
	}
	sn[1][0] += dir[ind][0];
	sn[1][1] += dir[ind][1];
}
void draw(){
	for(int i = 2; i < 20; i++){
		for(int j = 2; j < 20; j++){
			if(mmap[i][j] != 4){
				mmap[i][j] = 0;
			}
		}
	}
	for(int i = 1; i <= 20; i++){
		mmap[i][1] = 1;
		mmap[i][20] = 1;
		mmap[1][i] = 1;
		mmap[20][i] = 1;
	}
	for(int i = lon; i >= 2; i--){
		mmap[sn[i][0]][sn[i][1]] = 2;
	}
	if(mmap[sn[1][0]][sn[1][1]] == 4){
		add = 1;
	}else if(mmap[sn[1][0]][sn[1][1]] != 0){
		flag = -1;
		return;
	}
	mmap[sn[1][0]][sn[1][1]] = 3;
	if(eat){
		while(1){
	        xx = rand() % 18 + 2;
			yy = rand() % 18 + 2;
			if(!mmap[xx][yy]){
				mmap[xx][yy] = 4;
				eat = 0;
				break;
			}
		}	
	}
}
void output(){
	for(int i = 1; i <= 20; i++){
		for(int j = 1; j <= 20; j++){
			if(mmap[i][j] == 2){
				cout << "*";
			}
			if(!mmap[i][j]){
				cout << ".";
			}
			if(mmap[i][j] == 1){
				cout << "@";
			}
			if(mmap[i][j] == 3){
				cout << "#";
			}
			if(mmap[i][j] == 4){
				cout << "$";
			}
			cout << " ";
		}
		cout << endl;
	}
}

int main() {
	while(flag != -1){
		system("cls");
        if(_kbhit()){
            kbnum = _getch();
            if(kbnum == 119){
                ind = 3;
            } else if(kbnum == 115){
                ind = 1;
            } else if(kbnum == 97){
                ind = 2;
            } else if(kbnum == 100){
                ind = 0;
            }
        }
		move();
		draw();
		output();
		Sleep(500); //usleep(500000);
	}
	cout <<"	 Game Over!" << endl;
	return 0;
}