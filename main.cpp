#include <graphics.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "display.h"
#include "datahanding.h"
#include "datastructure.h"


using namespace std;


int clickInScore(int x, int y, int left, int top, int right, int bot){ // nhan chuot trai vao pham vi
	if((left <= x && x <= right) && (top <= y && y <= bot)) return 1;
	return 0;
}


void outtextwith(int line, student s){ // outtext voi chi so dong line
	
	setcolor(BLACK);
	int y = 0;
	if(line == 1) y = TABLSPOINTY + 50;
	else if(line == 2) y = TABLSPOINTY + 100;
	else if(line == 3) y = TABLSPOINTY + 150;
	else y = TABLSPOINTY + 200;
	
	outtextxy(TABLSPOINTX + 5, y, tochar(s.id));
	outtextxy(TABLSPOINTX + 150, y, tochar(s.firstName));
	outtextxy(TABLSPOINTX + 370, y, tochar(s.lastName));
	outtextxy(TABLSPOINTX + 515, y, tochar(s.gender));
	outtextxy(TABLSPOINTX + 615, y, tochar(s.phone));
	outtextxy(TABLSPOINTX + 760, y, tochar(s.idClass));
	outtextxy(TABLSPOINTX + 905, y, tochar(to_string(s.year)));
	
	setDefault();
}

int isSubString(string text, string id){ // kiem tra xau con 
	int s = text.size();
	for(int i = 0; i < s; i++){
		if(text[i] != id[i]) return 0;
	}
	return 1;
}

int existStudent(listStudent &ls, string id){
	ptrStudent p = ls.head;
	while(p != NULL){
		if(isSubString(id, p->value.id)){
			return 1;
		}
		p = p->next;
	}
	return 0;
}

int similarId(string idStudent, string idClass){
	if(idStudent[0] != 'N' || !isdigit(idStudent[7]) || !isdigit(idStudent[8]) || !isdigit(idStudent[9])) return 0;
	if(idStudent[7] == '0' && idStudent[8] == '0' && idStudent[9] == '0') return 0;
	for(int i = 1; i <= 6; i++){
		if(idStudent[i] != idClass[i]) return 0;
	}
	return 1;
}

int similarYear(string year, string idClass){
	if(year[0] != '2' || year[1] != '0') return 0;
	if(year[2] != idClass[1] || year[3] != idClass[2]) return 0;
	return 1;
}


void findStudent(listStudent &ls, string id, int &finded){
	int cnt = 1;
	ptrStudent p = ls.head;
	while(p != NULL){
		if(isSubString(id, p->value.id) && cnt <= 4){
			if((int) id.size() == 10){
				finded = 1;
				outtextwith(1, p->value); // in ra trong dong 1
				return;
			}
			outtextwith(cnt, p->value); // in ra trong dong thu cnt
			cnt += 1; 
		}
		p = p->next;
	}
}

void findClass(listStudent &ls, string idClass, int &finded){
	int cnt = 1;
	ptrStudent p = ls.head;
	while(p != NULL){
		if(isSubString(idClass, p->value.idClass) && cnt <= 4){
			if((int)idClass.size() == 9){
				finded = 1;
			}
			outtextwith(cnt, p->value); // in ra trong dong thu cnt
			cnt += 1; 
		}
		p = p->next;
	}
}

void findStudentAndClass(listStudent &ls, string idStudent, string idClass){
	int cnt = 1;
	ptrStudent p = ls.head;
	while(p != NULL){
		if(isSubString(idClass, p->value.idClass)){ 
			if(isSubString(idStudent, p->value.id) && cnt <= 4){
				// in ra thong tin vua nhap voi mau xanh tren dong 1
				int y = TABLSPOINTY + 50;
				student s = p->value;
				setcolor(LIGHTGREEN);
				outtextxy(TABLSPOINTX + 5, y, tochar(s.id));
				outtextxy(TABLSPOINTX + 150, y, tochar(s.firstName));
				outtextxy(TABLSPOINTX + 370, y, tochar(s.lastName));
				outtextxy(TABLSPOINTX + 515, y, tochar(s.gender));
				outtextxy(TABLSPOINTX + 615, y, tochar(s.phone));
				outtextxy(TABLSPOINTX + 760, y, tochar(s.idClass));
				outtextxy(TABLSPOINTX + 905, y, tochar(to_string(s.year)));
				setDefault();
				// in ra cac thong tin gan voi thong tin vua nhap
				cnt += 1;
				while(p->next != NULL && cnt <= 4){
					outtextwith(cnt, p->next->value);
					p = p->next;
					cnt += 1;
				}
			}
		}
		p = p->next;
	}
}

