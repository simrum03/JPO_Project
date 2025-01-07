#pragma once

#include <iostream>
#include <string>

namespace sr{

/**
 * @class Encryptor
 * @brief Abstract base class for encryption algorithms.
 *
 * The "Encryptor" class provides a framework for implementing different
 * encryption algorithms. Derived classes must implement the pure virtual
 * functions "description" and `encrypt".
 */

class Encryptor {
protected:
    std::string m_algorithm; ///< Name of the encryption algorithm.
    std::string m_data; ///< Data to be encrypted.

public:
    /**
     * @brief Default constructor.
     *
     * Initializes the algorithm name and data to empty strings.
     */
    Encryptor();

    /**
     * @brief Parameterized constructor.
     *
     * @param name Name of the encryption algorithm.
     * @param data Initial data to be encrypted (default is an empty string).
     */
    Encryptor(const std::string &name, const std::string &data = "");

    /**
     * @brief Virtual destructor.
     */
    virtual ~Encryptor() = default;


    /**
     * @brief Adds data to the encryption buffer.
     *
     * @param data Data to be added to the buffer.
     */
    void addData (const std::string &data);

    /**
     * @brief Retrieves the encrypted or unencrypted data.
     *
     * @return A string containing the data.
     */
    const std::string getData() const;

    /**
     * @brief Provides a description of the encryption algorithm.
     *
     * Derived classes must implement this function to return a textual
     * description of the algorithm.
     *
     * @return A string describing the encryption algorithm.
     */
    virtual std::string description() const  = 0;

    /**
     * @brief Performs the encryption process.
     *
     * Derived classes must implement this function to perform the encryption
     * on the stored data.
     *
     * @return The encrypted data as a string.
     */    
    virtual std::string encrypt() = 0;

    /**
     * @brief Writes encrypted data to a file.
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