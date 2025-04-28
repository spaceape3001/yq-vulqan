////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIButtonBar.hpp"
#include <tachyon/ui/UIUtils.hpp>
#include <tachyon/ui/UIStyle.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/vector/Vector2.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/ui/UIElementInfoWriter.hpp>

#include <yq/shape/AxBox2.hxx>
#include <yq/shape/Size2.hxx>
#include <yq/vector/Vector2.hxx>

namespace yq {
    // not sure why it wasn't instantiating this constructor, forcing it
    template AxBox2<float>::AxBox2(union_k, const Vector2F&, const Vector2F&);
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIButtonBar)

namespace yq::tachyon {
    namespace {
        /*
            bool    truth_table(Cardinal v)
            {
                switch(v){
                case Cardinal::Unknown:
                case Cardinal::Center:
                case Cardinal::NW:
                case Cardinal::NNW:
                case Cardinal::North:
                case Cardinal::NNE:
                case Cardinal::NE:
                case Cardinal::ENE:
                case Cardinal::East:
                case Cardinal::ESE:
                case Cardinal::SE:
                case Cardinal::SSE:
                case Cardinal::South:
                case Cardinal::SSW:
                case Cardinal::SW:
                case Cardinal::WSW:
                case Cardinal::West:
                case Cardinal::WNW:
                default:
                    return false;
                }
            }
        */

     
        constexpr Vector2F    pivot_for(Cardinal v)
        {
            switch(v){
            case Cardinal::Unknown:
            case Cardinal::Center:
                return { 0., 0. };
            case Cardinal::NW:
            case Cardinal::NNW:
                return { 0., 0. };
            case Cardinal::North:
                return { 0.5, 0. };
            case Cardinal::NNE:
                return { 1.0, 0. };
            case Cardinal::NE:
                return { 0.0, 0. };
            case Cardinal::ENE:
                return { 1.0, 0. };
            case Cardinal::East:
                return { 1.0, 0.5 };
            case Cardinal::ESE:
                return { 1.0, 1.0 };
            case Cardinal::SE:
                return ZERO;
            case Cardinal::SSE:
                return { 1.0, 1.0 };
            case Cardinal::South:
                return { 0.5, 1.0 };
            case Cardinal::SSW:
                return { 0.0, 1.0 };
            case Cardinal::SW:
                return ZERO;
            case Cardinal::WSW:
                return { 0.0, 1.0 };
            case Cardinal::West:
                return { 0.0, 0.5 };
            case Cardinal::WNW:
                return { 0.0, 0.0 };
            default:
                return ZERO;
            }
        }
     
        UIFlags add_flags(Cardinal v)
        {
            switch(v){
            case Cardinal::Unknown:
                return {};
            case Cardinal::Center:
                return {};
            case Cardinal::NW:
                return {};
            case Cardinal::NNW:
                return UIFlag::Horizontal;
            case Cardinal::North:
                return UIFlag::Horizontal;
            case Cardinal::NNE:
                return UIFlag::Horizontal;
            case Cardinal::NE:
                return {};
            case Cardinal::ENE:
                return {};
            case Cardinal::East:
                return {};
            case Cardinal::ESE:
                return {};
            case Cardinal::SE:
                return {};
            case Cardinal::SSE:
                return UIFlag::Horizontal;
            case Cardinal::South:
                return UIFlag::Horizontal;
            case Cardinal::SSW:
                return UIFlag::Horizontal;
            case Cardinal::SW:
                return UIFlag::Horizontal;
            case Cardinal::WSW:
                return {};
            case Cardinal::West:
                return {};
            case Cardinal::WNW:
                return {};
            default:
                return {};
            }
        }

        static constexpr const UIFlags  kToolBarFlags   = { UIFlag::NoDecoration, UIFlag::NoMove, UIFlag::SetPosition, UIFlag::AlwaysAutoResize };
    }

    void UIButtonBar::init_info()
    {
        auto w = writer<UIButtonBar>();
        w.description("UI Tool Bar");
        
        w.property("pivot", &UIButtonBar::pivot_get)
            .setter(&UIButtonBar::pivot_set)
            .description("Pivot point for the tool bar (in screen normalized coordinates)")
        ;
    }

    
    UIButtonBar::UIButtonBar(Cardinal b, std::string_view title, UIFlags flags) : UIButtonBar(pivot_for(b), title, UIFlags(add_flags(b) | flags))
    {
    }

    UIButtonBar::UIButtonBar(Vector2F piv, std::string_view title, UIFlags flags) :
        UIWindow(title, UIFlags(flags | kToolBarFlags))
    {
        pivot(SET, piv);
    }
    

    UIButtonBar::UIButtonBar(const UIButtonBar& cp) : UIWindow(cp)
    {
    }
    
    UIButtonBar::~UIButtonBar()
    {
    }
    
    UIButtonBar*  UIButtonBar::clone() const
    {
        return new UIButtonBar(*this);
    }

    void     UIButtonBar::pivot(set_k, Vector2F vec)
    {
        m_pivot     = vec;
        Vector2F    pointing    = m_pivot - Vector2F(0.5, 0.5);

        if(abs(pointing.y) > abs(pointing.x)){
            m_flags.set(UIFlag::Horizontal);
        } else if(abs(pointing.x) > abs(pointing.y)){
            m_flags.clear(UIFlag::Horizontal);
        }
        update(FLAGS);
    }

    Vector2F    UIButtonBar::pivot_get() const
    {
        return m_pivot;
    }
    
    void        UIButtonBar::pivot_set(const Vector2F& vec)
    {
        pivot(SET, vec);
    }

    void    UIButtonBar::render() 
    {
        if(m_flags(UIFlag::Invisible))
            return ;
        
        const auto& sty = style();
        float   edge    = sty.toolbar.inset() + m_number * (sty.toolbar.thickness() + sty.toolbar.padding());
        AxBox2F box = parent() -> viewport(CONTENT).inflate(-edge);
        
        position(SET, NEXT, box.project(m_pivot).emax(0.));
        
        #if 0
        if(m_flags(UIFlag::Horizontal)){
            m_size  = Size2F( sty.toolbar.length(m_actualSize.x), sty.toolbar.thickness());
        } else {
            m_size  = Size2F( sty.toolbar.thickness(), sty.toolbar.length(m_actualSize.y));
        }
        #endif
        
        //uiInfo << "UIButtonBar::render(): " << m_size << " @ " << m_position << " {" << m_pivot << "} in " << box << " edge=" << edge << " imflags=" << m_imFlags;

        UIWindow::render();
    }

    float   UIButtonBar::thickness() const
    {
        return style().toolbar.thickness();
    }
}
