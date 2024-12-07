#pragma once

#include "Encryptor.hpp"
#include "Decryptor.hpp"

class CaesarEncryptor : public Encryptor {
private:
    int m_shift;

public:
    CaesarEncryptor() : Encryptor("Caesar Cipher"), m_shift(7) {}
    CaesarEncryptor(int shift) : Encryptor("Caesar Cipher"), m_shift(shift) {}

    ~CaesarEncryptor() {}

    void setShift(int shift) {
        m_shift = shift;
    }

    int getShift() {
        return m_shift;
    }

    void description() const override {
        std::cout << "Algorithm: " << m_algorithm << std::endl;
        std::cout << "Shift: " << m_shift << std::endl;
    }

    std::string encrypt() override {
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

};