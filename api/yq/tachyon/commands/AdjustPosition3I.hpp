////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition3I : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition3I, TachyonCommand)
    public:
        AdjustPosition3I(TachyonID, const Vector3I&, const Param& p={});
        ~AdjustPosition3I();
    
        const Vector3I&   position() const  { return m_position; }
        
        static void init_info();
        
        int     x() const { return m_position.x; }
        int     y() const { return m_position.y; }
        int     z() const { return m_position.z; }
        
    private:
        Vector3I const  m_position;
    };
}
