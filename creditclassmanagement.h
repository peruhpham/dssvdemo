#ifndef CREDITCLASSMANAGEMENT_H
#define CREDITCLASSMANAGEMENT_H


#define MAXCLASS 10000

string formatIdClass(int &IdClass){
	string temp = "";
	temp = string(5 - to_string(IdClass).size(), '0') + to_string(IdClass);
	return temp;
}

// danh sach lop tinchi 

struct classForSubject{
	string idclass;// tu dong tang 
	string idSubject;
	string academicYear;//Niên Khoa 
	int semester;//Hoc ky 
	int group;
	int studentMin;
	int studentMax;
	bool unClass;
	ptrListRegister lr;
	classForSubject(){
		this->lr = NULL;
	}
}; 

static int count =1; 

typedef classForSubject *ptrClassForSubject;

struct listClassForSubject{
    ptrClassForSubject list[MAXCLASS];
    int size ;
    listClassForSubject(){
    	this->size = 0;																																	
	}
};

int addClassForSubject(listClassForSubject &lcfs, ptrClassForSubject &data){
	if(lcfs.size == MAXCLASS) return 0; // danh sach day 
	lcfs.list[lcfs.size] = data;	
	lcfs.size += 1;

	return 1;
} 


void displayListClassForSubject(listClassForSubject lcfs){
	for(int i = 0; i < lcfs.size; i++){
		cout << lcfs.list[i]->idclass << " " << lcfs.list[i]->idSubject << " " << lcfs.list[i]->academicYear;
		cout << " " << lcfs.list[i]->semester << " " << lcfs.list[i]->group << " " << lcfs.list[i]->studentMin;
		cout << " " << lcfs.list[i]->studentMax << " " << lcfs.list[i]->unClass;
		if(lcfs.list[i]->lr == NULL) cout << " Khong co sinh vien dang ky " << endl;
	}
}
void readListClassForSubject(listClassForSubject &lcfs, string nameFileListClassForSubject){
	ifstream f;
    f.open(nameFileListClassForSubject, ios::in);
    if(!f.is_open()){
        cout << "fail open file listclassforsubject!" << endl;
        return;
    }
    cout << "complete open file listclassforsubject!" << endl; // doc file
    
    cout << 1 << endl;
    while(!f.eof()){
    	
    	ptrClassForSubject p = new classForSubject;
    	
        string line;
        getline(f, line); 
        stringstream ss(line);
        
        getline(ss, p->idSubject, '#');
        getline(ss, p->academicYear, '#');
        ss >> p->semester; ss.ignore();
        ss >> p->group; ss.ignore();
        ss >> p->studentMin; ss.ignore();
        ss >> p->studentMax; ss.ignore();
        
        p->unClass = 1;
        
        int temp = lcfs.size + 1;
        p->idclass = formatIdClass(temp);
        addClassForSubject(lcfs, p);
    
    }
    f.close();
}

//int main(){
//	listClassForSubject lcfs; 
//	string nameFileListClassForSubject = "classforsubjectlist.txt";
//	
//	readListClassForSubject(lcfs, nameFileListClassForSubject);
//	
//	displayListClassForSubject(lcfs);
//}

#endif

