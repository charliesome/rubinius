#include "constant_serials.hpp"
#include "builtin/symbol.hpp"
#include "util/atomic.hpp"

using namespace rubinius;

ConstantSerial* ConstantSerialMap::symbol_serial(Symbol* sym) {
  ConstantSerial*& serial = serials_[sym->index()];
  if(!serial) {
    serial = new ConstantSerial();
  }
  return serial;
}
