////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElements.hpp>

namespace yq::tachyon {
    /*! Section of something with a specified title, useful for tree nodes, etc
    */
    class UISection : public UIElements {
        YQ_OBJECT_DECLARE(UISection, UIElements)
    public:
        static void init_meta();
        UISection(std::string_view, UIFlags={});
        UISection(const UISection&);
        ~UISection();
        virtual UISection* clone() const override;
        virtual const char* title() const;
    private:
        std::string     m_title;
    };
}
