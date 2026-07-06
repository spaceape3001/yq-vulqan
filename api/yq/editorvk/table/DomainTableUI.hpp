////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/domain.hpp>

namespace yq::tachyon{

    class DomainTableUI : public UIElement {
        YQ_OBJECT_DECLARE(DomainTableUI, UIElement)
    public:
        static void init_meta();
        
        DomainTableUI(UIFlags flags={});
        DomainTableUI(const DomainTableUI& cp);
        
        virtual DomainTableUI*   clone() const;
        const char*    title() const override;
        
        void    render() override;

        DomainID         selected() const { return m_selected; }
        void            set_selected(DomainID);

        void            tick() override;

    private:

        struct Row;
        
        
        void            changed_select();

        TextureID           m_editing;
        DomainID            m_selected;
        std::vector<Row>    m_rows;
    };

}
