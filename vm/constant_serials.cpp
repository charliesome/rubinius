#include "constant_serials.hpp"
#include "builtin/symbol.hpp"

using namespace rubinius;

ConstantSerialMap::ConstantSerialMap() {
  lock_.init();
}

ConstantSerialMap::~ConstantSerialMap() {
  for(std::tr1::unordered_map<native_int, ConstantSerial*>::iterator iter = serials_.begin(); iter != serials_.end(); ++iter) {
    delete iter->second;
  }
}

ConstantSerial* ConstantSerialMap::operator [](Symbol* sym) {
  utilities::thread::SpinLock::LockGuard guard();
  ConstantSerial*& serial = serials_[sym->index()];
  if(!serial) {
    serial = new ConstantSerial();
  }
  return serial;
}
