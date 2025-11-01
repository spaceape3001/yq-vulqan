////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIWindow.hpp"
#include <yq/tachyon/MyImGui.hpp>
#include <yq/math/utility.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/tachyon/logging.hpp>

#include <yq/text/format.hpp>
#include <yq/tachyon/ui/UIStyle.hpp>
#include <atomic>

#include <yq/shape/AxBox2.hxx>
#include <yq/shape/Size2.hxx>
#include <yq/vector/Vector2.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIWindow)

namespace yq {
    template Size2<float>::Size2(const Vector2F&);
}

namespace yq::tachyon {
    void UIWindow::init_meta()
    {
        auto w = writer<UIWindow>();
        w.description("\"Window\" in ImGui (not to be confused with the OS/Desktop Window)");
    }

    UIWindow::UIWindow(std::string_view zTitle, UIFlags flags) : 
        UIElements(flags),
        m_title(zTitle)
    {
        m_w.minimum = m_w.maximum = -1;
        m_h.minimum = m_h.maximum = -1;
        update(FLAGS);
    }
    
    UIWindow::UIWindow(const UIWindow& cp) : UIElements(cp), 
        m_title(cp.m_title),
        m_pivot(cp.m_pivot),
        m_x(cp.m_x),
        m_y(cp.m_y),
        m_w(cp.m_w),
        m_h(cp.m_h),
        m_imFlags(cp.m_imFlags),
        m_chFlags(cp.m_chFlags)
    {
    }
    
    UIWindow::~UIWindow()
    {
    }
    
    UIWindow*   UIWindow::clone() const
    {
        return new UIWindow(*this);
    }

    float       UIWindow::height() const
    {
        return height(USE);
    }
    
    float       UIWindow::height(actual_k) const
    {
        return m_h.actual;
    }
    
    float       UIWindow::height(calculate_k) const
    {
        return m_h.calc;
    }
    
    float       UIWindow::height(next_k) const
    {
        return m_h.next;
    }
    
    float       UIWindow::height(specification_k) const
    {
        return m_h.spec;
    }
    
    float       UIWindow::height(use_k) const
    {
        float   h   = std::max(antinan({ m_h.next, m_h.calc, m_h.spec, m_h.actual }, 0.f), style().window.min_size());
        if(m_h.maximum > 0.)
            h   = std::min(h, m_h.maximum);
        if(m_h.minimum > 0.)
            h   = std::max(h, m_h.minimum);
        return h;
    }
    
    void        UIWindow::height(set_k, calculate_k, float v)
    {
        m_h.calc    = v;
    }
    
    void        UIWindow::height(set_k, specification_k, float v)
    {
        m_h.spec    = v;
    }
    
    void        UIWindow::height(set_k, next_k, float v)
    {
        m_h.next    = v;
        m_flags |= UIFlag::SetSizeOnce;
    }

    Vector2F    UIWindow::position() const
    {
        return position(USE);
    }
    
    Vector2F    UIWindow::position(actual_k) const
    {
        return { m_x.actual, m_y.actual };
    }
    
    Vector2F    UIWindow::position(calculate_k) const
    {
        return { m_x.calc, m_y.calc };
    }
    
    Vector2F    UIWindow::position(next_k) const
    {
        return { m_x.next, m_y.next };
    }
    
    Vector2F    UIWindow::position(specification_k) const
    {
        return { m_x.spec, m_y.spec };
    }
    
    Vector2F    UIWindow::position(use_k) const
    {
        return { x(USE), y(USE) };
    }
    
    void        UIWindow::position(set_k, calculate_k, Vector2F v)
    {
        m_x.calc    = v.x;
        m_y.calc    = v.y;
    }
    
    void        UIWindow::position(set_k, next_k, Vector2F v)
    {
        m_x.next        = v.x;
        m_y.next        = v.y;
        m_flags        |= UIFlag::SetPositionOnce;
    }
    
    void        UIWindow::position(set_k, specification_k, Vector2F v)
    {
        m_x.spec    = v.x;
        m_y.spec    = v.y;
    }
    
    void        UIWindow::render()
    {
        if(m_flags(UIFlag::Invisible))
            return ;
            
        bool    isChild = m_flags(UIFlag::IsChild);
            
        if(m_title.empty()){
            static std::atomic<uint64_t> counter{0};
            m_title = "##";
            m_title += to_string( (uint64_t) (counter++));
        }
            
        bool    open  = true;
        

        if(isChild){
            float   w   = width(USE);
            float   h   = height(USE);
            m_h.next    = nanF;
            m_w.next    = nanF;
            m_flags -= UIFlag::SetSizeOnce;
            
            if(ImGui::BeginChild(m_title.c_str(), { w, h }, m_chFlags, m_imFlags)){
                content();
            }
        } else {
            if(m_flags.any({UIFlag::SetPosition, UIFlag::SetPositionOnce})){
                ImGui::SetNextWindowPos({ x(USE), y(USE) }, 0, m_pivot);
                m_x.next    = nanF;
                m_y.next    = nanF;
                m_flags -= UIFlag::SetPositionOnce;
            }
            if(m_flags.any({UIFlag::SetSize, UIFlag::SetSizeOnce})){
                ImGui::SetNextWindowSize({ width(USE), height(USE) });
                ImGui::SetNextWindowSizeConstraints( { m_w.minimum, m_h.minimum }, {m_w.maximum, m_h.maximum});
                m_h.next    = nanF;
                m_w.next    = nanF;
                m_flags -= UIFlag::SetSizeOnce;
            }

            if(ImGui::Begin(m_title.c_str(), m_flags(UIFlag::Closeable) ? &open : nullptr, m_imFlags)){
                content();
            }
        }
            
        auto p  = ImGui::GetWindowPos();
        m_x.actual  = p.x;
        m_y.actual  = p.y;

        auto s = ImGui::GetWindowSize();
        m_w.actual  = s.x;
        m_h.actual  = s.y;
        
        if(isChild){
            ImGui::EndChild();
        } else {
            ImGui::End();
        }

        if(!open){
            m_flags |= UIFlag::Invisible;  
            closing();
        }
    }
    Size2F      UIWindow::size() const
    {
        return size(USE);
    }
    
