#ifndef _DICHUYEN_H
#define _DICHUYEN_H
#include<iostream>
#include<stdlib.h>
using namespace std;
class ThanRan{
	
	private:
		
		int x, y;
		
	public:
	
	ThanRan(){
		
		x = 60;
		y = 0;
	}
	
	//move
	
	void up(){
		
		y--;
	}
	
	void down(){
		
		y++;
	}
	
	void right(){
		
		x++;
	}
	
	void left(){
		
		x--;
	}
	
	void setX(int a){
		
		x = a;
	}
	
	void setY(int a){
		
		y = a;
	}
	
	int getX(){
		
		return x;
	}
	
	int getY(){
		
		return y;
	}
	
};

class ConRan{
	
	private:
		
		ThanRan thanRan[10000] = {};
		int length = 2;
		char trangThai;
		
	public:
		
		ConRan(){
			
			trangThai = 'd';
			
			for (int i = 0, k = length; i < length; i++, k--){
				
				thanRan[i].setX(k);
				thanRan[i].setY(5);
			}
		}
		void reset(){
			trangThai = 'd';
			length = 2;
			for (int i = 0, k = length; i < length; i++, k--){
				
				thanRan[i].setX(k);
				thanRan[i].setY(5);
			}
		}
		void diChuyen(){
			
			for (int i = length - 1; i >= 1; i--){
				thanRan[i] = thanRan[i - 1];
			}
			
			if (trangThai == 'w'){
				
				thanRan[0].up();
			}
			else if (trangThai == 's'){
				
				thanRan[0].down();
			}
			else if (trangThai == 'd'){
				
				thanRan[0].right();
			}
			else if (trangThai == 'a'){
				
				thanRan[0].left();
			}
		}
		
		char getTrangThai(){
			
			return trangThai;
		}
		
		void setTrangThai(char tt){
			
			trangThai = tt;
		}
		
		void ve(){
			
			for (int i = 0; i < length; i++){
				
				gotoxy(thanRan[i].getX(), thanRan[i].getY());
				
				if (i == 0){
					setcolor(12);
					std::cout << (char)1;
				}
				else {
					int mau = 1+rand()%100;
					setcolor(mau);
					std::cout << "o";
				}
				
			}
		}
		bool anDot(ThanRan a){
			if(a.getX() == thanRan[0].getX() && a.getY() == thanRan[0].getY()){
				length++;
				return true;
			}
			return false;
		}
		bool test(ThanRan a){
			for(int i=0;i<length;i++){
				if(a.getX() == thanRan[i].getX() && a.getY() == thanRan[i].getY()) return false;
			}
			return true;
		}
		bool DIE(){
			for(int i=1;i<length;i++){
				if(thanRan[0].getX()==thanRan[i].getX()&&thanRan[0].getY()==thanRan[i].getY()) return true;
			}
			if(thanRan[0].getX()>=50||thanRan[0].getX()<=0||thanRan[0].getY()<=0||thanRan[0].getY()>=25)
			return true;
			return false;
		}
		void xoa(){
			
			for (int i = 0; i < length; i++){
				
				gotoxy(thanRan[i].getX(), thanRan[i].getY());
				std::cout << " ";
			}
		}
		
};
#endif
