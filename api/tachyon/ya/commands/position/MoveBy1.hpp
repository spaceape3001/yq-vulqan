////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy¹ : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy¹, PositionCommand)
    public:
        MoveBy¹(const Header&, const Vector1D&Δ);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MoveBy¹();
        MoveBy¹(const MoveBy¹&, const Header&);
        MoveBy¹(const Header&);
        
    private:
        Vector1D  m_Δ = ZERO;
        
        MoveBy¹(const MoveBy¹&) = delete;
        MoveBy¹(MoveBy¹&&) = delete;
        MoveBy¹& operator=(const MoveBy¹&) = delete;
        MoveBy¹& operator=(MoveBy¹&&) = delete;
    };
}
