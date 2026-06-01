////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʸMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʸMCommand, PositionCommand)
    public:
        AddPositionʸMCommand(const Header&, Meter Δy);
    
        static void init_meta();
        
        Meter  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPositionʸMCommand(const AddPositionʸMCommand&, const Header&);
        AddPositionʸMCommand(const Header&);
        ~AddPositionʸMCommand();
        
    private:
        Meter  m_Δy = 0.0;

        AddPositionʸMCommand(const AddPositionʸMCommand&) = delete;
        AddPositionʸMCommand(AddPositionʸMCommand&&) = delete;
        AddPositionʸMCommand& operator=(const AddPositionʸMCommand&) = delete;
        AddPositionʸMCommand& operator=(AddPositionʸMCommand&&) = delete;
    };
}
