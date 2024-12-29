////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByᶻ : public TachyonCommand {
        YQ_OBJECT_DECLARE(MoveByᶻ, TachyonCommand)
    public:
        MoveByᶻ(TachyonID, double Δz, const Param& p={});
        ~MoveByᶻ();
    
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
    private:
        double const  m_Δz;
    };
}
