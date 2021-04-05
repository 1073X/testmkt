
#include "source/lib/adapter.hpp"

namespace miu::mkt {

adapter* create_adapter() {
    return new testmkt::adapter();
}

}    // namespace miu::mkt
