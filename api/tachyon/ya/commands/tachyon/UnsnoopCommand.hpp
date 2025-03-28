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
    class UnsnoopCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(UnsnoopCommand, TachyonCommand)
    public:
        UnsnoopCommand(const Header&, TypedID);

        constexpr TypedID     listener() const { return m_listener; }
        
        static void init_info();
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        UnsnoopCommand(const UnsnoopCommand&, const Header&);
        ~UnsnoopCommand();
        
    private:
        const TypedID     m_listener;
        
        UnsnoopCommand(const UnsnoopCommand&) = delete;
        UnsnoopCommand(UnsnoopCommand&&) = delete;
        UnsnoopCommand& operator=(const UnsnoopCommand&) = delete;
        UnsnoopCommand& operator=(UnsnoopCommand&&) = delete;
    };
}
