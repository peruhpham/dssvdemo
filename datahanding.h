#ifndef DATAHANDING_H
#define DATAHANDING_H
// dinh dang du lieu nhap xuat, tao cac rang buoc du lieu

using namespace std;

int isSubString(string subtext, string text){ // kiem tra xau con 
	int s = subtext.size();
	for(int i = 0; i < s; i++){
		if(subtext[i] != text[i]) return 0;
	}
	return 1;
}

int stringtoint(string s){
	int temp = 0;
	for(int i = 1; i <= s.size(); i++){
		temp += (s[i - 1] - '0') * pow(10, s.size() - i);
	}
	return temp;
}

char* tochar(string s) {
    char* text = new char[s.size() + 1]; 
    for (int i = 0; i < s.size(); ++i) {
        text[i] = s[i];
    }
    text[s.size()] = '\0';
    return text;
}

void formatKey(char &key){
	if(islower(key)) key = toupper(key);
}

string formatIdClass(int IdClass){
	string temp = "";
	temp = string(5 - to_string(IdClass).size(), '0') + to_string(IdClass);
	return temp;
}

string toLowerCase(string text){
	for(char &x : text){
		x = tolower(x);
	}
	return text;
}


#endif

