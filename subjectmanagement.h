#ifndef SUBJECTMANAGEMENT_H 
#define SUBJECTMANAGEMENT_H

 
// Cac thong so co dinh.
#define MENU_SUB_SX 0
#define MENU_SUB_SY 190
#define MENU_SUB_LX 300
#define MENU_SUB_LY 310

#define TABLE_SX 700
#define TABLE_SY 70
#define TABLE_LX 1350
#define TABLE_LY 440 + 1

#define TABLE_FILTER_SX 700
#define TABLE_FILTER_SY 460
#define TABLE_FILTER_LX 1350
#define TABLE_FILTER_LY 580

#define TABLE_CONTROL_SX 340
#define TABLE_CONTROL_SY 70
#define TABLE_CONTROL_LX 680
#define TABLE_CONTROL_LY 600

#define TABLE_ERROR_SX 30
#define TABLE_ERROR_SY 400
#define TABLE_ERROR_LX 300
#define TABLE_ERROR_LY 550

#define ENTER 13
#define ESC 27
#define SPACE 32
#define BACKSPACE 8

#define MENU_ITEM_HEIGHT 40 //Chiều cao của mỗi mục trong menu
#define D_ROW 22

int dong = TABLE_FILTER_SY + 30;
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
void avlToArray (nodeSubject *currentNodeSubject, subject *arraySubject, int &currentIndex);
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
void highlightClickMouse(int x, int y, ptrSubject &root, subject arraySubject[], int sizeArraySubject, int &checkPageListTable);
// void controlAddDeleteSubject();
void controlAddDeleteSubject(listSubject &lsb, subject arraySubject[], int sizeArraySubject, bool checkSeletedItem);
string findSubjectByName (string nameSubject, ptrSubject rootSub);
// bool checkIdSubject (ptrSubject rootSubject, string idsSubject);
bool checkIdSubject(nodeSubject* rootSubject, const std::string& idsSubject);
bool checkNameSubject(nodeSubject* rootSubject, const std::string& nameSubject);
void drawSearchFilter();
nodeSubject* searchStartsWith(nodeSubject* root, string& key);
nodeSubject* searchAVL(nodeSubject* root, string &key);
void searchStartWithArray(subject arraySubject[], int sizeArraySubject, string &keySearch);
void noticeError();
nodeSubject * minValueNode(nodeSubject* node);
nodeSubject* deleteNode(nodeSubject* root, string & key);
void printRootLeftRight(nodeSubject * root);
void printUserManual ();
void selectionSort(subject *listSubject, int sizeListSubject);

void searchAVL2(nodeSubject* root, string& key, int &line);
//=================================================================================================================================================


