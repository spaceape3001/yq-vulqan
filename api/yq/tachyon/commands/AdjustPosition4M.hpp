////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector4.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition4M : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition4M, TachyonCommand)
    public:
        AdjustPosition4M(TachyonID, const Vector4M&, const Param& p={});
        ~AdjustPosition4M();
    
        const Vector4M&   position() const  { return m_position; }
        
        static void init_info();
        
        Meter  x() const { return m_position.x; }
        Meter  y() const { return m_position.y; }
        Meter  z() const { return m_position.z; }
        Meter  w() const { return m_position.w; }
        
    private:
        Vector4M const  m_position;
    };
}
