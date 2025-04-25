////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/accessors.hpp>
#include <yq/text/format.hpp>

namespace yq::tachyon {

    class StringValue : public StringAccessor {
    public:

        StringValue(const char* s);
        StringValue(const std::string&s);
        StringValue(std::string&&s);
        StringValue(std::string_view s);

        template <Stringable S>
        StringValue(S value) : StringValue(to_string(value))
        {
        }
        
        Any                 get(any_k) const override;
        std::string_view    get(value_k) const override;
        
        ~StringValue();
        
    private:
        std::string     m_value;
    };
}
