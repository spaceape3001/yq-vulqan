////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByᶻCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByᶻCommand, PositionCommand)
    public:
        MoveByᶻCommand(const Header&, double Δz);
    
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MoveByᶻCommand(const MoveByᶻCommand&, const Header&);
        MoveByᶻCommand(const Header&);
        ~MoveByᶻCommand();
        
    private:
        double  m_Δz = 0.0;
        
        MoveByᶻCommand(const MoveByᶻCommand&) = delete;
        MoveByᶻCommand(MoveByᶻCommand&&) = delete;
        MoveByᶻCommand& operator=(const MoveByᶻCommand&) = delete;
        MoveByᶻCommand& operator=(MoveByᶻCommand&&) = delete;
    };
}
