////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIWindowWriter.hpp"
#include <tachyon/ui/UIMenuBar.hpp>
#include <tachyon/ui/UIMenuBarWriter.hpp>
#include <tachyon/ui/UIToolBar.hpp>
#include <tachyon/ui/UIToolBarWriter.hpp>
#include <tachyon/ui/UIWindow.hpp>
#include <yq/shape/Size2.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {
    UIWindowWriter::UIWindowWriter() = default;
    UIWindowWriter::UIWindowWriter(const UIWindowWriter&) = default;
    UIWindowWriter::~UIWindowWriter() = default;

    UIWindow* UIWindowWriter::element()
    {
        return static_cast<UIWindow*>(m_ui);
    }
    
    UIWindowWriter::UIWindowWriter(UIWindow* ui) : UIElementsWriter(ui)
    {
    }

        /////////////////////////////////////////////
        // Element Data bits
        /////////////////////////////////////////////

    UIWindowWriter&     UIWindowWriter::size(Size2F v)
    {
        UIWindow*   win = element();
        if(win){
            win -> m_w.spec = v.x;
            win -> m_h.spec = v.y;
        }
        return *this;
    }
    
    UIWindowWriter&     UIWindowWriter::width(float v)
    {
        UIWindow*   win = element();
        if(win){
            win -> m_w.spec = v;
        }
        return *this;
    }
    
    UIWindowWriter&     UIWindowWriter::height(float v)
    {
        UIWindow*   win = element();
        if(win){
            win -> m_h.spec = v;
        }
        return *this;
    }

    UIWindowWriter&     UIWindowWriter::position(Vector2F v)
    {
        UIWindow*   win = element();
        if(win){
            win -> m_x.spec = v.x;
            win -> m_y.spec = v.y;
        }
        return *this;
    }
    
    UIWindowWriter&     UIWindowWriter::x(float v)
    {
        UIWindow*   win = element();
        if(win){
            win -> m_x.spec = v;
        }
        return *this;
    }
    
    UIWindowWriter&     UIWindowWriter::y(float v)
    {
        UIWindow*   win = element();
        if(win){
            win -> m_y.spec = v;
        }
        return *this;
    }
    

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

    UIToolBarWriter     UIWindowWriter::toolbar(Cardinal dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }
    
    UIToolBarWriter     UIWindowWriter::toolbar(const Vector2F& dir, std::string_view kName)
    {
        return make<UIToolBar>(dir, kName);
    }

    UIMenuBarWriter     UIWindowWriter::menubar()
    {
        return make<UIMenuBar>();
    }

}

