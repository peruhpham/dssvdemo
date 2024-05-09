#ifndef STUDENTGRADEMANAGEMENT_H
#define STUDENTGRADEMANAGEMENT_H

#define emptyStr ""
#define MAXYEAR  30
#define MAXSEMESTER 3

void inputExamScores(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls);
void displayStudentRegisteredStudentListV4(listStudent &ls, ptrListRegister &lr,int &currentStudent,int &order);
void drawPrintRegisteredStudentListV4(ptrClassForSubject cfs);
void drawInputExamScoresV2();

//Nguyen mau ham xu ly bang diem lop sinh vien
#define TABLE_CLASS_SX 700
#define TABLE_CLASS_SY 120
#define TABLE_CLASS_LX 1320
#define TABLE_CLASS_LY 190

void drawTableControlClassScores();
void drawTableControlClassScoresEmpty();



//============================================================================================================
void displayStudentRegisteredStudentListV4(listStudent &ls, ptrListRegister &lr,int &currentStudent,int &order){
	// bat dau in thong tin
    ptrRegister current = lr->head;
    
    for(int i = 0; i < currentStudent && current != NULL; i++){
        current = current->next; // dua con tro den vi tri currentStudent
    }

    if(current == NULL){
        return; // khong co sinh vien de hien thi
    }
    
    setbkcolor(WHITE);
    setcolor(BLACK);
    ptrStudent student = NULL;
    int cnt = 0, X = TEXTSPOINTX1, Y = TEXTLPOINTY1 + 5;
    while(current != NULL && cnt < 11){
    	if(current->data.unSub == false){
    		student = findPtrStudent(ls, current->data.idStudent); // tra ve thong tin sinh vien thong qua con tro
        
	        if(student != NULL){
				order += 1;
	        	outtextxy(X + 10, Y, tochar(to_string(order)));
				outtextxy(X + 90, Y, tochar(student->value.id));
				outtextxy(X + 270, Y, tochar(student->value.firstName));
				outtextxy(X + 520, Y, tochar(student->value.lastName));
				
				if(current->data.scores != 11){
					
					string text = to_string(current->data.scores);
					outtextxy(X + 750, Y, tochar(text.substr(0, 4)));
				} 
				else{
					outtextxy(X + 750, Y, "#");	
				}
				
				Y += 30; cnt += 1;
			}
		}
		currentStudent += 1;
		current = current->next;
	}
}

void drawPrintRegisteredStudentListV4(ptrClassForSubject cfs){ // vex bang in diem thi 
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 331); // xoa ta ca thong tin truoc do
	
	setcolor(LIGHTGRAY);
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 330); // tao khung to ben ngoai

	// tao header
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 
	
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	int X = TEXTSPOINTX1;
	outtextxy(X + 10, TEXTLPOINTY1 - 25, "STT");
	outtextxy(X + 90, TEXTLPOINTY1 - 25, "MSSV");
	outtextxy(X + 270, TEXTLPOINTY1 - 25, "HO");
	outtextxy(X + 520, TEXTLPOINTY1 - 25, "TEN");
	outtextxy(X + 750, TEXTLPOINTY1 - 25, "DIEM");
//	outtextxy(X + 710, TEXTLPOINTY1 - 25, "GHI CHU");
	
	// tao duong ke ngnang
	if(cfs != NULL){
		int Y = TEXTLPOINTY1 + 30;
		setcolor(LIGHTGRAY);
		for(int i = 0; i < 11; i++){
			line(TEXTSPOINTX1, Y, TEXTLPOINTX3, Y);
			Y += 30;
		}
		 
		// tao duong ke doc
		line(X + 70, TEXTLPOINTY1 - 30, X + 70, TEXTLPOINTY1 + 330);
		line(X + 250, TEXTLPOINTY1 - 30, X + 250, TEXTLPOINTY1 + 330);
		line(X + 490, TEXTLPOINTY1 - 30, X + 490, TEXTLPOINTY1 + 330);
//		line(X + 600, TEXTLPOINTY1 - 30, X + 600, TEXTLPOINTY1 + 330);
		line(X + 710, TEXTLPOINTY1 - 30, X + 710, TEXTLPOINTY1 + 330);
		
//		setfillstyle(SOLID_FILL, BLUE);
//		bar(TEXTLPOINTX3 - 60, TEXTLPOINTY1 + 336, TEXTLPOINTX3, TEXTLPOINTY1 + 366);
//		setbkcolor(BLUE);
//		setcolor(BLACK);
//		outtextxy(TEXTLPOINTX3 - 45, TEXTLPOINTY1 + 341, "LUU");
	}
	else{
		//tao duong ke doc
		setcolor(LIGHTGRAY);
		line(X + 70, TEXTLPOINTY1 - 30, X + 70, TEXTLPOINTY1);
		line(X + 250, TEXTLPOINTY1 - 30, X + 250, TEXTLPOINTY1);
		line(X + 490, TEXTLPOINTY1 - 30, X + 490, TEXTLPOINTY1);
//		line(X + 600, TEXTLPOINTY1 - 30, X + 600, TEXTLPOINTY1);
		line(X + 710, TEXTLPOINTY1 - 30, X + 710, TEXTLPOINTY1);
		
		setbkcolor(WHITE);
		setcolor(LIGHTGRAY);
		outtextxy(X + 330, TEXTLPOINTY1 + 5, "Chua co du lieu...");
	}
	
	setDefault(); 

}

void drawInputExamScoresV2(){
	setfillstyle(SOLID_FILL, WHITE);
	bar(LISTSPOINTX, LISTSPOINTY - 10, LISTLPOINTX, LISTLPOINTY - 5); // xoa toan bo noi dung trong muc nhap diem
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setbkcolor(WHITE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 40);
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, "Bang Diem Thi");
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY); // tao header cho muc nhap diem
	
	rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40); // ten ma mon hoc
	rectangle(TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40); // hoc ki 
	rectangle(TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40); // nien khoa
	rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40); // nhom
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(TEXTSPOINTX1 + 10, TEXTSPOINTY1 - 65, "Ten mon hoc - Ma");
	outtextxy(TEXTSPOINTX2 - 40, TEXTSPOINTY2 - 65, "Nien khoa");
	outtextxy(TEXTSPOINTX3 - 90, TEXTSPOINTY3 - 65, "Hoc ky");
	outtextxy(TEXTLPOINTX3 - 130, TEXTSPOINTY3 - 65, "Nhom");

	setDefault();
} 
//struct extendRegister{ // mo rong register/ them bien luu giu du lieu khi nhap diem cho register/ sinh vien dang ky nay
//	ptrRegister r;
//	double imformalScore;
//	extendRegister(){
//	}
//	extendRegister(ptrRegister r, double imformalScore){
//		this->r = r;
//		this->imformalScore = imformalScore;
//	}
//};
//
//typedef extendRegister *ptrExtendRegister;
//
//void pushBack(ptrExtendRegister *&arr, int &size, int &capacity, ptrRegister r, double informalScore) {
//    if (size >= capacity) {
//        int newCapacity = capacity * 2;
//        
//        ptrExtendRegister *newArr = new ptrExtendRegister[newCapacity];
//
//        for (int i = 0; i < size; ++i) {
//            newArr[i] = arr[i];
//        }
//
//        delete[] arr;
//
//        arr = newArr;
//        capacity = newCapacity;
//    }
//
//    arr[size++] = new extendRegister(r, informalScore);
//}
void outtextwithlineV2(int lineCurrent, subject s, int COLOR){
	string text = s.nameSubject + "-" + s.idSubject;
	setcolor(COLOR);
	switch(lineCurrent){
		case 0: // in trong box
			outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(text));
			break;
		case 1:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 - 35, tochar(text));
			break;
		case 2:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 - 5, tochar(text));
			break;
		case 3:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 25, tochar(text));
			break;
		case 4:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 55, tochar(text));
			break;
		case 5:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 85, tochar(text));
			break;
		case 6:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 115, tochar(text));
			break;
		case 7:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 145, tochar(text));
			break;
		case 8:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 175, tochar(text));
			break;
	}
	setDefault();
}





void findListIdSubjectV2(ptrSubject root, ptrSubject &firstSubject, int &lineCurrent, string nameSubject){
	if (root == NULL || lineCurrent > 8) return;

    findListIdSubjectV2(root->left, firstSubject, lineCurrent, nameSubject);
    if (lineCurrent <= 8 && isSubString(toLowerCase(nameSubject), toLowerCase(root->data.nameSubject))){
        if (lineCurrent == 1) {
            setbkcolor(LIGHTGRAY);
            firstSubject = root;
        } 
		else setbkcolor(WHITE);
            
        outtextwithlineV2(lineCurrent, root->data, BLACK); 
        lineCurrent++;
    }
    findListIdSubjectV2(root->right, firstSubject, lineCurrent, nameSubject);
}


ptrSubject findPrevSubjectV2(ptrSubject root, ptrSubject p, string nameSubject) {
    if (root == NULL) return NULL;

    stack<ptrSubject> s;
    ptrSubject current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            if(current->data > p->data) break;
            current = current->right;
        }

        current = s.top();
        s.pop();

        if(current->data < p->data && isSubString(toLowerCase(nameSubject), toLowerCase(current->data.nameSubject))) return current;

        current = current->left;
    }
    return NULL;
}

ptrSubject findNextSubjectV2(ptrSubject root, ptrSubject p, string nameSubject){
	if (root == NULL) return NULL;

    stack<ptrSubject> s;
    ptrSubject current = root;

    while (current != NULL || !s.empty()) {
        while (current != NULL) {
            s.push(current);
            if(current->data < p->data) break;
            current = current->left;
        }

        current = s.top();
        s.pop();

        if(current->data > p->data && isSubString(toLowerCase(nameSubject), toLowerCase(current->data.nameSubject))) return current;

        current = current->right;
    }
    return NULL;
}

void outtextwithline2V2(int lineCurrent, int academicYear, int COLOR){
	string text = to_string(academicYear);
	setcolor(COLOR);
	switch(lineCurrent){
		case 0: // in trong box
			outtextxy(TEXTSPOINTX2 - 50 + 5, TEXTSPOINTY2 - 40 + 10, tochar(text));
			break;
		case 1:
			outtextxy(TEXTSPOINTX2 - 50 + 5, TEXTLPOINTY2 - 40 + 5, tochar(text));
			break;
		case 2:
			outtextxy(TEXTSPOINTX2 - 50 + 5, TEXTLPOINTY2 - 40 + 35, tochar(text));
			break;
		case 3:
			outtextxy(TEXTSPOINTX2 - 50 + 5, TEXTLPOINTY2 - 40 + 65, tochar(text));
			break;
		case 4:
			outtextxy(TEXTSPOINTX2 - 50 + 5, TEXTLPOINTY2 - 40 + 95, tochar(text));
			break;
	}
	setDefault();
}

void outtextwithline4V2(int lineCurrent, int semester, int COLOR){
	string text = "Hoc ky " + to_string(semester);
	setcolor(COLOR);
	switch(lineCurrent){
		case 0: // in trong box
			outtextxy(TEXTSPOINTX3 - 100 + 5, TEXTSPOINTY3 - 40 + 10, tochar(text));
			break;
		case 1:
			outtextxy(TEXTSPOINTX3 - 100 + 5, TEXTLPOINTY3 - 40 + 5, tochar(text));
			break;
		case 2:
			outtextxy(TEXTSPOINTX3 - 100 + 5, TEXTLPOINTY3 - 40 + 35, tochar(text));
			break;
		case 3:
			outtextxy(TEXTSPOINTX3 - 100 + 5, TEXTLPOINTY3 - 40 + 65, tochar(text));
			break;
	}
	setDefault();
}
void findListYearV2(int *academicYear, int sizeYear){
	for(int i = 0; i < sizeYear; i++){
		if(i < 4){
			if(i == 0){
				setbkcolor(LIGHTGRAY);
			}
			else setbkcolor(WHITE);
			outtextwithline2V2(i + 1, academicYear[i], BLACK);
		}
		else return;
	}
}

