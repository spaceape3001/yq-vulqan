////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/CursorCommand.hpp>

namespace yq::tachyon {
    class CursorDisableCommand : public CursorCommand {
        YQ_OBJECT_DECLARE(CursorDisableCommand, CursorCommand)
    public:
        CursorDisableCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        CursorDisableCommand(const CursorDisableCommand&, const Header&);
        virtual ~CursorDisableCommand();
        
    private:
        CursorDisableCommand(const CursorDisableCommand&) = delete;
        CursorDisableCommand(CursorDisableCommand&&) = delete;
        CursorDisableCommand& operator=(const CursorDisableCommand&) = delete;
        CursorDisableCommand& operator=(CursorDisableCommand&&) = delete;
    };
}
