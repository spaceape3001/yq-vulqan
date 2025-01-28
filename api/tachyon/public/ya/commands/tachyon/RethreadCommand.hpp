////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/TachyonCommand.hpp>
#include <yt/typedef/thread.hpp>

namespace yq::tachyon {
    class RethreadCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(RethreadCommand, TachyonCommand)
    public:
        RethreadCommand(const Header&,  ThreadID);

        constexpr ThreadID  thread() const { return m_thread; }
        
        static void init_info();
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
    
        RethreadCommand(const RethreadCommand&, const Header&);
        ~RethreadCommand();

    private:
        const ThreadID  m_thread;

        RethreadCommand(const RethreadCommand&) = delete;
        RethreadCommand(RethreadCommand&&) = delete;
        RethreadCommand& operator=(const RethreadCommand&) = delete;
        RethreadCommand& operator=(RethreadCommand&&) = delete;
    };
}
