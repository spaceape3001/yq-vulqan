////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/api/Exception.hpp>

namespace yq::tachyon {
    class VulqanException : public Exception {
    public:
        VulqanException(const VulqanException&) = default;
        template <size_t N>
        VulqanException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            Exception(msg, sl) {}
    };
}
