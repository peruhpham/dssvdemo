#ifndef SUBJECTMANAGEMENT_H 
#define SUBJECTMANAGEMENT_H

//#include "datastructure.h"
//#include "datahanding.h"
//#include "display.h"
// using namespace std;
 

#define MENU_SUB_SX 0
#define MENU_SUB_SY 190
#define MENU_SUB_LX 300
#define MENU_SUB_LY 310

#define TABLE_SX 700
#define TABLE_SY 70
#define TABLE_LX 1350
#define TABLE_LY 440 + 1

#define TABLE_CONTROL_SX 340
#define TABLE_CONTROL_SY 70
#define TABLE_CONTROL_LX 680
#define TABLE_CONTROL_LY 600


#define ENTER 13
#define ESC 27
#define SPACE 32
#define BACKSPACE 8

#define MENU_ITEM_HEIGHT 40 //Chiều cao của mỗi mục trong menu
#define D_ROW 22
// #define MAX_MON_HOC 100



// Khai bao nguyen mau ham
void subjectManagement(listSubject &lsb);
void drawTableListSubject ();
void displaySubjectList(ptrSubject root);
void resetDisplaySubjectList(int &x, int &y);

void hightlightLineSubject();
void drawHeaderAndBottom();

void drawMenuSubject();
void drawMenuAndUpdateSelection(listSubject &lsb, int &selectedItem);
// void drawMenuAndUpdateSelection(listSubject &lsb);

void copyAVLToArray(ptrSubject root, subject arrSubject[], int& index);
//void displaySubjectListByControl();

void printSTT (listSubject &lsb);
void printListSubjectByName(subject *sub, int x, int y);
// void inorderTraversal(ptrSubject root, subject staticArray[], int& index);
void AVLToArray(ptrSubject currentNodeSubject, subject *arrayTmp, int &currentIndex);


void drawTableControlSubject();// draw bang dieu khien
void removeTableConsolSubject();// che lai man hinh khu vuc dieu khien va bang du lieu
void reloadingDataSubject();
void drawMenuStartSubject();
void drawScrollBarSubject();

void menuTQSubject(int selected);

void enterText(listSubject &lsb);// ham nhap chu
void highlightFrame(int x1, int y1, int x2, int y2);
void highlightFrame();
void highlightFrameDefault(int x1, int y1, int x2, int y2);
void mouseHighlightInputExamScores(int &selected, int &on);
void highlightClickMouse(int x, int y, listSubject &lsb);

void controlAddDeleteSubject();
//=====================================================================================================



// Tao giao dien moi cDanh sach mon hoc
void drawTableListSubject (){
	setcolor(LIGHTGRAY);
	rectangle(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);

	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);
	//----------------------------------------------------------------
	// new table
	setlinestyle(SOLID_LINE, 0, 1);
	//khung 
	setcolor(LIGHTGRAY);
	rectangle(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);
	//----------------
	// vẽ thanh cuộn 
	//----------------------------------------------------------------
	drawScrollBarSubject();// ve thanh cuon cho bang subject.
	
	//-------
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(LIGHTGRAY);
	line(TABLE_SX + 50, TABLE_SY, TABLE_SX + 50, TABLE_LY);
	line(TABLE_SX + 50 + 120, TABLE_SY, TABLE_SX + 50 + 120, TABLE_LY);
	line(TABLE_SX + 50 + 120 + 340, TABLE_SY, TABLE_SX + 50 + 120 +340, TABLE_LY);
	line(TABLE_SX + 50 + 120 + 340 + 60, TABLE_SY, TABLE_SX + 50 + 120 + 340 + 60, TABLE_LY);
	
    setfillstyle(SOLID_FILL, LIGHTBLUE);// Thiet lap mau fill la mau xanh lam
    bar(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_SY + 40);// Ve hinh chu nhat
	
	setlinestyle(SOLID_LINE, 0, 1);
	setcolor(LIGHTGRAY);
    for (int y = TABLE_SY + 40; y < TABLE_LY; y += D_ROW) {
        line(TABLE_SX, y, TABLE_LX-20, y);
    }
	// ve dupng thang phia sau
	line(TABLE_LX-20, TABLE_SY+40, TABLE_LX-20, TABLE_LY);
    // Thiet lap mau nen chu
    setbkcolor(LIGHTBLUE);
    setcolor(BLACK);
    outtextxy(TABLE_SX + 5, TABLE_SY + 10, "STT");
    outtextxy(TABLE_SX + 2 + 50, TABLE_SY + 10, "MA MON HOC");
    outtextxy(TABLE_SX + 110 + 50 + 120, TABLE_SY + 10, "TEN MON HOC");
    outtextxy(TABLE_SX + 2 + 50 + 120 + 340, TABLE_SY + 10, "STCLT");
    outtextxy(TABLE_SX + 2 + 50 + 120 + 340 + 60, TABLE_SY + 10, "STCTH");

	setDefault();
}
//----------------------------------------------------------------

