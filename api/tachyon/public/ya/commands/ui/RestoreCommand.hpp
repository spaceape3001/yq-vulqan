////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/UICommand.hpp>

namespace yq::tachyon {
    class RestoreCommand : public UICommand {
        YQ_OBJECT_DECLARE(RestoreCommand, UICommand)
    public:
        RestoreCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        RestoreCommand(const RestoreCommand&, const Header&);
        virtual ~RestoreCommand();
        
    private:

        RestoreCommand(const RestoreCommand&) = delete;
        RestoreCommand(RestoreCommand&&) = delete;
        RestoreCommand& operator=(const RestoreCommand&) = delete;
        RestoreCommand& operator=(RestoreCommand&&) = delete;
    };
}
