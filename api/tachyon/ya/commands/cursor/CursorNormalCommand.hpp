////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/CursorCommand.hpp>

namespace yq::tachyon {
    class CursorNormalCommand : public CursorCommand {
        YQ_OBJECT_DECLARE(CursorNormalCommand, CursorCommand)
    public:
        CursorNormalCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        CursorNormalCommand(const CursorNormalCommand&, const Header&);
        virtual ~CursorNormalCommand();
        
    private:
        CursorNormalCommand(const CursorNormalCommand&) = delete;
        CursorNormalCommand(CursorNormalCommand&&) = delete;
        CursorNormalCommand& operator=(const CursorNormalCommand&) = delete;
        CursorNormalCommand& operator=(CursorNormalCommand&&) = delete;
    };
}
