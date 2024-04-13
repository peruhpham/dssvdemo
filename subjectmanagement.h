#ifndef SUBJECTMANAGEMENT_H 
#define SUBJECTMANAGEMENT_H

//#include "datastructure.h"
//#include "datahanding.h"
//#include "display.h"
//using namespace std;
 

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

#define MAX_MON_HOC 100

void subjectManagement(listSubject &lsb);
void drawTableListSubject ();
void displaySubjectList(ptrSubject root);
void resetDisplaySubjectList(int &x, int &y);

void hightlightLineSubject();
void tieuXaoSubject();

void drawMenuSubject();
void drawMenuAndUpdateSelection(listSubject &lsb, int selectedItem);

void copyAVLToArray(ptrSubject root, subject arrSubject[], int& index);
//void displaySubjectListByControl();

void printSTT (listSubject &lsb);
void printListSubjectByName(subject *sub, int x, int y);
// void inorderTraversal(ptrSubject root, subject staticArray[], int& index);
void AVLToArray(ptrSubject currentNodeSubject, subject *arrayTmp, int &currentIndex);


void drawTableControlSubject();
//----------------------------------------------------------------



// tao giao dien moi cDanh sach mon hoc
void drawTableListSubject (){
	setcolor(RED);
	rectangle(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);

	setfillstyle(SOLID_FILL, YELLOW);
	bar(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);
	//----------------------------------------------------------------
	// new table
	setlinestyle(SOLID_LINE, 0, 1);
	//khung 
	setcolor(LIGHTGRAY);
	rectangle(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_LY);
	//----------------
	// vẽ thanh cuộn 
	// setcolor(RED);
	rectangle(TABLE_LX + 1, TABLE_SY, TABLE_LX - 20, TABLE_LY);
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_LX + 1, TABLE_SY, TABLE_LX - 20, TABLE_LY);
	//----------------------------------------------------------------

	int x1 = TABLE_LX + 1, y1 = TABLE_SY + 14;
	int x2 = TABLE_LX + 1 + 8, y2 = TABLE_SY;
	int x3 = TABLE_LX + 1 + 16, y3 = TABLE_SY + 14;
	line(x1, y1, x2, y2);
	line(x2, y2, x3, y3);
	line(x3, y3, x1, y1);
	int points1[] = {x1, y1, x2, y2, x3, y3, x1, y1};
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillpoly(4, points1);

	int u1 = TABLE_LX + 1, v1 = TABLE_LY - 14;
	int u2 = TABLE_LX + 1 + 8, v2 = TABLE_LY;
	int u3 = TABLE_LX + 1 + 16, v3 = TABLE_LY - 14;
	line(u1, y1, u2, v2);
	line(u2, y2, u3, v3);
	line(u3, y3, u1, v1);
	int points2[] = {u1, v1, u2, v2, u3, v3, u1, v1};
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	fillpoly(4, points2);
	
	//-------
	setlinestyle(SOLID_LINE, 0, 1);
	line(TABLE_SX + 50, TABLE_SY, TABLE_SX + 50, TABLE_LY);
	line(TABLE_SX + 50 + 120, TABLE_SY, TABLE_SX + 50 + 120, TABLE_LY);
	line(TABLE_SX + 50 + 120 + 340, TABLE_SY, TABLE_SX + 50 + 120 +340, TABLE_LY);
	line(TABLE_SX + 50 + 120 + 340 + 60, TABLE_SY, TABLE_SX + 50 + 120 + 340 + 60, TABLE_LY);
	
    setfillstyle(SOLID_FILL, LIGHTBLUE);// Thiet lap mau fill la mau xanh lam
    bar(TABLE_SX, TABLE_SY, TABLE_LX, TABLE_SY + 40);// Ve hinh chu nhat
	
	setlinestyle(SOLID_LINE, 0, 1);
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
//----------------------------------------------------------------
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
}

void resetDisplaySubjectList(int &x, int &y){
    x = TABLE_SX + 50;
    y = TABLE_SY + D_ROW/10 -1 + 40;

	// setfillstyle(SOLID_FILL, WHITE);
	// bar(TABLE_SX, TABLE_SY, TABLE_LX+30, TABLE_LY+1);
}

// void displaySubjectListByControl(listSubject lsb){
// //	listSubject lsb;
// //    readListSubject(lsb, "subjectlist.txt");
// 	copyAVLToArray(lsb.root, arrSubject, index);

