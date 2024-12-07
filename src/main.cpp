#include <iostream>

#include "../inc/CaesarCipher.hpp"

int main() {
    CaesarEncryptor cipher1;
    cipher1.description();
    cipher1.addData("HELLO ");
    cipher1.addData("Pearl");
    cipher1.encrypt();
    std::cout << "Encrypted: " << cipher1.getData() << std::endl;

    CaesarEncryptor cipher2(5);
    cipher2.description();
    cipher2.addData("THE WORLD ");
    cipher2.addData("IS YOURS.");
    cipher2.encrypt();
    std::cout << "Encrypted: " << cipher2.getData() << std::endl;

    return 0;
}