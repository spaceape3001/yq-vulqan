////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UISpacer.hpp"
#include "UISpacerWriter.hpp"
#include <tachyon/MyImGui.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UISpacer)

namespace yq::tachyon {
    void UISpacer::init_info()
    {
        auto w = writer<UISpacer>();
        w.description("UI Spacer");
        w.property("size", &UISpacer::m_size);
    }
    
    UISpacer::UISpacer(const Size2F& size, UIFlags flags) : UIElement(flags), m_size(size)
    {
    }
    
    UISpacer::UISpacer(const UISpacer& cp) : UIElement(cp), m_size(cp.m_size)
    {
    }
    
    UISpacer::~UISpacer()
    {
    }
    
    void            UISpacer::render()
    {
        ImGui::Dummy({ m_size.x, m_size.y });
    }
    
    
    void        UISpacer::size(set_k, const Size2F&sz)
    {
        m_size  = sz;
    }

    UISpacer*       UISpacer::clone() const
    {
        return new UISpacer(*this);
    }
    
    ////////////////////////////
    
    UISpacerWriter::UISpacerWriter() = default;
    UISpacerWriter::UISpacerWriter(const UISpacerWriter&) = default;
    UISpacerWriter::~UISpacerWriter() = default;
    
    UISpacer* UISpacerWriter::element()
    {
        return static_cast<UISpacer*>(m_ui);
    }
    
    UISpacerWriter::UISpacerWriter(UISpacer* ui) : UIElementWriter(ui)
    {
    }

}


/* 
    The implementation will call ImGui::Dummy()
*/
