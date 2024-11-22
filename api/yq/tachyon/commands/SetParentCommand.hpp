////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/api/TachyonBind.hpp>

namespace yq::tachyon {
    class SetParentCommand : public Command, public TachyonBind {
        YQ_OBJECT_DECLARE(SetParentCommand, Command)
    public:
    
        SetParentCommand(TachyonID, TachyonID parentID, const Param& p = {});
        virtual ~SetParentCommand();
        
        TachyonID   parent() const { return m_parent; }
        
        static void init_info();
        
    private:
        TachyonID const m_parent;
    };
}
