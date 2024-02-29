#include <graphics.h>
#include <string>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include "display.h"
#include "datahanding.h"
#include "datastructure.h"

using namespace std;

// int stringtoint(string s){
//	int temp = 0;
//	for(int i = 1; i <= s.size(); i++){
//		temp += (s[i - 1] - '0') * pow(10, s.size() - i);
//	}
//	return temp;
<<<<<<< HEAD
// }
//
// char* tochar(string s) {
//     char* text = new char[s.size() + 1]; // C?p ph�t b? nh? d?ng
//     for (int i = 0; i < s.size(); ++i) {
//         text[i] = s[i];
//     }
//     text[s.size()] = '\0';
//     return text;
// }
=======
//}
// 
//char* tochar(string s) {
//    char* text = new char[s.size() + 1]; // C?p ph�t b? nh? d?ng
//    for (int i = 0; i < s.size(); ++i) {
//        text[i] = s[i];
//    }
//    text[s.size()] = '\0';
//    return text;
//}
>>>>>>> a92bdb6c20cf2a49befe6019b5bd7b610576a03e

int clickInScore(int x, int y, int left, int top, int right, int bot)
{
	if ((left <= x && x <= right) && (top <= y && y <= bot))
		return 1; // kiem tra gioi han toa do cua diem click
	return 0;
}

void outtextwith(int line, student s)
{ // Dinh nghia ham xuat thong tin sinh vien trên mot dong

	setcolor(BLACK);
	int y = 0;

	if (line == 1)
		y = TABLSPOINTY + 50;
	else if (line == 2)
		y = TABLSPOINTY + 100;
	else if (line == 3)
		y = TABLSPOINTY + 150;
	else if (line == 4)
		y = TABLSPOINTY + 200;
	else
		y = TABLSPOINTY + 250;

	outtextxy(TABLSPOINTX + 5, y, tochar(s.id)); // tochar() de dua ve kieu char chú ý nó có 2 null, hơi lang phí bo nho
	outtextxy(TABLSPOINTX + 150, y, tochar(s.firstName));
	outtextxy(TABLSPOINTX + 370, y, tochar(s.lastName));
	outtextxy(TABLSPOINTX + 515, y, tochar(s.gender));
	outtextxy(TABLSPOINTX + 615, y, tochar(s.phone));
	outtextxy(TABLSPOINTX + 760, y, tochar(s.idClass));
	outtextxy(TABLSPOINTX + 905, y, tochar(to_string(s.year)));

	setDefault();
}

// kiem tra co phai la chuoi con hay khong
int isSubString(char *text, string id)
{
	int s = strlen(text);
	for (int i = 0; i < s; i++)
	{
		if (text[i] != id[i])
			return 0;
	}
	return 1;
}

