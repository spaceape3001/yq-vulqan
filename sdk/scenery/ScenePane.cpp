////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ScenePane.hpp"
#include <tachyon/api/WidgetInfoWriter.hpp>

YQ_TACHYON_IMPLEMENT(ScenePane)

ScenePane::ScenePane()
{
}

ScenePane::~ScenePane()
{
}

void ScenePane::init_info()
{
    auto w = writer<ScenePane>();
    w.description("Scene Editor");
}
