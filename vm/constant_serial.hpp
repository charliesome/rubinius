#ifndef RBX_CONSTANT_SERIALS_HPP
#define RBX_CONSTANT_SERIALS_HPP

#include "prelude.hpp"
#include "util/thread.hpp"

namespace rubinius {
  class Symbol;

  class ConstantSerial {
    native_int serial_;

  public:
    native_int current() const {
      return serial_;
    }

    const native_int* serial_address() const {
      return &serial_;
    }

    bool valid_p(native_int serial) const {
      return serial == serial_;
    }

    void increment() {
      atomic::fetch_and_add(&serial_, (native_int)1);
    }
  };
}

#endif
