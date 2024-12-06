////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector4.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition4I : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition4I, TachyonCommand)
    public:
        SetPosition4I(TachyonID, const Vector4I&, const Param& p={});
        ~SetPosition4I();
    
        const Vector4I&   position4i() const  { return m_position; }
        
        static void init_info();
        
        int     x() const { return m_position.x; }
        int     y() const { return m_position.y; }
        int     z() const { return m_position.z; }
        int     w() const { return m_position.w; }
        
    private:
        Vector4I const  m_position;
    };
}
