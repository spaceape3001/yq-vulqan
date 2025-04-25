////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/UICommand.hpp>

namespace yq::tachyon {
    class IconifyCommand : public UICommand {
        YQ_OBJECT_DECLARE(IconifyCommand, UICommand)
    public:
        IconifyCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_info();

    protected:
        IconifyCommand(const IconifyCommand&, const Header&);
        virtual ~IconifyCommand();
        
    private:

        IconifyCommand(const IconifyCommand&) = delete;
        IconifyCommand(IconifyCommand&&) = delete;
        IconifyCommand& operator=(const IconifyCommand&) = delete;
        IconifyCommand& operator=(IconifyCommand&&) = delete;
    };
}
