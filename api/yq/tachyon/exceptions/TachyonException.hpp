////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <exception>
#include <stdexcept>
#include <source_location>

namespace yq::tachyon {
    class TachyonException : public std::exception {
    public:
    
        TachyonException(const TachyonException&) = default;
        template <size_t N>
        TachyonException(const char (&msg)[N], const std::source_location& sl=std::source_location::current()) : m_what(msg), m_location(sl) {}
        virtual const char* what() const noexcept override { return m_what; }
        
        const std::source_location& where() const noexcept { return m_location; }
    
    private:
        const char*             m_what  = nullptr;
        std::source_location    m_location;
    };
}
