////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class ShowCommand : public UICommand {
        YQ_OBJECT_DECLARE(ShowCommand, UICommand)
    public:
        ShowCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();

    protected:
        ShowCommand(const ShowCommand&, const Header&);
        virtual ~ShowCommand();
        
    private:

        ShowCommand(const ShowCommand&) = delete;
        ShowCommand(ShowCommand&&) = delete;
        ShowCommand& operator=(const ShowCommand&) = delete;
        ShowCommand& operator=(ShowCommand&&) = delete;
    };
}
