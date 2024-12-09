#pragma once

#include <iostream>
#include <string>

namespace sr{
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

    virtual std::string description() const  = 0;
    virtual std::string decrypt() = 0;

    void writeToFile(const std::string& filename, const std::string& data, const std::string& label = "", bool append = false) const {
        std::ofstream outFile(filename, append ? std::ios::app : std::ios::out);
        if (outFile.is_open()) {
            if (append && !label.empty()) {
                outFile << "----- " << label << " -----" << std::endl;
            }

            outFile << "Encryption Details:" << std::endl;
            outFile << description();
            
            
            outFile << data << std::endl;

            if (append && !label.empty()) {
                outFile << "--------------------" << std::endl;
            }
            outFile.close();
            std::cout << "Data has been " << (append ? "appended to " : "saved to ") << filename << std::endl;
        } 
        else 
        {
            std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        }
    }

    void clearData() {
        m_data.clear();
    }
};
}