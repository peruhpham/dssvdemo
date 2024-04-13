#ifndef DISPLAY_H
#define DISPLAY_H

#define UP 72 + 255
#define DOWN 80 + 255
#define LEFT 75 + 255
#define RIGHT 77 + 255
#define ET 13
#define ESC 27
#define SPACE 32
#define BP 8 // backspace
#define SPOINTX 0
#define SPOINTY 0
#define LPOINTX 1350 + 30
#define LPOINTY 700

#define HEADSPOINTX 0
#define HEADSPOINTY 0
#define HEADLPOINTX 1350
#define HEADLPOINTY 60 // chinh sua

#define MENUSPOINTX 0
#define MENUSPOINTY 70
#define MENULPOINTX 320
#define MENULPOINTY 280

#define BOTTSPOINTX 0
#define BOTTSPOINTY 600
#define BOTTLPOINTX 1350
#define BOTTLPOINTY 600

#define NOTISPOINTX 400 // notice
#define NOTISPOINTY 150
#define NOTILPOINTX 1010
#define NOTILPOINTY 350

#define LISTSPOINTX 340
#define LISTSPOINTY 70
#define LISTLPOINTX 1350
#define LISTLPOINTY 600

#define TABLSPOINTX 342
#define TABLSPOINTY 190
#define TABLLPOINTX 1350
#define TABLLPOINTY 430

#define BOXSPOINTX LISTSPOINTX + 280
#define BOXSPOINTY LISTSPOINTY + 70
#define BOXLPOINTX LISTSPOINTX + 480
#define BOXLPOINTY LISTSPOINTY + 100

#define FORMSPOINTX TABLSPOINTX
#define FORMSPOINTY TABLLPOINTY + 40
#define FORMLPOINTX TABLLPOINTX
#define FORMLPOINTY TABLLPOINTY + 80

#define TEXTSPOINTX1 360
#define TEXTSPOINTY1 190
#define TEXTLPOINTX1 740
#define TEXTLPOINTY1 230

#define TEXTSPOINTX2 750
#define TEXTSPOINTY2 190
#define TEXTLPOINTX2 1040
#define TEXTLPOINTY2 230

#define TEXTSPOINTX3 1050
#define TEXTSPOINTY3 190
#define TEXTLPOINTX3 1320
#define TEXTLPOINTY3 230

#define TEXTSPOINTX4 750
#define TEXTSPOINTY4 300
#define TEXTLPOINTX4 1040
#define TEXTLPOINTY4 340

#define TEXTSPOINTX5 1050
#define TEXTSPOINTY5 300
#define TEXTLPOINTX5 1320
#define TEXTLPOINTY5 340

#define TEXTSPOINTX6 750
#define TEXTSPOINTY6 410
#define TEXTLPOINTX6 1040
#define TEXTLPOINTY6 450

#define OPENSPOINTX 1050
#define OPENSPOINTY 530
#define OPENLPOINTX 1260
#define OPENLPOINTY 570

int clickInRange(int x, int y, int left, int top, int right, int bot){ // nhan chuot trai vao pham vi
	if((left <= x && x <= right) && (top <= y && y <= bot)) return 1;
	return 0;
}


void setDefault(){
	setbkcolor(15); // mac dinh nen la mau trang
	setcolor(0); // mac dinh van ban la mau den
	setfillstyle(SOLID_FILL, WHITE); // mac dinh to khung hinh la mau trang
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 1); // mac dinh font complex, co chu la 1
	setlinestyle(0, 1, 1);
}

void resetBox(int COLOR){ // reset box nhap mac dinh khong co gi
	setfillstyle(SOLID_FILL, WHITE);
	bar(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); // xoa toan bo du lieu trong muc nhap
	setcolor(COLOR);
	rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY);
	setDefault();
}

void resetInforStudentBox(int num, int COLOR){
	switch(num){
		case 1:
			setfillstyle(SOLID_FILL, WHITE);
			bar(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // xoa sach muc nhap
			
			setcolor(COLOR);
			rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY);
			setDefault();
			break;
		case 2:
			setfillstyle(SOLID_FILL, WHITE);
			bar(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY); // xoa sach muc nhap
			
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
			setDefault();
			break;
		case 3:
			setfillstyle(SOLID_FILL, WHITE);
			bar(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY); // xoa sach muc nhap
			
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
			setDefault();
			break;
		case 4:
			setfillstyle(SOLID_FILL, WHITE);
			bar(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY); // xoa sach muc nhap
			
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
			setDefault();
			break;
		case 5:
			setfillstyle(SOLID_FILL, WHITE);
			bar(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY); // xoa sach muc nhap
			
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
			setDefault();
			break;
		case 6:
			setfillstyle(SOLID_FILL, WHITE);
			bar(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY); // xoa sach muc nhap
			
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
			setDefault();
			break;
	}
}
void resetText(){ // reset thong bao mac dinh khong co gi
	setfillstyle(SOLID_FILL, WHITE);
	bar(BOXLPOINTX + 20, LISTSPOINTY + 70, LPOINTX - 10, LISTSPOINTY + 100);
	setDefault();
}


void mouseHighlightUpdate(int &on, int &selected){
	setcolor(BLACK);
	 
	if(clickInRange(mousex(), mousey(), TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140)){
		if(on == 0){
			setfillstyle(SOLID_FILL, LIGHTBLUE);
			setbkcolor(LIGHTBLUE);
			bar(TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140);
			outtextxy(TABLSPOINTX + 115, TABLLPOINTY + 110, "Them thong tin");
			on = 1;
			selected = 1;
		}
	}
	else if(on == 1 && selected == 1){
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setbkcolor(LIGHTGRAY);
		bar(TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140);
		outtextxy(TABLSPOINTX + 115, TABLLPOINTY + 110, "Them thong tin");
		on = 0;
	}
	
	if(clickInRange(mousex(), mousey(), TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140)){
		if(on == 0){
			setfillstyle(SOLID_FILL, LIGHTBLUE);
			setbkcolor(LIGHTBLUE);
			bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
			outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
			on = 1;
			selected = 2;
		}
	}
	else if(on == 1 && selected == 2){
		
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setbkcolor(LIGHTGRAY);
		bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
		outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
		on = 0;
	}
	
	if(clickInRange(mousex(), mousey(), TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140)){
		if(on == 0){
			setfillstyle(SOLID_FILL, LIGHTBLUE);
			setbkcolor(LIGHTBLUE);
			bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
			outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
			on = 1;	
			selected = 3;
		}
	}
	else if(on == 1 && selected == 3){
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setbkcolor(LIGHTGRAY);
		bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
		outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
		on = 0;
	}
	
	if(clickInRange(mousex(), mousey(), BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY)){
		if(on == 0){
			setcolor(LIGHTGRAY);
			rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY);
			on = 1;
			selected = 4;
		}
	}
	else if (on == 1 && selected == 4){
		
		setcolor(BLACK);
		rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY);
		on = 0;
	}
	
	setDefault();	
}


