#include <graphics.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "display.h"
#include "datahanding.h"
#include "datastructure.h"
#include "studentmanagement.h"

using namespace std;

int main(){
	
	initwindow(LPOINTX, LPOINTY);
	
	// tao tien xu ly, khai bao
	string nameFileListStudent = "D:\\Documents\\C++\\ProjectTemp\\data\\studentlist.txt";
	listStudent ls;
	readListStudent(ls, nameFileListStudent);
	
//	getch();
	int selected = 1;
	createMenu(selected);
	while(1){
		char key = getch();
		switch(key){
			case ET: 	
				switch(selected){
//					case 1: 
					case 2:
						studentManagement(ls);
						createMenu(selected);	
						break;
//					case 3:
//					case 4: 
				}
				break;
			case UP:
				if(selected > 1){
					selected--;
					createMenu(selected);
				}
				break;
			case DOWN:
				if(selected < 4){
					selected++;
					createMenu(selected);
				}
				break;
			case ESC:
				if(!createNotice("Ban chac chan muon thoat!", "")){
					closegraph();
					return 0;
				}
				createMenu(selected);
				break;
		}
	}
}

