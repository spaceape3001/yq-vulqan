////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/container/reverse.hpp>
#include <yq/tachyon/ui/UIConsole.hpp>
#include <yq/tachyon/ui/UIConsoleWriter.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/text/transform.hpp>
#include <yq/text/vsplit.hpp>
#include <yq/typedef/string_vectors.hpp>
#include <yq/vector/Vector2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIConsole)

namespace yq::tachyon {
    struct UIConsole::Line {
        //  things like font & weight & misc style will go here....

        RGBA4F          color   = { 0., 0., 0., 0. };
        float           indent  = 0.;
        std::string     text;
        double          y       = 0.;
        float           x       = 0.;
        float           w       = 0.;
        float           h       = 0.;
    };

    void UIConsole::init_meta()
    {
    }
    
    UIConsole::UIConsole(std::string_view z, UIFlags flags) : 
        UIWindow(z, flags | UIFlag::AlwaysHorizontalScrollBar | UIFlag::AlwaysVerticalScrollBar)
    {
    }
    
    UIConsole::UIConsole(const UIConsole& cp) : UIWindow(cp), m_lines(cp.m_lines)
    {
    }
    
    UIConsole::~UIConsole()
    {
    }

    void    UIConsole::submit(const Options& options, std::string_view txt)
    {
        bool empty  = false;
        txt     = trimmed(txt);
        vsplit(txt, '\n', [&](std::string_view v){
            v = trimmed_end(v);
            if(v.empty()){  // new line filtering...
                if(empty)
                    return;
                empty   = true;
            } else
                empty   = false;

            Line        l;
            l.color     = options.color;
            l.indent    = options.indent;
            if(options.pre.empty()){
                l.text  = std::string(v);
            } else {
                l.text  = options.pre + v;
            }
            m_lines.push_back(std::move(l));
        });
    }
    
    void    UIConsole::submit(std::string_view txt)
    {
        submit({}, txt);
    }

    void    UIConsole::clear()
    {
        m_lines.clear();
        if(m_cursor.y > 0)
            m_cursor.y  = 0;
    }
    

    void    UIConsole::content() 
    {
        const ImGuiStyle&   style   = ImGui::GetStyle();
        ImDrawList*     drawList    = ImGui::GetWindowDrawList();
        Vector2F        nw          = (Vector2F) ImGui::GetWindowPos() + (Vector2F) style.FramePadding;
        Vector2F        se          = nw + (Vector2F) ImGui::GetWindowSize() - Vector2F(ALL, style.ScrollbarSize) - (Vector2F) style.FramePadding;
        //Vector2F        ne          = { se.x, nw.y };
        //Vector2F        sw          = { nw.x, se.y };
        float           th          = ImGui::GetTextLineHeightWithSpacing();
        
        for(;m_digest < m_lines.size();++m_digest){
            Line& l = m_lines[m_digest];
            l.x     = th * l.indent;
            l.y     = m_txtH;
            
            ImVec2  sz  = ImGui::CalcTextSize(l.text.c_str());
            l.w         = sz.x;
            l.h         = sz.y;
            
            m_txtH     += std::max(th, sz.y);
            m_txtW      = std::max(m_txtW, l.x+l.w);
        }
        
        
        //ImU32   dc    = ImGui::Color(color::BrickRed);
        
        
        //  scroll bars....
        //  we'll do the drawing here...

        // temporary hack
        //drawList->AddLine(nw, se, dc);
        //drawList->AddLine(sw, ne, dc);
        //drawList->AddEllipse(0.5*(se+nw), 0.5*(se-nw), dc);
        
        float       y   = se.y - th;
        for(const Line& l : reverse(m_lines)){
            if(y < nw.y)
                break;
            ImU32   clr = (l.color.alpha > 0.) ? ImGui::Color(l.color) : ImGui::Color(style.Colors[ImGuiCol_Text]);
            drawList->AddText({nw.x+l.x, y}, clr, l.text.c_str());
            y -= th;
        }
    }
    
    UIConsole*      UIConsole::clone() const 
    {
        return new UIConsole(*this);
    }
        
    
////////////////////////////////////////////////////////////////////////////////

    UIConsoleWriter::UIConsoleWriter() = default;
    UIConsoleWriter::UIConsoleWriter(const UIConsoleWriter&) = default;
    UIConsoleWriter::~UIConsoleWriter() = default;

    UIConsole* UIConsoleWriter::element()
    {
        return static_cast<UIConsole*>(m_ui);
    }
    
    UIConsoleWriter::UIConsoleWriter(UIConsole* ui) : UIWindowWriter(ui)
    {
    }
}

