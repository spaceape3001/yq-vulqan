////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ControlPanelUI.hpp"
#include <tachyon/ui/UIElementInfoWriter.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/AxBox2.hxx>

using namespace yq;
using namespace yq::tachyon;

void ControlPanelUI::init_info()
{
    auto w = writer<ControlPanelUI>();
    w.description("Scene Editor's Control Panel");
}

ControlPanelUI::ControlPanelUI(UIFlags flags) : UIWindow("Control Panel", flags)
{
}

ControlPanelUI::ControlPanelUI(const ControlPanelUI& cp) : UIWindow(cp)
{
}

ControlPanelUI*   ControlPanelUI::clone() const 
{
    return new ControlPanelUI(*this);
}

void    ControlPanelUI::render() 
{
    AxBox2F box = parent() -> viewport(CONTENT);
    position(SET, NEXT, box.ll());
    height(SET, NEXT, box.height());
    m_w.minimum     = m_min * box.width();
    m_w.maximum     = m_max * box.width();
    UIWindow::render();
}

YQ_OBJECT_IMPLEMENT(ControlPanelUI)
