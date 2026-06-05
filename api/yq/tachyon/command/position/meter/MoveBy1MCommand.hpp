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
    class MoveBy¹MCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveBy¹MCommand, PositionCommand)
    public:
        MoveBy¹MCommand(const Header&, const Meter1D&Δ);
    
        const Meter1D&   Δ() const  { return m_Δ; }
        
        static void init_meta();
        
        Meter  Δx() const { return m_Δ.x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        ~MoveBy¹MCommand();
        MoveBy¹MCommand(const MoveBy¹MCommand&, const Header&);
        MoveBy¹MCommand(const Header&);
        
    private:
        Meter1D  m_Δ = ZERO;
        
        MoveBy¹MCommand(const MoveBy¹MCommand&) = delete;
        MoveBy¹MCommand(MoveBy¹MCommand&&) = delete;
        MoveBy¹MCommand& operator=(const MoveBy¹MCommand&) = delete;
        MoveBy¹MCommand& operator=(MoveBy¹MCommand&&) = delete;
    };
}
