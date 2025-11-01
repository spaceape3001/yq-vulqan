////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/ControllerCommand.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class ControlCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ControlCommand, ControllerCommand)
    public:
        ControlCommand(const Header&, TypedID);
        
        static void init_meta();
        
        TypedID     tachyon() const { return m_tachyon; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ControlCommand(const ControlCommand&, const Header&);
        virtual ~ControlCommand();
    
    private:
        TypedID const  m_tachyon;
        
        ControlCommand(const ControlCommand&) = delete;
        ControlCommand(ControlCommand&&) = delete;
        ControlCommand& operator=(const ControlCommand&) = delete;
        ControlCommand& operator=(ControlCommand&&) = delete;
    };
}
