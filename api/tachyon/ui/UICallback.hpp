////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElement.hpp>

namespace yq::tachyon {

    /*! \brief UI Element that executes the specified callback
    */
    class UICallback : public UIElement {
        YQ_OBJECT_DECLARE(UICallback, UIElement)
    public:
        UICallback(UIFlags flags={});
        UICallback(const UICallback&);
        virtual ~UICallback();
        static void init_info();
    };
}