void mouseHighlightOpenClass(int &on, int &selected){
	
	// dua chuot vao box 1
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX1, TEXTSPOINTY1, TEXTLPOINTX1, TEXTLPOINTY1)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX1, TEXTSPOINTY1, TEXTLPOINTX1, TEXTLPOINTY1);
			on = 1;
			selected = 1;
		}
	}
	else if(on == 1 && selected == 1){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX1, TEXTSPOINTY1, TEXTLPOINTX1, TEXTLPOINTY1);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao box 2
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX2, TEXTSPOINTY2, TEXTLPOINTX2, TEXTLPOINTY2)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX2, TEXTSPOINTY2, TEXTLPOINTX2, TEXTLPOINTY2);
			on = 1;
			selected = 2;
		}
	}
	else if(on == 1 && selected == 2){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX2, TEXTSPOINTY2, TEXTLPOINTX2, TEXTLPOINTY2);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao box 3
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
			on = 1;	
			selected = 3;
		}
	}
	else if(on == 1 && selected == 3){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao box 4
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
			on = 1;
			selected = 4;
		}
	}
	else if (on == 1 && selected == 4){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao box 5
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
			on = 1;
			selected = 5;
		}
	}
	else if (on == 1 && selected == 5){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao box 6
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
			on = 1;
			selected = 6;
		}
	}
	else if (on == 1 && selected == 6){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao muc mo lop 
	
	if(clickInRange(mousex(), mousey(), OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY)){
		if(on == 0){
			setfillstyle(SOLID_FILL, BLUE);
			setbkcolor(BLUE);
			bar(OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY);
			outtextxy(OPENSPOINTX + 65, OPENSPOINTY + 10, "Mo lop");
			on = 1;
			selected = 7;
		}
	}
	else if (on == 1 && selected == 7){
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		setbkcolor(LIGHTBLUE);
		bar(OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY);
		outtextxy(OPENSPOINTX + 65, OPENSPOINTY + 10, "Mo lop");
		selected = 0;
		on = 0;
	}
	
	setDefault();
}

void mouseHighlightEditClass(int &on, int &selected){
	


	
	// dua chuot vao box 3
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
			on = 1;	
			selected = 3;
		}
	}
	else if(on == 1 && selected == 3){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao box 5
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
			on = 1;
			selected = 5;
		}
	}
	else if (on == 1 && selected == 5){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao box 6
	
	if(clickInRange(mousex(), mousey(), TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6)){
		if(on == 0){
			setcolor(LIGHTBLUE);
			rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
			on = 1;
			selected = 6;
		}
	}
	else if (on == 1 && selected == 6){
		setcolor(LIGHTGRAY);
		rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
		selected = 0;
		on = 0;
	}
	
	// dua chuot vao muc mo lop 
	
	if(clickInRange(mousex(), mousey(), OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY)){
		if(on == 0){
			setfillstyle(SOLID_FILL, BLUE);
			setbkcolor(BLUE);
			bar(OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY);
			outtextxy(OPENSPOINTX + 65, OPENSPOINTY + 10, "Hoan tat");
			on = 1;
			selected = 7;
		}
	}
	else if (on == 1 && selected == 7){
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		setbkcolor(LIGHTBLUE);
		bar(OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY);
		outtextxy(OPENSPOINTX + 65, OPENSPOINTY + 10, "Hoan tat");
		selected = 0;
		on = 0;
	}
	
	setDefault();
}

void highlightOpenClass(int selected, int COLOR){
	setcolor(BLACK);
	
	if(selected == 1){
		setfillstyle(SOLID_FILL, COLOR);
		bar(LISTSPOINTX + 40, LISTSPOINTY + 460, LISTSPOINTX + 210, LISTSPOINTY + 500);
		setbkcolor(COLOR);
		outtextxy(LISTSPOINTX + 90, LISTSPOINTY + 470, "MO LOP");
	}
	else{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(LISTSPOINTX + 40, LISTSPOINTY + 460, LISTSPOINTX + 210, LISTSPOINTY + 500);
		setbkcolor(LIGHTGRAY);
		outtextxy(LISTSPOINTX + 90, LISTSPOINTY + 470, "MO LOP");
	}
	if(selected == 2){
		setfillstyle(SOLID_FILL, COLOR);
		bar(LISTSPOINTX + 290, LISTSPOINTY + 460, LISTSPOINTX + 460, LISTSPOINTY + 500);
		setbkcolor(COLOR);
		outtextxy(LISTSPOINTX + 340, LISTSPOINTY + 470, "SUA LOP");
	}
	else{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(LISTSPOINTX + 290, LISTSPOINTY + 460, LISTSPOINTX + 460, LISTSPOINTY + 500);
		setbkcolor(LIGHTGRAY);
		outtextxy(LISTSPOINTX + 340, LISTSPOINTY + 470, "SUA LOP");
	}
	if(selected == 3){
		setfillstyle(SOLID_FILL, COLOR);
		bar(LISTSPOINTX + 540, LISTSPOINTY + 460, LISTSPOINTX + 710, LISTSPOINTY + 500);
		setbkcolor(COLOR);
		outtextxy(LISTSPOINTX + 590, LISTSPOINTY + 470, "XOA LOP");
	}
	else{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(LISTSPOINTX + 540, LISTSPOINTY + 460, LISTSPOINTX + 710, LISTSPOINTY + 500);
		setbkcolor(LIGHTGRAY);
		outtextxy(LISTSPOINTX + 590, LISTSPOINTY + 470, "XOA LOP");
	}
	if(selected == 4){
		setfillstyle(SOLID_FILL, COLOR);
		bar(LISTSPOINTX + 790, LISTSPOINTY + 460, LISTSPOINTX + 960, LISTSPOINTY + 500);
		setbkcolor(COLOR);
		outtextxy(LISTSPOINTX + 840, LISTSPOINTY + 470, "HUY LOP");	
	}
	else{
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(LISTSPOINTX + 790, LISTSPOINTY + 460, LISTSPOINTX + 960, LISTSPOINTY + 500);
		setbkcolor(LIGHTGRAY);
		outtextxy(LISTSPOINTX + 840, LISTSPOINTY + 470, "HUY LOP");	
	}
	
	setDefault();
}



void mouseHighlightOpenClassForSubject(int &on, int &mouseSelected, int &selected){

	// dua chuot den muc mo lop 	
	if(clickInRange(mousex(), mousey(), LISTSPOINTX + 40, LISTSPOINTY + 460, LISTSPOINTX + 210, LISTSPOINTY + 500)){
		if(on == 0){
			on = 1;
			mouseSelected = 1;
			highlightOpenClass(mouseSelected, LIGHTBLUE);
		}
	}
	else if(on == 1 && mouseSelected == 1){
		mouseSelected = 0;
		on = 0;
		highlightOpenClass(mouseSelected, LIGHTGRAY);
	}
	
	// dua chuot den muc sua lop
	
	if(clickInRange(mousex(), mousey(), LISTSPOINTX + 290, LISTSPOINTY + 460, LISTSPOINTX + 460, LISTSPOINTY + 500)){
		if(on == 0){
			on = 1;
			mouseSelected = 2;
			highlightOpenClass(mouseSelected, LIGHTBLUE);
		}
	}
	else if(on == 1 && mouseSelected == 2){
		mouseSelected = 0;
		on = 0;
		highlightOpenClass(mouseSelected, LIGHTGRAY);
	}
	
	// dua chuot vao muc xoa lop 
	
	if(clickInRange(mousex(), mousey(), LISTSPOINTX + 540, LISTSPOINTY + 460, LISTSPOINTX + 710, LISTSPOINTY + 500)){
		if(on == 0){
			on = 1;
			mouseSelected = 3;
			highlightOpenClass(mouseSelected, LIGHTBLUE);
		}
	}
	else if(on == 1 && mouseSelected == 3){
		mouseSelected = 0;
		on = 0;
		highlightOpenClass(mouseSelected, LIGHTBLUE);
	}
	
	// dua chuot vao muc huy lop 
	if(clickInRange(mousex(), mousey(), LISTSPOINTX + 790, LISTSPOINTY + 460, LISTSPOINTX + 960, LISTSPOINTY + 500)){
		if(on == 0){
			on = 1;
			mouseSelected = 4;
			highlightOpenClass(mouseSelected, LIGHTBLUE);
		}
	}
	else if(on == 1 && mouseSelected == 4){
		mouseSelected = 0;
		on = 0;
		highlightOpenClass(mouseSelected, LIGHTBLUE);
	}
	// click vao tim kiem
	if(clickInRange(mousex(), mousey(), LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430)){
		if(on == 0){
			on = 1;
			mouseSelected = 5;
			setcolor(LIGHTGRAY);
			rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430);
			setDefault();
		}
	}
	else if(on == 1 && mouseSelected == 5){
		mouseSelected = 0;
		on = 0;
		setcolor(BLACK);
		rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430);
		setDefault();
	}
	
	setDefault();
}



