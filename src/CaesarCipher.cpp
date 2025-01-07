#include "../inc/CaesarCipher.hpp"
#include <sstream>

namespace sr{

    CaesarEncryptor::CaesarEncryptor() : Encryptor("Caesar cipher"), m_shift(7) {}
    CaesarEncryptor::CaesarEncryptor(int shift) : Encryptor("Caesar cipher"), m_shift(shift) {}

    void CaesarEncryptor::setShift(int shift) {
        if (shift >= 0) {
            m_shift = shift;
        }
        else {
            std::cout << "Incorrect shift." << std::endl;
        }
    }

    int CaesarEncryptor::getShift() const {
        return m_shift;
    }

    std::string CaesarEncryptor::description() const {
        std::ostringstream oss;
        oss << "Algorithm: " << m_algorithm << std::endl;
        oss << "Shift: " << m_shift << std::endl;
        oss << "Encrypted data: ";
        return oss.str();
    }

    std::string CaesarEncryptor::encrypt() {
        if (m_shift <= 1 || m_data.empty()) {
        return m_data;
        }

        std::string encrypted = m_data;
        for (char &c : encrypted) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                c = (c - base + m_shift) % 26 + base;
            }
        }
        m_data = encrypted;
        return m_data;
    }


    CaesarDecryptor::CaesarDecryptor() : Decryptor("Caesar Cipher"), m_shift(7) {}
    CaesarDecryptor::CaesarDecryptor(int shift) : Decryptor("Caesar Cipher"), m_shift(shift) {}

    void CaesarDecryptor::setShift(int shift) {
        if (shift >= 0) {
            m_shift = shift;
        }
        else {
            std::cout << "Incorrect shift." << std::endl;
        }
    }

    int CaesarDecryptor::getShift() const {
        return m_shift;
    }

    std::string CaesarDecryptor::description() const {
        std::ostringstream oss;
        oss << "Algorithm: " << m_algorithm << std::endl;
        oss << "Shift: " << m_shift << std::endl;
        oss << "Decrypted data: ";
        return oss.str();
    }

    std::string CaesarDecryptor::decrypt() {
        if (m_shift <= 1 || m_data.empty()) {
        return m_data;
        }

        std::string decrypted = m_data;
        for (char &c : decrypted) {
            if (std::isalpha(c)) {
                char base = std::islower(c) ? 'a' : 'A';
                c = (c - base - m_shift + 26) % 26 + base;
            }
        }
        m_data = decrypted;
        return m_data;
    }

}