int x = TABLE_SX + 50, y = TABLE_SY + D_ROW/10 - 1 + 40;

void displaySubjectList(ptrSubject root) {
    if (root != nullptr) {
        if (root->left != nullptr) {    
            displaySubjectList(root->left);     
        }
        setbkcolor(WHITE);
        setcolor(BLACK); 
        outtextxy(20 + x, y, const_cast<char*>(root->data.idSubject.c_str())); 
        outtextxy(20 + x + 120, y, const_cast<char*>(root->data.nameSubject.c_str())); 
        outtextxy(20 + x + 120 + 340, y, const_cast<char*>(to_string(root->data.STCLT).c_str())); 
        outtextxy(20 + x + 120 + 340 + 60, y, const_cast<char*>(to_string(root->data.STCTH).c_str())); 
        y += D_ROW;
        if (root->right != nullptr) {
            displaySubjectList(root->right); 
        }
    }

	setDefault();
}

void resetDisplaySubjectList(int &x, int &y){
    x = TABLE_SX + 50;
    y = TABLE_SY + D_ROW/10 -1 + 40;
}

//----------------------------------------------------------------

//----------------------------------------------------------------
void hightlightLineSubject(){

}
//----------------------------------------------------------------
void drawHeaderAndBottom(){
	createHeader();
	createBottom();
}

//----------------------------------------------------------------
void drawMenuSubject(){
	setfillstyle(SOLID_FILL, WHITE);//Thiet lap mau cho khung menu subject
	setcolor(WHITE);
	rectangle(MENU_SUB_SX, MENU_SUB_SY, MENU_SUB_LX, MENU_SUB_LY);

	setbkcolor(WHITE); 
	bar(MENU_SUB_SX, MENU_SUB_SY, MENU_SUB_LX, MENU_SUB_LY);

	for(int i = MENU_SUB_SY + 30; i <= MENU_SUB_LY; i+=30){
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		line(MENU_SUB_SX, i, MENU_SUB_LX, i);

	}

	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	setcolor(BLACK);
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY, ">>Danh sach mon theo ID");
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY + 40, ">>Danh sach mon theo Ten");
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY + 80, ">>Nhap mon hoc");

	setDefault();
}
//----------------------------------------------------------------
void printSTT (listSubject &lsb){
	char number[4]; // luu tru day so tu dong tang
	for(int i=0; i<lsb.size; i++){
		sprintf(number, "%03d", i + 1);
		setbkcolor(WHITE);
		setcolor(BLACK);
		// setfillstyle(SOLID_FILL, YELLOW);
		outtextxy(TABLE_SX + 10, TABLE_SY + 40 + i*D_ROW + D_ROW/10 - 1, number);	
	}
	setDefault();
	cout << lsb.size << endl;
	cout << "da in so thu tu thanh cong\n";
}
//----------------------------------------------------------------

//----------------------------------------------------------------
// reset lại menu dieu kien subject.
void resetMenuSubject(int &selectedItem){
	int y = MENU_SUB_SY; // Vị trí y của menu đầu tiên

    // In ra menu
    outtextxy(MENU_SUB_SX, 10 + y, ">> Danh sach mon theo ID");
    outtextxy(MENU_SUB_SX, 10 + y + MENU_ITEM_HEIGHT, ">> Danh sach mon theo Ten");
    outtextxy(MENU_SUB_SX, 10 + y + 2 * MENU_ITEM_HEIGHT, ">> Nhap mon hoc");

    char key;
    while (1) {
		if(selectedItem == 0){
			setcolor(BLUE);
            outtextxy(MENU_SUB_SX, 10 + y, ">> Danh sach mon theo ID");
		}

        if (kbhit()) {
			
            key = getch();
            // cleardevice(); // Xóa màn hình để vẽ lại menu
            if (key == 72) {// Xử lý phím lên
                selectedItem = (selectedItem - 1 + 3) % 3;
            }
            else if (key == 80) {// Xử lý phím xuống
                selectedItem = (selectedItem + 1) % 3;
            }
            // In lại menu với lựa chọn mới được tô sáng
            y = MENU_SUB_SY;
			setcolor(BLACK);
            outtextxy(MENU_SUB_SX, 10 + y, ">> Danh sach mon theo ID");
            outtextxy(MENU_SUB_SX, 10 + y + MENU_ITEM_HEIGHT, ">> Danh sach mon theo Ten");
            outtextxy(MENU_SUB_SX, 10 + y + 2 * MENU_ITEM_HEIGHT, ">> Nhap mon hoc");
            // Tô sáng lựa chọn hiện tại
			if(selectedItem == 0){
				setcolor(BLUE);
            	outtextxy(MENU_SUB_SX, 10 + y, ">> Danh sach mon theo ID");
			}
			else if(selectedItem == 1){
				setcolor(BLUE);
				outtextxy(MENU_SUB_SX, 10 + y + MENU_ITEM_HEIGHT, ">> Danh sach mon theo Ten");
			}
			else if(selectedItem == 2){
				setcolor(BLUE);
				outtextxy(MENU_SUB_SX, 10 + y + 2 * MENU_ITEM_HEIGHT, ">> Nhap mon hoc");
			}

            setcolor(WHITE); // Reset màu về mặc định
        }
	}
	setDefault();
}