// Tao giao dien moi cDanh sach mon hoc
void drawTableListSubject (){
	setcolor(LIGHTGRAY);
	rectangle(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);
	//----------------------------------------------------------------
	setlinestyle(SOLID_LINE, 0, 1);// new table
	setcolor(LIGHTGRAY);//khung 
	rectangle(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);
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
    for (int y = TABLE_SY + 40; y < TABLE_LY; y += D_ROW) 
        line(TABLE_SX, y, TABLE_LX-20, y);
	
	line(TABLE_LX-20, TABLE_SY+40, TABLE_LX-20, TABLE_LY);// ve dupng thang phia sau
    setbkcolor(LIGHTBLUE);// Thiet lap mau nen chu
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
	// int x = TABLE_SX + 50;
	// int y = TABLE_SY + D_ROW/10 - 1 + 40;
    if (root != nullptr) {
        if (root->left != nullptr) {    
            displaySubjectList(root->left);     
        }
        setbkcolor(WHITE);
        setcolor(GREEN); 
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
//Ve lai khu vuc Header va Bottom.
void drawHeaderAndBottom(){
	createHeader();
	createBottom();
}

//----------------------------------------------------------------
//Ve menu cua phan subject
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
		setcolor(GREEN);
		// setfillstyle(SOLID_FILL, YELLOW);
		outtextxy(TABLE_SX + 10, TABLE_SY + 40 + i*D_ROW + D_ROW/10 - 1, number);	
	}
	setDefault();
	std::cout << lsb.size << endl;
	std::cout << "da in so thu tu thanh cong\n";
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
    while (true) {
		if(selectedItem == 0){
			setcolor(BLUE);
            outtextxy(MENU_SUB_SX, 10 + y, ">> Danh sach mon theo ID");
		}

        if (kbhit()){
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

// data from avl tre to array static.
void avlToArray (nodeSubject *currentNodeSubject, subject *arraySubject, int &currentIndex){
	if(currentNodeSubject != nullptr){
		avlToArray(currentNodeSubject->left, arraySubject, currentIndex);
		arraySubject[currentIndex] = currentNodeSubject->data;
		currentIndex++;
		avlToArray(currentNodeSubject->right, arraySubject, currentIndex);
	}
}




//chuyen du lieu tu cay avl sang array action
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
	std::cout << arraySize << " ";
	std::cout << endl;
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
	std::cout << "Danh sach mon hoc:............"<< endl;
	for(int i=0; i<5; i++){
		std::cout << sub->nameSubject << endl;
		setcolor(GREEN);
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

	bar(TABLE_CONTROL_SX+1, TABLE_CONTROL_SY+1, TABLE_CONTROL_LX-1, TABLE_CONTROL_LY-11); // draw nen gray
	
	setfillstyle(SOLID_FILL, LIGHTCYAN);
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

	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100, TABLE_CONTROL_SY + 50 + 250 + 30);
	bar(TABLE_CONTROL_SX + 1 + 10 + 100 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110, TABLE_CONTROL_SY + 50 + 250 + 30);
	bar(TABLE_CONTROL_SX + 1 + 10 + 110*2, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110*2, TABLE_CONTROL_SY + 50 + 250 + 30);
	setDefault();
	
	setbkcolor(LIGHTBLUE);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
	outtextxy(TABLE_CONTROL_SX + 10 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "INSERT");
	outtextxy(TABLE_CONTROL_SX + 10 + 110 + 10, TABLE_CONTROL_SY + 50 + 250 + 5,"DELETE");
	outtextxy(TABLE_CONTROL_SX + 10 + 110*2 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "UPDATE");
	setDefault(); 

	// draw muc search id hoac ten mon hoc sẽ hien ra thong tin can sua chua.
	setcolor(BLUE);
	setbkcolor(LIGHTCYAN);
	outtextxy(TABLE_CONTROL_SX + 10, TABLE_CONTROL_SY + 50 + 250 + 5 + 35, "Search: ");

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
	std::cout << "DA RELOADING THANH CONG DANH SACH SSUBJECT.\n";
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

//Ve menu dieu khien tong quat chuong trinh.
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
	else
		outtextxy(10, MENUSPOINTY + 95 + 40, text);
	

	// tao menu 2
	sprintf(text, "%c Danh sach theo ten", 62);
	setcolor(BLACK);
	if(selected == 1){
		setcolor(BLUE);
		outtextxy(10, MENUSPOINTY + 135 + 40 , text);
	}
	else
		outtextxy(10, MENUSPOINTY + 135 + 40 , text);
	
	
	sprintf(text, "%c Cap nhat danh sach", 62);
	setcolor(BLACK);
	if(selected == 2){
		setcolor(BLUE);
		outtextxy(10, MENUSPOINTY + 175 + 40 , text);
	}
	else
		outtextxy(10, MENUSPOINTY + 175 + 40, text);
	

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
	
	setDefault();
}

//void readListSubject2(nodeSubject* &root, string nameFileSubjectList) {
//    ifstream f(nameFileSubjectList);
//    if (!f.is_open()) {
//        cout << "fail open file subject!" << endl;
//        return;
//    }
//    cout << "completed open file subject!" << endl;
//
//    subject s;
//    string line;
//    while (getline(f, line)) {
//        stringstream ss(line);
//
//        getline(ss, s.idSubject, '#');
//        getline(ss, s.nameSubject, '#');
//        ss >> s.STCLT; ss.ignore();
//        ss >> s.STCTH; ss.ignore();
//
//        root = insert(root, s.nameSubject); // Sửa đổi ở đây để chèn vào cây theo tên môn học
//    }
//
//    f.close();
//}

//Hightlight khi co click mouse vao khung nhap chu
void highlightClickMouse(int x, int y, listSubject &lsb, subject arraySubject[], int sizeArraySubject, int &checkPageListTable){
// 	dong = TABLE_FILTER_SY + 30;
// 	// Neu click mouse gap thi hightlight thanh sang cho thanh search 
// 	string idSub = "", nameSub =  "";
// 	int stclt = -1, stcth = -1;

// 	// check da nhap du chua de insert
// 	bool checkInputId = false;
// 	bool checkInputName = false;
// 	bool checkInputLT = false;
// 	bool checkInputTH = false;

// 	int checkOutList = (lsb.size - 1)/15;// check list nay se chạy tu 0 den checkOutList
// 	// luc nay check out list = 1

// 	if(TABLE_CONTROL_SX + 1 + 10 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 <= y && x <= TABLE_CONTROL_SX - 1 + 10 + 300 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60){
// 		// Neu click mouse gap thi hightlight thanh sang cho thanh search
// 		highlightFrame(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30, TABLE_CONTROL_SX - 1 + 10 + 300, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60);
// 		//Xu li nhâp du lieu vao khung search 
// 		const int sizeText = 30;
// 		int index = 0;
// 		char textSearch[sizeText];
// 		bool isPrevSpace = true;

// 		std::cout << "Nhap vao mot chuoi search (nhap Enter de ket thuc):\n";
// 		while (true) { 
// 			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
// 				char text = getch(); 

// 				if (text == SPACE){
// 					if (index == 0 || isPrevSpace) // Loại bỏ dấu cách đầu hoặc liên tiếp
// 						continue;
// 					isPrevSpace = true;
// 				}else
// 					isPrevSpace = false;

// 				if (text == ENTER) 
// 					break; 
// 				else if (text == BACKSPACE) { 
// 					if (index > 0) { 
// 						std::cout << "\b \b"; 
// 						index--; 
// 						textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
// 						// cout << textSearch << endl;
// 						setcolor(BLUE);
// 						setbkcolor(YELLOW);
// 						bar(TABLE_CONTROL_SX + 1 + 10 + 1, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 1, TABLE_CONTROL_SX - 1 + 10 + 300 - 1, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60 - 1);
// 						textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
// 						outtextxy(TABLE_CONTROL_SX + 1 + 10 + 5, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 5, textSearch);

// 						setDefault();
// 					}
// 				}
// 				else if (index < sizeText - 1) { 
// 					textSearch[index++] = text; 
// 					textSearch[0] = toupper(textSearch[0]);
// 					std::cout << text; 
// 					setcolor(BLUE);
// 					setbkcolor(YELLOW);
// 					bar(TABLE_CONTROL_SX + 1 + 10 + 1, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 1, TABLE_CONTROL_SX - 1 + 10 + 300 - 1, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60 - 1);
// 					textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
// 					outtextxy(TABLE_CONTROL_SX + 1 + 10 + 5, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 5, textSearch);

// 					setDefault();
// 				}
// 			}
// 		}
// 		textSearch[index] = '\0'; // Thêm ký tự kết thúc chuỗi
// 		std::cout << "\nChuoi da nhap: " << textSearch << std::endl;
// 		setcolor(BLUE);
// 		setbkcolor(WHITE);
// 		bar(TABLE_CONTROL_SX + 1 + 10 + 1, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 1, TABLE_CONTROL_SX - 1 + 10 + 300 - 1, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60 - 1);
// 		outtextxy(TABLE_CONTROL_SX + 1 + 10 + 5, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30 + 5, textSearch);


// 		// Xu li thanh search
// 		/*Thanh search hien thi thong tin sang mot ben theo dang loc du lieu
// 			- 
// 		*/
// 		drawSearchFilter();
// 		cout << "In bang filter\n";
// 		// displaySubjectList(root); // in danh sach du lieu mon hoc bang avl  
// 		string strSearch(textSearch);
//         cout << "Search for strings starting with '" << strSearch << "': \n";

// 		//Xu ly tim kiem bang avl tree.

//         // ptrSubject root1 = root;
// 		// nodeSubject* result1 = searchStartsWith(root1, strSearch);
//         // if (result1 != NULL){
//         //     cout << result1->data.nameSubject << endl;
// 		// 	cout <<"da in thanh cong du lieu duoc tim kiem\n";
// 		// 	// int i = TABLE_FILTER_SY;
// 		// 	// outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, dong + 5, tochar(result1->data.nameSubject));
// 		// 	// dong += 30;
// 		// 	for(int i = TABLE_FILTER_SY + 60; i < TABLE_FILTER_LY; i += 30){
// 		// 		setcolor(RED);
// 		// 		outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, i + 5, tochar(result1->data.nameSubject));
// 		// 	}
// 		// }
//         // else{
//         //     cout << "Not found." << endl;

// 		// 	// setfillstyle(SOLID_FILL, WHITE);
// 		// 	// bar(TABLE_FILTER_SX, TABLE_FILTER_SY + 31, TABLE_FILTER_LX, TABLE_FILTER_LY);
// 		// 	// setcolor(LIGHTGRAY);
// 		// 	// rectangle(TABLE_FILTER_SX, TABLE_FILTER_SY, TABLE_FILTER_LX, TABLE_FILTER_LY);
// 		// 	// int i = TABLE_FILTER_SY + 30;
// 		// 	// outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, dong + 5, "Khong tim thay du lieu...");
// 		// 	// dong -= 30;
// 		// 	for(int i = TABLE_FILTER_SY + 30; i < TABLE_FILTER_LY; i += 30){
// 		// 		setcolor(GREEN);
// 		// 		outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, i + 5, "Khong tim thay du lieu...");
// 		// 	}
// 		// }
// 		// // string strSubFind = findSubjectByName(strSearch, lsb.root);
// 		// // cout << "Chuoi sau khi loc du lieu: " << strSubFind << "\nhet!!" << endl;

// 		// Thu lai xu li bang mang
// 		searchStartWithArray(arraySubject, sizeArraySubject, strSearch);


// 	}
// 	else {
// 		highlightFrameDefault(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30, TABLE_CONTROL_SX - 1 + 10 + 300, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60);
// 	}

// 	// MUC ID môn học
// 	if(TABLE_CONTROL_SX + 5 <= x && TABLE_CONTROL_SY + 30 + 30 <= y && TABLE_CONTROL_SX + 120 >= x && y <= TABLE_CONTROL_SY + 60 + 30){
// 		// Neu click mouse gap thi hightlight thanh sang cho thanh search
// 		highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);

// 		//xu li nhâp du lieu vao khung id
// 		const int sizeTextId = 8; 
// 		char stringTextId[sizeTextId]; 
// 		int indexId = 0; 
// 		std::cout << "Nhap vao mot chuoi id (nhap Enter de ket thuc):\n";
// 		while (true) { 
// 			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
// 				char textId = getch(); 
// 				if (textId == ENTER) { 
// 					break; 
// 				}
// 				else if(textId == SPACE){
// 					continue;
// 				}
// 				else if (textId == BACKSPACE) { 
// 					if (indexId > 0) { 
// 						std::cout << "\b \b"; 
// 						indexId--; 
// 						stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
// 						// cout << textSearch << endl;
// 						setcolor(BLUE);
// 						setbkcolor(YELLOW);
// 						bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
// 						stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
// 						outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextId);

// 						setDefault();
// 					}
// 				}
// 				else if (indexId < sizeTextId - 1) { 
// 					//Neu 3 ki tu dau tien thi mac dinh la chu in hoa.
// 					if((('A' <= textId && textId <= 'Z') || ('a' <= textId && textId <= 'z')) && (0 <= indexId && indexId <= 2)){
// 						stringTextId[indexId++] = toupper(textId); 
// 						std::cout << textId; 
// 					}
// 					else if((3 <= indexId && indexId <= 6) && ('0' <= textId && textId <= '9')){
// 						stringTextId[indexId++] = textId;
// 						std::cout << textId; 
// 					}
// 					setcolor(BLUE);
// 					setbkcolor(YELLOW);
// 					bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
// 					stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
// 					outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextId);

// 					setDefault();
// 				}
// 			}
// 		}
// 		stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
// 		std::cout << "\nChuoi da nhap: " << stringTextId << std::endl;
// 		setcolor(BLUE);
// 		setbkcolor(WHITE);
// 		bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
// 		outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextId);


// 		setDefault();

// 		//----------------------------------------------------------------------------------------------
// 		// xu lý bộ nhớ ở đây la xong phim.
// 		/*Lấy dữ liệu nhập của IDsubject đưa vào cây avl
// 		- Nếu IDsubject không tồn tại thì không cần thông báo không tìm thấy IDsubject
// 			+Tiếp tục đưa dữ liệu này vào node của cây avl.
// 		- Nếu IDsubject tồn tại thì thông báo tìm thấy IDsubject
// 			+ Hiện ra màn hình thông báo lỗi "ĐÃ TỒN TẠI IDSUBJECT" và yêu cầu nhập lại IDsubject
		
// 		*/
		
// 		// chay kiem tra id nhap vao co bị trung lap voi database da co hay kkhong
// 		if(checkIdSubject(lsb.root, stringTextId) == false){
// 			idSub = stringTextId;
// 			cout << "idSub: " << idSub << endl;

// 			// xu li data insert vao avl tree




			

// 		}else{
// 			cout << setw(10) << stringTextId << setw(15) << "Da ton tai id..." << endl;

// 			setfillstyle(SOLID_FILL, WHITE);
// 			bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);//an du lieu nhap khong hop le.
// 			// Bao loi trung idsubject
// 			setcolor(LIGHTRED);
// 			setbkcolor(LIGHTCYAN);
// 			outtextxy(TABLE_CONTROL_SX + 150, TABLE_CONTROL_SY + 70, "ID da ton tai!");
// 			delay(3000);
// 			setfillstyle(SOLID_FILL, LIGHTCYAN);
// 			bar(TABLE_CONTROL_SX + 150-2, TABLE_CONTROL_SY + 70, TABLE_CONTROL_SX + 310, TABLE_CONTROL_SY + 100);
// 		}


// 		//----------------------------------
// 	}
// 	else {
// 		highlightFrameDefault(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);
// 	}

// 	// Muc ten mon hoc
// 	if(TABLE_CONTROL_SX + 5 <= x && TABLE_CONTROL_SY + 60 + 30 + 30 <= y && TABLE_CONTROL_SX + 330 >= x && y <= TABLE_CONTROL_SY + 90 + 30 + 30){
// 		// Neu click mouse gap thi hightlight thanh sang cho thanh search
// 		highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60 + 30 + 30, TABLE_CONTROL_SX + 330, TABLE_CONTROL_SY + 90 + 30 + 30);

// 		//xu li nhâp du lieu vao khung search
// 		const int sizeTextName = 25; 
// 		char textName[sizeTextName]; 
// 		int indexName = 0; 
// 		bool isPrevSpace = true; // Biến để theo dõi xem ký tự trước đó có phải là dấu cách không

// 		std::cout << "Nhap vao mot chuoi ten mon hoc (nhap Enter de ket thuc):\n";
// 		while (true) { 
// 			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
// 				char text = getch(); 

// 				if (text == SPACE) {
// 					if (indexName == 0 || isPrevSpace) { // Loại bỏ dấu cách đầu hoặc liên tiếp
// 						continue;
// 					}
// 					isPrevSpace = true;
// 				} else {
// 					isPrevSpace = false;
// 				}

// 				if (text == ENTER) { 
// 					break; 
// 				}
// 				else if (text == BACKSPACE) { 
// 					if (indexName > 0) { 
// 						std::cout << "\b \b"; 
// 						indexName--; 
// 						// cout << textSearch << endl;
// 						setcolor(BLUE);
// 						setbkcolor(YELLOW);
// 						bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 60 + 30 + 30 + 1, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);
// 						textName[indexName] = '\0'; // Thêm ký tự kết thúc chuỗi
// 						outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 60 + 30 + 30 + 5, textName);

// 						setDefault();
// 					}
// 				}
// 				else if (indexName < sizeTextName - 1) { 
// 					textName[indexName++] = text; 
// 					textName[0] = toupper(textName[0]);
// 					std::cout << text; 
// 					setcolor(BLUE);
// 					setbkcolor(YELLOW);
// 					bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 60 + 30 + 30 + 1, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);
// 					textName[indexName] = '\0'; // Thêm ký tự kết thúc chuỗi
// 					outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 60 + 30 + 30 + 5, textName);

// 					setDefault();
// 				} 
// 			}
// 		}
// 		textName[indexName] = '\0'; // Thêm ký tự kết thúc chuỗi
// 		std::cout << "\nChuoi da nhap: " << textName << std::endl;
// 		setcolor(BLUE);
// 		setbkcolor(WHITE);
// 		bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 60 + 30 + 30 + 1, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);
// 		outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 60 + 30 + 30 + 5, textName);


// 		setDefault();

// 		if(checkNameSubject(lsb.root, textName) == false){
// 			nameSub = textName;
// 			cout << "nameSub: " << nameSub << endl;
// 			// xu li 

// 		}else{
// 			// Thong bao loi trung du lieu.
// 			cout << setw(30) << textName << setw(10) << "Mon hoc da ton tai!" << endl;

// 			setfillstyle(SOLID_FILL, WHITE);
// 			bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 60 + 30 + 30, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);//an du lieu nhap khong hop le.

// 			setcolor(LIGHTRED);
// 			setbkcolor(LIGHTCYAN);
// 			outtextxy(TABLE_CONTROL_SX + 130, TABLE_CONTROL_SY + 70, "Mon hoc da ton tai!" ); 
// 			delay(3000);
// 			setfillstyle(SOLID_FILL, LIGHTCYAN);
// 			bar(TABLE_CONTROL_SX + 130, TABLE_CONTROL_SY + 70,TABLE_CONTROL_SX + 335, TABLE_CONTROL_SY + 100);
// 			setDefault();
// 		}
// 	}
// 	else {
// 		highlightFrameDefault(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60 + 30 + 30, TABLE_CONTROL_SX + 330, TABLE_CONTROL_SY + 90 + 30 + 30);
// 	}

// 	// Muc so tin chi ly thuyet
// 	if(TABLE_CONTROL_SX + 5 <= x && TABLE_CONTROL_SY + 175 + 20 <= y && TABLE_CONTROL_SX + 100 >= x && y <= TABLE_CONTROL_SY + 195 + 30){
// 		// Neu click mouse gap thi hightlight thanh sang cho thanh search
// 		highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 100, TABLE_CONTROL_SY + 195 + 30);

// 		//xu li nhâp du lieu vao khung ly thuyet
// 		// char key;
// 		const int sizeTextLT = 4; 
// 		char textLT[sizeTextLT]; 
// 		int indexLT = 0; 
// 		std::cout << "Nhap vao mot chuoi so tin chi ly thuyet (nhap Enter de ket thuc):\n";
// 		while (true) { 
// 			if (kbhit()) { 
// 				char text = getch(); 
// 				if (text == ENTER) { 
// 					break; 
// 				}
// 				else if(text == SPACE){
// 					continue;
// 				}
// 				else if (text == BACKSPACE) { 
// 					if (indexLT > 0) { 
// 						std::cout << "\b \b"; 
// 						indexLT--; 
// 						textLT[indexLT] = '\0'; // Thêm ký tự kết thúc chuỗi
// 						// cout << textSearch << endl;
// 						setcolor(BLUE);
// 						setbkcolor(YELLOW);
// 						bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
// 						outtextxy(TABLE_CONTROL_SX + 5 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textLT);

// 						setDefault();
// 					}
// 				}
// 				else if (indexLT < sizeTextLT - 1) { 
// 					if('0' <= text && text <= '9')
// 						textLT[indexLT++] = text; 
// 					std::cout << text; 
// 					textLT[indexLT] = '\0'; // Thêm ký tự kết thúc chuỗi
// 					setcolor(BLUE);
// 					setbkcolor(YELLOW);
// 					bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
// 					outtextxy(TABLE_CONTROL_SX + 5 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textLT);

// 					setDefault();
// 				}
// 			}
// 		}
// 		textLT[indexLT] = '\0'; // Thêm ký tự kết thúc chuỗi
// 		std::cout << "\nChuoi da nhap: " << textLT << std::endl;
// 		setcolor(BLUE);
// 		setbkcolor(WHITE);
// 		bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
// 		outtextxy(TABLE_CONTROL_SX + 5 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textLT);


// 		stclt = stringtoint(textLT);
// 		cout << "stclt : " << stclt << endl;

// 		setDefault();
// 	}
// 	else {
// 		highlightFrameDefault(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 100, TABLE_CONTROL_SY + 195 + 30);
// 	}

// 	// muc so tin chi thuc hanh
// 	if(TABLE_CONTROL_SX + 5 + 150 <= x && TABLE_CONTROL_SY + 175 + 20 <= y && TABLE_CONTROL_SX + 5 + 150 + 100 >= x && y <= TABLE_CONTROL_SY + 195 + 30){
// 		// Neu click mouse gap thi hightlight thanh sang cho thanh search
// 		highlightFrame(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100, TABLE_CONTROL_SY + 195 + 30);

// 		//xu li nhâp du lieu vao khung thuc hanh
// 		// char key;
// 		const int sizeTextTH = 4; 
// 		char textTH[sizeTextTH]; 
// 		int indexTH = 0; 
// 		std::cout << "Nhap vao mot chuoi so tin chi thuc hanh (nhap Enter de ket thuc):\n";
// 		while (true) { 
// 			if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
// 				char text = getch(); 
// 				if (text == ENTER) { 
// 					break; 
// 				}
// 				else if(text == SPACE){
// 					continue;
// 				}
// 				else if (text == BACKSPACE) { 
// 					if (indexTH > 0) { 
// 						std::cout << "\b \b"; 
// 						indexTH--; 
// 						// cout << textSearch << endl;
// 						setcolor(BLUE);
// 						setbkcolor(YELLOW);
// 						bar(TABLE_CONTROL_SX + 5 + 150 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
// 						textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
// 						outtextxy(TABLE_CONTROL_SX + 5 + 150 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textTH);

// 						setDefault();
// 					}
// 				}
// 				else if (indexTH < sizeTextTH - 1) { 
// 					if('0' <= text && text <= '9')
// 						textTH[indexTH++] = text; 
// 					std::cout << text; 
// 					setcolor(BLUE);
// 					setbkcolor(YELLOW);
// 					bar(TABLE_CONTROL_SX + 5 + 150 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
// 					textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
// 					outtextxy(TABLE_CONTROL_SX + 5 + 150 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textTH);

// 					setDefault();
// 				}
// 			}
// 		}
// 		textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
// 		std::cout << "\nChuoi da nhap: " << textTH << std::endl;
// 		setcolor(BLUE);
// 		setbkcolor(WHITE);
// 		bar(TABLE_CONTROL_SX + 5 + 150 + 1, TABLE_CONTROL_SY + 175 + 20 + 1, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
// 		textTH[indexTH] = '\0'; // Thêm ký tự kết thúc chuỗi
// 		outtextxy(TABLE_CONTROL_SX + 5 + 150 + 20, TABLE_CONTROL_SY + 175 + 20 + 5, textTH);


// 		stcth = stringtoint(textTH);
// 		cout << "stcth: " << stcth << endl;

// 		setDefault();
// 	}
// 	else {
// 		highlightFrameDefault(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100, TABLE_CONTROL_SY + 195 + 30);
// 	}


// 	//----------------------------------------------------
// 	// Highlight khung sang khi click mouse Them, Sua, Xoa.
// 	// Muc Them
// 	if(TABLE_CONTROL_SX + 1 + 10 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 <= y && x <= TABLE_CONTROL_SX - 1 + 10 + 100 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30){
// 		setbkcolor(BLUE);
// 		setcolor(WHITE);
// 		setfillstyle(SOLID_FILL, BLUE);

// 		bar(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100, TABLE_CONTROL_SY + 50 + 250 + 30);
// 		outtextxy(TABLE_CONTROL_SX + 10 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "INSERT");
	
// 		//Xu li them vao avl
		


		
		
// 	}else{
// 		setbkcolor(LIGHTBLUE);
// 		setfillstyle(SOLID_FILL, LIGHTBLUE);
// 		setcolor(BLACK);
	
// 		bar(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100, TABLE_CONTROL_SY + 50 + 250 + 30);
// 		outtextxy(TABLE_CONTROL_SX + 10 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "INSERT");
// 	}
// 	// Muc Xoa
// 	if(TABLE_CONTROL_SX + 1 + 10 + 100 + 10 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 <= y && x <= TABLE_CONTROL_SX  - 1 + 10 + 100 + 110 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30){
// 		setbkcolor(BLUE);
// 		setcolor(WHITE);
// 		setfillstyle(SOLID_FILL, BLUE);
		
// 		bar(TABLE_CONTROL_SX + 1 + 10 + 100 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110, TABLE_CONTROL_SY + 50 + 250 + 30);
// 		outtextxy(TABLE_CONTROL_SX + 10 + 110 + 10, TABLE_CONTROL_SY + 50 + 250 + 5,"DELETE");
// 	}else{
// 		setbkcolor(LIGHTBLUE);
// 		setfillstyle(SOLID_FILL, LIGHTBLUE);
// 		setcolor(BLACK);

// 		bar(TABLE_CONTROL_SX + 1 + 10 + 100 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110, TABLE_CONTROL_SY + 50 + 250 + 30);
// 		outtextxy(TABLE_CONTROL_SX + 10 + 110 + 10, TABLE_CONTROL_SY + 50 + 250 + 5,"DELETE");
// 	}
// 	// Muc Sua
// 	if(TABLE_CONTROL_SX + 1 + 10 + 110*2 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 <= y && x <= TABLE_CONTROL_SX  - 1 + 10 + 100 + 110*2 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30){
// 		setbkcolor(BLUE);
// 		setcolor(WHITE);
// 		setfillstyle(SOLID_FILL, BLUE);

// 		bar(TABLE_CONTROL_SX + 1 + 10 + 110*2, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110*2, TABLE_CONTROL_SY + 50 + 250 + 30);
// 		outtextxy(TABLE_CONTROL_SX + 10 + 110*2 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "UPDATE");
// 	}else{
// 		setbkcolor(LIGHTBLUE);
// 		setfillstyle(SOLID_FILL, LIGHTBLUE);
// 		setcolor(BLACK);

// 		bar(TABLE_CONTROL_SX + 1 + 10 + 110*2, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX  + 10 + 100 + 110*2, TABLE_CONTROL_SY + 50 + 250 + 30);
// 		outtextxy(TABLE_CONTROL_SX + 10 + 110*2 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "UPDATE");
// 	}



// 	// Hight light thanh truot/cuon ========================///////////////////////////////
// 	int rowTable = TABLE_SY + 40 + D_ROW/10 -1;
// 	// len
// 	if(TABLE_LX - 20 <= x && TABLE_SY + 30 <= y && x <= TABLE_LX && y <= TABLE_SY + 30 + 20){
// 		drawTableListSubject ();

// 		checkPageListTable--;
// 		if(checkPageListTable < 0){
// 			checkPageListTable = 0;
// 		}
// 		if(checkPageListTable >= (lsb.size - 1)/15){
// 			checkPageListTable = (lsb.size - 1)/15;
// 		}
		

// 		bar(TABLE_LX - 18, TABLE_SY + 60, TABLE_LX - 2, TABLE_LY);
// 		setfillstyle ( SOLID_FILL, LIGHTGRAY);
// 		bar(TABLE_LX - 18, TABLE_SY + 60 + checkPageListTable*300, TABLE_LX - 2, TABLE_LY - checkPageListTable*300);

		
// 		for(int i = 15*checkPageListTable; i < 15 + 15*checkPageListTable; i++){
// 			if(i >= lsb.size) // tranh viec in ra nhieu hon so thu tu.
// 				continue;

// 			char number[4]; // luu tru day so tu dong tang
// 			sprintf(number, "%03d", i + 1);
// 			setbkcolor(WHITE);
// 			setcolor(GREEN);
// 			// setfillstyle(SOLID_FILL, YELLOW);
// 			outtextxy(TABLE_SX + 10, TABLE_SY + 40 + (i%15)*D_ROW + D_ROW/10 - 1, number);	
			

// 			setbkcolor(WHITE);
// 			setcolor(GREEN);
// 			outtextxy(TABLE_SX + 20 + 50, rowTable, tochar(arraySubject[i].idSubject));
// 			outtextxy(TABLE_SX + 20 + 50 + 120, rowTable, tochar(arraySubject[i].nameSubject));
// 			outtextxy(TABLE_SX + 20 + 50 + 120 + 340, rowTable, tochar(to_string(arraySubject[i].STCLT)));
// 			outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, rowTable, tochar(to_string(arraySubject[i].STCTH)));
// 			rowTable += D_ROW;
// 		}

// 		setbkcolor(RED);
// 		setcolor(RED);
// 		int x1 = TABLE_LX - 20, y1 = TABLE_SY + 40 + 14;
// 		int x2 = TABLE_LX - 20 + 8, y2 = TABLE_SY + 40;
// 		int x3 = TABLE_LX - 20 + 16, y3 = TABLE_SY + 40 + 14;
		
// 		line(x1, y1, x2, y2);
// 		line(x2, y2, x3, y3);
// 		line(x3, y3, x1, y1);
// 		int points1[] = {x1, y1, x2, y2, x3, y3, x1, y1};
// 		setfillstyle(SOLID_FILL, RED);
// 		fillpoly(4, points1);
// 	}else{
// 		drawScrollBarSubject();
// 	}
// 	//xuong
// 	if((TABLE_LX - 20 <= x && TABLE_LY-20 <= y && x <= TABLE_LX && y <= TABLE_LY + 20)){
// 		drawTableListSubject ();
// 		//
// 		checkPageListTable++;
// 		if(checkPageListTable >= (lsb.size - 1)/15){
// 			checkPageListTable = (lsb.size - 1)/15;
// 		}
// 		if(checkPageListTable < 0){
// 			checkPageListTable = 0;
// 		}

// 		bar(TABLE_LX - 18, TABLE_SY + 60, TABLE_LX - 2, TABLE_LY);
// 		setfillstyle ( SOLID_FILL, LIGHTGRAY);
// 		bar(TABLE_LX - 18, TABLE_SY + 60 + checkPageListTable*300, TABLE_LX - 2, TABLE_LY - checkPageListTable*300);

// 		for(int i = 15*checkPageListTable; i < 15 + 15*checkPageListTable; i++){
// 			if(i >= lsb.size) // tranh viec in ra nhieu hon so thu tu.
// 				continue;

// 			// print so thu tu theo du  lieu.
// 			char number[4]; // luu tru day so tu dong tang
// 			sprintf(number, "%03d", i + 1);
// 			setbkcolor(WHITE);
// 			setcolor(GREEN);
// 			// setfillstyle(SOLID_FILL, YELLOW);
// 			outtextxy(TABLE_SX + 10, TABLE_SY + 40 + (i%15)*D_ROW + D_ROW/10 - 1, number); // print theo tung bang 15 hang	
			
// 			setbkcolor(WHITE);
// 			setcolor(GREEN);
// 			outtextxy(TABLE_SX + 20 + 50, rowTable, tochar(arraySubject[i].idSubject));
// 			outtextxy(TABLE_SX + 20 + 50 + 120, rowTable, tochar(arraySubject[i].nameSubject));
// 			outtextxy(TABLE_SX + 20 + 50 + 120 + 340, rowTable, tochar(to_string(arraySubject[i].STCLT)));
// 			outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, rowTable, tochar(to_string(arraySubject[i].STCTH)));
// 			rowTable += D_ROW;
// 		}
// 		//
// 		setbkcolor(RED);
// 		setcolor(RED);

// 		int x1 = TABLE_LX - 20, y1 = TABLE_SY + 40 + 14;
// 		int x2 = TABLE_LX - 20 + 8, y2 = TABLE_SY + 40;
// 		int x3 = TABLE_LX - 20 + 16, y3 = TABLE_SY + 40 + 14;

// 		int u1 = TABLE_LX - 20 + 1, v1 = TABLE_LY - 14;
// 		int u2 = TABLE_LX - 20 + 1 + 8, v2 = TABLE_LY;
// 		int u3 = TABLE_LX - 20 + 1 + 16, v3 = TABLE_LY - 14;
// 		line(u1, y1, u2, v2);
// 		line(u2, y2, u3, v3);
// 		line(u3, y3, u1, v1);
// 		int points2[] = {u1, v1, u2, v2, u3, v3, u1, v1};
// 		setfillstyle(SOLID_FILL, RED);
// 		fillpoly(4, points2);
// 	}else{
// 		drawScrollBarSubject();
// 	}

// 	setDefault();
}

// Ve danh sach loc thong tin tai muc tim kiem.
void drawSearchFilter(){
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_FILTER_SX, TABLE_FILTER_SY, TABLE_FILTER_LX, TABLE_FILTER_LY);

	setcolor(LIGHTGRAY);
	rectangle (TABLE_FILTER_SX, TABLE_FILTER_SY, TABLE_FILTER_LX, TABLE_FILTER_LY);

	// tieu de
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(TABLE_FILTER_SX, TABLE_FILTER_SY, TABLE_FILTER_LX, TABLE_FILTER_SY + 30);
	setcolor(BLACK);
	setbkcolor(LIGHTBLUE);
	outtextxy(TABLE_FILTER_SX + 5, TABLE_FILTER_SY + 5, "STT");
	outtextxy(TABLE_FILTER_SX + 5 + 50 , TABLE_FILTER_SY + 5, "Ma mon hoc");
	outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 , TABLE_FILTER_SY + 5, "Ten mon hoc");
	outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 , TABLE_FILTER_SY + 5, "STCLT");
	outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 + 60, TABLE_FILTER_SY + 5, "STCTH");

	// cac duong ke ngang
	for(int i = TABLE_FILTER_SY + 30; i < TABLE_FILTER_LY; i += 30){
		setcolor(LIGHTGRAY);
		line(TABLE_FILTER_SX, i, TABLE_FILTER_LX, i);
	}
	// cac duong ke doc
	setcolor(LIGHTGRAY);
	line(TABLE_FILTER_SX + 50, TABLE_FILTER_SY, TABLE_FILTER_SX + 50, TABLE_FILTER_LY);
	line(TABLE_FILTER_SX + 50 + 120, TABLE_FILTER_SY, TABLE_FILTER_SX + 50 + 120, TABLE_FILTER_LY);
	line(TABLE_FILTER_SX + 50 + 120 + 340, TABLE_FILTER_SY, TABLE_FILTER_SX + 50 + 120 + 340, TABLE_FILTER_LY);
	line(TABLE_FILTER_SX + 50 + 120 + 340 + 60, TABLE_FILTER_SY, TABLE_FILTER_SX + 50 + 120 + 340 + 60, TABLE_FILTER_LY);

	setDefault();
}
// Tim kiem va loc mon hoc theo ten || theo bang sao cay avl chi muc dich hien thi thong tin thoi
string findSubjectByName (string nameSubject, ptrSubject rootSub){
	if(rootSub == nullptr) 
		return "";
	else {
		if(nameSubject > rootSub->data.nameSubject)
			return findSubjectByName(nameSubject, rootSub->right);
		if(nameSubject < rootSub->data.nameSubject)
			return findSubjectByName(nameSubject, rootSub->left);
	}
	return rootSub->data.nameSubject;
}
//Kiem tra id co bi trung hay khong
bool checkIdSubject(ptrSubject rootSubject, const string& idsSubject) {
    if (rootSubject == nullptr) {
        return false; //khong thay
    }
    if (rootSubject->data.idSubject == idsSubject) {
        return true; // Tim thay idSubject khop
    }
    
    if (checkIdSubject(rootSubject->left, idsSubject)) {
        return true; // Tim thay idSubject trong cay con ben trai
    }
    return checkIdSubject(rootSubject->right, idsSubject); // Tim kiem o node con ben phai
}
// Kiem tra ten mon hoc co bi trung hay khong
bool checkNameSubject(nodeSubject* rootSubject, const std::string& namesSubject){
	if(rootSubject == nullptr)
		return false;
	if(rootSubject->data.nameSubject == namesSubject)
		return true;

	if(checkNameSubject(rootSubject->left, namesSubject))
		return true;
	return checkNameSubject(rootSubject->right, namesSubject);
}

