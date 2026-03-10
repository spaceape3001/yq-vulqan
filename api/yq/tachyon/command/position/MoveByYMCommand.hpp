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
    class MoveByYMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByYMCommand, PositionCommand)
    public:
        MoveByYMCommand(const Header&, Meter Δy);
    
        static void init_meta();
        
        Meter  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveByYMCommand(const MoveByYMCommand&, const Header&);
        MoveByYMCommand(const Header&);
        ~MoveByYMCommand();
        
    private:
        Meter  m_Δy = 0.0;

        MoveByYMCommand(const MoveByYMCommand&) = delete;
        MoveByYMCommand(MoveByYMCommand&&) = delete;
        MoveByYMCommand& operator=(const MoveByYMCommand&) = delete;
        MoveByYMCommand& operator=(MoveByYMCommand&&) = delete;
    };
}
