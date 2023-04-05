#include <tachyon/Application.hpp>
#include <tachyon/Viewer.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/ui/Widget2.hpp>

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    Application         app(argc, argv, AppCreateInfo());
    
    ViewerCreateInfo      vci;
    vci.title        = "TextKING!";
    vci.clear        = { 0.0, 0.2, 0.5, 1. };
    vci.resizable    = true;
    vci.imgui        = true;

    Viewer* v       = new Viewer(vci, new Widget2);
    app.run(v);
    return 0;
}
