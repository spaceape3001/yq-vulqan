////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanMsgDock.hpp"
#include <yq/assetvk/ui/ValidationDebugTableUI.hpp>
#include <yq/tachyon/api/Frame.hpp>
#include <yq/tachyon/api/WidgetMetaWriter.hpp>
#include <yq/tachyon/command/tachyon/SubscribeCommand.hpp>
#include <yq/tachyon/command/tachyon/UnsubscribeCommand.hpp>
#include <yq/tachyon/event/vulqan/VulqanDebugEvent.hpp>
#include <yq/tachyon/vulkan/VulqanManager.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::VulqanMsgDock)

namespace yq::tachyon {
    void    VulqanMsgDock::init_meta()
    {
        auto w = writer<VulqanMsgDock>();
        w.label("Vulqan MSG");
        w.imgui(UI, new ValidationDebugTableUI);
        w.slot(&VulqanMsgDock::on_vulqan_debug_event);
    }

    VulqanMsgDock::VulqanMsgDock()
    {
    }
    
    VulqanMsgDock::~VulqanMsgDock()
    {
    }
    
    void    VulqanMsgDock::on_vulqan_debug_event(const VulqanDebugEvent&evt)
    {
        if(ValidationDebugTableUI* vtab  = dynamic_cast<ValidationDebugTableUI*>(ui_root()))
            vtab -> add(evt.trace());
    }

    Execution VulqanMsgDock::setup(const Context&ctx) 
    {
        const Frame*    frame   = Frame::current();
        if(!frame)
            return WAIT;
            
        if(!m_subscribed){
            TypedID   tid = VulqanManager::manager();
            if(!tid)
                return ABORT;
            if(!frame->contains(ManagerID{tid.id}))
                return WAIT;
            send(new SubscribeCommand({.target=tid}, *this));
            m_subscribed    = true;
        }
        return Widget::setup(ctx);
    }
    
    Execution VulqanMsgDock::teardown(const Context&ctx) 
    {
        if(m_subscribed){
            TypedID   tid = VulqanManager::manager();
            send(new UnsubscribeCommand({.target=tid}, *this));
            m_subscribed    = false;
        }
        return Widget::teardown(ctx);
    }
}
