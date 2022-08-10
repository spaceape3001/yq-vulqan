////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <math/Rectangle2.hpp>
#include <math/Vector2.hpp>
#include <engine/Application.hpp>
#include <engine/vulqan/VqMonitor.hpp>
#include <iostream>

using std::cout;
using namespace yq;
using namespace yq::engine;

int main(int argc, char* argv[])
{
    Application   app(argc, argv);
    app.init_glfw();
    std::vector<VqMonitor>  monitors    = VqMonitor::enumerate();
    VqMonitor               primary     = VqMonitor::primary();
    
    cout << monitors.size() << "Monitors\n";
    size_t      N   = monitors.size();
    for(size_t i=0;i<N; ++i){
        auto v  = monitors[i];
        auto mm     = v.phys_size_mm();
        auto sc     = v.scale();
        auto modes  = v.video_modes_available();
        auto cur    = v.video_mode_current();
        auto rect   = v.work_area();
        
        cout << "Monitor (" << (i+1) << "/" << N << "): " << v.name();
        
        if(v == primary)
            cout << "  PRIMARY!";
        
        cout << '\n'
             << "\tPosition: " << rect.position.x << ", " << rect.position.y << '\n'
             << "\tSize: " << rect.size.x << " x " << rect.size.y << '\n'
             << "\tScale: " << sc.x << " x " << sc.y << '\n'
             << "\tDimensions: " << mm.x << "mm x " << mm.y << "mm\n"
             << "\tVideo Modes:\n" 
         ;
         
         for(auto& vm : modes){
            cout << "\t\t" << vm.size.x << "x" << vm.size.y << " " << vm.refresh_rate << "Hz";
            if(vm == cur)
                cout << " CURRENT";
            cout << '\n'
                << "\t\t[" << vm.bits.red << ", " << vm.bits.green << ", " << vm.bits.blue << "] bpp\n";
         }
                     
    }
    

    return 0;
}