// Tìm và in ra các môn học bắt đầu bằng một chuỗi cho trước
void searchAVL2(nodeSubject* root, string& key, int &line) {
    if (root == nullptr)
        return;

    if (key.length() == 0) { // Trường hợp đặc biệt: nếu chuỗi key rỗng, in ra tất cả các môn học
		std::cout << "Khong tim thay data can tim kiem...\n";

		setfillstyle(SOLID_FILL, WHITE);
		bar(TABLE_FILTER_SX + 1, TABLE_FILTER_SY + 31, TABLE_FILTER_LX, TABLE_FILTER_LY);
		setcolor(LIGHTGRAY);
		setbkcolor(WHITE);
		outtextxy(TABLE_FILTER_SX + 180, TABLE_FILTER_SY + 50, "KHONG TIM KIEM THAY DU LIEU...");	
		setDefault();

		return;

        // searchAVL2(root->left, key, line);

        // cout << "Data is: " << endl;
        // cout << setw(5) << root->data.idSubject << " ";
        // cout << setw(20) << root->data.nameSubject << " ";
        // cout << setw(5) << root->data.STCLT << " ";
        // cout << setw(5) << root->data.STCTH << endl;

		// setcolor(LIGHTRED);
		// // outtextxy(TABLE_FILTER_SX + 5, hang + 5, tochar(to_string(stt+1)));
		// outtextxy(TABLE_FILTER_SX + 5 + 50 , line + 5, tochar(root->data.idSubject));
		// outtextxy(TABLE_FILTER_SX + 5 + 50 + 120, line + 5, tochar(root->data.nameSubject));
		// outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 , line + 5, tochar(to_string(root->data.STCLT)));
		// outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 + 60, line + 5, tochar(to_string(root->data.STCTH)));
		// line += 30;
		// std::cout << line << std::endl;

        // searchAVL2(root->right, key, line);
    }

    if (root->data.idSubject.compare(0, key.length(), key) < 0) // Nếu dữ liệu của nút nhỏ hơn key, tìm trong cây con bên phải
        searchAVL2(root->right, key, line);
    else if (root->data.idSubject.compare(0, key.length(), key) > 0) // Nếu dữ liệu của nút lớn hơn key, tìm trong cây con bên trái
        searchAVL2(root->left, key, line);
    else if(root->data.idSubject.compare(0, key.length(), key) == 0) {
        // Nếu dữ liệu của nút bằng key, in ra nút này và tiếp tục tìm kiếm trong cây con bên trái và bên phải
        searchAVL2(root->left, key, line);

        cout << "Data is: " << endl;
        cout << setw(5) << root->data.idSubject << " ";
        cout << setw(20) << root->data.nameSubject << " ";
        cout << setw(5) << root->data.STCLT << " ";
        cout << setw(5) << root->data.STCTH << endl;

		setcolor(LIGHTRED);
		// outtextxy(TABLE_FILTER_SX + 5, dong + 5, tochar(to_string(stt+1)));
		outtextxy(TABLE_FILTER_SX + 5 + 50 , line + 5, tochar(root->data.idSubject));
		outtextxy(TABLE_FILTER_SX + 5 + 50 + 120, line + 5, tochar(root->data.nameSubject));
		outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 , line + 5, tochar(to_string(root->data.STCLT)));
		outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 + 60, line + 5, tochar(to_string(root->data.STCTH)));
		line += 30;
		if(line > 520)
			return;
		std::cout << line << std::endl;


        searchAVL2(root->right, key, line);
    }
	else{
		std::cout << "Khong tim thay data can tim kiem...\n";

		setfillstyle(SOLID_FILL, WHITE);
		bar(TABLE_FILTER_SX + 1, TABLE_FILTER_SY + 31, TABLE_FILTER_LX, TABLE_FILTER_LY);
		setcolor(LIGHTGRAY);
		setbkcolor(WHITE);
		outtextxy(TABLE_FILTER_SX + 180, TABLE_FILTER_SY + 50, "KHONG TIM KIEM THAY DU LIEU...");	
		setDefault();
	}
	
}
// //Tim kiem va loc mon hoc theo ten || theo bang sao cay avl chi muc dich hien thi thong tin thoi
// nodeSubject* searchStartsWith(nodeSubject* root, string& key) {
//     if (root == NULL){
// 		std::cout << "Not found!!!" << endl;
// 		setcolor(RED);
// 		outtextxy(TABLE_FILTER_SX + 5, dong + 5, "Khong tim thay du lieu ...");
// 		dong += 30;
//         return NULL;
// 	}

