////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>

namespace yq::tachyon {
    class UISeparator : public UIElement {
        YQ_OBJECT_DECLARE(UISeparator, UIElement)
    public:
        
        UISeparator(UIFlags flags={});
        UISeparator(const UISeparator&);
        virtual ~UISeparator();
        UISeparator* clone() const override;
        void                    render();

        static void init_meta();
    };
}
