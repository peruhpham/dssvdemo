//#pragma once
//#include <graphics.h>
//#include <windows.h>
//#include <conio.h>
//#include <stdio.h>
//#include <bits/stdc++.h>
//#include "display.h"
//#include "datahanding.h"
//#include "datastructure.h"
//
//
////int stringtoint(string s){
////	int temp = 0;
////	for(int i = 1; i <= s.size(); i++){
////		temp += (s[i - 1] - '0') * pow(10, s.size() - i);
////	}
////	return temp;
////}
////
////char* tochar(string s) {
////    char* text = new char[s.size() + 1]; // C?p phát b? nh? d?ng
////    for (int i = 0; i < s.size(); ++i) {
////        text[i] = s[i];
////    }
////    text[s.size()] = '\0';
////    return text;
////}
//
//int clickInScore(int x, int y, int left, int top, int right, int bot){
//	if((left <= x && x <= right) && (top <= y && y <= bot)) return 1;
//	return 0;
//}
//
//
//void outtextwith(int line, student s){
//	
//	setcolor(BLACK);
//	int y = 0;
//	if(line == 1) y = TABLSPOINTY + 50;
//	else if(line == 2) y = TABLSPOINTY + 100;
//	else if(line == 3) y = TABLSPOINTY + 150;
//	else if(line == 4) y = TABLSPOINTY + 200;
//	else y = TABLSPOINTY + 250;
//	
//	outtextxy(TABLSPOINTX + 5, y, tochar(s.id));
//	outtextxy(TABLSPOINTX + 150, y, tochar(s.firstName));
//	outtextxy(TABLSPOINTX + 370, y, tochar(s.lastName));
//	outtextxy(TABLSPOINTX + 515, y, tochar(s.gender));
//	outtextxy(TABLSPOINTX + 615, y, tochar(s.phone));
//	outtextxy(TABLSPOINTX + 760, y, tochar(s.idClass));
//	outtextxy(TABLSPOINTX + 905, y, tochar(to_string(s.year)));
//	
//	setDefault();
//}
//
//int isSubString(char* text, string id){
//	int s = strlen(text);
//	for(int i = 0; i < s; i++){
//		if(text[i] != id[i]) return 0;
//	}
//	return 1;
//}
//
//void findStudent(listStudent &ls, char* text, int &finded){
//	int cnt = 1;
//	ptrStudent p = ls.head;
//	while(p != NULL){
//		if(isSubString(text, p->value.id) && cnt <= 5){
//			finded = 1;
//			if(strlen(text) == 10){
//				outtextwith(1, p->value); // in ra trong dong 1
//				return;
//			}
//			outtextwith(cnt, p->value); // in ra trong dong thu cnt
//			cnt += 1; 
//		}
//		p = p->next;
//	}
//}
//
//
//void updateStudent(listStudent &ls){
//	
//	drawUpdateStudent(); // ve giao dien 
//	
//	int run1 = 1;
//	
//	while(run1){
//		if(kbhit()){
//			char key = getch();
//			if(key == ESC){
//				if(!createNotice("Ban chac chan muon thoat!", "")){
//					return;
//				}
//				drawStudentManagement(1);
//				drawUpdateStudent();
//			}
//		}
//		if(ismouseclick(WM_LBUTTONDOWN)){
//			int run2 = 1, finded = 0;
//			int x, y; // lay toa do nhan chuot
//			getmouseclick(WM_LBUTTONDOWN, x, y);
//			clearmouseclick(WM_LBUTTONDOWN);
//			if(clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY)){
//				char idStudent[15];
//				int len = 0, finded = 0;
//				while(run2){
//					char key;
//					key = getch();
//					if(key == ET){
//						// khong co du lieu thi thong bao
//						if(!finded){
//							setcolor(LIGHTRED);
//							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong tim thay du lieu!");
//							Sleep(1000);
//						}
//						resetBox();
//						resetText();
//						setcolor(BLACK);
//						// chuong trinh tiep tuc, reset lai muc nhap
//						len = 0;
//						for(int i = 0; i < 15; i++) idStudent[i] = '\0';
//					}
//					else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
//						// luu tru input, xuat input, timkiem, xuat danh sach
//						if(len < 10){
//							finded = 0;
//							idStudent[len] = key;
//			                idStudent[len + 1] = '\0'; //
//			                len++;
//							outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);
//							
//							// bat dau xu ly tim kiem
//							drawUpdateStudent();
//							findStudent(ls, idStudent, finded);
//						}
//					}
//					else if(key == ESC){
//						run2 = 0;
//					}
//				}
//			}
//			else if(clickInScore(x, y, TABLSPOINTX + 85, TABLLPOINTY + 50, TABLSPOINTX + 305, TABLLPOINTY + 90)){
//				createNotice("them thong tin", "");
//			}
//			else if(clickInScore(x, y, TABLSPOINTX + 390, TABLLPOINTY + 50, TABLSPOINTX + 610, TABLLPOINTY + 90)){
//				createNotice("sua thong tin", "");
//			}
//			else if(clickInScore(x, y, TABLSPOINTX + 695, TABLLPOINTY + 50, TABLSPOINTX + 915, TABLLPOINTY + 90)){
//				createNotice("xoa thong tin", "");
//			}	
//		}
//	}
////	char idStudent[15];
////	int len = 0, finded = 0;
////	while(true){
////		char key;
////		key = getch();
////		if(key == ET){
////			// khong co du lieu thi thong bao
////			if(!createNotice("khong tim thay du lieu", "")){ // thong bao tra ve 0 thi thoat chuong trinh
////				return;
////			}
////			// chuong trinh tiep tuc, reset lai muc nhap
////			len = 0;
////			for(int i = 0; i < 15; i++) idStudent[i] = '\0';
////			drawStudentManagement(1);
////			drawUpdateStudent();
////		}
////		else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
////			// luu tru input, xuat input, timkiem, xuat danh sach
////			if(len < 15){
////				idStudent[len] = key;
////                idStudent[len + 1] = '\0'; //
////                len++;
////				outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);
////			}
////		}
////	}
//}
//
//void studentManagement(listStudent &ls){
//	int selected = 1;
//	drawStudentManagement(selected);
//	
//	char key;
//	while(true){
//		key = getch();
//		switch(key){
//			case ET:
//				switch(selected){
//					case 1:
//						updateStudent(ls);
//						break;
//					case 2:
//						getch();
//						closegraph();
//						break;
//				}
//				
//				getch();
//				closegraph();
//				return;
//				break;
//			case UP:
//				if(selected > 1){
//					selected--;
//					drawStudentManagement(selected);
//				}
//				break;
//			case DOWN:
//				if(selected < 2){
//					selected++;
//					drawStudentManagement(selected);
//				}
//				break;
//		}
//	}
//	
//	
//}
//	
//	// tao menu va nhap lua chon
//
//
////void findStudent(){
////	
////	// tao lai menu duoc chon o day 
////	
////	drawFindStudent(text); // ve giao dien 
////	
////	char idStudent[15];
////	int len = 0, finded = 0;
////	while(true){
////		char key;
////		key = getch();
////		if(key == ET){
////			// khong co du lieu thi thong bao
////			if(!createNotice("khong tim thay du lieu", "")){ // thong bao tra ve 0 thi thoat chuong trinh
////				return;
////			}
////			// chuong trinh tiep tuc, reset lai muc nhap
////			len = 0;
////			for(int i = 0; i < 15; i++) idStudent[i] = '\0';
////			createMenu(2);
////			drawFindStudent(text);
////		}
////		else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
////			// luu tru input, xuat input, timkiem, xuat danh sach
////			if(len < 15){
////				idStudent[len] = key;
////                idStudent[len + 1] = '\0'; //
////                len++;
////				outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);
////			}
////		}
////	}
////}

