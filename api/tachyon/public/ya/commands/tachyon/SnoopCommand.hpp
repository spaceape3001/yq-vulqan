////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/MG.hpp>
#include <ya/commands/TachyonCommand.hpp>
#include <yt/api/TypedID.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    class SnoopCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SnoopCommand, TachyonCommand)
    public:
        SnoopCommand(const Header&, TypedID);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        constexpr TypedID     listener() const { return m_listener; }
        
        static void init_info();
    
    protected:
        SnoopCommand(const SnoopCommand&, const Header&);
        ~SnoopCommand();
    
    private:
        const TypedID     m_listener;
        
        SnoopCommand(const SnoopCommand&) = delete;
        SnoopCommand(SnoopCommand&&) = delete;
        SnoopCommand& operator=(const SnoopCommand&) = delete;
        SnoopCommand& operator=(SnoopCommand&&) = delete;
    };
}
