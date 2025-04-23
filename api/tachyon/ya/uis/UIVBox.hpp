////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UILayout.hpp>

namespace yq::tachyon {
    class UIVBoxWriter;

    //! Tool meant for laying out WINDOWS!  (It'll reject otherwise)
    class UIVBox : public UILayout {
        YQ_OBJECT_DECLARE(UIVBox, UILayout)
    public:
        using Writer = UIVBoxWriter;
        UIVBox(UIFlags flags={});
        UIVBox(const UIVBox&);
        virtual ~UIVBox();
        
        UIVBox* clone() const override;
        
        static void init_info();
        
    protected:
        void    render() override;
        void   postadd(UIElement*) override;
        virtual YesNo   acceptable(UIElement*) override;
    };
}
