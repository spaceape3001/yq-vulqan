////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/application.hpp>
#include <yq/tachyon/viewer.hpp>
#include <yq/tachyon/widget.hpp>

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    AppCreateInfo       aci;
    
    aci.view.title      = "Big Empty";
    aci.view.clear        = { 0.0, 0.2, 0.5, 1. };
    aci.view.resizable    = true;
    //aci.view.imgui        = true;
    aci.view.size         = { 1920, 1080 };

    Application         app(argc, argv, aci);
    app.finalize();
    app.run(Widget::create<Widget>());
    return 0;
}