void findStudent(listStudent &ls, char *text, int &finded)
{
	int cnt = 1; // dem dong
	ptrStudent p = ls.head;
	while (p != NULL)
	{
		if (isSubString(text, p->value.id) && cnt <= 5)
		{
			if (strlen(text) == 10)
			{
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

void updateStudent(listStudent &ls)
{

	drawUpdateStudent(); // ve giao dien

	int run1 = 1;

	while (run1)
	{
		if (kbhit())
		{
			char key = getch();
			if (key == ESC)
			{
				if (!createNotice("Ban chac chan muon thoat!", ""))
				{
					return;
				}
				drawStudentManagement(1);
				drawUpdateStudent();
			}
		}

		// WM_LBUTTONDOWN ma lick chuot là có lick
		if (ismouseclick(WM_LBUTTONDOWN)){ 
			int run2 = 1, finded = 0;
			int x, y; // lay toa do nhan chuot
			getmouseclick(WM_LBUTTONDOWN, x, y); // lấy tọa độ click
			clearmouseclick(WM_LBUTTONDOWN); // xóa bộ đệm click 
			if (clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY))
			{
				char idStudent[15];
				int len = 0, finded = 0;
				while (run2)
				{
					char key;
					key = getch();
					if (key == ET)
					{
						// khong co du lieu thi thong bao
						if (!finded)
						{
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong tim thay du lieu!");
							Sleep(1000);
						}
						resetBox();	 // thiet dat lai khung nhap du lieu
						resetText(); // thiet lap lai thong bao loi
						setcolor(BLACK);
						// chuong trinh tiep tuc, reset lai muc nhap
						len = 0;
						for (int i = 0; i < 15; i++)
							idStudent[i] = '\0';
					}
					//
					else if (('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9'))
					{
						// luu tru input, xuat input, timkiem, xuat danh sach
						if (len < 10)
						{
							finded = 0;

							if ('a' <= key && key <= 'z')
								idStudent[len] = toupper(key);
							else
								idStudent[len] = key;

							idStudent[len + 1] = '\0'; // them null cuoi chuoi
							len++;

							outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);

							// bat dau xu ly tim kiem
							drawUpdateStudent(); // ve lai khung ket qua danh sach duoc tin thay
							findStudent(ls, idStudent, finded);
						}
					}
					else if (key == ESC)
					{
						run2 = 0;
					}

					// xu li them cac chuc nang , xoa backspace......
					else if (key == BP && 0 < len && len <= 10){
						len--;
						idStudent[len] = '\0';

						bar(BOXSPOINTX + 2, BOXSPOINTY + 2, BOXLPOINTX, BOXLPOINTY);
						outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);
					}
				}

				
			}
			else if (clickInScore(x, y, TABLSPOINTX + 85, TABLLPOINTY + 50, TABLSPOINTX + 305, TABLLPOINTY + 90))
			{
			}
			else if (clickInScore(x, y, TABLSPOINTX + 390, TABLLPOINTY + 50, TABLSPOINTX + 610, TABLLPOINTY + 90))
			{
				createNotice("sua thong tin", "");
			}
			else if (clickInScore(x, y, TABLSPOINTX + 695, TABLLPOINTY + 50, TABLSPOINTX + 915, TABLLPOINTY + 90))
			{
				createNotice("xoa thong tin", "");
			}
		}
	}
	//	char idStudent[15];
	//	int len = 0, finded = 0;
	//	while(true){
	//		char key;
	//		key = getch();
	//		if(key == ET){
	//			// khong co du lieu thi thong bao
	//			if(!createNotice("khong tim thay du lieu", "")){ // thong bao tra ve 0 thi thoat chuong trinh
	//				return;
	//			}
	//			// chuong trinh tiep tuc, reset lai muc nhap
	//			len = 0;
	//			for(int i = 0; i < 15; i++) idStudent[i] = '\0';
	//			drawStudentManagement(1);
	//			drawUpdateStudent();
	//		}
	//		else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
	//			// luu tru input, xuat input, timkiem, xuat danh sach
	//			if(len < 15){
	//				idStudent[len] = key;
	//                idStudent[len + 1] = '\0'; //
	//                len++;
	//				outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);
	//			}
	//		}
	//	}
}

void studentManagement(listStudent &ls)
{
	int selected = 1;
	drawStudentManagement(selected);

	char key;
	while (true)
	{
		key = getch();
		switch (key)
		{
		case ET:
			switch (selected)
			{
			case 1:
				updateStudent(ls);
				break;
			case 2:
				getch();
				closegraph();
				break;
			}

			getch();
			closegraph();
			return;
			break;
		case UP:
			if (selected > 1)
			{
				selected--;
				drawStudentManagement(selected);
			}
			break;
		case DOWN:
			if (selected < 2)
			{
				selected++;
				drawStudentManagement(selected);
			}
			break;
		}
	}
}

int main()
{

<<<<<<< HEAD
	initwindow(LPOINTX, LPOINTY);

=======
//void findStudent(){
//	
//	// tao lai menu duoc chon o day 
//	
//	drawFindStudent(text); // ve giao dien 
//	
//	char idStudent[15];
//	int len = 0, finded = 0;
//	while(true){
//		char key;
//		key = getch();
//		if(key == ET){
//			// khong co du lieu thi thong bao
//			if(!createNotice("khong tim thay du lieu", "")){ // thong bao tra ve 0 thi thoat chuong trinh
//				return;
//			}
//			// chuong trinh tiep tuc, reset lai muc nhap
//			len = 0;
//			for(int i = 0; i < 15; i++) idStudent[i] = '\0';
//			createMenu(2);
//			drawFindStudent(text);
//		}
//		else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
//			// luu tru input, xuat input, timkiem, xuat danh sach
//			if(len < 15){
//				idStudent[len] = key;
//                idStudent[len + 1] = '\0'; //
//                len++;
//				outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, idStudent);
//			}
//		}
//	}
//}

int main(){
	
	initwindow(500, LPOINTY);
	
>>>>>>> a92bdb6c20cf2a49befe6019b5bd7b610576a03e
	// tao tien xu ly, khai bao
	string nameFileListStudent = "studentlist.txt";
	listStudent ls;
	readListStudent(ls, nameFileListStudent);

	//	getch();
	int selected = 1;
	createMenu(selected);
	
	while (1)
	{
		char key = getch();
		switch (key)
		{
		case ET:
			switch (selected)
			{
				//					case 1:

			case 2:
				studentManagement(ls);
				getch();
				closegraph();
				//						node* listStudent;
				//						openOnFile(listStudent, flistStudent);
				//
				//						studentManagment(listStudent);

				//						break;
				//					case 3:
				//						if(createNotice("Da chon Danh sach mon hoc", "")){
				//							drawMenu(selected);
				//						}
				//						else{
				//							cleardevice();
				//							closegraph();
				//						}
				//						break;
				//					case 4:
				//						if(createNotice("Da chon Danh sach dang ky lop hoc", "")){
				//							drawMenu(selected);
				//						}
				//						else{
				//							cleardevice();
				//							closegraph();
				//						}
				//						break;
			}
			break;
		case UP:
			if (selected > 1)
			{
				selected--;
				createMenu(selected);
			}
			break;
		case DOWN:
			if (selected < 4)
			{
				selected++;
				createMenu(selected);
			}
			break;
		}
	}

	getch();
	closegraph();
}