void typeInforStudent(listStudent &ls, string idClass){
	int currentBox = 1, finded = 1;
	string idStudent, firstName, lastName, gender, phone, year;
	student s; s.idClass = idClass;
	
	int run2 = 1, enter = 1, x, y;
	while(run2){ // bat dau nhap thong tin ma lop
	 // cac muc nhap thong tin theo thu tu tu 1 - 6 tuong ung voi masv, ho, ten,...
	if(enter != 0){
		resetInforStudentBox(currentBox, LIGHTBLUE);
		enter = 0;
	}
		if(kbhit()){
			char key;
			key = getch();
			if(key == ET){
				switch(currentBox){
					case 1: // truong hop nhap maso sinh vien
						if((int)idStudent.size() != 10){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV khong du so ki tu!");
							setcolor(BLACK);
							Sleep(1000);
							resetText(); 
						}
						else if(existStudent(ls, idStudent) || !similarId(idStudent, idClass)){ // neu ma so da ton tai khong the nhap
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV da ton tai hoac khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText(); 
							resetInforStudentBox(currentBox, LIGHTBLUE);
							idStudent = "";
						}
						else{
							enter = 1;
							currentBox += 1;
							s.id = idStudent;
							setcolor(BLACK);
							rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // doi khung xanh thanh khung den va duy chuyen qua muc ke tiep
						}
						break;
					case 2:
						if((int)firstName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ho khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							firstName = "";
						}
						else{
							enter = 1;
							currentBox += 1;
							s.firstName = firstName;
							setcolor(BLACK);
							rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
						}
						break;
					case 3:
						if((int)lastName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ten khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							lastName = "";
						}
						else{
							enter = 1;
							currentBox += 1;
							s.lastName = lastName;
							setcolor(BLACK);
							rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
						}
						break;
					case 4:
						if(gender != "NAM" && gender != "NU"){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Gioi tinh khong phu hop!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							gender = "";
						}
						else{
							enter = 1;
							currentBox += 1;
							s.gender = gender;
							setcolor(BLACK);
							rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
						}
						break;
					case 5:
						if((int)phone.size() != 10 || phone[0] != '0'){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "SDT chu du hoac khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.phone = phone;
							setcolor(BLACK);
							rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
						}
						break;
					case 6:
						if((int)year.size() != 4 || !similarYear(year, idClass)){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Nam hoc khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							year = "";
						}
						else{
							enter = 1;
							currentBox += 1;
							s.year = stringtoint(year);
							setcolor(BLACK);
							rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
						}
						break;
				}
			}
			else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9') || key == SPACE || key == BP){
				switch(currentBox){
					case 1: // xu ly nhap cho muc idStudent
						if(key == BP && (int)idStudent.size() > 0){
							idStudent.pop_back();
							resetInforStudentBox(1, LIGHTBLUE); // xoa muc nhap va in lai
							setcolor(BLACK);
							outtextxy(FORMSPOINTX + 10, FORMSPOINTY + 10, tochar(idStudent));
						}
						else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
							if((int)idStudent.size() < 10){
								formatKey(key); // dua ve chu in hoa
								idStudent += key;
								setcolor(BLACK);
								outtextxy(FORMSPOINTX + 10, FORMSPOINTY + 10, tochar(idStudent)); // in ra trong hop nhap	
							}	
						}
						break;
					case 2: // xu ly nhap cho muc Ho 
						if(key == BP && (int)firstName.size() > 0){
							firstName.pop_back();
							resetInforStudentBox(2, LIGHTBLUE);
							setcolor(BLACK);
							outtextxy(TABLSPOINTX + 155, FORMSPOINTY + 10, tochar(firstName));
						}
						else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || key == SPACE){
							if((int)firstName.size() < 19){
								formatKey(key);
								firstName += key;
								setcolor(BLACK);
								outtextxy(TABLSPOINTX + 155, FORMSPOINTY + 10, tochar(firstName));
							}
						}
						break;
					case 3: // xu ly nhap cho muc TEN
						if(key == BP && (int)lastName.size() > 0){
							lastName.pop_back();
							resetInforStudentBox(3, LIGHTBLUE);
							setcolor(BLACK);
							outtextxy(TABLSPOINTX + 375, FORMSPOINTY + 10, tochar(lastName));
						}
						else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z')){
							if((int)lastName.size() < 12){
								formatKey(key);
								lastName += key;
								setcolor(BLACK);
								outtextxy(TABLSPOINTX + 375, FORMSPOINTY + 10, tochar(lastName));
							}
						}
						break;
					case 4: // xu ly nhap cho muc goi tinh
						if(key == BP && (int)gender.size() > 0){
							gender.pop_back();
							resetInforStudentBox(4, LIGHTBLUE);
							setcolor(BLACK);
							outtextxy(TABLSPOINTX + 520, FORMSPOINTY + 10, tochar(gender));
						}
						else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z')){
							if((int)gender.size() < 3){
								formatKey(key);
								gender += key;
								setcolor(BLACK);
								outtextxy(TABLSPOINTX + 520, FORMSPOINTY + 10, tochar(gender));
							} 
						}
						break;
					case 5: // xu ly nhap cho muc phone
						if(key == BP && (int)phone.size() > 0){
							phone.pop_back();
							resetInforStudentBox(5, LIGHTBLUE);
							setcolor(BLACK);
							outtextxy(TABLSPOINTX + 620, FORMSPOINTY + 10, tochar(phone));
						}
						else if(('0' <= key && key <= '9')){
							if((int)phone.size() < 10){
								formatKey(key);
								phone += key;
								setcolor(BLACK);
								outtextxy(TABLSPOINTX + 620, FORMSPOINTY + 10, tochar(phone));
							} 
						}
						break;
					case 6: // xu ly nhap cho muc khoa
						if(key == BP && (int)year.size() > 0){
							year.pop_back();
							resetInforStudentBox(6, LIGHTBLUE);
							setcolor(BLACK);
							outtextxy(TABLSPOINTX + 765, FORMSPOINTY + 10, tochar(year));
						}
						else if(('0' <= key && key <= '9')){
							if((int)year.size() < 4){
								formatKey(key);
								year += key;
								setcolor(BLACK);
								outtextxy(TABLSPOINTX + 765, FORMSPOINTY + 10, tochar(year));
							} 
						}
						break;
				}
			}
			else if(key == ESC){ // esc gom cac lua chon : thoat chuong trinh (return), quay tro lai (break) de su dung con tro chuot
				if(!createNotice("Ban chac chan muon thoat", "")){
					return;
				}
				// da chinh sua
				drawStudentManagement(1);
				drawUpdateStudent();
				drawInsertStudent();
				outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idClass));
				findClass(ls, idClass, finded);
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			// click vao nut add
			if(clickInScore(x, y, TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY)){
				if((int)idStudent.size() == 0){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin rong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
					return;
				}
				else if((int)year.size() == 0){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Vui long nhap du thong tin!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
				}
				else if((int)year.size() != 0){
					setcolor(LIGHTGREEN);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Them thong tin thanh cong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
					addLast(ls, s);
					createList();
					findStudentAndClass(ls, s.id, s.idClass); // hien thi ra thong tin sinh vien vua them
				}
			}
			// click ra ngoai
		}
	}
}

