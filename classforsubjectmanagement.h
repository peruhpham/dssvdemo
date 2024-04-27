#ifndef CLASSFORSUBJECTMANAGEMENT_H
#define CLASSFORSUBJECTMANAGEMENT_H

#define MAXYEAR  30
#define MAXSEMESTER 3
#define emptyStr ""

void outtextwithline(int lineCurrent, subject s, int COLOR){
	string text = s.idSubject + "-" + s.nameSubject;
	setcolor(COLOR);
	switch(lineCurrent){
		case 0: // in trong box
			outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 + 10, tochar(text));
			break;
		case 1:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 5, tochar(text));
			break;
		case 2:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 35, tochar(text));
			break;
		case 3:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 65, tochar(text));
			break;
		case 4:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 95, tochar(text));
			break;
		case 5:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 125, tochar(text));
			break;
		case 6:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 155, tochar(text));
			break;
		case 7:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 185, tochar(text));
			break;
		case 8:
			outtextxy(TEXTSPOINTX1 + 5, TEXTLPOINTY1 + 215, tochar(text));
			break;
	}
	setDefault();
}


void outtextwithline2(int lineCurrent, int academicYear, int COLOR){
	string text = to_string(academicYear);
	setcolor(COLOR);
	switch(lineCurrent){
		case 0: // in trong box
			outtextxy(TEXTSPOINTX2 + 5, TEXTSPOINTY2 + 10, tochar(text));
			break;
		case 1:
			outtextxy(TEXTSPOINTX2 + 5, TEXTLPOINTY2 + 5, tochar(text));
			break;
		case 2:
			outtextxy(TEXTSPOINTX2 + 5, TEXTLPOINTY2 + 35, tochar(text));
			break;
		case 3:
			outtextxy(TEXTSPOINTX2 + 5, TEXTLPOINTY2 + 65, tochar(text));
			break;
		case 4:
			outtextxy(TEXTSPOINTX2 + 5, TEXTLPOINTY2 + 95, tochar(text));
			break;
	}
	setDefault();
}

void outtextwithline4(int lineCurrent, int semester, int COLOR){
	string text = "Hoc ky " + to_string(semester);
	setcolor(COLOR);
	switch(lineCurrent){
		case 0: // in trong box
			outtextxy(TEXTSPOINTX4 + 5, TEXTSPOINTY4 + 10, tochar(text));
			break;
		case 1:
			outtextxy(TEXTSPOINTX4 + 5, TEXTLPOINTY4 + 5, tochar(text));
			break;
		case 2:
			outtextxy(TEXTSPOINTX4 + 5, TEXTLPOINTY4 + 35, tochar(text));
			break;
		case 3:
			outtextxy(TEXTSPOINTX4 + 5, TEXTLPOINTY4 + 65, tochar(text));
			break;
	}
	setDefault();
}

int isFullInForClass(ptrClassForSubject &cfs){
	if(cfs->academicYear == 0 || cfs->group == 0 || cfs->studentMax == 0 || cfs->studentMin == 0 || cfs->idSubject == emptyStr || cfs->semester == 0){
		setcolor(LIGHTRED);
		outtextxy(TEXTSPOINTX3, LISTSPOINTY + 60, "Khong de thong tin trong!");
		setcolor(BLACK);
		delay(1000);
		setfillstyle(SOLID_FILL, WHITE);
		bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
		setDefault();
		return 0;
	}
	return 1;
}


void findListIdSubject(ptrSubject root, ptrSubject &firstSubject, int &lineCurrent) { // in ra 8 thong tin dau tien
    if (root == NULL || lineCurrent > 8) return;

    findListIdSubject(root->left, firstSubject, lineCurrent);
    if (lineCurrent <= 8) {
        if (lineCurrent == 1) {
            setbkcolor(LIGHTGRAY);
            firstSubject = root;
        } 
		else setbkcolor(WHITE);
            
        outtextwithline(lineCurrent, root->data, BLACK);
        lineCurrent++;
    }
    findListIdSubject(root->right, firstSubject, lineCurrent);
}


ptrSubject findNextSubject(ptrSubject &root, ptrSubject p){
	ptrSubject nextSubject = NULL;
	ptrSubject current = root;
	while(current != NULL){
		if(current->data > p->data){
			nextSubject = current;
			current = current->left;
		}
		else if(current->data < p->data){
			current = current->right;
		}
		else{
			if(current->right != NULL){
				nextSubject = current->right;
				while(nextSubject->left != NULL){
					nextSubject = nextSubject->left;
				}
			}
			break;
		}
	}
	return nextSubject;
}

ptrSubject findPrevSubject(ptrSubject &root, ptrSubject p){
	ptrSubject prevSubject = NULL;
	ptrSubject current = root;
	while(current != NULL){
		if(current->data > p->data){
			current = current->left;
		}
		else if(current->data < p->data){
			prevSubject = current;
			current = current->right;
		}
		else{
			if(current->left != NULL){
				prevSubject = current->left;
				while(prevSubject->right != NULL){
					prevSubject = prevSubject->right;
				}
			}
			break;
		}
	}
	return prevSubject;
}

void findListYear(int *academicYear, int sizeYear){
	for(int i = 0; i < sizeYear; i++){
		if(i < 4){
			if(i == 0){
				setbkcolor(LIGHTGRAY);
			}
			else setbkcolor(WHITE);
			outtextwithline2(i + 1, academicYear[i], BLACK);
		}
		else return;
	}
}


int findIndexClass(listClassForSubject &lcfs, int idClass){
	for(int i = 0; i < lcfs.size; i++){
		if(lcfs.list[i]->idclass == idClass) return i;
	}
	return -1;
}
void findListSemester(int *semester, int sizeSemester){
	for(int i = 0; i < sizeSemester; i++){
		if(i == 0){
			setbkcolor(LIGHTGRAY);
		}
		else setbkcolor(WHITE);
		outtextwithline4(i + 1, semester[i], BLACK);
	}
}

