////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

/*
    This example will be about combinging ImGUI and the vulkan to have some controls
    as we play around with the camera.
*/

#include <yq/core/DelayInit.hpp>
#include <yq/core/Logging.hpp>
#include <ya/utils/LoggerBox.hpp>
#include <yt/application.hpp>

#include "MainWidget.hpp"

#include <chrono>

using namespace yq;
using namespace yq::tachyon;

//using timepoint_t   = std::chrono::time_point<std::chrono::steady_clock>;


//TachyonID       gLogger;



#if 0
    // "SLAVE" motion from the old file (disabled ATM)
    void        vulkan(ViContext& ctx) override
    {
        
        #if 0
        if(slave_clock){
            timepoint_t n   = std::chrono::steady_clock::now();
            std::chrono::duration<double>  diff    = start - n;
        
            Degree      angle{ diff.count() };
            
            auto ca     = cos((Radian) angle);
            auto sa     = sin((Radian) angle);
            Vector3D    p2{ 10. * ca, 0., 10 * sa };
            
            cam->set_position(p2);
            cam->set_orientation(rotor_y((Radian) -angle));
        }
        #endif

        Scene3DWidget0::vulkan(ctx);
    }
    

#endif

int main(int argc, char* argv[])
{
    AppCreateInfo        aci;
    aci.thread.sim          = true;
    aci.view.title        = "Cameras!";
    aci.view.resizable    = false;
    aci.view.size         = { 1920, 1080 };
    aci.view.clear        = { 0.1f, 0.1f, 0.2f, 1.f };
    aci.view.imgui        = true;
    
    Application app(argc, argv, aci);
    
    //load_plugin_dir("plugin");
    app.start();
    
    MainWidget*     w   = Widget::create<MainWidget>();
    
    //CameraScene* sc  = Tachyon::create<CameraScene>();
    //Widget*     w   = Widget::create<CameraScene3DWidget>(sc);
    //LoggerBox*  lb  = Tachyon::create<LoggerBox>();
    //gLogger         = lb->id();
    //lb->unsafe_snoop(w);
    app.run(w);
    return 0;
}



