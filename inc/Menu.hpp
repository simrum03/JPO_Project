#pragma once

#include <iostream>
#include <fstream>
#include <filesystem>
#include "CaesarCipher.hpp"
#include "RailFenceCipher.hpp"

namespace sr{

/**
 * @class Menu
 * @brief Provides a user interface for encryption, decryption, and file management.
 * 
 * The Menu class allows the user to interact with different encryption and decryption algorithms,
 * manage files, and execute the main program logic via a text-based menu system.
 */
class Menu {
private:
    std::string m_filename; ///< Name of the file being processed.
public:
    /**
     * @brief Default constructor.
     */
    Menu();

    /**
     * @brief Parameterized constructor.
     *
     * @param filename Name of the file being processed.
     */
    Menu(const std::string& filename);

    /**
     * @brief Runs the main menu loop.
     * 
     * Displays the main menu and handles user input for various actions.
     */
    void run();

    /**
     * @brief Sets the filename for file operations.
     * 
     * @param filename The name of the file to be set.
     */
    void setFilename (const std::string &filename);

    /**
     * @brief Retrieves the current filename.
     * 
     * @return The current filename as a string.
     */
    const std::string getFilename() const;


    /**
     * @brief Displays the main menu options.
     * 
     * Menu:
     * 1 - Encrypting
     * 2 - Decrypting
     * 3 - Delete a file
     * 4 - Quit program
     */
    void showMainMenu() const;

    /**
     * @brief Handles encryption operations.
     * 
     * Allows the user to choose an encryption algorithm and perform encryption.
     * 
     * Choice:
     * c - Caesar cipher
     * r - Rail fence cipher
     * b - Back to main menu
     * 
     * After completing data encryption user is asked whether he want to continue encrypting or not.
     */
    void handleEncryption();

    /**
     * @brief Handles decryption operations.
     * 
     * Allows the user to choose a decryption algorithm and perform decryption.
     * 
     * Choice:
     * c - Caesar cipher
     * r - Rail fence cipher
     * b - Back to main menu
     * 
     * After completing data decryption user is asked whether he want to continue decrypting or not.
     */
    void handleDecryption();

    /**
     * @brief Handles Caesar cipher encryption.
     * 
     * Prompts the user for input shift and data to encrypt, encrypts the data, and optionally saves it to a file.
     */
    void handleCaesarEncryption();

    /**
     * @brief Handles Rail Fence cipher encryption.
     * 
     * Prompts the user for input number of rails and data to encrypt, encrypts the data, and optionally saves it to a file.
     */
    void handleRailFenceEncryption();

    /**
     * @brief Handles Caesar cipher decryption.
     * 
     * Prompts the user for input shift and data to decrypt, decrypts the data, and optionally saves it to a file.
     */
    void handleCaesarDecryption();

    /**
     * @brief Handles Rail Fence cipher decryption.
     * 
     * Prompts the user for input number of rails and data to decrypt, decrypts the data, and optionally saves it to a file.
     */
    void handleRailFenceDecryption();

    /**
     * @brief Handles file deletion operations.
     * 
     * Allows the user to delete an existing file.
     */
    void handleFileDeletion();

    /**
     * @brief Lists all available files in the current directory.
     * 
     * @return True if files are found, false otherwise.
     */
    bool listFiles() const;

    /**
     * @brief Deletes a specified file.
     * 
     * @param filename The name of the file to delete.
     */
    void deleteFile(const std::string& filename);

    /**
     * @brief Gets an integer input from the user.
     * 
     * @param prompt The prompt to display to the user.
     * @return The integer value entered by the user, otherwise error when input is not an intiger.
     */
    int getInput(const std::string& prompt) const;

    /**
     * @brief Gets input data from the user.
     * 
     * The user can type multiple lines of data, ending input by typing "stop".
     * 
     * @return The input data as a string.
     */
    std::string getInputData() const;


    /**
     * @brief Saves or appends encrypted data to a file.
     * 
     * Prompts the user to choose between creating a new file or appending to an existing file.
     * 
     * Choice:
     * 1 - Save data to a new file
     * 2 - Append data to an existing file
     * 3 - Do nothing
     * 
     * @param encryptor The encryptor object containing the encrypted data.
     */
    void saveOrAppendToFile(sr::Encryptor &encryptor);

    /**
     * @brief Saves or appends decrypted data to a file.
     * 
     * Prompts the user to choose between creating a new file or appending to an existing file.
     * 
     * Choice:
     * 1 - Save data to a new file
     * 2 - Append data to an existing file
     * 3 - Do nothing
     * 
     * @param decryptor The decryptor object containing the decrypted data.
     */
    void saveOrAppendToFile(sr::Decryptor &decryptor);

    /**
     * @brief Checks if a string represents a valid integer.
     * 
     * @param str The string to check.
     * @return True if the string is a valid integer, false otherwise.
     */
    bool isInteger(const std::string& str) const;
};
}
