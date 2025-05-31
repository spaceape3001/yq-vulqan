////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "UIControlPanel.hpp"
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/AxBox2.hxx>

using namespace yq;
using namespace yq::tachyon;

void UIControlPanel::init_info()
{
    auto w = writer<UIControlPanel>();
    w.description("Scene Editor's Control Panel");
}

UIControlPanel::UIControlPanel(UIFlags flags) : UIWindow("Control Panel", flags)
{
}

UIControlPanel::UIControlPanel(const UIControlPanel& cp) : UIWindow(cp)
{
}

UIControlPanel*   UIControlPanel::clone() const 
{
    return new UIControlPanel(*this);
}

void    UIControlPanel::render() 
{
    AxBox2F box = parent() -> viewport(CONTENT);
    position(SET, NEXT, box.ll());
    height(SET, NEXT, box.height());
    m_w.minimum     = m_min * box.width();
    m_w.maximum     = m_max * box.width();
    UIWindow::render();
}

YQ_OBJECT_IMPLEMENT(UIControlPanel)
