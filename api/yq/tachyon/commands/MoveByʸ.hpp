////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByʸ : public TachyonCommand {
        YQ_OBJECT_DECLARE(MoveByʸ, TachyonCommand)
    public:
        MoveByʸ(TachyonID, double Δy, const Param& p={});
        ~MoveByʸ();
    
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
    private:
        double const  m_Δy;
    };
}
