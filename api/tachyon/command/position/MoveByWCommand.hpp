////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByʷCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʷCommand, PositionCommand)
    public:
        MoveByʷCommand(const Header&, double Δw);
    
        static void init_meta();
        
        double  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByʷCommand(const MoveByʷCommand&, const Header&);
        MoveByʷCommand(const Header&);
        ~MoveByʷCommand();

    private:
        double  m_Δw = 0.0;
        
        MoveByʷCommand(const MoveByʷCommand&) = delete;
        MoveByʷCommand(MoveByʷCommand&&) = delete;
        MoveByʷCommand& operator=(const MoveByʷCommand&);
        MoveByʷCommand& operator=(MoveByʷCommand&&);
    };
}
