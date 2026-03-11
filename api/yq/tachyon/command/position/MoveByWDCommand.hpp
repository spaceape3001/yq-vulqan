////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByʷDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByʷDCommand, PositionCommand)
    public:
        MoveByʷDCommand(const Header&, double Δw);
    
        static void init_meta();
        
        double  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByʷDCommand(const MoveByʷDCommand&, const Header&);
        MoveByʷDCommand(const Header&);
        ~MoveByʷDCommand();

    private:
        double  m_Δw = 0.0;
        
        MoveByʷDCommand(const MoveByʷDCommand&) = delete;
        MoveByʷDCommand(MoveByʷDCommand&&) = delete;
        MoveByʷDCommand& operator=(const MoveByʷDCommand&);
        MoveByʷDCommand& operator=(MoveByʷDCommand&&);
    };
}