void findListSemesterV2(int *semester, int sizeSemester){
	for(int i = 0; i < sizeSemester; i++){
		if(i == 0){
			setbkcolor(LIGHTGRAY);
		}
		else setbkcolor(WHITE);
		outtextwithline4V2(i + 1, semester[i], BLACK);
	}
}

void displayStudentRegisteredStudentListV2(listStudent &ls, ptrListRegister &lr, int &currentStudent, int &order, double inputScore[], ptrRegister r[]){
	// bat dau in thong tin
    ptrRegister current = lr->head;
    
    for(int i = 0; i < currentStudent && current != NULL; i++){
        current = current->next; // dua con tro den vi tri currentStudent
    }

    if(current == NULL){
        return; // khong co sinh vien de hien thi
    }
    
    setbkcolor(WHITE);
    setcolor(BLACK);
    ptrStudent student = NULL;
    
	int cnt = 0, X = TEXTSPOINTX1, Y = TEXTLPOINTY1 + 5;
    while(current != NULL && cnt < 11){
    	if(current->data.unSub == false){
    		student = findPtrStudent(ls, current->data.idStudent); // tra ve thong tin sinh vien thong qua con tro
        
	        if(student != NULL){
				order += 1;
	        	outtextxy(X + 10, Y, tochar(to_string(order)));
				outtextxy(X + 60, Y, tochar(student->value.id));
				outtextxy(X + 210, Y, tochar(student->value.firstName));
				outtextxy(X + 460, Y, tochar(student->value.lastName));
				
 				if(inputScore[order] != 11){
 					
					string text = to_string(inputScore[order]);
					outtextxy(X + 610, Y, tochar(text.substr(0, 4)));
				}
				else if(current->data.scores != 11){
					
					string text = to_string(current->data.scores);
					outtextxy(X + 610, Y, tochar(text.substr(0, 4)));
				} 

				if(r[order] == NULL){
					r[order] = current;
				}
				Y += 30; cnt += 1;
			}
		}
		currentStudent += 1;
		current = current->next;
	}
    
}


void typingScore(int X1, int Y1, int X2, int Y2, double inputScore[], ptrRegister r[], int pos, int order){
	
	int orderTemp = 0, ascii = 0;
	string score = emptyStr; char key;
	setcolor(BLACK);
	rectangle(X1, Y1, X2, Y2); // to sang hop nhap
	
	// lay du lieu tu hop nhap
	
	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	if(ascii == ET){
	    		setcolor(LIGHTGRAY);
				rectangle(X1, Y1, X2, Y2); // to mau hop nhap
				
				if((int)score.size() == 1){
					score += ".00";
				}
				else if((int)score.size() == 2 && score[1] == '.'){
					score += "00";
				}
				else if((int)score.size() == 3 && score[1] == '.'){
					score += "0";
				}
				else if((int)score.size() == 2 && score[1] != '.'){
					score += ".00";
				}
				
				setcolor(BLACK);
				outtextxy(X1 + 10, Y1 + 5, tochar(score));
				// tim con tro dang click vao
				orderTemp = 11 * ((order - 1) / 11) + pos;
				if(score != emptyStr) inputScore[orderTemp] = stod(score); // luu du lieu vao mang tam cho den khi nguoi dung an nut luu
				
				score = emptyStr;
				break;
			}
			else if(ascii == ESC){
				setcolor(LIGHTGRAY);
				rectangle(X1, Y1, X2, Y2); // to mau hop nhap
				
				setfillstyle(SOLID_FILL, WHITE);
				bar(X1 + 1, Y1 + 1, X2 - 1, Y2 - 1);
				orderTemp = 11 * ((order - 1) / 11) + pos;
				
				setcolor(BLACK);
				if(inputScore[orderTemp] != 11){
					string text = to_string(inputScore[orderTemp]);
					outtextxy(X1 + 10, Y1 + 5, tochar(text.substr(0, 4)));
				}
				else if(r[orderTemp]->data.scores != 11){
					string text = to_string(r[orderTemp]->data.scores);
					outtextxy(X1 + 10, Y1 + 5, tochar(text.substr(0, 4)));
				} 
				
				score = emptyStr;
				break;
			}
			else if(ascii == BP && (int)score.size() > 0){
				score.pop_back();
				setfillstyle(SOLID_FILL, WHITE);
				bar(X1 + 1, Y1 + 1, X2 - 1, Y2 - 1);
				setcolor(BLACK);
				outtextxy(X1 + 10, Y1 + 5, tochar(score));
			}
			else if('0' <= ascii && ascii <= '9' || ascii == '.'){
				setcolor(BLACK);
				if((int)score.size() < 4){
					if( (score.size() == 0 && isdigit(key)) || (score.size() == 1 && key == '.' ) ||
						(score.size() == 1 && score[0] == '1' && key == '0') 
						|| (score.size() > 1) && score[1] == '.' && isdigit(key)){
						score += key;
						
						setfillstyle(SOLID_FILL, WHITE);
						bar(X1 + 1, Y1 + 1, X2 - 1, Y2 - 1);
						outtextxy(X1 + 10, Y1 + 5, tochar(score));
					}
				}
			}
		}
	}
	setDefault();
}


void saveScores(ptrRegister r[], double inputScore[], int sizeList, int &saved, int show){
	for(int i = 1; i < sizeList; i++){
		if(inputScore[i] != 11){ // co diem cap nhap
			r[i]->data.scores = inputScore[i];
		}
	}
	saved = 1;
	
	if(show){
		setbkcolor(WHITE);
		setcolor(BLUE);
		outtextxy(TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 341, "Luu thanh cong!");
		delay(1200);
		setfillstyle(SOLID_FILL, WHITE);
		bar(TEXTSPOINTX1 + 690, TEXTLPOINTY1 + 335, TEXTSPOINTX1 + 890, TEXTLPOINTY1 + 365);
		setDefault();
	}
}
void inputScores(ptrClassForSubject &cfs, listStudent &ls){
	// cfs->lr->head  : danh sach dang ky la danh sach lien ket don.
	int sizeList = cfs->lr->size + 1;
	ptrRegister r[sizeList]; // chua register theo order r[1] = register : o order thu 1 thi du lieu la register
	double inputScore[sizeList]; // chua diem dang nhap
	for(int i = 1; i <= sizeList; i++){
		r[i] = NULL;
		inputScore[i] = 11;
	}
	
	ptrListRegister lr = cfs->lr;
	int currentStudent = 0, prevStudent = 0, order = 0, orderTemp = 0, pos = 0, saved = 0;
	stack <int> st; // duoc su dung khi nhan phim up
	string score = emptyStr;
	
	prevStudent = currentStudent;
	displayStudentRegisteredStudentListV2(ls, lr, currentStudent, order, inputScore, r); // in ra thong tin cac sinh vien dau tien.
	
	char key; int ascii, x, y;
	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	switch(ascii){
	    		case UP:
	    			if(order > 11 && st.empty() == false){ // stack co phan tu nghia la truoc do da an phim down
	    				currentStudent = st.top(); st.pop();
	    				prevStudent = currentStudent;
	    				if(order % 11 == 0) order -= 22;
	    				else order = order - (order % 11) - 11;
	    				drawPrintRegisteredStudentListV2(cfs); //ve lai khung 
	    				displayStudentRegisteredStudentListV2(ls, lr, currentStudent, order, inputScore, r);
					}
	    			break;
	    		case DOWN:
	    			if(currentStudent < lr->size){
	    				st.push(prevStudent);
	    				prevStudent = currentStudent;
	    				drawPrintRegisteredStudentListV2(cfs); // ve lai khung
	    				displayStudentRegisteredStudentListV2(ls, lr, currentStudent, order, inputScore, r);
					}
	    			break;
	    		case ESC:
	    			if(saved == 0){ // chua luu
	    				int selected = createNoticeV2();
	    				if(selected == 1){ // thoat va luu
	    					saveScores(r, inputScore, sizeList, saved, 0);
	    					
	    					drawInputExamScores(); // ve khung cap nhat diem
	    					drawPrintRegisteredStudentListV2(NULL); // ve khung chua danh sach dang ky la rong
	    					return;
	    					
						}
						else if(selected == -1){ // thoat va khong luu
							drawInputExamScores(); // ve khung cap nhat diem
	    					drawPrintRegisteredStudentListV2(NULL); // ve khung chua danh sach dang ky la rong
	    					return;
						}
						else if(selected == 0){ // o lai
							if(order % 11 == 0) order -= 11;
							else order -= (order % 11);
							
							currentStudent = prevStudent; // in lai thong tin cu
							drawPrintRegisteredStudentListV2(cfs); // ve lai khung
	    					displayStudentRegisteredStudentListV2(ls, lr, currentStudent, order, inputScore, r);
						}
					}
					else{ // da luu roi
						int selected = createNoticeV3();
						if(selected == 1){ // thoat
							drawInputExamScores(); // ve khung cap nhat diem
	    					drawPrintRegisteredStudentListV2(NULL); // ve khung chua danh sach dang ky la rong
	    					return;
						}
						else if(selected == 0){ // o lai
							if(order % 11 == 0) order -= 11;
							else order -= (order % 11);
							
							currentStudent = prevStudent; // in lai thong tin cu
							drawPrintRegisteredStudentListV2(cfs); // ve lai khung
	    					displayStudentRegisteredStudentListV2(ls, lr, currentStudent, order, inputScore, r);
						}
					}
	    			break;
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			// nhap diem 
			
			if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 30)){ // nhap diem tren dong 1
				int orderTemp = 11 * ((order - 1) / 11) + 1;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 30, inputScore, r, 1, order);
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 30, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 60)){
				int orderTemp = 11 * ((order - 1) / 11) + 2;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 30, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 60, inputScore, r, 2, order); // nhap diem tren dong 2
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 60, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 90)){
				int orderTemp = 11 * ((order - 1) / 11) + 3;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 60, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 90, inputScore, r, 3, order); // nhap diem tren dong 3
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 90, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 120)){
				int orderTemp = 11 * ((order - 1) / 11) + 4;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 90, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 120, inputScore, r, 4, order); // nhap diem tren dong 4
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 120, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 150)){
				int orderTemp = 11 * ((order - 1) / 11) + 5;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 120, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 150, inputScore, r, 5, order); // nhap diem tren dong 5
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 150, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 180)){
				int orderTemp = 11 * ((order - 1) / 11) + 6;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 150, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 180, inputScore, r, 6, order); // nhap diem tren dong 6
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 180, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 210)){
				int orderTemp = 11 * ((order - 1) / 11) + 7;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 180, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 210, inputScore, r, 7, order); // nhap diem tren dong 7
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 210, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 240)){
				int orderTemp = 11 * ((order - 1) / 11) + 8;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 210, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 240, inputScore, r, 8, order); // nhap diem tren dong 8
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 240, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 270)){
				int orderTemp = 11 * ((order - 1) / 11) + 9;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 240, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 270, inputScore, r, 9, order); // nhap diem tren dong 9
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 270, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 300)){
				int orderTemp = 11 * ((order - 1) / 11) + 10;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 270, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 300, inputScore, r, 10, order); // nhap diem tren dong 10
			}
			else if(clickInRange(x, y, TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 300, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 330)){
				int orderTemp = 11 * ((order - 1) / 11) + 11;
				if(orderTemp < sizeList)
				typingScore(TEXTSPOINTX1 + 600, TEXTLPOINTY1 + 300, TEXTSPOINTX1 + 700, TEXTLPOINTY1 + 330, inputScore, r, 11, order); // nhap diem tren dong 11
			}
			else if(clickInRange(x, y, TEXTLPOINTX3 - 60, TEXTLPOINTY1 + 336, TEXTLPOINTX3, TEXTLPOINTY1 + 366)){ // click vao nut luu
				saveScores(r, inputScore, sizeList, saved, 1);
			}
		}
	}
}


