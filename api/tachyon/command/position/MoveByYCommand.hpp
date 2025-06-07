////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByʸCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʸCommand, PositionCommand)
    public:
        MoveByʸCommand(const Header&, double Δy);
    
        static void init_info();
        
        double  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveByʸCommand(const MoveByʸCommand&, const Header&);
        MoveByʸCommand(const Header&);
        ~MoveByʸCommand();
        
    private:
        double  m_Δy = 0.0;

        MoveByʸCommand(const MoveByʸCommand&) = delete;
        MoveByʸCommand(MoveByʸCommand&&) = delete;
        MoveByʸCommand& operator=(const MoveByʸCommand&) = delete;
        MoveByʸCommand& operator=(MoveByʸCommand&&) = delete;
    };
}
