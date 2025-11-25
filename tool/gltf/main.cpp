////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLTFWin.hpp"

#include <yq/process/PluginLoader.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/api/Tachyon.hxx>

using namespace yq;
using namespace yq::tachyon;


int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    
    aci.thread.auxillary    = true;
    aci.thread.sim          = true;
    aci.view.clear          = { 0.005f, 0.005f, 0.005f, 1.f };
    aci.view.imgui          = true;
    aci.view.resizable      = true;
    aci.view.size           = { 1920, 1080 };
    aci.view.title          = "GLTF!";
    
    Application app(argc, argv, aci);
    Meta::init();

    app.start();
    GLTFWin*    w   = Tachyon::create<GLTFWin>();
    if(argc>1)
        w -> open(argv[1]);
    app.run(w);
    return 0;
}

