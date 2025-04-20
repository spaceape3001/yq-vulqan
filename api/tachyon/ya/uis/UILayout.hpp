////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElements.hpp>
#include <string_view>
#include <string>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class UILayoutWriter;
    
    /*! \brief Simple Text Layout
    */
    class UILayout : public UIElements {
        YQ_OBJECT_DECLARE(UILayout, UIElements)
    public:
        using Writer = UILayoutWriter;

        UILayout(UIFlags flags={});
        UILayout(const UILayout&);
        virtual ~UILayout();
        
        static void init_info();
    protected:
        UILayout*       clone() const;
    };
}
