////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElements.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class UIStackedWriter;
    
    //! Meant to choose the element to show....
    class UIStacked : public UIElements {
        YQ_OBJECT_DECLARE(UIStacked, UIElements)
    public:
    
        using Writer = UIStackedWriter;
    
        UIStacked(UIFlags flags={});
        UIStacked(const UIStacked&);
        virtual ~UIStacked();
        
        UIStacked* clone() const override;
        void            render() override;
        
        // It's 1...count (ie, we subtract one to render, 0 for the dummy)
        void            select(size_t);
        size_t          count() const;
        
        const Size2F&   dummy() const { return m_dummy; }
        void            dummy(set_k, const Size2F&);
        
    private:
        Size2F          m_dummy  = ZERO;
        size_t          m_select = 0;
    };
}
