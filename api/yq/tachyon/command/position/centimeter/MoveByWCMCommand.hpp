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
    class MoveByʷCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʷCMCommand, PositionCommand)
    public:
        MoveByʷCMCommand(const Header&, Centimeter Δw);
    
        static void init_meta();
        
        Centimeter  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByʷCMCommand(const MoveByʷCMCommand&, const Header&);
        MoveByʷCMCommand(const Header&);
        ~MoveByʷCMCommand();

    private:
        Centimeter  m_Δw = 0.0;
        
        MoveByʷCMCommand(const MoveByʷCMCommand&) = delete;
        MoveByʷCMCommand(MoveByʷCMCommand&&) = delete;
        MoveByʷCMCommand& operator=(const MoveByʷCMCommand&);
        MoveByʷCMCommand& operator=(MoveByʷCMCommand&&);
    };
}