void insertStudent(listStudent &ls){
	drawInsertStudent();
	int run1 = 1;
	
	int x, y; // lay toa do nhan chuot
	
	// bat dau chon muc voi 2 truong hop : 1. nhap phim ESC de thoat, 2. click chuot vao muc de nhap du lieu
	while(run1){
		// phat hien nhap phim ESC va xu ly
		if(kbhit()){
			char key = getch();
			if(key == ESC){
				if(!createNotice("Ban chac chan muon thoat!", "")){ // neu thoat thi return
					return;
				}
				// truong hop quay lai thi tiep tuc bang cach ve lai toan bo man hinh cu
				drawStudentManagement(1);
				drawUpdateStudent();
				drawInsertStudent();
			}
		}
		// phat hien nhap chuot va xu ly
		if(ismouseclick(WM_LBUTTONDOWN)){
			int run2 = 1, entered = 0; // entered de kiem tra xem da nhap thong tin vao hop chua
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			// neu click chuot ra ngoai muc nhap thi hien thi thong bao nhap lai
			if(!clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY) && entered == 0){
				createBox(LIGHTRED, "Vui long nhap Ma lop:");
			}
			// click chuot vao muc nhap va bat dau nhap 
			else{
				createBox(BLACK, "Vui long nhap Ma lop:");
				setcolor(LIGHTBLUE);
				rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); // to hop nhap thanh mau xanh
				setDefault();
				
				string idClass;
				int finded = 0;
				while(run2){ // bat dau nhap thong tin ma lop
					// truong hop nhan phim
					if(kbhit()){
						char key;
						key = getch();
						if(key == ET){
							// khong co du lieu thi thong bao
							if(!finded){
								setcolor(LIGHTRED);
								outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong tim thay du lieu! vui long nhap lai.");
								setcolor(BLACK);
								createList();
								Sleep(1000);
								resetBox(LIGHTBLUE); // tao khung nhap rong voi mau xanh
								resetText(); 
								
								setDefault();
							}
							else{
								setcolor(BLACK);
								rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); // to muc nhap thanh mau den nhung van de text
								// neu da tim thay du lieu 
								// 1. nhap msv
								typeInforStudent(ls, idClass);
								return; // quay tro lai muc them sua xoa thong tin.
								
							}
							// chuong trinh tiep tuc, reset lai muc nhap
							idClass = "";
						}
						else if(key == BP && (int)idClass.size() > 0){
							idClass.pop_back();
							resetBox(LIGHTBLUE); // xoa muc nhap va in lai
							outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idClass));
							createList();
							findClass(ls, idClass, finded);
						}
						else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
							// luu tru input, xuat input, timkiem, xuat danh sach
							if((int)idClass.size() < 9){
								formatKey(key); // dua ve chu in hoa
								finded = 0;
								idClass += key;
								outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idClass)); // in ra trong hop nhap
								
								// bat dau xu ly tim kiem
								createList();
								findClass(ls, idClass, finded);
							}
						}
						else if(key == ESC){ // esc gom cac lua chon : thoat chuong trinh (return), quay tro lai (break) de su dung con tro chuot
							if(!createNotice("Ban chac chan muon thoat", "")){
								return;
							}
							cleardevice();
							drawStudentManagement(1);
							drawUpdateStudent();
							drawInsertStudent();
							break;
						}
					}
					// truong hop click chuot vao vi tri add hoac click ra ngoai muc nhap 
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if(!clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY)){
							resetBox(BLACK);
							resetText();
							break; // dung nhap du lieu
						}
					}
				}	
			}
		}
	}
}                            
void updateStudent(listStudent &ls){
	
	drawUpdateStudent(); // ve giao dien 
	
	int run1 = 1;
	
	int x, y; // lay toa do nhan chuot
	while(run1){
		if(kbhit()){
			char key = getch();
			if(key == ESC){
				if(!createNotice("Ban chac chan muon thoat!", "")){
					return;
				}
				drawStudentManagement(1);
				drawUpdateStudent();
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			int run2 = 1, finded = 0;
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY)){
				
				setcolor(LIGHTBLUE);
				rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); // to hop nhap thanh mau xanh
				setDefault();
				
				string idStudent;
				int finded = 0;
				while(run2){
					if(kbhit()){
						char key;
						key = getch();
						if(key == ET){
							// khong co du lieu thi thong bao
							if(!finded){
								setcolor(LIGHTRED);
								outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong tim thay du lieu!");
								createList();
								Sleep(1000);
							}
							resetBox(LIGHTBLUE); // tao khung nhap rong voi mau xanh
							resetText(); 
							setcolor(BLACK);
							// chuong trinh tiep tuc, reset lai muc nhap
							idStudent = "";
						}
						else if(key == BP && (int)idStudent.size() > 0){
							idStudent.pop_back();
							resetBox(LIGHTBLUE); // xoa muc nhap va in lai
							outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idStudent));
							createList();
							findStudent(ls, idStudent, finded);
						}
						else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
							// luu tru input, xuat input, timkiem, xuat danh sach
							if((int)idStudent.size() < 10){
								finded = 0;
								idStudent  += key;
								outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idStudent));
								
								// bat dau xu ly tim kiem
								createList();
								findStudent(ls, idStudent, finded);
							}
						}
						else if(key == ESC){ // esc gom cac lua chon : thoat chuong trinh (return), quay tro lai (break) de su dung con tro chuot
							if(!createNotice("Ban chac chan muon thoat", "")){
								return;
							}
							cleardevice();
							drawStudentManagement(1);
							drawUpdateStudent();
							break;
						}
					}
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN, x, y);
						if(!clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY)){
							resetBox(BLACK);
							resetText();
							break; // dung nhap du lieu
						}
					}
				}
			}
			else if(clickInScore(x, y, TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140)){
				insertStudent(ls);
				cleardevice();
				drawStudentManagement(1);
				drawUpdateStudent();
			}
			else if(clickInScore(x, y, TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140)){
				
			}
			else if(clickInScore(x, y, TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140)){
				
			}	
		}
	}
}

void studentManagement(listStudent &ls){
	int selected = 1;
	drawStudentManagement(selected);
	
	char key;
	while(true){
		key = getch();
		switch(key){
			case ET:
				switch(selected){
					case 1:
						updateStudent(ls);
						return;
						break;
//					case 2:
						
				}
				break;
			case UP:
				if(selected > 1){
					selected--;
					drawStudentManagement(selected);
				}
				break;
			case DOWN:
				if(selected < 2){
					selected++;
					drawStudentManagement(selected);
				}
				break;
			case ESC:
				return;
		}
	}
	
	
}
	

int main(){
	
	initwindow(LPOINTX, LPOINTY);
	
	// tao tien xu ly, khai bao
	string nameFileListStudent = "D:\\Documents\\C++\\ProjectTemp\\data\\studentlist.txt";
	listStudent ls;
	readListStudent(ls, nameFileListStudent);
	
	getch();
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

