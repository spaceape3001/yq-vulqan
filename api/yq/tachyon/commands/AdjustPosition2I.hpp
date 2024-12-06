////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition2I : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition2I, TachyonCommand)
    public:
        AdjustPosition2I(TachyonID, const Vector2I&, const Param& p={});
        ~AdjustPosition2I();
    
        const Vector2I&   position() const  { return m_position; }
        
        static void init_info();
        
        int     x() const { return m_position.x; }
        int     y() const { return m_position.y; }
        
    private:
        Vector2I const  m_position;
    };
}
