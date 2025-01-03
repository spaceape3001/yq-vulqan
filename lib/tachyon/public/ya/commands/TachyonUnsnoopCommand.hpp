////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/MG.hpp>
#include <ya/commands/TachyonCommand.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    class TachyonUnsnoopCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonUnsnoopCommand, TachyonCommand)
    public:
        TachyonUnsnoopCommand(TachyonID, TachyonID, const Param& p = {});
        ~TachyonUnsnoopCommand();

        constexpr TachyonID     listener() const { return m_listener; }
        
        static void init_info();
    private:
        const TachyonID     m_listener;
    };
}