//----------------------------------------------------------------
//chuyen du lieu tu cay avl sang array
void AVLtoArray(nodeSubject* currentNodeSubject, subject *arrayTmp, int &currentIndex){
	if(currentNodeSubject != nullptr){
		AVLtoArray(currentNodeSubject->left, arrayTmp, currentIndex);
		arrayTmp[currentIndex] = currentNodeSubject->data;
		currentIndex++;
		AVLtoArray(currentNodeSubject->right, arrayTmp, currentIndex);
	}
}

void countNodeSubject(nodeSubject* currentNodeSubject, int &arraySize) {
	if(currentNodeSubject != nullptr){
		countNodeSubject(currentNodeSubject->left, arraySize);
		arraySize++;
		countNodeSubject(currentNodeSubject->right, arraySize);
	}
	cout << arraySize << " ";
	cout << endl;
}

subject* arraySubject(nodeSubject* currentNodeSubject, int &arraySize) {
	countNodeSubject(currentNodeSubject, arraySize);
	subject *arraySub = new subject[arraySize];
	int currentIndex = 0;
	AVLtoArray(currentNodeSubject, arraySub, currentIndex);
	return arraySub;
}

//In danh sach theo thu tu ten mon hoc.
void printListSubjectByName(subject *sub, int &x, int &y){
	for(int i=0; i<5; i++){
		outtextxy(TABLE_SX + 50, y, tochar(sub[i].idSubject));
		outtextxy(TABLE_SX + 50 + 120, y, tochar(sub[i].nameSubject));
		outtextxy(TABLE_SX + 50 + 120 + 340, y, tochar(to_string(sub[i].STCLT)));
		outtextxy(TABLE_SX + 50 + 120 + 340 + 60, y, tochar(to_string(sub[i].STCTH)));
	}
	y += D_ROW;
}

//----------------------------------------------------------------
//draw bang do hoa xu ly them sua xoa mon hoc.
void drawTableControlSubject(){ //draw bang do hoa xu ly them sua xoa mon hoc.
	setcolor(BLUE);
	rectangle(TABLE_CONTROL_SX, TABLE_CONTROL_SY, TABLE_CONTROL_LX, TABLE_CONTROL_LY-10); // draw vien do

	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(TABLE_CONTROL_SX+1, TABLE_CONTROL_SY+1, TABLE_CONTROL_LX-1, TABLE_CONTROL_LY-11); // draw nen gray
	
	
	outtextxy(TABLE_CONTROL_SX + 2, TABLE_CONTROL_SY, "CAP NHAT THONG TIN");// tieu de bang dieu khien
	setDefault();
	//------------------------
	setcolor(BLUE);
	setbkcolor(LIGHTCYAN);
	settextstyle(SMALL_FONT, HORIZ_DIR, 6);// dieu chinh kich thuoc chu

	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60-20 , "Ma mon hoc:");
	rectangle(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);// o de nhap thong tin id mon hoc
	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 120-20 , "Ten mon hoc:");
	rectangle(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60 + 30 + 30, TABLE_CONTROL_SX + 330, TABLE_CONTROL_SY + 90 + 30 + 30);// o de nhap thong tin id mon hoc
	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 158, "So tin chi");
	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175, "Ly thuyet:");
	rectangle(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 100, TABLE_CONTROL_SY + 195 + 30);// o de nhap thong tin id mon hoc
	outtextxy(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175, "Thuc hanh:");
	rectangle(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100, TABLE_CONTROL_SY + 195 + 30);// o de nhap thong tin id mon hoc
	
	// set mau nen backgrough cho khung dien thong tin
	setbkcolor(WHITE);
	bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
	bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 60 + 30 + 30, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);// o de nhap thong tin id mon hoc
	bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 175 + 20, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);// o de nhap thong tin id mon hoc
	bar(TABLE_CONTROL_SX + 1 + 5 + 150, TABLE_CONTROL_SY + 1 + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);// o de nhap thong tin id mon hoc
	setDefault();

	// phan hien thi cho cap nhat them/ sua / xoa .... 340px den 680px = 340px -> moi o 100px -> kc 10px
	setcolor(BLUE);
	rectangle(TABLE_CONTROL_SX + 10, TABLE_CONTROL_SY + 50 + 250, TABLE_CONTROL_SX + 10 + 100, TABLE_CONTROL_SY + 50 + 250 + 30);
	rectangle(TABLE_CONTROL_SX + 10 + 100 + 10, TABLE_CONTROL_SY + 50 + 250, TABLE_CONTROL_SX + 10 + 100 + 110, TABLE_CONTROL_SY + 50 + 250 + 30);
	rectangle(TABLE_CONTROL_SX + 10 + 110*2, TABLE_CONTROL_SY + 50 + 250, TABLE_CONTROL_SX + 10 + 100 + 110*2, TABLE_CONTROL_SY + 50 + 250 + 30);
	setDefault();
	setbkcolor(WHITE);
	bar(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX - 1 + 10 + 100, TABLE_CONTROL_SY + 50 - 1 + 250 + 30);
	bar(TABLE_CONTROL_SX + 1 + 10 + 100 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX  - 1 + 10 + 100 + 110, TABLE_CONTROL_SY + 50 - 1 + 250 + 30);
	bar(TABLE_CONTROL_SX + 1 + 10 + 110*2, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX  - 1 + 10 + 100 + 110*2, TABLE_CONTROL_SY + 50 - 1 + 250 + 30);
	setDefault();
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	outtextxy(TABLE_CONTROL_SX + 10 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "(+)THEM");
	outtextxy(TABLE_CONTROL_SX + 10 + 110 + 10, TABLE_CONTROL_SY + 50 + 250 + 5,"(-)XOA");
	outtextxy(TABLE_CONTROL_SX + 10 + 110*2 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "(+-)SUA");
	setDefault();

	// draw muc search id hoac ten mon hoc sẽ hien ra thong tin can sua chua.
	setcolor(BLUE);
	setbkcolor(LIGHTCYAN);
	outtextxy(TABLE_CONTROL_SX + 10, TABLE_CONTROL_SY + 50 + 250 + 5 + 35, "Tim kiem: ");

	rectangle(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30, TABLE_CONTROL_SX - 1 + 10 + 300, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60);
	setbkcolor(WHITE);
	bar(TABLE_CONTROL_SX + 1 + 10 + 1, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 1, TABLE_CONTROL_SX - 1 + 10 + 300 - 1, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60 - 1);
	setDefault();

}

