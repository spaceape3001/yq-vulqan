////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ControllerCommand.hpp>
#include <tachyon/api/TypedID.hpp>

namespace yq::tachyon {
    class UnlistenCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(UnlistenCommand, ControllerCommand)
    public:
    
        UnlistenCommand(const Header&, TypedID);
        
        TypedID    tachyon() const { return m_tachyon; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        UnlistenCommand(const UnlistenCommand&, const Header&);
        virtual ~UnlistenCommand();
        
    private:
        TypedID const  m_tachyon;
        
        UnlistenCommand(const UnlistenCommand&) = delete;
        UnlistenCommand(UnlistenCommand&&) = delete;
        UnlistenCommand& operator=(const UnlistenCommand&) = delete;
        UnlistenCommand& operator=(UnlistenCommand&&) = delete;
    };
}
