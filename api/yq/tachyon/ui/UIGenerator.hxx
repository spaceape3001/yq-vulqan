////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIGenerator.hpp>
#include <functional>
#include <cassert>
#include <utility>

namespace yq::tachyon {
    template <SomeUIElement U, SomeWidget W>
    class UIGenerateByWidgetRef : public UIGenerator {
    public:
        using function_t = std::function<U*(W&)>;
        
        UIGenerateByWidgetRef(function_t&& fn) : m_create(std::move(fn))
        {
            assert(m_create);
        }
        
        ~UIGenerateByWidgetRef(){}
        
        U*     clone() const override
        {
            W*  w   = dynamic_cast<W*>(widget());
            if(!w)
                return nullptr;
            return m_create(w);
        }

        virtual const UIElementMeta*    ui_info() const override
        { 
            return &meta<U>();
        }

    private:
        function_t    m_create;
    };
}