void highlightInforStudentBox(int num, int COLOR){
	switch(num){
		case 1:
			setcolor(COLOR);
			rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY);
			setDefault();
			break;
		case 2:			
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
			setDefault();
			break;
		case 3:		
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
			setDefault();
			break;
		case 4:	
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
			setDefault();
			break;
		case 5:
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
			setDefault();
			break;
		case 6:
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
			setDefault();
			break;
		case 7:
			setfillstyle(SOLID_FILL, COLOR);
			bar(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // to nhat muc add
			setbkcolor(COLOR);
			setcolor(BLACK);
			outtextxy(TABLSPOINTX + 930, FORMSPOINTY + 10, "Add");
			setDefault();
			break;
	}
}


void highlightEditInforStudentBox(int num, int COLOR){
	switch(num){
		case 1:
			setcolor(COLOR);
			rectangle(FORMSPOINTX, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY);
			setDefault();
			break;
		case 2:			
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);
			setDefault();
			break;
		case 3:		
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);
			setDefault();
			break;
		case 4:	
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);
			setDefault();
			break;
		case 5:
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);
			setDefault();
			break;
		case 6:
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
			setDefault();
			break;
		case 7:
			setcolor(COLOR);
			rectangle(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY);
			setDefault();
			break;
		case 8:
			setfillstyle(SOLID_FILL, COLOR);
			bar(FORMSPOINTX, TABLLPOINTY + 100, TABLSPOINTX + 145, TABLLPOINTY + 140); 
			setbkcolor(COLOR);
			setcolor(BLACK);
			outtextxy(FORMSPOINTX + 30, TABLLPOINTY + 110, "Update");
			
			setDefault();
			break;
	}
}

void highlightLineCurrent(int lineCurrent, int COLOR){
	setfillstyle(SOLID_FILL, COLOR);
	switch(lineCurrent){
		case 1:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 1, TEXTLPOINTX1, TEXTLPOINTY1 + 30);
			break;
		case 2:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 31, TEXTLPOINTX1, TEXTLPOINTY1 + 60);
			break;
		case 3:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 61, TEXTLPOINTX1, TEXTLPOINTY1 + 90);
			break;
		case 4:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 91, TEXTLPOINTX1, TEXTLPOINTY1 + 120);
			break;
		case 5:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 121, TEXTLPOINTX1, TEXTLPOINTY1 + 150);
			break;
		case 6:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 151, TEXTLPOINTX1, TEXTLPOINTY1 + 180);
			break;
		case 7:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 181, TEXTLPOINTX1, TEXTLPOINTY1 + 210);
			break;
		case 8:
			bar(TEXTSPOINTX1 + 1, TEXTLPOINTY1 + 211, TEXTLPOINTX1, TEXTLPOINTY1 + 240);
			break;
	}
	
	setDefault();
}

void highlightLineCurrent2(int lineCurrent, int COLOR){
	setfillstyle(SOLID_FILL, COLOR);
	switch(lineCurrent){
		case 1:
			bar(TEXTSPOINTX2 + 1, TEXTLPOINTY2 + 1, TEXTLPOINTX2, TEXTLPOINTY2 + 30);
			break;
		case 2:
			bar(TEXTSPOINTX2 + 1, TEXTLPOINTY2 + 31, TEXTLPOINTX2, TEXTLPOINTY2 + 60);
			break;
		case 3:
			bar(TEXTSPOINTX2 + 1, TEXTLPOINTY2 + 61, TEXTLPOINTX2, TEXTLPOINTY2 + 90);
			break;
		case 4:
			bar(TEXTSPOINTX2 + 1, TEXTLPOINTY2 + 91, TEXTLPOINTX2, TEXTLPOINTY2 + 120);
			break;
	}
	
	setDefault();
}

void highlightLineCurrent4(int lineCurrent, int COLOR){
	setfillstyle(SOLID_FILL, COLOR);
	switch(lineCurrent){
		case 1:
			bar(TEXTSPOINTX4+ 1, TEXTLPOINTY4 + 1, TEXTLPOINTX4, TEXTLPOINTY4 + 30);
			break;
		case 2:
			bar(TEXTSPOINTX4 + 1, TEXTLPOINTY4 + 31, TEXTLPOINTX4, TEXTLPOINTY4 + 60);
			break;
		case 3:
			bar(TEXTSPOINTX4 + 1, TEXTLPOINTY4 + 61, TEXTLPOINTX4, TEXTLPOINTY4 + 90);
			break;
	}
	
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

void createBox(int COLOR, char *text){ // tao muc nhap (MSSV)
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLSPOINTX + 5, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY + 2); // xoa sach du lieu trong box
	rectangle(BOXSPOINTX, BOXSPOINTY, BOXLPOINTX, BOXLPOINTY); // tao khung box
	
	setcolor(COLOR);
	settextstyle(COMPLEX_FONT, HORIZ_DIR, 2); 
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 80, text); // viet lai du lieu
	setDefault();
}
int createNotice(char *text1, char* text2){
//	cleardevice();
//	createHeader();
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(NOTISPOINTX, NOTISPOINTY, NOTILPOINTX, NOTILPOINTY);
	
	setcolor(LIGHTRED); // thiet lap mau chu
	outtextxy(NOTISPOINTX + 250, NOTISPOINTY + 50, "Thong bao!");
	setcolor(BLACK);
	rectangle(NOTISPOINTX, NOTISPOINTY, NOTILPOINTX, NOTILPOINTY); // tao hop thong bao to khung theo mau chu k to mau nen
	
	outtextxy(NOTISPOINTX + 20, NOTISPOINTY + 100, text1);
	outtextxy(NOTISPOINTX + 20, NOTISPOINTY + 130, text2);
	outtextxy(NOTISPOINTX + 20, NOTISPOINTY + 160, "Nhan Enter de tiep tuc/ Esc de thoat chuong trinh");
	
	setDefault;
	
	char key; int ascii;
	key = getch();
	ascii = static_cast<int>(key);
	if (ascii == 0) { 
	    key = getch();
	    ascii = static_cast<int>(key);
	    ascii += 255;
	}
//	cleardevice();
	if(ascii == ET){
		return 1;
	}
	return 0;
}

