////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UILayout.hpp>

namespace yq::tachyon {
    class UIHBoxWriter;

    //! Tool meant for laying out WINDOWS!  (It'll reject otherwise)
    class UIHBox : public UILayout {
        YQ_OBJECT_DECLARE(UIHBox, UILayout)
    public:
        using Writer = UIHBoxWriter;
        UIHBox(UIFlags flags={});
        UIHBox(const UIHBox&);
        virtual ~UIHBox();
        
        UIHBox* clone() const;
        
        static void init_info();
        
    protected:
        void                render() override;
        void                postadd(UIElement*) override;
        virtual YesNo       acceptable(UIElement*) override;
    };
}
