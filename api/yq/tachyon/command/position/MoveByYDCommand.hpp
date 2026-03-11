////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByʸDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʸDCommand, PositionCommand)
    public:
        MoveByʸDCommand(const Header&, double Δy);
    
        static void init_meta();
        
        double  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MoveByʸDCommand(const MoveByʸDCommand&, const Header&);
        MoveByʸDCommand(const Header&);
        ~MoveByʸDCommand();
        
    private:
        double  m_Δy = 0.0;

        MoveByʸDCommand(const MoveByʸDCommand&) = delete;
        MoveByʸDCommand(MoveByʸDCommand&&) = delete;
        MoveByʸDCommand& operator=(const MoveByʸDCommand&) = delete;
        MoveByʸDCommand& operator=(MoveByʸDCommand&&) = delete;
    };
}
