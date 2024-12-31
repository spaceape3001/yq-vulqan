////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveBy1 : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveBy1, SpatialCommand)
    public:
        MoveBy1(TachyonID, const Vector1D&Δ, const Param& p={});
        ~MoveBy1();
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        
    private:
        Vector1D const  m_Δ;
    };
}
