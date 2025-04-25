////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/CursorCommand.hpp>

namespace yq::tachyon {
    class CursorHideCommand : public CursorCommand {
        YQ_OBJECT_DECLARE(CursorHideCommand, CursorCommand)
    public:
        CursorHideCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        CursorHideCommand(const CursorHideCommand&, const Header&);
        virtual ~CursorHideCommand();
        
    private:
        CursorHideCommand(const CursorHideCommand&) = delete;
        CursorHideCommand(CursorHideCommand&&) = delete;
        CursorHideCommand& operator=(const CursorHideCommand&) = delete;
        CursorHideCommand& operator=(CursorHideCommand&&) = delete;
    };
}
