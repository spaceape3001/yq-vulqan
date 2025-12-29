////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIPanel.hxx"
#include "UIPanelWriter.hpp"

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/trait/has_nan.hpp>

#include <yq/shape/AxBox2.hxx>

namespace yq::tachyon {

    UIPanel::Pointers::Pointers() = default;
    UIPanel::Pointers::~Pointers() = default;
    UIPanel::Pointers::Pointers(const Pointers&) = default;

////////////////////////////////////////////////////////////////////////////////

    void UIPanel::init_meta()
    {
        auto w = writer<UIPanel>();
        w.description("UI Panel (ie, for the main window)");
    }

    UIPanel*    UIPanel::panel(const std::string& uid)
    {
        return dynamic_cast<UIPanel*>(element(FIRST, uid));
    }
    
    UIPanel*    UIPanel::panel(uint64_t bid)
    {
        return dynamic_cast<UIPanel*>(element(FIRST, bid));
    }

    UIWindow*    UIPanel::window(const std::string& uid)
    {
        return dynamic_cast<UIWindow*>(element(FIRST, uid));
    }
    
    UIWindow*    UIPanel::window(uint64_t bid)
    {
        return dynamic_cast<UIWindow*>(element(FIRST, bid));
    }
    
////////////////////////////////////////////////////////////////////////////////

    
    UIPanel::UIPanel(std::string_view title, UIFlags flags) : UIWindow(title, flags)
    {
    }
    
    UIPanel::UIPanel(const UIPanel& cp) : UIWindow(cp), m_calc(cp.m_calc)
    {
    }
    
    UIPanel::~UIPanel()
    {
    }

    UIPanel* UIPanel::clone() const 
    {
        return new UIPanel(*this);
    }
    
    void    UIPanel::render() 
    {
        Context ctx { 
            .available  = parent()->viewport(CONTENT),
            .current    = box()
        };
        
        float   l   = NaNf;
        float   r   = NaNf;
        float   t   = NaNf;
        float   b   = NaNf;
        float   w   = NaNf;
        float   h   = NaNf;
        float   hx  = NaNf;
        float   hn  = NaNf;
        float   wx  = NaNf;
        float   wn  = NaNf;
        
        //  get the calculations

        if(m_calc.left)
            l           = m_calc.left -> compute(ctx);
        if(m_calc.right)
            r           = m_calc.right -> compute(ctx);
        if(m_calc.top)
            t           = m_calc.top -> compute(ctx);
        if(m_calc.bottom)
            b           = m_calc.bottom -> compute(ctx);
        if(m_calc.width){
            w           = m_calc.width -> compute(ctx);
        } else if((m_w.actual > 0) && !is_nan(m_w.actual)){
            w           = m_w.actual;
        } else if(m_calc.widthStart){
            w           = m_calc.widthStart -> compute(ctx);
        }
        if(m_calc.widthMax)
            wx          = m_calc.widthMax -> compute(ctx);
        if(m_calc.widthMin)
            wn          = m_calc.widthMin -> compute(ctx);
            
        if(m_calc.height){
            h           = m_calc.height -> compute(ctx);
        } else if((m_h.actual > 0) && !is_nan(m_h.actual)){
            h           = m_h.actual;
        } else if(m_calc.heightStart){
            h           = m_calc.heightStart -> compute(ctx);
        }
        
        if(m_calc.heightMax)
            hx          = m_calc.heightMax -> compute(ctx);
        if(m_calc.heightMin)
            hn          = m_calc.heightMin -> compute(ctx);

        if(m_flags(UIFlag::Debug)){
            uiInfo << "UIPanel(" << title() << ")::render() calculations:\n"
                   << "  bottom     : " << b << '\n'
                   << "  height     : " << h << '\n'
                   << "  height min : " << h << '\n'
                   << "  height max : " << h << '\n'
                   << "  left       : " << l << '\n'
                   << "  right      : " << r << '\n'
                   << "  top        : " << t << '\n'
                   << "  width      : " << w << '\n'
                   << "  width max  : " << wx << '\n'
                   << "  width min  : " << wn << '\n'
            ;
        }

        // And... determine...
        
        if(is_nan(l))
            l           = ctx.available.lo.x;
        if(is_nan(t))
            t           = ctx.available.lo.y;
        if(is_nan(r)){
            if(is_nan(w))
                r       = ctx.available.hi.x;
            else
                r       = l + w;
        }
        if(is_nan(b)){
            if(is_nan(h))
                b       = ctx.available.hi.y;
            else
                b       = t + h;
        }
        
        m_x.next        = l;
        m_y.next        = t;
        m_w.next        = r - l;
        m_h.next        = b - t;

        if(!is_nan(hx))
            m_h.maximum = hx;
        if(!is_nan(hn))
            m_h.minimum = hn;
            
        if(!is_nan(wx))
            m_w.maximum = wx;
        if(!is_nan(wn))
            m_w.minimum = wn;
        
        m_flags |= UIFlag::SetPositionOnce;
        m_flags |= UIFlag::SetSizeOnce;
        
        UIWindow::render();
    }
    
