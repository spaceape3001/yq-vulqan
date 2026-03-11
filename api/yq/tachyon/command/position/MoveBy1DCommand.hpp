////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveBy¹DCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy¹DCommand, PositionCommand)
    public:
        MoveBy¹DCommand(const Header&, const Vector1D&Δ);
    
        const Vector1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        double  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MoveBy¹DCommand();
        MoveBy¹DCommand(const MoveBy¹DCommand&, const Header&);
        MoveBy¹DCommand(const Header&);
        
    private:
        Vector1D  m_Δ = ZERO;
        
        MoveBy¹DCommand(const MoveBy¹DCommand&) = delete;
        MoveBy¹DCommand(MoveBy¹DCommand&&) = delete;
        MoveBy¹DCommand& operator=(const MoveBy¹DCommand&) = delete;
        MoveBy¹DCommand& operator=(MoveBy¹DCommand&&) = delete;
    };
}
