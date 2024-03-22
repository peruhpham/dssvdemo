
#include <iostream>
#include <conio.h> // Ð? s? d?ng getch()

#define UP 72 + 255
#define DOWN 80 + 255


int main() {
    // Vòng l?p d? ki?m tra mã ASCII c?a các phím khi du?c nh?n
    while (true) {
        char key = getch(); 
        
        int ascii = static_cast<int>(key);
        if (ascii == -32) { 
            key = getch();
            ascii = static_cast<int>(key);
            ascii += 255;
    	}

        if (ascii == UP) {
            std::cout << "ban da nhan phim UP" << std::endl;
        } else if (ascii == DOWN) {
            std::cout << "ban da nhan phim down DOWN" << std::endl;
        }
        else if(('a' <= ascii && ascii <= 'z') || ('A' <= ascii && ascii <= 'Z')|| ('0' <= ascii && ascii <= '9')){
        	std::cout << "BAN DA NHAN KY TU: " << key << std::endl;
		}
        
        
        else {
            std::cout << "BAN DA NHAN KY TU KHAC " << key << std::endl;
        }
    }
    return 0;
}
