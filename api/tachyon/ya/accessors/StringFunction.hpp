////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/typedef/accessors.hpp>
#include <functional>

namespace yq::tachyon {

    class StringFunction : public StringAccessor {
    public:

        using FN = std::function<std::string_view()>;

        StringFunction(FN&&);
        
        Any                 get(any_k) const override;
        std::string_view    get(value_k) const override;
        
        ~StringFunction();
        
    private:
        FN                  m_function;
    };
}
