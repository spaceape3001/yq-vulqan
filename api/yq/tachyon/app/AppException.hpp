////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/Exception.hpp>

namespace yq::tachyon {
    class AppException : public Exception {
    public:
        AppException(const AppException&) = default;
        template <size_t N>
        AppException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            Exception(msg, sl) {}
    };
}
