////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/application.hpp>
#include "SceneryMW.hpp"
#include <iostream>

////////////////////////////////////////////////////////////////////////////////
int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.sim          = true;
    aci.view.title        = "Scenery Editor";
    aci.view.size         = { 1920, 1080 };
    aci.view.clear        = { 0.1f, 0.1f, 0.2f, 1.f };
    aci.view.imgui        = true;
    aci.view.resizable    = true;
    
    Application app(argc, argv, aci);
    app.start();
    
    SceneryMW*     w   = Widget::create<SceneryMW>();
    app.run(w);
    return 0;
}