void inputExamScores(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls){
	drawInputExamScores();
	
	int ascii, x, y, selected = 0, on = 0, cntline = 1, lineCurrent = 1;
	ptrSubject firstSubject = NULL;
	ptrClassForSubject cfs = NULL;
	string nameSubject = emptyStr, idSubject = emptyStr, groupTemp = emptyStr;
	char key;
	
	int sizeYear = 0, sizeSemester = MAXSEMESTER, yearCurrent = 1, academic = 0, semes = 0, group = 0;
	int *academicYear = new int[MAXYEAR];
	readListYear(academicYear, sizeYear);
	
	int *semester = new int[MAXSEMESTER]; 
	for(int i = 0; i < MAXSEMESTER; i++){
		semester[i] = i + 1;
	} 
	
	drawPrintRegisteredStudentListV2(cfs);
	while(true){
		mouseHighlightInputExamScores(selected, on);
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	if(ascii == ESC) return;
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInRange(x, y, TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40)){ // ten ma mon hoc
				highlightInputExamScores(selected, BLUE);
				
				lineCurrent = 1; cntline = 1;
				firstSubject = NULL;
				
				createListIdSubjectV2(); // tao khung chua danh sach
				highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
				findListIdSubjectV2(lsj.root, firstSubject, cntline, nameSubject); // loc theo ten va in thong tin ra man hinh
				while(true){
					if(kbhit()){
						key = getch();
						ascii = static_cast<int>(key);
				        if (ascii == 0) { 
				            key = getch();
				            ascii = static_cast<int>(key);
				            ascii += 255;
				    	}
				    	
				    	if(ascii == ET){
				    		if(firstSubject != NULL){
				    			setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
								idSubject = firstSubject->data.idSubject; // du lieu duoc chon luu vao idSubject;
								
								outtextwithlineV2(0, firstSubject->data, BLACK);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
								// neu da du thong tin thi cho phep nhap diem
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);
								drawPrintRegisteredStudentListV2(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
									inputScores(cfs, ls);
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
							}
							else{
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
								idSubject = emptyStr;	
							}
				    		
				    		nameSubject = emptyStr;
				    		lineCurrent = 1;
				    		setcolor(LIGHTGRAY);
							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							setDefault();
							break;
						}
						else if(ascii == UP && firstSubject != NULL){
							if(lineCurrent > 1){
								ptrSubject prevSubject = findPrevSubjectV2(lsj.root, firstSubject, nameSubject); 
								if(prevSubject != NULL){
									highlightInputLineCurrent(lineCurrent, WHITE);
									outtextwithlineV2(lineCurrent, firstSubject->data, BLACK);
									
									firstSubject = prevSubject;
									lineCurrent -= 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, firstSubject->data, BLACK);
								}
							}
							else if(lineCurrent == 1){
								ptrSubject prevSubject = findPrevSubjectV2(lsj.root, firstSubject, nameSubject);
								if(prevSubject != NULL){
									firstSubject = prevSubject;
									
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, prevSubject->data, BLACK);
									
									lineCurrent += 1;
									
									while(findNextSubjectV2(lsj.root, prevSubject, nameSubject) != NULL && lineCurrent <= 8){
										prevSubject = findNextSubjectV2(lsj.root, prevSubject, nameSubject);
										outtextwithlineV2(lineCurrent, prevSubject->data, BLACK);
										lineCurrent += 1;
									}
									lineCurrent = 1;
								}
							}
						}
						else if(ascii == DOWN && firstSubject != NULL){
							if(lineCurrent < 8 && lineCurrent != 0){
								ptrSubject nextSubject = findNextSubjectV2(lsj.root, firstSubject, nameSubject);
								
								if(nextSubject != NULL){
									highlightInputLineCurrent(lineCurrent, WHITE);
									outtextwithlineV2(lineCurrent, firstSubject->data, BLACK);
									
									firstSubject = nextSubject;
									lineCurrent += 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, firstSubject->data, BLACK);
								}
							}
							else if(lineCurrent == 8){
								ptrSubject nextSubject = findNextSubjectV2(lsj.root, firstSubject, nameSubject);
								if(nextSubject != NULL){
									firstSubject = nextSubject;
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, nextSubject->data, BLACK);
									lineCurrent -= 1;
									
									while(findPrevSubjectV2(lsj.root, nextSubject, nameSubject) != NULL && lineCurrent >= 1){
										nextSubject = findPrevSubjectV2(lsj.root, nextSubject, nameSubject);
										outtextwithlineV2(lineCurrent, nextSubject->data, BLACK);
										lineCurrent -= 1;
									}
									lineCurrent = 8;
								}
							}
						}
						else if(ascii == ESC){
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201);
							bar(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);					
							setcolor(LIGHTGRAY);
							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							if(idSubject != emptyStr) outtextwithlineV2(0, findSubject(idSubject, lsj.root)->data, BLACK);
							nameSubject = emptyStr;
							setDefault();
							break;
						}
						if(ascii == BP && (int)nameSubject.size() > 0){
							nameSubject.pop_back();
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
							setcolor(BLACK);
							outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameSubject));
							
							lineCurrent = 1; firstSubject = NULL, cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdSubjectV2(lsj.root, firstSubject, cntline, nameSubject);
							
						}
						else if(('a' <= ascii && ascii <= 'z') || ('A' <= ascii && ascii <= 'Z') || ascii == SPACE){
							if((int)nameSubject.size() < 28){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
								nameSubject += key;
								setcolor(BLACK);
								outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameSubject));
							}
							
							lineCurrent = 1; firstSubject = NULL, cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdSubjectV2(lsj.root, firstSubject, cntline, nameSubject);
						}
					}
				}
			}
			else if(clickInRange(x, y, TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40)){ // nien khoa
				highlightInputExamScores(selected, BLUE);
				
				lineCurrent = 1; //
				yearCurrent = 0;
				
				createListYearV2();
				if(sizeYear != 0){ // danh sach rong
					highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
					findListYearV2(academicYear, sizeYear); // in ra danh sach 4 nam hoc dau tien
					
					while(true){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
//					    	
					    	if(ascii == ET){
					    		setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX2 - 50, TEXTLPOINTY2 - 40 + 1, TEXTLPOINTX2 - 100 + 1, TEXTLPOINTY2 - 40 + 121);
								bar(TEXTSPOINTX2 - 50 + 1, TEXTSPOINTY2 - 40 + 1, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40);
								academic = academicYear[yearCurrent];
								
								outtextwithline2V2(0, academicYear[yearCurrent], BLACK);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40);
								
								// neu da du thong tin thi cho phep nhap diem
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);
								drawPrintRegisteredStudentListV2(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
									inputScores(cfs, ls);
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
								break;
							}
							else if(ascii == UP){
								if(lineCurrent > 1){
									if(yearCurrent > 0){
										highlightLineCurrent2V2(lineCurrent, WHITE);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										yearCurrent -= 1;
										lineCurrent -= 1;
										
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
									}
								}
								else if(lineCurrent == 1){
									if(yearCurrent > 0){
										yearCurrent -= 1;
										
										createListYearV2();
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										lineCurrent += 1;
										
										int nextYear = yearCurrent;
										while(nextYear < sizeYear - 1 && lineCurrent <= 4){
											nextYear += 1;
											outtextwithline2V2(lineCurrent, academicYear[nextYear], BLACK);
											lineCurrent += 1;
										}
										lineCurrent = 1;
									}
								}
							}
							else if(ascii == DOWN){
								if(lineCurrent < 4 && lineCurrent != 0){
									if(yearCurrent < sizeYear - 1){ // ton tai phan tu sau no
										highlightLineCurrent2V2(lineCurrent, WHITE);
										setbkcolor(WHITE);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										yearCurrent += 1;
										lineCurrent += 1;
										
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
									}
								}
								else if(lineCurrent == 4){
									if(yearCurrent < sizeYear - 1){
										yearCurrent += 1;
										
										createListYearV2();
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										lineCurrent -= 1;
										
										int prevYear = yearCurrent;
										while(prevYear > 0 && lineCurrent >= 1){
											prevYear -= 1;
											outtextwithline2V2(lineCurrent, academicYear[prevYear], BLACK);
											lineCurrent -= 1;
										}
										lineCurrent = 4;
									}
								}
							}
							else if(ascii == ESC){
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX2 - 50, TEXTLPOINTY2 - 40 + 1, TEXTLPOINTX2 - 100 + 1, TEXTLPOINTY2 - 40 + 121); // xoa muc nhap
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40);
						
								break;
							}
						}
					}
				}
			}	
			else if(clickInRange(x, y, TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40)){ // hoc ky
				highlightInputExamScores(selected, BLACK);
				lineCurrent = 1; 

				createListSemesterV2();
				if(sizeSemester != 0){ // danh sach rong
					highlightLineCurrent4V2(lineCurrent, LIGHTGRAY);
					findListSemesterV2(semester, MAXSEMESTER); // in ra cac hoc ky;
					
					while(true){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 - 100, TEXTLPOINTY3 - 40 + 1, TEXTLPOINTX3 - 150 + 1, TEXTLPOINTY3 - 40 + 91);
								bar(TEXTSPOINTX3 - 100 + 1, TEXTSPOINTY3 - 40 + 1, TEXTLPOINTX4, TEXTLPOINTY3 - 40);
								semes = semester[lineCurrent - 1];
								
								outtextwithline4V2(0, semester[lineCurrent - 1], BLACK);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40);
								
								// neu da du thong tin thi cho phep nhap diem
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);
								drawPrintRegisteredStudentListV2(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
									inputScores(cfs, ls);
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
								
								break;
							}
							else if(ascii == UP){
								if(lineCurrent > 1){ // co the dich chuyen len
									highlightLineCurrent4V2(lineCurrent, WHITE);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
									
									lineCurrent -= 1;
									
									highlightLineCurrent4V2(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
								}
							}
							else if(ascii == DOWN){
								if(lineCurrent < 3 && lineCurrent != 0){
									highlightLineCurrent4V2(lineCurrent, WHITE);
									setbkcolor(WHITE);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
									
									lineCurrent += 1;
									
									highlightLineCurrent4V2(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
								}
							}
							else if(ascii == ESC){
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 - 100, TEXTLPOINTY3 - 40 + 1, TEXTLPOINTX3 - 150 + 1, TEXTLPOINTY3 - 40 + 91);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40);
								
								
								break;
							}
						}
					}
				}
			}
			else if(clickInRange(x, y, TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40)){ // nhom
				highlightInputExamScores(selected, BLUE);
				while(true){
					if(kbhit()){
						key = getch();
						ascii = static_cast<int>(key);
				        if (ascii == 0) { 
				            key = getch();
				            ascii = static_cast<int>(key);
				            ascii += 255;
				    	}
				    	
				    	if(ascii == ET){
							if(groupTemp.size() != 0){
								setcolor(LIGHTGRAY);
								rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
								group = stringtoint(groupTemp);
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);
								drawPrintRegisteredStudentListV2(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
									inputScores(cfs, ls);
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
								break;
							}
							else{
								setcolor(LIGHTGRAY);
								rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
								break;
							}
							
						}
						if(ascii == BP && (int)groupTemp.size() > 0){
							groupTemp.pop_back();
							
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTLPOINTX3 - 140 + 1, TEXTSPOINTY3 - 40 + 1, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
							setcolor(BLACK);
							setbkcolor(WHITE);
							outtextxy(TEXTLPOINTX3 - 140 + 5, TEXTSPOINTY3 - 40 + 10, tochar(groupTemp));
						}
						else if(('0' <= ascii && ascii <= '9')){
							if((int)groupTemp.size() < 2){
								if((int)groupTemp.size() == 0 && key == '0') continue;
								formatKey(key);
								groupTemp += key;
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTLPOINTX3 - 140 + 5, TEXTSPOINTY3 - 40 + 10, tochar(groupTemp));
							} 
						}
						else if(ascii == ESC){
							setcolor(LIGHTGRAY);
							rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
							groupTemp = emptyStr;
							group = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTLPOINTX3 - 140 + 1, TEXTSPOINTY3 - 40 + 1, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
							setDefault();
							break;
						}
					}
				}
			}
		}
	}
}