    // ---------------------------------------

    void    UIPanel::bottom(set_k, const CalcSCPtr&v)
    {
        m_calc.bottom   = v;
    }
    
    void    UIPanel::left(set_k, const CalcSCPtr& v)
    {
        m_calc.left = v;
    }

    void    UIPanel::height(set_k, const CalcSCPtr& v)
    {
        m_calc.height   = v;
    }
    
    void    UIPanel::height(set_k, maximum_k, const CalcSCPtr&v)
    {
        m_calc.heightMax    = v;
    }
    
    void    UIPanel::height(set_k, minimum_k, const CalcSCPtr&v)
    {
        m_calc.heightMin    = v;
    }

    void    UIPanel::height(set_k, start_k, const CalcSCPtr& v)
    {
        m_calc.heightStart   = v;
    }
    
    void    UIPanel::right(set_k, const CalcSCPtr& v)
    {
        m_calc.right = v;
    }
    
    void    UIPanel::top(set_k, const CalcSCPtr& v)
    {
        m_calc.top  = v;
    }
    
    void    UIPanel::width(set_k, const CalcSCPtr& v)
    {
        m_calc.width = v;
    }
    
    void    UIPanel::width(set_k, maximum_k, const CalcSCPtr& v)
    {
        m_calc.widthMax = v;
    }
    
    void    UIPanel::width(set_k, minimum_k, const CalcSCPtr& v)
    {
        m_calc.widthMin = v;
    }

    void    UIPanel::width(set_k, start_k, const CalcSCPtr& v)
    {
        m_calc.widthStart   = v;
    }
    

////////////////////////////////////////////////////////////////////////////////

    UIPanelWriter::UIPanelWriter() = default;
    UIPanelWriter::UIPanelWriter(const UIPanelWriter&) = default;
    UIPanelWriter::~UIPanelWriter() = default;

    UIPanel* UIPanelWriter::element()
    {
        return static_cast<UIPanel*>(m_ui);
    }
    
    UIPanelWriter::UIPanelWriter(UIPanel* ui) : UIWindowWriter(ui)
    {
    }

    // ---------------------------------------

