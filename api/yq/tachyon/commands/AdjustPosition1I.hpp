////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AdjustPosition1I : public TachyonCommand {
        YQ_OBJECT_DECLARE(AdjustPosition1I, TachyonCommand)
    public:
        AdjustPosition1I(TachyonID, const Vector1I&, const Param& p={});
        ~AdjustPosition1I();
    
        const Vector1I&   position() const  { return m_position; }
        
        static void init_info();
        
        int     x() const { return m_position.x; }
        
    private:
        Vector1I const  m_position;
    };
}
