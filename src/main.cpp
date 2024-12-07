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

    CaesarDecryptor cipher3(5);
    cipher3.description();
    cipher3.addData(cipher2.getData());
    cipher3.decrypt();
    std::cout << "Decrypted: " << cipher3.getData() << std::endl;

    //testing for potential errors
    std::cout << "Testing for potential errors:" << std::endl;
    CaesarEncryptor encryptionTest(1);
    encryptionTest.addData("abcdefghijklmnopqrstuvwxyz0123456789-=~[];',./!@#$%^&*()");
    encryptionTest.encrypt();
    std::cout << "Encryption test: " << encryptionTest.getData() << std::endl;

    std::cout << "Testing for potential errors:" << std::endl;
    CaesarDecryptor decryptionTest(1);
    decryptionTest.addData("abcdefghijklmnopqrstuvwxyz0123456789-=~[];',./!@#$%^&*()");
    decryptionTest.decrypt();
    std::cout << "Decryption test: " << decryptionTest.getData() << std::endl;



    return 0;
}