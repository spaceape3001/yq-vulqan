////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveBy¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveBy¹, SpatialCommand)
    public:
        MoveBy¹(TachyonID, const Vector1D&Δ, const Param& p={});
        ~MoveBy¹();
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        
    private:
        Vector1D const  m_Δ;
    };
}