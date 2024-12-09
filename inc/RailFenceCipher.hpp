#pragma once

#include "Encryptor.hpp"
#include "Decryptor.hpp"
#include <vector>

namespace sr{
class RailFenceEncryptor : public Encryptor {
private:
    int m_rails;

public:
    RailFenceEncryptor() : Encryptor("Rail fence cipher"), m_rails(2) {}
    RailFenceEncryptor(int rails) : Encryptor("Rail fence cipher"), m_rails(rails) {}

    ~RailFenceEncryptor() {}

    void setRails(int rails){
        m_rails = rails;
    }

    int getRails(){
        return m_rails;
    }

    std::string description() const override {
        std::ostringstream oss;
        oss << "Algorithm: " << m_algorithm << std::endl;
        oss << "Number of rails: " << m_rails << std::endl;
        oss << "Encrypted data: ";
        return oss.str();
    }

    std::string encrypt() override {
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
};

class RailFenceDecryptor : public Decryptor {
private:
    int m_rails;

public:
    RailFenceDecryptor() : Decryptor("Rail fence cipher"), m_rails(2) {}
    RailFenceDecryptor(int rails) : Decryptor("Rail fence cipher"), m_rails(rails) {}

    ~RailFenceDecryptor() {}

    void setRails(int rails){
        m_rails = rails;
    }

    int getRails(){
        return m_rails;
    }

    std::string description() const override {
        std::ostringstream oss;
        oss << "Algorithm: " << m_algorithm << std::endl;
        oss << "Number of rails: " << m_rails << std::endl;
        oss << "Decrypted data: ";
        return oss.str();
    }

    std::string decrypt() override {
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
};
}