//     if (key.length() == 0) // Trường hợp đặc biệt: nếu chuỗi key rỗng, trả về root
//         return root;

//     if (root->data.nameSubject.compare(0, key.length(), key) < 0) // Nếu dữ liệu của nút nhỏ hơn key, tìm trong cây con bên phải
//         return searchStartsWith(root->right, key);
//     else if (root->data.nameSubject.compare(0, key.length(), key) > 0) // Nếu dữ liệu của nút lớn hơn key, tìm trong cây con bên trái
//         return searchStartsWith(root->left, key);
//     else {
//         // Nếu dữ liệu của nút bằng key, in ra nút này và tiếp tục tìm kiếm trong cả hai cây con
//         std::cout << "Data is: " << endl;
// 		std::cout << setw(5) << root->data.idSubject << "";
// 		std::cout << setw(20) << root->data.nameSubject << " ";
// 		std::cout << setw(5) << root->data.STCLT << " ";
// 		std::cout << setw(5) << root->data.STCTH << "";
// 		std::cout << endl;
		
// 		setcolor(GREEN);
// 		outtextxy(TABLE_FILTER_SX + 5, dong + 5, "001");
// 		outtextxy(TABLE_FILTER_SX + 5 + 50 , dong + 5, tochar(root->data.idSubject));
// 		outtextxy(TABLE_FILTER_SX + 5 + 50 + 120, dong + 5, tochar(root->data.nameSubject));
// 		outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 , dong + 5, tochar(to_string(root->data.STCLT)));
// 		outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 + 60, dong + 5, tochar(to_string(root->data.STCTH)));
// 		dong += 30;
// 		// return root;
//         searchStartsWith(root->left, key);
//         searchStartsWith(root->right, key);
//         return NULL; // Trả về NULL để không làm gì thêm
//     }
// }

