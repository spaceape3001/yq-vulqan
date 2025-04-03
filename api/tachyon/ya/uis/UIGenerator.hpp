////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>
#include <functional>
#include <cassert>
#include <utility>

namespace yq::tachyon {
    template <SomeUIElement U=UIElement>
    struct UIGenerator : public UIElement {
        using function_t = std::function<U*(Widget&)>;
        function_t    create;
        
        UIGenerator(function_t&& fn) : create(std::move(fn))
        {
            assert(create);
        }
        
        ~UIGenerator(){}
        
        U*     clone() const override
        {
            return create(widget());
        }
        
        void    render() override 
        {
            //  non-existent render given we won't be rendered
        }
    };

}
