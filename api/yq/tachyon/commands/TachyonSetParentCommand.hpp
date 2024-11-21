////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>

namespace yq::tachyon {
    class TachyonSetParentCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonSetParentCommand, TachyonCommand)
    public:
    
        TachyonSetParentCommand(TachyonID, TachyonID parentID, const Param& p = {});
        virtual ~TachyonSetParentCommand();
        
        TachyonID   parent() const { return m_parent; }
        
        static void init_info();
        
    private:
        TachyonID const m_parent;
    };
}