void createScrollBar(int firstStudent, int sizeClass){
	// tao thanh cuon 
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(LISTSPOINTX - 17, LISTSPOINTY, LISTSPOINTX - 5, LISTLPOINTY - 2); // xoa du lieu
	
	setcolor(LIGHTGRAY);
	rectangle(LISTSPOINTX - 17, LISTSPOINTY, LISTSPOINTX - 5, LISTLPOINTY - 2);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	
	int x1 = LISTSPOINTX - 11, x2 = LISTSPOINTX - 17, x3 = LISTSPOINTX - 5;
	int y1 = LISTSPOINTY, y2 = LISTSPOINTY + 8, y3 = LISTSPOINTY + 8;

	int poly[8] = {x1, y1, x2, y2, x3, y3, x1, y1};
	fillpoly(3, poly);
	
	x1 = LISTSPOINTX - 11; x2 = LISTSPOINTX - 17; x3 = LISTSPOINTX - 5;
	y1 = LISTLPOINTY - 2; y2 = LISTLPOINTY - 10; y3 = LISTLPOINTY - 10;
	  
	int poly2[8] = {x1, y1, x2, y2, x3, y3, x1, y1};
	fillpoly(3, poly2);
	
	int part = ceil((float)sizeClass / 12);
	
	int dy = (LISTLPOINTY - LISTSPOINTY - 22) / part ;
	
	int currentPart = ceil((float)firstStudent / 12);
	
	int y = LISTSPOINTY + 11;
	
	y += dy * (currentPart - 1);
	
	bar(LISTSPOINTX - 17, y,LISTSPOINTX - 5, y + dy);
	
	setDefault();
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
		outtextxy(10, MENUSPOINTY + 10, "Lop sinh vien");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
		outtextxy(10, MENUSPOINTY + 10, "Lop sinh vien");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY, MENUSPOINTX + 300, MENUSPOINTY + 40);
	
	// tao menu 2
	
	setcolor(BLACK);
	if(selected == 2){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
		outtextxy(10, MENUSPOINTY + 50 , "Lop tin chi");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
		outtextxy(10, MENUSPOINTY + 50 , "Lop tin chi");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
	
	// tao menu 3
	setcolor(BLACK);
	if(selected == 3){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 300, MENUSPOINTY + 120);
		outtextxy(10, MENUSPOINTY + 90, "Mon hoc");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 300, MENUSPOINTY + 120);
		outtextxy(10, MENUSPOINTY + 90, "Mon hoc");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX,  MENUSPOINTY + 80, MENUSPOINTX + 300, MENUSPOINTY + 120);

	
	// tao menu 4
	setcolor(BLACK);
	if(selected == 4){
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 300, MENUSPOINTY + 160);
		outtextxy(10, MENUSPOINTY + 130, "Diem");
	}
	else{
		setbkcolor(WHITE);
		setfillstyle(SOLID_FILL, WHITE);
		bar(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 300, MENUSPOINTY + 160);
		outtextxy(10, MENUSPOINTY + 130, "Diem");
	}
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 120, MENUSPOINTX + 300, MENUSPOINTY + 160);

	setDefault();
	createBottom();
	
}

void createTable(char *text){ // tao khung lon ben ngoai
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 60); 
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, text);
	
	setlinestyle(0, 0, 1);
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY); // can le
	
	setDefault();
}

void createList(){ // tao khung nho ben trong
	
	setfillstyle(SOLID_FILL, WHITE); // xoa sach thong tin the hien tren bang 
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
	
	line(TABLSPOINTX + 145, TABLSPOINTY, TABLSPOINTX + 145, TABLLPOINTY); // tao duong ke doc
	line(TABLSPOINTX + 365, TABLSPOINTY, TABLSPOINTX + 365, TABLLPOINTY);	
	line(TABLSPOINTX + 510, TABLSPOINTY, TABLSPOINTX + 510, TABLLPOINTY);	
	line(TABLSPOINTX + 610, TABLSPOINTY, TABLSPOINTX + 610, TABLLPOINTY);	
	line(TABLSPOINTX + 755, TABLSPOINTY, TABLSPOINTX + 755, TABLLPOINTY);	
	line(TABLSPOINTX + 900, TABLSPOINTY, TABLSPOINTX + 900, TABLLPOINTY);	
	
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
	
	setDefault();
}

void createListIdSubject(){
	
	setfillstyle(SOLID_FILL, WHITE);
	
	bar(TEXTSPOINTX1, TEXTLPOINTY1 + 1, TEXTLPOINTX1, TEXTLPOINTY1 + 240); // xoa list 
	
	setcolor(LIGHTGRAY);
	line(TEXTSPOINTX1, TEXTLPOINTY1, TEXTSPOINTX1, TEXTLPOINTY1 + 240);
	line(TEXTLPOINTX1, TEXTLPOINTY1, TEXTLPOINTX1, TEXTLPOINTY1 + 240);
	line(TEXTSPOINTX1, TEXTLPOINTY1 + 240, TEXTLPOINTX1, TEXTLPOINTY1 + 240);
	
	setDefault();
}

void createListYear(){
	setfillstyle(SOLID_FILL, WHITE);
	
	bar(TEXTSPOINTX2, TEXTLPOINTY2 + 1, TEXTLPOINTX2, TEXTLPOINTY2 + 120); // xoa list 
	
	setcolor(LIGHTGRAY);
	line(TEXTSPOINTX2, TEXTLPOINTY2, TEXTSPOINTX2, TEXTLPOINTY2 + 120);
	line(TEXTLPOINTX2, TEXTLPOINTY2, TEXTLPOINTX2, TEXTLPOINTY2 + 120);
	line(TEXTSPOINTX2, TEXTLPOINTY2 + 120, TEXTLPOINTX2, TEXTLPOINTY2 + 120);
	
	setDefault();
}

void createListSemester(){
	setfillstyle(SOLID_FILL, WHITE);
	
	bar(TEXTSPOINTX4, TEXTLPOINTY4 + 1, TEXTLPOINTX4, TEXTLPOINTY4 + 90); // xoa list 
	
	setcolor(LIGHTGRAY);
	line(TEXTSPOINTX4, TEXTLPOINTY4, TEXTSPOINTX4, TEXTLPOINTY4 + 90);
	line(TEXTLPOINTX4, TEXTLPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4 + 90);
	line(TEXTSPOINTX4, TEXTLPOINTY4 + 90, TEXTLPOINTX4, TEXTLPOINTY4 + 90);
	
	setDefault();
}

