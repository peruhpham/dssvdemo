#ifndef DATAHANDING_H
#define DATAHANDING_H
// dinh dang du lieu nhap xuat, tao cac rang buoc du lieu

using namespace std;

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
#endif
