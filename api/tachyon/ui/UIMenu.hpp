////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>
#include <yt/keywords.hpp>

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
        
        static void init_info();

    protected:
        virtual void        render() override;

    private:
        std::string     m_name;
    };
}
