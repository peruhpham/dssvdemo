#ifndef DISPLAY_H
#define DISPLAY_H

const int UP = 72; 
const int DOWN = 80;
const int ET = 13;
const int ESC = 27;
const int SPACE = 32;
const int BP = 8; // backspace
const int SPOINTX = 0;
const int SPOINTY = 0;
const int LPOINTX = 1350;
const int LPOINTY = 700;

const int HEADSPOINTX = 0;
const int HEADSPOINTY = 0;
const int HEADLPOINTX = 1350;
const int HEADLPOINTY = 60; // chinh sua

const int MENUSPOINTX = 0;
const int MENUSPOINTY = 70;
const int MENULPOINTX = 320;
const int MENULPOINTY = 280;

const int BOTTSPOINTX = 0;
const int BOTTSPOINTY = 600;
const int BOTTLPOINTX = 1350;
const int BOTTLPOINTY = 600;

const int NOTISPOINTX = 400; // notice
const int NOTISPOINTY = 150;
const int NOTILPOINTX = 1010;
const int NOTILPOINTY = 350;

const int LISTSPOINTX = 340;
const int LISTSPOINTY = 70;
const int LISTLPOINTX = 1350;
const int LISTLPOINTY = 600;

const int TABLSPOINTX = 342;
const int TABLSPOINTY = 190;
const int TABLLPOINTX = 1350;
const int TABLLPOINTY = 480;

const int BOXSPOINTX = LISTSPOINTX + 250;
const int BOXSPOINTY = LISTSPOINTY + 70;
const int BOXLPOINTX = LISTSPOINTX + 450;
const int BOXLPOINTY = LISTSPOINTY + 100;


void setDefault(){
	setbkcolor(15); // mac dinh nen la mau trang
	setcolor(0); // mac dinh van ban la mau den
	setfillstyle(SOLID_FILL, WHITE); // mac dinh to khung hinh la mau trang
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1); // mac dinh font complex, co chu la 1
	setlinestyle(0, 1, 1);
}

void resetBox(){ // reset box nhap mac dinh khong co gi
	setfillstyle(SOLID_FILL, WHITE);
	bar(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY);
	setcolor(BLACK);
	rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY);
	setDefault();
}

void resetText(){ // reset thong bao mac dinh khong co gi
	setfillstyle(SOLID_FILL, WHITE);
	bar(BOXLPOINTX + 20, LISTSPOINTY + 70, BOXLPOINTX + 400, LISTSPOINTY + 100);
	setDefault();
}

void createHeader(){
	setfillstyle(SOLID_FILL, LIGHTBLUE); // tao trang head 
	bar(HEADSPOINTX, HEADSPOINTY, HEADLPOINTX, HEADLPOINTY); // tao hinh chu nhat to san mau nen
	
	setcolor(BLACK);
	settextstyle(DEFAULT_FONT, HORIZ_DIR, 4); // tao trang head
	outtextxy(40, 10, "TRANG CHU");
	
	setDefault();
}

void createBottom(){
	setlinestyle(0, 0, 2); // tao trang bottom
	line(BOTTSPOINTX, BOTTSPOINTY, BOTTLPOINTX, BOTTLPOINTY); // tao duong ke 
	outtextxy(10, BOTTLPOINTY + 10, "Thong tin them : "); 
	
	setDefault();
}

int createNotice(char *text1, char* text2){
	cleardevice();
	createHeader();
	
	setcolor(LIGHTRED); // thiet lap mau chu
	outtextxy(NOTISPOINTX + 250, NOTISPOINTY + 50, "Thong bao!");
	setcolor(BLACK);
	rectangle(NOTISPOINTX, NOTISPOINTY, NOTILPOINTX, NOTILPOINTY); // tao hop thong bao to khung theo mau chu k to mau nen
	
	outtextxy(NOTISPOINTX + 20, NOTISPOINTY + 100, text1);
	outtextxy(NOTISPOINTX + 20, NOTISPOINTY + 130, text2);
	outtextxy(NOTISPOINTX + 20, NOTISPOINTY + 160, "Nhan Enter de tiep tuc/ Esc de thoat chuong trinh");
	
	setDefault;
	
	char key;
	key = getch();
	cleardevice();
	if(key == ET){
		return 1;
	}
	return 0;
}

void createMenu(int selected){
	
	// tao menu 1
	
	cleardevice();
	setbkcolor(WHITE);
	cleardevice(); // xoa man hinh va to mau nen

	createHeader(); // tao header 
	setcolor(BLACK);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);

	if(selected == 1){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
		outtextxy(10, MENUSPOINTY + 10, "Quan ly lop tin chi");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
		outtextxy(10, MENUSPOINTY + 10, "Quan ly lop tin chi");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
	
	// tao menu 2
	
	setcolor(BLACK);
	if(selected == 2){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
		outtextxy(10, MENUSPOINTY + 50 , "Quan ly sinh vien");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
		outtextxy(10, MENUSPOINTY + 50 , "Quan ly sinh vien");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
	
	// tao menu 3
	setcolor(BLACK);
	if(selected == 3){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 300, MENUSPOINTY + 120);
		outtextxy(10, MENUSPOINTY + 90, "Quan ly mon hoc");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 300, MENUSPOINTY + 120);
		outtextxy(10, MENUSPOINTY + 90, "Quan ly mon hoc");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 300, MENUSPOINTY + 120);

	
	// tao menu 4
	setcolor(BLACK);
	if(selected == 4){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 300, MENUSPOINTY + 160);
		outtextxy(10, MENUSPOINTY + 130, "Quan ly dang ky lop hoc");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 300, MENUSPOINTY + 160);
		outtextxy(10, MENUSPOINTY + 130, "Quan ly dang ky lop hoc");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 300, MENUSPOINTY + 160);

	setDefault();
	createBottom();
	
}

