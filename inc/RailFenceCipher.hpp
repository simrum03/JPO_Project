#pragma once

#include "Encryptor.hpp"
#include "Decryptor.hpp"
#include <vector>

namespace sr{

/**
 * @class RailFenceEncryptor
 * @brief A class that provides functionality to encrypt text using the Rail Fence cipher.
 * 
 * The RailFenceEncryptor class implements encryption using the Rail Fence cipher.
 * It arranges the text in a zigzag pattern across a specified number of rails,
 * and then reads the text row by row to produce the encrypted text.
 */
class RailFenceEncryptor : public Encryptor {
private:
    int m_rails; ///< The number of rails used for the encryption.

public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the Rail Fence cipher with a default number of rails set to 2.
     */
    RailFenceEncryptor();

    /**
     * @brief Parameterized constructor.
     * @param rails The number of rails to use for the encryption.
     */
    RailFenceEncryptor(int rails);

    /**
     * @brief Destructor.
     */
    ~RailFenceEncryptor() {}

    /**
     * @brief Sets the number of rails for the encryption.
     * @param rails The number of rails. Must be non-negative.
     */
    void setRails(int rails);

    /**
     * @brief Gets the current number of rails.
     * @return The number of rails used for encryption.
     */
    int getRails() const;

    /**
     * @brief Provides a description of the encryption algorithm and current settings.
     * @return A string describing the Rail Fence cipher and the number of rails.
     */
    std::string description() const override;

    /**
     * @brief Encrypts the data using the Rail Fence cipher.
     * 
     * The method arranges the text in a zigzag pattern across the specified number of rails
     * and then reads the text row by row to produce the encrypted string.
     * 
     * @return The encrypted data as a string.
     */
    std::string encrypt() override;
};


/**
 * @class RailFenceDecryptor
 * @brief A class that provides functionality to decrypt text using the Rail Fence cipher.
 * 
 * The RailFenceDecryptor class reverses the encryption process by reassembling the zigzag pattern 
 * to recover the original plaintext. It uses the number of rails used during encryption to perform 
 * the decryption correctly.
 */
class RailFenceDecryptor : public Decryptor {
private:
    int m_rails; ///< The number of rails used for the decryption.

public:
    /**
     * @brief Default constructor.
     * 
     * Initializes the Rail Fence cipher decryption with a default number of rails set to 2.
     */
    RailFenceDecryptor();

    /**
     * @brief Parameterized constructor.
     * @param rails The number of rails to use for the decryption.
     */
    RailFenceDecryptor(int rails);

    /**
     * @brief Destructor.
     */
    ~RailFenceDecryptor() {}

    /**
     * @brief Sets the number of rails for the decryption.
     * @param rails The number of rails. Must be non-negative.
     */
    void setRails(int rails);

    /**
     * @brief Gets the current number of rails.
     * @return The number of rails used for decryption.
     */
    int getRails() const;

    /**
     * @brief Provides a description of the decryption algorithm and current settings.
     * @return A string describing the Rail Fence cipher decryption and the number of rails.
     */
    std::string description() const override;

    /**
     * @brief Decrypts the data using the Rail Fence cipher.
     * 
     * The method reconstructs the zigzag pattern used during encryption to decrypt the message
     * and return the original plaintext.
     * 
     * @return The decrypted data as a string.
     */
    std::string decrypt() override;
};
}
