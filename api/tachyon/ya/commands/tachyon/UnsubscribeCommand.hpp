////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/msg/MG.hpp>
#include <ya/commands/TachyonCommand.hpp>
#include <yt/api/TypedID.hpp>
#include <tachyon/typedef/thread.hpp>

namespace yq::tachyon {
    class UnsubscribeCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(UnsubscribeCommand, TachyonCommand)
    public:
        UnsubscribeCommand(const Header&, TypedID, MGF g=ALL);

        constexpr TypedID      listener() const { return m_listener; }
        constexpr MGF           groups() const { return m_groups; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();
    protected:
        UnsubscribeCommand(const UnsubscribeCommand&, const Header&);
        ~UnsubscribeCommand();

    private:
        const TypedID       m_listener;
        const MGF           m_groups;
        
        UnsubscribeCommand(const UnsubscribeCommand&) = delete;
        UnsubscribeCommand(UnsubscribeCommand&&) = delete;
        UnsubscribeCommand& operator=(const UnsubscribeCommand&) = delete;
        UnsubscribeCommand& operator=(UnsubscribeCommand&&) = delete;
    };
}