// Che lai man hinh khu vuc dieu khien va bang du lieu.
void removeTableConsolSubject(){
	setcolor(BLUE);
	rectangle(TABLE_CONTROL_SX, TABLE_CONTROL_SY, TABLE_LX, TABLE_LY + 149);
	// getch();
	bar(TABLE_CONTROL_SX, TABLE_CONTROL_SY, TABLE_LX + 2, TABLE_LY + 150);
}

//Load lai du lieu trong danh sach mon hoc.
void reloadingDataSubject(){
	string nameFileListSubject = "data\\subjectlist.txt";

	listSubject lsub;

	readListSubject(lsub, nameFileListSubject);
	std::cout << "\n" << "DA RELOADING THANH CONG DANH SACH SSUBJECT.\n";
}

// Ve thanh cuon cho table subject.
void drawScrollBarSubject(){
	int x1 = TABLE_LX - 20, y1 = TABLE_SY + 40 + 14;
	int x2 = TABLE_LX - 20 + 8, y2 = TABLE_SY + 40;
	int x3 = TABLE_LX - 20 + 16, y3 = TABLE_SY + 40 + 14;
	
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	int points1[] = {x1, y1, x2, y2, x3, y3, x1, y1};
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillpoly(4, points1);

	int u1 = TABLE_LX - 20 + 1, v1 = TABLE_LY - 14;
	int u2 = TABLE_LX - 20 + 1 + 8, v2 = TABLE_LY;
	int u3 = TABLE_LX - 20 + 1 + 16, v3 = TABLE_LY - 14;
	line(u1, y1, u2, v2);
	line(u2, y2, u3, v3);
	line(u3, y3, u1, v1);
	int points2[] = {u1, v1, u2, v2, u3, v3, u1, v1};
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillpoly(4, points2);

	//ve thanh sang theo du lieu
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_LX - 19, TABLE_SY + 41 + 16, TABLE_LX - 1, TABLE_LY - 1 - 16);

	setDefault();
}

void menuTQSubject(int selected){
	char text[50];
	cleardevice();
	
	createHeader();
	createBottom();

	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
	outtextxy(10, MENUSPOINTY + 10, "Lop sinh vien");
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
	setDefault();
	
	setbkcolor(WHITE);
	setfillstyle(SOLID_FILL, WHITE);
	bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
	outtextxy(10, MENUSPOINTY + 50, "Lop tin chi");
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80); 
	setDefault();

	setbkcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(MENUSPOINTX, MENUSPOINTY + 40 + 40, MENUSPOINTX + 300, MENUSPOINTY + 80 + 40);
	outtextxy(10, MENUSPOINTY + 50 + 40, "Mon hoc");
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 40 + 40, MENUSPOINTX + 300, MENUSPOINTY + 80 + 40); 
	setDefault();


	// bat dau tao menu con 
	sprintf(text, "%c Danh sach theo ID", 62);
	setcolor(BLACK);
	if(selected == 0){
		setcolor(BLUE);
		outtextxy(10, MENUSPOINTY + 95 + 40, text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 95 + 40, text);
	}

	// tao menu 2
	
	sprintf(text, "%c Danh sach theo ten", 62);
	setcolor(BLACK);
	if(selected == 1){
		setcolor(BLUE);
		outtextxy(10, MENUSPOINTY + 135 + 40 , text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 135 + 40 , text);
	}
	
	sprintf(text, "%c Cap nhat danh sach", 62);
	setcolor(BLACK);
	if(selected == 2){
		setcolor(BLUE);
		outtextxy(10, MENUSPOINTY + 175 + 40 , text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 175 + 40, text);
	}

	setDefault();
}

