#ifndef STUDENTGRADEMANAGEMENT_H
#define STUDENTGRADEMANAGEMENT_H

#define emptyStr ""
#define MAXYEAR  30
#define MAXSEMESTER 3


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

void studentGradeManagement(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls){
	
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
//						case 2: // in diem thi cua lop tin chi
//							displayExamScores();
//							drawStudentGradeManagement(selected);
//							break;
//						case 3: // in diem trung binh theo lop hoc, gom nhieu mon/ lop tin chi
//							displayClassEverageScores();
//							drawStudentGradeManagement(selected);
//							break;
//						case 4: // in diem tong ket theo lop hoc, gom nhieu mon/ lop tin chi
//							displayClassCumulativeScores();
//							drawStudentGradeManagement(selected);
//							break;
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
