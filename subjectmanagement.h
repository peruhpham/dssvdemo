#ifndef SUBJECTMANAGEMENT_H 
#define SUBJECTMANAGEMENT_H

//#include "datastructure.h"
//#include "datahanding.h"
//#include "display.h"
//using namespace std;

//#define MENU_SX 10
//#define MENU_SY 70
//#define MENU_LX 310
//#define MENU_LY 100


void subjectManagement(listSubject &lsb);
void displaySubjectList(ptrNodeSubject root, int x, int y);
void drawMenuOption();
//----------------------------------------------------------------
void drawMenuOption(){
    setcolor(LIGHTBLUE);
    setlinestyle(SOLID_LINE, 0, 1);
	rectangle(10, 70 + 60 + 45*1, 1340, 70+60 + 90);
}

void outListTable (){

	// setcolor(BLACK);	
	// outtextxy(500, 500, "hxinhf fhff2 4344341414143 43");
	
//	setDefault();
}

//----------------------------------------------------------------
// test consol
//void displaySubjectList(ptrNodeSubject root) {
//    if (root != nullptr) {
//        displaySubjectList(root->left);
//        std::cout << "MA MON HOC: " << root->data.idSubject << std::endl;
//        std::cout << "TEN MON HOC: " << root->data.nameSubject << std::endl;
//        std::cout << "SO TIN CHI LI THUYET: " << root->data.STCLT << std::endl;
//        std::cout << "SO TIN CHI THUC HANH: " << root->data.STCTH << std::endl << std::endl;
//        displaySubjectList(root->right);
//    }
//}

void displaySubjectList(ptrNodeSubject root, int x, int y) {
//	y+= 50;
    if (root != nullptr) {
        if (root->left != nullptr) {    
            displaySubjectList(root->left, x, y); 
            y+= 10;
        }
        setcolor(RED); 
        outtextxy(x, y, const_cast<char*>(root->data.idSubject.c_str())); 
        outtextxy(x + 150, y, const_cast<char*>(root->data.nameSubject.c_str())); 
        outtextxy(x + 400, y, const_cast<char*>(to_string(root->data.STCLT).c_str())); 
        outtextxy(x + 450, y, const_cast<char*>(to_string(root->data.STCTH).c_str())); 
        y+= 20;
        if (root->right != nullptr) {
            displaySubjectList(root->right, x, y); 
            y+= 10;
        }
    }
}

//----------------------------------------------------------------

void drawSubjectTableHeader() {
    setcolor(BLACK);
    outtextxy(TABLSPOINTX + 5, TABLSPOINTY, "ID MON HOC");
    outtextxy(TABLSPOINTX + 150, TABLSPOINTY, "TEN MON HOC");
    outtextxy(TABLSPOINTX + 370, TABLSPOINTY, "STCLT");
    outtextxy(TABLSPOINTX + 515, TABLSPOINTY, "STCTH");
}

void drawSubjectTableRow(int y, subject subject) {
    setcolor(BLACK);
    outtextxy(TABLSPOINTX + 5, y, tochar(subject.idSubject));
    outtextxy(TABLSPOINTX + 150, y, tochar(subject.nameSubject));
    outtextxy(TABLSPOINTX + 370, y, tochar(to_string(subject.STCLT)));
    outtextxy(TABLSPOINTX + 515, y, tochar(to_string(subject.STCTH)));
}

//void drawSubjectList(listSubject lsb) {
//    drawSubjectTableHeader(); 
//
//    int y = TABLSPOINTY; 
//    for (int i = 0; i < 5; i++) {
//        drawSubjectTableRow(y, lsb.subjectArr[i]); 
//        y += 50; 
//    }
//}


void subjectManagement(listSubject &lsb){
	drawSubjectManagement();
	
//	drawSubjectTableHeader();
	//test 
    displaySubjectList(lsb.root, 400, 100);
//    displaySubjectList(lsb.root);
	 

	// subject sub;
	// outListTable ();
	// setcolor(BLACK);	
	// outtextxy(500, 500, "hxinhf fhff2 4344341414143 43");


//	listSubject lsb = readSubjectListFromFile("subjects.txt");

//    drawSubjectList(lsb); 

    getch();
}

#endif 