void getListOpeningClass(ptrClassForSubject ListOpeningClass[], listClassForSubject &lcfs, int &sizeList, int idClass, int academic, int semester){
	for(int i = 0; i < sizeList; i++){
		ListOpeningClass[i] = NULL;
	}
	sizeList = 0;
	
	for(int i = 0; i < lcfs.size; i++){
		
		if(lcfs.list[i]->unClass == false && 
		(idClass == 0 || idClass == lcfs.list[i]->idclass) && 
		(academic == 0 || academic == lcfs.list[i]->academicYear) && 
	    (semester == 0 || semester == lcfs.list[i]->semester)){
			ListOpeningClass[sizeList] = lcfs.list[i]; // tro truc tiep vao lop
			sizeList += 1;
		}
	}
}
void getListCancelClass(ptrClassForSubject listCancelClass[], listClassForSubject &lcfs, int &sizeList, int idClass, int academic, int semester){
	
	for(int i = 0; i < sizeList; i++){
		listCancelClass[i] = NULL;
	}
	sizeList = 0;
	
	for(int i = 0; i < lcfs.size; i++){
		
		if(lcfs.list[i]->unClass == false && lcfs.list[i]->lr->size < lcfs.list[i]->studentMin &&
		(idClass == 0 || idClass == lcfs.list[i]->idclass) && 
		(academic == 0 || academic == lcfs.list[i]->academicYear) && 
	    (semester == 0 || semester == lcfs.list[i]->semester)){
			listCancelClass[sizeList] = lcfs.list[i]; // tro truc tiep vao lop
			sizeList += 1;
		}
	}
}
int openClass(listClassForSubject &lcfs, listSubject &lsj, int *academicYear, int &sizeYear, int *semester){
	
	drawOpenClass();
	
	int semesterTemp = 0, sizeSemester = MAXSEMESTER; // de luu lai muc da chon , muc dich ve lai khi bi de
	int selected = 0, run1 = 1, x, y, on = 0, open = 1, currentClass = -1, lineCurrent, cntline, ascii, yearCurrent, status;
	string minStudent = emptyStr, maxStudent = emptyStr, groupTemp = emptyStr, text = emptyStr; char key;
	ptrSubject firstSubject = NULL; 
	
	ptrClassForSubject cfs = new classForSubject; // khoi tao
	
	while(run1){
		
		mouseHighlightOpenClass(on, selected);
		
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	if(ascii == ESC){
	    		if(!createNotice("Ban chac chan muon thoat!", "")){
	    			return currentClass;
				}
				
				on = selected = 0;
				
				drawClassForSubjectManagement(2);
				drawOpenClassForSubject();
				drawOpenClass();
				minStudent = maxStudent = groupTemp = emptyStr;
				cfs->idSubject = emptyStr;
				cfs->academicYear = cfs->group = cfs->semester = cfs->studentMax = cfs->studentMin = semesterTemp = 0;
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			
			switch(selected){
				case 1: // click vao muc ten - ma mon
				
					lineCurrent = 1; cntline = 1;
					firstSubject = NULL; // luu mon hoc hien tai trong danh sach duoc in dam tren man hinh
					
					createListIdSubject();
					if(lsj.root != NULL){ // danh sach rong
						highlightLineCurrent(lineCurrent, LIGHTGRAY);
						findListIdSubject(lsj.root, firstSubject, cntline); // in ra danh sach 8 mon hoc dau tien tren bang
						
						while(run1){
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
									bar(TEXTSPOINTX1, TEXTLPOINTY1 + 1, TEXTLPOINTX1 + 1, TEXTLPOINTY1 + 241);
									bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 + 1, TEXTLPOINTX1, TEXTLPOINTY1);
									cfs->idSubject = firstSubject->data.idSubject;
									
									outtextwithline(0, firstSubject->data, BLACK);
									break;
								}
								else if(ascii == UP){
									if(lineCurrent > 1){
										ptrSubject prevSubject = findPrevSubject(lsj.root, firstSubject);
										if(prevSubject != NULL){
											highlightLineCurrent(lineCurrent, WHITE);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
											
											firstSubject = prevSubject;
											lineCurrent -= 1;
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
										}
									}
									else if(lineCurrent == 1){
										ptrSubject prevSubject = findPrevSubject(lsj.root, firstSubject);
										if(prevSubject != NULL){
											firstSubject = prevSubject;
											
											createListIdSubject();
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, prevSubject->data, BLACK);
											
											lineCurrent += 1;
											
											while(findNextSubject(lsj.root, prevSubject) != NULL && lineCurrent <= 8){
												prevSubject = findNextSubject(lsj.root, prevSubject);
												outtextwithline(lineCurrent, prevSubject->data, BLACK);
												lineCurrent += 1;
											}
											lineCurrent = 1;
										}
									}
								}
								else if(ascii == DOWN){
									if(lineCurrent < 8 && lineCurrent != 0){
										ptrSubject nextSubject = findNextSubject(lsj.root, firstSubject);
										if(nextSubject != NULL){
											highlightLineCurrent(lineCurrent, WHITE);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
											
											firstSubject = nextSubject;
											lineCurrent += 1;
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
										}
									}
									else if(lineCurrent == 8){
										ptrSubject nextSubject = findNextSubject(lsj.root, firstSubject);
										if(nextSubject != NULL){
											firstSubject = nextSubject;
											createListIdSubject();
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, nextSubject->data, BLACK);
											lineCurrent -= 1;
											
											while(findPrevSubject(lsj.root, nextSubject) != NULL && lineCurrent >= 1){
												nextSubject = findPrevSubject(lsj.root, nextSubject);
												outtextwithline(lineCurrent, nextSubject->data, BLACK);
												lineCurrent -= 1;
											}
											lineCurrent = 8;
										}
									}
								}
								else if(ascii == ESC){
									setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX1, TEXTLPOINTY1 + 1, TEXTLPOINTX1 + 1, TEXTLPOINTY1 + 241);
									break;
								}
							}
						}
					}
					break;
				case 2: // click vao muc nien khoa
				
					lineCurrent = 1; //
					yearCurrent = 0;
					
					createListYear();
					if(sizeYear != 0){ // danh sach rong
						highlightLineCurrent2(lineCurrent, LIGHTGRAY);
						findListYear(academicYear, sizeYear); // in ra danh sach 4 nam hoc dau tien
						
						while(run1){
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
									bar(TEXTSPOINTX2, TEXTLPOINTY2 + 1, TEXTLPOINTX2 + 1, TEXTLPOINTY2 + 121);
									bar(TEXTSPOINTX2 + 1, TEXTSPOINTY2 + 1, TEXTLPOINTX2, TEXTLPOINTY2);
									cfs->academicYear = academicYear[yearCurrent];
									
									outtextwithline2(0, academicYear[yearCurrent], BLACK);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX4 + 10, TEXTSPOINTY4 - 25, "Hoc ky");
									
									if(semesterTemp != 0){
										setbkcolor(WHITE);
										outtextwithline4(0, semesterTemp, BLACK);
									}
									break;
								}
								else if(ascii == UP){
									if(lineCurrent > 1){
										if(yearCurrent > 0){
											highlightLineCurrent2(lineCurrent, WHITE);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											yearCurrent -= 1;
											lineCurrent -= 1;
											
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
										}
									}
									else if(lineCurrent == 1){
										if(yearCurrent > 0){
											yearCurrent -= 1;
											
											createListYear();
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											lineCurrent += 1;
											
											int nextYear = yearCurrent;
											while(nextYear < sizeYear - 1 && lineCurrent <= 4){
												nextYear += 1;
												outtextwithline2(lineCurrent, academicYear[nextYear], BLACK);
												lineCurrent += 1;
											}
											lineCurrent = 1;
										}
									}
								}
								else if(ascii == DOWN){
									if(lineCurrent < 4 && lineCurrent != 0){
										if(yearCurrent < sizeYear - 1){ // ton tai phan tu sau no
											highlightLineCurrent2(lineCurrent, WHITE);
											setbkcolor(WHITE);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											yearCurrent += 1;
											lineCurrent += 1;
											
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
										}
									}
									else if(lineCurrent == 4){
										if(yearCurrent < sizeYear - 1){
											yearCurrent += 1;
											
											createListYear();
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											lineCurrent -= 1;
											
											int prevYear = yearCurrent;
											while(prevYear > 0 && lineCurrent >= 1){
												prevYear -= 1;
												outtextwithline2(lineCurrent, academicYear[prevYear], BLACK);
												lineCurrent -= 1;
											}
											lineCurrent = 4;
										}
									}
								}
								else if(ascii == ESC){
									
									setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX2, TEXTLPOINTY2 + 1, TEXTLPOINTX2 + 1, TEXTLPOINTY2 + 121);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX4 + 10, TEXTSPOINTY4 - 25, "Hoc ky");
									
									if(semesterTemp != 0){
										setbkcolor(WHITE);
										outtextwithline4(0, semesterTemp, BLACK);
									}
									break;
								}
							}
						}
					}
					break;
				case 3: // click vao muc so sv toi thieu 
					
					setcolor(BLUE);
					rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
					while(run1){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		if(isSubString(minStudent, "0") || minStudent == emptyStr){
					    			setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "Sinh vien bat buoc phai co!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else if(minStudent != emptyStr && maxStudent != emptyStr && stringtoint(maxStudent) < stringtoint(minStudent)){
									setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "So luong khong phu hop!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else{
									setcolor(LIGHTBLUE);
									rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
									cfs->studentMin = stringtoint(minStudent);
									break;
								}
							}
							if(ascii == BP && (int)minStudent.size() > 0){
								minStudent.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 + 1, TEXTSPOINTY3 + 1, TEXTLPOINTX3, TEXTLPOINTY3);
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTSPOINTX3 + 5, TEXTSPOINTY3 + 10, tochar(minStudent));
							}
							else if(('0' <= ascii && ascii <= '9')){
								if((int)minStudent.size() < 4){
									if((int)minStudent.size() == 0 && key == '0') continue;
									formatKey(key);
									minStudent += key;
									setcolor(BLACK);
									setbkcolor(WHITE);
									outtextxy(TEXTSPOINTX3 + 5, TEXTSPOINTY3 + 10, tochar(minStudent));
								} 
							}
							else if(ascii == ESC){
								
								setcolor(LIGHTBLUE);
								rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
								minStudent = emptyStr;
								cfs->studentMin = 0;
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 + 1, TEXTSPOINTY3 + 1, TEXTLPOINTX3, TEXTLPOINTY3);
								setDefault();
								break;
							}
						}
					}
					
					break;
				case 4: // click vao muc hoc ky
					lineCurrent = 1; //

					createListSemester();
					if(sizeSemester != 0){ // danh sach rong
						highlightLineCurrent4(lineCurrent, LIGHTGRAY);
						findListSemester(semester, MAXSEMESTER); // in ra cac hoc ky;
						
						while(run1){
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
									bar(TEXTSPOINTX4, TEXTLPOINTY4 + 1, TEXTLPOINTX4 + 1, TEXTLPOINTY4 + 91);
									bar(TEXTSPOINTX4 + 1, TEXTSPOINTY4 + 1, TEXTLPOINTX4, TEXTLPOINTY4);
									cfs->semester = semester[lineCurrent - 1];
									semesterTemp = semester[lineCurrent - 1]; // luu lai gia tri
									
									outtextwithline4(0, semester[lineCurrent - 1], BLACK);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX6 + 10, TEXTSPOINTY6 - 25, "Nhom");
									
									if(groupTemp != emptyStr){
										setbkcolor(WHITE);
										outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(groupTemp));
									}
									break;
								}
								else if(ascii == UP){
									if(lineCurrent > 1){ // co the dich chuyen len
										highlightLineCurrent4(lineCurrent, WHITE);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
										
										lineCurrent -= 1;
										
										highlightLineCurrent4(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
									}
								}
								else if(ascii == DOWN){
									if(lineCurrent < 3 && lineCurrent != 0){
										highlightLineCurrent4(lineCurrent, WHITE);
										setbkcolor(WHITE);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
										
										lineCurrent += 1;
										
										highlightLineCurrent4(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
									}
								}
								else if(ascii == ESC){
									
									setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX4, TEXTLPOINTY4 + 1, TEXTLPOINTX4 + 1, TEXTLPOINTY4 + 91);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX6 + 10, TEXTSPOINTY6 - 25, "Nhom");
									
									if(groupTemp != emptyStr){
										setbkcolor(WHITE);
										outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(groupTemp));
									}
									
									break;
								}
							}
						}
					}
					break;
					
				case 5: 
				
					setcolor(BLUE);
					rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
					while(run1){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		if(isSubString(maxStudent, "0") || maxStudent == emptyStr){
					    			setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "Sinh vien bat buoc phai co!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else if(minStudent != emptyStr && maxStudent != emptyStr && stringtoint(maxStudent) < stringtoint(minStudent)){
									setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "So luong khong phu hop!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else{
									setcolor(LIGHTBLUE);
									rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
									cfs->studentMax = stringtoint(maxStudent);
									break;
								}
							}
							if(ascii == BP && (int)maxStudent.size() > 0){
								maxStudent.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX5 + 1, TEXTSPOINTY5 + 1, TEXTLPOINTX5, TEXTLPOINTY5);
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTSPOINTX5 + 5, TEXTSPOINTY5 + 10, tochar(maxStudent));
							}
							else if(('0' <= ascii && ascii <= '9')){
								if((int)maxStudent.size() < 4){
									if((int)maxStudent.size() == 0 && key == '0') continue;
									formatKey(key);
									maxStudent += key;
									setcolor(BLACK);
									setbkcolor(WHITE);
									outtextxy(TEXTSPOINTX5 + 5, TEXTSPOINTY5 + 10, tochar(maxStudent));
								} 
							}
							else if(ascii == ESC){
								setcolor(LIGHTBLUE);
								rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
								maxStudent = emptyStr;
								cfs->studentMax = 0;
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX5 + 1, TEXTSPOINTY5 + 1, TEXTLPOINTX5, TEXTLPOINTY5);
								setDefault();
								break;
							}
						}
					}
					break;
					
				case 6:
					setcolor(BLUE);
					rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
					while(run1){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		
					    		if(isSubString(groupTemp, "0") || groupTemp == emptyStr){
					    			setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "Nhom nam ngoai gioi han!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else{
									setcolor(LIGHTBLUE);
									rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
									cfs->group = stringtoint(groupTemp);
									break;
								}
							}
							if(ascii == BP && (int)groupTemp.size() > 0){
								groupTemp.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX6 + 1, TEXTSPOINTY6 + 1, TEXTLPOINTX6, TEXTLPOINTY6);
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(groupTemp));
							}
							else if(('0' <= ascii && ascii <= '9')){
								if((int)groupTemp.size() < 2){
									if((int)groupTemp.size() == 0 && key == '0') continue;
									formatKey(key);
									groupTemp += key;
									setcolor(BLACK);
									setbkcolor(WHITE);
									outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(groupTemp));
								} 
							}
							else if(ascii == ESC){
								setcolor(LIGHTBLUE);
								rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
								groupTemp = emptyStr;
								cfs->group = 0;
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX6 + 1, TEXTSPOINTY6 + 1, TEXTLPOINTX6, TEXTLPOINTY6);
								setDefault();
								break;
							}
						}
					}
					break;
					
				case 7: // click vao mo lop -> kiem tra lop da co hay chua, neu lop co roi thi thong bao , tat thong bao. neu chua thi add roi thong bao
					open = 1;
					if(isFullInForClass(cfs)){
						drawOpen(open);
						while(run1){
							if(kbhit()){
								key = getch();
								int ascii = static_cast<int>(key);
						        if (ascii == 0) { 
						            key = getch();
						            ascii = static_cast<int>(key);
						            ascii += 255;
						    	}
						    	if(ascii == ET){ 
						    		setfillstyle(SOLID_FILL, WHITE);
						    		bar(OPENSPOINTX - 301, OPENSPOINTY - 60, OPENLPOINTX + 1, OPENLPOINTY - 59);
						    		setDefault();
									break;
								}
								else if(ascii == RIGHT && open == 1){ 
									open -= 1;
									drawOpen(open);
								}
								else if(ascii == LEFT && open == 0){ 
									open += 1;
									drawOpen(open);
								}
							}
						}
						if(open == 1){  // neu classforsubject da du thong tin thi cho phep them
							status = addClassForSubject(lcfs, cfs);
							if(status == -1){ // list class for subject 
								setcolor(LIGHTRED);
								outtextxy(TEXTSPOINTX3, LISTSPOINTY + 60, "Danh sach lop da day!");
								setcolor(BLACK);
								delay(1000);
								setfillstyle(SOLID_FILL, WHITE);
								bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
								setDefault();
							}
							else if(status == 0){
								setcolor(LIGHTRED);
								outtextxy(TEXTSPOINTX3, LISTSPOINTY + 60, "Nhom da ton tai!");
								setcolor(BLACK);
								delay(1000);
								setfillstyle(SOLID_FILL, WHITE);
								bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
								setDefault();
							}
							else{
								setcolor(LIGHTGREEN);
								text = "Da mo lop tin chi voi Ma:" + formatIdClass(cfs->idclass);
								outtextxy(TEXTSPOINTX3 - 50, LISTSPOINTY + 60, tochar(text));
								setcolor(BLACK);
								delay(2000);
								setfillstyle(SOLID_FILL, WHITE);
								bar(BOXLPOINTX + 100, LISTSPOINTY + 60, BOXLPOINTX + 700, LISTSPOINTY + 90);
								setDefault();
							}
						}
					}
					break;
			}
		}
	}
}


