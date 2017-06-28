#ifndef DATA_H
#define DATA_H

#include <limits>
#include <sstream>

class Product {

public:
    int qtd;
    std::string name;
    std::string clazz;

    Product() {
        qtd = 0;
        name = "";
        clazz = "";
    }

    void read(const std::string &s) {
        std::stringstream ss(s);
        ss >> qtd;
        std::getline(ss, name, '\n');
        ss >> clazz;
    }

    void write(std::string &s) {
        std::stringstream ss;
        ss << qtd << name << std::endl << clazz;
        s = ss.str();
    }

    void decrease() {
        if ( qtd <= std::numeric_limits<unsigned short>::min() ) {
            return;
        }

        qtd--;
    }

    void increase() {
        if ( qtd >= std::numeric_limits<unsigned short>::max() ) {
            return;
        }

        qtd++;
    }
};

#endif // DATA_H
