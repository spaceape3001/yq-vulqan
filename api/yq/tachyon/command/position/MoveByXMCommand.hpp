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
    class MoveByXMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByXMCommand, PositionCommand)
    public:
        MoveByXMCommand(const Header&, Meter Δx);
    
        static void init_meta();
        
        Meter  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByXMCommand(const MoveByXMCommand&, const Header&);
        MoveByXMCommand(const Header&);
        ~MoveByXMCommand();

    private:
        Meter  m_Δx = 0.0;
        
        MoveByXMCommand(const MoveByXMCommand&) = delete;
        MoveByXMCommand(MoveByXMCommand&&) = delete;
        MoveByXMCommand& operator=(const MoveByXMCommand&);
        MoveByXMCommand& operator=(MoveByXMCommand&&);
    };
}
