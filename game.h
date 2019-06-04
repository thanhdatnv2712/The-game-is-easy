#ifndef _GAME_H
#define _GAME_H
#include <iostream>
#include <vector>
#include <stdlib.h>
#include <time.h>
#include "dichuyen.h"
#include "console.h"
using namespace std;
void Init2(){
	clrscr();
	for(int i=0;i<=100;i++){
		gotoxy(20,9);cout<<"Loading.........";
		gotoxy(20,10);cout<<i<<"%";
		gotoxy(i,11);cout<<"**********";
		gotoxy(i,12);cout<<"  **********";
		gotoxy(i,13);cout<<"    **********";
		gotoxy(i,14);cout<<"  **********";
		gotoxy(i,15);cout<<"**********";
		Sleep(i);
		if(i!=100){
			gotoxy(i,11);cout<<" *********";
			gotoxy(i,12);cout<<"   *********";
			gotoxy(i,13);cout<<"     *********";
			gotoxy(i,14);cout<<"   *********";
			gotoxy(i,15);cout<<" *********";
		}
		else{
			Sleep(2000);
			gotoxy(i,11);cout<<"          ";
			gotoxy(i,12);cout<<"            ";
			gotoxy(i,13);cout<<"              ";
			gotoxy(i,14);cout<<"            ";
			gotoxy(i,15);cout<<"          ";
		}
	}
}
ConRan ran;

void dieuKhien(){
	
	char key;
	
	if (_kbhit()){					//ham bat phim
		
		key = _getch();				//ham lay du lieu tu ban phim
		
		if (key == 'w' && ran.getTrangThai() != 's'){
			
			ran.setTrangThai('w');
		}
		else if (key == 's' && ran.getTrangThai() != 'w'){
			
			ran.setTrangThai('s');
		}
		else if (key == 'a' && ran.getTrangThai() != 'd'){
			
			ran.setTrangThai('a');
		}
		else if (key == 'd' && ran.getTrangThai() != 'a'){
			
			ran.setTrangThai('d');
		}
	}
	else
		return;
}
void Map(){
	setcolor(7);
	for(int i=0;i<=25;i++){
		gotoxy(0,i);cout<<"#";
		gotoxy(50,i);cout<<"#";
	}
	for(int i=0;i<=50;i++){
		gotoxy(i,0);cout<<"#";
		gotoxy(i,25);cout<<"#";
	}
}
void Start(){
	srand(time(NULL));
	int diem = 0;
	ThanRan dot;
	int x,y;
	do{
		x =1 + rand()%49;
		y =1 + rand()%24;
		dot.setX(x);dot.setY(y);
	}while(!ran.test(dot));
	gotoxy(x,y);
	cout<<(char)1;
	Map();
	while(true){
		settextbgcolor(64);
		gotoxy(51,0); cout<<"Diem: "<<diem;
		dieuKhien();
		ran.diChuyen();
		if(ran.anDot(dot)){
			gotoxy(x,y);
			cout<<" ";
			diem++;
			do{
				x =1 + rand()%49;
				y =1 + rand()%24;
				dot.setX(x);dot.setY(y);
			}while(!ran.test(dot));	
			gotoxy(x,y);
			cout<<(char)1;
		}
		if(ran.DIE()){
			clrscr();
			gotoxy(5,5);
			cout<<"GAME OVER!!!";
			gotoxy(5,5);
			string Lost = "Diem cua ban la: ";
			for(int i=0;i<Lost.length();i++){
				gotoxy(5,6);
				for(int j=0;j<=i;j++){
					cout<<Lost[j];
				}
				Sleep(250);
			}
			cout<<diem;
			Sleep(2000);
			gotoxy(4,7);
			cout<<"Ban co muon choi lai: [1].YES     [2].NO";
			while(1){
				if(_kbhit()){
					char a = _getch();
					if(a == '1'){
				 		ran.reset();
				 		//setcolor(10);
				 		clrscr();
						Start();
			 		}
				 	if(a == '2') return;
				}
			}
		}
		ran.ve();
		//settextbgcolor(64);
		Sleep(50);
		ran.xoa();
	}	
	clrscr();
}
void Init3(){
	gotoxy(20,7);cout<<"     BTC Snake";
	gotoxy(20,11);cout<<"BBBB  TTTTTT CCCCC";
	gotoxy(20,12);cout<<"B   B TTTTTT C    ";
	gotoxy(20,13);cout<<"B   B   TT   C    ";
	gotoxy(20,14);cout<<"BBBB    TT   C    ";
	gotoxy(20,15);cout<<"B   B   TT   C    ";
	gotoxy(20,16);cout<<"B   B   TT   C    ";
	gotoxy(20,17);cout<<"BBBB    TT   CCCCC";
	gotoxy(15,20);cout<<"[1]. Start    [2].Infor    [3]. Exit";
	gotoxy(15,21);cout<<"----Edit by coder co don----";
	gotoxy(15,22);cout<<" ----------BTC Team--------";
}
void Init(){				//khoi tao game
	Nocursortype();
	Init3();
	while(1){
		if(_kbhit()){
			char a = getch();
			if(a=='3'){
				break;
			}
			if(a=='1'){
				Init2();
				clrscr();
				Start();
				break;
			}
			if(a=='2'){
				Init2();
				clrscr();
				cout<<"BTC Team gom 4 thanh vien:"<<endl;
				cout<<"-Phan Duc Duan <coder_co_don> phu trach ki thuat"<<endl;
				cout<<"-Nguyen Tung Lam <Lam_BTC> phu trach ki thuat"<<endl;
				cout<<"-Nguyen Van Quang <Quang mam> phu trach thiet ke"<<endl;
				cout<<"-Nguyen Quoc Thai <Thai Master> phu trach y tuong"<<endl;
				gotoxy(20,11);cout<<"BBBB  TTTTTT CCCCC";
				gotoxy(20,12);cout<<"B   B TTTTTT C    ";
				gotoxy(20,13);cout<<"B   B   TT   C    ";
				gotoxy(20,14);cout<<"BBBB    TT   C    ";
				gotoxy(20,15);cout<<"B   B   TT   C    ";
				gotoxy(20,16);cout<<"B   B   TT   C    ";
				gotoxy(20,17);cout<<"BBBB    TT   CCCCC";
				gotoxy(15,20);cout<<"Nhap x de quay lai.....";
				while(1){
					if(_kbhit()){
						char a = getch();
						if(a=='x') break;
					}
				}
				clrscr();
				Init3();
			}
		}
	}
	clrscr();
}
#endif
