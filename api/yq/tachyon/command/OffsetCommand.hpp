////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class OffsetCommand : public Command {
        YQ_OBJECT_DECLARE(OffsetCommand, Command)
    public:
        OffsetCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        OffsetCommand(const OffsetCommand&, const Header&);
        virtual ~OffsetCommand();
        
    private:

        OffsetCommand(const OffsetCommand&) = delete;
        OffsetCommand(OffsetCommand&&) = delete;
        OffsetCommand& operator=(const OffsetCommand&) = delete;
        OffsetCommand& operator=(OffsetCommand&&) = delete;
    };
}
