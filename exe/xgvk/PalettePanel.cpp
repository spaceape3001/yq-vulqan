////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PalettePanel.hpp"
#include <yq/tachyon/ui/UIElementMetaWriter.hpp>
#include <yq/shape/AxBox2.hpp>
#include <yq/shape/AxBox2.hxx>

using namespace yq;
using namespace yq::tachyon;

YQ_OBJECT_IMPLEMENT(PalettePanel)

PalettePanel::PalettePanel(UIFlags flags) : UIWindow("##XGPalette", flags)
{
}

PalettePanel::PalettePanel(const PalettePanel& cp) : UIWindow(cp)
{
}

PalettePanel::~PalettePanel()
{
}

PalettePanel* PalettePanel::clone() const 
{
    return new PalettePanel(*this);
}

void    PalettePanel::render() 
{
    AxBox2F box = parent() -> viewport(CONTENT);
    position(SET, NEXT, box.ll());
    height(SET, NEXT, box.height());
    m_w.minimum     = m_min * box.width();
    m_w.maximum     = m_max * box.width();
    UIWindow::render();
}

void PalettePanel::init_meta()
{
    auto w = writer<PalettePanel>();
    w.description("The Palette");
}