//-------------------------------------------------------------------------------------------------------------------------------
void drawTableIdClass(){
	setfillstyle(SOLID_FILL, WHITE);
	bar(LISTSPOINTX, LISTSPOINTY - 10, LISTLPOINTX, LISTLPOINTY - 5); // xoa toan bo noi dung trong muc nhap diem
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setbkcolor(WHITE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 40);
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, "Diem GPA 1 Lop");
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY); // tao header cho muc nhap diem
	
	rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40); // ten ma mon hoc
//	rectangle(TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40); // hoc ki 
//	rectangle(TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40); // nien khoa
//	rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40); // nhom
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(TEXTSPOINTX1 + 10, TEXTSPOINTY1 - 65, "Ten mon hoc - Ma");
//	outtextxy(TEXTSPOINTX2 - 40, TEXTSPOINTY2 - 65, "Nien khoa");
//	outtextxy(TEXTSPOINTX3 - 90, TEXTSPOINTY3 - 65, "Hoc ky");
//	outtextxy(TEXTLPOINTX3 - 130, TEXTSPOINTY3 - 65, "Nhom");

	setDefault();
} 

void drawPrintRegisteredStudentListV5(){ // ve bang in diem trung binh (gpa)
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 331); // xoa ta ca thong tin truoc do
	
	setcolor(LIGHTGRAY);
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 330); // tao khung to ben ngoai

	// tao header
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 
	
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	int X = TEXTSPOINTX1;
	outtextxy(X + 10, TEXTLPOINTY1 - 25, "STT");
	outtextxy(X + 60, TEXTLPOINTY1 - 25, "MSSV");
	outtextxy(X + 210, TEXTLPOINTY1 - 25, "HO");
	outtextxy(X + 460, TEXTLPOINTY1 - 25, "TEN");
	outtextxy(X + 610, TEXTLPOINTY1 - 25, "SO TC");
	outtextxy(X + 710, TEXTLPOINTY1 - 25, "DIEM TB");
	
	// tao duong ke ngnang
	int Y = TEXTLPOINTY1 + 30;
	setcolor(LIGHTGRAY);
	for(int i = 0; i < 11; i++){
		line(TEXTSPOINTX1, Y, TEXTLPOINTX3, Y);
		Y += 30;
	}
		
	// tao duong ke doc
	line(X + 50, TEXTLPOINTY1 - 30, X + 50, TEXTLPOINTY1 + 330);
	line(X + 200, TEXTLPOINTY1 - 30, X + 200, TEXTLPOINTY1 + 330);
	line(X + 450, TEXTLPOINTY1 - 30, X + 450, TEXTLPOINTY1 + 330);
	line(X + 600, TEXTLPOINTY1 - 30, X + 600, TEXTLPOINTY1 + 330);
	line(X + 700, TEXTLPOINTY1 - 30, X + 700, TEXTLPOINTY1 + 330);
		
	
	setDefault(); 

}

void highlightInputExamScoresV2(int selected, int COLOR){
	
	if(selected == 1){
		setcolor(COLOR);
		rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
	}
	else{
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
	}
	
	
	setDefault();
}

void outtextwithlineV3(int lineCurrent,string idClass, int COLOR){
	string text = idClass;
	setcolor(COLOR);
	switch(lineCurrent){
		case 0: // in trong box
			outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(text));
			break;
		case 1:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 - 35, tochar(text));
			break;
		case 2:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 - 5, tochar(text));
			break;
		case 3:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 25, tochar(text));
			break;
		case 4:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 55, tochar(text));
			break;
		case 5:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 85, tochar(text));
			break;
		case 6:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 115, tochar(text));
			break;
		case 7:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 145, tochar(text));
			break;
		case 8:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 175, tochar(text));
			break;
	}
	setDefault();
}

void findListIdClass(listClass lc,string &idClass,int lineCurrent, string nameClass){
	for(int i=0;i<lc.size;i++){
		if(lineCurrent <= 8 && isSubString(nameClass,lc.idClass[i])){
			if(lineCurrent==1){
				setbkcolor(LIGHTGRAY);
				idClass = lc.idClass[i];
			}
			else{
				setbkcolor(WHITE);
			}
			outtextwithlineV3(lineCurrent,lc.idClass[i],BLACK);
			lineCurrent++;
		}
	}
}

string findPrevClassV2(listClass lc,string nameClass){
	for(int i=1;i<lc.size;i++){
		if(isSubString(nameClass,lc.idClass[i])){
			return lc.idClass[i-1];
		}
	}
	return "";
}

string findNextClassV2(listClass lc, string nameClass){
	
	for(int i=0; i<lc.size-1 ;i++){
		if(isSubString(nameClass,lc.idClass[i])){
			return lc.idClass[i+1];
		}
	}
	return "";
}

void outputScores(ptrClassForSubject &cfs, listStudent &ls){
	int currentStudent = 0;
	int prevStudent = currentStudent;
	int order=0;
	displayStudentRegisteredStudentListV4(ls,cfs->lr,currentStudent,order);
	char key; int ascii, x, y;
	stack <int> st; // duoc su dung khi nhan phim up
	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	switch(ascii){
	    		case UP:
	    			if(order > 11 && st.empty() == false){ // stack co phan tu nghia la truoc do da an phim down
	    				currentStudent = st.top(); st.pop();
	    				prevStudent = currentStudent;
	    				if(order % 11 == 0) order -= 22;
	    				else order = order - (order % 11) - 11;
	    				drawPrintRegisteredStudentListV4(cfs); //ve lai khung 
	    				displayStudentRegisteredStudentListV4(ls,cfs->lr,currentStudent,order);
					}
	    			break;
	    		case DOWN:
	    			if(currentStudent < cfs->lr->size){
	    				st.push(prevStudent);
	    				prevStudent = currentStudent;
	    				drawPrintRegisteredStudentListV4(cfs); // ve lai khung
	    				displayStudentRegisteredStudentListV4(ls,cfs->lr,currentStudent,order);
					}
	    			break;
	    		case ESC:
	    			drawInputExamScoresV2();
	    			drawPrintRegisteredStudentListV4(cfs);
					return;
	    			break;
	    	}
		}
	}
}




