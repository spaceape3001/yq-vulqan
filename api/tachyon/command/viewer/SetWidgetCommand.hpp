////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ViewerCommand.hpp>
#include <tachyon/typedef/widget.hpp>

namespace yq::tachyon {
    class SetWidgetCommand : public ViewerCommand {
        YQ_OBJECT_DECLARE(SetWidgetCommand, ViewerCommand)
    public:
    
        /*
            Since this is transferring an actual object, don't think we need to go widget IDs
        */
    
        SetWidgetCommand(const Header&, WidgetPtr);
        
        static void init_info();
        
        const WidgetPtr&    widget() const { return m_widget; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
    
        SetWidgetCommand(const SetWidgetCommand&, const Header&);
        virtual ~SetWidgetCommand();

    private:
        WidgetPtr   m_widget;
        
        SetWidgetCommand(const SetWidgetCommand&) = delete;
        SetWidgetCommand(SetWidgetCommand&&) = delete;
        SetWidgetCommand& operator=(const SetWidgetCommand&) = delete;
        SetWidgetCommand& operator=(SetWidgetCommand&&) = delete;
    };
}
