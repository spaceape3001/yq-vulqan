////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViewPanel.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/AxBox2.hxx>

using namespace yq;
using namespace yq::tachyon;

YQ_OBJECT_IMPLEMENT(ViewPanel)

ViewPanel::ViewPanel(UIFlags flags) : UIWindow("##ViewPanel", flags)
{
}

ViewPanel::ViewPanel(const ViewPanel& cp) : UIWindow(cp)
{
}

ViewPanel::~ViewPanel()
{
}

ViewPanel* ViewPanel::clone() const 
{
    return new ViewPanel(*this);
}

void    ViewPanel::render() 
{
    yq::AxBox2F box = parent() -> viewport(CONTENT);
    float   cx   = 0.;
    float   cy   = 0;
    UIWindow*   ctrlp = dynamic_cast<UIWindow*>(element(FIRST, "PalettePanel"));
    if(ctrlp && !ctrlp->invisible())
        cx   = ctrlp->right();
    corners(SET, NEXT, {cx, cy}, box.hh() );
    UIWindow::render();
}

void ViewPanel::init_meta()
{
    auto w = writer<ViewPanel>();
    w.description("The View");
}

