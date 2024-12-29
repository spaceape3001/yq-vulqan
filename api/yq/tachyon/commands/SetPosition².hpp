////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition² : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition², TachyonCommand)
    public:
        SetPosition²(TachyonID, const Vector2D&, const Param& p={});
        ~SetPosition²();
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        
    private:
        Vector2D const  m_position;
    };
}
