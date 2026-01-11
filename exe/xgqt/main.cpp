////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/Tachyon.hxx>
#include <yq/vkqt/app/YApp.hpp>
#include "MainWindow.hpp"

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    AppCreateInfo   aci;
    YApp            app(argc, argv, aci);
    
    app.start();
    
    Ref<MainWindow> mw  = Tachyon::create<MainWindow>();
    mw->show();
    app.run();
    return 0;
}