void createFormEditStudent(){
	setfillstyle(SOLID_FILL, WHITE);
	bar(FORMSPOINTX, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // xoa sach khong gian
	
	setcolor(LIGHTGRAY);
	rectangle(FORMSPOINTX, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // tao khung hinh chu nhat
	
	line(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // tao duong ke doc
	line(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);	
	line(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);	
	line(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);	
	line(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);	
	line(TABLSPOINTX + 900, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
	
	setcolor(BLACK);
	outtextxy(TABLSPOINTX + 10, FORMSPOINTY - 25, "Mssv");
	outtextxy(TABLSPOINTX + 155, FORMSPOINTY - 25, "Ho");
	outtextxy(TABLSPOINTX + 375, FORMSPOINTY - 25, "Ten");
	outtextxy(TABLSPOINTX + 520, FORMSPOINTY - 25, "Phai");
	outtextxy(TABLSPOINTX + 620, FORMSPOINTY - 25, "Sdt");
	outtextxy(TABLSPOINTX + 765, FORMSPOINTY - 25, "Ma lop");
	outtextxy(TABLSPOINTX + 910, FORMSPOINTY - 25, "Khoa");
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(FORMSPOINTX, TABLLPOINTY + 100, TABLSPOINTX + 145, TABLLPOINTY + 140);
	
	setbkcolor(LIGHTBLUE);
	outtextxy(FORMSPOINTX + 30, TABLLPOINTY + 110, "Update");
	setDefault();
}
void createFormStudent(){ // createTypeInforStudentBox : tao khung nhap thong tin student
	setfillstyle(SOLID_FILL, WHITE);
	bar(FORMSPOINTX, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // xoa sach khong gian
	
	setcolor(LIGHTGRAY);
	rectangle(FORMSPOINTX, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // tao khung hinh chu nhat
	
	line(TABLSPOINTX + 145, FORMSPOINTY, TABLSPOINTX + 145, FORMLPOINTY); // tao duong ke doc
	line(TABLSPOINTX + 365, FORMSPOINTY, TABLSPOINTX + 365, FORMLPOINTY);	
	line(TABLSPOINTX + 510, FORMSPOINTY, TABLSPOINTX + 510, FORMLPOINTY);	
	line(TABLSPOINTX + 610, FORMSPOINTY, TABLSPOINTX + 610, FORMLPOINTY);	
	line(TABLSPOINTX + 755, FORMSPOINTY, TABLSPOINTX + 755, FORMLPOINTY);	
	line(TABLSPOINTX + 900, FORMSPOINTY, TABLSPOINTX + 900, FORMLPOINTY);
	
	setcolor(BLACK);
	outtextxy(TABLSPOINTX + 10, FORMSPOINTY - 25, "Mssv");
	outtextxy(TABLSPOINTX + 155, FORMSPOINTY - 25, "Ho");
	outtextxy(TABLSPOINTX + 375, FORMSPOINTY - 25, "Ten");
	outtextxy(TABLSPOINTX + 520, FORMSPOINTY - 25, "Phai");
	outtextxy(TABLSPOINTX + 620, FORMSPOINTY - 25, "Sdt");
	outtextxy(TABLSPOINTX + 765, FORMSPOINTY - 25, "Khoa");
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(TABLSPOINTX + 900, FORMSPOINTY, FORMLPOINTX, FORMLPOINTY); // Tao muc add
	setbkcolor(LIGHTBLUE);
	outtextxy(TABLSPOINTX + 930, FORMSPOINTY + 10, "Add");
	
	setDefault();	
}

void createListStudentWithClass(){
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 10); // xoa ta ca thong tin truoc do
	
	setcolor(LIGHTGRAY);
	rectangle(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTLPOINTY - 10); // tao khung to ben ngoai
	
	setfillstyle(SOLID_FILL, LIGHTBLUE); // tao thanh taskbar
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 40);
	
	int Y = LISTSPOINTY + 80; // tao duong ke ngang
	for(int i = 1; i <= 11; i++){
		line(LISTSPOINTX, Y, LISTLPOINTX, Y);
		Y += 40;
	}
	
	line(LISTSPOINTX + 145, LISTSPOINTY, LISTSPOINTX + 145, LISTLPOINTY - 10); // tao duong ke doc
	line(LISTSPOINTX + 365, LISTSPOINTY, LISTSPOINTX + 365, LISTLPOINTY - 10);	
	line(LISTSPOINTX + 510, LISTSPOINTY, LISTSPOINTX + 510, LISTLPOINTY - 10);	
	line(LISTSPOINTX + 610, LISTSPOINTY, LISTSPOINTX + 610, LISTLPOINTY - 10);	
	line(LISTSPOINTX + 755, LISTSPOINTY, LISTSPOINTX + 755, LISTLPOINTY - 10);	
	line(LISTSPOINTX + 900, LISTSPOINTY, LISTSPOINTX + 900, LISTLPOINTY - 10);
	
	setbkcolor(LIGHTBLUE);
	setcolor(WHITE);
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, "Mssv");
	outtextxy(LISTSPOINTX + 155, LISTSPOINTY + 10, "Ho");
	outtextxy(LISTSPOINTX + 375, LISTSPOINTY + 10, "Ten");
	outtextxy(LISTSPOINTX + 520, LISTSPOINTY + 10, "Phai");
	outtextxy(LISTSPOINTX + 620, LISTSPOINTY + 10, "Sdt");
	outtextxy(LISTSPOINTX + 765, LISTSPOINTY + 10, "Ma lop");
	outtextxy(LISTSPOINTX + 910, LISTSPOINTY + 10, "Khoa");
	
	setDefault();
}
void drawEditStudent(){
	
	// an (xoa) cac muc them, xoa thong tin
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140);
	bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
	setDefault();
	
	createFormEditStudent();
	
	setDefault();
}
void drawInsertStudent(){
	
	// an (xoa) cac muc sua, xoa thong tin 
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
	bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
	setDefault();
	
	createBox(BLACK, "Vui long nhap Ma lop:");
	createList();
	createFormStudent();
	
	setDefault();
}

void drawUpdateStudent(){
	
	createTable("Tra cuu thong tin");
	createList();
	createBox(BLACK, "Vui long nhap MSSV:");
	
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	setbkcolor(LIGHTGRAY);
	bar(TABLSPOINTX + 85, TABLLPOINTY + 100, TABLSPOINTX + 305, TABLLPOINTY + 140);
	outtextxy(TABLSPOINTX + 115, TABLLPOINTY + 110, "Them thong tin");
	bar(TABLSPOINTX + 390, TABLLPOINTY + 100, TABLSPOINTX + 610, TABLLPOINTY + 140);
	outtextxy(TABLSPOINTX + 420, TABLLPOINTY + 110, "Sua thong tin");
	bar(TABLSPOINTX + 695, TABLLPOINTY + 100, TABLSPOINTX + 915, TABLLPOINTY + 140);
	outtextxy(TABLSPOINTX + 725, TABLLPOINTY + 110, "Xoa thong tin");
	setDefault();
}


void drawDisplayStudentWithClass(listClass &lc, int currentClass, int selected){
	// ve bang liet ke danh sach lop
	
	int ClASSPOINTX = MENUSPOINTX + 150, CLASLPOINTX = MENUSPOINTX + 290;
	int CLASSPOINTY = MENUSPOINTY + 155, CLASLPOINTY = MENUSPOINTY + 155;
	
	int firstClass = currentClass - selected; // lop hien tai in ra o vi tri selected do do tim cac lop truoc do de in ra cac muc truoc do
	
	for(int i = firstClass; i < firstClass + 8 ; i++){
		
		if(i < lc.size && i == currentClass){ // neu i dang la lop hien tai thi in ra mau xanh
			setcolor(LIGHTBLUE);
			outtextxy(ClASSPOINTX + 20, CLASSPOINTY -25, tochar(lc.idClass[i]));
		}
		else if(i < lc.size){ // neu i khac voi lop hien tai thi in ra mau den
			setcolor(BLACK);
			outtextxy(ClASSPOINTX + 20, CLASSPOINTY -25, tochar(lc.idClass[i]));
		}
		setcolor(LIGHTGRAY);
		line(ClASSPOINTX, CLASSPOINTY, CLASLPOINTX, CLASLPOINTY);
		CLASSPOINTY += 30;
		CLASLPOINTY += 30;
	}
	// ve cac duong ke trong danh sach lop
	setDefault();
}


void drawListClassForSubject(listClassForSubject &lcfs, listSubject &lsj, int currentClass, int selected){
	
	if(lcfs.size == 0){
		setfillstyle(SOLID_FILL, WHITE);
		bar(LISTSPOINTX + 41, LISTSPOINTY + 81, LISTLPOINTX, LISTSPOINTY + 389); // xoa du lieu trong bang
		
		setcolor(LIGHTGRAY);
		setbkcolor(WHITE);
		outtextxy(LISTSPOINTX + 400, LISTSPOINTY + 85, "Khong co du lieu ..."); 
		
		setDefault();
		return;
	}
	
	int CLASSPOINTY = LISTSPOINTY + 85;
	
	int firstClass = currentClass - selected; // lop hien tai in ra o vi tri selected do do tim cac lop truoc do de in ra cac muc truoc do
	
	setbkcolor(WHITE);
	bar(LISTSPOINTX + 41, LISTSPOINTY + 81, LISTLPOINTX, LISTSPOINTY + 389);
	
	for(int i = firstClass; i < firstClass + 10 ; i++){
		
		if(i < lcfs.size && i == currentClass){ // neu i dang la lop hien tai thi in ra mau xanh
		
			setfillstyle(SOLID_FILL, LIGHTBLUE);
			bar(LISTSPOINTX + 41, CLASSPOINTY - 5, LISTLPOINTX, CLASSPOINTY + 25);
			
			setbkcolor(LIGHTBLUE);
			setcolor(BLACK);
			outtextxy(LISTSPOINTX + 50, CLASSPOINTY, tochar(formatIdClass(lcfs.list[i]->idclass)));
			outtextxy(LISTSPOINTX + 150, CLASSPOINTY, tochar(findNameSubject(lcfs.list[i]->idSubject, lsj.root))); // findNameSubject trong datastructure
			outtextxy(LISTSPOINTX + 500, CLASSPOINTY, tochar(to_string(lcfs.list[i]->academicYear)));
			outtextxy(LISTSPOINTX + 580, CLASSPOINTY, tochar(to_string(lcfs.list[i]->semester)));
			outtextxy(LISTSPOINTX + 660, CLASSPOINTY, tochar(to_string(lcfs.list[i]->group)));
			outtextxy(LISTSPOINTX + 740, CLASSPOINTY, tochar(to_string(lcfs.list[i]->studentMin)));
			outtextxy(LISTSPOINTX + 820, CLASSPOINTY, tochar(to_string(lcfs.list[i]->studentMax)));
			
			if(lcfs.list[i]->lr->size < lcfs.list[i]->studentMin){
				outtextxy(LISTSPOINTX + 900, CLASSPOINTY, "Thieu SV");
			}
			else{
				outtextxy(LISTSPOINTX + 900, CLASSPOINTY, "Du DK");
			}
			
			// trang thai in ra o day .......
			setDefault();
		}
		else if(i < lcfs.size){ // neu i khac voi lop hien tai thi in ra mau den
			
			setcolor(BLACK);
			outtextxy(LISTSPOINTX + 50, CLASSPOINTY, tochar(formatIdClass(lcfs.list[i]->idclass)));
			outtextxy(LISTSPOINTX + 150, CLASSPOINTY, tochar(findNameSubject(lcfs.list[i]->idSubject, lsj.root)));
			outtextxy(LISTSPOINTX + 500, CLASSPOINTY, tochar(to_string(lcfs.list[i]->academicYear)));
			outtextxy(LISTSPOINTX + 580, CLASSPOINTY, tochar(to_string(lcfs.list[i]->semester)));
			outtextxy(LISTSPOINTX + 660, CLASSPOINTY, tochar(to_string(lcfs.list[i]->group)));
			outtextxy(LISTSPOINTX + 740, CLASSPOINTY, tochar(to_string(lcfs.list[i]->studentMin)));
			outtextxy(LISTSPOINTX + 820, CLASSPOINTY, tochar(to_string(lcfs.list[i]->studentMax)));
			
			if(lcfs.list[i]->lr->size < lcfs.list[i]->studentMin){
				setcolor(LIGHTRED);
				outtextxy(LISTSPOINTX + 900, CLASSPOINTY, "Thieu SV");
			}
			else{
				outtextxy(LISTSPOINTX + 900, CLASSPOINTY, "Du DK");
			}
			// trang thai in o day 
			setDefault();
		}
		CLASSPOINTY += 30;
	}
	
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX + 140, LISTSPOINTY + 40, LISTSPOINTX + 140, LISTSPOINTY + 390);
	line(LISTSPOINTX + 490, LISTSPOINTY + 40, LISTSPOINTX + 490, LISTSPOINTY + 390);
	line(LISTSPOINTX + 570, LISTSPOINTY + 40, LISTSPOINTX + 570, LISTSPOINTY + 390);
	line(LISTSPOINTX + 650, LISTSPOINTY + 40, LISTSPOINTX + 650, LISTSPOINTY + 390);
	line(LISTSPOINTX + 730, LISTSPOINTY + 40, LISTSPOINTX + 730, LISTSPOINTY + 390);
	line(LISTSPOINTX + 810, LISTSPOINTY + 40, LISTSPOINTX + 810, LISTSPOINTY + 390);
	line(LISTSPOINTX + 890, LISTSPOINTY + 40, LISTSPOINTX + 890, LISTSPOINTY + 390);
	// ve cac duong ke trong danh sach lop
	setDefault();
}

void drawDeleteStudent(string text, int selected){
	
	setbkcolor(WHITE);
	setcolor(LIGHTRED);
	outtextxy(FORMSPOINTX + 10, FORMSPOINTY + 10, tochar(text));
	setcolor(BLACK);
	
	if(selected == 1){ /// tao muc yes / no 
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(TABLSPOINTX + 695, FORMSPOINTY, TABLSPOINTX + 805, FORMLPOINTY);
		outtextxy(TABLSPOINTX + 735, FORMSPOINTY + 10, "Co");
		
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(TABLSPOINTX + 805, FORMSPOINTY, TABLSPOINTX + 915, FORMLPOINTY);
		outtextxy(TABLSPOINTX + 825, FORMSPOINTY + 10, "Khong");
	}
	else if(selected == 2){
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		bar(TABLSPOINTX + 695, FORMSPOINTY, TABLSPOINTX + 805, FORMLPOINTY);
		outtextxy(TABLSPOINTX + 735, FORMSPOINTY + 10, "Co");
		
		setbkcolor(LIGHTBLUE);
		setfillstyle(SOLID_FILL, LIGHTBLUE);
		bar(TABLSPOINTX + 805, FORMSPOINTY, TABLSPOINTX + 915, FORMLPOINTY);
		outtextxy(TABLSPOINTX + 825, FORMSPOINTY + 10, "Khong");
	}

	setDefault();
}


void drawStudentManagement(int selected){
	char text[50] = "Lop sinh vien";
	
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
	line(MENUSPOINTX + 10, MENUSPOINTY + 45, MENUSPOINTX + 290, MENUSPOINTY + 45); // Tao duong ke ngang cho menu
	line(MENUSPOINTX + 10, MENUSPOINTY + 85, MENUSPOINTX + 290, MENUSPOINTY + 85);
	line(MENUSPOINTX + 10, MENUSPOINTY + 125, MENUSPOINTX + 290, MENUSPOINTY + 125);
//	line(MENUSPOINTX + 10,  MENUSPOINTY + 165, MENUSPOINTX + 290, MENUSPOINTY + 165);
//	line(MENUSPOINTX + 10, MENUSPOINTY + 205, MENUSPOINTX + 290, MENUSPOINTY + 205);

	setDefault();
}


void drawOpenClass(){
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(LISTSPOINTX, LISTSPOINTY - 10, LISTLPOINTX, LISTLPOINTY - 5);
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setbkcolor(WHITE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 40);
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, "Mo lop tin chi");
	
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY);
	
	rectangle(TEXTSPOINTX1, TEXTSPOINTY1, TEXTLPOINTX1, TEXTLPOINTY1);
	rectangle(TEXTSPOINTX2, TEXTSPOINTY2, TEXTLPOINTX2, TEXTLPOINTY2);
	rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
	rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
	rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
	rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(TEXTSPOINTX1 + 10, TEXTSPOINTY1 - 25, "Ma - Ten mon hoc");
	outtextxy(TEXTSPOINTX2 + 10, TEXTSPOINTY2 - 25, "Nien khoa");
	outtextxy(TEXTSPOINTX3 + 10, TEXTSPOINTY3 - 25, "So SV toi thieu");
	outtextxy(TEXTSPOINTX4 + 10, TEXTSPOINTY4 - 25, "Hoc ky");
	outtextxy(TEXTSPOINTX5 + 10, TEXTSPOINTY5 - 25, "So SV toi da");
	outtextxy(TEXTSPOINTX6 + 10, TEXTSPOINTY6 - 25, "Nhom");

	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setbkcolor(LIGHTBLUE);
	setcolor(BLACK);
	bar(OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY);
	
	outtextxy(OPENSPOINTX + 65, OPENSPOINTY + 10, "Mo lop");
	