//search lai
// nodeSubject* searchAVL(nodeSubject* root, string &key){
// 	// Trường hợp cơ sở: root là null hoặc khóa là root
//     if (root == nullptr || root->data.nameSubject == key){
// 		// setcolor(GREEN);
// 		// outtextxy(TABLE_FILTER_SX + 5, dong + 5, "001");
// 		// outtextxy(TABLE_FILTER_SX + 5 + 50 , dong + 5, tochar(root->data.idSubject));
// 		// outtextxy(TABLE_FILTER_SX + 5 + 50 + 120, dong + 5, tochar(root->data.nameSubject));
// 		// outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 , dong + 5, tochar(to_string(root->data.STCLT)));
// 		// outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 + 60, dong + 5, tochar(to_string(root->data.STCTH)));
// 		// dong += 30;
//        return root;
// 	}

//     // Khóa lớn hơn khóa của root
//     if (root->data.nameSubject < key)
//        return searchAVL(root->right, key);

//     // Khóa nhỏ hơn khóa của root
//     return searchAVL(root->left, key);
// }

// Tim kiem mon hoc thong qua array tmp duoc tao ra de xu li hien thi
void searchStartWithArray(subject *arraySubject, int sizeArraySubject, string &keySearch){
	int stt = 0;
	bool checkSearch = false;

	//test doc data...
	for(int i = 0; i < sizeArraySubject; i++){
		std::cout << setw(3) << i + 1 << setw(30) << arraySubject[i].nameSubject << endl;
	}

	int hang = TABLE_FILTER_SY + 30;

	if(keySearch == " ")
		std::cout << "Chua nhap du lieu tim kiem......" << endl;
	else{
		for(int i = 0; i < sizeArraySubject; i++){
			std::cout << "dang tim kiem.............." << i + 1 << endl;
			if(arraySubject[i].nameSubject.compare(0, keySearch.length(), keySearch) == 0){
				std::cout << "Data is searched: ";
				std::cout << setw(5)	<< to_string(stt + 1);
				std::cout << setw(10) 	<< arraySubject[i].idSubject;
				std::cout << setw(30) 	<< arraySubject[i].nameSubject;
				std::cout << setw(5) 	<< arraySubject[i].STCLT;
				std::cout << setw(5) 	<< arraySubject[i].STCTH;
				std::cout << endl;
				if(stt >= 3)
					continue; // tranh viec tran man hinh hien thi.

				setcolor(LIGHTRED);
				outtextxy(TABLE_FILTER_SX + 5, hang + 5, tochar(to_string(stt+1)));
				outtextxy(TABLE_FILTER_SX + 5 + 50 , hang + 5, tochar(arraySubject[i].idSubject));
				outtextxy(TABLE_FILTER_SX + 5 + 50 + 120, hang + 5, tochar(arraySubject[i].nameSubject));
				outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 , hang + 5, tochar(to_string(arraySubject[i].STCLT)));
				outtextxy(TABLE_FILTER_SX + 5 + 50 + 120 + 340 + 60, hang + 5, tochar(to_string(arraySubject[i].STCTH)));
				hang += 30;

				stt++;
				checkSearch = true;
			}
		}
	}

	if(checkSearch == false){
		std::cout << "Khong tim thay data can tim kiem...\n";

		setfillstyle(SOLID_FILL, WHITE);
		bar(TABLE_FILTER_SX + 1, TABLE_FILTER_SY + 31, TABLE_FILTER_LX, TABLE_FILTER_LY);

		setcolor(LIGHTGRAY);
		setbkcolor(WHITE);
		outtextxy(TABLE_FILTER_SX + 180, TABLE_FILTER_SY + 50, "KHONG TIM KIEM THAY DU LIEU...");	

		setDefault();
	}

	std::cout << "Seach complete array ......" << endl;
}

// Thong bao co hanh dong thoat man hinh
void noticeError(){
	setcolor(LIGHTRED);
	rectangle(TABLE_ERROR_SX, TABLE_ERROR_SY, TABLE_ERROR_LX, TABLE_ERROR_LY);
	setfillstyle(SOLID_FILL, LIGHTMAGENTA);
	bar(TABLE_ERROR_SX + 2, TABLE_ERROR_SY + 2, TABLE_ERROR_LX-1, TABLE_ERROR_LY-1);

	setcolor(WHITE);
	setbkcolor(LIGHTMAGENTA);
	outtextxy(TABLE_ERROR_SX + 50, TABLE_ERROR_SY + 40, "Ban muon thoat?");
	outtextxy(TABLE_ERROR_SX + 10, TABLE_ERROR_SY + 70, "Nhan ENTER : tiep tuc.");
	outtextxy(TABLE_ERROR_SX + 10, TABLE_ERROR_SY + 100, "Nhan 2 ESC : thoat!");

	setDefault();
}


// xoa node tree avl
/* Given a non-empty binary search tree, 
return the node with minimum key value 
found in that tree. Note that the entire 
tree does not need to be searched. */
nodeSubject * minValueNode(nodeSubject* node) 
{ 
    nodeSubject* current = node; 
 
    /* loop down to find the leftmost leaf */
    while (current->left != NULL) 
        current = current->left; 
 
    return current; 
} 
 
// Recursive function to delete a node 
// with given key from subtree with 
// given root. It returns root of the 
// modified subtree. 
nodeSubject* deleteNode(nodeSubject* root, string & key) 
{ 
     
    // STEP 1: PERFORM STANDARD BST DELETE 
    if (root == NULL) 
        return root; 
 
    // If the key to be deleted is smaller 
    // than the root's key, then it lies
    // in left subtree 
    if ( key < root->data.idSubject ) 
        root->left = deleteNode(root->left, key); 
 
    // If the key to be deleted is greater 
    // than the root's key, then it lies 
    // in right subtree 
    else if( key > root->data.idSubject ) 
        root->right = deleteNode(root->right, key); 
 
    // if key is same as root's key, then 
    // This is the node to be deleted 
    else
    { 
        // node with only one child or no child 
        if( (root->left == NULL) ||
            (root->right == NULL) ) 
        { 
            nodeSubject *temp = root->left ? 
                         root->left : 
                         root->right; 
 
            // No child case 
            if (temp == NULL) 
            { 
                temp = root; 
                root = NULL; 
            } 
            else // One child case 
            *root = *temp; // Copy the contents of 
                           // the non-empty child 
            free(temp); 
        } 
        else
        { 
            // node with two children: Get the inorder 
            // successor (smallest in the right subtree) 
            nodeSubject* temp = minValueNode(root->right); 
 
            // Copy the inorder successor's 
            // data to this node 
            root->data = temp->data; 
 
            // Delete the inorder successor 
            root->right = deleteNode(root->right, 
                                     temp->data.idSubject); 
        } 
    } 
 
    // If the tree had only one node
    // then return 
    if (root == NULL) 
    return root; 
 
    // STEP 2: UPDATE HEIGHT OF THE CURRENT NODE 
    root->height = 1 + max(height(root->left), 
                           height(root->right)); 
 
    // STEP 3: GET THE BALANCE FACTOR OF 
    // THIS NODE (to check whether this 
    // node became unbalanced) 
    int balance = getBalance(root); 
 
    // If this node becomes unbalanced, 
    // then there are 4 cases 
 
    // Left Left Case 
    if (balance > 1 && 
        getBalance(root->left) >= 0) 
        return rightRotate(root); 
 
    // Left Right Case 
    if (balance > 1 && 
        getBalance(root->left) < 0) 
    { 
        root->left = leftRotate(root->left); 
        return rightRotate(root); 
    } 
 
    // Right Right Case 
    if (balance < -1 && 
        getBalance(root->right) <= 0) 
        return leftRotate(root); 
 
    // Right Left Case 
    if (balance < -1 && 
        getBalance(root->right) > 0) 
    { 
        root->right = rightRotate(root->right); 
        return leftRotate(root); 
    } 
 
    return root; 
} 


// In danh sach avl tree
void printRootLeftRight(nodeSubject *root){
	if(root != nullptr){
		std::cout 
		<< setw(10) << root->data.idSubject 
		<< setw(30) << root->data.nameSubject 
		<< setw(5) << root->data.STCLT 
		<< setw(5) << root->data.STCTH 
		<< endl;
		printRootLeftRight(root->left);
		printRootLeftRight(root->right);
	}
}

void printUserManual (){
	setcolor(BLACK);
	outtextxy(200, 610, "ESC : Thoat!");
	outtextxy(200, 635, "ENTER : Ket thuc du lieu nhap vao."); 
	outtextxy(200, 660, "Nhap data truoc - Click INSERT sau | Click DELETE truoc - Nhap data can xoa sau.");
	setDefault();
}

//Sap xep theo ten mon hoc.
void selectionSort(subject *listSubject, int sizeListSubject){
	for(int i = 0; i < sizeListSubject - 1; i++){
		int indexMin = i;
		for(int j = i+ 1; j < sizeListSubject; j++){
			if(listSubject[j].nameSubject < listSubject[indexMin].nameSubject)
				indexMin = j;
		}
		subject tmpListSubject = listSubject[i];
		listSubject[i] = listSubject[indexMin];
		listSubject[indexMin] = tmpListSubject;
	}
}


