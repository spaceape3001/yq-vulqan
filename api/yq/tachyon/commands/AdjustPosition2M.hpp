////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition2M : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition2M, TachyonCommand)
    public:
        AdjustPosition2M(TachyonID, const Vector2M&, const Param& p={});
        ~AdjustPosition2M();
    
        const Vector2M&   position() const  { return m_position; }
        
        static void init_info();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        
    private:
        Vector2M const  m_position;
    };
}
