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
    class MoveByˣCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByˣCMCommand, PositionCommand)
    public:
        MoveByˣCMCommand(const Header&, Centimeter Δx);
    
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByˣCMCommand(const MoveByˣCMCommand&, const Header&);
        MoveByˣCMCommand(const Header&);
        ~MoveByˣCMCommand();

    private:
        Centimeter  m_Δx = 0.0;
        
        MoveByˣCMCommand(const MoveByˣCMCommand&) = delete;
        MoveByˣCMCommand(MoveByˣCMCommand&&) = delete;
        MoveByˣCMCommand& operator=(const MoveByˣCMCommand&);
        MoveByˣCMCommand& operator=(MoveByˣCMCommand&&);
    };
}
