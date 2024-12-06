////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition4M : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition4M, TachyonCommand)
    public:
        SetPosition4M(TachyonID, const Vector4M&, const Param& p={});
        ~SetPosition4M();
    
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
