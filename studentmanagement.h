#ifndef STUDENTMANAGEMENT_H
#define STUDENTMANAGEMENT_H

#define emptyStr ""

void outtextwith(int line, student s, int COLOR){ // outtext voi chi so dong line
	
	setcolor(COLOR);
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

int isEmptyBox(int num, string idStudent, string firstName, string lastName, string gender, string phone, string year){
	switch(num){
		case 1:
			if(idStudent == emptyStr) return 1;
			break;
		case 2:			
			if(firstName == emptyStr) return 1;
			break;
		case 3:		
			if(lastName == emptyStr) return 1;
			break;
		case 4:	
			if(gender == emptyStr) return 1;
			break;
		case 5:
			if(phone == emptyStr) return 1;
			break;
		case 6:
			if(year == emptyStr) return 1;
			break;
	}
	return 0;
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

int isFullInforStudent(student p){ // kiem tra con tro p da day du thong tin hay khong
	if(p.id == emptyStr || p.idClass == emptyStr || p.firstName == emptyStr || p.lastName == emptyStr ||
	   p.phone == emptyStr || p.gender == emptyStr || to_string(p.year).size() != 4) return 0;
	return 1;
}

int similarId(string idStudent, string idClass){ // kiem tra ma sinh vien co tuong ung voi ma lop khong
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


ptrStudent findStudent(listStudent &ls, string id, int &finded){ // tim kiem thong tin sinh vien trong ds sinh vien
	int cnt = 1;
	ptrStudent p = ls.head;
	ptrStudent firstStudent = NULL;
	while(p != NULL){
		if(isSubString(id, p->value.id) && cnt <= 4 && id != emptyStr){
			finded = 1; // da xuat hien thong tin lien quan
			if(firstStudent == NULL) firstStudent = p; // luu giu thong tin dau tien duoc in ra trong danh sach
//			if((int) id.size() == 10){
//				finded = 1; // danh dau da tim thay
//			}
			if(firstStudent == p) outtextwith(cnt, p->value, LIGHTGREEN); // neu la thong tin dau tien thi in dam, con tro chuot dang o day
			else outtextwith(cnt, p->value, BLACK); 
			cnt += 1; 
		}
		p = p->next;
	}
	return firstStudent;
}

ptrStudent findPrevStudent(listStudent &ls, string idStudent, string id){ // idStudent dang nhap tu ban phim, id la chuan trong danh sach
	ptrStudent p = ls.head, prev = NULL;
	while(p != NULL){
		if(p->value.id == id){ // tim duoc vi tri hien tai trong danh sach
			if(prev != NULL && isSubString(idStudent, prev->value.id)){ // sinh vien dung truoc co ma tuong ung voi ma dang nhap tu ban phim
				return prev;
			}
		}
		prev = p;
		p = p->next;
	}
	return NULL;
}

ptrStudent findNextStudent(listStudent &ls, string idStudent, string id){
	ptrStudent p = ls.head; 
	while(p != NULL){
		if(p->value.id == id){ // tim duoc vi tri sinh vien hien tai trong danh sach
			if(p->next != NULL && isSubString(idStudent, p->next->value.id)){ // sinh vien dung sau co ma tuong ung voi ma dang nhap tu ban phim
				return p->next;
			}
		}
		p = p->next;
	}
	return NULL;
}

ptrStudent findClass(listStudent &ls, string idClass, int &finded){ // tim ma lop, va in ra thong tin sinh vien trong lop do
	int cnt = 1;
	ptrStudent p = ls.head;
	ptrStudent firstStudent = NULL;
	while(p != NULL){
		if(isSubString(idClass, p->value.idClass) && cnt <= 4 && idClass != emptyStr){
			if(firstStudent == NULL) firstStudent = p;
			if((int)idClass.size() == 9){
				finded = 1;
			} // in ra 4 thong tin dau danh sach cho moi lan nhap
			if(firstStudent == p) outtextwith(cnt, p->value, LIGHTGREEN); // in ra trong dong thu cnt
			else outtextwith(cnt, p->value, BLACK);
			cnt += 1; 
		}
		p = p->next;
	}
	return firstStudent; // tra ve sinh vien dau tien duoc tim kiem
}

ptrStudent findStudentInClass(listStudent &ls, string idStudent, string idClass){ // tim sinh vien dung sau sinh vien hien tai co ma lop idclass
	int cnt = 1;
	ptrStudent p = ls.head;
	ptrStudent firstStudent = NULL;
	while(p != NULL){
		if(isSubString(idClass, p->value.idClass)){ 
			if(isSubString(idStudent, p->value.id) && cnt <= 4){
				// in ra thong tin vua nhap voi mau xanh tren dong 1
				firstStudent = p;
				outtextwith(cnt, p->value, LIGHTGREEN);
				cnt += 1;
			}
			else if(firstStudent != NULL && cnt <= 4){
				outtextwith(cnt, p->value, BLACK);
				cnt += 1;
			}
		}
		p = p->next;
	}
	return firstStudent;
}

ptrStudent findPrevStudentInClass(listStudent &ls, string idClass, string idStudent){ // tim sinh vien dung ngay truoc sinh vien hien tai, co ma lop la idclass
	ptrStudent p = ls.head, prev = NULL;
	while(p != NULL){
		if(p->value.id == idStudent){ // tim duoc vi tri sinh vien hien tai
			if(prev != NULL && isSubString(idClass, prev->value.idClass)){ // sinh vien dung truoc co ma lop tuong ung voi ma lop dang nhap tu ban phim
				return prev;
			}
		}
		prev = p;
		p = p->next;
	}
	return NULL;
}

ptrStudent findNextStudentInClass(listStudent &ls, string idClass, string idStudent){ // tim ra sinh vien dung ngay sau sinh vien hien tai co ma lop la idclass
	ptrStudent p = ls.head; 
	while(p != NULL){
		if(p->value.id == idStudent){ // tim ra vi tri cua sinh vien hien tai
			if(p->next != NULL && isSubString(idClass, p->next->value.idClass)){ // sinh vien dung sau co ma lop tuong ung voi ma lop dang nhap tu ban phim
				return p->next;
			}
		}
		p = p->next;
	}
	return NULL;
}

ptrStudent displayStudentWithId(listStudent ls, string id, string idStudent){ // id la ma dang nhap tu ban phim, 
	// liet ke tat ca sinh vien co ma id tuong ung voi ma id dang nhap tu ban phim
	// the hien tren bang bat dau bang sinh vien co ma la idStudent va tra ve sinh vien nay
	int cnt = 1, mark = 0;
	ptrStudent p = ls.head;
	ptrStudent firstStudent = NULL;
	while(p != NULL){
		if(isSubString(id, p->value.id) && cnt <= 4 && id != emptyStr){
			
			if(firstStudent == NULL && isSubString(idStudent, p->value.id)){ // khong xay ra qua 1 lan
				mark = 1;
				firstStudent = p;
				outtextwith(cnt, p->value, LIGHTGREEN);
				cnt += 1;
			}
			else if(mark == 1){
				outtextwith(cnt, p->value, BLACK);
				cnt += 1; 
			}
		}
		p = p->next;
	}
	return firstStudent;
}
void typeInforStudent(listStudent &ls, string idClass, ptrStudent firstStudent, int lineCurrent){
	int currentBox = 1, maxCurrentBox = 1, finded = 1;
	string idStudent, firstName, lastName, gender, phone, year;
	student s; s.idClass = idClass;
	
	int run2 = 1, enter = 1, x, y;
	while(run2){ // bat dau nhap thong tin ma lop
	 // cac muc nhap thong tin theo thu tu tu 1 - 6 tuong ung voi masv, ho, ten,...
	if(enter != 0){
		if(currentBox == 7){
			highlightInforStudentBox(currentBox, BLUE);
		}
		else 
			highlightInforStudentBox(currentBox, LIGHTBLUE); // chi doi mau ma khong xoa du lieu
		enter = 0;
	}
	maxCurrentBox = max(maxCurrentBox, currentBox); // xac dinh da nhap bao nhieu thong tin
		if(kbhit()){
			char key;
			key = getch();
			if(key == ET){
				switch(currentBox){
					case 1: // truong hop nhap xong maso sinh vien
						if((int)idStudent.size() != 10){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV khong du so ki tu!");
							setcolor(BLACK);
							Sleep(1000);
							resetText(); 
							setDefault();
						}
						else if(existStudent(ls, idStudent) || !similarId(idStudent, idClass)){ // neu ma so da ton tai khong the nhap
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV da ton tai hoac khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText(); 
							resetInforStudentBox(currentBox, LIGHTBLUE);
							idStudent = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.id = idStudent;
							setcolor(LIGHTGRAY);
							rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // doi khung xanh thanh khung den va duy chuyen qua muc ke tiep
							setDefault();
						}
						break;
					case 2: // truong hop nhap xong ho
						if((int)firstName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ho khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							firstName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.firstName = firstName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
							setDefault();
						}
						break;
					case 3: // truong hop nhap xong ten
						if((int)lastName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ten khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							lastName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.lastName = lastName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
							setDefault();
						}
						break;
					case 4: // truong hop nhap xong gioi tinh
						if(gender != "NAM" && gender != "NU"){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Gioi tinh khong phu hop!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							gender = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.gender = gender;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
							setDefault();
						}
						break;
					case 5: // truong hop nhap xong sdt
						if((int)phone.size() != 10 || phone[0] != '0' || phone[1] == '0'){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "SDT chu du hoac khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.phone = phone;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
							setDefault();
						}
						break;
					case 6: // truong hop nhap xong nam
						if((int)year.size() != 4 || !similarYear(year, idClass)){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Nam hoc khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							year = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.year = stringtoint(year);
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
							
							setfillstyle(SOLID_FILL, BLUE);
							bar(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // to dam muc add
							setbkcolor(BLUE);
							outtextxy(TABLSPOINTX + 930, FORMSPOINTY + 10, "Add");
							setDefault();
						}
						break;
					case 7: // truong hop nhap xong thong tin, nhan nut add
						if((int)idStudent.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin rong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							return;
						}
						else if((int)year.size() == 0){ // chi xay ra khi click chuot
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
							
							addStudent(ls, s);
							
							createList();
							firstStudent = findStudentInClass(ls, s.id, s.idClass); // hien thi ra thong tin sinh vien vua them
							if(firstStudent != NULL) lineCurrent = 1;
							else lineCurrent = 0;
							
							idStudent = emptyStr; firstName = emptyStr; lastName = emptyStr; 
							gender = emptyStr; phone = emptyStr; year = emptyStr;
							createFormStudent();
							
							enter = 1;
							currentBox = 1;
						}
						
						break;
				}	
			}
			else if(key == LEFT){
				switch(currentBox){
					case 2: // truong hop nhap xong ho
						if((int)firstName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ho khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							firstName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							s.firstName = firstName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
							setDefault();
						}
						break;
					case 3: // truong hop nhap xong ten
						if((int)lastName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ten khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							lastName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							s.lastName = lastName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
							setDefault();
						}
						break;
					case 4: // truong hop nhap xong gioi tinh
						if(gender != "NAM" && gender != "NU"){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Gioi tinh khong phu hop!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							gender = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							s.gender = gender;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
							setDefault();
						}
						break;
					case 5: // truong hop nhap xong sdt
						if((int)phone.size() != 10 || phone[0] != '0' || phone[1] == '0'){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "SDT chu du hoac khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							s.phone = phone;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
							setDefault();
						}
						break;
					case 6: // truong hop nhap xong nam
						if((int)year.size() != 4 || !similarYear(year, idClass)){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Nam hoc khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							year = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							s.year = stringtoint(year);
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
						}
						break;
				}
			}
			else if(key == RIGHT){
				switch(currentBox){
					case 1: // truong hop nhap xong maso sinh vien
						if((int)idStudent.size() != 10){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV khong du so ki tu!");
							setcolor(BLACK);
							Sleep(1000);
							resetText(); 
							setDefault();
						}
						else if(existStudent(ls, idStudent) || !similarId(idStudent, idClass)){ // neu ma so da ton tai khong the nhap
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV da ton tai hoac khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText(); 
							resetInforStudentBox(currentBox, LIGHTBLUE);
							idStudent = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.id = idStudent;
							setcolor(LIGHTGRAY);
							rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // doi khung xanh thanh khung den va duy chuyen qua muc ke tiep
							setDefault();
						}
						break;
					case 2: // truong hop nhap xong ho
						if((int)firstName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ho khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							firstName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.firstName = firstName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
							setDefault();
						}
						break;
					case 3: // truong hop nhap xong ten
						if((int)lastName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ten khong duoc de trong!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							lastName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.lastName = lastName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
							setDefault();
						}
						break;
					case 4: // truong hop nhap xong gioi tinh
						if(gender != "NAM" && gender != "NU"){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Gioi tinh khong phu hop!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							gender = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.gender = gender;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
							setDefault();
						}
						break;
					case 5: // truong hop nhap xong sdt
						if((int)phone.size() != 10 || phone[0] != '0' || phone[1] == '0'){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "SDT chu du hoac khong hop le!");
							setcolor(BLACK);
							Sleep(1000);
							resetText();
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							s.phone = phone;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
							setDefault();
						}
						break;
				}
			}
			else if(key == UP){
				if(lineCurrent > 1){
					// dich sang o truoc do
					ptrStudent prevStudent = findPrevStudentInClass(ls, idClass, firstStudent->value.id); // tim ra thong tin sinh vien trong lop truoc do
					if(prevStudent != NULL){
						outtextwith(lineCurrent, firstStudent->value, BLACK); // doi mau chu thanh mau den
						
						firstStudent = prevStudent;
						lineCurrent -= 1;
						outtextwith(lineCurrent, firstStudent->value, LIGHTGREEN); // to sang thong tin sinh vien duoc chon
					}
				}
				else if(lineCurrent == 1){
					// to trang moi bat dau dong tu 1
					ptrStudent prevStudent = findPrevStudentInClass(ls, idClass, firstStudent->value.id);
					if(prevStudent != NULL){
						firstStudent = prevStudent;
						
						createList(); // tao trang moi
						outtextwith(lineCurrent, prevStudent->value, LIGHTGREEN);
						lineCurrent += 1;
						
						while(findNextStudentInClass(ls, idClass, prevStudent->value.id) != NULL && lineCurrent <= 4){
							prevStudent = findNextStudentInClass(ls, idClass, prevStudent->value.id);
							outtextwith(lineCurrent, prevStudent->value, BLACK);
							lineCurrent += 1;
						}
						lineCurrent = 1;
					}
				}
			}
			else if(key == DOWN){
				if(lineCurrent < 4 && lineCurrent != 0){
					ptrStudent nextStudent = findNextStudentInClass(ls, idClass, firstStudent->value.id);
					if(nextStudent != NULL){
						outtextwith(lineCurrent, firstStudent->value, BLACK);
						
						firstStudent = nextStudent;
						lineCurrent += 1;
						outtextwith(lineCurrent, firstStudent->value, LIGHTGREEN);
					}
				}
				else if(lineCurrent == 4){
					// to trang moi bat dau tu dong 1
					ptrStudent nextStudent = findNextStudentInClass(ls, idClass, firstStudent->value.id);
					if(nextStudent != NULL){
						firstStudent = nextStudent;
						createList();
						outtextwith(lineCurrent, nextStudent->value, LIGHTGREEN);
						lineCurrent -= 1;
						
						while(findPrevStudentInClass(ls, idClass, nextStudent->value.id) != NULL && lineCurrent >= 1){
							nextStudent = findPrevStudentInClass(ls, idClass, nextStudent->value.id);
							outtextwith(lineCurrent, nextStudent->value, BLACK);
							lineCurrent -= 1;
						}
						lineCurrent = 4;
					}
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
				// ve lai toan bo man hinh va xoa nhung gi da nhap
				enter = 1;
				currentBox = 1;
				drawStudentManagement(1);
				drawUpdateStudent();
				drawInsertStudent();
				outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idClass));
				firstStudent = findClass(ls, idClass, finded);
				if(firstStudent != NULL) lineCurrent = 1;
				else lineCurrent = 0;
				
				idStudent = emptyStr; firstName = emptyStr; lastName = emptyStr; 
				gender = emptyStr; phone = emptyStr; year = emptyStr;
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
					
					addStudent(ls, s);
					
					createList();
					firstStudent = findStudentInClass(ls, s.id, s.idClass); // hien thi ra thong tin sinh vien vua them
					if(firstStudent != NULL) lineCurrent = 1;
					else lineCurrent = 0;
					
					idStudent = emptyStr; firstName = emptyStr; lastName = emptyStr; 
					gender = emptyStr; phone = emptyStr; year = emptyStr;
					createFormStudent();
					
					enter = 1;
					currentBox = 1;
				}
			}
			 //click de chinh sua nhap id
			else if(clickInScore(x, y, FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY) && maxCurrentBox >= 1){
				// bat dau to nhat muc dang chon
				if(isEmptyBox(currentBox, idStudent, firstName, lastName, gender, phone, year)){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin khong the rong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
				}
				else{
					setcolor(BLACK); 
					if(currentBox == 7){
						highlightInforStudentBox(currentBox, LIGHTBLUE);
					}
					else{
						highlightInforStudentBox(currentBox, LIGHTGRAY);
					}
					enter = 1; // hightlight muc can chinh sua
					currentBox = 1;
				}
			}
			// click de chinh sua nhap ho
			else if(clickInScore(x, y, TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY) && maxCurrentBox >= 2){
				//bat dau to nhat muc dang chon
				if(isEmptyBox(currentBox, idStudent, firstName, lastName, gender, phone, year)){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin khong the rong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
				}
				else{
					setcolor(BLACK); 
					if(currentBox == 7){
						highlightInforStudentBox(currentBox, LIGHTBLUE);
					}
					else{
						highlightInforStudentBox(currentBox, LIGHTGRAY);
					}
					enter = 1; // hightlight muc can chinh sua
					currentBox = 2;
				}
			}
			// click de chinh sua nhap ten
			else if(clickInScore(x, y, TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY) && maxCurrentBox >= 3){
				//bat dau to nhat muc dang chon
				if(isEmptyBox(currentBox, idStudent, firstName, lastName, gender, phone, year)){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin khong the rong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
				}
				else{
					setcolor(BLACK); 
					if(currentBox == 7){
						highlightInforStudentBox(currentBox, LIGHTBLUE);
					}
					else{
						highlightInforStudentBox(currentBox, LIGHTGRAY);
					}
					enter = 1; // hightlight muc can chinh sua
					currentBox = 3;
				}
			}
			// click de chinh sua nhap gioi tinh
			else if(clickInScore(x, y, TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY) && maxCurrentBox >= 4){
				//bat dau to nhat muc dang chon
				if(isEmptyBox(currentBox, idStudent, firstName, lastName, gender, phone, year)){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin khong the rong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
				}
				else{
					setcolor(BLACK); 
					if(currentBox == 7){
						highlightInforStudentBox(currentBox, LIGHTBLUE);
					}
					else{
						highlightInforStudentBox(currentBox, LIGHTGRAY);
					}
					enter = 1; // hightlight muc can chinh sua
					currentBox = 4;
				}
			}
			// click de chinh sua nhap sdt
			else if(clickInScore(x, y, TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY) && maxCurrentBox >= 5){
				//bat dau to nhat muc dang chon
				if(isEmptyBox(currentBox, idStudent, firstName, lastName, gender, phone, year)){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin khong the rong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
				}
				else{
					setcolor(BLACK); 
					if(currentBox == 7){
						highlightInforStudentBox(currentBox, LIGHTBLUE);
					}
					else{
						highlightInforStudentBox(currentBox, LIGHTGRAY);
					}
					enter = 1; // hightlight muc can chinh sua
					currentBox = 5;
				}
			}
			// click de chinh sua nhap nam
			else if(clickInScore(x, y, TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY) && maxCurrentBox >= 6){
				//bat dau to nhat muc dang chon
				if(isEmptyBox(currentBox, idStudent, firstName, lastName, gender, phone, year)){
					setcolor(LIGHTRED);
					outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Thong tin khong the rong!");
					setcolor(BLACK);
					Sleep(1000);
					resetText();
				}
				else{
					setcolor(BLACK); 
					if(currentBox == 7){
						highlightInforStudentBox(currentBox, LIGHTBLUE);
					}
					else{
						highlightInforStudentBox(currentBox, LIGHTGRAY);
					}
					enter = 1; // hightlight muc can chinh sua
					currentBox = 6;
				}
			}
			//click ra ngoai
		}
	}
}



void insertStudent(listStudent &ls){ // bat buoc nhap ma lop sau do bat dau nhap thong tin voi ham typeInforStudent()
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
				int finded = 0, lineCurrent = 0; // dong thong tin dang duoc to sang
				ptrStudent firstStudent = NULL;
				while(run2){ // bat dau nhap thong tin ma lop
					// truong hop nhan phim
					if(kbhit()){
						char key;
						key = getch();
						if(key == ET){
							// khong co du lieu thi thong bao
							if(!finded){
								setcolor(LIGHTRED);
								outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong tim thay! Hay nhap dung Ma lop.");
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
								typeInforStudent(ls, idClass, firstStudent, lineCurrent);
								return; // quay tro lai muc them sua xoa thong tin.
								
							}
							// chuong trinh tiep tuc, reset lai muc nhap
							idClass = "";
						}
						else if(key == UP){
							if(lineCurrent > 1){
								// dich sang o truoc do
								ptrStudent prevStudent = findPrevStudentInClass(ls, idClass, firstStudent->value.id); // tim ra thong tin sinh vien trong lop truoc do
								if(prevStudent != NULL){
									outtextwith(lineCurrent, firstStudent->value, BLACK); // doi mau chu thanh mau den
									
									firstStudent = prevStudent;
									lineCurrent -= 1;
									outtextwith(lineCurrent, firstStudent->value, LIGHTGREEN); // to sang thong tin sinh vien duoc chon
								}
							}
							else if(lineCurrent == 1){
								// to trang moi bat dau dong tu 1
								ptrStudent prevStudent = findPrevStudentInClass(ls, idClass, firstStudent->value.id);
								if(prevStudent != NULL){
									firstStudent = prevStudent;
									
									createList(); // tao trang moi
									outtextwith(lineCurrent, prevStudent->value, LIGHTGREEN);
									lineCurrent += 1;
									
									while(findNextStudentInClass(ls, idClass, prevStudent->value.id) != NULL && lineCurrent <= 4){
										prevStudent = findNextStudentInClass(ls, idClass, prevStudent->value.id);
										outtextwith(lineCurrent, prevStudent->value, BLACK);
										lineCurrent += 1;
									}
									lineCurrent = 1;
								}
							}
						}
						else if(key == DOWN){
							if(lineCurrent < 4 && lineCurrent != 0){
								ptrStudent nextStudent = findNextStudentInClass(ls, idClass, firstStudent->value.id);
								if(nextStudent != NULL){
									outtextwith(lineCurrent, firstStudent->value, BLACK);
									
									firstStudent = nextStudent;
									lineCurrent += 1;
									outtextwith(lineCurrent, firstStudent->value, LIGHTGREEN);
								}
							}
							else if(lineCurrent == 4){
								// to trang moi bat dau tu dong 1
								ptrStudent nextStudent = findNextStudentInClass(ls, idClass, firstStudent->value.id);
								if(nextStudent != NULL){
									firstStudent = nextStudent;
									createList();
									outtextwith(lineCurrent, nextStudent->value, LIGHTGREEN);
									lineCurrent -= 1;
									
									while(findPrevStudentInClass(ls, idClass, nextStudent->value.id) != NULL && lineCurrent >= 1){
										nextStudent = findPrevStudentInClass(ls, idClass, nextStudent->value.id);
										outtextwith(lineCurrent, nextStudent->value, BLACK);
										lineCurrent -= 1;
									}
									lineCurrent = 4;
								}
							}
						}
						else if(key == BP && (int)idClass.size() > 0){
							idClass.pop_back();
							resetBox(LIGHTBLUE); // xoa muc nhap va in lai
							outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idClass));
							createList();
							firstStudent = findClass(ls, idClass, finded);
							if(firstStudent != NULL) lineCurrent = 1;
							else lineCurrent = 0;
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
								firstStudent = findClass(ls, idClass, finded); // da to sang thong tin dau tien
								if(firstStudent != NULL) lineCurrent = 1;
								else lineCurrent = 0;
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
 
void editStudent(listStudent &ls, string id, ptrStudent firstStudentTemp, int &lineCurrent){ 
	drawEditStudent();
	
	resetBox(BLACK); // ve lai muc nhap mssv
	setcolor(BLACK);
	outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(id));
	
	student firstStudent = firstStudentTemp->value; // firstStudent chua thong tin dang cap nhat, cap nhat toi dau, firstStudent thay doi toi do (de hien thi vao muc nhap)
	                                            // firstStudentTemp chi thay doi thong tin khi hoan tat cap nhat (an vao update)
	
	// lay tat ca thong tin cua sinh vien can chinh sua
	string idStudent = firstStudent.id;
	string firstName = firstStudent.firstName;
	string lastName = firstStudent.lastName;
	string gender = firstStudent.gender;
	string phone = firstStudent.phone;
	string idClass = firstStudent.idClass;
	string year = to_string(firstStudent.year);
	
	// in ra thong tin sinh vien can chinh sua tren man hinh
	
	setcolor(BLACK);
	outtextxy(FORMSPOINTX + 10, FORMSPOINTY + 10, tochar(idStudent));
	outtextxy(TABLSPOINTX + 155, FORMSPOINTY + 10, tochar(firstName));
	outtextxy(TABLSPOINTX + 375, FORMSPOINTY + 10, tochar(lastName));
	outtextxy(TABLSPOINTX + 520, FORMSPOINTY + 10, tochar(gender));
	outtextxy(TABLSPOINTX + 620, FORMSPOINTY + 10, tochar(phone));
	outtextxy(TABLSPOINTX + 765, FORMSPOINTY + 10, tochar(idClass));
	outtextxy(TABLSPOINTX + 910, FORMSPOINTY + 10, tochar(year));
	
	int currentBox = 1, maxCurrentBox = 1;
	
	int run1 = 1, enter = 1, finded = 1, x, y;
		
	char key;
	while(run1){
		if(enter != 0){
			if(currentBox == 8){
				highlightEditInforStudentBox(currentBox, BLUE);
			}
			else if(currentBox == 7){
				setcolor(LIGHTBLUE);
				rectangle(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY);
				setDefault();
			}
			else 
				highlightInforStudentBox(currentBox, LIGHTBLUE); // chi doi mau ma khong xoa du lieu
			enter = 0;
		}
		maxCurrentBox = max(maxCurrentBox, currentBox); // xac dinh da nhap bao nhieu thong tin
		if(kbhit()){
			char key;
			key = getch();
			if(key == ET){
				switch(currentBox){
					case 1: // truong hop nhap xong maso sinh vien
						if((int)idStudent.size() != 10){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV khong du so ki tu!");
							setcolor(BLACK);
							delay(1000);
							resetText(); 
							setDefault();
						}
						else if(!similarId(idStudent, idClass)){ // neu ma so da ton tai khong the nhap
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV da ton tai hoac khong hop le!");
							setcolor(BLACK);
							delay(1000);
							resetText(); 
							resetInforStudentBox(currentBox, LIGHTBLUE);
							idStudent = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.id = idStudent;
							setcolor(LIGHTGRAY);
							rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // doi khung xanh thanh khung den va duy chuyen qua muc ke tiep
							setDefault();
						}
						break;
					case 2: // truong hop nhap xong ho
						if((int)firstName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ho khong duoc de trong!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							firstName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.firstName = firstName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
							setDefault();
						}
						break;
					case 3: // truong hop nhap xong ten
						if((int)lastName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ten khong duoc de trong!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							lastName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.lastName = lastName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
							setDefault();
						}
						break;
					case 4: // truong hop nhap xong gioi tinh
						if(gender != "NAM" && gender != "NU"){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Gioi tinh khong phu hop!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							gender = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.gender = gender;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
							setDefault();
						}
						break;
					case 5: // truong hop nhap xong sdt
						if((int)phone.size() != 10 || phone[0] != '0' || phone[1] == '0'){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "SDT chu du hoac khong hop le!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.phone = phone;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
							setDefault();
						}
						break;
					case 6: // truong hop nhap xong idClass
					
						enter = 1;
						currentBox += 1;
						firstStudent.idClass = idClass;
						setcolor(LIGHTGRAY);
						rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
						break;
					case 7: // truong hop nhap xong nam
					
						if((int)year.size() != 4 || !similarYear(year, idClass)){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khoa hoc khong hop le!");
							setcolor(BLACK);
							delay(1000);
							resetText();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.year = stringtoint(year);
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY);
							
							setDefault();							
						}
						break;
						
					case 8: // truong hop da nhap xong thong tin
						
						if(!isFullInforStudent(firstStudent)){ // chi xay ra khi click chuot
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Vui long nhap du thong tin!");
							setcolor(BLACK);
							delay(1000);
							resetText();
						}
						else{
							setcolor(LIGHTGREEN);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Cap nhat thong tin thanh cong!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							
							firstStudentTemp->value = firstStudent;
							//uploadStudent(ls, firstStudent->value); // cap nhat thong tin sinh vien moi
							
							createList();
							firstStudentTemp = displayStudentWithId(ls, id, firstStudentTemp->value.id); // hien thi nhung sinh vien co id giong voi id dang nhap tu bang phim 
//							Sleep(20000);
							if(firstStudentTemp != NULL) lineCurrent = 1;                            // va thong tin sinh vien dau tien la firstStudent
							else lineCurrent = 0;
							
							// xoa muc update va ve lai mac dinh truoc khi return
							setfillstyle(SOLID_FILL, WHITE);
							bar(FORMSPOINTX, FORMSPOINTY - 30, FORMLPOINTX, FORMLPOINTY + 10);
							bar(FORMSPOINTX, TABLLPOINTY + 100, TABLSPOINTX + 145, TABLLPOINTY + 140);
							
							setfillstyle(SOLID_FILL, LIGHTGRAY);
							setbkcolor(LIGHTGRAY);
							bar(TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140);
							outtextxy(TABLSPOINTX + 115, TABLLPOINTY + 110, "Them thong tin");
							bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
							outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
							
							resetBox(LIGHTBLUE); // ve lai muc nhap mssv
							setcolor(BLACK);
							outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(id));
							
							setDefault();
							return;
						}
						
						break;
				}	
			}
			
			else if(key == LEFT){
				switch(currentBox){
					case 2: // truong hop nhap xong ho
						if((int)firstName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ho khong duoc de trong!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							firstName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							firstStudent.firstName = firstName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
							setDefault();
						}
						break;
					case 3: // truong hop nhap xong ten
						if((int)lastName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ten khong duoc de trong!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							lastName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							firstStudent.lastName = lastName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
							setDefault();
						}
						break;
					case 4: // truong hop nhap xong gioi tinh
						if(gender != "NAM" && gender != "NU"){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Gioi tinh khong phu hop!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							gender = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							firstStudent.gender = gender;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
							setDefault();
						}
						break;
					case 5: // truong hop nhap xong sdt
						if((int)phone.size() != 10 || phone[0] != '0' || phone[1] == '0'){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "SDT chu du hoac khong hop le!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							setDefault();
						}
						else{
							enter = 1;
							currentBox -= 1;
							firstStudent.phone = phone;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
							setDefault();
						}
						break;
					case 6: // truong hop nhap xong idClass
					
						enter = 1;
						currentBox -= 1;
						firstStudent.idClass = idClass;
						setcolor(LIGHTGRAY);
						rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
						break;
					case 7: // truong hop nhap xong nam
					
						if((int)year.size() != 4 || !similarYear(year, idClass)){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khoa hoc khong hop le!");
							setcolor(BLACK);
							delay(1000);
							resetText();
						}
						else{
							enter = 1;
							currentBox -= 1;
							firstStudent.year = stringtoint(year);
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY);
							
							setDefault();							
						}
						break;
						
				}
						
			}
			else if(key == RIGHT){
				switch(currentBox){
					case 1: // truong hop nhap xong maso sinh vien
						if((int)idStudent.size() != 10){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV khong du so ki tu!");
							setcolor(BLACK);
							delay(1000);
							resetText(); 
							setDefault();
						}
						else if(!similarId(idStudent, idClass)){ // neu ma so da ton tai khong the nhap
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "MSSV da ton tai hoac khong hop le!");
							setcolor(BLACK);
							delay(1000);
							resetText(); 
							resetInforStudentBox(currentBox, LIGHTBLUE);
							idStudent = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.id = idStudent;
							setcolor(LIGHTGRAY);
							rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // doi khung xanh thanh khung den va duy chuyen qua muc ke tiep
							setDefault();
						}
						break;
					case 2: // truong hop nhap xong ho
						if((int)firstName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ho khong duoc de trong!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							firstName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.firstName = firstName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
							setDefault();
						}
						break;
					case 3: // truong hop nhap xong ten
						if((int)lastName.size() == 0){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Ten khong duoc de trong!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							lastName = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.lastName = lastName;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
							setDefault();
						}
						break;
					case 4: // truong hop nhap xong gioi tinh
						if(gender != "NAM" && gender != "NU"){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Gioi tinh khong phu hop!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							resetInforStudentBox(currentBox, LIGHTBLUE);
							gender = emptyStr;
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.gender = gender;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
							setDefault();
						}
						break;
					case 5: // truong hop nhap xong sdt
						if((int)phone.size() != 10 || phone[0] != '0' || phone[1] == '0'){
							setcolor(LIGHTRED);
							outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "SDT chu du hoac khong hop le!");
							setcolor(BLACK);
							delay(1000);
							resetText();
							setDefault();
						}
						else{
							enter = 1;
							currentBox += 1;
							firstStudent.phone = phone;
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
							setDefault();
						}
						break;
					case 6: // truong hop nhap xong idClass
					
						enter = 1;
						currentBox += 1;
						firstStudent.idClass = idClass;
						setcolor(LIGHTGRAY);
						rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
						break;
				}
			}
			
			else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9') || key == SPACE || key == BP){
				switch(currentBox){
					case 1: // xu ly nhap cho muc idStudent
						setcolor(LIGHTRED);
						outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong the chinh sua MSSV!");
						setcolor(BLACK);
						Sleep(500);
						resetText();
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
					case 6: // xu ly nhap cho muc idclass
						setcolor(LIGHTRED);
						outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong the chinh sua MSSV!");
						setcolor(BLACK);
						delay(1000);
						resetText();
						break;
					case 7: // xu ly cho muc nhap khoa
						if(key == BP && (int)year.size() > 0){
							year.pop_back();
							
							setfillstyle(SOLID_FILL, WHITE);
							bar(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY);
							setcolor(LIGHTGRAY);
							rectangle(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // xoa sach thong tin truoc do
							
							
							setcolor(BLACK);
							outtextxy(TABLSPOINTX + 910, FORMSPOINTY + 10, tochar(year));
						}
						else if(('0' <= key && key <= '9')){
							if((int)year.size() < 4){
								formatKey(key);
								year += key;
								setcolor(BLACK);
								outtextxy(TABLSPOINTX + 910, FORMSPOINTY + 10, tochar(year));
							} 
						}
						break;
				}
			}
			else if(key == ESC){
				if(createNotice("Ban chac chan muon thoat!", "")){ // truong hop nhan enter de tiep tuc
				
					// ve lai toan bo man hinh cu
					drawStudentManagement(1);
					drawUpdateStudent();
					drawEditStudent();
					displayStudentWithId(ls, id, firstStudent.id);
					setcolor(BLACK);
					outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(id));
					
					setcolor(BLACK);
					outtextxy(FORMSPOINTX + 10, FORMSPOINTY + 10, tochar(idStudent));
					outtextxy(TABLSPOINTX + 155, FORMSPOINTY + 10, tochar(firstName));
					outtextxy(TABLSPOINTX + 375, FORMSPOINTY + 10, tochar(lastName));
					outtextxy(TABLSPOINTX + 520, FORMSPOINTY + 10, tochar(gender));
					outtextxy(TABLSPOINTX + 620, FORMSPOINTY + 10, tochar(phone));
					outtextxy(TABLSPOINTX + 765, FORMSPOINTY + 10, tochar(idClass));
					outtextxy(TABLSPOINTX + 910, FORMSPOINTY + 10, tochar(year));
					
					enter = 1; // to xanh muc dang nhap	
				}
				else{
					
					// xoa muc update va ve lai mac dinh truoc khi return
					
					drawStudentManagement(1);
					drawUpdateStudent();
					drawEditStudent();
					
					createList();
					firstStudentTemp = displayStudentWithId(ls, id, firstStudentTemp->value.id); // hien thi nhung sinh vien co id giong voi id dang nhap tu bang phim 
					if(firstStudentTemp != NULL) lineCurrent = 1;                            // va thong tin sinh vien dau tien la firstStudent
					else lineCurrent = 0;
					
					resetBox(LIGHTBLUE); // ve lai muc nhap mssv
					setcolor(BLACK);
					outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(id));
					
					setfillstyle(SOLID_FILL, WHITE); // xoa muc nhap thong tin sinh vien
					bar(FORMSPOINTX, FORMSPOINTY - 30, FORMLPOINTX, FORMLPOINTY + 10);
					bar(FORMSPOINTX, TABLLPOINTY + 100, TABLSPOINTX + 145, TABLLPOINTY + 140);
					
					
					setfillstyle(SOLID_FILL, LIGHTGRAY); // hien lai cac chuc nang
					setbkcolor(LIGHTGRAY);
					bar(TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140);
					outtextxy(TABLSPOINTX + 115, TABLLPOINTY + 110, "Them thong tin");
					bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
					outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
					
					setbkcolor(LIGHTBLUE);
					setfillstyle(SOLID_FILL, LIGHTBLUE); // highlight muc dang chon
					bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
					outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
					setDefault();
					
					return;
				}
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			
		}
	}
}                      
void updateStudent(listStudent &ls){
	
	drawUpdateStudent(); // ve giao dien 
	
	int run1 = 1, run2 = 1, run3 = 1, finded = 0, lineCurrent = 0;
	string idStudent;
	ptrStudent firstStudent = NULL;
	
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
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY)){ // NEU CLICK VAO TIM KIEM SINH VIEN
				
				setcolor(LIGHTBLUE);
				rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); // to hop nhap thanh mau xanh
				setDefault();
				
				idStudent = emptyStr;
				finded = 0, lineCurrent = 0;
				firstStudent = NULL;
				char key; int selected = 1;
				while(run2){
					if(kbhit()){
						key = getch();
						if(key == ET){
							// khong co du lieu lien quan thi thong bao
							if(!finded){
								setcolor(LIGHTRED);
								outtextxy(BOXLPOINTX + 30, LISTSPOINTY + 80, "Khong tim thay du lieu!");
								createList();
								Sleep(1000);
								resetBox(LIGHTBLUE); // tao khung nhap rong voi mau xanh
								resetText(); 
								setcolor(BLACK);
								// chuong trinh tiep tuc, reset lai muc nhap
								idStudent = "";
							}
							else{ 
								if(selected == 1){
									editStudent(ls, idStudent, firstStudent, lineCurrent);
									
								}
								else{
									//deleteStudent(ls, firstStudent, lineCurrent);
									
								}
							}
						}	
						else if(key == RIGHT){
							if(selected == 1 && finded){
								selected += 1;
								
								setbkcolor(LIGHTGRAY);
								setfillstyle(SOLID_FILL, LIGHTGRAY); // unhighlight muc truoc do
								bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
								
								setbkcolor(LIGHTBLUE);
								setfillstyle(SOLID_FILL, LIGHTBLUE); // highlight muc dang chon
								bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
								
								setDefault();
							} 
						}
						else if(key == LEFT){
							if(selected == 2 && finded){
								selected -= 1;
								
								setbkcolor(LIGHTGRAY);
								setfillstyle(SOLID_FILL, LIGHTGRAY); // unhighlight muc truoc do
								bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
								
								setbkcolor(LIGHTBLUE);
								setfillstyle(SOLID_FILL, LIGHTBLUE); // highlight muc dang chon
								bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
								
								setDefault();
							}
						}
						else if(key == UP){
							if(lineCurrent > 1){
								// dich sang o truoc do
								ptrStudent prevStudent = findPrevStudent(ls, idStudent, firstStudent->value.id); // tim ra thong tin sinh vien trong lop truoc do co ma la ma con cua idstudent
								if(prevStudent != NULL){
									outtextwith(lineCurrent, firstStudent->value, BLACK); // doi mau chu thanh mau den
									
									firstStudent = prevStudent;
									lineCurrent -= 1;
									outtextwith(lineCurrent, firstStudent->value, LIGHTGREEN); // to sang thong tin sinh vien duoc chon
								}
							}
							else if(lineCurrent == 1){
								// to trang moi bat dau dong tu 1
								ptrStudent prevStudent = findPrevStudent(ls, idStudent, firstStudent->value.id); // idStudent dang nhap tu ban phim, id la chuan trong danh sach
								if(prevStudent != NULL){
									firstStudent = prevStudent;
									
									createList(); // tao trang moi
									outtextwith(lineCurrent, prevStudent->value, LIGHTGREEN);
									lineCurrent += 1;
									
									while(findNextStudent(ls, idStudent, prevStudent->value.id) != NULL && lineCurrent <= 4){
										prevStudent = findNextStudent(ls, idStudent, prevStudent->value.id);
										outtextwith(lineCurrent, prevStudent->value, BLACK);
										lineCurrent += 1;
									}
									lineCurrent = 1;
								}
							}
						}
						else if(key == DOWN){
							if(lineCurrent < 4 && lineCurrent != 0){
								ptrStudent nextStudent = findNextStudent(ls, idStudent,  firstStudent->value.id);
								if(nextStudent != NULL){
									outtextwith(lineCurrent, firstStudent->value, BLACK);
									
									firstStudent = nextStudent;
									lineCurrent += 1;
									outtextwith(lineCurrent, firstStudent->value, LIGHTGREEN);
								}
							}
							else if(lineCurrent == 4){
								// to trang moi bat dau tu dong 1
								ptrStudent nextStudent = findNextStudent(ls, idStudent, firstStudent->value.id);
								if(nextStudent != NULL){
									firstStudent = nextStudent;
									createList();
									outtextwith(lineCurrent, nextStudent->value, LIGHTGREEN);
									lineCurrent -= 1;
									
									while(findPrevStudent(ls, idStudent, nextStudent->value.id) != NULL && lineCurrent >= 1){
										nextStudent = findPrevStudent(ls, idStudent, nextStudent->value.id);
										outtextwith(lineCurrent, nextStudent->value, BLACK);
										lineCurrent -= 1;
									}
									lineCurrent = 4;
								}
							}
						}
						else if(key == BP && (int)idStudent.size() > 0){
							
							finded = 0;
							idStudent.pop_back();
							resetBox(LIGHTBLUE); // xoa muc nhap va in lai
							outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idStudent));
							createList();
							firstStudent = findStudent(ls, idStudent, finded); // in ra man hinh thong tin sinh vien va tra ve thong tin duoc to dam
							if(firstStudent != NULL) lineCurrent = 1;
							else lineCurrent = 0;
							
							if(finded){
								selected = 1;
								setbkcolor(LIGHTBLUE); // neu tim thay sinh vien thi hien thi chuc nang xoa sua.
								setfillstyle(SOLID_FILL, LIGHTBLUE); 
								bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
								
								setbkcolor(LIGHTGRAY);
								setfillstyle(SOLID_FILL, LIGHTGRAY); // neu tim kiem duoc thong tin sinh vien thi hien thi chuc nang xoa va sua
								bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
								
								setDefault();
							}
							else{ // neu khong tim thay thi khong hien thi chuc nang xoa va sua
								selected = 0;
								
								setbkcolor(LIGHTGRAY);
								setfillstyle(SOLID_FILL, LIGHTGRAY); // neu tim kiem duoc thong tin sinh vien thi hien thi chuc nang xoa va sua
								bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
								
								setfillstyle(SOLID_FILL, LIGHTGRAY); 
								bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
								outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
								
								setDefault();
							}
						}
						else if(('a' <= key && key <= 'z') || ('A' <= key && key <= 'Z') || ('0' <= key && key <= '9')){
							// luu tru input, xuat input, timkiem, xuat danh sach
							if((int)idStudent.size() < 10){
								finded = 0;
								formatKey(key);
								idStudent  += key;
								outtextxy(BOXSPOINTX + 10, BOXSPOINTY + 5, tochar(idStudent));
								
								// bat dau xu ly tim kiem
								createList(); 
								firstStudent = findStudent(ls, idStudent, finded); // finded nay de kiem tra xem co thong tin lien quan hay khong
								
								if(finded){
									selected = 1;
									setbkcolor(LIGHTBLUE); // neu tim thay sinh vien thi hien thi chuc nang xoa sua.
									setfillstyle(SOLID_FILL, LIGHTBLUE); 
									bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
									outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
									
									setbkcolor(LIGHTGRAY);
									setfillstyle(SOLID_FILL, LIGHTGRAY); // neu tim kiem duoc thong tin sinh vien thi hien thi chuc nang xoa va sua
									bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
									outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
									
									setDefault();
								}
								else{ // neu khong tim thay thi khong hien thi chuc nang xoa va sua
									selected = 0;
									
									setbkcolor(LIGHTGRAY);
									setfillstyle(SOLID_FILL, LIGHTGRAY); // neu tim kiem duoc thong tin sinh vien thi hien thi chuc nang xoa va sua
									bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
									outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
									
									setfillstyle(SOLID_FILL, LIGHTGRAY); 
									bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
									outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
									
									setDefault();
								}
								
								if(firstStudent != NULL) lineCurrent = 1;
								else lineCurrent = 0;
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
						clearmouseclick(WM_LBUTTONDOWN);
						if(!clickInScore(x, y, BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY)){ // click ra ngoai muc nhap khi dang nhap
							selected = 0;
								
							setbkcolor(LIGHTGRAY);
							setfillstyle(SOLID_FILL, LIGHTGRAY); // neu tim kiem duoc thong tin sinh vien thi hien thi chuc nang xoa va sua
							bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
							outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
							
							setfillstyle(SOLID_FILL, LIGHTGRAY); 
							bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
							outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
							
							setDefault();
						
							resetBox(BLACK);
							resetText();
							createList(); // click ra ngoai thi xoa luon bang tim kiem
							break; // dung nhap du lieu
						}
					}
				}
			}
			else if(clickInScore(x, y, TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140)){ // click vao muc them thong tin
				insertStudent(ls);
				cleardevice();
				drawStudentManagement(1);
				drawUpdateStudent();
			}
			else if(clickInScore(x, y, TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140)){ // click vao muc sua thong tin
				createBox(LIGHTRED, "Vui long nhap MSSV:");
				delay(1500);
				createBox(BLACK, "Vui long nhap MSSV:");
			}
			else if(clickInScore(x, y, TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140)){ // click vao muc xoa thong tin
				createBox(LIGHTRED, "Vui long nhap MSSV:");
				delay(1500);
				createBox(BLACK, "Vui long nhap MSSV:");
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

#endif
