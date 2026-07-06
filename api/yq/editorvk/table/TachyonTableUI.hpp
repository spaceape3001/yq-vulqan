////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/layout/UIPanel.hpp>

namespace yq::tachyon {
    class TachyonTableUI : public UIPanel {
        YQ_OBJECT_DECLARE(TachyonTableUI, UIPanel)
    public:
    
        class Table;

        TachyonTableUI(UIFlags={});
        TachyonTableUI(const TachyonTableUI&);
        TachyonTableUI* clone() const override;
    
        
        static void init_meta();
        
    private:
        Table*      m_table = nullptr;
    };
    
    class TachyonTableUI::Table : public UIElement {
        YQ_OBJECT_DECLARE(Table, UIElement)
    public:
    
        Table(UIFlags flgs={});
        Table(const Table&);
        
        Table* clone() const override;

        void render() override;
        void content() override;
    };
}
