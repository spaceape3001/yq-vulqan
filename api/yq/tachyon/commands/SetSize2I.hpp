////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class SetSize2I : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetSize2I, TachyonCommand)
    public:
        SetSize2I(TachyonID, const Size2I&, const Param& p={});
        ~SetSize2I();
    
        const Size2I&   size2i() const  { return m_size; }
        
        static void init_info();
        
        int     x() const { return m_size.x; }
        int     y() const { return m_size.y; }
        
    private:
        Size2I const  m_size;
    };
}