// Ve menu cac lenh dieu khien cua mon hoc.
void drawMenuStartSubject(){
	setfillstyle(SOLID_FILL, WHITE);
	bar(MENU_SUB_SX, MENU_SUB_SY, MENU_SUB_LX + 2, MENU_SUB_LY);// ve lai bang chua cac muc dieu khien.

	setcolor(BLACK);
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY, ">> Danh sach mon theo ID");
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY + MENU_ITEM_HEIGHT, ">> Danh sach mon theo Ten");
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY + 2 * MENU_ITEM_HEIGHT, ">> Nhap mon hoc");

	setDefault();
}

//------------------------------------------------------------------------------------------------------------


//hightlight khung viet chu
void highlightFrame(int x1, int y1, int x2, int y2){
	setcolor(LIGHTRED);
	rectangle(x1, y1, x2, y2);	
	setbkcolor(LIGHTGRAY);
	bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	
	setDefault();
}
// reset lai khunng da hightlight truoc do
void highlightFrameDefault(int x1, int y1, int x2, int y2){
	setcolor(BLUE);
	rectangle(x1, y1, x2, y2);	
	// setbkcolor(WHITE);
	// bar(x1 + 1, y1 + 1, x2 - 1, y2 - 1);
	
	setDefault();
}