// Phần xử lý điều khiển ---------------------------------------------------------------------------------------------------------
//----------------------------------------------------------------
// Xu li ghi file
//Dieu khien them sua xoa tai man hinh mon hoc
void controlAddDeleteSubject(listSubject &lsb, subject arraySubject[], int sizeArraySubject, bool checkSeletedItem){
	printUserManual();

	//Mac dinh thanh sang thanh cuon luc dau
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_LX - 18, TABLE_SY + 60, TABLE_LX - 2, TABLE_LY - 16);
	setfillstyle ( SOLID_FILL, LIGHTBLUE);
	bar(TABLE_LX - 16, TABLE_SY + 60, TABLE_LX - 6, TABLE_SY + 120);
	// drawSearchFilter();
	// cout << "In bangarraySubject[i].
	char key;
	int ascii;
	int x, y;

	int checkPageListTable = (lsb.size - 1)/15;
	int tmpCheckListTable = checkPageListTable;
	int tmpPage = 0;

	bool clickLan1 = false;
	int click = 0;

	// check da nhap du chua de insert
	bool checkInputId = false;
	bool checkInputName = false;
	bool checkInputLT = false;
	bool checkInputTH = false;

	bool checkIdDelete = false;

	bool checkClickDataTable = false;
	subject subjectUpdate;

	string idSub = "", nameSub =  "";
	int stclt = -1, stcth = -1;

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
	    		noticeError();//bao hanh dong
				key = getch();
				if(key == ESC){
					return;
				}else{
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_ERROR_SX, TABLE_ERROR_SY, TABLE_ERROR_LX + 2, TABLE_ERROR_LY + 2);
					continue;
				}
			}

			// if(ascii = ENTER)
			// 	continue;
		}

		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			
			++click;
			highlightClickMouse(x, y, lsb, arraySubject, sizeArraySubject, checkPageListTable);


			// keo ra khoi highlightClickMouse
			dong = TABLE_FILTER_SY + 30;
			// Neu click mouse gap thi hightlight thanh sang cho thanh search 

			int checkOutList = (lsb.size - 1)/15;// check list nay se chạy tu 0 den checkOutList
			// luc nay check out list = 1

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

						if (text == SPACE){
							if (index == 0 || isPrevSpace) // Loại bỏ dấu cách đầu hoặc liên tiếp
								continue;
							isPrevSpace = true;
						}else
							isPrevSpace = false;

						if (text == ENTER) 
							break; 
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


				// Xu li thanh search
				/*Thanh search hien thi thong tin sang mot ben theo dang loc du lieu
					- 
				*/
				drawSearchFilter();
				std::cout << "In bang filter\n";
				// displaySubjectList(root); // in danh sach du lieu mon hoc bang avl  
				std::string strSearch(textSearch);
				std::cout << "Search for strings starting with '" << strSearch << "': \n";

				//Xu ly tim kiem bang avl tree.

				// ptrSubject root1 = lsb.root;
				// nodeSubject* result1 = searchAVL(root1, strSearch);
				// if (result1->data.nameSubject == strSearch){
				//     cout << result1->data.nameSubject << endl;
				// 	cout <<"da in thanh cong du lieu duoc tim kiem\n";
				// 	// int i = TABLE_FILTER_SY;
				// 	// outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, dong + 5, tochar(result1->data.nameSubject));
				// 	// dong += 30;
				// 	for(int i = TABLE_FILTER_SY + 60; i < TABLE_FILTER_LY; i += 30){
				// 		setcolor(RED);
				// 		outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, i + 5, tochar(result1->data.nameSubject));
				// 	}
				// }
				// else{
				//     cout << "Not found." << endl;

				// 	// setfillstyle(SOLID_FILL, WHITE);
				// 	// bar(TABLE_FILTER_SX, TABLE_FILTER_SY + 31, TABLE_FILTER_LX, TABLE_FILTER_LY);
				// 	// setcolor(LIGHTGRAY);
				// 	// rectangle(TABLE_FILTER_SX, TABLE_FILTER_SY, TABLE_FILTER_LX, TABLE_FILTER_LY);
				// 	// int i = TABLE_FILTER_SY + 30;
				// 	// outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, dong + 5, "Khong tim thay du lieu...");
				// 	// dong -= 30;
				// 	for(int i = TABLE_FILTER_SY + 30; i < TABLE_FILTER_LY; i += 30){
				// 		setcolor(YELLOW);
				// 		setcolor(GREEN);
				// 		outtextxy(TABLE_FILTER_SX + 10 + 50 + 120, i + 5, "Khong tim thay du lieu...");
				// 	}
				// }
				// string strSubFind = findSubjectByName(strSearch, lsb.root);
				// cout << "Chuoi sau khi loc du lieu: " << strSubFind << "\nhet!!" << endl;

				// Thu lai xu li bang mang
				int line = TABLE_FILTER_SY + 30;
				searchAVL2(lsb.root, strSearch, line);// tim kiem tren cay avl
				std::cout << "Da tim kiem avl xong ... \n";


 				searchStartWithArray(arraySubject, lsb.size, strSearch);
			}
			else {
				highlightFrameDefault(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250 + 30 + 30, TABLE_CONTROL_SX - 1 + 10 + 300, TABLE_CONTROL_SY + 50 - 1 + 250 + 30 + 60);
			}

			// MUC ID môn học
			if(TABLE_CONTROL_SX + 5 <= x && TABLE_CONTROL_SY + 30 + 30 <= y && TABLE_CONTROL_SX + 120 >= x && y <= TABLE_CONTROL_SY + 60 + 30){
				// Neu click mouse gap thi hightlight thanh sang cho thanh search
				highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);

				//xu li nhâp du lieu vao khung id
				const int sizeTextId = 8; 
				char stringTextId[sizeTextId]; 
				std::string tmpTextId;
				int indexId = 0; 
				std::cout << "Nhap vao mot chuoi id (nhap Enter de ket thuc):\n";

				while (true) { 
					if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
						char textId = getch(); 
						if (textId == ENTER && tmpTextId.length() == 7) { 
							std::cout << "size mtpTextId: " << tmpTextId << endl;
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
					tmpTextId = stringTextId;
				}
				stringTextId[indexId] = '\0'; // Thêm ký tự kết thúc chuỗi
				std::cout << "\nChuoi da nhap: " << stringTextId << std::endl;
				setcolor(BLUE);
				setbkcolor(WHITE);
				bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
				outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextId);


				setDefault();

				//----------------------------------------------------------------------------------------------
				// xu lý bộ nhớ ở đây la xong phim.
				/*Lấy dữ liệu nhập của IDsubject đưa vào cây avl
				- Nếu IDsubject không tồn tại thì không cần thông báo không tìm thấy IDsubject
					+Tiếp tục đưa dữ liệu này vào node của cây avl.
				- Nếu IDsubject tồn tại thì thông báo tìm thấy IDsubject
					+ Hiện ra màn hình thông báo lỗi "ĐÃ TỒN TẠI IDSUBJECT" và yêu cầu nhập lại IDsubject
				
				*/
				
				// chay kiem tra id nhap vao co bị trung lap voi database da co hay kkhong
				if(checkIdSubject(lsb.root, stringTextId) == false && stringTextId != ""){
					idSub = stringTextId;
					std::cout << "idSub: " << idSub << endl;

					// xu li data insert vao avl tree
					checkInputId = true;
				}else{
					std::cout << setw(10) << stringTextId << setw(15) << "Da ton tai id..." << endl;

					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);//an du lieu nhap khong hop le.
					// Bao loi trung idsubject
					setcolor(LIGHTRED);
					setbkcolor(WHITE);
					outtextxy(TABLE_CONTROL_SX + 150, TABLE_CONTROL_SY + 70, "ID da ton tai!");
					delay(3000);
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 150-2, TABLE_CONTROL_SY + 70, TABLE_CONTROL_SX + 310, TABLE_CONTROL_SY + 100);
				}


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

				if(checkNameSubject(lsb.root, textName) == false && textName != ""){
					nameSub = textName;
					std::cout << "nameSub: " << nameSub << endl;
					// xu li 
					checkInputName = true;

				}else{
					// Thong bao loi trung du lieu.
					std::cout << setw(30) << textName << setw(10) << "Mon hoc da ton tai!" << endl;

					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 60 + 30 + 30, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);//an du lieu nhap khong hop le.

					setcolor(LIGHTRED);
					setbkcolor(WHITE);
					outtextxy(TABLE_CONTROL_SX + 130, TABLE_CONTROL_SY + 70, "Mon hoc da ton tai!" ); 
					delay(3000);
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 130, TABLE_CONTROL_SY + 70,TABLE_CONTROL_SX + 335, TABLE_CONTROL_SY + 100);
					setDefault();
				}
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
				const int sizeTextLT = 3; 
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

				if(textLT != ""){
					stclt = stringtoint(textLT);
					std::cout << "stclt : " << stclt << endl;

					checkInputLT = true;
				}

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
				const int sizeTextTH = 3; 
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

				if(textTH != ""){
					stcth = stringtoint(textTH);
					std::cout << "stcth: " << stcth << endl;

					checkInputTH = true;
				}

				setDefault();
			}
			else {
				highlightFrameDefault(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100, TABLE_CONTROL_SY + 195 + 30);
			}


			//----------------------------------------------------
			// Highlight khung sang khi click mouse Them, Sua, Xoa.

			// Muc Them - insert
			if(TABLE_CONTROL_SX + 1 + 10 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 <= y && x <= TABLE_CONTROL_SX - 1 + 10 + 100 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30){
				setbkcolor(BLUE);
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, BLUE);
				bar(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100, TABLE_CONTROL_SY + 50 + 250 + 30);
				outtextxy(TABLE_CONTROL_SX + 10 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "INSERT");
				//Xu li them vao avl
				if(checkInputId && checkInputName && checkInputLT && checkInputTH){
					// Thuc hien insert
					subject nodeNewSubject;
					nodeNewSubject.idSubject = idSub;
					nodeNewSubject.nameSubject = nameSub;
					nodeNewSubject.STCLT = stclt;
					nodeNewSubject.STCTH = stcth;

					insert(lsb.root, nodeNewSubject);// insert vao node avl tree.
					lsb.size++;
					std::cout << "size node subject: " << lsb.size << endl;
					arraySubject[lsb.size-1] = nodeNewSubject;
					// cout << "Xem danh sach subject moi...\n";
					// for(int i = 0; i < lsb.size; i++){
					// 	cout << setw(5) << i + 1 << setw(10) << arraySubject[i].idSubject << setw(30) << arraySubject[i].nameSubject << endl;	
					// }
					// An data subject
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
					bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 60 + 30 + 30, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 90 + 30 + 30 - 1);
					bar(TABLE_CONTROL_SX + 1 + 5, TABLE_CONTROL_SY + 1 + 175 + 20, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);
					bar(TABLE_CONTROL_SX + 1 + 5 + 150, TABLE_CONTROL_SY + 1 + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 100 - 1, TABLE_CONTROL_SY + 195 + 30 - 1);

					// gan nhan false lai de khong insert lung tung
					checkInputId = false;
					checkInputName = false;
					checkInputLT = false;
					checkInputTH = false;
				}
				else{
					if(checkInputId == false){
						std::cout << "Error! Not complete data input idsubject..." << endl;
						setcolor(RED);
						setbkcolor(LIGHTCYAN);
						outtextxy(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, "Chua nhap IDsubject!");
						
						delay(1000);
						setfillstyle(SOLID_FILL, WHITE);
						bar(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, TABLE_CONTROL_SX + 320, TABLE_CONTROL_SY + 300);
						setDefault();
					}
					if(checkInputName == false){
						std::cout << "Error! Not complete data input nameSubject..." << endl;
						setcolor(RED);
						setbkcolor(LIGHTCYAN);
						outtextxy(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, "Chua nhap nameSubject!");
						
						delay(1000);
						setfillstyle(SOLID_FILL, WHITE);
						bar(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, TABLE_CONTROL_SX + 320, TABLE_CONTROL_SY + 300);
						setDefault();
					}
					if(checkInputLT == false){
						std::cout << "Error! Not complete data input STCLT subject..." << endl;
						setcolor(RED);
						setbkcolor(LIGHTCYAN);
						outtextxy(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, "Chua nhap STCLT!");
						
						delay(1000);
						setfillstyle(SOLID_FILL, WHITE);
						bar(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, TABLE_CONTROL_SX + 320, TABLE_CONTROL_SY + 300);
						setDefault();
					}
					if(checkInputTH == false){
						std::cout << "Error! Not complete data input STCTH subject..." << endl;
						setcolor(RED);
						setbkcolor(LIGHTCYAN);
						outtextxy(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, "Chua nhap STCTH!");
						
						delay(1000);
						setfillstyle(SOLID_FILL, WHITE);
						bar(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, TABLE_CONTROL_SX + 320, TABLE_CONTROL_SY + 300);
						setDefault();
					}
					// Thong bao loi toan bo.
					// cout << "Error! Not complete data subject input..." << endl;
					// setcolor(RED);
					// setbkcolor(LIGHTCYAN);
					// outtextxy(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 250, "Chua nhap du data subject!");
					// delay(3000);
					// setfillstyle(SOLID_FILL, LIGHTCYAN);
					// bar(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 250, TABLE_CONTROL_SX + 320, TABLE_CONTROL_SY + 280);
					setDefault();
				}
			}else{
				setbkcolor(LIGHTBLUE);
				setfillstyle(SOLID_FILL, LIGHTBLUE);
				setcolor(BLACK);
			
				bar(TABLE_CONTROL_SX + 1 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100, TABLE_CONTROL_SY + 50 + 250 + 30);
				outtextxy(TABLE_CONTROL_SX + 10 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "INSERT");
			}

			// Muc Xoa - Delete Subject
			if(TABLE_CONTROL_SX + 1 + 10 + 100 + 10 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 <= y && x <= TABLE_CONTROL_SX  - 1 + 10 + 100 + 110 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30){
				std::cout << "\nXoa - Delete Subject" << endl;
				setbkcolor(BLUE);
				setcolor(WHITE);
				setfillstyle(SOLID_FILL, BLUE);
				bar(TABLE_CONTROL_SX + 1 + 10 + 100 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110, TABLE_CONTROL_SY + 50 + 250 + 30);
				outtextxy(TABLE_CONTROL_SX + 10 + 110 + 10, TABLE_CONTROL_SY + 50 + 250 + 5,"DELETE");

				// // MUC ID môn học - De xoa thong tin
				checkIdDelete = true;
				// printRootLeftRight(lsb.root);
			}else{
				setbkcolor(LIGHTBLUE);
				setfillstyle(SOLID_FILL, LIGHTBLUE);
				setcolor(BLACK);

				bar(TABLE_CONTROL_SX + 1 + 10 + 100 + 10, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110, TABLE_CONTROL_SY + 50 + 250 + 30);
				outtextxy(TABLE_CONTROL_SX + 10 + 110 + 10, TABLE_CONTROL_SY + 50 + 250 + 5,"DELETE");
			}

			if(checkIdDelete == true){
				checkIdDelete = false;
				std::cout << "click dung muc ID de xoa thong tin" << endl;
				// Highlight sang len de user nhan thay.
				highlightFrame(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);

				//xu li nhâp du lieu vao khung id
				const int sizeTextIdDelete = 8; 
				char stringTextIdDelete[sizeTextIdDelete]; 
				string tmpTextIdDelete;
				int indexIdDelete = 0; 
				std::cout << "Nhap vao mot chuoi id (nhap Enter de ket thuc):\n";

				while (true) { 
					if (kbhit()) { // Kiểm tra xem có ký tự được nhấn từ bàn phím không
						char textIdDelete = getch(); 
						if (textIdDelete == ENTER && tmpTextIdDelete.length() == 7) { 
							std::cout << "size mtpTextId: " << tmpTextIdDelete << endl;
							break; 
						}
						else if(textIdDelete == SPACE){
							continue;
						}
						else if (textIdDelete == BACKSPACE) { 
							if (indexIdDelete > 0) { 
								std::cout << "\b \b"; 
								indexIdDelete--; 
								stringTextIdDelete[indexIdDelete] = '\0'; // Thêm ký tự kết thúc chuỗi
								// cout << textSearch << endl;
								setcolor(BLUE);
								setbkcolor(YELLOW);
								bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
								stringTextIdDelete[indexIdDelete] = '\0'; // Thêm ký tự kết thúc chuỗi
								outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextIdDelete);

								setDefault();
							}
						}
						else if (indexIdDelete < sizeTextIdDelete - 1) { 
							//Neu 3 ki tu dau tien thi mac dinh la chu in hoa.
							if((('A' <= textIdDelete && textIdDelete <= 'Z') || ('a' <= textIdDelete && textIdDelete <= 'z')) && (0 <= indexIdDelete && indexIdDelete <= 2)){
								stringTextIdDelete[indexIdDelete++] = toupper(textIdDelete); 
								std::cout << textIdDelete; 
							}
							else if((3 <= indexIdDelete && indexIdDelete <= 6) && ('0' <= textIdDelete && textIdDelete <= '9')){
								stringTextIdDelete[indexIdDelete++] = textIdDelete;
								std::cout << textIdDelete; 
							}
							setcolor(BLUE);
							setbkcolor(YELLOW);
							bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
							stringTextIdDelete[indexIdDelete] = '\0'; // Thêm ký tự kết thúc chuỗi
							outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextIdDelete);

							setDefault();
						}
					}
					tmpTextIdDelete = stringTextIdDelete;
				}
				stringTextIdDelete[indexIdDelete] = '\0'; // Thêm ký tự kết thúc chuỗi
				std::cout << "\nID subject can xoa: " << stringTextIdDelete << std::endl;
				setcolor(BLUE);
				setbkcolor(WHITE);
				bar(TABLE_CONTROL_SX + 5 + 1, TABLE_CONTROL_SY + 30 + 30 + 1, TABLE_CONTROL_SX + 120 - 1, TABLE_CONTROL_SY + 60 + 30 - 1);
				outtextxy(TABLE_CONTROL_SX + 5 + 5, TABLE_CONTROL_SY + 30 + 30 + 5, stringTextIdDelete);
				setDefault();

				string textDelete = string(stringTextIdDelete);
				deleteNode(lsb.root, textDelete);
				lsb.size--;
				std::cout << "xoa node id = " << textDelete << " thanh cong ..." << endl; 
			}

			// neu click vao bang du lieu     thi hien thi vao khung xu ly.
			if(TABLE_SX + 50  <= x && x <= TABLE_LX - 30 && TABLE_SY + 40 <= y && y <= TABLE_LY){
				checkClickDataTable = true;

				// kiem tra xem co click vao o nao khong
				int indexTable = (y - TABLE_SY - 40) / 22;

				if(tmpPage*15 + indexTable < lsb.size){
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 6, TABLE_CONTROL_SY + 62, TABLE_CONTROL_SX + 119, TABLE_CONTROL_SY + 89);
					bar(TABLE_CONTROL_SX + 6, TABLE_CONTROL_SY + 121, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 150 - 1);
					bar(TABLE_CONTROL_SX + 6, TABLE_CONTROL_SY + 1 + 195, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 225 - 1);
					bar(TABLE_CONTROL_SX + 6 + 150, TABLE_CONTROL_SY + 1 + 195, TABLE_CONTROL_SX + 5 + 250 - 1, TABLE_CONTROL_SY + 225 - 1);
					
					setbkcolor(WHITE);
					setcolor(RED);
					outtextxy(TABLE_CONTROL_SX + 10, TABLE_CONTROL_SY + 64, tochar(arraySubject[15*tmpPage + indexTable].idSubject));
					outtextxy(TABLE_CONTROL_SX + 10, TABLE_CONTROL_SY + 123, tochar(arraySubject[15*tmpPage + indexTable].nameSubject));
					outtextxy(TABLE_CONTROL_SX + 10, TABLE_CONTROL_SY + 3 + 195, tochar(to_string(arraySubject[15*tmpPage + indexTable].STCLT)));
					outtextxy(TABLE_CONTROL_SX + 10 + 150, TABLE_CONTROL_SY + 3 + 195, tochar(to_string(arraySubject[15*tmpPage + indexTable].STCTH)));

					// dua data duoc chon vao bien tmp
					idSub 	= arraySubject[15*tmpPage + indexTable].idSubject;
					nameSub = arraySubject[15*tmpPage + indexTable].nameSubject;
					stclt 	= stringtoint(to_string( arraySubject[15*tmpPage + indexTable].STCLT ));
					stcth 	= stringtoint(to_string( arraySubject[15*tmpPage + indexTable].STCTH ));

					subjectUpdate.idSubject		= idSub;
					subjectUpdate.nameSubject 	= nameSub;
					subjectUpdate.STCLT			= stclt;
					subjectUpdate.STCTH			= stcth;
				}
				else{
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 6, TABLE_CONTROL_SY + 62, TABLE_CONTROL_SX + 119, TABLE_CONTROL_SY + 89);
					bar(TABLE_CONTROL_SX + 6, TABLE_CONTROL_SY + 121, TABLE_CONTROL_SX + 330 - 1, TABLE_CONTROL_SY + 150 - 1);
					bar(TABLE_CONTROL_SX + 6, TABLE_CONTROL_SY + 1 + 195, TABLE_CONTROL_SX + 100 - 1, TABLE_CONTROL_SY + 225 - 1);
					bar(TABLE_CONTROL_SX + 6 + 150, TABLE_CONTROL_SY + 1 + 195, TABLE_CONTROL_SX + 5 + 250 - 1, TABLE_CONTROL_SY + 225 - 1);
				}
			}

			// Muc Update Subject
			if(TABLE_CONTROL_SX + 1 + 10 + 110*2 <= x && TABLE_CONTROL_SY + 50 + 1 + 250 <= y && x <= TABLE_CONTROL_SX  - 1 + 10 + 100 + 110*2 && y <= TABLE_CONTROL_SY + 50 - 1 + 250 + 30){
				if(checkClickDataTable == true){
					setbkcolor(BLUE);
					setcolor(WHITE);
					setfillstyle(SOLID_FILL, BLUE);

					bar(TABLE_CONTROL_SX + 1 + 10 + 110*2, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX + 10 + 100 + 110*2, TABLE_CONTROL_SY + 50 + 250 + 30);
					outtextxy(TABLE_CONTROL_SX + 10 + 110*2 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "UPDATE");


					//xu li update khi nhan click chuot vao vị tri danh sách 
					deleteNode(lsb.root, idSub);// xoa node
					lsb.size--;
					insert(lsb.root, subjectUpdate);
					lsb.size++;

					std::cout << "update thanh cong..." << std::endl;

					// du lieu hiẹn ra , neu xoa thi cat di duoi cua du lieu, neu them vao thi tao ra chuoi moi va cong vao.

					// Update xong thi reset lai bien tmp, de tranh xung dot data.
					idSub 	= " ";
					nameSub = " ";
					stclt 	= -1;
					stcth 	= -1; 
				}
				else{
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, TABLE_CONTROL_SX + 320, TABLE_CONTROL_SY + 300);
					setcolor(RED);
					setbkcolor(WHITE);
					outtextxy( TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, "Chua chon data de update...");
					delay(1000);
					setfillstyle(SOLID_FILL, WHITE);
					bar(TABLE_CONTROL_SX + 20, TABLE_CONTROL_SY + 270, TABLE_CONTROL_SX + 320, TABLE_CONTROL_SY + 300);
					setDefault();
				}
			}else{
				setbkcolor(LIGHTBLUE);
				setfillstyle(SOLID_FILL, LIGHTBLUE);
				setcolor(BLACK);

				bar(TABLE_CONTROL_SX + 1 + 10 + 110*2, TABLE_CONTROL_SY + 50 + 1 + 250, TABLE_CONTROL_SX  + 10 + 100 + 110*2, TABLE_CONTROL_SY + 50 + 250 + 30);
				outtextxy(TABLE_CONTROL_SX + 10 + 110*2 + 10, TABLE_CONTROL_SY + 50 + 250 + 5, "UPDATE");
			}



			// Hight light thanh truot/cuon ========================///////////////////////////////
			int rowTable = TABLE_SY + 40 + D_ROW/10 -1;
			// checkPageListTable = 0;
			// len
			if(TABLE_LX - 20 <= x && TABLE_SY + 30 <= y && x <= TABLE_LX && y <= TABLE_SY + 60){
				int index1 = 0;
				avlToArray(lsb.root, arraySubject, index1);

				drawTableListSubject ();

				tmpPage--;
				if(tmpPage < 0){
					tmpPage = 0;
				}
				if(tmpPage >= (lsb.size - 1)/15){
					tmpPage = (lsb.size - 1)/15;
				}

				if(checkSeletedItem == true)// khi dang o muc xem danh sach theo ten
					selectionSort(arraySubject, index1);
				
				for(int i = 15*tmpPage; i < 15 + 15*tmpPage; i++){
					if(i >= lsb.size) // tranh viec in ra nhieu hon so thu tu.
						continue;

					char number[4]; // luu tru day so tu dong tang
					sprintf(number, "%03d", i + 1);
					setbkcolor(WHITE);
					setcolor(GREEN);
					// setfillstyle(SOLID_FILL, YELLOW);
					outtextxy(TABLE_SX + 10, TABLE_SY + 40 + (i%15)*D_ROW + D_ROW/10 - 1, number);	

					setbkcolor(WHITE);
					setcolor(GREEN);
					outtextxy(TABLE_SX + 20 + 50, rowTable, tochar(arraySubject[i].idSubject));
					outtextxy(TABLE_SX + 20 + 50 + 120, rowTable, tochar(arraySubject[i].nameSubject));
					outtextxy(TABLE_SX + 20 + 50 + 120 + 340, rowTable, tochar(to_string(arraySubject[i].STCLT)));
					outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, rowTable, tochar(to_string(arraySubject[i].STCTH)));
					rowTable += D_ROW;
				}

				setbkcolor(RED);
				setcolor(RED);
				int x1 = TABLE_LX - 20, y1 = TABLE_SY + 40 + 14;
				int x2 = TABLE_LX - 20 + 8, y2 = TABLE_SY + 40;
				int x3 = TABLE_LX - 20 + 16, y3 = TABLE_SY + 40 + 14;
				
				line(x1, y1, x2, y2);
				line(x2, y2, x3, y3);
				line(x3, y3, x1, y1);
				int points1[] = {x1, y1, x2, y2, x3, y3, x1, y1};
				setfillstyle(SOLID_FILL, RED);
				fillpoly(4, points1);
			}else{
				drawScrollBarSubject();
			}
			//xuong
			if((TABLE_LX - 20 <= x && TABLE_LY-20 <= y && x <= TABLE_LX && y <= TABLE_LY + 20)){
				int index2 = 0;
				avlToArray(lsb.root, arraySubject, index2);

				drawTableListSubject ();
				//
				tmpPage++;
				if(tmpPage >= (lsb.size - 1)/15){
					tmpPage = (lsb.size - 1)/15;
				}
				if(tmpPage < 0){
					tmpPage = 0;
				}
				
				if(checkSeletedItem == true)// khi xem danh sach tai muc dnah sach theo ten
					selectionSort(arraySubject, index2);

				for(int i = 15*tmpPage; i < 15 + 15*tmpPage; i++){
					if(i >= lsb.size) // tranh viec in ra nhieu hon so thu tu.
						continue;

					// print so thu tu theo du  lieu.
					char number[4]; // luu tru day so tu dong tang
					sprintf(number, "%03d", i + 1);
					setbkcolor(WHITE);
					setcolor(GREEN);
					// setfillstyle(SOLID_FILL, YELLOW);
					outtextxy(TABLE_SX + 10, TABLE_SY + 40 + (i%15)*D_ROW + D_ROW/10 - 1, number); // print theo tung bang 15 hang	
					
					setbkcolor(WHITE);
					setcolor(GREEN);
					outtextxy(TABLE_SX + 20 + 50, rowTable, tochar(arraySubject[i].idSubject));
					outtextxy(TABLE_SX + 20 + 50 + 120, rowTable, tochar(arraySubject[i].nameSubject));
					outtextxy(TABLE_SX + 20 + 50 + 120 + 340, rowTable, tochar(to_string(arraySubject[i].STCLT)));
					outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, rowTable, tochar(to_string(arraySubject[i].STCTH)));
					rowTable += D_ROW;
				}
				//
				setbkcolor(RED);
				setcolor(RED);

				int x1 = TABLE_LX - 20, y1 = TABLE_SY + 40 + 14;
				int x2 = TABLE_LX - 20 + 8, y2 = TABLE_SY + 40;
				int x3 = TABLE_LX - 20 + 16, y3 = TABLE_SY + 40 + 14;

				int u1 = TABLE_LX - 20 + 1, v1 = TABLE_LY - 14;
				int u2 = TABLE_LX - 20 + 1 + 8, v2 = TABLE_LY;
				int u3 = TABLE_LX - 20 + 1 + 16, v3 = TABLE_LY - 14;
				line(u1, y1, u2, v2);
				line(u2, y2, u3, v3);
				line(u3, y3, u1, v1);
				int points2[] = {u1, v1, u2, v2, u3, v3, u1, v1};
				setfillstyle(SOLID_FILL, RED);
				fillpoly(4, points2);
			}else{
				drawScrollBarSubject();
			}

			// Hien thi khung chi muc du lieu thanh cuon
			if(tmpPage == 0){// re chuot o dau danh sach, mac dinh thi checkListtable == ((lsb.size - 1)/15 roi.
				setfillstyle(SOLID_FILL, WHITE);
				bar(TABLE_LX - 18, TABLE_SY + 60, TABLE_LX - 2, TABLE_LY - 16);
				setfillstyle ( SOLID_FILL, LIGHTBLUE);
				bar(TABLE_LX - 16, TABLE_SY + 60, TABLE_LX - 6, TABLE_SY + 120);
			}
			else if(tmpPage == ((lsb.size - 1)/15) ){//re chuot den cuoi danh sach.
				setfillstyle(SOLID_FILL, WHITE);
				bar(TABLE_LX - 18, TABLE_SY + 60, TABLE_LX - 2, TABLE_LY - 16);
				setfillstyle ( SOLID_FILL, LIGHTBLUE);
				bar(TABLE_LX - 16, TABLE_LY - 76, TABLE_LX - 6, TABLE_LY - 16);
			}
			else{
				setfillstyle(SOLID_FILL, WHITE);
				bar(TABLE_LX - 18, TABLE_SY + 60, TABLE_LX - 2, TABLE_LY - 16);
				setfillstyle ( SOLID_FILL, LIGHTBLUE);
				bar(TABLE_LX - 16, (TABLE_SY + 60 + tmpPage*(295)/tmpCheckListTable) - 30, TABLE_LX - 6, (TABLE_SY + 60 + tmpPage*(295)/tmpCheckListTable) + 30);
			}

			setDefault();
		}
	}
}


