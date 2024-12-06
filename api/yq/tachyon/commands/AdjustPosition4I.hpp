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
    class AdjustPosition4I : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition4I, TachyonCommand)
    public:
        AdjustPosition4I(TachyonID, const Vector4I&, const Param& p={});
        ~AdjustPosition4I();
    
        const Vector4I&   position() const  { return m_position; }
        
        static void init_info();
        
        int     x() const { return m_position.x; }
        int     y() const { return m_position.y; }
        int     z() const { return m_position.z; }
        int     w() const { return m_position.w; }
        
    private:
        Vector4I const  m_position;
    };
}
