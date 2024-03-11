#include <graphics.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include "datahanding.h"
#include "datastructure.h"
#include "display.h"
#include "studentmanagement.h"
#include "classregistermanagement.h"

using namespace std;

int main(){
	
	initwindow(LPOINTX, LPOINTY);
	
	// tao tien xu ly, khai bao
	string nameFileListStudent = "data\\studentlist.txt";
	string nameFileListClass = "data\\classlist.txt";
//	string nameFileListRegister = "C:\\dssvdemo\\dsdk.txt";
	
	listStudent ls;
	listClass lc;
//	listRegister lr;
	
	readListStudent(ls, nameFileListStudent);
	readListClass(lc, nameFileListClass);
//	readListRegister(lr, nameFileListRegister);
	
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
						studentManagement(ls, lc);
						createMenu(selected);	
						break;
					case 3:
					//	classRegisterManagement(lr);
						break;
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