//Hightlight khi co click mouse vao khung nhap chu
void highlightClickMouse(int x, int y, listSubject &lsb){
	// Neu click mouse gap thi hightlight thanh sang cho thanh search 
	if(TABLE_CONTROL_SX + 1 + 10 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 <= y && x <= TABLE_CONTROL_SX - 1 + 10 + 300 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60){
		// Neu click mouse gap thi hightlight thanh sang cho thanh search
		highlightFrame(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30, TABLE_CONTROL_SX - 1 + 10 + 300, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60);

		//Xu li nhâp du lieu vao khung search 
		const int sizeText = 30;
		int index = 0;
		char textSearch[sizeText];
		bool isPrevSpace = true;

		std::cout << "Nhap vao mot chuoi search (nhap Enter de ket thuc):\n";
		while (true) { 
			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
				char text = getch(); 

				if (text == SPACE) {
					if (index == 0 || isPrevSpace) { // Loại bỏ dấu cách đầu hoặc liên tiếp
						continue;
					}
					isPrevSpace = true;
				} else {
					isPrevSpace = false;
				}

				if (text == ENTER) { 
					break; 
				}
				// else if(text == SPACE){
				// 	continue;
				// }
				else if (text == BACKSPACE) { 
					if (index > 0) { 
						std::cout << "\b \b"; 
						index--; 
						textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
						// cout << textSearch << endl;
						setcolor(BLUE);
						setbkcolor(YELLOW);
						bar(TABLE_CONTROL_SX + 1 + 10 + 1, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 1, TABLE_CONTROL_SX - 1 + 10 + 300 - 1, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60 - 1);
						textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
						outtextxy(TABLE_CONTROL_SX + 1 + 10 + 5, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 5, textSearch);

						setDefault();
					}
				}
				else if (index < sizeText - 1) { 
					textSearch[index++] = text; 
					textSearch[0] = toupper(textSearch[0]);
					std::cout << text; 
					setcolor(BLUE);
					setbkcolor(YELLOW);
					bar(TABLE_CONTROL_SX + 1 + 10 + 1, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 1, TABLE_CONTROL_SX - 1 + 10 + 300 - 1, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60 - 1);
					textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
					outtextxy(TABLE_CONTROL_SX + 1 + 10 + 5, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 5, textSearch);

					setDefault();
				}
			}
		}
		textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
		std::cout << "\nChuoi da nhap: " << textSearch << std::endl;
		setcolor(BLUE);
		setbkcolor(WHITE);
		bar(TABLE_CONTROL_SX + 1 + 10 + 1, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 1, TABLE_CONTROL_SX - 1 + 10 + 300 - 1, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60 - 1);
		outtextxy(TABLE_CONTROL_SX + 1 + 10 + 5, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 5, textSearch);

	}
	else {
		highlightFrameDefault(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30, TABLE_CONTROL_SX - 1 + 10 + 300, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60);
	}

	// MUC ID
	if(TABLE_CONTROL_SX + 5 <= x && TABLE_CONTROL_SY + 30 + 30 <= y && TABLE_CONTROL_SX + 120 >= x && y <= TABLE_CONTROL_SY + 60 + 30){
		// Neu click mouse gap thi hightlight thanh sang cho thanh search
		highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);

		//xu li nhâp du lieu vao khung id
		const int sizeTextId = 8; 
		char stringTextId[sizeTextId]; 
		int indexId = 0; 
		std::cout << "Nhap vao mot chuoi id (nhap Enter de ket thuc):\n";
		while (true) { 
			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
				char textId = getch(); 
				if (textId == ENTER) { 
					break; 
				}
				else if(textId == SPACE){
					continue;
				}
				else if (textId == BACKSPACE) { 
					if (indexId > 0) { 
						std::cout << "\b \b"; 
						indexId--; 
						stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
						// cout << textSearch << endl;
						setcolor(BLUE);
						setbkcolor(YELLOW);
						bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
						stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
						outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextId);

						setDefault();
					}
				}
				else if (indexId < sizeTextId - 1) { 
					//Neu 3 ki tu dau tien thi mac dinh la chu in hoa.
					if((('A' <= textId && textId <= 'Z') || ('a' <= textId && textId <= 'z')) && (0 <= indexId && indexId <= 2)){
						stringTextId[indexId++] = toupper(textId); 
						std::cout << textId; 
					}
					else if((3 <= indexId && indexId <= 6) && ('0' <= textId && textId <= '9')){
						stringTextId[indexId++] = textId;
						std::cout << textId; 
					}
					setcolor(BLUE);
					setbkcolor(YELLOW);
					bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
					stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
					outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextId);

					setDefault();
				}
			}
		}
		stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
		std::cout << "\nChuoi da nhap: " << stringTextId << std::endl;
		setcolor(BLUE);
		setbkcolor(WHITE);
		bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
		outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextId);

		setDefault();

		//----------------------------------------------------------------------------------------------
		// xu ly bo nho tai day la xong phim.



		//----------------------------------
	}
	else {
		highlightFrameDefault(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);
	}

	// Muc ten mon hoc
	if(TABLE_CONTROL_SX + 5 <= x && TABLE_CONTROL_SY + 60 + 30 + 30 <= y && TABLE_CONTROL_SX + 330 >= x && y <= TABLE_CONTROL_SY + 90 + 30 + 30){
		// Neu click mouse gap thi hightlight thanh sang cho thanh search
		highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60 + 30 + 30, TABLE_CONTROL_SX + 330, TABLE_CONTROL_SY + 90 + 30 + 30);

		//xu li nhâp du lieu vao khung search
		const int sizeTextName = 25; 
		char textName[sizeTextName]; 
		int indexName = 0; 
		bool isPrevSpace = true; // Biến để theo dõi xem ký tự trước đó có phải là dấu cách không

		std::cout << "Nhap vao mot chuoi ten mon hoc (nhap Enter de ket thuc):\n";
		while (true) { 
			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
				char text = getch(); 

				if (text == SPACE) {
					if (indexName == 0 || isPrevSpace) { // Loại bỏ dấu cách đầu hoặc liên tiếp
						continue;
					}
					isPrevSpace = true;
				} else {
					isPrevSpace = false;
				}

				if (text == ENTER) { 
					break; 
				}
				else if (text == BACKSPACE) { 
					if (indexName > 0) { 
						std::cout << "\b \b"; 
						indexName--; 
						// cout << textSearch << endl;
						setcolor(BLUE);
						setbkcolor(YELLOW);
						bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 60 + 30 + 30 + 1, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);
						textName[indexName] = '\0'; // Thêm ký tự kết thúc chuỗi
						outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 60 + 30 + 30 + 5, textName);

						setDefault();
					}
				}
				else if (indexName < sizeTextName - 1) { 
					textName[indexName++] = text; 
					textName[0] = toupper(textName[0]);
					std::cout << text; 
					setcolor(BLUE);
					setbkcolor(YELLOW);
					bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 60 + 30 + 30 + 1, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);
					textName[indexName] = '\0'; // Thêm ký tự kết thúc chuỗi
					outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 60 + 30 + 30 + 5, textName);

					setDefault();
				} 
			}
		}
		textName[indexName] = '\0'; // Thêm ký tự kết thúc chuỗi
		std::cout << "\nChuoi da nhap: " << textName << std::endl;
		setcolor(BLUE);
		setbkcolor(WHITE);
		bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 60 + 30 + 30 + 1, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);
		outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 60 + 30 + 30 + 5, textName);

		setDefault();
	}
	else {
		highlightFrameDefault(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60 + 30 + 30, TABLE_CONTROL_SX + 330, TABLE_CONTROL_SY + 90 + 30 + 30);
	}

	// Muc so tin chi ly thuyet
	if(TABLE_CONTROL_SX + 5 <= x && TABLE_CONTROL_SY + 175 + 20 <= y && TABLE_CONTROL_SX + 100 >= x && y <= TABLE_CONTROL_SY + 195 + 30){
		// Neu click mouse gap thi hightlight thanh sang cho thanh search
		highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 100, TABLE_CONTROL_SY + 195 + 30);

		//xu li nhâp du lieu vao khung ly thuyet
		// char key;
		const int sizeTextLT = 4; 
		char textLT[sizeTextLT]; 
		int indexLT = 0; 
		std::cout << "Nhap vao mot chuoi so tin chi ly thuyet (nhap Enter de ket thuc):\n";
		while (true) { 
			if (kbhit()) { 
				char text = getch(); 
				if (text == ENTER) { 
					break; 
				}
				else if(text == SPACE){
					continue;
				}
				else if (text == BACKSPACE) { 
					if (indexLT > 0) { 
						std::cout << "\b \b"; 
						indexLT--; 
						textLT[indexLT] = '\0'; // Thêm ký tự kết thúc chuỗi
						// cout << textSearch << endl;
						setcolor(BLUE);
						setbkcolor(YELLOW);
						bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
						outtextxy(TABLE_CONTROL_SX + 5 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textLT);

						setDefault();
					}
				}
				else if (indexLT < sizeTextLT - 1) { 
					if('0' <= text && text <= '9')
						textLT[indexLT++] = text; 
					std::cout << text; 
					textLT[indexLT] = '\0'; // Thêm ký tự kết thúc chuỗi
					setcolor(BLUE);
					setbkcolor(YELLOW);
					bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
					outtextxy(TABLE_CONTROL_SX + 5 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textLT);

					setDefault();
				}
			}
		}
		textLT[indexLT] = '\0'; // Thêm ký tự kết thúc chuỗi
		std::cout << "\nChuoi da nhap: " << textLT << std::endl;
		setcolor(BLUE);
		setbkcolor(WHITE);
		bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
		outtextxy(TABLE_CONTROL_SX + 5 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textLT);

		setDefault();
	}
	else {
		highlightFrameDefault(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 100, TABLE_CONTROL_SY + 195 + 30);
	}

	// muc so tin chi thuc hanh
	if(TABLE_CONTROL_SX + 5 + 150 <= x && TABLE_CONTROL_SY + 175 + 20 <= y && TABLE_CONTROL_SX + 5 + 150 + 100 >= x && y <= TABLE_CONTROL_SY + 195 + 30){
		// Neu click mouse gap thi hightlight thanh sang cho thanh search
		highlightFrame(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100, TABLE_CONTROL_SY + 195 + 30);

		//xu li nhâp du lieu vao khung thuc hanh
		// char key;
		const int sizeTextTH = 4; 
		char textTH[sizeTextTH]; 
		int indexTH = 0; 
		std::cout << "Nhap vao mot chuoi so tin chi thuc hanh (nhap Enter de ket thuc):\n";
		while (true) { 
			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
				char text = getch(); 
				if (text == ENTER) { 
					break; 
				}
				else if(text == SPACE){
					continue;
				}
				else if (text == BACKSPACE) { 
					if (indexTH > 0) { 
						std::cout << "\b \b"; 
						indexTH--; 
						// cout << textSearch << endl;
						setcolor(BLUE);
						setbkcolor(YELLOW);
						bar(TABLE_CONTROL_SX + 5 + 150 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
						textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
						outtextxy(TABLE_CONTROL_SX + 5 + 150 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textTH);

						setDefault();
					}
				}
				else if (indexTH < sizeTextTH - 1) { 
					if('0' <= text && text <= '9')
						textTH[indexTH++] = text; 
					std::cout << text; 
					setcolor(BLUE);
					setbkcolor(YELLOW);
					bar(TABLE_CONTROL_SX + 5 + 150 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
					textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
					outtextxy(TABLE_CONTROL_SX + 5 + 150 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textTH);

					setDefault();
				}
			}
		}
		textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
		std::cout << "\nChuoi da nhap: " << textTH << std::endl;
		setcolor(BLUE);
		setbkcolor(WHITE);
		bar(TABLE_CONTROL_SX + 5 + 150 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
		textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
		outtextxy(TABLE_CONTROL_SX + 5 + 150 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textTH);

		setDefault();
	}
	else {
		highlightFrameDefault(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100, TABLE_CONTROL_SY + 195 + 30);
	}



}

// ham nhap chu vao khung 
void enterText(listSubject &lsb){
	while(1){

	}
}

// Phan xu lý/////////////////////////////////////////
//----------------------------------------------------------------
//Dieu khien them sua xoa tai man hinh mon hoc
void controlAddDeleteSubject(listSubject &lsb){
	char key;
	int ascii;
	int x, y;

	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}

			if(ascii == ESC){
	    		if(!createNotice("Ban co muon luu lai du lieu!", "")){
	    			return;
				}
			}
		}

		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);

			highlightClickMouse(x, y, lsb);


		}
		
	}
}



