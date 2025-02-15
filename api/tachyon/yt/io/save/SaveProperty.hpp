////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Any.hpp>

namespace yq {
    class PropertyInfo;
}

namespace yq::tachyon {
    struct SaveProperty {
        const PropertyInfo*         info    = nullptr;
        Any                         value;
    };
}
