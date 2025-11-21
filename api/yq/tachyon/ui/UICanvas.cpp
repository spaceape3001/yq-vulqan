////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UICanvas.hpp"
#include "UICanvasWriter.hpp"

#include <yq/shape/AxBox2.hpp>
#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UICanvas)

namespace yq::tachyon {
    UICanvas::UICanvas(std::string_view k, UIFlags flags) : UIElement(flags), m_key(k), m_size(0., 0.)
    {
    }
    
    UICanvas::UICanvas(const UICanvas& cp) : UIElement(cp), m_key(cp.m_key), m_size(cp.m_size)
    {
    }
    
    UICanvas::~UICanvas()
    {
    }
        
    UICanvas* UICanvas::clone() const 
    {
        return new UICanvas(*this);
    }
    
    void UICanvas::content(const AxBox2F&)
    {
        content();
    }
    
    void UICanvas::render() 
    {
        if(ImGui::BeginChild(m_key.c_str(), {m_size.x, m_size.y}, 
            ImGuiChildFlags_Borders, 
            ImGuiWindowFlags_AlwaysVerticalScrollbar|ImGuiWindowFlags_AlwaysHorizontalScrollbar
        )){
            content(AxBox2F{});
        }
        ImGui::EndChild();
    }

    void            UICanvas::size(set_k, const Size2F&v)
    {
        m_size  = v;
    }

        
    void UICanvas::init_meta()
    {
        auto w = writer<UICanvas>();
        w.description("Canvas UI Element");
    }

    
////////////////////////////////////////////////////////////////////////////////

    UICanvasWriter::UICanvasWriter() = default;
    UICanvasWriter::UICanvasWriter(const UICanvasWriter&) = default;
    UICanvasWriter::~UICanvasWriter() = default;

    UICanvas* UICanvasWriter::element()
    {
        return static_cast<UICanvas*>(m_ui);
    }
    
    UICanvasWriter::UICanvasWriter(UICanvas* ui) : UIElementWriter(ui)
    {
    }

    UICanvasWriter&    UICanvasWriter::size(const Size2F&sz)
    {
        if(UICanvas* elem = element())
            elem -> size(SET, sz);
        return *this;
    }
    
}

