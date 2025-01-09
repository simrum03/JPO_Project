#include <iostream>
#include <fstream>
#include <filesystem>
#include "CaesarCipher.hpp"
#include "RailFenceCipher.hpp"
#include "Menu.hpp"

namespace sr{

    Menu::Menu() : m_filename("") {}
    Menu::Menu(const std::string& filename) : m_filename(filename) {}

    void Menu::run() {
        std::string option;
        while (true) {
            showMainMenu();
            std::cin >> option;

            if (option == "1") {
                handleEncryption();
            } 
            else if (option == "2") {
                handleDecryption();
            } 
            else if (option == "3") {
                handleFileDeletion();
            } 
            else if (option == "4") {
                std::cout << "Quitting..." << std::endl;
                break;
            } 
            else {
                std::cout << "Invalid option. Try again." << std::endl;
            }
            std::cout << std::endl;
        }
    }

    void Menu::setFilename (const std::string &filename) {
        m_filename = filename;
    }

    const std::string Menu::getFilename() const {
        return m_filename;
    }

    void Menu::showMainMenu() const {
        std::cout << "---------------------" << std::endl
                  << "Menu:" << std::endl 
                  << "1 - Encrypting" << std::endl
                  << "2 - Decrypting" << std::endl
                  << "3 - Delete a file" << std::endl
                  << "4 - Quit program" << std::endl
                  << "---------------------" << std::endl
                  << "Enter your choice: ";
    }

    void Menu::handleEncryption() {
        while (true) {
            std::cout << "Encrypting selected. Choose an algorithm:" << std::endl
                      << "c - Caesar cipher" << std::endl
                      << "r - Rail fence cipher" << std::endl
                      << "b - Back to main menu" << std::endl
                      << "Enter your algorithm choice: ";
            std::string algorithm;
            std::cin >> algorithm;

            if (algorithm == "c") {
                handleCaesarEncryption();
            } 
            else if (algorithm == "r") {
                handleRailFenceEncryption();
            } 
            else if (algorithm == "b") {
                break;
            } 
            else {
                std::cout << "Invalid choice. Try again." << std::endl;
            }

            std::cout << "Do you want to continue encrypting? (y/n): ";
            std::string choice;
            std::cin >> choice;
            if (choice != "y") {
                break;
            }
        }
    }

    void Menu::handleDecryption() {
        while (true) {
            std::cout << "Decrypting selected. Choose an algorithm:" << std::endl
                      << "c - Caesar cipher" << std::endl
                      << "r - Rail fence cipher" << std::endl
                      << "b - Back to main menu" << std::endl
                      << "Enter your algorithm choice: ";
            std::string algorithm;
            std::cin >> algorithm;

            if (algorithm == "c") {
                handleCaesarDecryption();
            } 
            else if (algorithm == "r") {
                handleRailFenceDecryption();
            } 
            else if (algorithm == "b") {
                break;
            } 
            else {
                std::cout << "Invalid choice. Try again." << std::endl;
            }

            std::cout << "Do you want to continue decrypting? (y/n): ";
            std::string choice;
            std::cin >> choice;
            if (choice != "y") {
                break;
            }
        }
    }

    void Menu::handleCaesarEncryption() {
        sr::CaesarEncryptor caesar;
        int shift = getInput("Enter shift: ");
        caesar.setShift(shift);

        std::cout << "Enter data you would like to encrypt (type 'stop' to finish):" << std::endl;
        std::string data = getInputData();
        caesar.addData(data);

        caesar.encrypt();
        std::cout << "Encrypted data: " << caesar.getData() << std::endl;
        saveOrAppendToFile(caesar);
    }

    void Menu::handleRailFenceEncryption() {
        sr::RailFenceEncryptor railfence;
        int rails = getInput("Enter number of rails: ");
        railfence.setRails(rails);

        std::cout << "Enter data you would like to encrypt (type 'stop' to finish):" << std::endl;
        std::string data = getInputData();
        railfence.addData(data);

        railfence.encrypt();
        std::cout << "Encrypted data: " << railfence.getData() << std::endl;
        saveOrAppendToFile(railfence);
    }

    void Menu::handleCaesarDecryption() {
        sr::CaesarDecryptor caesar;
        int shift = getInput("Enter shift: ");
        caesar.setShift(shift);

        std::cout << "Enter data you would like to decrypt (type 'stop' to finish):" << std::endl;
        std::string data = getInputData();
        caesar.addData(data);

        caesar.decrypt();
        std::cout << "Decrypted data: " << caesar.getData() << std::endl;
        saveOrAppendToFile(caesar);
    }

