////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class FloatCommand : public UICommand {
        YQ_OBJECT_DECLARE(FloatCommand, UICommand)
    public:
        FloatCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        FloatCommand(const FloatCommand&, const Header&);
        virtual ~FloatCommand();
        
    private:

        FloatCommand(const FloatCommand&) = delete;
        FloatCommand(FloatCommand&&) = delete;
        FloatCommand& operator=(const FloatCommand&) = delete;
        FloatCommand& operator=(FloatCommand&&) = delete;
    };
}
