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
    class MoveByZMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByZMCommand, PositionCommand)
    public:
        MoveByZMCommand(const Header&, Meter Δz);
    
        static void init_meta();
        
        Meter  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MoveByZMCommand(const MoveByZMCommand&, const Header&);
        MoveByZMCommand(const Header&);
        ~MoveByZMCommand();
        
    private:
        Meter  m_Δz = 0.0;
        
        MoveByZMCommand(const MoveByZMCommand&) = delete;
        MoveByZMCommand(MoveByZMCommand&&) = delete;
        MoveByZMCommand& operator=(const MoveByZMCommand&) = delete;
        MoveByZMCommand& operator=(MoveByZMCommand&&) = delete;
    };
}
