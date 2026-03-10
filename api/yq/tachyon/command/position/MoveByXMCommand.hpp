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
    class MoveByˣMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByˣMCommand, PositionCommand)
    public:
        MoveByˣMCommand(const Header&, Meter Δx);
    
        static void init_meta();
        
        Meter  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByˣMCommand(const MoveByˣMCommand&, const Header&);
        MoveByˣMCommand(const Header&);
        ~MoveByˣMCommand();

    private:
        Meter  m_Δx = 0.0;
        
        MoveByˣMCommand(const MoveByˣMCommand&) = delete;
        MoveByˣMCommand(MoveByˣMCommand&&) = delete;
        MoveByˣMCommand& operator=(const MoveByˣMCommand&);
        MoveByˣMCommand& operator=(MoveByˣMCommand&&);
    };
}