    Size2F      UIWindow::size(actual_k) const
    {
        return { m_w.actual, m_h.actual };
    }
    
    Size2F      UIWindow::size(calculate_k) const
    {
        return { m_w.calc, m_h.calc };
    }
    
    Size2F      UIWindow::size(next_k) const
    {
        return { m_w.next, m_h.next };
    }
    
    Size2F      UIWindow::size(specification_k) const
    {
        return { m_w.spec, m_h.spec };
    }
    
    Size2F      UIWindow::size(use_k) const
    {
        return { width(USE), height(USE) };
    }
    
    void        UIWindow::size(set_k, calculate_k, Size2F v)
    {
        m_w.calc    = v.x;
        m_h.calc    = v.y;
    }
    
    void        UIWindow::size(set_k, next_k, Size2F v)
    {
        m_w.next    = v.x;
        m_h.next    = v.y;
        m_flags |= UIFlag::SetSizeOnce;
    }
    
    void        UIWindow::size(set_k, specification_k, Size2F v)
    {
        m_w.spec    = v.x;
        m_h.spec    = v.y;
    }

    const char*   UIWindow::title() const 
    {
        return m_title.c_str();
    }

    void    UIWindow::update(flags_k)
    {
        m_imFlags   = ImGui::WindowFlags(m_flags);
        m_chFlags   = ImGui::ChildFlags(m_flags);
        if(m_flags(UIFlag::IsChild)){
            m_imFlags &= ~ImGuiWindowFlags_AlwaysAutoResize;
            if((m_chFlags & ImGuiChildFlags_AlwaysAutoResize) && !(m_chFlags & (ImGuiChildFlags_AutoResizeX | ImGuiChildFlags_AutoResizeY)))
                m_chFlags &= ~ImGuiChildFlags_AlwaysAutoResize;
        }
    }

    AxBox2F UIWindow::viewport() const
    {
        float   _x = x(USE);
        float   _y = y(USE);
        float   _w = width(USE);
        float   _h = height(USE);
        
        return AxBox2F(UNION, {_x, _y}, {_x+_w, _y+_h});
    }

    float       UIWindow::width() const
    {
        return width(USE);
    }
    
    float       UIWindow::width(actual_k) const
    {
        return m_w.actual;
    }
    
    float       UIWindow::width(calculate_k) const
    {
        return m_w.calc;
    }
    
    float       UIWindow::width(next_k) const
    {
        return m_w.next;
    }
    
    float       UIWindow::width(specification_k) const
    {
        return m_w.spec;
    }
    
    float       UIWindow::width(use_k) const
    {
        float w = std::max(antinan({ m_w.next, m_w.calc, m_w.spec, m_w.actual }, 0.f), style().window.min_size());
        if((m_w.maximum > 0.) && (w>m_w.maximum))
            w   = m_w.maximum;
        if((m_w.minimum > 0.) && (w<m_w.minimum))
            w   = m_w.minimum;
        return w;
    }
    
    void        UIWindow::width(set_k, calculate_k, float v)
    {
        m_w.calc    = v;
    }
    
    void        UIWindow::width(set_k, next_k, float v)
    {
        m_w.next    = v;
        m_flags |= UIFlag::SetSizeOnce;
    }
    
    void        UIWindow::width(set_k, specification_k, float v)
    {
        m_w.spec    = v;
    }

    float       UIWindow::x() const
    {
        return x(USE);
    }
    
    float       UIWindow::x(actual_k) const
    {
        return m_x.actual;
    }
    
    float       UIWindow::x(calculate_k) const
    {
        return m_x.calc;
    }
    
    float       UIWindow::x(next_k) const
    {
        return m_x.next;
    }
    
    float       UIWindow::x(specification_k) const
    {
        return m_x.spec;
    }
    
    float       UIWindow::x(use_k) const
    {
        return antinan({ m_x.next, m_x.calc, m_x.spec, m_x.actual }, 0.f);
    }
    
    void        UIWindow::x(set_k, calculate_k, float v)
    {
        m_x.calc    = v;
    }
    
    void        UIWindow::x(set_k, next_k, float v)
    {
        m_x.next    = v;
    }
    
    void        UIWindow::x(set_k, specification_k, float v)
    {
        m_x.spec = v;
        m_flags |= UIFlag::SetPositionOnce;
    }

    float       UIWindow::y() const
    {
        return y(USE);
    }
    
    float       UIWindow::y(actual_k) const
    {
        return m_y.actual;
    }
    
    float       UIWindow::y(calculate_k) const
    {
        return m_y.calc;
    }
    
    float       UIWindow::y(next_k) const
    {
        return m_y.next;
    }
    
    float       UIWindow::y(specification_k) const
    {
        return m_y.spec;
    }
    
    float       UIWindow::y(use_k) const
    {
        return antinan({ m_y.next, m_y.calc, m_y.spec, m_y.actual }, 0.f);
    }
    
    void        UIWindow::y(set_k, calculate_k, float v)
    {
        m_y.calc = v;
    }
    
    void        UIWindow::y(set_k, next_k, float v)
    {
        m_y.next = v;
        m_flags |= UIFlag::SetPositionOnce;
    }
    
    void        UIWindow::y(set_k, specification_k, float v)
    {
        m_y.spec = v;
    }

}