void displayExamScores(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls){
	drawInputExamScoresV2();
	
	int ascii, x, y, selected = 0, on = 0, cntline = 1, lineCurrent = 1;
	ptrSubject firstSubject = NULL;
	ptrClassForSubject cfs = NULL;
	string nameSubject = emptyStr, idSubject = emptyStr, groupTemp = emptyStr;
	char key;
	
	int sizeYear = 0, sizeSemester = MAXSEMESTER, yearCurrent = 1, academic = 0, semes = 0, group = 0;
	int *academicYear = new int[MAXYEAR];
	readListYear(academicYear, sizeYear);
	
	int *semester = new int[MAXSEMESTER]; 
	for(int i = 0; i < MAXSEMESTER; i++){
		semester[i] = i + 1;
	} 
	
	drawPrintRegisteredStudentListV4(cfs);
	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	if(ascii == ESC) return;
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInRange(x, y, TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40)){ // ten ma mon hoc
				highlightInputExamScores(selected, BLUE);
				
				lineCurrent = 1; cntline = 1;
				firstSubject = NULL;
				
				createListIdSubjectV2(); // tao khung chua danh sach
				highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
				findListIdSubjectV2(lsj.root, firstSubject, cntline, nameSubject); // loc theo ten va in thong tin ra man hinh
				while(true){
					if(kbhit()){
						key = getch();
						ascii = static_cast<int>(key);
				        if (ascii == 0) { 
				            key = getch();
				            ascii = static_cast<int>(key);
				            ascii += 255;
				    	}
				    	if(ascii == ET){
							if(firstSubject != NULL){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
								idSubject = firstSubject->data.idSubject; // du lieu duoc chon luu vao idSubject;
								
								outtextwithlineV2(0, firstSubject->data, BLACK);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
								// neu da du thong tin thi cho phep nhap diem
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);
								drawPrintRegisteredStudentListV4(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
									inputScores(cfs, ls);
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
							}
							else{
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
								idSubject = emptyStr;	
							}
							
							nameSubject = emptyStr;
							lineCurrent = 1;
							setcolor(LIGHTGRAY);
							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							setDefault();
							break;
						}
						else if(ascii == UP && firstSubject != NULL){
							if(lineCurrent > 1){
								ptrSubject prevSubject = findPrevSubjectV2(lsj.root,firstSubject, nameSubject);
								if(prevSubject != NULL){
									firstSubject = prevSubject;
									
									lineCurrent -= 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, firstSubject->data, BLACK);
								}
							}
							else if(lineCurrent == 1){
								ptrSubject prevSubject = findPrevSubjectV2(lsj.root, firstSubject, nameSubject);
								if(prevSubject != NULL){
									firstSubject = prevSubject;
									
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, prevSubject->data, BLACK);
									
									lineCurrent += 1;
									
									while(findNextSubjectV2(lsj.root, prevSubject, nameSubject) != NULL && lineCurrent <= 8){
										prevSubject = findNextSubjectV2(lsj.root, prevSubject, nameSubject);
										outtextwithlineV2(lineCurrent, prevSubject->data, BLACK);
										lineCurrent += 1;
									}
									lineCurrent = 1;
								}
							}
						}	
						else if(ascii == DOWN && firstSubject != NULL){
							if(lineCurrent < 8 && lineCurrent != 0){
								ptrSubject nextSubject = findNextSubjectV2(lsj.root, firstSubject, nameSubject);
								
								if(nextSubject != NULL){
									highlightInputLineCurrent(lineCurrent, WHITE);
									outtextwithlineV2(lineCurrent, firstSubject->data, BLACK);
									
									firstSubject = nextSubject;
									lineCurrent += 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, firstSubject->data, BLACK);
								}
							}
							else if(lineCurrent == 8){
								ptrSubject nextSubject = findNextSubjectV2(lsj.root, firstSubject, nameSubject);
								if(nextSubject != NULL){
									firstSubject = nextSubject;
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV2(lineCurrent, nextSubject->data, BLACK);
									lineCurrent -= 1;
									
									while(findPrevSubjectV2(lsj.root, nextSubject, nameSubject) != NULL && lineCurrent >= 1){
										nextSubject = findPrevSubjectV2(lsj.root, nextSubject, nameSubject);
										outtextwithlineV2(lineCurrent, nextSubject->data, BLACK);
										lineCurrent -= 1;
									}
									lineCurrent = 8;
								}
							}
						}
						else if(ascii == ESC){
							
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201);
							bar(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);					
							setcolor(LIGHTGRAY);
							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							if(idSubject != emptyStr) outtextwithlineV2(0, findSubject(idSubject, lsj.root)->data, BLACK);
							nameSubject = emptyStr;
							drawPrintRegisteredStudentListV4(cfs);
							setDefault();
							break;
						}
						if(ascii == BP && (int)nameSubject.size() > 0){
							nameSubject.pop_back();
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
							setcolor(BLACK);
							outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameSubject));
							
							lineCurrent = 1; firstSubject = NULL, cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdSubjectV2(lsj.root, firstSubject, cntline, nameSubject);
							
						}
						else if(('a' <= ascii && ascii <= 'z') || ('A' <= ascii && ascii <= 'Z') || ascii == SPACE){
							if((int)nameSubject.size() < 28){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
								nameSubject += key;
								setcolor(BLACK);
								outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameSubject));
							}
							
							lineCurrent = 1; firstSubject = NULL, cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdSubjectV2(lsj.root, firstSubject, cntline, nameSubject);
						}
					}
				}
			}
			
			else if(clickInRange(x, y, TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40)){ // nien khoa
				highlightInputExamScores(selected, BLUE);
				
				lineCurrent = 1; //
				yearCurrent = 0;
				
				createListYearV2();
				if(sizeYear != 0){ // danh sach rong
					highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
					findListYearV2(academicYear, sizeYear); // in ra danh sach 4 nam hoc dau tien
					
					while(true){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
//					    	
					    	if(ascii == ET){
					    		setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX2 - 50, TEXTLPOINTY2 - 40 + 1, TEXTLPOINTX2 - 100 + 1, TEXTLPOINTY2 - 40 + 121);
								bar(TEXTSPOINTX2 - 50 + 1, TEXTSPOINTY2 - 40 + 1, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40);
								academic = academicYear[yearCurrent];
								
								outtextwithline2V2(0, academicYear[yearCurrent], BLACK);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40);
								
								// neu da du thong tin thi cho phep nhap diem
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);
								drawPrintRegisteredStudentListV4(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
									inputScores(cfs, ls);
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
								break;
							}
							else if(ascii == UP){
								if(lineCurrent > 1){
									if(yearCurrent > 0){
										highlightLineCurrent2V2(lineCurrent, WHITE);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										yearCurrent -= 1;
										lineCurrent -= 1;
										
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
									}
								}
								else if(lineCurrent == 1){
									if(yearCurrent > 0){
										yearCurrent -= 1;
										
										createListYearV2();
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										lineCurrent += 1;
										
										int nextYear = yearCurrent;
										while(nextYear < sizeYear - 1 && lineCurrent <= 4){
											nextYear += 1;
											outtextwithline2V2(lineCurrent, academicYear[nextYear], BLACK);
											lineCurrent += 1;
										}
										lineCurrent = 1;
									}
								}
							}
							else if(ascii == DOWN){
								if(lineCurrent < 4 && lineCurrent != 0){
									if(yearCurrent < sizeYear - 1){ // ton tai phan tu sau no
										highlightLineCurrent2V2(lineCurrent, WHITE);
										setbkcolor(WHITE);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										yearCurrent += 1;
										lineCurrent += 1;
										
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
									}
								}
								else if(lineCurrent == 4){
									if(yearCurrent < sizeYear - 1){
										yearCurrent += 1;
										
										createListYearV2();
										highlightLineCurrent2V2(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline2V2(lineCurrent, academicYear[yearCurrent], BLACK);
										
										lineCurrent -= 1;
										
										int prevYear = yearCurrent;
										while(prevYear > 0 && lineCurrent >= 1){
											prevYear -= 1;
											outtextwithline2V2(lineCurrent, academicYear[prevYear], BLACK);
											lineCurrent -= 1;
										}
										lineCurrent = 4;
									}
								}
							}
							else if(ascii == ESC){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX2 - 50, TEXTLPOINTY2 - 40 + 1, TEXTLPOINTX2 - 100 + 1, TEXTLPOINTY2 - 40 + 121); // xoa muc nhap
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX2 - 50, TEXTSPOINTY2 - 40, TEXTLPOINTX2 - 100, TEXTLPOINTY2 - 40);
								drawPrintRegisteredStudentListV4(cfs);
								break;
							}
						}
					}
				}
			}	
			else if(clickInRange(x, y, TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40)){ // hoc ky
				highlightInputExamScores(selected, BLACK);
				lineCurrent = 1; 

				createListSemesterV2();
				if(sizeSemester != 0){ // danh sach rong
					highlightLineCurrent4V2(lineCurrent, LIGHTGRAY);
					findListSemesterV2(semester, MAXSEMESTER); // in ra cac hoc ky;
					
					while(true){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 - 100, TEXTLPOINTY3 - 40 + 1, TEXTLPOINTX3 - 150 + 1, TEXTLPOINTY3 - 40 + 91);
								bar(TEXTSPOINTX3 - 100 + 1, TEXTSPOINTY3 - 40 + 1, TEXTLPOINTX4, TEXTLPOINTY3 - 40);
								semes = semester[lineCurrent - 1];
								
								outtextwithline4V2(0, semester[lineCurrent - 1], BLACK);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40);
								
								// neu da du thong tin thi cho phep nhap diem
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);
								drawPrintRegisteredStudentListV4(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
									inputScores(cfs, ls);
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
								
								break;
							}
							else if(ascii == UP){
								if(lineCurrent > 1){ // co the dich chuyen len
									highlightLineCurrent4V2(lineCurrent, WHITE);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
									
									lineCurrent -= 1;
									
									highlightLineCurrent4V2(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
								}
							}
							else if(ascii == DOWN){
								if(lineCurrent < 3 && lineCurrent != 0){
									highlightLineCurrent4V2(lineCurrent, WHITE);
									setbkcolor(WHITE);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
									
									lineCurrent += 1;
									
									highlightLineCurrent4V2(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithline4V2(lineCurrent, semester[lineCurrent - 1], BLACK);
								}
							}
							else if(ascii == ESC){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 - 100, TEXTLPOINTY3 - 40 + 1, TEXTLPOINTX3 - 150 + 1, TEXTLPOINTY3 - 40 + 91);
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX3 - 100, TEXTSPOINTY3 - 40, TEXTLPOINTX3 - 150, TEXTLPOINTY3 - 40);
								drawPrintRegisteredStudentListV4(cfs);
								break;
							}
						}
					}
				}
			}
			else if(clickInRange(x, y, TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40)){ // nhom
				highlightInputExamScores(selected, BLUE);
				while(true){
					if(kbhit()){
						key = getch();
						ascii = static_cast<int>(key);
				        if (ascii == 0) { 
				            key = getch();
				            ascii = static_cast<int>(key);
				            ascii += 255;
				    	}
				    	
				    	if(ascii == ET){
							if(groupTemp.size() != 0){
								setcolor(LIGHTGRAY);
								rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
								group = stringtoint(groupTemp);
								cfs = findClassForSubject(lcfs, idSubject, academic, semes, group);// loc ra 
								drawPrintRegisteredStudentListV4(cfs); // ve khung
								if(cfs != NULL){ // co thong tin thi in danh sach va bat dau nhap diem
								
									outputScores(cfs, ls);
									
									idSubject = groupTemp = emptyStr;
									academic = semes = 0;
									group = 0;
								} 
								break;
							}
							else{
								setcolor(LIGHTGRAY);
								rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
								break;
							}
							
						}
						if(ascii == BP && (int)groupTemp.size() > 0){
							groupTemp.pop_back();
							
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTLPOINTX3 - 140 + 1, TEXTSPOINTY3 - 40 + 1, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
							setcolor(BLACK);
							setbkcolor(WHITE);
							outtextxy(TEXTLPOINTX3 - 140 + 5, TEXTSPOINTY3 - 40 + 10, tochar(groupTemp));
						}
						else if(('0' <= ascii && ascii <= '9')){
							if((int)groupTemp.size() < 2){
								if((int)groupTemp.size() == 0 && key == '0') continue;
								formatKey(key);
								groupTemp += key;
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTLPOINTX3 - 140 + 5, TEXTSPOINTY3 - 40 + 10, tochar(groupTemp));
							} 
						}
						else if(ascii == ESC){
							drawPrintRegisteredStudentListV4(cfs);
							setcolor(LIGHTGRAY);
							rectangle(TEXTLPOINTX3 - 140 , TEXTSPOINTY3 - 40, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
							groupTemp = emptyStr;
							group = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTLPOINTX3 - 140 + 1, TEXTSPOINTY3 - 40 + 1, TEXTLPOINTX3, TEXTLPOINTY3 - 40);
							setDefault();
							break;
						}
					}
				}
			}
		}
	}
}


//----------------------------------------------------------------
int checkNumberTC(listSubject &lsj, string idSubject){
	ptrSubject find = findSubject(idSubject,lsj.root);
	if(find == NULL) return 0; 
	return find->data.STCLT + find->data.STCTH; 
}

float checkScore(ptrClassForSubject cs){
	if(cs->lr->head->data.scores >=0 && cs->lr->head->data.scores <=10){
		return cs->lr->head->data.scores;
	}
	return 0;
}




void searchNumberTC(listSubject &lsj,listClassForSubject &lcfs,listStudent &ls,listStudent &keep,string idClass, int &order,int currentClass,int listSTC[],float listCPA[]){
	
	ptrStudent p=ls.head;

	ptrRegister r=NULL;
	ptrListRegister tmpLr=NULL; 
	
	while(p != NULL && p->value.idClass <= idClass){
		if(p->value.idClass == idClass){
			addStudent(keep,p->value);	
		} 
		p=p->next; 
	} 
	keep.size = getSizeClass(keep,idClass); 

	ptrStudent tmp = keep.head;
	int STC;
	float CPA;

	int num=0; 
	while(tmp != NULL && num < keep.size){
		STC=0;
		CPA=0;
		for(int i=0; i<lcfs.size ;i++){
			r=lcfs.list[i]->lr->head;
			while( r!= NULL && r->data.idStudent != tmp->value.id){
				r=r->next;
			}
			if(r!=NULL){
				if(r->data.scores >= 0 && r->data.scores <=10){
					STC+=checkNumberTC(lsj,lcfs.list[i]->idSubject);
					CPA+=(r->data.scores)*checkNumberTC(lsj,lcfs.list[i]->idSubject);
				}

			}
		}
		if(CPA != 0 && STC != 0){
			listCPA[num]=CPA/STC;
			listSTC[num]=STC;
			++num;
		} 
		else{ 
			listCPA[num]=0;
			listSTC[num]=0;
			++num;
		} 
		
		tmp=tmp->next;
	}

	
}


void displayStudentHaveScore(listStudent &ls,listStudent keep,int currentClass,int &order,int STC[],float CPA[]){
	// bat dau in thong tin
    ptrStudent currentST = keep.head;
     int num=0; 
    for(int i = 0; i < currentClass && currentST != NULL; i++){
        currentST = currentST->next; // dua con tro den vi tri currentStudent
        num++;
    }
   
    if(currentST == NULL){
    	return;
	}
    
    setbkcolor(WHITE);
    setcolor(BLACK);
    ptrStudent student = NULL;
    int i =  currentClass;
    int cnt = 0, X = TEXTSPOINTX1, Y = TEXTLPOINTY1 + 5;
    while(currentST != NULL  && cnt < 11 && i < keep.size && num < keep.size){
    	
   		student = findPtrStudent(ls, currentST->value.id); // tra ve thong tin sinh vien thong qua con tro ds dang ki cua lop da tim dc 
        
	        if(student != NULL){
				order += 1;
	        	outtextxy(X + 10, Y, tochar(to_string(order)));
				outtextxy(X + 60, Y, tochar(currentST->value.id));
				outtextxy(X + 220, Y, tochar(currentST->value.firstName));
				outtextxy(X + 470, Y, tochar(currentST->value.lastName));
				outtextxy(X + 620, Y, tochar((to_string(STC[num]))));
				string outCPA;
				if(CPA[num] != 0){
					string tmpCPA = to_string(CPA[num]);
					for(int i=0;i<4;i++){
						outCPA+=tmpCPA[i];
					}
					outtextxy(X + 720,Y, tochar(outCPA));
				}
				else  outtextxy(X + 720,Y, tochar((to_string(CPA[num]))));
				
				

				
				Y += 30; cnt += 1;
				++num; 
			}
		currentClass += 1;
		currentST=currentST->next;
	}
}




// void displayClassEverageScores(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls,listClass &lc){
// 	drawTableIdClass();
	
// 	int ascii, x, y, selected = 0, on = 0, cntline = 1, lineCurrent = 1; 
// 	int currentClass = 0; 
	
// 	string idClass = emptyStr;
// 	string nameClass = emptyStr;
// 	char key;

// 	int order=0;
	 
