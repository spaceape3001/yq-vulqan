////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Exception.hpp>

namespace yq::tachyon {
    class ExceptionGLFW : public Exception {
    public:
        ExceptionGLFW(const ExceptionGLFW&) = default;
        template <size_t N>
        ExceptionGLFW(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            Exception(msg, sl) {}
    };
}
