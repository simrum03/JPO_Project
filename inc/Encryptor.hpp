#pragma once

#include <iostream>
#include <string>

class Encryptor {
protected:
    std::string m_algorithm;
    std::string m_data;

public:
    Encryptor() : m_algorithm(""), m_data("") {}
    Encryptor(const std::string &name, const std::string &data = "") : m_algorithm(name), m_data(data) {}

    virtual ~Encryptor() {}

    void addData (const std::string &data) {
        m_data += data;
    }

    const std::string getData() const {
        return m_data;
    }

    virtual void description() const = 0;
    virtual std::string encrypt() = 0;

    void clearData() {
        m_data.clear();
    }
};