////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/MG.hpp>
#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    class TachyonUnsubscribeCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonUnsubscribeCommand, TachyonCommand)
    public:
        TachyonUnsubscribeCommand(TachyonID, TachyonID, MGF g=ALL, const Param& p = {});
        ~TachyonUnsubscribeCommand();

        constexpr TachyonID     listener() const { return m_listener; }
        constexpr MGF           groups() const { return m_groups; }
        
        static void init_info();
    private:
        const TachyonID     m_listener;
        const MGF           m_groups;
    };
}
