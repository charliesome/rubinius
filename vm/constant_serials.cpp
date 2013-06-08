#include "constant_serials.hpp"
#include "builtin/symbol.hpp"

using namespace rubinius;

ConstantSerialMap::ConstantSerialMap() {
  lock_.init();
}

ConstantSerial* ConstantSerialMap::operator [](Symbol* sym) {
  utilities::thread::SpinLock::LockGuard guard();
  ConstantSerial*& serial = serials_[sym->index()];
  if(!serial) {
    serial = new ConstantSerial();
  }
  return serial;
}