//	settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
//	setbkcolor(WHITE);
//	setcolor(LIGHTGRAY);
//	outtextxy(TEXTLPOINTX1 - 20, TEXTSPOINTY1 + 10, "v");
//	outtextxy(TEXTLPOINTX2 - 20, TEXTSPOINTY2 + 10, "v");
//	outtextxy(TEXTLPOINTX4 - 20, TEXTSPOINTY4 + 10, "v");
	
	setDefault();
}

void drawEditClass(){
	
	setfillstyle(SOLID_FILL, WHITE);
	bar(LISTSPOINTX, LISTSPOINTY - 10, LISTLPOINTX, LISTLPOINTY - 5);
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setbkcolor(WHITE);
	bar(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 40);
	outtextxy(LISTSPOINTX + 10, LISTSPOINTY + 10, "Sua lop tin chi");
	
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX, LISTSPOINTY, LISTSPOINTX, LISTLPOINTY);
	
	rectangle(TEXTSPOINTX3, TEXTSPOINTY3, TEXTLPOINTX3, TEXTLPOINTY3);
	rectangle(TEXTSPOINTX5, TEXTSPOINTY5, TEXTLPOINTX5, TEXTLPOINTY5);
	rectangle(TEXTSPOINTX6, TEXTSPOINTY6, TEXTLPOINTX6, TEXTLPOINTY6);
	
	rectangle(TEXTSPOINTX1, TEXTSPOINTY1, TEXTLPOINTX1, TEXTLPOINTY1);
	rectangle(TEXTSPOINTX2, TEXTSPOINTY2, TEXTLPOINTX2, TEXTLPOINTY2);
	rectangle(TEXTSPOINTX4, TEXTSPOINTY4, TEXTLPOINTX4, TEXTLPOINTY4);
	
	setbkcolor(WHITE);
	setcolor(BLACK);
	outtextxy(TEXTSPOINTX1 + 10, TEXTSPOINTY1 - 25, "Ma - Ten mon hoc");
	outtextxy(TEXTSPOINTX2 + 10, TEXTSPOINTY2 - 25, "Nien khoa");
	outtextxy(TEXTSPOINTX3 + 10, TEXTSPOINTY3 - 25, "So SV toi thieu");
	outtextxy(TEXTSPOINTX4 + 10, TEXTSPOINTY4 - 25, "Hoc ky");
	outtextxy(TEXTSPOINTX5 + 10, TEXTSPOINTY5 - 25, "So SV toi da");
	outtextxy(TEXTSPOINTX6 + 10, TEXTSPOINTY6 - 25, "Nhom");

	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setbkcolor(LIGHTBLUE);
	setcolor(BLACK);
	bar(OPENSPOINTX, OPENSPOINTY, OPENLPOINTX, OPENLPOINTY);
	
	outtextxy(OPENSPOINTX + 65, OPENSPOINTY + 10, "Hoan tat");
	
