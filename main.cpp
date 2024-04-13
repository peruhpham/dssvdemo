#include <graphics.h>
#include <windows.h>
#include <conio.h>
#include <stdio.h>
#include <bits/stdc++.h>
#include <string>
#include "datahanding.h"
#include "datastructure.h"
#include "display.h"
#include "studentmanagement.h"
#include "classforsubjectmanagement.h"

#include "subjectmanagement.h"

  
using namespace std;

int main(){  
	
	initwindow(LPOINTX, LPOINTY);
	
	// tao tien xu ly, khai bao 
	string nameFileListStudent = "data\\studentlist.txt";
	string nameFileListClass = "data\\classlist.txt";
	string nameFileListClassForSubject = "data\\classforsubjectlist.txt";
	string nameFileListSubject = "data\\subjectlist.txt";
	
	listStudent ls;
	listClass lc;
	listClassForSubject lcfs;
	listSubject lsj;
	
	readListStudent(ls, nameFileListStudent);
	readListClass(lc, nameFileListClass);
	readListClassForSubject(lcfs, nameFileListClassForSubject);
	readListSubject(lsj, nameFileListSubject);
	   
//  getch();
	int selected = 1;
	createMenu(selected);

	while(1){
		char key = getch();
		       
		int ascii = static_cast<int>(key); 
        if (ascii == 0) { 
            key = getch();
            ascii = static_cast<int>(key);
            ascii += 255;  
    	}
          
		switch(ascii){  
			case ET:    	         
				switch(selected){      
					case 1:  
						studentManagement(ls, lc);        
						createMenu(selected);	                
						break;  
					case 2:
						classForSubjectManagement(lcfs, lsj); // quan li lop theo mon hoc (lop tin chi)
						createMenu(selected);  
						break;
					case 3:
						//  
//						displaySubjectListByControl(lsj); 
						// 
						subjectManagement(lsj, selected); // quan li 
						
						resetDisplaySubjectList(x, y);
						createMenu(selected);
						break;						 
					case 4:
						break;      
				} 
				break;               
			case UP:
				if(selected > 1){  
					selected--;
					createMenu(selected);
				}
				break; 
			case DOWN:
				if(selected < 4){
					selected++;
					createMenu(selected);
				}
				break;
			case ESC:
				if(!createNotice("Ban chac chan muon thoat!", "")){
					closegraph();
					return 0;
				}
				createMenu(selected);
				break;
			
		}
	}
}

