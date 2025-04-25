////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/MG.hpp>
#include <tachyon/command/TachyonCommand.hpp>
#include <tachyon/api/TypedID.hpp>
#include <tachyon/typedef/thread.hpp>

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