void editClass(listClassForSubject &lcfs, listSubject &lsj, int* academicYear, int sizeYear, int *semester, int currentClass){
	
	drawEditClass();
	
	// khai bao 
	int sizeSemester = MAXSEMESTER;
	int run1 = 1, on = 0, ascii = 0, selected = 0, lineCurrent, cntline, yearCurrent, status, edit, x, y;
	
//	string idSubject = lcfs.list[currentClass]->idSubject;
//	int academicYear = lcfs.list[currentClass]->academicYear;
	int semesterTemp = lcfs.list[currentClass]->semester;
	
	string group = to_string(lcfs.list[currentClass]->group); 
	string minStudent = to_string(lcfs.list[currentClass]->studentMin); 
	string maxStudent = to_string(lcfs.list[currentClass]->studentMax);
	
	ptrClassForSubject cfs = new classForSubject;
	*cfs = *lcfs.list[currentClass];
	ptrSubject firstSubject = NULL;
	
	char key;
	
	string nameSubject = findNameSubject(cfs->idSubject, lsj.root);
	string text = cfs->idSubject + "-" + nameSubject;
	
	setcolor(BLACK);
	outtextxy(TEXTSPOINTX1 + 5, TEXTSPOINTY1 + 10, tochar(text));
	outtextxy(TEXTSPOINTX2 + 5, TEXTSPOINTY2 + 10, tochar(to_string(cfs->academicYear)));
	outtextxy(TEXTSPOINTX3 + 5, TEXTSPOINTY3 + 10, tochar(minStudent));
	outtextxy(TEXTSPOINTX4 + 5, TEXTSPOINTY4 + 10, tochar("Hoc ky " + to_string(cfs->semester)));
	outtextxy(TEXTSPOINTX5 + 5, TEXTSPOINTY5 + 10, tochar(maxStudent));
	outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(group));
	
	while(run1){
		
		mouseHighlightEditClass(on, selected);
		
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
				
				on = selected = 0;
				
				minStudent = maxStudent = group = emptyStr;
				cfs->idSubject = emptyStr;
				cfs->academicYear = cfs->group = cfs->semester = cfs->studentMax = cfs->studentMin = 0;
				
				drawClassForSubjectManagement(2);
				drawOpenClassForSubject();
				drawEditClass();
				
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			
			switch(selected){
				case 1:  // click vao ma mon - ten mon 
					lineCurrent = 1; cntline = 1;
					firstSubject = NULL; // luu mon hoc hien tai trong danh sach duoc in dam tren man hinh
					
					createListIdSubject();
					if(lsj.root != NULL){ // danh sach rong
						highlightLineCurrent(lineCurrent, LIGHTGRAY);
						findListIdSubject(lsj.root, firstSubject, cntline); // in ra danh sach 8 mon hoc dau tien tren bang
						
						while(run1){
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
									bar(TEXTSPOINTX1, TEXTLPOINTY1 + 1, TEXTLPOINTX1 + 1, TEXTLPOINTY1 + 241);
									bar(TEXTSPOINTX1 + 1, TEXTSPOINTY1 + 1, TEXTLPOINTX1, TEXTLPOINTY1);
									cfs->idSubject = firstSubject->data.idSubject;
									
									outtextwithline(0, firstSubject->data, BLACK);
									break;
								}
								else if(ascii == UP){
									if(lineCurrent > 1){
										ptrSubject prevSubject = findPrevSubject(lsj.root, firstSubject);
										if(prevSubject != NULL){
											highlightLineCurrent(lineCurrent, WHITE);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
											
											firstSubject = prevSubject;
											lineCurrent -= 1;
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
										}
									}
									else if(lineCurrent == 1){
										ptrSubject prevSubject = findPrevSubject(lsj.root, firstSubject);
										if(prevSubject != NULL){
											firstSubject = prevSubject;
											
											createListIdSubject();
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, prevSubject->data, BLACK);
											
											lineCurrent += 1;
											
											while(findNextSubject(lsj.root, prevSubject) != NULL && lineCurrent <= 8){
												prevSubject = findNextSubject(lsj.root, prevSubject);
												outtextwithline(lineCurrent, prevSubject->data, BLACK);
												lineCurrent += 1;
											}
											lineCurrent = 1;
										}
									}
								}
								else if(ascii == DOWN){
									if(lineCurrent < 8 && lineCurrent != 0){
										ptrSubject nextSubject = findNextSubject(lsj.root, firstSubject);
										if(nextSubject != NULL){
											highlightLineCurrent(lineCurrent, WHITE);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
											
											firstSubject = nextSubject;
											lineCurrent += 1;
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, firstSubject->data, BLACK);
										}
									}
									else if(lineCurrent == 8){
										ptrSubject nextSubject = findNextSubject(lsj.root, firstSubject);
										if(nextSubject != NULL){
											firstSubject = nextSubject;
											createListIdSubject();
											highlightLineCurrent(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline(lineCurrent, nextSubject->data, BLACK);
											lineCurrent -= 1;
											
											while(findPrevSubject(lsj.root, nextSubject) != NULL && lineCurrent >= 1){
												nextSubject = findPrevSubject(lsj.root, nextSubject);
												outtextwithline(lineCurrent, nextSubject->data, BLACK);
												lineCurrent -= 1;
											}
											lineCurrent = 8;
										}
									}
								}
								else if(ascii == ESC){
									setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX1, TEXTLPOINTY1 + 1, TEXTLPOINTX1 + 1, TEXTLPOINTY1 + 241);
									break;
								}
							}
						}
					}
					break;
					
				case 2: 
					 // click vao muc nien khoa
				
					lineCurrent = 1; //
					yearCurrent = 0;
					
					createListYear();
					if(sizeYear != 0){ // danh sach rong
						highlightLineCurrent2(lineCurrent, LIGHTGRAY);
						findListYear(academicYear, sizeYear); // in ra danh sach 4 nam hoc dau tien
						
						while(run1){
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
									bar(TEXTSPOINTX2, TEXTLPOINTY2 + 1, TEXTLPOINTX2 + 1, TEXTLPOINTY2 + 121);
									bar(TEXTSPOINTX2 + 1, TEXTSPOINTY2 + 1, TEXTLPOINTX2, TEXTLPOINTY2);
									cfs->academicYear = academicYear[yearCurrent];
									
									outtextwithline2(0, academicYear[yearCurrent], BLACK);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX4 + 10, TEXTSPOINTY4 - 25, "Hoc ky");
									
									if(semesterTemp != 0){
										setbkcolor(WHITE);
										outtextwithline4(0, semesterTemp, BLACK);
									}
									break;
								}
								else if(ascii == UP){
									if(lineCurrent > 1){
										if(yearCurrent > 0){
											highlightLineCurrent2(lineCurrent, WHITE);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											yearCurrent -= 1;
											lineCurrent -= 1;
											
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
										}
									}
									else if(lineCurrent == 1){
										if(yearCurrent > 0){
											yearCurrent -= 1;
											
											createListYear();
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											lineCurrent += 1;
											
											int nextYear = yearCurrent;
											while(nextYear < sizeYear - 1 && lineCurrent <= 4){
												nextYear += 1;
												outtextwithline2(lineCurrent, academicYear[nextYear], BLACK);
												lineCurrent += 1;
											}
											lineCurrent = 1;
										}
									}
								}
								else if(ascii == DOWN){
									if(lineCurrent < 4 && lineCurrent != 0){
										if(yearCurrent < sizeYear - 1){ // ton tai phan tu sau no
											highlightLineCurrent2(lineCurrent, WHITE);
											setbkcolor(WHITE);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											yearCurrent += 1;
											lineCurrent += 1;
											
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
										}
									}
									else if(lineCurrent == 4){
										if(yearCurrent < sizeYear - 1){
											yearCurrent += 1;
											
											createListYear();
											highlightLineCurrent2(lineCurrent, LIGHTGRAY);
											setbkcolor(LIGHTGRAY);
											outtextwithline2(lineCurrent, academicYear[yearCurrent], BLACK);
											
											lineCurrent -= 1;
											
											int prevYear = yearCurrent;
											while(prevYear > 0 && lineCurrent >= 1){
												prevYear -= 1;
												outtextwithline2(lineCurrent, academicYear[prevYear], BLACK);
												lineCurrent -= 1;
											}
											lineCurrent = 4;
										}
									}
								}
								else if(ascii == ESC){
									
									setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX2, TEXTLPOINTY2 + 1, TEXTLPOINTX2 + 1, TEXTLPOINTY2 + 121);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX4 + 10, TEXTSPOINTY4 - 25, "Hoc ky");
									
									if(semesterTemp != 0){
										setbkcolor(WHITE);
										outtextwithline4(0, semesterTemp, BLACK);
									}
									break;
								}
							}
						}
					}
					break;
				case 3: // click vao muc so sv toi thieu 
					
					setcolor(BLUE);
					rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
					while(run1){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		if(isSubString(minStudent, "0") || minStudent == emptyStr){
					    			setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "Sinh vien bat buoc phai co!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else if(minStudent != emptyStr && maxStudent != emptyStr && stringtoint(maxStudent) < stringtoint(minStudent)){
									setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "So luong khong phu hop!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else{
									setcolor(LIGHTBLUE);
									rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
									cfs->studentMin = stringtoint(minStudent);
									break;
								}
							}
							if(ascii == BP && (int)minStudent.size() > 0){
								minStudent.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 + 1, TEXTSPOINTY3 + 1, TEXTLPOINTX3, TEXTLPOINTY3);
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTSPOINTX3 + 5, TEXTSPOINTY3 + 10, tochar(minStudent));
							}
							else if(('0' <= ascii && ascii <= '9')){
								if((int)minStudent.size() < 4){
									if((int)minStudent.size() == 0 && key == '0') continue;
									formatKey(key);
									minStudent += key;
									setcolor(BLACK);
									setbkcolor(WHITE);
									outtextxy(TEXTSPOINTX3 + 5, TEXTSPOINTY3 + 10, tochar(minStudent));
								} 
							}
							else if(ascii == ESC){
								
								setcolor(LIGHTBLUE);
								rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
								minStudent = emptyStr;
								cfs->studentMin = 0;
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX3 + 1, TEXTSPOINTY3 + 1, TEXTLPOINTX3, TEXTLPOINTY3);
								setDefault();
								break;
							}
						}
					}
					
					break;
				
				case 4: // click vao muc hoc ky
					lineCurrent = 1; //

					createListSemester();
					if(sizeSemester != 0){ // danh sach rong
						highlightLineCurrent4(lineCurrent, LIGHTGRAY);
						findListSemester(semester, MAXSEMESTER); // in ra cac hoc ky;
						
						while(run1){
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
									bar(TEXTSPOINTX4, TEXTLPOINTY4 + 1, TEXTLPOINTX4 + 1, TEXTLPOINTY4 + 91);
									bar(TEXTSPOINTX4 + 1, TEXTSPOINTY4 + 1, TEXTLPOINTX4, TEXTLPOINTY4);
									cfs->semester = semester[lineCurrent - 1];
									semesterTemp = semester[lineCurrent - 1]; // luu lai gia tri
									
									outtextwithline4(0, semester[lineCurrent - 1], BLACK);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX6 + 10, TEXTSPOINTY6 - 25, "Nhom");
									
									if(group != emptyStr){
										setbkcolor(WHITE);
										outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(group));
									}
									break;
								}
								else if(ascii == UP){
									if(lineCurrent > 1){ // co the dich chuyen len
										highlightLineCurrent4(lineCurrent, WHITE);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
										
										lineCurrent -= 1;
										
										highlightLineCurrent4(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
									}
								}
								else if(ascii == DOWN){
									if(lineCurrent < 3 && lineCurrent != 0){
										highlightLineCurrent4(lineCurrent, WHITE);
										setbkcolor(WHITE);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
										
										lineCurrent += 1;
										
										highlightLineCurrent4(lineCurrent, LIGHTGRAY);
										setbkcolor(LIGHTGRAY);
										outtextwithline4(lineCurrent, semester[lineCurrent - 1], BLACK);
									}
								}
								else if(ascii == ESC){
									
									setfillstyle(SOLID_FILL, WHITE);
									bar(TEXTSPOINTX4, TEXTLPOINTY4 + 1, TEXTLPOINTX4 + 1, TEXTLPOINTY4 + 91);
									
									setcolor(LIGHTGRAY);
									rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
									
									setbkcolor(WHITE);
									setcolor(BLACK);
									outtextxy(TEXTSPOINTX6 + 10, TEXTSPOINTY6 - 25, "Nhom");
									
									if(group != emptyStr){
										setbkcolor(WHITE);
										outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(group));
									}
									
									break;
								}
							}
						}
					}
					break;
					
					
				case 5: 
				
					setcolor(BLUE);
					rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
					while(run1){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		if(isSubString(maxStudent, "0") || maxStudent == emptyStr){
					    			setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "Sinh vien bat buoc phai co!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else if(minStudent != emptyStr && maxStudent != emptyStr && stringtoint(maxStudent) < stringtoint(minStudent)){
									setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "So luong khong phu hop!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else{
									setcolor(LIGHTBLUE);
									rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
									cfs->studentMax = stringtoint(maxStudent);
									break;
								}
							}
							if(ascii == BP && (int)maxStudent.size() > 0){
								maxStudent.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX5 + 1, TEXTSPOINTY5 + 1, TEXTLPOINTX5, TEXTLPOINTY5);
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTSPOINTX5 + 5, TEXTSPOINTY5 + 10, tochar(maxStudent));
							}
							else if(('0' <= ascii && ascii <= '9')){
								if((int)maxStudent.size() < 4){
									if((int)maxStudent.size() == 0 && key == '0') continue;
									formatKey(key);
									maxStudent += key;
									setcolor(BLACK);
									setbkcolor(WHITE);
									outtextxy(TEXTSPOINTX5 + 5, TEXTSPOINTY5 + 10, tochar(maxStudent));
								} 
							}
							else if(ascii == ESC){
								setcolor(LIGHTBLUE);
								rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
								maxStudent = emptyStr;
								cfs->studentMax = 0;
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX5 + 1, TEXTSPOINTY5 + 1, TEXTLPOINTX5, TEXTLPOINTY5);
								setDefault();
								break;
							}
						}
					}
					break;
					
				case 6:
					setcolor(BLUE);
					rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
					while(run1){
						if(kbhit()){
							key = getch();
							ascii = static_cast<int>(key);
					        if (ascii == 0) { 
					            key = getch();
					            ascii = static_cast<int>(key);
					            ascii += 255;
					    	}
					    	
					    	if(ascii == ET){
					    		
					    		if(isSubString(group, "0") || group == emptyStr){
					    			setcolor(LIGHTRED);
									outtextxy(BOXLPOINTX + 200, LISTSPOINTY + 60, "Nhom nam ngoai gioi han!");
									setcolor(BLACK);
									delay(1000);
									setfillstyle(SOLID_FILL, WHITE);
									bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
									setDefault();	
								}
								else{
									setcolor(LIGHTBLUE);
									rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
									cfs->group = stringtoint(group);
									break;
								}
							}
							if(ascii == BP && (int)group.size() > 0){
								group.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX6 + 1, TEXTSPOINTY6 + 1, TEXTLPOINTX6, TEXTLPOINTY6);
								setcolor(BLACK);
								setbkcolor(WHITE);
								outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(group));
							}
							else if(('0' <= ascii && ascii <= '9')){
								if((int)group.size() < 2){
									if((int)group.size() == 0 && key == '0') continue;
									formatKey(key);
									group += key;
									setcolor(BLACK);
									setbkcolor(WHITE);
									outtextxy(TEXTSPOINTX6 + 5, TEXTSPOINTY6 + 10, tochar(group));
								} 
							}
							else if(ascii == ESC){
								setcolor(LIGHTBLUE);
								rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
								group = emptyStr;
								cfs->group = 0;
								setfillstyle(SOLID_FILL, WHITE);
								bar(TEXTSPOINTX6 + 1, TEXTSPOINTY6 + 1, TEXTLPOINTX6, TEXTLPOINTY6);
								setDefault();
								break;
							}
						}
					}
					break;
					
				case 7: // click vao  hoan tat
					edit = 1;
					if(isFullInForClass(cfs)){
						drawEdit(edit);
						while(run1){
							if(kbhit()){
								key = getch();
								int ascii = static_cast<int>(key);
						        if (ascii == 0) { 
						            key = getch();
						            ascii = static_cast<int>(key);
						            ascii += 255;
						    	}
						    	if(ascii == ET){ 
						    		setfillstyle(SOLID_FILL, WHITE);
						    		bar(OPENSPOINTX - 301, OPENSPOINTY - 60, OPENLPOINTX + 1, OPENLPOINTY - 59);
						    		setDefault();
									break;
								}
								else if(ascii == RIGHT && edit == 1){ 
									edit -= 1;
									drawEdit(edit);
								}
								else if(ascii == LEFT && edit == 0){ 
									edit += 1;
									drawEdit(edit);
								}
							}
						}
						if(edit == 1){  // neu classforsubject da du thong tin thi cho phep them
							status = updateClassForSubject(lcfs, cfs, currentClass);
							if(status == 0){
								setcolor(LIGHTRED);
								outtextxy(TEXTSPOINTX3, LISTSPOINTY + 60, "Nhom da ton tai!");
								setcolor(BLACK);
								delay(1000);
								setfillstyle(SOLID_FILL, WHITE);
								bar(BOXLPOINTX + 200, LISTSPOINTY + 60, BOXLPOINTX + 500, LISTSPOINTY + 90);
								setDefault();
							}
							else{
								setcolor(LIGHTGREEN);
								text = "Da chinh sua lop tin chi!";
								outtextxy(TEXTSPOINTX3, LISTSPOINTY + 60, tochar(text));
								setcolor(BLACK);
								delay(1500);
								setfillstyle(SOLID_FILL, WHITE);
								bar(BOXLPOINTX + 100, LISTSPOINTY + 60, BOXLPOINTX + 700, LISTSPOINTY + 90);
								setDefault();
								
								return;
								
							}
						}
					}
					break;
			}
		}
	}
}

