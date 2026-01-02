////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/widget/WidgetUI.hpp>

namespace yq::tachyon {
    class VulqanDebugEvent;

    class VulqanMsgDock : public WidgetUI {
        YQ_TACHYON_DECLARE(VulqanMsgDock, WidgetUI)
    public:
        VulqanMsgDock();
        ~VulqanMsgDock();
        
        Execution setup(const Context&) override;
        Execution teardown(const Context&) override;
        
        static void    init_meta();
        
    private:
        void    on_vulqan_debug_event(const VulqanDebugEvent&);
    
        bool    m_subscribed    = false;
    };
}
