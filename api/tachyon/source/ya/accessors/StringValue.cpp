////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/accessors/StringValue.hpp>

namespace yq::tachyon {
    StringValue::StringValue(const char* s) : m_value(s ? std::string(s) : std::string())
    {
    }
    

    StringValue::StringValue(const std::string&s) : m_value(s)
    {
    }

    StringValue::StringValue(std::string&&s) : m_value(std::move(s))
    {
    }
    
    
    StringValue::StringValue(std::string_view s) : m_value(s)
    {
    }

    StringValue::~StringValue()
    {
    }

    Any                 StringValue::get(any_k) const 
    {
        return Any(m_value);
    }
    
    std::string_view    StringValue::get(value_k) const 
    {
        return m_value;
    }
}
