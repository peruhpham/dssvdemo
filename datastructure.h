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

//================================================================

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




//============================================================================

// cay nhi phan 


//struct subject{
//	int idSubject, STCLT, STCTH;
//	string nameSubject;	
//};
////-----
//struct nodeSubject{
//	subject data;
//	nodeSubject *left, *right;
//	int height;
//};
//
//int height (nodeSubject *sub){
//	if(sub == nullptr) 
//		return 0;
//	return sub->height;
//}
//int max(int a, int b){
//	return a > b ? a : b;
//}
//nodeSubject* newNodeSubject(subject sub){
//	nodeSubject *tmp = new nodeSubject();
//	
//	tmp->data = sub;
//	tmp->left = nullptr;
//	tmp->right = nullptr;
//	tmp->height = 1;
//
//	return tmp;
//}
//nodeSubject *rightRotate(nodeSubject *y){
//	nodeSubject *x = y->left;
//	nodeSubject *T2 = x->right;
//
//	// Perform rotation 
//	x->right = y; 
//	y->left = T2; 
//
//	// Update heights 
//	y->height = max(height(y->left), 
//					height(y->right)) + 1; 
//	x->height = max(height(x->left), 
//					height(x->right)) + 1; 
//
//	// Return new root 
//	return x;
//}
//Node *leftRotate(nodeSubject *x) 
//{ 
//	nodeSubject *y = x->right; 
//	nodeSubject *T2 = y->left; 
//
//	// Perform rotation 
//	y->left = x; 
//	x->right = T2; 
//
//	// Update heights 
//	x->height = max(height(x->left),	 
//					height(x->right)) + 1; 
//	y->height = max(height(y->left), 
//					height(y->right)) + 1; 
//
//	// Return new root 
//	return y; 
//} 
//// Get Balance factor of node N 
//int getBalance(nodeSubject *N) 
//{ 
//	if (N == NULL) 
//		return 0; 
//	return height(N->left) - height(N->right); 
//} 
//
//nodeSubject *insert(nodeSubject *nodeSub, subject key){
//	if(nodeSub == NULL)
//		return(newNodeSubject(key));
//
//	if(key < nodeSub->key)
//		nodeSub->left = insert(nodeSub->left, key);
//	else if(key >nodeSub->right)
//		nodeSub->right = insert(nodeSub->right, key);
//	else
//		return nodeSub;
//
//	//update height
//	nodeSub->height = 1 + max(height(nodeSub->left), height(nodeSub->right));
//	// get banlane
//	int banlane =getBalance(nodeSub);
//
//	if(balance > 1 && key < nodeSub->left->key)
//		return rightRotate(nodeSub);
//	if(balance < -1 && key > nodeSub->right->key)
//		return leftRotate(nodeSub);
//	if(balance > 1 && key > nodeSub->left->key){
//		nodeSub->left = leftRotate(nodeSub->key);
//		return rightRotate(nodeSub);
//	}
//	if(balance < -1 && key < nodeSub->right->key){
//		nodeSub->right = rightRotate(nodeSub->right);
//		return leftRotate(nodeSub);
//	}
//	
//	return nodeSub;
//}
//
//void outRootLeftRight(nodeSubject *root){
//	if(root != nullptr){
//		cout << root->key->data.idSubject << " ";
//		cout << root->key->data.nameSubject << " ";
//		cout << root->key->data.STCLT << " ";
//		cout << root->key->data.STCTH << " ";
//
//		outRootLeftRight(root->left);
//		outRootLeftRight(root->right);
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



// cau truc cay nhi phan can bang 

struct subject {
    string idSubject;
    string nameSubject;
	int STCLT, STCTH;
    
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
typedef nodeSubject *ptrNodeSubject;

struct listSubject{
	ptrNodeSubject root;
	int size;

	listSubject(){
		this->root = NULL;
		this->size = 0;
	}
};


int height(ptrNodeSubject sub) {
    if (sub == nullptr) 
        return 0;
    return sub->height;
}

int max(int a, int b) {
    return a > b ? a : b;
}



ptrNodeSubject rightRotate(ptrNodeSubject y) {
    ptrNodeSubject x = y->left;
    ptrNodeSubject T2 = x->right;

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

ptrNodeSubject leftRotate(ptrNodeSubject x){
    ptrNodeSubject y = x->right; 
    ptrNodeSubject T2 = y->left; 

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
int getBalance(ptrNodeSubject N) { 
    if (N == NULL) 
        return 0; 
    return height(N->left) - height(N->right); 
} 

ptrNodeSubject insert(ptrNodeSubject nodeSub, subject key) {
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


void readSubjectList(listSubject &lsb, string nameFileSubjectList) {
	ptrNodeSubject root = lsb.root;
	
    ifstream f(nameFileSubjectList);
    if (!f.is_open()) {
        cout << "Failed to open file!" << endl;
        return;
    }
    cout << "File opened successfully!" << endl;

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
    
    f.close();
}



#endif
