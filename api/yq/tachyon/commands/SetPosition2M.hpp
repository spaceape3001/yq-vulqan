////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition2M : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition2M, TachyonCommand)
    public:
        SetPosition2M(TachyonID, const Vector2M&, const Param& p={});
        ~SetPosition2M();
    
        const Vector2M&   position() const  { return m_position; }
        
        static void init_info();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        
    private:
        Vector2M const  m_position;
    };
}
