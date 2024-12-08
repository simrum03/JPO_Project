#pragma once

#include <iostream>
#include <string>

class Decryptor {
protected:
    std::string m_algorithm;
    std::string m_data;

public:
    Decryptor() : m_algorithm(""), m_data("") {}
    Decryptor(const std::string &name, const std::string &data = "") : m_algorithm(name), m_data(data) {}

    virtual ~Decryptor() {}

    void addData (const std::string &data) {
        m_data += data;
    }

    const std::string getData() const {
        return m_data;
    }

    virtual void description() const = 0;
    virtual std::string decrypt() = 0;

    void clearData() {
        m_data.clear();
    }
};