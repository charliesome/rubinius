#ifndef RBX_CONSTANT_SERIALS_HPP
#define RBX_CONSTANT_SERIALS_HPP

#include "prelude.hpp"
#include "util/thread.hpp"

#include <tr1/unordered_map>

namespace rubinius {
  class Symbol;

  class ConstantSerial {
    native_int serial_;

  public:
    native_int current() const {
      return serial_;
    }

    bool valid_p(native_int serial) {
      return serial == serial_;
    }

    void increment() {
      atomic::fetch_and_add(&serial_, (native_int)1);
    }
  };

  class ConstantSerialMap {
    rubinius::utilities::thread::SpinLock lock_;
    std::tr1::unordered_map<native_int, ConstantSerial*> serials_;

  public:
    ConstantSerialMap();
    ConstantSerial* operator [](Symbol*);
  };
}

#endif
