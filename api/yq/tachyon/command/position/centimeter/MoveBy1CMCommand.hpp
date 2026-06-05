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
    class MoveBy¹CMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy¹CMCommand, PositionCommand)
    public:
        MoveBy¹CMCommand(const Header&, const Centimeter1D&Δ);
    
        const Centimeter1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MoveBy¹CMCommand();
        MoveBy¹CMCommand(const MoveBy¹CMCommand&, const Header&);
        MoveBy¹CMCommand(const Header&);
        
    private:
        Centimeter1D  m_Δ = ZERO;
        
        MoveBy¹CMCommand(const MoveBy¹CMCommand&) = delete;
        MoveBy¹CMCommand(MoveBy¹CMCommand&&) = delete;
        MoveBy¹CMCommand& operator=(const MoveBy¹CMCommand&) = delete;
        MoveBy¹CMCommand& operator=(MoveBy¹CMCommand&&) = delete;
    };
}
