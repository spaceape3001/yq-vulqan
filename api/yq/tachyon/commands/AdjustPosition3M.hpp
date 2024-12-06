////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector3.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition3M : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition3M, TachyonCommand)
    public:
        AdjustPosition3M(TachyonID, const Vector3M&, const Param& p={});
        ~AdjustPosition3M();
    
        const Vector3M&   position() const  { return m_position; }
        
        static void init_info();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }
        
    private:
        Vector3M const  m_position;
    };
}
