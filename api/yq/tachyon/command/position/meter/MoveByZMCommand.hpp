////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByᶻMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByᶻMCommand, PositionCommand)
    public:
        MoveByᶻMCommand(const Header&, Meter Δz);
    
        static void init_meta();
        
        Meter  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MoveByᶻMCommand(const MoveByᶻMCommand&, const Header&);
        MoveByᶻMCommand(const Header&);
        ~MoveByᶻMCommand();
        
    private:
        Meter  m_Δz = 0.0;
        
        MoveByᶻMCommand(const MoveByᶻMCommand&) = delete;
        MoveByᶻMCommand(MoveByᶻMCommand&&) = delete;
        MoveByᶻMCommand& operator=(const MoveByᶻMCommand&) = delete;
        MoveByᶻMCommand& operator=(MoveByᶻMCommand&&) = delete;
    };
}
