////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/Exception.hpp>

namespace yq::tachyon {
    class TachyonException : public Exception {
    public:
    
        TachyonException(const TachyonException&) = default;
        template <size_t N>
        TachyonException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            Exception(msg, sl) {}
    };
}
