////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <variant>
#include <yq/tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    template <typename R>
    struct executor_trait_t {
        typedef R (*function_t)(const Url&);
        using result_t  = R;
    };



    //template <typename ... T>
    //struct executor_traits {
        //using types_t   = T...;
    //};

    using executor_result_t = std::variant<std::monostate, WidgetPtr>;
    
}
