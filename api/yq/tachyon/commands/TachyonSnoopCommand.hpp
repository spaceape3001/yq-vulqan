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
    class TachyonSnoopCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonSnoopCommand, TachyonCommand)
    public:
        TachyonSnoopCommand(TachyonID, TachyonID, const Param& p = {});
        ~TachyonSnoopCommand();

        constexpr TachyonID     listener() const { return m_listener; }
        
        static void init_info();
    private:
        const TachyonID     m_listener;
    };
}
