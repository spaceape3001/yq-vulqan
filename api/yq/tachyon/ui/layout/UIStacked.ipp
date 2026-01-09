////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIStackedWriter.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIStacked)

namespace yq::tachyon {
    UIStacked::UIStacked(UIFlags flags) : UIElements(flags)
    {
    }
    
    UIStacked::UIStacked(const UIStacked& cp) : 
        UIElements(cp), 
            m_dummy(cp.m_dummy), 
            m_select(cp.m_select)
    {
    }
    
    UIStacked::~UIStacked()
    {
    }
    
    UIStacked* UIStacked::clone() const 
    {
        return new UIStacked(*this);
    }
    
    void    UIStacked::render() 
    {
        if(m_select && (m_select <= m_items.size())){
            m_items[m_select-1]->render();
        } else if(m_dummy != ZERO){
            ImGui::Dummy(m_dummy);
        }
        
        //  likely improve to get smarter, maybe adaptive with begin/end child?
    }
    
    
    // It's 1...count (ie, we subtract one to render, 0 for the dummy)
    void            UIStacked::select(size_t n)
    {
        m_select = n;
    }
    
    size_t            UIStacked::count() const
    {
        return m_items.size();
    }
    
    void            UIStacked::dummy(set_k, const Size2F&v)
    {
        m_dummy  = v;
    }

////////////////////////////////////////////////////////////////////////////////

    UIStackedWriter::UIStackedWriter() = default;
    UIStackedWriter::UIStackedWriter(const UIStackedWriter&) = default;
    UIStackedWriter::~UIStackedWriter() = default;

    UIStacked* UIStackedWriter::element()
    {
        return static_cast<UIStacked*>(m_ui);
    }
    
    UIStackedWriter::UIStackedWriter(UIStacked* ui) : UIElementsWriter(ui)
    {
    }
    
    UIStackedWriter&    UIStackedWriter::select(size_t n)
    {
        if(UIStacked* u = element())
            u -> select(n);
        return *this;
    }
    
    UIStackedWriter&    UIStackedWriter::dummy(const Size2F&v)
    {
        if(UIStacked* u = element())
            u -> dummy(SET, v);
        return *this;
    }
}
