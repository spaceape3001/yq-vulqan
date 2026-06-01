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
    class MoveByʸCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʸCMCommand, PositionCommand)
    public:
        MoveByʸCMCommand(const Header&, Centimeter Δy);
    
        static void init_meta();
        
        Centimeter  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveByʸCMCommand(const MoveByʸCMCommand&, const Header&);
        MoveByʸCMCommand(const Header&);
        ~MoveByʸCMCommand();
        
    private:
        Centimeter  m_Δy = 0.0;

        MoveByʸCMCommand(const MoveByʸCMCommand&) = delete;
        MoveByʸCMCommand(MoveByʸCMCommand&&) = delete;
        MoveByʸCMCommand& operator=(const MoveByʸCMCommand&) = delete;
        MoveByʸCMCommand& operator=(MoveByʸCMCommand&&) = delete;
    };
}
