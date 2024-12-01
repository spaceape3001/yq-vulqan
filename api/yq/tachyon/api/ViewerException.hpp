////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonException.hpp>

namespace yq::tachyon {
    class ViewerException : public TachyonException {
    public:
        ViewerException(const ViewerException&) = default;
        template <size_t N>
        ViewerException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : 
            TachyonException(msg, sl) {}
    };
}
