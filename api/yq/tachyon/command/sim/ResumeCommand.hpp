////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SimCommand.hpp>

namespace yq::tachyon {
    class ResumeCommand : public SimCommand {
        YQ_OBJECT_DECLARE(ResumeCommand, SimCommand)
    public:
        ResumeCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

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