// 	cout << "Danh sach mon hoc sao chep tu cay AVL:" << endl;
//     for (int i = 0; i < index; ++i) {
//         cout << "ID: " << arrSubject[i].idSubject << ", Name: " << arrSubject[i].nameSubject << ", STCLT: " << arrSubject[i].STCLT << ", STCTH: " << arrSubject[i].STCTH << endl;
//     }
// 	cout << endl;
// 	cout << "HET" << endl;


// }
//----------------------------------------------------------------

//----------------------------------------------------------------
void hightlightLineSubject(){

}
//----------------------------------------------------------------
void tieuXaoSubject(){
    // setcolor(LIGHTBLUE);
    // bar(TABLE_SX, 0, TABLE_LX, TABLE_SY);
    // bar(TABLE_SX, TABLE_LY, TABLE_LX, TABLE_LY + 200);
	createHeader();
	createBottom();
}

//----------------------------------------------------------------
void drawMenuSubject(){
	//Thiet lap mau cho khung menu subject
	setfillstyle(SOLID_FILL, WHITE);
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
}
//----------------------------------------------------------------
// Hàm duyệt cây AVL theo thứ tự in-order và thêm phần tử vào mảng tĩnh


//==========================================================================
 // Duyệt cây và lưu thông tin vDanh sách tạm thời
// ptrSubject danhSachTamThoi[MAX_MON_HOC];
// int currentIndex = 0;

// Hàm so sánh hai môn học theo tên môn học
// bool soSanhTheoTenMonHoc(const ptrSubject& sub1, const ptrSubject& sub2) {
//     return sub1->data.nameSubject < sub2->data.nameSubject;
// }

// Duyệt cây và lưu thông tin vDanh sách tạm thời
// void duyetCayVaLuuThongTin(ptrSubject root, ptrSubject danhSachTamThoi[], int& currentIndex) {
//     if (root != NULL) {
//         duyetCayVaLuuThongTin(root->left, danhSachTamThoi, currentIndex);
//         danhSachTamThoi[currentIndex++] = root;
//         duyetCayVaLuuThongTin(root->right, danhSachTamThoi, currentIndex);
//     }
// }

// Hàm sắp xếp chọn
// void sapXepChon(ptrSubject danhSach[], int n, bool (*soSanh)(const ptrSubject&, const ptrSubject&)) {
//     for (int i = 0; i < n - 1; i++) {
//         int minIndex = i;
//         for (int j = i + 1; j < n; j++) {
//             if (soSanh(danhSach[j], danhSach[minIndex])) {
//                 minIndex = j;
//             }
//         }
//         if (minIndex != i) {
//             swap(danhSach[i], danhSach[minIndex]);
//         }
//     }
// }

// Danh sách môn học theo thứ tự tên môn học
// void inDanhSachTheoTenMonHoc(ptrSubject danhSachTamThoi[], int n) {
//     for (int i = 0; i < n; ++i) {
//         cout << "Ten mon hoc: " << danhSachTamThoi[i]->data.nameSubject << ", Id: " << danhSachTamThoi[i]->data.idSubject << endl;
//     }
// }



//----------------------------------------------------------------
// reset lại menu
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
            // Xử lý phím lên
            if (key == 72) {
                selectedItem = (selectedItem - 1 + 3) % 3;
            }
            // Xử lý phím xuống
            else if (key == 80) {
                selectedItem = (selectedItem + 1) % 3;
            }
            // In lại menu với lựa chọn mới được tô sáng
            y = MENU_SUB_SY;
			setcolor(BLACK);
            outtextxy(MENU_SUB_SX, 10 + y, ">> Danh sach mon theo ID");
            outtextxy(MENU_SUB_SX, 10 + y + MENU_ITEM_HEIGHT, ">> Danh sach mon theo Ten");
            outtextxy(MENU_SUB_SX, 10 + y + 2 * MENU_ITEM_HEIGHT, ">> Nhap mon hoc");
            // Tô sáng lựa chọn hiện tại
            // setcolor(RED);
            // outtextxy(MENU_SUB_SX, 10 + y + selectedItem * MENU_ITEM_HEIGHT, ">>");
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
}

//----------------------------------------------------------------
void AVLtoArray(nodeSubject* currentNodeSubject, subject *arrayTmp, int &currentIndex){//chuyen du lieu tu cay avl sang array
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
}

subject* arraySubject(nodeSubject* currentNodeSubject, int &arraySize) {
	countNodeSubject(currentNodeSubject, arraySize);
	subject *arraySub = new subject[arraySize];
	int currentIndex = 0;
	AVLtoArray(currentNodeSubject, arraySub, currentIndex);
	return arraySub;
}

