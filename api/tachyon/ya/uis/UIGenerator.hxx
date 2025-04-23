////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIGenerator.hpp>
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
            U* u = m_create(w);
            if(u && flags())
                u -> flags(SET, flags());
            return u;
        }

        virtual const UIElementInfo*    ui_info() const override
        { 
            return &meta<U>();
        }

    private:
        function_t    m_create;
    };
}
