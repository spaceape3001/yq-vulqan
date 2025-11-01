////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByˣCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByˣCommand, PositionCommand)
    public:
        MoveByˣCommand(const Header&, double Δx);
    
        static void init_meta();
        
        double  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByˣCommand(const MoveByˣCommand&, const Header&);
        MoveByˣCommand(const Header&);
        ~MoveByˣCommand();

    private:
        double  m_Δx = 0.0;
        
        MoveByˣCommand(const MoveByˣCommand&) = delete;
        MoveByˣCommand(MoveByˣCommand&&) = delete;
        MoveByˣCommand& operator=(const MoveByˣCommand&);
        MoveByˣCommand& operator=(MoveByˣCommand&&);
    };
}
