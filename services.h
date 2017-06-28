#ifndef SERVICES_H
#define SERVICES_H

#include <leveldb/db.h>
#include <leveldb/options.h>
#include "data.h"

class Services {
private:
    leveldb::Options options;
    leveldb::DB *db;

    Services();

public:
    ~Services();

    static Services& getInstance() {
        //https://stackoverflow.com/questions/1008019/c-singleton-design-pattern
        static Services instance;
        return instance;
    }

    bool getProduct(const std::string& id, Product& p) const;

    void take(const std::string &id);

    void place(const std::string &id);

};

#endif // SERVICES_H
