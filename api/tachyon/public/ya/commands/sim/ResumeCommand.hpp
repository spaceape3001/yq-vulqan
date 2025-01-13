////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SimCommand.hpp>

namespace yq::tachyon {
    class ResumeCommand : public SimCommand {
        YQ_OBJECT_DECLARE(ResumeCommand, SimCommand)
    public:
        ResumeCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        ResumeCommand(const ResumeCommand&, const Header&);
        virtual ~ResumeCommand();
        
    private:

        ResumeCommand(const ResumeCommand&) = delete;
        ResumeCommand(ResumeCommand&&) = delete;
        ResumeCommand& operator=(const ResumeCommand&) = delete;
        ResumeCommand& operator=(ResumeCommand&&) = delete;
    };
}
