////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/ControllerCommand.hpp>
#include <tachyon/typedef/tachyon.hpp>
#include <yt/api/TypedID.hpp>

namespace yq::tachyon {
    class ListenCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ListenCommand, ControllerCommand)
    public:

        ListenCommand(const Header&, TypedID);
        
        TypedID    tachyon() const { return m_tachyon; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        ListenCommand(const ListenCommand&, const Header&);
        virtual ~ListenCommand();
        
    private:
        TypedID const  m_tachyon;
        
        ListenCommand(const ListenCommand&) = delete;
        ListenCommand(ListenCommand&&) = delete;
        ListenCommand& operator=(const ListenCommand&) = delete;
        ListenCommand& operator=(ListenCommand&&) = delete;
    };
}
