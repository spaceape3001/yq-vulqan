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
    class MoveByʷMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʷMCommand, PositionCommand)
    public:
        MoveByʷMCommand(const Header&, Meter Δw);
    
        static void init_meta();
        
        Meter  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByʷMCommand(const MoveByʷMCommand&, const Header&);
        MoveByʷMCommand(const Header&);
        ~MoveByʷMCommand();

    private:
        Meter  m_Δw = 0.0;
        
        MoveByʷMCommand(const MoveByʷMCommand&) = delete;
        MoveByʷMCommand(MoveByʷMCommand&&) = delete;
        MoveByʷMCommand& operator=(const MoveByʷMCommand&);
        MoveByʷMCommand& operator=(MoveByʷMCommand&&);
    };
}