// 		listStudent keepMain;
// 		keepMain.size = getSizeClass(keepMain,idClass);
// 		float listCPA[1000]; 
// 		int listSTC[1000];
		
	
// 	drawPrintRegisteredStudentListV5();
// 	while(true){
// 		if(kbhit()){
// 			key = getch();
// 			ascii = static_cast<int>(key);
// 	        if (ascii == 0) { 
// 	            key = getch();
// 	            ascii = static_cast<int>(key);
// 	            ascii += 255;
// 	    	}
// 			switch(ascii){
// 				case DOWN:
// 	    			if(currentClass + 11 < keepMain.size){
// 	    				currentClass += 11;
// 	    				drawPrintRegisteredStudentListV5();
// 	    				displayStudentHaveScore(ls,keepMain,currentClass,order,listSTC,listCPA);
// 					}
// 					break;
// 				case UP:// sai cai in so thu tu
// 					if(currentClass - 11 >= 0 && currentClass < keepMain.size){
// 	    				currentClass -= 11;
// 	    				if(order % 11 == 0) order -= 22;
// 	    				else order = order - (order % 11) - 11;
// 	    				drawPrintRegisteredStudentListV5();
// 	    				displayStudentHaveScore(ls,keepMain,currentClass,order,listSTC,listCPA);
// 					}
// 			}
			
// 	    	if(ascii == ESC) return;
// 		}
// 		if(ismouseclick(WM_LBUTTONDOWN)){
// 			getmouseclick(WM_LBUTTONDOWN, x, y);
// 			clearmouseclick(WM_LBUTTONDOWN);
// 			if(clickInRange(x, y, TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40)){ // ten lop
// 				highlightInputExamScoresV2(selected, BLUE);
				
// 				setfillstyle(SOLID_FILL, WHITE);
// 				bar(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
// 				setcolor(BLACK);
// 				rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
				
// 				lineCurrent = 1;
// 				cntline = 1;
// 				idClass=""; 
				
// 				createListIdSubjectV2(); // tao khung chua danh sach
// 				highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
// 				findListIdClass(lc,idClass,cntline,nameClass); // loc theo ma lop va in thong tin ra man hinh
// 				while(true){
// 					if(kbhit()){
// 						key = getch();
// 						ascii = static_cast<int>(key);
// 				        if (ascii == 0) { 
// 				            key = getch();
// 				            ascii = static_cast<int>(key);
// 				            ascii += 255;
// 				    	}
				    	
// 				    	if(ascii == ET && idClass !=""){
// 					    		if(idClass != ""){
// 					    			setfillstyle(SOLID_FILL, WHITE);
// 									bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
// 									bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
// 									nameClass = idClass; // du lieu duoc chon luu vao nameClass;
									
// 									outtextwithlineV3(0, nameClass, BLACK);
									
// 									setcolor(LIGHTGRAY);
// 									rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
									
									
// 									drawPrintRegisteredStudentListV5();
// 									// show
// 									searchNumberTC(lsj,lcfs,ls,keepMain,idClass,order,currentClass,listSTC,listCPA);// loc sinh vien trong lop,stc,cpa
// 									keepMain.size = getSizeClass(keepMain,idClass); 
// 									displayStudentHaveScore(ls,keepMain,currentClass,order,listSTC,listCPA);
									
// 								}
// 								else{
// 									setfillstyle(SOLID_FILL, WHITE);
// 									bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
// 									bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
// 									nameClass = emptyStr;	
// 								}
					    		
// 					    		nameClass = emptyStr;
// 					    		lineCurrent = 1;
// 					    		setcolor(LIGHTGRAY);
// 								rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
// 								setDefault();
// 								break;
// 							}
// 						else if(ascii == UP && idClass != ""){
// 							if(lineCurrent > 1){
								
// 								string prevClass = findPrevClassV2(lc,idClass);
// 								if(prevClass != ""){
// 									highlightInputLineCurrent(lineCurrent, WHITE);
// 									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
// 									idClass = prevClass;
									
// 									lineCurrent -= 1;
// 									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
// 									setbkcolor(LIGHTGRAY);
// 									outtextwithlineV3(lineCurrent, idClass, BLACK);
// 								}
// 							}
// 							else if(lineCurrent == 1){
// 								string prevClass = findPrevClassV2(lc,idClass);
// 								if(prevClass != ""){
// 									idClass = prevClass;
									
// 									createListIdSubjectV2();
// 									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
// 									setbkcolor(LIGHTGRAY);
// 									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
// 									lineCurrent += 1;
									
// 									while(findNextClassV2(lc,prevClass) != "" && lineCurrent <= 8){
// 										prevClass = findNextClassV2(lc, prevClass);
// 										outtextwithlineV3(lineCurrent, prevClass, BLACK);
// 										lineCurrent += 1;
// 									}
// 									lineCurrent = 1;
// 								}
// 							}
// 						}	
// 						else if(ascii == DOWN && idClass != ""){
// //							cout<<2<<endl;
// 							if(lineCurrent < 8 && lineCurrent != 0){
// 								string nextClass = findNextClassV2(lc, idClass);
// //								cout<<"id can tim la: "<<idClass<<" "<<"id tim dc ke tiep: "<<nextClass<<endl;
// 								if(nextClass != ""){
// //									cout<<1<<endl;
									
// 									highlightInputLineCurrent(lineCurrent, WHITE);
// 									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
// 									idClass = nextClass;
// 									lineCurrent += 1;
// 									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
// 									setbkcolor(LIGHTGRAY);
// 									outtextwithlineV3(lineCurrent, idClass, BLACK);
// 								}
// 							}
// 							else if(lineCurrent == 8){
// 								string nextClass = findNextClassV2(lc, idClass);// tim tk ke tiep 
// 								if(nextClass != ""){
// 									idClass = nextClass;// hien tai = ke tiep 
// 									createListIdSubjectV2();
// 									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
// 									setbkcolor(LIGHTGRAY);
// 									outtextwithlineV3(lineCurrent,nextClass, BLACK); //hien ra ke tiep 
// 									lineCurrent -= 1;
									
// 									while(findPrevClassV2(lc,nextClass) != "" && lineCurrent >= 1){
// 										nextClass = findPrevClassV2(lc,nextClass);
// 										outtextwithlineV3(lineCurrent, nextClass, BLACK);
// 										lineCurrent -= 1;
// 									}
// 									lineCurrent = 8;
// 								}
// 							}
// 						}
// 						else if(ascii == ESC){
// 							setfillstyle(SOLID_FILL, WHITE);
// 							bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201);
// 							bar(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);					
// 							setcolor(LIGHTGRAY);
// 							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							
// 							nameClass = emptyStr; idClass="";
// 							drawPrintRegisteredStudentListV5();
// 							setDefault();
// 							break;
// 						}
						
// 						if(ascii == BP && (int)nameClass.size() > 0){ 
// 							nameClass.pop_back();
// 							setfillstyle(SOLID_FILL, WHITE);
// 							bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
// 							setcolor(BLACK);
// 							outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameClass));
							
// 							lineCurrent = 1; cntline = 1;
// 							createListIdSubjectV2(); // tao khung chua danh sach
// 							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
// 							findListIdClass(lc,idClass,lineCurrent,nameClass);
							
// 						}
						
// 						else if(('a' <= ascii && ascii <= 'z') || ('A' <= ascii && ascii <= 'Z') || ('0' <= ascii && ascii <= '9')  || ascii == SPACE){  
// 							if((int)nameClass.size() < 9){
// 								setfillstyle(SOLID_FILL, WHITE);
// 								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
// 								formatKey(key);
// 								nameClass += key;
// 								setcolor(BLACK);
// 								outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameClass));
// 							}
							
// 							lineCurrent = 1; idClass = "", cntline = 1;
// 							createListIdSubjectV2(); // tao khung chua danh sach
// 							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
// 							findListIdClass(lc,idClass,lineCurrent,nameClass);
// 						}
// 					}
// 				}
// 			}
// 		}
// 	}
// }


void displayClassEverageScores(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls,listClass &lc){
	drawTableIdClass();
	
	int ascii, x, y, selected = 0, on = 0, cntline = 1, lineCurrent = 1; 
	int currentClass = 0; 
	
	string idClass = emptyStr;
	string nameClass = emptyStr;
	char key;

	int order=0;
	 
		listStudent keepMain;
		keepMain.size = getSizeClass(keepMain,idClass);
		float listCPA[1000]; 
		int listSTC[1000];
		
	
	drawPrintRegisteredStudentListV5();
	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
			switch(ascii){
				case DOWN:
	    			if(currentClass + 11 < keepMain.size){
	    				currentClass += 11;
	    				drawPrintRegisteredStudentListV5();
	    				displayStudentHaveScore(ls,keepMain,currentClass,order,listSTC,listCPA);
					}
					break;
				case UP:// sai cai in so thu tu
					if(currentClass - 11 >= 0 && currentClass < keepMain.size){
	    				currentClass -= 11;
	    				if(order % 11 == 0) order -= 22;
	    				else order = order - (order % 11) - 11;
	    				drawPrintRegisteredStudentListV5();
	    				displayStudentHaveScore(ls,keepMain,currentClass,order,listSTC,listCPA);
					}
			}
			
	    	if(ascii == ESC) return;
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInRange(x, y, TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40)){ // ten lop
				highlightInputExamScoresV2(selected, BLUE);
				
				setfillstyle(SOLID_FILL, WHITE);
				bar(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
				setcolor(BLACK);
				rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
				
				lineCurrent = 1;
				cntline = 1;
				idClass=""; 
				
				createListIdSubjectV2(); // tao khung chua danh sach
				highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
				findListIdClass(lc,idClass,cntline,nameClass); // loc theo ma lop va in thong tin ra man hinh
				while(true){
					if(kbhit()){
						key = getch();
						ascii = static_cast<int>(key);
				        if (ascii == 0) { 
				            key = getch();
				            ascii = static_cast<int>(key);
				            ascii += 255;
				    	}
				    	
				    	if(ascii == ET && idClass !=""){
					    		if(idClass != ""){
					    			setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
									bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
									nameClass = idClass; // du lieu duoc chon luu vao nameClass;
									
									outtextwithlineV3(0, nameClass, BLACK);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
									
									
									drawPrintRegisteredStudentListV5();
									// show
									searchNumberTC(lsj,lcfs,ls,keepMain,idClass,order,currentClass,listSTC,listCPA);// loc sinh vien trong lop,stc,cpa
									keepMain.size = getSizeClass(keepMain,idClass); 
									displayStudentHaveScore(ls,keepMain,currentClass,order,listSTC,listCPA);
									
								}
								else{
									setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
									bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
									nameClass = emptyStr;	
								}
					    		
					    		nameClass = emptyStr;
					    		lineCurrent = 1;
					    		setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
								setDefault();
								break;
							}
						else if(ascii == UP && idClass != ""){
							if(lineCurrent > 1){
								
								string prevClass = findPrevClassV2(lc,idClass);
								if(prevClass != ""){
									highlightInputLineCurrent(lineCurrent, WHITE);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
									idClass = prevClass;
									
									lineCurrent -= 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
								}
							}
							else if(lineCurrent == 1){
								string prevClass = findPrevClassV2(lc,idClass);
								if(prevClass != ""){
									idClass = prevClass;
									
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
									lineCurrent += 1;
									
									while(findNextClassV2(lc,prevClass) != "" && lineCurrent <= 8){
										prevClass = findNextClassV2(lc, prevClass);
										outtextwithlineV3(lineCurrent, prevClass, BLACK);
										lineCurrent += 1;
									}
									lineCurrent = 1;
								}
							}
						}	
						else if(ascii == DOWN && idClass != ""){
//							cout<<2<<endl;
							if(lineCurrent < 8 && lineCurrent != 0){
								string nextClass = findNextClassV2(lc, idClass);
//								cout<<"id can tim la: "<<idClass<<" "<<"id tim dc ke tiep: "<<nextClass<<endl;
								if(nextClass != ""){
//									cout<<1<<endl;
									
									highlightInputLineCurrent(lineCurrent, WHITE);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
									idClass = nextClass;
									lineCurrent += 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
								}
							}
							else if(lineCurrent == 8){
								string nextClass = findNextClassV2(lc, idClass);// tim tk ke tiep 
								if(nextClass != ""){
									idClass = nextClass;// hien tai = ke tiep 
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent,nextClass, BLACK); //hien ra ke tiep 
									lineCurrent -= 1;
									
									while(findPrevClassV2(lc,nextClass) != "" && lineCurrent >= 1){
										nextClass = findPrevClassV2(lc,nextClass);
										outtextwithlineV3(lineCurrent, nextClass, BLACK);
										lineCurrent -= 1;
									}
									lineCurrent = 8;
								}
							}
						}
						else if(ascii == ESC){
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201);
							bar(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);					
							setcolor(LIGHTGRAY);
							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							
							nameClass = emptyStr; idClass="";
							drawPrintRegisteredStudentListV5();
							setDefault();
							break;
						}
						
						if(ascii == BP && (int)nameClass.size() > 0){ 
							nameClass.pop_back();
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
							setcolor(BLACK);
							outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameClass));
							
							lineCurrent = 1; cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdClass(lc,idClass,lineCurrent,nameClass);
							
						}
						
						else if(('a' <= ascii && ascii <= 'z') || ('A' <= ascii && ascii <= 'Z') || ('0' <= ascii && ascii <= '9')  || ascii == SPACE){  
							if((int)nameClass.size() < 9){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
								formatKey(key);
								nameClass += key;
								setcolor(BLACK);
								outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameClass));
							}
							
							lineCurrent = 1; idClass = "", cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdClass(lc,idClass,lineCurrent,nameClass);
						}
					}
				}
			}
		}
	}
}