//	settextstyle(GOTHIC_FONT, HORIZ_DIR, 1);
//	setbkcolor(WHITE);
//	setcolor(LIGHTGRAY);
//	outtextxy(TEXTLPOINTX1 - 20, TEXTSPOINTY1 + 10, "v");
//	outtextxy(TEXTLPOINTX2 - 20, TEXTSPOINTY2 + 10, "v");
//	outtextxy(TEXTLPOINTX4 - 20, TEXTSPOINTY4 + 10, "v");
	
	setDefault();
}

void drawOpenClassForSubject(){
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX, HEADLPOINTY, LISTSPOINTX, LISTLPOINTY);
	
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	setbkcolor(WHITE);
	setcolor(BLACK);
	bar(LISTSPOINTX + 40, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY + 40);
	outtextxy(LISTSPOINTX + 50, LISTSPOINTY + 10, "Danh sach lop tin chi");
	
	setcolor(LIGHTGRAY);
	line(LISTSPOINTX + 40, LISTSPOINTY, LISTLPOINTX, LISTSPOINTY);
	line(LISTSPOINTX + 40, LISTSPOINTY + 80, LISTLPOINTX, LISTSPOINTY + 80);
	line(LISTSPOINTX + 40, LISTSPOINTY + 390, LISTLPOINTX, LISTSPOINTY + 390);
	line(LISTSPOINTX + 40, LISTSPOINTY, LISTSPOINTX + 40, LISTSPOINTY + 390);
	
	// tao duong ke doc 
	
	line(LISTSPOINTX + 140, LISTSPOINTY + 40, LISTSPOINTX + 140, LISTSPOINTY + 390);
	line(LISTSPOINTX + 490, LISTSPOINTY + 40, LISTSPOINTX + 490, LISTSPOINTY + 390);
	line(LISTSPOINTX + 570, LISTSPOINTY + 40, LISTSPOINTX + 570, LISTSPOINTY + 390);
	line(LISTSPOINTX + 650, LISTSPOINTY + 40, LISTSPOINTX + 650, LISTSPOINTY + 390);
	line(LISTSPOINTX + 730, LISTSPOINTY + 40, LISTSPOINTX + 730, LISTSPOINTY + 390);
	line(LISTSPOINTX + 810, LISTSPOINTY + 40, LISTSPOINTX + 810, LISTSPOINTY + 390);
	line(LISTSPOINTX + 890, LISTSPOINTY + 40, LISTSPOINTX + 890, LISTSPOINTY + 390);
	
	setcolor(LIGHTBLUE);
	outtextxy(LISTSPOINTX + 50, LISTSPOINTY + 50, "Ma Lop");
	outtextxy(LISTSPOINTX + 250, LISTSPOINTY + 50, "Mon giang day");
	outtextxy(LISTSPOINTX + 500, LISTSPOINTY + 50, "N.Khoa");
	outtextxy(LISTSPOINTX + 580, LISTSPOINTY + 50, "Hoc ky");
	outtextxy(LISTSPOINTX + 670, LISTSPOINTY + 50, "Nhom");
	outtextxy(LISTSPOINTX + 750, LISTSPOINTY + 50, "SVTT");
	outtextxy(LISTSPOINTX + 830, LISTSPOINTY + 50, "SVTD");
	outtextxy(LISTSPOINTX + 895, LISTSPOINTY + 50, "Trang thai");
	
	setcolor(BLACK);
	outtextxy(LISTSPOINTX + 40, LISTSPOINTY + 410, "Tim kiem");
	rectangle(LISTSPOINTX + 150, LISTSPOINTY + 400, LISTSPOINTX + 340, LISTSPOINTY + 430);
	
	setfillstyle(SOLID_FILL, LIGHTGRAY);
	bar(LISTSPOINTX + 40, LISTSPOINTY + 460, LISTSPOINTX + 210, LISTSPOINTY + 500);
	bar(LISTSPOINTX + 290, LISTSPOINTY + 460, LISTSPOINTX + 460, LISTSPOINTY + 500);
	bar(LISTSPOINTX + 540, LISTSPOINTY + 460, LISTSPOINTX + 710, LISTSPOINTY + 500);
	bar(LISTSPOINTX + 790, LISTSPOINTY + 460, LISTSPOINTX + 960, LISTSPOINTY + 500);
	
	setcolor(BLACK);
	setbkcolor(LIGHTGRAY);
	outtextxy(LISTSPOINTX + 90, LISTSPOINTY + 470, "MO LOP");
	outtextxy(LISTSPOINTX + 340, LISTSPOINTY + 470, "SUA LOP");
	outtextxy(LISTSPOINTX + 590, LISTSPOINTY + 470, "XOA LOP");
	outtextxy(LISTSPOINTX + 840, LISTSPOINTY + 470, "HUY LOP");	
	
	setDefault();
}

