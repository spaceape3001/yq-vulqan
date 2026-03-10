////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionYMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionYMCommand, PositionCommand)
    public:
        AddPositionYMCommand(const Header&, Meter Δy);
    
        static void init_meta();
        
        Meter  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPositionYMCommand(const AddPositionYMCommand&, const Header&);
        AddPositionYMCommand(const Header&);
        ~AddPositionYMCommand();
        
    private:
        Meter  m_Δy = 0.0;

        AddPositionYMCommand(const AddPositionYMCommand&) = delete;
        AddPositionYMCommand(AddPositionYMCommand&&) = delete;
        AddPositionYMCommand& operator=(const AddPositionYMCommand&) = delete;
        AddPositionYMCommand& operator=(AddPositionYMCommand&&) = delete;
    };
}
