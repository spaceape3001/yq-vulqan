////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <exception>
#include <stdexcept>
#include <source_location>

namespace yq {
    namespace engine {
        class VqException : public std::runtime_error {
        public:
            VqException(const char* what_, const std::source_location& where_=std::source_location::current()) :
                std::runtime_error(what_),  m_where(where_) 
            {
            }
            
            const std::source_location& where() const { return m_where; }
        private:
            std::source_location    m_where;
        };
    }
}
