#ifndef DATASTRUCTURE_H
#define DATASTRUCTURE_H

// khai bao tat ca cau truct du lieu, cac ham thao tac voi cau truc du lieu : nhap, xoa

using namespace std;

const int MAXLISTCLASS = 50;

// danh sach sinh vien 
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
    
    if(cur == NULL){ // truong hop rong
    	ls.head = newnode;
    	return;
	}
	for(cur; cur->next != NULL && cur->next->value.id <= x.id; cur = cur->next);
	
	if(cur->value.id > x.id){
		newnode->next = ls.head;
		ls.head = newnode;
		return;
	}
	if(cur->value.id < x.id){
		newnode->next = cur->next;
		cur->next = newnode;
		return;
	}
	return;
}

void uploadStudent(listStudent &ls, student s){
	ptrStudent cur = ls.head;
	if(cur == NULL){
		return;
	}
	while(cur != NULL){
		if(isSubString(s.id, cur->value.id)){
			cur->value = s;
			return;
		}
		cur = cur->next;
	}
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


// danh sach lop hoc 

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

// cay nhi phan 


//struct subject{
//	string idSubject, name;
//	string STCLT, STCTH;
//};
//
//struct nodeSubject{ // cau truc cay nhi phan can bang 
//	subject data;
//	int height;
//	nodeSubject *left, *right;
//};
//
//void init(nodeSubject *&root){
//	root = NULL;
//}
//
//nodeSubject* createNodeSubject(subject data){ // tao mot node voi voi gia tri da cho
//	nodeSubject *newNode = new nodeSubject;
//	newNode->data = data;
//	newNode->height = 1;
//	newNode->left = newNode->right = NULL;
//	return newNode;
//}
//
//int getHeight(nodeSubject *root){
//	if(root == NULL) return 0; // truong hop danh sach rong
//	return root->height;
//}
//
//int getBalance(nodeSubject *root){
//	if(root == NULL) return 0; // truong hop danh sach rong
//	return getHeight(root->left) - getHeight(root->right);
//}
//
//nodeSubject* rightRotate(nodeSubject *y){
//	nodeSubject *x = y->left;
//	nodeSubject *T2 = x->right;
//	x->right = y;
//	y->left = T2;
//	
//	y->height = 1 + max(getHeight(y->left), getHeight(y->right));
//	x->height = 1 + max(getHeight(x->left), getHeight(x->right));
//	
//	return x;
//}
//
//
//void addNode(nodeSubject *&root, subject s){
//	if(root == NULL){ // truong hop danh sach rong
//		root = createNodeSubject(s);
//		return;
//	}
//	addNode(root->left, s);
//	
//	root->height = 1 + max(getHeight(root->left), getHeight(root->right));
//	int balance = getBalance(root);
//	
//	if(balance > 1){ // cay khong can bang luon trong truong hop left left
//		root = rightRotate(root);
//	}
//}
//
//void readSubjectList(nodeSubject *&root, string nameFileSubjectList){ // xu ly doc file
//	fstream f;
//	f.open(nameFileSubjectList, ios::in);
//	if(!f.is_open()){
//		cout << "Failed Open!" << endl;
//		return;
//	}
//	cout << "Completed Open!" << endl;
//	
//	subject s;
//	while(!f.eof()){
//		string line;
//		getline(f, line);
//		
//		stringstream ss(line);
//		getline(ss, s.idSubject, '#');
//		getline(ss, s.name, '#');
//		getline(ss, s.STCLT, '#');
//		getline(ss, s.STCTH, '#');
//		
//		addNode(root, s);
//	}
//}

#endif
