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
    class TachyonSubscribeCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonSubscribeCommand, TachyonCommand)
    public:
        TachyonSubscribeCommand(TachyonID, TachyonID, MGF g=MG::General, const Param& p = {});
        ~TachyonSubscribeCommand();

        constexpr TachyonID     listener() const { return m_listener; }
        constexpr MGF           groups() const { return m_groups; }
        
        static void init_info();
    private:
        const TachyonID     m_listener;
        const MGF           m_groups;
    };
}
