////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/accessor/StringFunction.hpp>

namespace yq::tachyon {
    StringFunction::StringFunction(FN&&fn) : m_function(std::move(fn))
    {
        assert(m_function);
    }
    
    Any                 StringFunction::get(any_k) const 
    {
        return Any(m_function());
    }
    
    std::string_view    StringFunction::get(value_k) const 
    {
        return m_function();
    }
    
    StringFunction::~StringFunction()
    {
    }
}
