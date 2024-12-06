////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition4D : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition4D, TachyonCommand)
    public:
        AdjustPosition4D(TachyonID, const Vector4D&, const Param& p={});
        ~AdjustPosition4D();
    
        const Vector4D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        double  w() const { return m_position.w; }
        
    private:
        Vector4D const  m_position;
    };
}
