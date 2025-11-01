////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/MG.hpp>
#include <yq/tachyon/command/TachyonCommand.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/thread.hpp>

namespace yq::tachyon {
    class SubscribeCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(SubscribeCommand, TachyonCommand)
    public:
        SubscribeCommand(const Header&, TypedID, MGF g=MG::General);

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        constexpr TypedID       listener() const { return m_listener; }
        constexpr MGF           groups() const { return m_groups; }
        
        static void init_meta();
    protected:
        SubscribeCommand(const SubscribeCommand&, const Header&);
        ~SubscribeCommand();
    
    private:
        const TypedID       m_listener;
        const MGF           m_groups;
        
        SubscribeCommand(const SubscribeCommand&) = delete;
        SubscribeCommand(SubscribeCommand&&) = delete;
        SubscribeCommand& operator=(const SubscribeCommand&) = delete;
        SubscribeCommand& operator=(SubscribeCommand&&) = delete;
    };
}
