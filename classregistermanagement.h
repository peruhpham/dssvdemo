#ifndef CLASSREGISTERMANAGEMENT_H
#define CLASSREGISTERMANAGEMENT_H

//void classRegisterManagement(listRegister &lr){
//	// xu ly
//}

//===Quan li Danh sach Dang ki=== 
// ds lien ket don
struct Register{  
    string idStudent;
    double scores;
    bool unSub;
};

struct nodeRegister{ 
    Register data;
    nodeRegister *next;
    nodeRegister(Register data){
        this->data=data;
        this->next=NULL;
    }
};

typedef nodeRegister *ptrRegister;


 struct listRegister{
     int size;
     ptrRegister head;
     listRegister(){
         this->size=0;
         this->head=NULL;
     }
 };

typedef listRegister *ptrListRegister; 


void insertRegister(listRegister &lr, Register data){
	ptrRegister newnode = new nodeRegister(data);
    ptrRegister cur = lr.head;
    
    if(cur == NULL){ // truong hop rong
    	lr.head = newnode;
    	return;
	}
	
	for(cur; cur->next != NULL && cur->next->data.idStudent <= data.idStudent; cur = cur->next);
	
	if(cur->data.idStudent > data.idStudent){
		newnode->next = lr.head;
		lr.head = newnode;
		return;
	}
	
	if(cur->data.idStudent < data.idStudent){
		newnode->next = cur->next;
		cur->next = newnode;
		return;
	}
	return;
}


void readListRegister(listRegister &lr, string nameFileListStudent){
    ifstream f;
    f.open(nameFileListStudent, ios::in);
    if(!f.is_open()){
        cout << "fail open!" << endl;
        return;
    }
    cout << "complete open!" << endl; // doc file
    
    Register e;
    while(!f.eof()){
        
        getline(f,e.idStudent,'#');
        f>>e.scores;f.ignore();
        f>>e.unSub;f.ignore();
         
        insertRegister(lr,e);
    }
    f.close();
}

void displayRegister(listRegister &lr){
    ptrRegister p = lr.head;
    while(p != NULL){
    	cout << p->data.idStudent << " " << p->data.scores << " ";
    	if(p->data.unSub) cout << "da dang ky!" << endl;
    	p = p->next;	
	}
}


#endif
