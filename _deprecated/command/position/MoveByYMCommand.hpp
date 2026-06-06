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
    class MoveByʸMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʸMCommand, PositionCommand)
    public:
        MoveByʸMCommand(const Header&, Meter Δy);
    
        static void init_meta();
        
        Meter  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveByʸMCommand(const MoveByʸMCommand&, const Header&);
        MoveByʸMCommand(const Header&);
        ~MoveByʸMCommand();
        
    private:
        Meter  m_Δy = 0.0;

        MoveByʸMCommand(const MoveByʸMCommand&) = delete;
        MoveByʸMCommand(MoveByʸMCommand&&) = delete;
        MoveByʸMCommand& operator=(const MoveByʸMCommand&) = delete;
        MoveByʸMCommand& operator=(MoveByʸMCommand&&) = delete;
    };
}
