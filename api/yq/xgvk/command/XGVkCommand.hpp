////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class XGVkCommand : public Command {
        YQ_OBJECT_DECLARE(XGVkCommand, Command)
    public:
    
        static void init_meta();

    protected:
        XGVkCommand(const Header&);
        XGVkCommand(const XGVkCommand&, const Header&);
        ~XGVkCommand();
        
    private:
        XGVkCommand(const XGVkCommand&) = delete;
        XGVkCommand(XGVkCommand&&) = delete;
        XGVkCommand& operator=(const XGVkCommand&) = delete;
        XGVkCommand& operator=(XGVkCommand&&) = delete;
    };
}
