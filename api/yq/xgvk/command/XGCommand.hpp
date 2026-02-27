////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class XGCommand : public Command {
        YQ_OBJECT_DECLARE(XGCommand, Command)
    public:
    
        static void init_meta();

    protected:
        XGCommand(const Header&);
        XGCommand(const XGCommand&, const Header&);
        ~XGCommand();
        
    private:
        XGCommand(const XGCommand&) = delete;
        XGCommand(XGCommand&&) = delete;
        XGCommand& operator=(const XGCommand&) = delete;
        XGCommand& operator=(XGCommand&&) = delete;
    };
}
