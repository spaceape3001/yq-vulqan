////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UILayout.hpp>

namespace yq::tachyon {
    class UIVBoxLayoutWriter;

    //! Tool meant for laying out WINDOWS!  (It'll reject otherwise)
    class UIVBoxLayout : public UILayout {
        YQ_OBJECT_DECLARE(UIVBoxLayout, UILayout)
    public:
        using Writer = UIVBoxLayoutWriter;
        UIVBoxLayout(UIFlags flags={});
        UIVBoxLayout(const UIVBoxLayout&);
        virtual ~UIVBoxLayout();
        
        UIVBoxLayout* clone() const override;
        
        static void init_meta();
        
    protected:
        void    render() override;
        void   postadd(UIElement*) override;
        virtual YesNo   acceptable(UIElement*) override;
    };
}
