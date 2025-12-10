////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class ScaleCommand : public Command {
        YQ_OBJECT_DECLARE(ScaleCommand, Command)
    public:
        ScaleCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        ScaleCommand(const ScaleCommand&, const Header&);
        virtual ~ScaleCommand();
        
    private:

        ScaleCommand(const ScaleCommand&) = delete;
        ScaleCommand(ScaleCommand&&) = delete;
        ScaleCommand& operator=(const ScaleCommand&) = delete;
        ScaleCommand& operator=(ScaleCommand&&) = delete;
    };
}
