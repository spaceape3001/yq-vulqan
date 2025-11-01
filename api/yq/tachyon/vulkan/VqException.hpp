////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Exception.hpp>

namespace yq::tachyon {
    class VqException : public Exception {
    public:
        VqException(const VqException&) = default;
        template <size_t N>
        VqException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            Exception(msg, sl) {}
    };
}
