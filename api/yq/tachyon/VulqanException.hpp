////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/TachyonException.hpp>

namespace yq::tachyon {
    class VulqanException : public TachyonException {
    public:
        VulqanException(const VulqanException&) = default;
        template <size_t N>
        VulqanException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            TachyonException(msg, sl) {}
    };
}
