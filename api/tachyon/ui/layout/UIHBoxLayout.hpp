////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UILayout.hpp>

namespace yq::tachyon {
    class UIHBoxLayoutWriter;

    //! Tool meant for laying out WINDOWS!  (It'll reject otherwise)
    class UIHBoxLayout : public UILayout {
        YQ_OBJECT_DECLARE(UIHBoxLayout, UILayout)
    public:
        using Writer = UIHBoxLayoutWriter;
        UIHBoxLayout(UIFlags flags={});
        UIHBoxLayout(const UIHBoxLayout&);
        virtual ~UIHBoxLayout();
        
        UIHBoxLayout* clone() const;
        
        static void init_info();
        
    protected:
        void                render() override;
        void                postadd(UIElement*) override;
        virtual YesNo       acceptable(UIElement*) override;
    };
}
