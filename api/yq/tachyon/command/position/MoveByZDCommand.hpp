////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByᶻDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByᶻDCommand, PositionCommand)
    public:
        MoveByᶻDCommand(const Header&, double Δz);
    
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        MoveByᶻDCommand(const MoveByᶻDCommand&, const Header&);
        MoveByᶻDCommand(const Header&);
        ~MoveByᶻDCommand();
        
    private:
        double  m_Δz = 0.0;
        
        MoveByᶻDCommand(const MoveByᶻDCommand&) = delete;
        MoveByᶻDCommand(MoveByᶻDCommand&&) = delete;
        MoveByᶻDCommand& operator=(const MoveByᶻDCommand&) = delete;
        MoveByᶻDCommand& operator=(MoveByᶻDCommand&&) = delete;
    };
}