    UIPanelWriter&  UIPanelWriter::bottom(const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->bottom(SET, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::bottom(float v)
    {
        return bottom(std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::bottom(pivot_k, float v)
    {
        return bottom(std::make_shared<UIPanel::ScaledV>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::bottom(std::string_view k, bottom_k)
    {
        return bottom(std::make_shared<UIPanel::UIDBottom>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::bottom(std::string_view k, top_k)
    {
        return bottom(std::make_shared<UIPanel::UIDTop>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::height(const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->height(SET, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::height(float v)
    {
        return height(std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::height(pivot_k, float v)
    {
        return height(std::make_shared<UIPanel::ScaledV>(v));
    }

    UIPanelWriter&  UIPanelWriter::height(toolbar_k)
    {
        return height(std::make_shared<UIPanel::StyToolBar>());
    }
    
    UIPanelWriter&  UIPanelWriter::height(maximum_k, const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->height(SET, MAXIMUM, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::height(maximum_k, float v)
    {
        return height(MAXIMUM, std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::height(maximum_k, pivot_k, float v)
    {
        return height(MAXIMUM, std::make_shared<UIPanel::ScaledV>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::height(minimum_k, const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->height(SET, MINIMUM, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::height(minimum_k, float v)
    {
        return height(MINIMUM, std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::height(minimum_k, pivot_k, float v)
    {
        return height(MINIMUM, std::make_shared<UIPanel::ScaledV>(v));
    }

    UIPanelWriter&  UIPanelWriter::height(start_k, const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->height(SET, START, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::height(start_k, float v)
    {
        return height(START, std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::height(start_k, pivot_k, float v)
    {
        return height(START, std::make_shared<UIPanel::ScaledV>(v));
    }

    UIPanelWriter&  UIPanelWriter::left(const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->left(SET, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::left(float v)
    {
        return left(std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::left(pivot_k, float v)
    {
        return left(std::make_shared<UIPanel::ScaledH>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::left(std::string_view k, left_k)
    {
        return left(std::make_shared<UIPanel::UIDLeft>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::left(std::string_view k, right_k)
    {
        return left(std::make_shared<UIPanel::UIDRight>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::right(const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->right(SET, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::right(float v)
    {
        return right(std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::right(pivot_k, float v)
    {
        return right(std::make_shared<UIPanel::ScaledH>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::right(std::string_view k, left_k)
    {
        return right(std::make_shared<UIPanel::UIDLeft>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::right(std::string_view k, right_k)
    {
        return right(std::make_shared<UIPanel::UIDRight>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::top(const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->top(SET, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::top(float v)
    {
        return top(std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::top(pivot_k, float v)
    {
        return top(std::make_shared<UIPanel::ScaledV>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::top(std::string_view k, bottom_k)
    {
        return top(std::make_shared<UIPanel::UIDBottom>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::top(std::string_view k, top_k)
    {
        return top(std::make_shared<UIPanel::UIDTop>(k));
    }
    
    UIPanelWriter&  UIPanelWriter::width(const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->width(SET, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::width(float v)
    {
        return width(std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::width(pivot_k, float v)
    {
        return width(std::make_shared<UIPanel::ScaledH>(v));
    }

    UIPanelWriter&  UIPanelWriter::width(toolbar_k)
    {
        return width(std::make_shared<UIPanel::StyToolBar>());
    }
    
    UIPanelWriter&  UIPanelWriter::width(maximum_k, const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->width(SET, MAXIMUM, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::width(maximum_k, float v)
    {
        return width(MAXIMUM, std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::width(maximum_k, pivot_k, float v)
    {
        return width(MAXIMUM, std::make_shared<UIPanel::ScaledH>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::width(minimum_k, const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->width(SET, MINIMUM, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::width(minimum_k, float v)
    {
        return width(MINIMUM, std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::width(minimum_k, pivot_k, float v)
    {
        return width(MINIMUM, std::make_shared<UIPanel::ScaledH>(v));
    }

    
    UIPanelWriter&  UIPanelWriter::width(start_k, const UIPanel::CalcSCPtr& v)
    {
        if(UIPanel*p = element())
            p->width(SET, START, v);
        return *this;
    }
    
    UIPanelWriter&  UIPanelWriter::width(start_k, float v)
    {
        return width(START, std::make_shared<UIPanel::Fixed>(v));
    }
    
    UIPanelWriter&  UIPanelWriter::width(start_k, pivot_k, float v)
    {
        return width(START, std::make_shared<UIPanel::ScaledH>(v));
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIPanel)
