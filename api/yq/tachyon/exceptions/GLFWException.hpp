////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/exceptions/TachyonException.hpp>

namespace yq::tachyon {
    class GLFWException : public TachyonException {
    public:
        GLFWException(const GLFWException&) = default;
        template <size_t N>
        GLFWException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            TachyonException(msg, sl) {}
    };
}
