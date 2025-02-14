////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/CursorCommand.hpp>

namespace yq::tachyon {
    class CursorCaptureCommand : public CursorCommand {
        YQ_OBJECT_DECLARE(CursorCaptureCommand, CursorCommand)
    public:
        CursorCaptureCommand(const Header&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        static void init_info();
        
    protected:
        CursorCaptureCommand(const CursorCaptureCommand&, const Header&);
        virtual ~CursorCaptureCommand();
        
    private:
        CursorCaptureCommand(const CursorCaptureCommand&) = delete;
        CursorCaptureCommand(CursorCaptureCommand&&) = delete;
        CursorCaptureCommand& operator=(const CursorCaptureCommand&) = delete;
        CursorCaptureCommand& operator=(CursorCaptureCommand&&) = delete;
    };
}