/*Hien thi bang diem tong hop cua lop sinh vien: 
	- Moi sinh vien se c diem cua nhung mon cua lop tin chi da dang ki truoc do.
	-
*/
// #define hang 22
#define D_COT_SCORE 80



void drawTableControlClassScores(){
	//Tieu de bang tong ket cac mon hoc cua lop sinh vien
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_CLASS_SX, TABLE_CLASS_SY, TABLE_CLASS_LX, TABLE_CLASS_LY);
	outtextxy(TABLE_CLASS_SX + 200, TABLE_CLASS_SY + 10, "BANG DIEM TONG KET");
	outtextxy(TABLE_CLASS_SX + 200, TABLE_CLASS_SY + 10 + 20, "Lop:  Chua chon lop ...");

	setfillstyle(SOLID_FILL, WHITE);
	bar(LISTSPOINTX, LISTSPOINTY - 10, LISTLPOINTX, LISTLPOINTY - 5); // xoa toan bo noi dung trong muc nhap diem
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 40);

	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, "DANH SACH DIEM CUA LOP SINH VIEN");

	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY); // tao header cho muc nhap diem
	
	rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40); // ten ma mon hoc
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(TEXTSPOINTX1 + 10, TEXTSPOINTY1 - 65, "Ten lop sinh vien - ID");

	setDefault();
}

//Ve bang du lieu rong khi chua chon lop sinh vien
void drawTableDataClassScoresEmpty(){
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);

	//Tieu de bang tong ket cac mon hoc cua lop sinh vien
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLE_CLASS_SX, TABLE_CLASS_SY, TABLE_CLASS_LX, TABLE_CLASS_LY);

	setcolor(BLACK);
	setbkcolor(WHITE);
	outtextxy(TABLE_CLASS_SX + 200, TABLE_CLASS_SY + 10, "BANG DIEM TONG KET");
	outtextxy(TABLE_CLASS_SX + 220, TABLE_CLASS_SY + 10 + 20, "Lop: ...  ");

	//-----------------
	setfillstyle(SOLID_FILL, WHITE);
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 331);//KHUNG CHI CHUA DATA

	setfillstyle(SOLID_FILL, LIGHTBLUE);// tao header
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 
	setcolor(BLUE);
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 

	setcolor(LIGHTGRAY);
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 330);// KHUNG

	setcolor(LIGHTMAGENTA);
	outtextxy(TEXTSPOINTX1 + 200, TEXTLPOINTY1 + 30, "VUI LONG CHON LOP SINH VIEN DE HIEN THI DIEM ...");

	setcolor(LIGHTGRAY);// NGAN CACH TIEU DE
	line(TEXTSPOINTX1, TEXTLPOINTY1 - 30													, TEXTSPOINTX1														, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40, TEXTLPOINTY1 - 30												, TEXTSPOINTX1 + 40 												, TEXTLPOINTY1 ); 
	line(TEXTSPOINTX1 + 40 + 120, TEXTLPOINTY1 - 30											, TEXTSPOINTX1 + 40 + 120											, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40 + 120 + 200, TEXTLPOINTY1 - 30									, TEXTSPOINTX1 + 40 + 120 + 200										, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80, TEXTLPOINTY1 - 30								, TEXTSPOINTX1 + 40 + 120 + 200 + 80								, TEXTLPOINTY1 );
	
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80, TEXTLPOINTY1 - 30							, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80							, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80, TEXTLPOINTY1 - 30					, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80						, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30				, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80					, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30			, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80			, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30		, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80		, TEXTLPOINTY1 );
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80 + 80	, TEXTLPOINTY1 );



	setbkcolor(LIGHTBLUE);
	setcolor(BLACK);
	// settextstyle(SMALL_FONT, HORIZ_DIR, 5);	
	outtextxy(TEXTSPOINTX1 + 3      												, TEXTLPOINTY1 - 22, "STT" );
	outtextxy(TEXTSPOINTX1 + 3 + 40 												, TEXTLPOINTY1 - 22, "Ma SV" );
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120											, TEXTLPOINTY1 - 22, "Ho lot");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200										, TEXTLPOINTY1 - 22, "Ten");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80								, TEXTLPOINTY1 - 22, "Mon 1" );
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80							, TEXTLPOINTY1 - 22, "Mon 2");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80						, TEXTLPOINTY1 - 22, "Mon 3");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80					, TEXTLPOINTY1 - 22, "Mon 4");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80			, TEXTLPOINTY1 - 22, "Mon 5");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80		, TEXTLPOINTY1 - 22, "Mon 6");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80 + 80	, TEXTLPOINTY1 - 22, "Mon 7");
	
	// setbkcolor(WHITE);
	// setcolor(BLACK);
	// outtextxy(TEXTSPOINTX1 + 3      												, TEXTLPOINTY1 - 21 + 22, "001" );
	// outtextxy(TEXTSPOINTX1 + 3 + 40 												, TEXTLPOINTY1 - 21 + 22, "N22DCCN193");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120											, TEXTLPOINTY1 - 21 + 22, "NGUYEN THI TU");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200										, TEXTLPOINTY1 - 21 + 22, "QUYNH");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80								, TEXTLPOINTY1 - 21 + 22, "BAS1122");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80							, TEXTLPOINTY1 - 21 + 22, "BAS1122");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80						, TEXTLPOINTY1 - 21 + 22, "BAS1122");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80					, TEXTLPOINTY1 - 21 + 22, "BAS1122");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80			, TEXTLPOINTY1 - 21 + 22, "BAS1122");
	// outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80		, TEXTLPOINTY1 - 21 + 22, "BAS1122");


	
	setDefault(); 
}

// Bang du lieu de chua danh sach diem sinh vien cua lop sinh vien
void drawTableDataClassScores(){ 
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);

	setfillstyle(SOLID_FILL, WHITE);
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 330); // xoa ta ca thong tin truoc do
	
	setcolor(LIGHTGRAY);
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1 + 330); // tao khung to ben ngoai

	setfillstyle(SOLID_FILL, LIGHTBLUE);// tao header
	bar(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 
	rectangle(TEXTSPOINTX1, TEXTLPOINTY1 - 30, TEXTLPOINTX3, TEXTLPOINTY1); 
	
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	outtextxy(TEXTSPOINTX1 + 3      												, TEXTLPOINTY1 - 22, "STT" );
	outtextxy(TEXTSPOINTX1 + 3 + 40 												, TEXTLPOINTY1 - 22, "MSSV" );
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120											, TEXTLPOINTY1 - 22, "Ho lot");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200										, TEXTLPOINTY1 - 22, "Ten");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80								, TEXTLPOINTY1 - 22, "Mon 1" );
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80							, TEXTLPOINTY1 - 22, "Mon 2");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80						, TEXTLPOINTY1 - 22, "Mon 3");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80					, TEXTLPOINTY1 - 22, "Mon 4");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80			, TEXTLPOINTY1 - 22, "Mon 5");
	outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80		, TEXTLPOINTY1 - 22, "Mon 6");
	

	setbkcolor(WHITE);
	setcolor(LIGHTGRAY);
	line(TEXTSPOINTX1, TEXTLPOINTY1 - 30													, TEXTSPOINTX1														, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40, TEXTLPOINTY1 - 30												, TEXTSPOINTX1 + 40 												, TEXTLPOINTY1 + 330); 
	line(TEXTSPOINTX1 + 40 + 120, TEXTLPOINTY1 - 30											, TEXTSPOINTX1 + 40 + 120											, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200, TEXTLPOINTY1 - 30									, TEXTSPOINTX1 + 40 + 120 + 200										, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80, TEXTLPOINTY1 - 30								, TEXTSPOINTX1 + 40 + 120 + 200 + 80								, TEXTLPOINTY1 + 330);
	
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80, TEXTLPOINTY1 - 30							, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80							, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80, TEXTLPOINTY1 - 30					, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80						, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30				, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80					, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30			, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80			, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30		, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80		, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80 + 80	, TEXTLPOINTY1 + 330);

	setDefault(); 
}

// chuyen double sang string voi 2 chu so thap phan
std::string doubleToString(double value) {
    std::ostringstream stream;
    stream << std::fixed << std::setprecision(2) << value;
    return stream.str();
}

// kiem tra xenm sinh vien dang duyet co nam trong danh sach mon dang duyet khong
bool checkIdStudentForListRegister (ptrListRegister lr, string &idStudent){
	for(ptrRegister current = lr->head; current != nullptr; current = current->next){
		if(idStudent == current->data.idStudent){
			return true;
		}
	}
	return false;
}

// draw lai khung hien thi duoi tieu de bang danh sach diem tong ket
void drawNewListScoreByClass (){
	setfillstyle(SOLID_FILL, WHITE);
	bar(TEXTSPOINTX1, TEXTLPOINTY1, TEXTLPOINTX3, TEXTLPOINTY1 + 330); 

	setcolor(LIGHTGRAY);
	line(TEXTSPOINTX1, TEXTLPOINTY1 - 30													, TEXTSPOINTX1														, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40, TEXTLPOINTY1 - 30												, TEXTSPOINTX1 + 40 												, TEXTLPOINTY1 + 330); 
	line(TEXTSPOINTX1 + 40 + 120, TEXTLPOINTY1 - 30											, TEXTSPOINTX1 + 40 + 120											, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200, TEXTLPOINTY1 - 30									, TEXTSPOINTX1 + 40 + 120 + 200										, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80, TEXTLPOINTY1 - 30								, TEXTSPOINTX1 + 40 + 120 + 200 + 80								, TEXTLPOINTY1 + 330);
	
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80, TEXTLPOINTY1 - 30							, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80							, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80, TEXTLPOINTY1 - 30					, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80						, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30				, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80					, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30			, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80			, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30		, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80		, TEXTLPOINTY1 + 330);
	line(TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80 + 80, TEXTLPOINTY1 - 30, TEXTSPOINTX1 + 40 + 120 + 200 + 80 + 80 + 80 + 80 + 80 + 80 + 80	, TEXTLPOINTY1 + 330);
	
	//dong cuoi
	line(TEXTSPOINTX1, TEXTLPOINTY1 + 330, TEXTSPOINTX1 + 980, TEXTLPOINTY1 + 330);

	setDefault();
}

// tim kiem trong danh sach lop tin chi co ton tai sinh vien nào có điểm không
bool checkScoreStudentInClassSubject(ptrListRegister ptrlr){
	for(ptrRegister i = ptrlr->head; i != nullptr; i = i->next){
		if(i->data.scores != 11 || (i->data.scores >= 0 && i->data.scores <= 10)){
			return true;
		}
	}
	return false;
}


