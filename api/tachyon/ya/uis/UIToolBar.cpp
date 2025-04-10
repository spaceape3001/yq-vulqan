////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIToolBar.hpp"
#include "UIToolBarWriter.hpp"
#include <yt/ui/UIUtils.hpp>
#include <yt/ui/UIStyle.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/vector/Vector2.hpp>
#include <yt/logging.hpp>
#include <yt/ui/UIElementInfoWriter.hpp>

#include <yq/shape/AxBox2.hxx>
#include <yq/shape/Size2.hxx>
#include <yq/vector/Vector2.hxx>

namespace yq {
    // not sure why it wasn't instantiating this constructor, forcing it
    template AxBox2<float>::AxBox2(union_k, const Vector2F&, const Vector2F&);
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::UIToolBar)

namespace yq::tachyon {
    namespace {
        /*
            bool    truth_table(UICardinal v)
            {
                switch(v){
                case UICardinal::Unknown:
                case UICardinal::Center:
                case UICardinal::NW:
                case UICardinal::NNW:
                case UICardinal::North:
                case UICardinal::NNE:
                case UICardinal::NE:
                case UICardinal::ENE:
                case UICardinal::East:
                case UICardinal::ESE:
                case UICardinal::SE:
                case UICardinal::SSE:
                case UICardinal::South:
                case UICardinal::SSW:
                case UICardinal::SW:
                case UICardinal::WSW:
                case UICardinal::West:
                case UICardinal::WNW:
                default:
                    return false;
                }
            }
        */

     
        constexpr Vector2F    pivot_for(UICardinal v)
        {
            switch(v){
            case UICardinal::Unknown:
            case UICardinal::Center:
                return { 0., 0. };
            case UICardinal::NW:
            case UICardinal::NNW:
                return { 0., 0. };
            case UICardinal::North:
                return { 0.5, 0. };
            case UICardinal::NNE:
                return { 1.0, 0. };
            case UICardinal::NE:
                return { 0.0, 0. };
            case UICardinal::ENE:
                return { 1.0, 0. };
            case UICardinal::East:
                return { 1.0, 0.5 };
            case UICardinal::ESE:
                return { 1.0, 1.0 };
            case UICardinal::SE:
                return ZERO;
            case UICardinal::SSE:
                return { 1.0, 1.0 };
            case UICardinal::South:
                return { 0.5, 1.0 };
            case UICardinal::SSW:
                return { 0.0, 1.0 };
            case UICardinal::SW:
                return ZERO;
            case UICardinal::WSW:
                return { 0.0, 1.0 };
            case UICardinal::West:
                return { 0.0, 0.5 };
            case UICardinal::WNW:
                return { 0.0, 0.0 };
            default:
                return ZERO;
            }
        }
     
        UIFlags add_flags(UICardinal v)
        {
            switch(v){
            case UICardinal::Unknown:
                return {};
            case UICardinal::Center:
                return {};
            case UICardinal::NW:
                return {};
            case UICardinal::NNW:
                return UIFlag::Horizontal;
            case UICardinal::North:
                return UIFlag::Horizontal;
            case UICardinal::NNE:
                return UIFlag::Horizontal;
            case UICardinal::NE:
                return {};
            case UICardinal::ENE:
                return {};
            case UICardinal::East:
                return {};
            case UICardinal::ESE:
                return {};
            case UICardinal::SE:
                return {};
            case UICardinal::SSE:
                return UIFlag::Horizontal;
            case UICardinal::South:
                return UIFlag::Horizontal;
            case UICardinal::SSW:
                return UIFlag::Horizontal;
            case UICardinal::SW:
                return UIFlag::Horizontal;
            case UICardinal::WSW:
                return {};
            case UICardinal::West:
                return {};
            case UICardinal::WNW:
                return {};
            default:
                return {};
            }
        }

        static constexpr const UIFlags  kToolBarFlags   = { UIFlag::NoDecoration, UIFlag::NoMove, UIFlag::SetPosition, UIFlag::AlwaysAutoResize };
    }

    void UIToolBar::init_info()
    {
        auto w = writer<UIToolBar>();
        w.description("UI Tool Bar");
        
        w.property("pivot", &UIToolBar::pivot_get)
            .setter(&UIToolBar::pivot_set)
            .description("Pivot point for the tool bar (in screen normalized coordinates)")
        ;
    }

    
    UIToolBar::UIToolBar(UICardinal b, std::string_view title, UIFlags flags) : UIToolBar(pivot_for(b), title, UIFlags(add_flags(b) | flags))
    {
    }

    UIToolBar::UIToolBar(Vector2F piv, std::string_view title, UIFlags flags) :
        UIWindow(title, UIFlags(flags | kToolBarFlags))
    {
        pivot(SET, piv);
    }
    

    UIToolBar::UIToolBar(const UIToolBar& cp) : UIWindow(cp)
    {
    }
    
    UIToolBar::~UIToolBar()
    {
    }
    
    UIToolBar*  UIToolBar::clone() const
    {
        return new UIToolBar(*this);
    }

    void     UIToolBar::pivot(set_k, Vector2F vec)
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

    Vector2F    UIToolBar::pivot_get() const
    {
        return m_pivot;
    }
    
    void        UIToolBar::pivot_set(const Vector2F& vec)
    {
        pivot(SET, vec);
    }

    void    UIToolBar::render() 
    {
        if(m_flags(UIFlag::Invisible))
            return ;
        
        const auto& sty = style();
        float   edge    = sty.toolbar.inset() + m_number * (sty.toolbar.thickness() + sty.toolbar.padding());
        AxBox2F box = parent() -> viewport(CONTENT).inflate(-edge);
        m_position  = box.project(m_pivot).emax(0.);
        
        #if 0
        if(m_flags(UIFlag::Horizontal)){
            m_size  = Size2F( sty.toolbar.length(m_actualSize.x), sty.toolbar.thickness());
        } else {
            m_size  = Size2F( sty.toolbar.thickness(), sty.toolbar.length(m_actualSize.y));
        }
        #endif
        
        //uiInfo << "UIToolBar::render(): " << m_size << " @ " << m_position << " {" << m_pivot << "} in " << box << " edge=" << edge << " imflags=" << m_imFlags;

        UIWindow::render();
    }

    float   UIToolBar::thickness() const
    {
        return style().toolbar.thickness();
    }


    ////////////////////////////

    UIToolBarWriter::UIToolBarWriter() = default;
    UIToolBarWriter::UIToolBarWriter(const UIToolBarWriter&) = default;
    UIToolBarWriter::~UIToolBarWriter() = default;

    UIToolBar* UIToolBarWriter::element()
    {
        return static_cast<UIToolBar*>(m_ui);
    }
    
    UIToolBarWriter::UIToolBarWriter(UIToolBar* ui) : UIWindowWriter(ui)
    {
    }
}