void deleteClass(listClassForSubject &lcfs, int currentClass){
	int dele = 1, ascii, run = 1, status;
	
	drawDelete(dele);
	
	char key; string text;
	
	while(run){
		if(kbhit()){
			key = getch();
			int ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
	    	if(ascii == ET){ 
	    		setfillstyle(SOLID_FILL, WHITE);
	    		bar(OPENSPOINTX - 301, OPENSPOINTY - 60, OPENLPOINTX + 50, OPENLPOINTY - 59);
	    		setDefault();
				break;
			}
			else if(ascii == RIGHT && dele == 1){ 
				dele -= 1;
				drawDelete(dele);
			}
			else if(ascii == LEFT && dele == 0){ 
				dele += 1;
				drawDelete(dele);
			}
		}
	}
	
	if(dele == 1){ // thuc hien xoa
		deleteClassForSubject(lcfs, currentClass);
		return;
	}
}

void cancelClass(listClassForSubject &lcfs, listSubject &lsj){

	ptrClassForSubject listCancelClass[MAXCLASS]; // mang chua danh sach cac lop co kha nang huy (sinh vien dang ky < sinh vien toi thieu)
	int sizeList = 0, currentClass = 0, temp = 0, cntSelected = 0, cancel = 0, on = 0, on2 = 0, selected = 0;
	bool markClass[MAXCLASS];
	
	int idClass = 0, academic = 0, semester = 0;
	string idClassTemp = emptyStr, academicTemp = emptyStr, semesterTemp = emptyStr;
	
	getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester); // loc ket qua vao mang
	
	// in ra thong tin lop 
	drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
	int x, y, ascii; char key; string text;
	
	
	while(true){
		
		mouseHighlightCancelClass2(on2, selected);
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
	    			if(currentClass - 10 >= 0  && currentClass < sizeList){
	    				currentClass -= 10;
	    				drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					}
	    			break;
	    		case DOWN:
	    			if(currentClass + 10 < sizeList){
	    				currentClass += 10;
	    				drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					}
	    			break;
	    		case ESC: // xoa man hinh va return
	    			if(createNotice("Chac chan muon thoat!", "")){ // tiep tuc chuong trinh
	    				drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
	    				outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
						outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
						outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
					}
					else{
						setfillstyle(SOLID_FILL, WHITE);
						bar(LISTSPOINTX + 40, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 5);	// xoa man hinh
						cntSelected = 0;
						memset(markClass, false, sizeof(markClass));
						return;
					}
					break;
			}
		}
	
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 85, LISTLPOINTX - 20, LISTSPOINTY + 105)){ // click vao o huy lop 1
				temp = currentClass;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 115, LISTLPOINTX - 20, LISTSPOINTY + 135)){ // click vao o huy lop 2 ...
				temp = currentClass + 1;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 145, LISTLPOINTX - 20, LISTSPOINTY + 165)){ // 3
				temp = currentClass + 2;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 175, LISTLPOINTX - 20, LISTSPOINTY + 195)){ // 4
				temp = currentClass + 3;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 205, LISTLPOINTX - 20, LISTSPOINTY + 225)){ // 5
				temp = currentClass + 4;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 235, LISTLPOINTX - 20, LISTSPOINTY + 255)){ // 6
				temp = currentClass + 5;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 265, LISTLPOINTX - 20, LISTSPOINTY + 285)){ // 7
				temp = currentClass + 6;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 295, LISTLPOINTX - 20, LISTSPOINTY + 315)){  // 8
				temp = currentClass + 7;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 325, LISTLPOINTX - 20, LISTSPOINTY + 345)){ // 9
				temp = currentClass + 8;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTLPOINTX - 45, LISTSPOINTY + 355, LISTLPOINTX - 20, LISTSPOINTY + 375)){ // 10
				temp = currentClass + 9;
				if(temp < sizeList && markClass[temp] == false){
					markClass[temp] = true;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected += 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
				else if(temp < sizeList){
					markClass[temp] = false;
					drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
					cntSelected -= 1;
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
					outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 750, LISTSPOINTY + 460, LISTSPOINTX + 960, LISTSPOINTY + 500)){ // click de huy cac lop da chon
				drawCancel(cancel, cntSelected); // tao muc chon yes / no neu cntSelected > 0
				while(cntSelected != 0){
					mouseHighlightCancelClass(on, cancel);
					if(kbhit()){
					}
					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN, x, y);
						clearmouseclick(WM_LBUTTONDOWN);
						if(clickInRange(x, y, OPENSPOINTX + 40, OPENSPOINTY - 60, OPENSPOINTX + 135, OPENLPOINTY - 60)){ // chan chan huy lop
							for(int i = 0; i < sizeList; i++){
								if(markClass[i] == true){ // chi muc i cua ListCancelClass da bi danh dau
									listCancelClass[i]->unClass = true;
								}
							}
							setfillstyle(SOLID_FILL, WHITE);
							bar(OPENSPOINTX - 300, OPENSPOINTY - 60, OPENSPOINTX + 260, OPENLPOINTY - 59); // xoa muc yes / no
							
							// tao lai danh sach lop co the huy ngoai tru cac lop da huy
							for(int i = 0; i < sizeList; i++){
								listCancelClass[i] = NULL;
							}
							sizeList = 0;
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester);
							
							// bo danh dau, ve lai danh sach ngoai tru cac lop da huy
							memset(markClass, false, sizeof(markClass));
							currentClass = 0; cntSelected = 0; cancel = 0; on = 0;
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							
							text = "Da huy lop thanh cong!";
							setbkcolor(WHITE);
							setcolor(LIGHTRED);
							outtextxy(OPENSPOINTX, OPENSPOINTY - 50, tochar(text));
							delay(1500);
							
							setfillstyle(SOLID_FILL, WHITE);
							bar(OPENSPOINTX - 300, OPENSPOINTY - 55, OPENSPOINTX + 300, OPENSPOINTY);
							//
							break;
						}
						else if(clickInRange(x, y, OPENSPOINTX + 155, OPENSPOINTY - 60, OPENSPOINTX + 255, OPENLPOINTY - 60)){ // khong huy 
							setfillstyle(SOLID_FILL, WHITE);
							bar(OPENSPOINTX - 300, OPENSPOINTY - 60, OPENSPOINTX + 260, OPENLPOINTY - 59); // xoa muc yes/ no
							
							on = 0; cancel = 0;
							break;
						}
					}
				}
				
			}
			else if(clickInRange(x, y, LISTSPOINTX + 520, LISTSPOINTY + 460, LISTSPOINTX + 730, LISTSPOINTY + 500)){ // click de huy TAT CA cac lop 
				drawCancelAllClass(sizeList);
				while(sizeList != 0){
					mouseHighlightCancelClass(on, cancel);
					if(kbhit()){

					}

					if(ismouseclick(WM_LBUTTONDOWN)){
						getmouseclick(WM_LBUTTONDOWN, x, y);
						clearmouseclick(WM_LBUTTONDOWN);
						if(clickInRange(x, y, OPENSPOINTX + 40, OPENSPOINTY - 60, OPENSPOINTX + 135, OPENLPOINTY - 60)){ // chan chan huy lop
							for(int i = 0; i < sizeList; i++){
								listCancelClass[i]->unClass = true; // huy tat ca lop
							}
							setfillstyle(SOLID_FILL, WHITE);
							bar(OPENSPOINTX - 300, OPENSPOINTY - 60, OPENSPOINTX + 260, OPENLPOINTY - 59); // xoa muc yes / no
							
							// tao lai danh sach lop co the huy ngoai tru cac lop da huy
							for(int i = 0; i < sizeList; i++){
								listCancelClass[i] = NULL;
							}
							sizeList = 0; cntSelected;
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester);
							
							// bo danh dau, ve lai danh sach ngoai tru cac lop da huy
							memset(markClass, false, sizeof(markClass));
							currentClass = 0; cntSelected = 0; cancel = 0; on = 0;
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass);
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							
							text = "Da huy lop thanh cong!";
							setbkcolor(WHITE);
							setcolor(LIGHTRED);
							outtextxy(OPENSPOINTX, OPENSPOINTY - 50, tochar(text));
							delay(1500);
							
							setfillstyle(SOLID_FILL, WHITE);
							bar(OPENSPOINTX - 300, OPENSPOINTY - 55, OPENSPOINTX + 300, OPENSPOINTY);
							//
							break;
						}
						else if(clickInRange(x, y, OPENSPOINTX + 155, OPENSPOINTY - 60, OPENSPOINTX + 255, OPENLPOINTY - 60)){ // khong huy 
							setfillstyle(SOLID_FILL, WHITE);
							bar(OPENSPOINTX - 300, OPENSPOINTY - 60, OPENSPOINTX + 260, OPENLPOINTY - 59); // xoa muc yes/ no
							
							on = 0; cancel = 0;
							break;
						}
					}
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430)){ // muc nhap ma lop
				setcolor(LIGHTBLUE);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to muc nhap thanh mau xanh
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
				    		
				    		setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to muc nhap thanh mau den
							
							idClass = stringtoint(idClassTemp);
							currentClass = 0; cntSelected = 0;
							
							memset(markClass, false, sizeof(markClass));
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass); 
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							break;
						}
						else if(ascii == ESC){
							idClassTemp = emptyStr; idClass = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 429); // xoa noi dung da nhap
							
							setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to muc nhap thanh mau den
							
							currentClass = 0; cntSelected = 0;
							
							memset(markClass, false, sizeof(markClass));
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass); 
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							break;
						}
						else if(ascii == BP){
							if(idClassTemp != emptyStr){
								idClassTemp.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 429); // xoa noi dung cu
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp)); // hien noi dung moi
							}
						}
						else if('0' <= ascii && ascii <= '9'){
							if(idClassTemp.size() < 10){
								if(idClassTemp.size() == 0 && ascii == '0') continue;
								idClassTemp += key;
								
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							}
						}
					}
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470)){ // muc nhap nien khoa
				setcolor(LIGHTBLUE);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470); // to muc nhap thanh mau xanh
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
				    		
				    		setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470); // to muc nhap thanh mau den
							
							academic = stringtoint(academicTemp);
							currentClass = 0; cntSelected = 0;
							
							memset(markClass, false, sizeof(markClass));
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass); // tim kiem danh sach theo idClass
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							break;
						}
						else if(ascii == ESC){
							academicTemp = emptyStr; academic = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(LISTSPOINTX + 151, LISTSPOINTY + 441, LISTSPOINTX + 340, LISTSPOINTY + 469); // xoa noi dung da nhap
							
							setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470); // to muc nhap thanh mau den
							
							currentClass = 0; cntSelected = 0;
							
							memset(markClass, false, sizeof(markClass));
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo academic
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass); 
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							break;
						}
						else if(ascii == BP){
							if(academicTemp != emptyStr){
								academicTemp.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX + 151, LISTSPOINTY + 441, LISTSPOINTX + 340, LISTSPOINTY + 469); // xoa noi dung cu
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp)); // hien noi dung moi
							}
						}
						else if('0' <= ascii && ascii <= '9'){
							if(academicTemp.size() < 4){
								if(academicTemp.size() == 0 && ascii == '0') continue;
								academicTemp += key;
								
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							}
						}
					}
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510)){ // muc nhap hoc ki
				setcolor(LIGHTBLUE);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510); // to muc nhap thanh mau xanh
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
				    		setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510); // to muc nhap thanh mau den
							
							semester = stringtoint(semesterTemp);
							currentClass = 0; cntSelected = 0;
							
							memset(markClass, false, sizeof(markClass));
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass4
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass); // tim kiem danh sach theo idClass
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							break;
						}
						else if(ascii == ESC){
							semesterTemp = emptyStr; semester = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(LISTSPOINTX + 151, LISTSPOINTY + 481, LISTSPOINTX + 340, LISTSPOINTY + 509); // xoa noi dung da nhap
							
							setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510); // to muc nhap thanh mau den
							
							currentClass = 0; cntSelected = 0;
							
							memset(markClass, false, sizeof(markClass));
							getListCancelClass(listCancelClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawListCancelClass(listCancelClass, sizeList, currentClass, lsj, markClass); 
							
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							break;
						}
						else if(ascii == BP){
							if(semesterTemp != emptyStr){
								semesterTemp.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX + 151, LISTSPOINTY + 481, LISTSPOINTX + 340, LISTSPOINTY + 509); // xoa noi dung cu
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp)); // hien noi dung moi
							}
						}
						else if('0' <= ascii && ascii <= '9'){
							if(semesterTemp.size() < 1){
								if(semesterTemp.size() == 0 && ascii == '0') continue;
								semesterTemp += key;
								
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							}
						}
					}
				}
			}
		}
	}
}

