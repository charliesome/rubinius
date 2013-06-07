#include "constant_serials.hpp"
#include "builtin/symbol.hpp"
#include "util/atomic.hpp"

using namespace rubinius;

ConstantSerials::Serial* ConstantSerials::symbol_serial(Symbol* sym) {
  ConstantSerials::Serial*& serial = serials[sym->index()];
  if(!serial) {
    serial = new ConstantSerials::Serial();
  }
  return serial;
}