// print danh sach diem theo mon cua lop
void printListScoreByClass(listClassForSubject lcfs, listStudent ls, string &idClass) {
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);

    bool checkDataInClass = false;
	bool hasScore = false;
    int sttStudentForClass = 0;// so thu tu sinh vien tỏng lop tin chi
    int cot = 0;
	int hang = 22;

	for (ptrStudent curStu = ls.head; curStu != nullptr; curStu = curStu->next) {
        if (idClass == curStu->value.idClass) {
			sttStudentForClass++;
			std::cout << "sinh vien " << setw(3) << sttStudentForClass << std::endl; 
			for (int i = 0; i < lcfs.size; i++) {
				// if(lcfs.list[i]->lr->head->data.unSub || lcfs.list[i]->lr->head->data.scores > 10 || lcfs.list[i]->lr->head->data.scores < 0) // chỉ can in ra danh sach mon da co diem
				if(!checkScoreStudentInClassSubject(lcfs.list[i]->lr)) // neu lop khong co sinh vien co diem thi bỏ qua
					continue;

				std::cout << " i = " << setw(10) << i << std::endl;
				checkDataInClass = true;
				delay(100);

				if(sttStudentForClass % 15 - 1 == 0){
					delay(200);
					hang = 22;
					drawNewListScoreByClass();
				}

				setcolor(GREEN);
				setbkcolor(WHITE);
				outtextxy(TEXTSPOINTX1 + 3      			, TEXTLPOINTY1 - 20 + hang, tochar(to_string(sttStudentForClass)) );
				outtextxy(TEXTSPOINTX1 + 3 + 40 			, TEXTLPOINTY1 - 20 + hang, tochar(curStu->value.id) );
				outtextxy(TEXTSPOINTX1 + 3 + 40 + 120		, TEXTLPOINTY1 - 20 + hang, tochar(curStu->value.firstName));
				outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200	, TEXTLPOINTY1 - 20 + hang, tochar(curStu->value.lastName));

				// In ra header mon hoc da co diem
				delay(100);
				setcolor(WHITE);
				setbkcolor(LIGHTBLUE);
				outtextxy(TEXTSPOINTX1 + 2 + 40 + 120 + 200 + 80 + cot, TEXTLPOINTY1 - 22, tochar(lcfs.list[i]->idSubject));// mon 1 den het

				ptrRegister curReg = lcfs.list[i]->lr->head; // Con trỏ tạm thời
				while (curReg != nullptr) {
					if (idClass == curStu->value.idClass && curStu->value.id == curReg->data.idStudent && !curReg->data.unSub && 0 <= curReg->data.scores && curReg->data.scores <= 10) {
						delay(100);
						
						setcolor(RED);
						setbkcolor(WHITE);
						outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + cot, TEXTLPOINTY1 - 20 + hang, tochar(doubleToString(curReg->data.scores)));
						
						cot += D_COT_SCORE;
						break; // thay roi thi thoat, tranh lap den cuoi
					}
					curReg = curReg->next; 
				}
				if (curReg == nullptr) {// sinh vien khong co diem
					delay(100);

					setcolor(BLACK);
					setbkcolor(WHITE);
					outtextxy(TEXTSPOINTX1 + 3 + 40 + 120 + 200 + 80 + cot, TEXTLPOINTY1 - 20 + hang, "#");
					cot += D_COT_SCORE;
				}
			}
			hang += 21;
			cot = 0;
		}
	}
		

    if (!checkDataInClass) {
		setfillstyle(SOLID_FILL, WHITE);
		bar(TEXTSPOINTX1 + 2 , TEXTLPOINTY1 , TEXTLPOINTX3 - 1, TEXTLPOINTY1 + 330); // an bang du lieu truoc danh sach diem truoc do

        settextstyle(COMPLEX_FONT, HORIZ_DIR, 1);
        setcolor(BLACK);
        setbkcolor(YELLOW);
        outtextxy(TEXTSPOINTX1 + 400 + 3, TEXTLPOINTY1 - 20 + 50, "LOP SINH VIEN CHUA CO DIEM ... ");
    }
}


//Xu ly dieu khien bang diem tong ket (muc 4) phan 4
void displayClassCumulativeScores(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls,listClass &lc){
	drawTableControlClassScores();// Bang dieu khien 
	
	int ascii, x, y, selected = 0, on = 0, cntline = 1, lineCurrent = 1;
	
	string idClass = emptyStr;
	string nameClass = emptyStr;
	char key;
	int TSTC;
	float gpa; 
	int order=0; 
	
	drawTableDataClassScoresEmpty();// bang chua danh sach diem sinh vien

	while(true){
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
		}
		if(ascii == ESC) 
			return;

		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInRange(x, y, TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40)){ // ten ma mon hoc
				// highlightInputExamScoresV2(selected, BLUE);
				
				lineCurrent = 1; cntline = 1;
				idClass=""; 
				
				createListIdSubjectV2(); // khung danh sach lop can lua chon
				highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
				findListIdClass(lc,idClass,cntline,nameClass); // loc theo ten va in thong tin ra man hinh
				while(true){
					if(kbhit()){
						key = getch();
						ascii = static_cast<int>(key);
				        if (ascii == 0) { 
				            key = getch();
				            ascii = static_cast<int>(key);
				            ascii += 255;
				    	}
				    	
				    	if(ascii == ET && idClass !=""){
							if(idClass != ""){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
								nameClass = idClass; // du lieu duoc chon luu vao nameClass;
								
								outtextwithlineV3(0, idClass, BLACK);
								
								setcolor(LIGHTGRAY);
								rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TABLE_CLASS_SX + 200 + 70, TABLE_CLASS_SY + 10 + 20, TABLE_CLASS_SX + 200 + 150, TABLE_CLASS_SY + 10 + 20 + 20);
								setcolor(RED);
								outtextxy(TABLE_CLASS_SX + 200 + 70, TABLE_CLASS_SY + 10 + 20, tochar(idClass));// cap nhat lop dang hien thi
								drawTableDataClassScores();

								printListScoreByClass(lcfs, ls, idClass);
								// searchNumberTC(lsj,lcfs,ls,idClass,order,lineCurrent);
							}
							else{
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201); // xoa danh sach
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41); // xoa noi dung da nhap
								nameClass = emptyStr;	
							}
							
							nameClass = emptyStr;
							lineCurrent = 1;
							setcolor(LIGHTGRAY);
							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							setDefault();
							break;
						}
						else if(ascii == UP && idClass != ""){
							if(lineCurrent > 1){
								
								string prevClass = findPrevClassV2(lc,idClass);

								std::cout << "id class line > 0: " << idClass << std::endl;

								if(prevClass != ""){
									highlightInputLineCurrent(lineCurrent, WHITE);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
									idClass = prevClass;
									
									lineCurrent -= 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
									// print danh sach
								}
							}
							else if(lineCurrent == 1){
								string prevClass = findPrevClassV2(lc,idClass);

								std::cout << "id class line == 1: " << idClass << std::endl;

								if(prevClass != ""){
									idClass = prevClass;
									
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
									lineCurrent += 1;
									
									while(findNextClassV2(lc,prevClass) != "" && lineCurrent <= 8){
										prevClass = findNextClassV2(lc, prevClass);
										outtextwithlineV3(lineCurrent, prevClass, BLACK);
										lineCurrent += 1;
									}
									lineCurrent = 1;
								}
							}
						}	
						else if(ascii == DOWN && idClass != ""){
							if(lineCurrent < 8 && lineCurrent != 0){
								string nextClass = findNextClassV2(lc, idClass);

								std::cout << "id class line < 8 and != 0: " << idClass << std::endl;

								if(nextClass != ""){
									
									highlightInputLineCurrent(lineCurrent, WHITE);
									outtextwithlineV3(lineCurrent, idClass, BLACK);
									
									idClass = nextClass;
									lineCurrent += 1;
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent, idClass, BLACK);


									//print danh sach



								}
							}
							else if(lineCurrent == 8){
								string nextClass = findNextClassV2(lc, idClass);// tim tk ke tiep 

								std::cout << "id class line == 8: " << idClass << std::endl;

								if(nextClass != ""){
									idClass = nextClass;// hien tai = ke tiep 
									createListIdSubjectV2();
									highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
									setbkcolor(LIGHTGRAY);
									outtextwithlineV3(lineCurrent,nextClass, BLACK); //hien ra ke tiep 
									lineCurrent -= 1;
									
									while(findPrevClassV2(lc,nextClass) != "" && lineCurrent >= 1){
										nextClass = findPrevClassV2(lc,nextClass);
										outtextwithlineV3(lineCurrent, nextClass, BLACK);
										lineCurrent -= 1;
									}
									lineCurrent = 8;
								}
							}
						}
						else if(ascii == ESC){
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1, TEXTLPOINTY1 - 39, TEXTLPOINTX1 - 49, TEXTLPOINTY1 + 201);
							bar(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);					
							setcolor(LIGHTGRAY);
							rectangle(TEXTSPOINTX1, TEXTSPOINTY1 - 40, TEXTLPOINTX1 - 50, TEXTLPOINTY1 - 40);
							
							nameClass = emptyStr;//idClass="";
							drawPrintRegisteredStudentListV5();
							setDefault();
							break;
						}
						
						if(ascii == BP && (int)nameClass.size() > 0){
							nameClass.pop_back();
							setfillstyle(SOLID_FILL, WHITE);
							bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
							setcolor(BLACK);
							outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameClass));
							
							lineCurrent = 1; nameClass = ""; cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdClass(lc,idClass,lineCurrent,nameClass);
							
						}
						else if(('a' <= ascii && ascii <= 'z') || ('A' <= ascii && ascii <= 'Z') || ('0' <= ascii && ascii <= '9')  || ascii == SPACE){
							if((int)nameClass.size() < 9){
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 - 39, TEXTLPOINTX1 - 51, TEXTLPOINTY1 - 41);
								formatKey(key);
								nameClass += key;
								setcolor(BLACK);
								outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 - 30, tochar(nameClass));
							}
							
							lineCurrent = 1; idClass = "", cntline = 1;
							createListIdSubjectV2(); // tao khung chua danh sach
							highlightInputLineCurrent(lineCurrent, LIGHTGRAY);
							findListIdClass(lc,idClass,lineCurrent,nameClass);
						}

						if(ismouseclick(WM_LBUTTONDOWN)){
							getmouseclick(WM_LBUTTONDOWN, x, y);
							clearmouseclick(WM_LBUTTONDOWN);


						}
					}
				}
			}
		}
	}
}


/*DIEU KIEN DIEM SINH VIEN
*/
//================================================================================================

void studentGradeManagement(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls,listClass &lc){
	
	int selected = 1, run1 = 1;
	char key;
	
	drawStudentGradeManagement(selected);
	
	while(run1){
		if(kbhit()){
			key = getch();
			
			int ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	
			switch(ascii){
				case ET: 
					switch(selected){
						case 1: // nhap diem cho lop tin chi
							inputExamScores(lcfs, lsj, ls);
							drawStudentGradeManagement(selected);
							break;
						case 2: // in diem thi cua lop tin chi
							displayExamScores(lcfs,lsj,ls);
							drawStudentGradeManagement(selected);
							break;
						case 3: // in diem trung binh theo lop hoc, gom nhieu mon/ lop tin chi
							displayClassEverageScores(lcfs, lsj, ls, lc); 
							drawStudentGradeManagement(selected);
							break;
						case 4: // in diem tong ket theo lop hoc, gom nhieu mon/ lop tin chi
							displayClassCumulativeScores(lcfs, lsj, ls, lc);
							drawStudentGradeManagement(selected);
							break;
					}
					break;
				case UP:
					if(selected > 1){
						selected--;
						drawStudentGradeManagement(selected);
					}
					break;
				case DOWN:
					if(selected < 4){
						selected++;
						drawStudentGradeManagement(selected);
					}
					break;
				case ESC:
					return;
			}
		}
	}
}


#endif