void openClassForSubject(listClassForSubject &lcfs, listSubject &lsj){
	drawOpenClassForSubject();
	// khai bao, tien xu ly;
	int sizeYear = 0, sizeSemester = MAXSEMESTER;
	int *academicYear = new int[MAXYEAR];
	readListYear(academicYear, sizeYear);
	
	int *semester = new int[MAXSEMESTER]; 
	for(int i = 0; i < MAXSEMESTER; i++){
		semester[i] = i + 1;
	} 
	
	int currentClass = 0, row = 0;
	char key; string idClass = emptyStr, text = emptyStr;
	int ascii, selected = 1, mouseSelected = 0, finded = 0, x, y, on = 0, off = 1; // off de kiem tra : neu tat ca cac muc deu tat thi off = 1
	drawListClassForSubject(lcfs, lsj, currentClass, row); // in ra thong tin cac lop tin chi, to dam muc duoc chon

	highlightOpenClass(selected, LIGHTBLUE);
	while(true){
		mouseHighlightOpenClassForSubject(on, mouseSelected, selected);
		if(on == 0 && off == 1){
			highlightOpenClass(selected, LIGHTBLUE);
			off = 0; 
		}
		if(on == 1 && off == 0){
			off = 1;
		}
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
			switch(ascii){
				case ET: 
					if(mouseSelected == 0 || mouseSelected == selected || mouseSelected == 5){ // neu tro chuot vao cung voi muc dang chon tu phim left right hoac la tro chuot tro ra ngoai thi cho phep enter
						switch(selected){
							case 1: // chuc nang mo lop 
								openClass(lcfs, lsj, academicYear, sizeYear, semester);
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 5); // 
								
								setcolor(BLACK);
								rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
								
								idClass = emptyStr;
								finded = 0; currentClass = 0; row = 0; selected = 1;
								
								drawClassForSubjectManagement(1);
								drawOpenClassForSubject();
								drawListClassForSubject(lcfs, lsj, currentClass, row);
								highlightOpenClass(selected, LIGHTBLUE);
								break;
							case 2: // chuc nang sua lop
								if(lcfs.size != 0 && !existStudentRegisting(lcfs, currentClass)){ // lr : listRegister; ton tai sinh vien co diem
	
									editClass(lcfs, lsj, academicYear, sizeYear, semester, currentClass);
								
									setfillstyle(SOLID_FILL, WHITE);
									bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 5); // 
									
									setcolor(BLACK);
									rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
									
									idClass = emptyStr;
									selected = 2; finded = 0;
									
									drawClassForSubjectManagement(1);
									drawOpenClassForSubject();
									drawListClassForSubject(lcfs, lsj, currentClass, row);
									highlightOpenClass(selected, LIGHTBLUE);
								}
								else{
									text = "Sinh vien da co diem, Khong the sua!"; 
									setbkcolor(WHITE);
									setcolor(LIGHTRED);
									outtextxy(OPENSPOINTX - 300, OPENSPOINTY - 50, tochar(text));
									Sleep(1000);
									setfillstyle(SOLID_FILL, WHITE);
					    			bar(OPENSPOINTX - 301, OPENSPOINTY - 60, OPENLPOINTX + 50, OPENLPOINTY - 59);
					    			setDefault();
								}
							break;
							case 3: // chuc nang xoa lop
								if(lcfs.size != 0 && !existStudentHaveGrade(lcfs.list[currentClass]->lr)){ // lop hien tai khong co sinh vien dang ky
									deleteClass(lcfs, currentClass);
									
									setfillstyle(SOLID_FILL, WHITE);
									bar(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // 
									
									setcolor(BLACK);
									rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
									
									idClass = emptyStr;
									selected = 3; finded = 0;
									
									if(currentClass == lcfs.size){
										currentClass -= 1;
										row = max(row - 1, 0);
									}
									
									if(lcfs.size == 0){
										finded = 1; 
										selected = 1;
										highlightOpenClass(selected, LIGHTBLUE);
										
										setfillstyle(SOLID_FILL, WHITE);
										bar(LISTSPOINTX + 41, LISTSPOINTY + 81, LISTLPOINTX, LISTSPOINTY + 389); // xoa du lieu trong bang
										
										setcolor(LIGHTGRAY);
										setbkcolor(WHITE);
										outtextxy(LISTSPOINTX + 400, LISTSPOINTY + 85, "Khong co du lieu ..."); 
										
										setDefault();
									}
									else{
										drawListClassForSubject(lcfs, lsj, currentClass, row);
										highlightOpenClass(selected, LIGHTBLUE);
									}
								}
								else{
									text = "Sinh vien da co diem, Khong the xoa!"; 
									setbkcolor(WHITE);
									setcolor(LIGHTRED);
									outtextxy(OPENSPOINTX - 300, OPENSPOINTY - 50, tochar(text));
									Sleep(1000);
									setfillstyle(SOLID_FILL, WHITE);
					    			bar(OPENSPOINTX - 301, OPENSPOINTY - 60, OPENLPOINTX + 50, OPENLPOINTY - 59);
					    			setDefault();
								}
							break;
							case 4: // chuc nang huy lop 
								if(lcfs.size != 0){ // so luong sinh vien dang ky > min
									cancelClass(lcfs, lsj);
									
									drawOpenClassForSubject();
									drawListClassForSubject(lcfs, lsj, currentClass, row);
									highlightOpenClass(selected, LIGHTBLUE);
									setDefault();
								}
							break;
						}
					}
					break;
				case UP:
					if(finded == 0){ // neu da tim kiem thi khong the up / down
						if(row > 0){
							row -= 1;
							currentClass -= 1;
							drawListClassForSubject(lcfs, lsj, currentClass, row); // giu trang thai, to mau muc khac
						}
						else if(currentClass > 0){
							currentClass -= 1;
							drawListClassForSubject(lcfs, lsj, currentClass, row);  // thay doi trang thai, giu muc hien tai
						}
					}
					break;
				case DOWN:
					if(finded == 0){
						if(row < 9 && currentClass < lcfs.size - 1){
							row += 1;
							currentClass += 1;
							drawListClassForSubject(lcfs, lsj, currentClass, row);
						}
						else if(currentClass < lcfs.size - 1){
							currentClass += 1;
							drawListClassForSubject(lcfs, lsj, currentClass, row);
						}
					}
					break;
					
				case LEFT: 
					if(selected > 1 && mouseSelected != 1 && mouseSelected != 2 && mouseSelected != 3 && mouseSelected != 4){
						selected -= 1;
						highlightOpenClass(selected, LIGHTBLUE);
					}
					break;
				case RIGHT:
					if(selected < 4 && selected != 0 && mouseSelected != 1 && mouseSelected != 2 && mouseSelected != 3 && mouseSelected != 4){
						selected += 1;
						highlightOpenClass(selected, LIGHTBLUE);
					}
					break;
				case ESC:
					if(finded == 1){
						finded = 0; currentClass = 0; row = 0; selected = 1;
						drawListClassForSubject(lcfs, lsj, currentClass, row);
						highlightOpenClass(selected, LIGHTBLUE);
						
						setfillstyle(SOLID_FILL, WHITE);
						bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 430); // xoa du lieu trong hop nhap
						setcolor(BLACK);
						rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
						
						idClass = emptyStr;
					}
					else if(finded == 0){
						return;
					}
					break;
				
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInRange(x, y,LISTSPOINTX + 40, LISTSPOINTY + 460, LISTSPOINTX + 210, LISTSPOINTY + 500)){ // mo lop
				openClass(lcfs, lsj, academicYear, sizeYear, semester);
				
				setfillstyle(SOLID_FILL, WHITE);
				bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 5); // 
				
				setcolor(BLACK);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
				
				idClass = emptyStr;
				finded = 0; currentClass = 0; row = 0; selected = 1;
				
				drawClassForSubjectManagement(1);
				drawOpenClassForSubject();
				drawListClassForSubject(lcfs, lsj, currentClass, row);
				highlightOpenClass(selected, LIGHTBLUE);
			}
			else if(clickInRange(x, y, LISTSPOINTX + 290, LISTSPOINTY + 460, LISTSPOINTX + 460, LISTSPOINTY + 500) && lcfs.size != 0){ // sua lop
				if(lcfs.size != 0 && !existStudentRegisting(lcfs, currentClass)){ // lr : listRegister; ton tai sinh vien co diem
	
					editClass(lcfs, lsj, academicYear, sizeYear, semester, currentClass);
				
					setfillstyle(SOLID_FILL, WHITE);
					bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 5); // 
					
					setcolor(BLACK);
					rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
					
					idClass = emptyStr;
					selected = 2; finded = 0;
					
					drawClassForSubjectManagement(1);
					drawOpenClassForSubject();
					drawListClassForSubject(lcfs, lsj, currentClass, row);
					highlightOpenClass(selected, LIGHTBLUE);
				}
				
				else{
					text = "Da co SV dang ky, Khong the sua!"; 
					setbkcolor(WHITE);
					setcolor(LIGHTRED);
					outtextxy(OPENSPOINTX - 300, OPENSPOINTY - 50, tochar(text));
					Sleep(1000);
					setfillstyle(SOLID_FILL, WHITE);
	    			bar(OPENSPOINTX - 301, OPENSPOINTY - 60, OPENLPOINTX + 50, OPENLPOINTY - 59);
	    			setDefault();
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 540, LISTSPOINTY + 460, LISTSPOINTX + 710, LISTSPOINTY + 500) && lcfs.size != 0){ // xoa lop 
				if(lcfs.size != 0 && !existStudentHaveGrade(lcfs.list[currentClass]->lr)){ // lop hien tai khong co sinh vien dang ky
					deleteClass(lcfs, currentClass); 
					
					setfillstyle(SOLID_FILL, WHITE);
					bar(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // 
									
					setcolor(BLACK);
					rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
					
					idClass = emptyStr;
					selected = 3; finded = 0;
					
					if(currentClass == lcfs.size){
						currentClass -= 1;
						row = max(row - 1, 0);
					}
					
					if(lcfs.size == 0){
						finded = 1; 
						selected = 1;
						highlightOpenClass(selected, LIGHTBLUE);
						
						setfillstyle(SOLID_FILL, WHITE);
						bar(LISTSPOINTX + 41, LISTSPOINTY + 81, LISTLPOINTX, LISTSPOINTY + 389); // xoa du lieu trong bang
						
						setcolor(LIGHTGRAY);
						setbkcolor(WHITE);
						outtextxy(LISTSPOINTX + 400, LISTSPOINTY + 85, "Khong co du lieu ..."); 
						
						setDefault();
					}
					else{
						drawListClassForSubject(lcfs, lsj, currentClass, row);
						highlightOpenClass(selected, LIGHTBLUE);
					}
				}
				else{
					text = "Sinh vien da co diem, Khong the xoa!"; 
					setbkcolor(WHITE);
					setcolor(LIGHTRED);
					outtextxy(OPENSPOINTX - 300, OPENSPOINTY - 50, tochar(text));
					Sleep(1000);
					setfillstyle(SOLID_FILL, WHITE);
	    			bar(OPENSPOINTX - 301, OPENSPOINTY - 60, OPENLPOINTX + 50, OPENLPOINTY - 59);
	    			setDefault();
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 790, LISTSPOINTY + 460, LISTSPOINTX + 960, LISTSPOINTY + 500)){ // huy lop
				if(lcfs.size != 0){ // so luong sinh vien dang ky > min
					cancelClass(lcfs, lsj);
					
					drawOpenClassForSubject();
					drawListClassForSubject(lcfs, lsj, currentClass, row);
					highlightOpenClass(selected, LIGHTBLUE);
					setDefault();
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430)){ // tim kiem
				setcolor(LIGHTBLUE);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau xanh
				highlightOpenClass(selected, LIGHTGRAY);
				setDefault();
				
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
							if(idClass == emptyStr){
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 430); // xoa du lieu trong hop nhap
								setcolor(BLACK);
								rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
								
								idClass = emptyStr;
								
								finded = 0; currentClass = 0; row = 0; selected = 1;
								drawListClassForSubject(lcfs, lsj, currentClass, row);
								highlightOpenClass(selected, LIGHTBLUE);
								break;
							}
							else{
								int i = findIndexClass(lcfs, stringtoint(idClass)); 
								if(i >= 0 && i < lcfs.size && lcfs.list[i] != NULL){
									setfillstyle(SOLID_FILL, WHITE);
									bar(LISTSPOINTX + 41, LISTSPOINTY + 81, LISTLPOINTX, LISTSPOINTY + 389); // xoa du lieu trong bang
									
									setfillstyle(SOLID_FILL, LIGHTBLUE);
									bar(LISTSPOINTX + 41, LISTSPOINTY + 80, LISTLPOINTX, LISTSPOINTY + 110); // highlight dong dau tien (dong ket qua)
									
									setbkcolor(LIGHTBLUE);
									setcolor(BLACK);
									outtextxy(LISTSPOINTX + 50, LISTSPOINTY + 85, tochar(to_string(lcfs.list[i]->idclass)));
									outtextxy(LISTSPOINTX + 150, LISTSPOINTY + 85, tochar(findNameSubject(lcfs.list[i]->idSubject, lsj.root))); // findNameSubject trong datastructure
									outtextxy(LISTSPOINTX + 500, LISTSPOINTY + 85, tochar(to_string(lcfs.list[i]->academicYear)));
									outtextxy(LISTSPOINTX + 580, LISTSPOINTY + 85, tochar(to_string(lcfs.list[i]->semester)));
									outtextxy(LISTSPOINTX + 660, LISTSPOINTY + 85, tochar(to_string(lcfs.list[i]->group)));
									outtextxy(LISTSPOINTX + 740, LISTSPOINTY + 85, tochar(to_string(lcfs.list[i]->studentMin)));
									outtextxy(LISTSPOINTX + 820, LISTSPOINTY + 85, tochar(to_string(lcfs.list[i]->studentMax)));
									
									if(lcfs.list[i]->unClass == true){
										setcolor(BLACK);
										outtextxy(LISTSPOINTX + 900, LISTSPOINTY + 85, "Da huy");
									}
									else if(existStudentHaveGrade(lcfs.list[i]->lr)){
										setcolor(BLACK);
										outtextxy(LISTSPOINTX + 900, LISTSPOINTY + 85, "Da mo");
									}
									else{
										setcolor(BLACK);
										outtextxy(LISTSPOINTX + 900, LISTSPOINTY + 85, "Dang mo");
									}
									
									setcolor(LIGHTGRAY);
									line(LISTSPOINTX + 140, LISTSPOINTY + 40, LISTSPOINTX + 140, LISTSPOINTY + 390);
									line(LISTSPOINTX + 480, LISTSPOINTY + 40, LISTSPOINTX + 480, LISTSPOINTY + 390);
									line(LISTSPOINTX + 560, LISTSPOINTY + 40, LISTSPOINTX + 560, LISTSPOINTY + 390);
									line(LISTSPOINTX + 640, LISTSPOINTY + 40, LISTSPOINTX + 640, LISTSPOINTY + 390);
									line(LISTSPOINTX + 720, LISTSPOINTY + 40, LISTSPOINTX + 720, LISTSPOINTY + 390);
									line(LISTSPOINTX + 800, LISTSPOINTY + 40, LISTSPOINTX + 800, LISTSPOINTY + 390);
									line(LISTSPOINTX + 890, LISTSPOINTY + 40, LISTSPOINTX + 890, LISTSPOINTY + 390);
									// ve cac duong ke trong danh sach lop
									
									setcolor(BLACK);
									rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
									setDefault();
									
									selected = 2;
									highlightOpenClass(selected, LIGHTBLUE);
									
									finded = 1; row = 0;
									
									currentClass = i;
									break;
								}
								else{
									setfillstyle(SOLID_FILL, WHITE);
									bar(LISTSPOINTX + 41, LISTSPOINTY + 81, LISTLPOINTX, LISTSPOINTY + 389); // xoa du lieu trong bang
									
									setcolor(LIGHTGRAY);
									setbkcolor(WHITE);
									outtextxy(LISTSPOINTX + 400, LISTSPOINTY + 85, "Khong tim thay du lieu ..."); 
									
									setDefault();
								}
							}
						}
						else if(ascii == BP && (int)idClass.size() > 0){
							idClass.pop_back();
							
							setfillstyle(SOLID_FILL, WHITE);
							setbkcolor(WHITE);
							setcolor(BLACK);
							
							bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 430) ;// xoa du lieu trong muc nhap
							outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClass));
							setDefault();
						}
						else if('0' <= ascii && ascii <= '9'){
							if((int)idClass.size() < 5){
								setfillstyle(SOLID_FILL, WHITE);
								setbkcolor(WHITE);
								setcolor(BLACK);
							
								formatKey(key); // dua ve chu in hoa
								finded = 0;
								idClass += key;
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClass)); // in ra
								setDefault();
							}							
						}
						else if(ascii == ESC){
							setfillstyle(SOLID_FILL, WHITE);
							bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 430); // xoa du lieu trong hop nhap
							setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to hop nhap thanh mau den
							
							idClass = emptyStr;
							
							finded = 0; currentClass = 0; row = 0; selected = 1;
							drawListClassForSubject(lcfs, lsj, currentClass, row);
							highlightOpenClass(selected, LIGHTBLUE);
							
							break;
						}
					}
				}
			}
		}
	}
}


