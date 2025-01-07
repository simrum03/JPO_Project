#include "../inc/RailFenceCipher.hpp"
#include <vector>
#include <sstream>

namespace sr{

    RailFenceEncryptor::RailFenceEncryptor() : Encryptor("Rail fence cipher"), m_rails(2) {}
    RailFenceEncryptor::RailFenceEncryptor(int rails) : Encryptor("Rail fence cipher"), m_rails(rails) {}

    void RailFenceEncryptor::setRails(int rails) {
        if (rails >= 0) {
            m_rails = rails;
        }
        else {
            std::cout << "Incorrect number of rails." << std::endl;
        }
    }
    int RailFenceEncryptor::getRails() const {
        return m_rails;
    }

    std::string RailFenceEncryptor::description() const {
        std::ostringstream oss;
        oss << "Algorithm: " << m_algorithm << std::endl;
        oss << "Number of rails: " << m_rails << std::endl;
        oss << "Encrypted data: ";
        return oss.str();
    }

    std::string RailFenceEncryptor::encrypt() {
    if (m_rails <= 1 || m_data.empty()) {
        return m_data;
    }

    std::vector<std::string> rails(m_rails); 
    int rail = 0; 
    bool directionDown = true;

    for (char c : m_data) {
        rails[rail] += c;
        if (directionDown) {
            rail++;
            if (rail == m_rails) { 
                rail -= 2;
                directionDown = false;
            }
        } 
        else 
        {
            rail--;
            if (rail < 0) { 
                rail += 2;
                directionDown = true;
            }
        }
    }

    m_data.clear();
    for (const auto &line : rails) {
        m_data += line;
    }
    return m_data;
}

    RailFenceDecryptor::RailFenceDecryptor() : Decryptor("Rail fence cipher"), m_rails(2) {}
    RailFenceDecryptor::RailFenceDecryptor(int rails) : Decryptor("Rail fence cipher"), m_rails(rails) {}

    void RailFenceDecryptor::setRails(int rails){
        if (rails >= 0) {
            m_rails = rails;
        }
        else {
            std::cout << "Incorrect number of rails." << std::endl;
        }
    }

    int RailFenceDecryptor::getRails() const {
        return m_rails;
    }

    std::string RailFenceDecryptor::description() const {
        std::ostringstream oss;
        oss << "Algorithm: " << m_algorithm << std::endl;
        oss << "Number of rails: " << m_rails << std::endl;
        oss << "Decrypted data: ";
        return oss.str();
    }

    std::string RailFenceDecryptor::decrypt() {
        if (m_rails <= 1 || m_data.empty()) {
            return m_data;
        }

        std::vector<std::string> rails(m_rails);
        int rail = 0;
        bool directionDown = true;

        std::vector<int> railLengths(m_rails, 0);

        for (char c : m_data) {
            railLengths[rail]++;
            if (directionDown) {
                rail++;
                if (rail == m_rails) {
                    rail -= 2;
                    directionDown = false;
                }
            } 
            else 
            {
                rail--;
                if (rail < 0) {
                    rail += 2;
                    directionDown = true;
                }
            }
        }

        int index = 0;
        for (int i = 0; i < m_rails; ++i) {
            rails[i] = m_data.substr(index, railLengths[i]);
            index += railLengths[i];
        }

        std::string decrypted;
        rail = 0;
        directionDown = true;
        for (size_t i = 0; i < m_data.size(); ++i) {
            decrypted += rails[rail][0];
            rails[rail].erase(rails[rail].begin());

            if (directionDown) {
                rail++;
                if (rail == m_rails) {
                    rail -= 2;
                    directionDown = false;
                }
            } 
            else 
            {
                rail--;
                if (rail < 0) {
                    rail += 2;
                    directionDown = true;
                }
            }
        }
        m_data = decrypted;
        return m_data;
    }
}
