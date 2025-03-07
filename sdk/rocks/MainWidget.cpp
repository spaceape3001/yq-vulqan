////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include "MainWidget.hpp"

#include <ya/events/mouse/MousePressEvent.hpp>
#include <yt/ui/WidgetInfoWriter.hpp>

MainWidget::MainWidget()
{
}

MainWidget::~MainWidget()
{
}


void  MainWidget::on_mouse_press_event(const MousePressEvent&evt)
{
    //cmd_close();
}

void  MainWidget::init_info()
{
    auto w = writer<MainWidget>();
    w.slot(&MainWidget::on_mouse_press_event);
}

YQ_TACHYON_IMPLEMENT(MainWidget)
