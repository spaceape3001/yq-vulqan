////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL -- ROCKS
//
////////////////////////////////////////////////////////////////////////////////

#include "RockApp.hpp"
#include <yt/os/Desktop.hpp>
#include <yt/os/Monitor.hpp>
#include <yt/logging.hpp>
#include "MainWidget.hpp"

RockApp* RockApp::s_app = nullptr;

RockApp::RockApp(int argc, char**argv, const AppCreateInfo& aci) : Application(argc, argv, aci)
{
    s_app   = this;
}

RockApp::~RockApp()
{
    s_app   = nullptr;
}

void    RockApp::configure_vulqan() 
{
    for(const Monitor* m : desktop()->monitors()){
        XWin    xw;
        xw.monitor      = m->id();
        xw.pixels       = m->size();
        xw.position     = m->position();
        xw.scale        = m->scale();
        xw.dimensions   = m->dimensions();
        
        m_windows.push_back(xw);
    }
    std::stable_sort(m_windows.begin(), m_windows.end(), [](const XWin& a, const XWin& b) -> bool {
        return a.position.x < b.position.x;
    });
yInfo() << "RockApp configuring vulkan (detected " << m_windows.size() << " monitors)";
    m_cInfo.vulkan.graphics     = (unsigned int) m_windows.size();
}


bool RockApp::start()
{
    if(m_startStarted)
        return true;
    m_startStarted  = true;
    
    if(!Application::start())
        return false;
    
    static const RGBA4F kColors[] = {
        { 0.02f, 0.00f, 0.00f, 1.f },
        { 0.01f, 0.01f, 0.00f, 1.f },
        { 0.00f, 0.02f, 0.00f, 1.f },
        { 0.00f, 0.01f, 0.01f, 1.f },
        { 0.00f, 0.00f, 0.02f, 1.f },
        { 0.01f, 0.00f, 0.01f, 1.f }
    };
    static constexpr size_t nColors = sizeof(kColors)/sizeof(kColors[0]);
    
    //  Eventually sort the windows
    
    ViewerCreateInfo        vci;
    vci.title           = "Rocks";
    vci.resizable       = false;
    //vci.floating        = true;
    //vci.decorated       = false;
    size_t                  counter = 0;
    
    std::vector<WidgetPtr>  widgets;

    yInfo() << "RockApp should have " << m_windows.size() << " windows";
    
    vci.size        = { 1920, 1080 };
    //vci.clear       = { 0.001f, 0.001f, 0.001f, 1.f};
    
    for(XWin& xw : m_windows){
yInfo() << "Monitor> " << xw.pixels.x << "*" << xw.pixels.y << " " << xw.position.x << "," << xw.position.y;

        vci.monitor     = xw.monitor;
        vci.position        = iround(xw.position);
        vci.wmode           = WindowMode::Windowed;
        //vci.size            = iround(xw.pixels*0.75);
        vci.clear           = kColors[(counter++) % nColors];
        
        WidgetPtr   w   = Tachyon::create<MainWidget>();
        widgets.push_back(w);
        xw.widget   = w->id();
        xw.viewer   = create(VIEWER, vci, w);
        tick(); tick();
    }
    
    
    return true;
}