// Hàm vẽ menu và cập nhật lựa chọn
void drawMenuAndUpdateSelection(listSubject &lsb, int &selectedItem) {
	bool checkSelectedItem = false;

    int y = MENU_SUB_SY; // Vị trí y của menu đầu tiên
	std::cout << selectedItem << " draw menu" << endl;
	char key;
	while(true){
		if(selectedItem == 0){
			std::cout << "selectItem 0" << endl;
			reloadingDataSubject();
			drawTableControlSubject();
			// Xu li enter tai day
			drawTableListSubject ();
			//print Danh sach theo tên môn hoc.
//			printSTT(lsb);
			subject subjectListArray[500];
			int arraySize = 0;
			// subject* subjectListArray = arraySubject(lsb.root, arraySize);
			avlToArray(lsb.root, subjectListArray, arraySize);
			y = TABLE_SY + 40 + D_ROW/10 -1;
			drawTableListSubject();
//			printSTT(lsb);
			// print so thu tu theo du  lieu.

			// In danh sach bang cay avl
			// displaySubjectList(lsb.root);

			//In danh sach bang mang.
			for(int i=0; i<15; i++){// print ra danh sach mon hoc
				char number[4]; // luu tru day so tu dong tang
				sprintf(number, "%03d", i + 1);
				setbkcolor(WHITE);
				setcolor(GREEN);
				// setfillstyle(SOLID_FILL, YELLOW);
				outtextxy(TABLE_SX + 10, TABLE_SY + 40 + (i%15)*D_ROW + D_ROW/10 - 1, number); // print theo tung bang 15 hang	

				setbkcolor(WHITE);
				setcolor(GREEN);
				outtextxy(TABLE_SX + 20 + 50, y, tochar(subjectListArray[i].idSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120, y, tochar(subjectListArray[i].nameSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340, y, tochar(to_string(subjectListArray[i].STCLT)));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, y, tochar(to_string(subjectListArray[i].STCTH)));
				y += D_ROW;
			}
			drawHeaderAndBottom();

			// Them phan dieu khien khi click mouse
			reloadingDataSubject();
			std::cout << "reload data list subject\n";
			
			std::cout << "\nSize subject truoc khi vao control" << setw(5) << arraySize << endl;
			controlAddDeleteSubject(lsb, subjectListArray, arraySize, checkSelectedItem);
			// delete[] subjectListArray;
		}
		else if(selectedItem == 1){
			checkSelectedItem = true;

			std::cout << "selected 1" << endl;
			reloadingDataSubject();

			drawTableControlSubject();
			// Xu li enter tai day
			drawTableListSubject ();
			//===========================
			int sizeArraySubject = 0;
			subject subjectListArray[500];
			avlToArray(lsb.root, subjectListArray, sizeArraySubject);

			selectionSort(subjectListArray, sizeArraySubject);
			// for(int i = 0; i < sizeArraySubject; ++i){
			// 	int indexCerrent = i;
			// 	while(indexCerrent > 0 && subjectListArray[indexCerrent - 1].nameSubject > subjectListArray[indexCerrent].nameSubject){
			// 		subject nodeTmp = subjectListArray[indexCerrent];
			// 		subjectListArray[indexCerrent] = subjectListArray[indexCerrent - 1];
			// 		subjectListArray[indexCerrent - 1] = nodeTmp;

			// 		indexCerrent--;
			// 	}
			// }

			// int arraySize = 0;
			// subject* subjectListArray = arraySubject(lsb.root, arraySize);
			// for(int i = 0; i < arraySize; i++){ 
			// 	int indexCurrent = i;
			// 	while(indexCurrent > 0 && subjectListArray[indexCurrent-1].nameSubject > subjectListArray[indexCurrent].nameSubject){
			// 		subject temp = subjectListArray[indexCurrent];
			// 		subjectListArray[indexCurrent] = subjectListArray[indexCurrent-1];
			// 		subjectListArray[indexCurrent-1] = temp;

			// 		indexCurrent--;
			// 	}
			// }

			y = TABLE_SY + 40 + D_ROW/10 -1;
			drawTableListSubject();
			// printSTT(lsb);
			for(int i=0; i<15; i++){// print ra danh sach mon hoc
				char number[4]; // luu tru day so tu dong tang
				sprintf(number, "%03d", i + 1);
				setbkcolor(WHITE);
				setcolor(GREEN);
				// setfillstyle(SOLID_FILL, YELLOW);
				outtextxy(TABLE_SX + 10, TABLE_SY + 40 + (i%15)*D_ROW + D_ROW/10 - 1, number);	

				setbkcolor(WHITE);
				setcolor(GREEN);
				outtextxy(TABLE_SX + 20 + 50, y, tochar(subjectListArray[i].idSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120, y, tochar(subjectListArray[i].nameSubject));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340, y, tochar(to_string(subjectListArray[i].STCLT)));
				outtextxy(TABLE_SX + 20 + 50 + 120 + 340 + 60, y, tochar(to_string(subjectListArray[i].STCTH)));
				y += D_ROW;
			}
			
			drawHeaderAndBottom();

			controlAddDeleteSubject(lsb, subjectListArray, sizeArraySubject, checkSelectedItem);
			// delete[] subjectListArray;hj
			//=================


			// getch();// dung man hinh de xem
		}
		else if(selectedItem == 2){
			
			drawTableControlSubject();
			// Xu li enter tai day
			drawTableListSubject ();
			//print Danh sach theo tên môn hoc.
			printSTT(lsb);
			std::cout << "selectedIrem 2" << endl;
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
					std::cout << "3 case subject mana" << selected << endl;
					/* code */
					switch(selected){
						case 0: 
							std::cout << "case 1 subject mana" << endl;
							drawMenuAndUpdateSelection(lsb, selected);// xu ly hien giao dien danh sach theo id tai day
							menuTQSubject(selected);
							break;
						case 1: 
							std::cout << "case 2 subject manager" << endl;
							drawMenuAndUpdateSelection(lsb, selected);// xu ly hien giao dien danh sach theo ten mon hoc tai day
							menuTQSubject(selected);// hightlight mousee chuot
							break;
						case 2: 
							std::cout << "case 3 subject manager" << endl;
							drawMenuAndUpdateSelection(lsb, selected);// xu ly hien giao dien cap nhat
							menuTQSubject(selected);// hightlight mousee chuot
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
				break;
				std::cout << "4\n";
			}
		}
	}
}

#endif 
