////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition3I : public TachyonCommand {
        YQ_OBJECT_DECLARE(SetPosition3I, TachyonCommand)
    public:
        SetPosition3I(TachyonID, const Vector3I&, const Param& p={});
        ~SetPosition3I();
    
        const Vector3I&   position3i() const  { return m_position; }
        
        static void init_info();
        
        int     x() const { return m_position.x; }
        int     y() const { return m_position.y; }
        int     z() const { return m_position.z; }
        
    private:
        Vector3I const  m_position;
    };
}
