#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

// khai bao tat ca cau truct du lieu, cac ham thao tac voi cau truc du lieu : nhap, xoa

using namespace std;

#define MAXLISTCLASS 50
#define MAXCLASS 10000
#define emptyStr ""



int getAutoIdClass(){
	static int id = 0;
	return ++id;
}

// danh sach sinh vien 
//_______________________________________________________________________________________

struct student{    
    string id, firstName, lastName;
	string gender, phone, idClass;
	int year;
};

struct nodeStudent{
    student value;
    nodeStudent *next;
    nodeStudent(student value){
    	this->value = value;
    	this->next = NULL;
	}
};

typedef nodeStudent *ptrStudent;

struct listStudent{
	int size;
	ptrStudent head;
	listStudent(){
		this->size = 0;
		this->head = NULL;
	}
};

void addStudent(listStudent &ls,student x){ // chen co thu tu
    ptrStudent newnode = new nodeStudent(x);
    ptrStudent cur = ls.head;
    ptrStudent prev = NULL;
    
    if(cur == NULL){ // truong hop rong
    	ls.head = newnode;
    	return;
	}
	
	while(cur != NULL){;
		if(newnode->value.idClass < cur->value.idClass){
			if(prev == NULL){
				ls.head = newnode;
				newnode->next = cur;
			}
			else{
				prev->next = newnode; 
				newnode->next = cur;
			}
			return;
		}
		else if(newnode->value.idClass == cur->value.idClass){
			if(newnode->value.lastName < cur->value.lastName){
				if(prev == NULL){
					ls.head = newnode;
					newnode->next = cur;
				}
				else{
					prev->next = newnode; 
					newnode->next = cur;
				}
				return;
			}
			else if(newnode->value.lastName == cur->value.lastName){
				if(newnode->value.firstName < cur->value.firstName){
					if(prev == NULL){
						ls.head = newnode;
						newnode->next = cur;
					}
					else{
						prev->next = newnode; 
						newnode->next = cur;
					}
					return;
				}
				else if(newnode->value.firstName == cur->value.firstName){
					if(prev != NULL){
						prev->next = newnode; // chen sau
						newnode->next = cur;
						return;
					}
				}
			}
		}
		prev = cur;
		cur = cur->next;
	}
	
	if(prev != NULL){
		prev->next = newnode; // chen cuoi
	}
	
	return;
}

void removeStudent(listStudent &ls, student s){
	ptrStudent cur = ls.head;
	ptrStudent prev = NULL;
	
	if(cur == NULL){
		return;
	}
	if(cur->value.id == s.id){
		ls.head = cur->next;
		delete cur;
		return;
	}
	while(cur != NULL && cur->value.id != s.id){
		prev = cur;
		cur = cur->next;
	}
	
	if(cur == NULL) return; // khong tim thay du lieu
	
	prev->next = cur->next;
	delete cur;
}

void uploadStudent(listStudent &ls, student s){ // cap nhat thong tin 
	ptrStudent cur = ls.head;
	if(cur == NULL){
		return;
	}
	
	removeStudent(ls, s); // xoa sinh vien theo id;
	
	addStudent(ls, s); // them sinh vien vao danh sach co thu tu
}

// doc file 
void readListStudent(listStudent &ls, string nameFileListStudent){
    ifstream f;
    f.open(nameFileListStudent, ios::in);
    if(!f.is_open()){
        cout << "failed open list student!" << endl;
        return;
    }
    cout << "completed open list student!" << endl; // doc file
    
    student e;
    while(!f.eof()){
        
        string line, temp;
        getline(f, line); 
        stringstream ss(line);
        
        getline(ss, e.id, '#');
        getline(ss, e.firstName, '#');
        getline(ss, e.lastName, '#');
        getline(ss, e.gender, '#');
        getline(ss, e.phone, '#');
        getline(ss, e.idClass, '#');
        getline(ss, temp, '#');
        
        e.year = stringtoint(temp);
        addStudent(ls,e);
    }
    f.close();
}

void printfStudent(student stu){
    cout << stu.id << " " << stu.firstName << " " << stu.lastName << " " << stu.gender << " " << stu.phone << " " << stu.idClass << " " << stu.year << endl;
}
void displayStudentList(listStudent ls){
    ptrStudent p = ls.head;
    while(p != NULL){
        printfStudent(p->value);
        p = p->next;
    }
}


