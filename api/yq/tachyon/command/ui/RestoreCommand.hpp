////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class RestoreCommand : public UICommand {
        YQ_OBJECT_DECLARE(RestoreCommand, UICommand)
    public:
        RestoreCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

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
