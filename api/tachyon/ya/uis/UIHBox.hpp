////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>

namespace yq::tachyon {

    //! A line of non-wrapping UI elements
    class UIHBox : public UIElements {
    public:
        UIHBox();
        UIHBox(const UIHBox&);
        ~UIHBox();
        
        UIHBox*     clone() const;
        
    protected:
    
        void    render(items_k) override;
    };
}
