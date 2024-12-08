#include <iostream>

#include "../inc/CaesarCipher.hpp"
#include "../inc/RailFenceCipher.hpp"

int main() {

    std::string option;

    while(true){
        std::cout << "Hello! Choose your option:" << std::endl
              << "e - encrypting" << std::endl
              << "d - decrypting" << std::endl
              << "q - quit program" << std::endl;
        
        std::cout << "Enter your choice: ";
        std::cin >> option;

        if (option == "e"){
            std::string algorithm;
            std::cout << "Encrypting selected." << std::endl;

            std::cout << "Choose an algorithm:" << std::endl
                      << "c - Caesar cipher" << std::endl
                      << "r - Rail fence cipher" << std::endl
                      << "q - quit program" << std::endl;

            std::cout << "Enter your algorithm choice: ";
            std::cin >> algorithm;

            if (algorithm == "c") {
                CaesarEncryptor caesar;
                int shift{};
                std::cout << "Enter shift: ";
                std::cin >> shift;

                caesar.setShift(shift);
                caesar.description();

                std::cout << "Enter data you would like to encrypt (type 'stop' to finish):" << std::endl;

                std::string data;
                while(true) {
                    std::getline(std::cin, data);

                    if (data == "stop") {
                        break;
                    }
                    caesar.addData(data);
                }

                std::string allData = caesar.getData();
                caesar.encrypt();
                std::cout << "Encrypted data: " << caesar.getData();
                break;
            }
            else if (algorithm == "r") {
                RailFenceEncryptor railfence;
                int rails{};
                std::cout << "Enter number of rails: ";
                std::cin >> rails;
                railfence.setRails(rails);
                railfence.description();

                std::cout << "Enter data you would like to encrypt (type 'stop' to finish):" << std::endl;

                std::string data;
                while(true) {
                    std::getline(std::cin, data);

                    if (data == "stop") {
                        break;
                    }
                    railfence.addData(data);
                }

                std::string allData = railfence.getData();
                railfence.encrypt();
                std::cout << "Encrypted data: " << railfence.getData();
                break;
            }
            else if (algorithm == "q") {
                std::cout << "Quitting..." << std::endl;
                break;
            }
            else {
                std::cout << "Invalid choice." << std::endl;
            }
        }
        else if (option == "d") {
            std::string algorithm;
            std::cout << "Decrypting selected." << std::endl;

            std::cout << "Choose an algorithm:" << std::endl
                      << "c - Caesar cipher" << std::endl
                      << "r - Rail fence cipher" << std::endl
                      << "q - quit program" << std::endl;

            std::cout << "Enter your algorithm choice: ";
            std::cin >> algorithm;

            if (algorithm == "c") {
                CaesarDecryptor caesar;
                int shift{};
                std::cout << "Enter shift: ";
                std::cin >> shift;

                caesar.setShift(shift);
                caesar.description();

                std::cout << "Enter data you would like to decrypt (type 'stop' to finish):" << std::endl;

                std::string data;
                while(true){
                    std::getline(std::cin, data);

                    if (data == "stop") {
                        break;
                    }
                    caesar.addData(data);
                }

                std::string allData = caesar.getData();
                caesar.decrypt();
                std::cout << "Decrypted data: " << caesar.getData();
                break;
            }
            else if (algorithm == "r") {
                RailFenceDecryptor railfence;
                int rails{};
                std::cout << "Enter number of rails: ";
                std::cin >> rails;

                railfence.setRails(rails);
                railfence.description();

                std::cout << "Enter data you would like to decrypt (type 'stop' to finish):" << std::endl;

                std::string data;
                while(true) {
                    std::getline(std::cin, data);

                    if (data == "stop") {
                        break;
                    }
                    railfence.addData(data);
                }

                std::string allData = railfence.getData();
                railfence.decrypt();
                std::cout << "Decrypted data: " << railfence.getData();
                break;
            }
            else if (algorithm == "q") {
                std::cout << "Quitting..." << std::endl;
                break;
            }
            else {
                std::cout << "Invalid option." << std::endl;
            }
        }
        else if (option == "q") {
            std::cout << "Quitting..." << std::endl;
            break;
        }
        else {
            std::cout << "Invalid option. Try again." << std::endl;
        }

    std::cout << std::endl;
    }

    return 0;
}