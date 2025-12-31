////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElement.hpp>
#include <yq/tachyon/typedef/model.hpp>

namespace yq::tachyon{
    class Frame;

    class ModelTableUI : public UIElement {
        YQ_OBJECT_DECLARE(ModelTableUI, UIElement)
    public:
        static void init_meta();
        
        ModelTableUI(UIFlags flags={});
        ModelTableUI(const ModelTableUI& cp);
        
        virtual ModelTableUI*   clone() const;
        const char*    title() const override;
        
        void    render() override;

        ModelID         selected() const { return m_selected; }
        void            set_selected(ModelID);

        void            tick() override;

    private:

        struct Row;
        
        
        void            changed_select();

        TextureID           m_editing;
        ModelID             m_selected;
        std::vector<Row>    m_rows;
    };

}
