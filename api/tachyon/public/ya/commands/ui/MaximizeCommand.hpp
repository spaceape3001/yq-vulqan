////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/UICommand.hpp>

namespace yq::tachyon {
    class MaximizeCommand : public UICommand {
        YQ_OBJECT_DECLARE(MaximizeCommand, UICommand)
    public:
        MaximizeCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        MaximizeCommand(const MaximizeCommand&, const Header&);
        virtual ~MaximizeCommand();
        
    private:

        MaximizeCommand(const MaximizeCommand&) = delete;
        MaximizeCommand(MaximizeCommand&&) = delete;
        MaximizeCommand& operator=(const MaximizeCommand&) = delete;
        MaximizeCommand& operator=(MaximizeCommand&&) = delete;
    };
}
