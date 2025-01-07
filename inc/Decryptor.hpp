#pragma once

#include <iostream>
#include <string>

namespace sr{

/**
 * @class Decryptor
 * @brief Abstract base class for decryption algorithms.
 *
 * The Decryptor class provides a framework for implementing different
 * decryption algorithms. Derived classes must implement the pure virtual
 * functions description and decrypt.
 */

class Decryptor {
protected:
    std::string m_algorithm; ///< Name of the decryption algorithm.
    std::string m_data; ///< Data to be decrypted.

public:

    /**
     * @brief Default constructor.
     *
     * Initializes the algorithm name and data to empty strings.
     */
    Decryptor();

    /**
     * @brief Parameterized constructor.
     *
     * @param name Name of the decryption algorithm.
     * @param data Initial data to be decrypted (default is an empty string).
     */
    Decryptor(const std::string &name, const std::string &data = "");

    /**
     * @brief Virtual destructor.
     */
    virtual ~Decryptor() = default;

    /**
     * @brief Adds data to the decryption buffer.
     *
     * @param data Data to be added to the buffer.
     */
    void addData (const std::string &data);

    /**
     * @brief Retrieves the decrypted or undecrypted data.
     *
     * @return A string containing the data.
     */
    const std::string getData() const;

    /**
     * @brief Provides a description of the decryption algorithm.
     *
     * Derived classes must implement this function to return a textual
     * description of the algorithm.
     *
     * @return A string describing the decryption algorithm.
     */
    virtual std::string description() const  = 0;

    /**
     * @brief Performs the decryption process.
     *
     * Derived classes must implement this function to perform the decryption
     * on the stored data.
     *
     * @return The decrypted data as a string.
     */
    virtual std::string decrypt() = 0;

    /**
     * @brief Writes decrypted data to a file.
     *
     * @param filename Name of the file to write to.
     * @param data Data to be written to the file.
     * @param label Optional label to prepend to the data (default is an empty string).
     * @param append If true, data is appended to the file; otherwise, the file is overwritten (default is false).
     */
    void writeToFile(const std::string& filename, const std::string& data, const std::string& label = "", bool append = false) const;

    /**
     * @brief Clears all data stored in the buffer.
     */
    void clearData();
};
}