    void Menu::handleRailFenceDecryption() {
        sr::RailFenceDecryptor railfence;
        int rails = getInput("Enter number of rails: ");
        railfence.setRails(rails);

        std::cout << "Enter data you would like to decrypt (type 'stop' to finish):" << std::endl;
        std::string data = getInputData();
        railfence.addData(data);

        railfence.decrypt();
        std::cout << "Decrypted data: " << railfence.getData() << std::endl;
        saveOrAppendToFile(railfence);
    }

    void Menu::handleFileDeletion() {
        if (!listFiles()) {
            std::cout << "There is no file to delete." << std::endl;
            return;
        }
        std::cout << "Enter the name of the file you would like to delete: ";
        std::cin >> m_filename;
        deleteFile(m_filename);
    }

    bool Menu::listFiles() const {
        bool foundFiles = false;
        std::cout << "List of current files:" << std::endl;
        for (const auto& entry : std::filesystem::directory_iterator(".")) {
            if (entry.is_regular_file()) {
                std::string name = entry.path().filename().string();
                if (name != "CMakeCache.txt" && name != "cmake_install.cmake" && name != "main.exe" && name != "Makefile" && name != "compile_commands.json") {
                    std::cout << " - " << name << std::endl;
                    foundFiles = true;
                }
            }
        }
        return foundFiles;
    }

    void Menu::deleteFile(const std::string& filename) {
        try {
            if (std::filesystem::remove(filename)) {
                std::cout << "File " << filename << " has been deleted." << std::endl;
            } 
            else {
                std::cerr << "Error: File " << filename << " does not exist." << std::endl;
            }
        } 
        catch (const std::filesystem::filesystem_error& e) {
            std::cerr << "Filesystem error: " << e.what() << std::endl;
        }
    }

    int Menu::getInput(const std::string& prompt) const {
        std::string input;
        while (true) {
            std::cout << prompt;
            std::cin >> input;
            if (isInteger(input) && std::stoi(input) >= 0) {
                return std::stoi(input);
            }
            std::cout << "Incorrect input. Try again." << std::endl;
        }
    }

    std::string Menu::getInputData() const {
        std::string data, line;
        std::cin.ignore();
        while (true) {
            std::getline(std::cin, line);
            if (line == "stop") {
                break;
            }
            data += line;
        }
        return data;
    }

    void Menu::saveOrAppendToFile(sr::Encryptor &encryptor) {
        std::cout << "What do you want to do with your encrypted data?" << std::endl
                << "1 - Save data to a new file" << std::endl
                << "2 - Append data to an existing file" << std::endl
                << "3 - Do nothing" << std::endl
                << "Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        if (choice == "1" || choice == "2") {
            bool append = (choice == "2");
            if (append) {
                listFiles();
            }
            std::cout << "Enter filename: ";
            std::cin >> m_filename;


            std::string label;
            if (append) {
                std::cout << "Enter a label to differentiate this data in the file (optional): ";
                std::cin.ignore();
                std::getline(std::cin, label);
            }

            encryptor.writeToFile(m_filename, encryptor.getData(), label, append);
        } 
        else if (choice == "3") {
            std::cout << "No changes made." << std::endl;
        } 
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    void Menu::saveOrAppendToFile(sr::Decryptor &decryptor) {
        std::cout << "What do you want to do with your decrypted data?" << std::endl
              << "1 - Save data to a new file" << std::endl
              << "2 - Append data to an existing file" << std::endl
              << "3 - Do nothing" << std::endl
              << "Enter your choice: ";
        std::string choice;
        std::cin >> choice;

        if (choice == "1" || choice == "2") {
            std::cout << "Enter filename: ";
            std::cin >> m_filename;
            bool append = (choice == "2");

            std::string label;
            if (append) {
                std::cout << "Enter a label to differentiate this data in the file (optional): ";
                std::cin.ignore();
                std::getline(std::cin, label);
            }

            decryptor.writeToFile(m_filename, decryptor.getData(), label, append);
        } 
        else if (choice == "3") {
            std::cout << "No changes made." << std::endl;
        } 
        else {
            std::cout << "Invalid choice." << std::endl;
        }
    }

    bool Menu::isInteger(const std::string& str) const {
        for (char c : str) {
            if (!isdigit(c) && c != '-' && c != '+') {
                return false;
            }
        }
        return true;
    }
}