void drawDelete(int dele){
	string text = "Chan chan xoa lop hien tai!"; 
	setbkcolor(WHITE);
	setcolor(LIGHTRED);
	outtextxy(OPENSPOINTX - 300, OPENSPOINTY - 50, tochar(text));
	if(dele == 1){ /// tao muc yes / no 
		setbkcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		setcolor(BLACK);
		bar(OPENSPOINTX + 40, OPENSPOINTY - 60, OPENSPOINTX + 145, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 80, OPENSPOINTY - 50, "Co");
		
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(BLACK);
		bar(OPENSPOINTX + 145, OPENSPOINTY - 60, OPENSPOINTX + 255, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 170, OPENSPOINTY - 50, "Khong");
	}
	else if(dele == 0){
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(BLACK);
		bar(OPENSPOINTX + 40, OPENSPOINTY - 60, OPENSPOINTX + 145, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 80, OPENSPOINTY - 50, "Co");
		
		setbkcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		setcolor(BLACK);
		bar(OPENSPOINTX + 145, OPENSPOINTY - 60, OPENSPOINTX + 255, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 170, OPENSPOINTY - 50, "Khong");
	}
	setDefault();
}

void drawEdit(int edit){
	string text = "Chan chan da hoan tat!"; 
	setbkcolor(WHITE);
	setcolor(LIGHTRED);
	outtextxy(OPENSPOINTX - 300, OPENSPOINTY - 50, tochar(text));
	if(edit == 1){ /// tao muc yes / no 
		setbkcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		setcolor(BLACK);
		bar(OPENSPOINTX, OPENSPOINTY - 60, OPENSPOINTX + 105, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 40, OPENSPOINTY - 50, "Co");
		
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(BLACK);
		bar(OPENSPOINTX + 105, OPENSPOINTY - 60, OPENSPOINTX + 210, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 130, OPENSPOINTY - 50, "Khong");
	}
	else if(edit == 0){
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(BLACK);
		bar(OPENSPOINTX, OPENSPOINTY - 60, OPENSPOINTX + 105, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 40, OPENSPOINTY - 50, "Co");
		
		setbkcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		setcolor(BLACK);
		bar(OPENSPOINTX + 105, OPENSPOINTY - 60, OPENSPOINTX + 210, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 130, OPENSPOINTY - 50, "Khong");
	}
	setDefault();
}
void drawOpen(int &open){
	
	string text = "Chan chan mo Lop"; 
	setbkcolor(WHITE);
	setcolor(LIGHTRED);
	outtextxy(OPENSPOINTX - 300, OPENSPOINTY - 50, tochar(text));
	if(open == 1){ /// tao muc yes / no 
		setbkcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		setcolor(BLACK);
		bar(OPENSPOINTX, OPENSPOINTY - 60, OPENSPOINTX + 105, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 40, OPENSPOINTY - 50, "Co");
		
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(BLACK);
		bar(OPENSPOINTX + 105, OPENSPOINTY - 60, OPENSPOINTX + 210, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 130, OPENSPOINTY - 50, "Khong");
	}
	else if(open == 0){
		setbkcolor(LIGHTGRAY);
		setfillstyle(SOLID_FILL, LIGHTGRAY);
		setcolor(BLACK);
		bar(OPENSPOINTX, OPENSPOINTY - 60, OPENSPOINTX + 105, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 40, OPENSPOINTY - 50, "Co");
		
		setbkcolor(BLUE);
		setfillstyle(SOLID_FILL, BLUE);
		setcolor(BLACK);
		bar(OPENSPOINTX + 105, OPENSPOINTY - 60, OPENSPOINTX + 210, OPENLPOINTY - 60);
		outtextxy(OPENSPOINTX + 130, OPENSPOINTY - 50, "Khong");
	}
	setDefault();
}
void drawClassForSubjectManagement(int selected){
	
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
	
	setbkcolor(LIGHTBLUE);
	setfillstyle(SOLID_FILL, LIGHTBLUE);
	bar(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80);
	outtextxy(10, MENUSPOINTY + 50, "Lop tin chi");
	setcolor(LIGHTGRAY);
	rectangle(MENUSPOINTX, MENUSPOINTY + 40, MENUSPOINTX + 300, MENUSPOINTY + 80); 
	setDefault();
	
	// bat dau tao menu con 
	sprintf(text, "%c Mo lop tin chi", 62);
	setcolor(BLACK);
	if(selected == 1){
		setcolor(LIGHTBLUE);
		outtextxy(10, MENUSPOINTY + 95, text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 95, text);
	}

	// tao menu 2
	
	sprintf(text, "%c Danh sach dang ky", 62);
	setcolor(BLACK);
	if(selected == 2){
		setcolor(LIGHTBLUE);
		outtextxy(10, MENUSPOINTY + 135 , text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 135 , text);
	}
	
	sprintf(text, "%c Huy lop tin chi", 62);
	setcolor(BLACK);
	if(selected == 3){
		setcolor(LIGHTBLUE);
		outtextxy(10, MENUSPOINTY + 175 , text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 175 , text);
	}
	
	sprintf(text, "%c Dang ki lop tin chi", 62);
	setcolor(BLACK);
	if(selected == 4){
		setcolor(LIGHTBLUE);
		outtextxy(10, MENUSPOINTY + 215 , text);
	}
	else{
		outtextxy(10, MENUSPOINTY + 215 , text);
	}
	
	setcolor(LIGHTGRAY); // Tao duong ke ngang cho menu
	line(MENUSPOINTX + 10, MENUSPOINTY + 85, MENUSPOINTX + 290, MENUSPOINTY + 85);
	line(MENUSPOINTX + 10, MENUSPOINTY + 125, MENUSPOINTX + 290, MENUSPOINTY + 125);
	line(MENUSPOINTX + 10,  MENUSPOINTY + 165, MENUSPOINTX + 290, MENUSPOINTY + 165);
	line(MENUSPOINTX + 10, MENUSPOINTY + 205, MENUSPOINTX + 290, MENUSPOINTY + 205);
	line(MENUSPOINTX + 10, MENUSPOINTY + 245, MENUSPOINTX + 290, MENUSPOINTY + 245);
	
	
	setDefault();
	
}



#endif