// Hàm vẽ menu và cập nhật lựa chọn
void drawMenuAndUpdateSelection(listSubject &lsb, int &selectedItem) {
    int y = MENU_SUB_SY; // Vị trí y của menu đầu tiên
	cout << selectedItem << " draw menu" << endl;
	char key;
	while(1){
		if(selectedItem == 0){
			cout << "selectItem 0" << endl;
			reloadingDataSubject();
			drawTableControlSubject();
			// Xu li enter tai day
			drawTableListSubject ();
			//print Danh sach theo tên môn hoc.
			printSTT(lsb);
			int arraySize = 0;
			subject* subjectListArray = arraySubject(lsb.root, arraySize);
			y = TABLE_SY + 40 + D_ROW/10 -1;
			drawTableListSubject();
			printSTT(lsb);
			for(int i=0; i<arraySize; i++){// print ra danh sach mon hoc
				setbkcolor(WHITE);
				setcolor(LIGHTRED);
				outtextxy(TABLE_SX + 20 + 50, y, tochar(subjectListArray[i].idSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120, y, tochar(subjectListArray[i].nameSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340, y, tochar(to_string(subjectListArray[i].STCLT)));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, y, tochar(to_string(subjectListArray[i].STCTH)));
				y += D_ROW;
			}
			delete[] subjectListArray;
			drawHeaderAndBottom();

			// Them phan dieu khien khi click mouse
			controlAddDeleteSubject(lsb);


			// getch(); // dung man hinh de xem
		}
		else if(selectedItem == 1){
			cout << "selected 1" << endl;
			reloadingDataSubject();

			drawTableControlSubject();
			// Xu li enter tai day
			drawTableListSubject ();
			//print Danh sach theo tên môn hoc.
			printSTT(lsb);
			//===========================
			int arraySize = 0;
			subject* subjectListArray = arraySubject(lsb.root, arraySize);
			for(int i = 0; i < arraySize; i++){ 
				int indexCurrent = i;
				while(indexCurrent > 0 && subjectListArray[indexCurrent-1].nameSubject > subjectListArray[indexCurrent].nameSubject){
					subject temp = subjectListArray[indexCurrent];
					subjectListArray[indexCurrent] = subjectListArray[indexCurrent-1];
					subjectListArray[indexCurrent-1] = temp;

					indexCurrent--;
				}
			}

			y = TABLE_SY + 40 + D_ROW/10 -1;
			drawTableListSubject();
			printSTT(lsb);
			for(int i=0; i<arraySize; i++){// print ra danh sach mon hoc
				setbkcolor(WHITE);
				setcolor(GREEN);
				outtextxy(TABLE_SX + 20 + 50, y, tochar(subjectListArray[i].idSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120, y, tochar(subjectListArray[i].nameSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340, y, tochar(to_string(subjectListArray[i].STCLT)));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, y, tochar(to_string(subjectListArray[i].STCTH)));
				y += D_ROW;
			}

			delete[] subjectListArray;
			//=================

			drawHeaderAndBottom();

			// getch();// dung man hinh de xem
		}
		else if(selectedItem == 2){
			
			drawTableControlSubject();
			// Xu li enter tai day
			drawTableListSubject ();
			//print Danh sach theo tên môn hoc.
			printSTT(lsb);
			cout << "selectedIrem 2" << endl;

			// getch();
		}

		key = getch();// dung man hinh de xem, neu nhan ESC se thoat chuong trinh hien tai
		if(key == ESC)
			return;
	}
}

//----------------------------------------------------------------

void subjectManagement1(listSubject &lsb){	
	int selected = 0; // lua chon ban dau cua menu lua chon chuc nang

	menuTQSubject(selected);
	
	char key = ESC;
	int ascii;
	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
			if(ascii == 0){
				key = getch();
				ascii = static_cast<int>(key);
				ascii += 255;
			}
			switch(ascii){
				case ENTER:
					cout << "3 case subject mana" << selected << endl;
					/* code */
					switch(selected){
						case 0: 
							cout << "case 1 subject mana" << endl;
							// xu ly hien giao dien danh sach theo id tai day
							drawMenuAndUpdateSelection(lsb, selected);
							
							// highlightFrame(100, 100, 200, 200);
							
							
							
							menuTQSubject(selected);
							break;
						case 1: 
							cout << "case 2 subject manager" << endl;
							// xu ly hien giao dien danh sach theo ten mon hoc tai day
							drawMenuAndUpdateSelection(lsb, selected);
							// hightlight mousee chuot
							menuTQSubject(selected);
							break;
						case 2: 
							cout << "case 3 subject manager" << endl;
							// xu ly hien giao dien cap nhat
							drawMenuAndUpdateSelection(lsb, selected);
							menuTQSubject(selected);
							break;
					}
					break;
				case UP:
					if(selected >= 0){
						selected = (selected - 1 + 3)%3;
						menuTQSubject(selected);
					}
					break;
				case DOWN:
					if(selected <= 2){
						selected = (selected + 1)%3 ;
						menuTQSubject(selected);
					}
					break;
				case ESC:
					return;

				cout << "4\n";
				//----------------------------------------------------------------
			}
		}
	}
}

#endif 
