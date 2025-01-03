////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/TachyonCommand.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    class TachyonDeleteCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonDeleteCommand, TachyonCommand)
    public:
        TachyonDeleteCommand(Tachyon*,  const Param& p = {});
        TachyonDeleteCommand(TachyonID, const Param& p = {});
        ~TachyonDeleteCommand();

        static void init_info();
    };
}