void createTable(char *text){ // tao khung lon ben ngoai
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 60); // ve khung list
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, text);
	
	setlinestyle(0, 0, 1);
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY); // can le
	
	setDefault();
}

void createList(){ // tao khung nho ben trong
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLSPOINTX, TABLSPOINTY, TABLLPOINTX, TABLLPOINTY);
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setlinestyle(0, 0, 1);
	setcolor(LIGHTGRAY);
	
	bar(TABLSPOINTX, TABLSPOINTY, TABLLPOINTX, TABLSPOINTY + 40 ); // tao table hinh chu nhat
	rectangle(TABLSPOINTX, TABLSPOINTY, TABLLPOINTX, TABLLPOINTY); 
	line(TABLSPOINTX, TABLSPOINTY + 40, TABLLPOINTX, TABLSPOINTY + 40); // tao duong ke ngang
	line(TABLSPOINTX, TABLSPOINTY + 90, TABLLPOINTX, TABLSPOINTY + 90);
	line(TABLSPOINTX, TABLSPOINTY + 140, TABLLPOINTX, TABLSPOINTY + 140);
	line(TABLSPOINTX, TABLSPOINTY + 190, TABLLPOINTX, TABLSPOINTY + 190);
	line(TABLSPOINTX, TABLSPOINTY + 240, TABLLPOINTX, TABLSPOINTY + 240);
	
	line(TABLSPOINTX + 145, TABLSPOINTY, TABLSPOINTX + 145, TABLLPOINTY); // tao duong ke doc
	line(TABLSPOINTX + 365, TABLSPOINTY, TABLSPOINTX + 365, TABLLPOINTY);	
	line(TABLSPOINTX + 510, TABLSPOINTY, TABLSPOINTX + 510, TABLLPOINTY);	
	line(TABLSPOINTX + 610, TABLSPOINTY, TABLSPOINTX + 610, TABLLPOINTY);	
	line(TABLSPOINTX + 755, TABLSPOINTY, TABLSPOINTX + 755, TABLLPOINTY);	
	line(TABLSPOINTX + 900, TABLSPOINTY, TABLSPOINTX + 900, TABLLPOINTY);	
	
	
	setDefault();
}


void drawUpdateStudent(){
	
	createTable("Tra cuu thong tin");
	createList();
	
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 2); // tao khung nhap mssv
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 80, "Vui long nhap MSSV:");
	rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); 

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1); // tieu de tren bang danh sach
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	outtextxy(TABLSPOINTX + 10, TABLSPOINTY + 10, "MSSV");
	outtextxy(TABLSPOINTX + 155, TABLSPOINTY + 10, "HO");
	outtextxy(TABLSPOINTX + 375, TABLSPOINTY + 10, "TEN");
	outtextxy(TABLSPOINTX + 520, TABLSPOINTY + 10, "PHAI");
	outtextxy(TABLSPOINTX + 620, TABLSPOINTY + 10, "SDT");
	outtextxy(TABLSPOINTX + 765, TABLSPOINTY + 10, "MA LOP");
	outtextxy(TABLSPOINTX + 910, TABLSPOINTY + 10, "KHOA");
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setbkcolor(LIGHTGRAY);
	bar(TABLSPOINTX + 85, TABLLPOINTY + 50, TABLSPOINTX + 305, TABLLPOINTY + 90);
	outtextxy(TABLSPOINTX + 115, TABLLPOINTY + 60, "Them thong tin");
	bar(TABLSPOINTX + 390, TABLLPOINTY + 50, TABLSPOINTX + 610, TABLLPOINTY + 90);
	outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 60, "Sua thong tin");
	bar(TABLSPOINTX + 695, TABLLPOINTY + 50, TABLSPOINTX + 915, TABLLPOINTY + 90);
	outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 60, "Xoa thong tin");
	setDefault();
}

void drawStudentManagement(int selected){
	char text[50] = "Quan ly sinh vien";
	
	cleardevice();
	
	createHeader();
	createBottom();
	
	// tieu de tren bang menu 
	setbkcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
	outtextxy(10, MENUSPOINTY + 10, text); 
	setDefault();

	// tao menu 1

	sprintf(text, "%c Cap nhat thong tin", 62);
	setcolor(BLACK);
	if(selected == 1){
		setcolor(LIGHTBLUE);
		outtextxy(10, MENUSPOINTY + 55, text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 55, text);
	}

	// tao menu 2
	
	sprintf(text, "%c Xem danh sach theo lop", 62);
	setcolor(BLACK);
	if(selected == 2){
		setcolor(LIGHTBLUE);
		outtextxy(10, MENUSPOINTY + 95 , text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 95 , text);
	}
	
	setcolor(LIGHTGRAY);
	line(MENUSPOINTX + 10, MENUSPOINTY + 45, MENUSPOINTX + 290, MENUSPOINTY + 45);
	line(MENUSPOINTX + 10, MENUSPOINTY + 85, MENUSPOINTX + 290, MENUSPOINTY + 85);
	line(MENUSPOINTX + 10, MENUSPOINTY + 125, MENUSPOINTX + 290, MENUSPOINTY + 125);
//	line(MENUSPOINTX + 10,  MENUSPOINTY + 165, MENUSPOINTX + 290, MENUSPOINTY + 165);
//	line(MENUSPOINTX + 10, MENUSPOINTY + 205, MENUSPOINTX + 290, MENUSPOINTY + 205);

	setDefault();
}

#endif