ptrStudent findPtrStudent(listStudent &ls, string id){
	ptrStudent cur = ls.head;
	
	while(cur != NULL){
		if(cur->value.id == id){
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}



// danh sach lop hoc 
//_______________________________________________________________________________________




struct listClass{
	int size;
	string idClass[MAXLISTCLASS]; // danh sach id lop hoc
	listClass(){
		this->size = 0;
	}
};

int addClass(listClass &lc,  string idClass){
	if(lc.size == MAXLISTCLASS) return 0;
	lc.idClass[lc.size] = idClass;
	lc.size += 1;
	return 1;
}

void displayListClass(listClass &lc){
	for(int i = 0; i < lc.size; i++){
		cout << lc.idClass[i] << endl;
	}
}

void readListClass(listClass &lc, string nameFileListClass){
	ifstream f;
	f.open(nameFileListClass, ios::in);
	if(!f.is_open()){
		cout << "failed open list class!" << endl;
		return;
	}
	cout << "completed open list class!" << endl;
	
	string idClass;
	
	while(!f.eof()){
		getline(f, idClass);
		addClass(lc, idClass);
	}
	f.close();
}


// danh sach dang ky 
//_______________________________________________________________________________________



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

void insertRegister(ptrListRegister &lr, Register data){
	ptrRegister newnode = new nodeRegister(data);
    ptrRegister cur = lr->head;
    
    if(cur == NULL){ // truong hop rong
    	lr->head = newnode;
    	lr->size += 1;
    	return;
	}
	
	for(cur; cur->next != NULL && cur->next->data.idStudent <= data.idStudent; cur = cur->next);
	
	if(cur->data.idStudent > data.idStudent){
		newnode->next = lr->head;
		lr->head = newnode;
		lr->size += 1;
		return;
	}
	
	if(cur->data.idStudent < data.idStudent){
		newnode->next = cur->next;
		cur->next = newnode;
		lr->size += 1;
		return;
	}

	return;
}
//void testReadListRegister(listClassForSubject &lcfs, listStudent &ls){
//	ptrStudent currentStudent = ls.head;
//	
//	Register r; 
//	for(int i = 0; i < lcfs.size; i++){
//		
//		cout << "__________" << i << "__________" << endl;
//		while(currentStudent != NULL){
//			// moi cur la mot ptrStudent
//			
//			r.idStudent = currentStudent->value.id;
//			r.scores = 0;
//			r.unSub = 0;
//
//			cout << &(lcfs.list[i]->lr) << endl;
//			insertRegister(lcfs.list[i]->lr, r);
//			currentStudent = currentStudent->next;
//		}
//		currentStudent = ls.head;
//		
//	}
//}

// danh sach lop theo mon hoc (lop tin chi)
//_______________________________________________________________________________________



struct classForSubject{
	int idclass;// tu dong tang 
	string idSubject;
	int academicYear;//Niên Khoa 
	int semester;//Hoc ky 
	int group;
	int studentMin;
	int studentMax;
	bool unClass;
	ptrListRegister lr;
	classForSubject(){
		this->lr = new listRegister;
		
		this->idclass = 0; this->idSubject = emptyStr;
		this->group = this->academicYear = this->semester = this->studentMax = this->studentMin = 0;
		this->unClass = true;
	}
}; 

typedef classForSubject *ptrClassForSubject;

struct listClassForSubject{
    ptrClassForSubject list[MAXCLASS];
    int size ;
    listClassForSubject(){
    	this->size = 0;																																	
	}
};

int addClassForSubject(listClassForSubject &lcfs, ptrClassForSubject &data){
	if(lcfs.size == MAXCLASS) return -1; // danh sach day 
	
	// kiem tra da ton tai hay chua
	for(int i = 0; i < lcfs.size; i++){ 
		if(lcfs.list[i]->idSubject == data->idSubject && lcfs.list[i]->academicYear == data->academicYear && 
		   lcfs.list[i]->semester == data->semester && lcfs.list[i]->group == data->group){
			return 0; // danh sach da co thong tin;
		}
	}
	
	data->idclass = getAutoIdClass();
	data->unClass = false;
	data->lr = new listRegister;
	
	lcfs.list[lcfs.size] = new classForSubject;

	*lcfs.list[lcfs.size] = *data;	
	lcfs.size += 1;

	return 1;
} 

int updateClassForSubject(listClassForSubject &lcfs, ptrClassForSubject &data, int currentClass){
	if(lcfs.size == MAXCLASS) return -1; // danh sach day 
	
	for(int i = 0; i < lcfs.size; i++){ // toi uu bang binary search;
		if(lcfs.list[i]->idSubject == data->idSubject && lcfs.list[i]->academicYear == data->academicYear && 
		    lcfs.list[i]->semester == data->semester && lcfs.list[i]->group == data->group && i != currentClass){
			return 0; // danh sach da co thong tin
		}
	}
	
	*lcfs.list[currentClass] = *data;
	return 1;
}

int deleteClassForSubject(listClassForSubject &lcfs, int currentClass){
	if(lcfs.size == 0) return 0;
	int i = currentClass;
	ptrClassForSubject temp = lcfs.list[i];
	while(i < lcfs.size - 1){
		lcfs.list[i] = lcfs.list[i + 1];
		i += 1;
	}
	lcfs.list[i] = NULL;
	delete temp;
	lcfs.size -= 1;
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
        cout << "fail open file list classforsubject!" << endl;
        return;
    }
    
    ptrClassForSubject p = new classForSubject;
    
    cout << "completed open file list classforsubject!" << endl; // doc file
    while(!f.eof()){
    	
        string line;
        getline(f, line); 
        stringstream ss(line);
        
        getline(ss, p->idSubject, '#');
        ss >> p->academicYear; ss.ignore();
        ss >> p->semester; ss.ignore();
        ss >> p->group; ss.ignore();
        ss >> p->studentMin; ss.ignore();
        ss >> p->studentMax; ss.ignore();
        
        addClassForSubject(lcfs, p);
    
    }
    f.close();
}

ptrClassForSubject findClassForSubject(listClassForSubject &lcfs, string idSubject, int academic, int semes, int group){
	for(int i = 0; i < lcfs.size; i++){ // toi uu bang binary search;
		if(lcfs.list[i]->idSubject == idSubject && lcfs.list[i]->academicYear ==academic && 
		    lcfs.list[i]->semester == semes && lcfs.list[i]->group == group){
			return lcfs.list[i]; // danh sach da co thong tin
		}
	}
	return NULL;
}



int existStudentHaveGrade(ptrListRegister &lr){
	ptrRegister p = lr->head;
	if(p == NULL) return 0;
	while(p != NULL){
		if(p->data.scores != 0){
			return 1;
		}
		p = p->next;
	}
	return 0;
}

int existStudentRegisting(listClassForSubject &lcfs, int currentClass){
	if(lcfs.list[currentClass]->lr->head != NULL) return 1;
	return 0;
}

// danh sach mon hoc 
//_______________________________________________________________________________________



struct subject {
    string idSubject;
	int STCLT, STCTH;
    string nameSubject;
    
    friend bool operator>(const subject& subject1, const subject& subject2);
    friend bool operator<(const subject& subject1, const subject& subject2);

};

bool operator>(const subject& subject1, const subject& subject2) {
    return subject1.idSubject > subject2.idSubject;
}

bool operator<(const subject& subject1, const subject& subject2) {
    return subject1.idSubject < subject2.idSubject;
}

//-----
struct nodeSubject {
    subject data;
    nodeSubject *left,*right;
    int height;
    nodeSubject(subject sub){
    	this->data = sub;
    	this->left = this->right = NULL;
    	this->height = 1;
	}
};


typedef nodeSubject *ptrSubject;

struct listSubject{
	ptrSubject root;
	int size;
	listSubject(){
		this->root = NULL;
		this->size = 0;
	}
};


int height(ptrSubject sub) {
    if (sub == nullptr) 
        return 0;
    return sub->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}



ptrSubject rightRotate(ptrSubject y) {
    ptrSubject x = y->left;
    ptrSubject T2 = x->right;

    // Perform rotation 
    x->right = y; 
    y->left = T2; 

    // Update heights 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 
    x->height = max(height(x->left), 
                    height(x->right)) + 1; 

    // Return new root 
    return x;
}

ptrSubject leftRotate(ptrSubject x) {
    ptrSubject y = x->right; 
    ptrSubject T2 = y->left; 

    // Perform rotation 
    y->left = x; 
    x->right = T2; 

    // Update heights 
    x->height = max(height(x->left),     
                    height(x->right)) + 1; 
    y->height = max(height(y->left), 
                    height(y->right)) + 1; 

    // Return new root 
    return y; 
} 



// Get Balance factor of node N 
int getBalance(ptrSubject N) { 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

ptrSubject insert(ptrSubject nodeSub, subject key) {
    if (nodeSub == nullptr)
        return new nodeSubject(key);

    if (key.idSubject < nodeSub->data.idSubject)
        nodeSub->left = insert(nodeSub->left, key);
    else if (key.idSubject > nodeSub->data.idSubject)
        nodeSub->right = insert(nodeSub->right, key);
    else
        return nodeSub;

    // Update height
    nodeSub->height = 1 + max(height(nodeSub->left), height(nodeSub->right));

    // Get balance
    int balance = getBalance(nodeSub);

    if (balance > 1 && key.idSubject < nodeSub->left->data.idSubject)
        return rightRotate(nodeSub);
    if (balance < -1 && key.idSubject > nodeSub->right->data.idSubject)
        return leftRotate(nodeSub);
    if (balance > 1 && key.idSubject > nodeSub->left->data.idSubject) {
        nodeSub->left = leftRotate(nodeSub->left);
        return rightRotate(nodeSub);
    }
    if (balance < -1 && key.idSubject < nodeSub->right->data.idSubject) {
        nodeSub->right = rightRotate(nodeSub->right);
        return leftRotate(nodeSub);
    }

    return nodeSub;
}


void readListSubject(listSubject &lsb, string nameFileSubjectList) {
	ptrSubject root = lsb.root;
	
    ifstream f(nameFileSubjectList);
    if (!f.is_open()) {
        cout << "fail open file subject!" << endl;
        return;
    }
    cout << "completed open file subject!" << endl;

    subject s;
    string line;
    while (getline(f, line)) {
        stringstream ss(line);

		getline(ss, s.idSubject, '#');
		getline(ss, s.nameSubject, '#');
		ss >> s.STCLT; ss.ignore();
		ss >> s.STCTH; ss.ignore();

        root = insert(root, s);
    }
    
    lsb.root = root;
    
    f.close();
}

string findNameSubject(string idSubject, ptrSubject root) {
    if (root == NULL) return emptyStr;
	if(idSubject > root->data.idSubject) return findNameSubject(idSubject, root->right);
	if(idSubject < root->data.idSubject) return findNameSubject(idSubject, root->left);
	return root->data.nameSubject;
}

ptrSubject findSubject(string idSubject, ptrSubject root){
	if (root == NULL) return NULL;
	if(idSubject > root->data.idSubject) return findSubject(idSubject, root->right);
	if(idSubject < root->data.idSubject) return findSubject(idSubject, root->left);
	return root;
}

void readListYear(int *academicYear, int &sizeYear){
	string nameFileListYear = "data\\yearlist.txt";
	ifstream f(nameFileListYear);
    if (!f.is_open()) {
        cout << "fail open file year!" << endl;
        return;
    }
    cout << "completed open file year!" << endl;

    int year;
    while (f >> year) {
        academicYear[sizeYear] = year;
        sizeYear += 1;
    }
    
    f.close();
}

void testReadListRegister(listClassForSubject &lcfs, listStudent &ls){
	ptrStudent currentStudent = ls.head;
	
	Register r; 
	for(int i = 0; i < lcfs.size; i++){
		while(currentStudent != NULL){
			// moi cur la mot ptrStudent
			
			r.idStudent = currentStudent->value.id;
			r.scores = 11;
			r.unSub = 0;
		
			insertRegister(lcfs.list[i]->lr, r);
			
			currentStudent = currentStudent->next;
		}
		currentStudent = ls.head;
		
	}
}
#endif