void printRegisteredStudentList(ptrClassForSubject listOpeningClass[], int &currentClass, listSubject &lsj, listStudent &ls){
	
	drawPrintRegisteredStudentList(listOpeningClass, currentClass, lsj); // ve khung in ra danh sach 
	
	ptrListRegister lr = listOpeningClass[currentClass]->lr;
	int currentStudent = 0;
	
	drawDisplayRegisteredStudentList(ls, lr, currentStudent);
	
	char key; int ascii;
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
	    			if(currentStudent >= 10){
	    				currentStudent -= 10;
	    				drawDisplayRegisteredStudentList(ls, lr, currentStudent);
					}
	    			break;
	    		case DOWN:
	    			if(currentStudent + 10 < lr->size){
	    				currentStudent += 10;
	    				drawDisplayRegisteredStudentList(ls, lr, currentStudent);
					}
	    			break;
	    		case ESC:
	    			
	    			setbkcolor(WHITE);
	    			bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 5);
	    			
	    			setcolor(WHITE);
					line(LISTSPOINTX - 5, HEADLPOINTY, LISTSPOINTX - 5, LISTLPOINTY);
	    			return;
	    			break;
			}
		}
	}
	
}

void listRegisterClass(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls){
	
	ptrClassForSubject ListOpeningClass[MAXCLASS]; // mang chua danh sach cac lop dang mo
	int sizeList = 0, currentClass = 0, row = 0, ascii, selected = 0, on = 0, x, y;
	char key; string text = emptyStr;
	
	int idClass = 0, academic = 0, semester = 0;
	string idClassTemp = emptyStr, academicTemp = emptyStr, semesterTemp = emptyStr;
	
	getListOpeningClass(ListOpeningClass, lcfs, sizeList, idClass, academic, semester); // loc ket qua vao mang
	
	drawListRegisterClass(sizeList);
	drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
	

	while(true){
		mouseHighlightListRegisterClass(on, selected);
		if(kbhit()){
			key = getch();
			ascii = static_cast<int>(key);
	        if (ascii == 0) { 
	            key = getch();
	            ascii = static_cast<int>(key);
	            ascii += 255;
	    	}
			switch(ascii){
				case ET: 
					// the hien danh sach cua lop duoc chon o chi muc currentClass trong listOpeningClass ( listOpeningClass[currentClass] )
					
					printRegisteredStudentList(ListOpeningClass, currentClass, lsj, ls);
					
					drawListRegisterClass(sizeList);
					drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
					break;
				case UP:
					if(row > 0){
						row -= 1;
						currentClass -= 1;
						drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row); // giu trang thai, to mau muc khac
					}
					else if(currentClass > 0){
						currentClass -= 1;
						drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);  // thay doi trang thai, giu muc hien tai
					}
					break;
				case DOWN:
					if(row < 9 && currentClass < sizeList - 1){
						row += 1;
						currentClass += 1;
						drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
					}
					else if(currentClass < sizeList - 1){
						currentClass += 1;
						drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
					}
					break;
					
				case ESC:
					return;
					break;
				
			}
		}
		if(ismouseclick(WM_LBUTTONDOWN)){
			getmouseclick(WM_LBUTTONDOWN, x, y);
			clearmouseclick(WM_LBUTTONDOWN);
			if(clickInRange(x, y, LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430)){ // muc nhap ma lop
				setcolor(LIGHTBLUE);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to muc nhap thanh mau xanh
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
				    		setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to muc nhap thanh mau den
							
							idClass = stringtoint(idClassTemp);
							currentClass = 0; row = 0;
							
							getListOpeningClass(ListOpeningClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
							
							break;
						}
						else if(ascii == ESC){
							idClassTemp = emptyStr; idClass = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 429); // xoa noi dung da nhap
							
							setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430); // to muc nhap thanh mau den
							
							currentClass = 0; row = 0;
							
							getListOpeningClass(ListOpeningClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
							break;
						}
						else if(ascii == BP){
							if(idClassTemp != emptyStr){
								idClassTemp.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX + 151, LISTSPOINTY + 401, LISTSPOINTX + 340, LISTSPOINTY + 429); // xoa noi dung cu
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp)); // hien noi dung moi
							}
						}
						else if('0' <= ascii && ascii <= '9'){
							if(idClassTemp.size() < 10){
								if(idClassTemp.size() == 0 && ascii == '0') continue;
								idClassTemp += key;
								
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 405, tochar(idClassTemp));
							}
						}
					}
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470)){ // muc nhap nien khoa
				setcolor(LIGHTBLUE);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470); // to muc nhap thanh mau xanh
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
				    		setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470); // to muc nhap thanh mau den
							
							academic = stringtoint(academicTemp);
							currentClass = 0; row = 0;
							
							getListOpeningClass(ListOpeningClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
							
							break;
						}
						else if(ascii == ESC){
							academicTemp = emptyStr; academic = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(LISTSPOINTX + 151, LISTSPOINTY + 441, LISTSPOINTX + 340, LISTSPOINTY + 469); // xoa noi dung da nhap
							
							setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 440, LISTSPOINTX + 340, LISTSPOINTY + 470); // to muc nhap thanh mau den
							
							currentClass = 0; row = 0;
							
							getListOpeningClass(ListOpeningClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
							break;
						}
						else if(ascii == BP){
							if(academicTemp != emptyStr){
								academicTemp.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX + 151, LISTSPOINTY + 441, LISTSPOINTX + 340, LISTSPOINTY + 469); // xoa noi dung cu
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp)); // hien noi dung moi
							}
						}
						else if('0' <= ascii && ascii <= '9'){
							if(academicTemp.size() < 4){
								if(academicTemp.size() == 0 && ascii == '0') continue;
								academicTemp += key;
								
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 445, tochar(academicTemp));
							}
						}
					}
				}
			}
			else if(clickInRange(x, y, LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510)){ // muc nhap hoc ki
				setcolor(LIGHTBLUE);
				rectangle(LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510); // to muc nhap thanh mau xanh
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
				    		
				    		setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510); // to muc nhap thanh mau den
							
							semester = stringtoint(semesterTemp);
							currentClass = 0; row = 0;
							
							getListOpeningClass(ListOpeningClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
							
							break;
						}
						else if(ascii == ESC){
							semesterTemp = emptyStr; semester = 0;
							setfillstyle(SOLID_FILL, WHITE);
							bar(LISTSPOINTX + 151, LISTSPOINTY + 481, LISTSPOINTX + 340, LISTSPOINTY + 509); // xoa noi dung da nhap
							
							setcolor(BLACK);
							rectangle(LISTSPOINTX + 150, LISTSPOINTY + 480, LISTSPOINTX + 340, LISTSPOINTY + 510); // to muc nhap thanh mau den
							
							currentClass = 0; row = 0;
							
							getListOpeningClass(ListOpeningClass, lcfs, sizeList, idClass, academic, semester); // loc thong tin theo idclass
							drawDisplayListRegisterClass(ListOpeningClass, sizeList, lsj, currentClass, row);
							break;
							
						}
						else if(ascii == BP){
							if(semesterTemp != emptyStr){
								semesterTemp.pop_back();
								
								setfillstyle(SOLID_FILL, WHITE);
								bar(LISTSPOINTX + 151, LISTSPOINTY + 481, LISTSPOINTX + 340, LISTSPOINTY + 509); // xoa noi dung cu
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp)); // hien noi dung moi
							}
						}
						else if('0' <= ascii && ascii <= '9'){
							if(semesterTemp.size() < 1){
								if(semesterTemp.size() == 0 && ascii == '0') continue;
								semesterTemp += key;
								
								setcolor(BLACK);
								outtextxy(LISTSPOINTX + 160, LISTSPOINTY + 485, tochar(semesterTemp));
							}
						}
					}
				}
			}
		}
	}
}

void classForSubjectManagement(listClassForSubject &lcfs, listSubject &lsj, listStudent &ls){
	int selected = 1;
	drawClassForSubjectManagement(selected);
	
	int run1 = 1;
	char key;
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
						case 1: // mo lop tin chi
							openClassForSubject(lcfs, lsj);
							drawClassForSubjectManagement(selected);
							break;
						case 2: // danh sach dang ky
							listRegisterClass(lcfs, lsj, ls);
							drawClassForSubjectManagement(selected);
							break;
						case 3: // dang ky lop tin chi
							break;
					}
					break;
				case UP:
					if(selected > 1){
						selected--;
						drawClassForSubjectManagement(selected);
					}
					break;
				case DOWN:
					if(selected < 3){
						selected++;
						drawClassForSubjectManagement(selected);
					}
					break;
				case ESC:
					return;
			}
		}
	}
}


#endif 

