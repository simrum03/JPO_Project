#include <iostream>
#include <fstream>
#include <filesystem>

#include "../inc/CaesarCipher.hpp"
#include "../inc/RailFenceCipher.hpp"

void deleteFile(const std::string& filename) {
    if (std::filesystem::exists(filename)) {
        std::filesystem::remove(filename);
        std::cout << "File " << filename << " has been deleted." << std::endl;
    } 
    else 
    {
        std::cerr << "Error: File " << filename << " does not exist." << std::endl;
    }
}

int main() {

    std::string option;
    std::string filename;

    while(true){
        std::cout << "Hello! Choose your option:" << std::endl
                  << "1 - Encrypting" << std::endl
                  << "2 - Decrypting" << std::endl
                  << "3 - Delete a file" << std::endl             
                  << "4 - Quit program" << std::endl;
        
        std::cout << "Enter your choice: ";
        std::cin >> option;

        if (option == "1"){
            while(true) {
                std::string algorithm;
                std::cout << "Encrypting selected." << std::endl;

                std::cout << "Choose an algorithm:" << std::endl
                          << "c - Caesar cipher" << std::endl
                          << "r - Rail fence cipher" << std::endl
                          << "b - back to main menu" << std::endl
                          << "q - quit program" << std::endl;

                std::cout << "Enter your algorithm choice: ";
                std::cin >> algorithm;

                if (algorithm == "c") {
                    sr::CaesarEncryptor caesar;
                    int shift{};
                    std::cout << "Enter shift: ";
                    std::cin >> shift;

                    caesar.setShift(shift);

                    std::cout << "Enter data you would like to encrypt (type 'stop' to finish):" << std::endl;

                    std::string data;
                    while(true) {
                        std::getline(std::cin, data);

                        if (data == "stop") {
                            std::cout << "\033[A\033[2K";
                            break;
                        }
                        caesar.addData(data);
                    }

                    std::string allData = caesar.getData();
                    caesar.encrypt();
                    std::cout << "Encrypted data: " << caesar.getData() << std::endl;

                    std::string choice;
                    std::cout << "What do you want to do with your data?" << std::endl
                              << "1 - Save data to file" << std::endl
                              << "2 - Append data to existing file" << std::endl
                              << "3 - Delete a file" << std::endl
                              << "Enter your choice: ";
                    std::cin >> choice;

                    if (choice == "1") {
                        std::string label;

                        std::cout << "Enter filename: ";
                        std::cin >> filename;

                        std::cin.ignore();
                        std::cout << "Enter a label for this data: ";
                        std::getline(std::cin, label);

                        caesar.writeToFile(filename, caesar.getData(), label);
                    }
                    else if (choice == "2") {
                        bool foundFiles = false;

                        for (const auto& entry : std::filesystem::directory_iterator(".")) {
                            if (entry.is_regular_file()) {
                                std::string name = entry.path().filename().string();                    
                
                                if (name != "CMakeCache.txt" && name != "cmake_install.cmake" && name != "main.exe" && name != "Makefile") {
                                    std::cout << " - " << entry.path().filename().string() << std::endl;
                                    foundFiles = true;
                                }
                            }
                        }

                        if (!foundFiles) {
                            std::cout << "Currently there is no file with data." << std::endl;
                            break;
                        }

                        std::cout << "Enter the name of the file you would like to append: ";
                        std::cin >> filename;

                        if (std::filesystem::exists(filename)) {
                            std::string label;

                            std::cin.ignore();
                            std::cout << "Enter a label for this data: ";
                            std::getline(std::cin, label);

                            caesar.writeToFile(filename, caesar.getData(), label, true);
                        }
                        else {
                            std::cerr << "Error: File " << filename << " does not exist." << std::endl;
                        }
                    }
                    else {
                        std::cout << "Incorrect option." << std::endl;
                    }
                    break;
                }
                else if (algorithm == "r") {
                    sr::RailFenceEncryptor railfence;
                    int rails{};
                    std::cout << "Enter number of rails: ";
                    std::cin >> rails;
                    railfence.setRails(rails);

                    std::cout << "Enter data you would like to encrypt (type 'stop' to finish):" << std::endl;

                    std::string data;
                    while(true) {
                        std::getline(std::cin, data);

                        if (data == "stop") {
                            std::cout << "\033[A\033[2K";
                            break;
                        }
                        railfence.addData(data);
                    }

                    std::string allData = railfence.getData();
                    railfence.encrypt();
                    std::cout << "Encrypted data: " << railfence.getData() << std::endl;

                    std::string choice;
                    std::cout << "What do you want to do with your data?" << std::endl
                              << "1 - Save data to file" << std::endl
                              << "2 - Append data to existing file" << std::endl
                              << "3 - Delete a file" << std::endl
                              << "Enter your choice: ";
                    std::cin >> choice;

                    if (choice == "1") {
                        std::string label;

                        std::cout << "Enter filename: ";
                        std::cin >> filename;

                        std::cin.ignore();
                        std::cout << "Enter a label for this data: ";
                        std::getline(std::cin, label);

                        railfence.writeToFile(filename, railfence.getData(), label);
                    }
                    else if (choice == "2") {
                        bool foundFiles = false;

                        for (const auto& entry : std::filesystem::directory_iterator(".")) {
                            if (entry.is_regular_file()) {
                                std::string name = entry.path().filename().string();                    
                
                                if (name != "CMakeCache.txt" && name != "cmake_install.cmake" && name != "main.exe" && name != "Makefile") {
                                    std::cout << " - " << entry.path().filename().string() << std::endl;
                                    foundFiles = true;
                                }
                            }
                        }

                        if (!foundFiles) {
                            std::cout << "Currently there is no file with data." << std::endl;
                            break;
                        }

                        std::cout << "Enter the name of the file you would like to append: ";
                        std::cin >> filename;

                        if (std::filesystem::exists(filename)) {
                            std::string label;

                            std::cin.ignore();
                            std::cout << "Enter a label for this data: ";
                            std::getline(std::cin, label);

                            railfence.writeToFile(filename, railfence.getData(), label, true);
                        }
                        else {
                            std::cerr << "Error: File " << filename << " does not exist." << std::endl;
                        }
                    }
                    else {
                        std::cout << "Incorrect option." << std::endl;
                    }
                    break;
                }
                else if (algorithm == "b") {
                    break;
                }
                else if (algorithm == "q") {
                    std::cout << "Quitting..." << std::endl;
                    return 0;
                }
                else {
                    std::cout << "Invalid choice." << std::endl;
                }
            }
        }
        else if (option == "2") {
            while(true) {
                std::string algorithm;
                std::cout << "Decrypting selected." << std::endl;

                std::cout << "Choose an algorithm:" << std::endl
                          << "c - Caesar cipher" << std::endl
                          << "r - Rail fence cipher" << std::endl
                          << "b - back to main menu" << std::endl
                          << "q - quit program" << std::endl;

                std::cout << "Enter your algorithm choice: ";
                std::cin >> algorithm;

                if (algorithm == "c") {
                    sr::CaesarDecryptor caesar;
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
                            std::cout << "\033[A\033[2K";
                            break;
                        }
                        caesar.addData(data);
                    }

                    std::string allData = caesar.getData();
                    caesar.decrypt();
                    std::cout << "Decrypted data: " << caesar.getData() << std::endl;

                    std::string choice;
                    std::cout << "What do you want to do with your data?" << std::endl
                              << "1 - Save data to file" << std::endl
                              << "2 - Append data to existing file" << std::endl
                              << "3 - Delete a file" << std::endl
                              << "Enter your choice: ";
                    std::cin >> choice;

                    if (choice == "1") {
                        std::string label;

                        std::cout << "Enter filename: ";
                        std::cin >> filename;

                        std::cin.ignore();
                        std::cout << "Enter a label for this data: ";
                        std::getline(std::cin, label);

                        caesar.writeToFile(filename, caesar.getData(), label);
                    }
                    else if (choice == "2") {
                        bool foundFiles = false;

                        for (const auto& entry : std::filesystem::directory_iterator(".")) {
                            if (entry.is_regular_file()) {
                                std::string name = entry.path().filename().string();                    
                
                                if (name != "CMakeCache.txt" && name != "cmake_install.cmake" && name != "main.exe" && name != "Makefile") {
                                    std::cout << " - " << entry.path().filename().string() << std::endl;
                                    foundFiles = true;
                                }
                            }
                        }

                        if (!foundFiles) {
                            std::cout << "Currently there is no file with data." << std::endl;
                            break;
                        }

                        std::cout << "Enter the name of the file you would like to append: ";
                        std::cin >> filename;

                        if (std::filesystem::exists(filename)) {
                            std::string label;

                            std::cin.ignore();
                            std::cout << "Enter a label for this data: ";
                            std::getline(std::cin, label);

                            caesar.writeToFile(filename, caesar.getData(), label, true);
                        }
                        else {
                            std::cerr << "Error: File " << filename << " does not exist." << std::endl;
                        }
                    }
                    else {
                        std::cout << "Incorrect option." << std::endl;
                    }                    
                    break;
                }
                else if (algorithm == "r") {
                    sr::RailFenceDecryptor railfence;
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
                            std::cout << "\033[A\033[2K";
                            break;
                        }
                        railfence.addData(data);
                    }

                    std::string allData = railfence.getData();
                    railfence.decrypt();
                    std::cout << "Decrypted data: " << railfence.getData() << std::endl;

                    std::string choice;
                    std::cout << "What do you want to do with your data?" << std::endl
                              << "1 - Save data to file" << std::endl
                              << "2 - Append data to existing file" << std::endl
                              << "3 - Delete a file" << std::endl
                              << "Enter your choice: ";
                    std::cin >> choice;

                    if (choice == "1") {
                        std::string label;

                        std::cout << "Enter filename: ";
                        std::cin >> filename;

                        std::cin.ignore();
                        std::cout << "Enter a label for this data: ";
                        std::getline(std::cin, label);

                        railfence.writeToFile(filename, railfence.getData(), label);
                    }
                    else if (choice == "2") {
                        bool foundFiles = false;

                        for (const auto& entry : std::filesystem::directory_iterator(".")) {
                            if (entry.is_regular_file()) {
                                std::string name = entry.path().filename().string();                    
                
                                if (name != "CMakeCache.txt" && name != "cmake_install.cmake" && name != "main.exe" && name != "Makefile") {
                                    std::cout << " - " << entry.path().filename().string() << std::endl;
                                    foundFiles = true;
                                }
                            }
                        }

                        if (!foundFiles) {
                            std::cout << "Currently there is no file with data." << std::endl;
                            break;
                        }

                        std::cout << "Enter the name of the file you would like to append: ";
                        std::cin >> filename;

                        if (std::filesystem::exists(filename)) {
                            std::string label;

                            std::cin.ignore();
                            std::cout << "Enter a label for this data: ";
                            std::getline(std::cin, label);

                            railfence.writeToFile(filename, railfence.getData(), label, true);
                        }
                        else {
                            std::cerr << "Error: File " << filename << " does not exist." << std::endl;
                        }
                    }
                    else {
                        std::cout << "Incorrect option." << std::endl;
                    }                    
                    break;
                }
                else if (algorithm == "b") {
                    break;
                }
                else if (algorithm == "q") {
                    std::cout << "Quitting..." << std::endl;
                    return 0;
                }
                else {
                    std::cout << "Invalid option." << std::endl;
                }
            }
        }
        else if (option == "3") {
            bool foundFiles = false;

            for (const auto& entry : std::filesystem::directory_iterator(".")) {
                if (entry.is_regular_file()) {
                    std::string name = entry.path().filename().string();                    
                
                    if (name != "CMakeCache.txt" && name != "cmake_install.cmake" && name != "main.exe" && name != "Makefile") {
                        std::cout << " - " << entry.path().filename().string() << std::endl;
                        foundFiles = true;
                    }
                }
            }
            if (!foundFiles) {
                std::cout << "There is no file to delete." << std::endl;
                break;
            }

            std::cout << "Enter the name of the file you would like to delete: ";
            std::cin >> filename;

            if (std::filesystem::exists(filename)) {
                deleteFile(filename);
            }
            else {
                std::cerr << "Error: File " << filename << " does not exist." << std::endl;
            } 
        }
        else if (option == "4") {
            std::cout << "Quitting..." << std::endl;
            return 0;
        }
        else {
            std::cout << "Invalid option. Try again." << std::endl;
        }

    std::cout << std::endl;
    }

    return 0;
}