void printListSubjectByName(subject *sub, int &x, int &y){
	for(int i=0; i<11; i++){
		outtextxy(TABLE_SX + 50, y, tochar(sub[i].idSubject));
		outtextxy(TABLE_SX + 50 + 120, y, tochar(sub[i].nameSubject));
		outtextxy(TABLE_SX + 50 + 120 + 340, y, tochar(to_string(sub[i].STCLT)));
		outtextxy(TABLE_SX + 50 + 120 + 340 + 60, y, tochar(to_string(sub[i].STCTH)));
	}
	y += D_ROW;
}

//----------------------------------------------------------------
void drawTableControlSubject(){
	setcolor(BLUE);
	rectangle(TABLE_CONTROL_SX, TABLE_CONTROL_SY, TABLE_CONTROL_LX, TABLE_CONTROL_LY); // draw vien do

	setfillstyle(SOLID_FILL, LIGHTCYAN);
	bar(TABLE_CONTROL_SX+1, TABLE_CONTROL_SY+1, TABLE_CONTROL_LX-1, TABLE_CONTROL_LY-2); // draw nen gray
	
	
	outtextxy(TABLE_CONTROL_SX + 2, TABLE_CONTROL_SY, "CAP NHAT THONG TIN");// tieu de bang dieu khien

	setcolor(BLUE);
	settextstyle(SMALL_FONT, HORIZ_DIR, 5);// dieu chinh kich thuoc chu

	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60-20 , "Ma mon hoc:");
	rectangle(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 30 + 30, TABLE_CONTROL_SX + 120, TABLE_CONTROL_SY + 60 + 30);// o de nhap thong tin id mon hoc

	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 120-20 , "Ten mon hoc:");
	rectangle(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 60 + 30 + 30, TABLE_CONTROL_SX + 330, TABLE_CONTROL_SY + 90 + 30 + 30);// o de nhap thong tin id mon hoc

	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 160, "So tin chi");

	outtextxy(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175, "Ly thuyet:");
	rectangle(TABLE_CONTROL_SX + 5, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 80, TABLE_CONTROL_SY + 195 + 30);// o de nhap thong tin id mon hoc

	outtextxy(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175, "Thuc hanh:");
	rectangle(TABLE_CONTROL_SX + 5 + 150, TABLE_CONTROL_SY + 175 + 20, TABLE_CONTROL_SX + 5 + 150 + 80, TABLE_CONTROL_SY + 195 + 30);// o de nhap thong tin id mon hoc
	
	
	setDefault();

	// 340px den 680px = 340px -> moi o 100px -> kc 10px
	rectangle(TABLE_CONTROL_SX + 10, TABLE_CONTROL_SY + 250, TABLE_CONTROL_SX + 10 + 100, TABLE_CONTROL_SY + 250 + 30);
	outtextxy(TABLE_CONTROL_SX + 10 + 10, TABLE_CONTROL_SY + 250 + 5, "(+) THEM");
	rectangle(TABLE_CONTROL_SX + 10 + 100 + 10, TABLE_CONTROL_SY + 250, TABLE_CONTROL_SX + 10 + 100 + 110, TABLE_CONTROL_SY + 250 + 30);
	outtextxy(TABLE_CONTROL_SX + 10 + 110 + 10, TABLE_CONTROL_SY + 250 + 5,"(-) XOA");
	rectangle(TABLE_CONTROL_SX + 10 + 110*2, TABLE_CONTROL_SY + 250, TABLE_CONTROL_SX + 10 + 100 + 110*2, TABLE_CONTROL_SY + 250 + 30);
	outtextxy(TABLE_CONTROL_SX + 10 + 110*2 + 10, TABLE_CONTROL_SY + 250 + 5, "SUA");

}


// Phan xu lý/////////////////////////////////////////
//----------------------------------------------------------------

