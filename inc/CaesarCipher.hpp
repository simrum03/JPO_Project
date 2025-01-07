#pragma once

#include "Encryptor.hpp"
#include "Decryptor.hpp"

namespace sr{

/**
 * @class CaesarEncryptor
 * @brief A class that provides functionality to encrypt text using the Caesar cipher algorithm.
 * 
 * The CaesarEncryptor shifts each letter in the input text by a specified number of positions 
 * in the alphabet to produce the encrypted output. Non-alphabetic characters remain unchanged.
 * The class allows for setting and retrieving the shift value, providing a description of the 
 * encryption settings, and performing the encryption operation.
 */
class CaesarEncryptor : public Encryptor {
private:
    int m_shift;

public:
    /**
     * @brief Default constructor. 
     * 
     * Initializes the shift value by default to 7.
     */
    CaesarEncryptor();

    /**
     * @brief Parameterized constructor.
     * @param shift Number of positions to shift in the Caesar cipher.
     */
    CaesarEncryptor(int shift);

    /**
     * @brief Destructor.
     */
    ~CaesarEncryptor() {}

    /**
     * @brief Sets the shift value for the Caesar cipher.
     * @param shift Number of positions to shift. Must be non-negative.
     */
    void setShift(int shift);

    /**
     * @brief Gets the current shift value.
     * @return The number of positions to shift in the Caesar cipher.
     */
    int getShift() const;

    /**
     * @brief Provides a description of the encryption algorithm and current settings.
     * @return A string describing the encryption algorithm and shift value.
     */
    std::string description() const override;

    /**
     * @brief Encrypts the data using the Caesar cipher algorithm.
     * @return The encrypted data as a string.
     */
    std::string encrypt() override;

};


/**
 * @class CaesarDecryptor
 * @brief A class that provides functionality to decrypt text using the Caesar cipher algorithm.
 * 
 * The CaesarDecryptor reverses the encryption process by shifting each letter in the encrypted text 
 * backward by a specified number of positions in the alphabet to recover the original plaintext. 
 * Non-alphabetic characters remain unchanged. The class allows for setting and retrieving the shift value, 
 * providing a description of the decryption settings, and performing the decryption operation.
 */
class CaesarDecryptor : public Decryptor {
private:
    int m_shift; ///< Number of positions to shift in the Caesar cipher.

public:
    /**
     * @brief Default constructor initializes the shift value to 7.
     */
    CaesarDecryptor();

    /**
     * @brief Parameterized constructor.
     * @param shift Number of positions to shift in the Caesar cipher.
     */
    CaesarDecryptor(int shift);

    /**
     * @brief Destructor.
     */
    ~CaesarDecryptor() {}

    /**
     * @brief Sets the shift value for the Caesar cipher.
     * @param shift Number of positions to shift. Must be non-negative.
     */
    void setShift(int shift);

    /**
     * @brief Gets the current shift value.
     * @return The number of positions to shift in the Caesar cipher.
     */
    int getShift() const;


    /**
     * @brief Provides a description of the decryption algorithm and current settings.
     * @return A string describing the decryption algorithm and shift value.
     */
    std::string description() const override;

    /**
     * @brief Decrypts the data using the Caesar cipher algorithm.
     * @return The decrypted data as a string.
     */
    std::string decrypt() override;
};
}