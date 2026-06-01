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
    class MoveByᶻCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByᶻCMCommand, PositionCommand)
    public:
        MoveByᶻCMCommand(const Header&, Centimeter Δz);
    
        static void init_meta();
        
        Centimeter  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MoveByᶻCMCommand(const MoveByᶻCMCommand&, const Header&);
        MoveByᶻCMCommand(const Header&);
        ~MoveByᶻCMCommand();
        
    private:
        Centimeter  m_Δz = 0.0;
        
        MoveByᶻCMCommand(const MoveByᶻCMCommand&) = delete;
        MoveByᶻCMCommand(MoveByᶻCMCommand&&) = delete;
        MoveByᶻCMCommand& operator=(const MoveByᶻCMCommand&) = delete;
        MoveByᶻCMCommand& operator=(MoveByᶻCMCommand&&) = delete;
    };
}
