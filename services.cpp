#include "services.h"
#include <iostream>


Services::Services() {
    options.create_if_missing = true;
    leveldb::Status status = leveldb::DB::Open(options, "/tmp/testdb", &db);

    if ( !status.ok() ) {
        throw; //TODO fixme
    }
}



Services::~Services() {
    delete db;
}



bool Services::getProduct(const std::string& id, Product& p) const {
    std::string reg;
    leveldb::Slice key = id;
    leveldb::Status s = db->Get(leveldb::ReadOptions(), key, &reg);

    if ( s.IsNotFound() ) {
        return false;
    }

    //TODO verificar s?
    p.read(reg);
    return true;
}



void Services::take(const std::string& id) {
    Product p;
    this->getProduct(id, p);
    p.decrease();

    std::string reg;
    p.write(reg);

    leveldb::Slice key = id;
    leveldb::Status s = db->Put(leveldb::WriteOptions(), key, reg);
    //TODO verificar s?
}



void Services::place(const std::string& id) {
    Product p;
    this->getProduct(id, p);
    p.increase();

    std::string reg;
    p.write(reg);

    leveldb::Slice key = id;
    leveldb::Status s = db->Put(leveldb::WriteOptions(), key, reg);
    //TODO verificar s?
}
