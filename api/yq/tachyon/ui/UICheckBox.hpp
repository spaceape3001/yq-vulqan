////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <string_view>
#include <string>
#include <yq/shape/Size2.hpp>
#include <variant>
#include <yq/tachyon/typedef/accessors.hpp>

namespace yq::tachyon {
    class UICheckBoxWriter;
    
    /*! \brief Simple Text CheckBox
    */
    class UICheckBox : public UIElement {
        YQ_OBJECT_DECLARE(UICheckBox, UIElement)
    public:
        using Writer = UICheckBoxWriter;

        UICheckBox(std::string_view, UIFlags flags={});
        UICheckBox(const UICheckBox&);
        virtual ~UICheckBox();
        void                    render();
        const char*             title() const override;
        std::string_view        text() const { return m_text; }
        
        bool                    checked() const;
        
        static void init_meta();
    
    protected:
        virtual UICheckBox*     clone() const = 0;
        virtual bool            get() const = 0;
        virtual void            set(bool)  = 0;
        
    private:
        std::string         m_text;
    };
}
