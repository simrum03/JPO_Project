#include "../inc/Encryptor.hpp"
#include <fstream>

namespace sr{

    Encryptor::Encryptor() : m_algorithm(""), m_data("") {}
    Encryptor::Encryptor(const std::string &name, const std::string &data) : m_algorithm(name), m_data(data) {}

    void Encryptor::addData (const std::string &data) {
        m_data += data;
    }

    const std::string Encryptor::getData() const {
        return m_data;
    }

    void Encryptor::writeToFile(const std::string& filename, const std::string& data, const std::string& label, bool append) const {
        std::ofstream outFile(filename, append ? std::ios::app : std::ios::out);
        if (outFile.is_open()) {
            if (append && !label.empty()) {
                std::string labelLine = "----- " + label + " -----";
                outFile << labelLine << std::endl;
            }

            outFile << "Encryption Details:" << std::endl;
            outFile << description();
            
            
            outFile << data << std::endl;

            if (append && !label.empty()) {
                std::string labelLine = "----- " + label + " -----";
                std::string separator(labelLine.size(), '-');
                outFile << separator << std::endl;
            }
            outFile.close();
            std::cout << "Data has been " << (append ? "appended to " : "saved to ") << filename << std::endl;
        } 
        else 
        {
            std::cerr << "Error: Could not open file " << filename << " for writing." << std::endl;
        }
    }

    void Encryptor::clearData() {
        m_data.clear();
    }
}