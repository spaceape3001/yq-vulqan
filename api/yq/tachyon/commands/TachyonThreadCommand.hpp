////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    class TachyonThreadCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonThreadCommand, TachyonCommand)
    public:
        TachyonThreadCommand(Tachyon*,  ThreadID, const Param& p = {});
        TachyonThreadCommand(TachyonID, ThreadID, const Param& p = {});
        ~TachyonThreadCommand();

        constexpr ThreadID  thread() const { return m_thread; }
        
        static void init_info();
    private:
        const ThreadID  m_thread;
    };
}
