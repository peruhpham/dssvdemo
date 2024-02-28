#ifndef DECLAREDATASTRUCTURE_H
#define DECLAREDATASTRUCTURE_H


using namespace std;

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

void addLast(listStudent &ls,student x){
    ptrStudent p = new nodeStudent(x);
   
    if(ls.size == 0){
        ls.head = p;
        ls.size += 1;
    }
    else{
        ptrStudent last = ls.head;
        while(last->next != NULL){
            last = last->next;
        }
        last->next = p;
        ls.size += 1;
    }
}

// doc file 
void readListStudent(listStudent &ls, string nameFileListStudent){
    ifstream f;
    f.open(nameFileListStudent, ios::in);
    if(!f.is_open()){
        cout << "fail open!" << endl;
        return;
    }
    cout << "complete open!" << endl; // doc file
    
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
        addLast(ls,e);
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
