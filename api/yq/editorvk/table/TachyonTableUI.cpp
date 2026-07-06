////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonTableUI.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

namespace yq::tachyon {
    TachyonTableUI::TachyonTableUI(UIFlags flags) : UIPanel("tachyons", flags)
    {
        m_table = new Table;
        m_table->binding(CREATE);
    }
    
    TachyonTableUI::TachyonTableUI(const TachyonTableUI&cp) : UIPanel(cp)
    {
        for(UIElement* ui : items()){
            if(auto p = dynamic_cast<Table*>(ui)){
                m_table = ui;
                break;
            }
        }
    }
    
    TachyonTableUI* TachyonTableUI::clone() const 
    {
        return new TachyonTableUI(*this);
    }
    
    void TachyonTableUI::init_meta()
    {
        auto w = writer<TachyonTableUI>();
        w.description("Tachyon Table UI");
    }

    ////////////////////////////////////////////////////////////////////////////
    

    TachyonTableUI::Table::Table(UIFlags flgs) : UIElement(flgs)
    {
    }
    
    TachyonTableUI::Table::Table(const Table& cp) : UIElement(cp)
    {
    }
    
    TachyonTableUI::Table* TachyonTableUI::Table::clone() const 
    {
        return new Table(*this);
    }

    void TachyonTableUI::Table::render() 
    {
        UIElement::render();
    }

    void TachyonTableUI::Table::content() 
    {
        UIElement::content();
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonTableUI)
YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonTableUI::Table)
