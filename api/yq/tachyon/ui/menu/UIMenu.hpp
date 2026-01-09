////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElements.hpp>
#include <yq/tachyon/keywords.hpp>

namespace yq::tachyon {
    class UIMenuWriter;
    class UIMenu : public UIElements {
        YQ_OBJECT_DECLARE(UIMenu, UIElements)
    public:
        using Writer = UIMenuWriter;
    
        UIMenu(std::string_view, UIFlags flags={});
        UIMenu(const UIMenu&);
        virtual ~UIMenu();
        
        virtual UIMenu*     clone() const override;

        virtual const char*   title() const override;
        
        static void init_meta();

    protected:
        virtual void        render() override;

    private:
        std::string     m_name;
    };
}
