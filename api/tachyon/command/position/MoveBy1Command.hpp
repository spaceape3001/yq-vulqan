////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy¹Command : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy¹Command, PositionCommand)
    public:
        MoveBy¹Command(const Header&, const Vector1D&Δ);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MoveBy¹Command();
        MoveBy¹Command(const MoveBy¹Command&, const Header&);
        MoveBy¹Command(const Header&);
        
    private:
        Vector1D  m_Δ = ZERO;
        
        MoveBy¹Command(const MoveBy¹Command&) = delete;
        MoveBy¹Command(MoveBy¹Command&&) = delete;
        MoveBy¹Command& operator=(const MoveBy¹Command&) = delete;
        MoveBy¹Command& operator=(MoveBy¹Command&&) = delete;
    };
}