// Hàm vẽ menu và cập nhật lựa chọn
void drawMenuAndUpdateSelection(listSubject &lsb, int selectedItem) {
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
        if (kbhit()) {
            key = getch();
            // Xử lý phím lên
            if (key == 72) {
                selectedItem = (selectedItem - 1 + 3) % 3;
            }
            // Xử lý phím xuống
            else if (key == 80) {
                selectedItem = (selectedItem + 1) % 3;
            }
            // In lại menu với lựa chọn mới được tô sáng
            y = MENU_SUB_SY;
			setcolor(BLACK);
            outtextxy(MENU_SUB_SX, 10 + y, ">> Danh sach mon theo ID");
            outtextxy(MENU_SUB_SX, 10 + y + MENU_ITEM_HEIGHT, ">> Danh sach mon theo Ten");
            outtextxy(MENU_SUB_SX, 10 + y + 2 * MENU_ITEM_HEIGHT, ">> Nhap mon hoc");
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
		
		if(key == ENTER && selectedItem == 0){
			// xu li nhap
			drawTableControlSubject();



			// Xu li enter tai day
			drawTableListSubject ();
			displaySubjectList(lsb.root);
			printSTT(lsb);
			tieuXaoSubject();

			key = getch();
			if(key == ESC){
				tieuXaoSubject();
				setcolor(LIGHTGRAY);
				bar(TABLE_SX, TABLE_SY, TABLE_LX + 30, TABLE_LY + 1);
				// resetMenuSubject(selectedItem);
				break;
			}
			// break; // thoat khoi vòng lap
			//================================================================
		}
		else if(key == ENTER && selectedItem == 1){
			drawTableControlSubject();

			// Xu li enter tai day
			drawTableListSubject ();
			//priDanh sach theo tên môn hoc.

			// displaySubjectList(lsb.root);
			printSTT(lsb);
			//-===========================
			int arraySize = 0;
			subject* subjectListArray = arraySubject(lsb.root, arraySize);
			
			cout << "\narray from AVL tree data\n";
			for(int i = 0; i < arraySize; i++){
				cout << subjectListArray[i].idSubject << " " << subjectListArray[i].nameSubject << " " << subjectListArray[i].STCLT << " " << subjectListArray[i].STCTH << endl;

			}
			y = TABLE_SY + 40 + D_ROW/10 -1;

			for(int i = 0; i < arraySize; i++){ // sap xep theo ten mon hoc
				int indexCurrent = i;
				while(indexCurrent > 0 && subjectListArray[indexCurrent-1].nameSubject > subjectListArray[indexCurrent].nameSubject){
					subject temp = subjectListArray[indexCurrent];
					subjectListArray[indexCurrent] = subjectListArray[indexCurrent-1];
					subjectListArray[indexCurrent-1] = temp;

					indexCurrent--;
				}
			}

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
			
			// duyetCayVaLuuThongTin(lsb.root, danhSachTamThoi, currentIndex);

			// Sắp xDanh sách tạm thời theo tên môn học
			// sapXepChon(danhSachTamThoi, currentIndex, soSanhTheoTenMonHoc);

			// Danh sách môn học theo thứ tự tên môn học
			cout << "Danh sach mon hoc theo thu tu ten:" << endl;
			// inDanhSachTheoTenMonHoc(danhSachTamThoi, currentIndex);

			//=================

			tieuXaoSubject();

			key = getch();
			if(key == ESC){
				tieuXaoSubject();
				
				setcolor(LIGHTGRAY);
				bar(TABLE_SX, TABLE_SY, TABLE_LX + 30, TABLE_LY + 1);

				// resetMenuSubject(selectedItem);
				break;
			}
			// getch(); 
			break; // thoat khoi vòng lap
		}
		else if(key == ENTER && selectedItem == 2){
			// Xu li enter tai day
				drawTableListSubject ();
				// displaySubjectList(lsb.root);

				tieuXaoSubject();

				// getch();
				break; // thoat khoi vòng lap/
		}

		else if(key == ESC)
			break;
	}


}


//----------------------------------------------------------------
void subjectManagement(listSubject &lsb, int selected){	
	setcolor(BLACK);
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY, ">> Danh sach mon theo ID");
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY + MENU_ITEM_HEIGHT, ">> Danh sach mon theo Ten");
	outtextxy(MENU_SUB_SX, 10 + MENU_SUB_SY + 2 * MENU_ITEM_HEIGHT, ">> Nhap mon hoc");
	char key = ENTER;
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
			int selectedItem = 0; // Lựa chọn hiện tại của menu
			switch(ascii){
				case ENTER:
					/* code */
					// resetDisplaySubjectList(x, y);
					drawMenuSubject();
					//----------------------------------------------------------------
					drawMenuAndUpdateSelection(lsb, selectedItem);
					//----------------------------------------------------------------
				break;

				case ESC:
					createMenu(selected);

					setfillstyle(SOLID_FILL, RED);
					bar(TABLE_SX, TABLE_SY, TABLE_LX+30, TABLE_LY+10);
				break;
			}
		}
		else if(ascii == ESC)
			break;
	}
    // getch();
    setDefault();
}

#endif 

