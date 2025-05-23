////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <cstddef>
#include <tachyon/config/vulqan.hpp>

namespace yq {
    template <size_t> class BasicBuffer;
}

namespace yq::tachyon {
    using PushBuffer    = BasicBuffer<MAX_PUSH>;
}
