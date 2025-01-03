////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/WidgetCommand.hpp>

namespace yq::tachyon {
    class Widget;
    
    class WidgetStartupCommand : public WidgetCommand {
        YQ_OBJECT_DECLARE(WidgetStartupCommand, WidgetCommand)
    public:
    
        WidgetStartupCommand(Widget*, const Param& p = {});
        WidgetStartupCommand(WidgetID, const Param& p = {});
        virtual ~WidgetStartupCommand();
        
        static void init_info();
    };
}
