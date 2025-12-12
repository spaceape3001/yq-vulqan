////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class CountCommand : public Command {
        YQ_OBJECT_DECLARE(CountCommand, Command)
    public:
        CountCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        CountCommand(const CountCommand&, const Header&);
        virtual ~CountCommand();
        
    private:

        CountCommand(const CountCommand&) = delete;
        CountCommand(CountCommand&&) = delete;
        CountCommand& operator=(const CountCommand&) = delete;
        CountCommand& operator=(CountCommand&&) = delete;
    };
}
