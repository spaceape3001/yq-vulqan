#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/ui/Widget.hpp>

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    AppCreateInfo       aci;
    
    aci.view.title      = "Big Empty";
    aci.view.clear        = { 0.0, 0.2, 0.5, 1. };
    aci.view.resizable    = true;
    aci.view.imgui        = true;
    aci.view.size         = { 1920, 1080 };

    Application         app(argc, argv, AppCreateInfo());
    app.finalize();
    app.add_viewer(new Widget);
    app.run();
    return 0;
}
