////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/shape/Size2.hpp>

namespace yq::tachyon {
    class SetSize2 : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetSize2, TachyonCommand)
    public:
        SetSize2(TachyonID, const Size2D&, const Param& p={});
        ~SetSize2();
    
        const Size2D&   size() const  { return m_size; }
        
        static void init_info();
        
        double  x() const { return m_size.x; }
        double  y() const { return m_size.y; }
        
    private:
        Size2D const  m_size;
    };
}
