//
// Created by Altorais on 2024/11/18.
//

#include <assert.h>
#include <iostream>
#include <string.h>

#include "include/leveldb/db.h"

int main() {

  leveldb::DB* db = NULL;
  leveldb::Options options;
  options.create_if_missing = true;
  // 需要在cmake-build-debug下新增tmp目录
  leveldb::Status status = leveldb::DB::Open(options, "tmp/testdb", &db);
  std::cout << status.ToString() << std::endl;
  assert(status.ok());

  std::string key = "test_key";
  std::string value = "test_value";
  std::string get;

  leveldb::Status s = db->Put(leveldb::WriteOptions(), key, value);

  if (s.ok())
    s = db->Get(leveldb::ReadOptions(), key, &get);
  if (s.ok())
    std::cout << "key=" << key << "\nvalue=" << get  << std::endl;
  else
    std::cout << "failed to find the key!" << std::endl;


//  std::string key = "name";
//
//#if defined(WRITE_MODE)
//  std::string value = "Jeff Dean";
//  // 写入key, value
//  status = db->Put(leveldb::WriteOptions(), key, value);
//  std::cout << "write key:" << key << " value:" << value << " "
//            << status.ToString() << std::endl;
//#else
//  std::string db_value;
//  status = db->Get(leveldb::ReadOptions(), key, &db_value);
//  std::cout << "read key:" << key << " value:" << db_value << " "
//            << status.ToString() << std::endl;
//#endif
  delete db;

  return 0;
}
