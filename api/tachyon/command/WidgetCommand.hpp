////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Command.hpp>

namespace yq::tachyon {
    class WidgetCommand : public Command {
        YQ_OBJECT_DECLARE(WidgetCommand, Command)
    public:
    
        WidgetCommand(const Header&);
        
        static void init_info();
        
    protected:
        WidgetCommand(const WidgetCommand&, const Header&);
        virtual ~WidgetCommand();

    private:
        WidgetCommand(const WidgetCommand&) = delete;
        WidgetCommand(WidgetCommand&&) = delete;
        WidgetCommand& operator=(const WidgetCommand&) = delete;
        WidgetCommand& operator=(WidgetCommand&&) = delete;
    };
}
