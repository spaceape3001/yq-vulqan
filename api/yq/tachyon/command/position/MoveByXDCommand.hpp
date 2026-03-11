////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount in body coordinates
    class MoveByˣDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(MoveByˣDCommand, PositionCommand)
    public:
        MoveByˣDCommand(const Header&, double Δx);
    
        static void init_meta();
        
        double  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        MoveByˣDCommand(const MoveByˣDCommand&, const Header&);
        MoveByˣDCommand(const Header&);
        ~MoveByˣDCommand();

    private:
        double  m_Δx = 0.0;
        
        MoveByˣDCommand(const MoveByˣDCommand&) = delete;
        MoveByˣDCommand(MoveByˣDCommand&&) = delete;
        MoveByˣDCommand& operator=(const MoveByˣDCommand&);
        MoveByˣDCommand& operator=(MoveByˣDCommand&&);
    };
}
