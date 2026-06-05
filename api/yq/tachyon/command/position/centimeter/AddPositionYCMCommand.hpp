////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʸCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʸCMCommand, PositionCommand)
    public:
        AddPositionʸCMCommand(const Header&, Centimeter Δy);
    
        static void init_meta();
        
        Centimeter  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPositionʸCMCommand(const AddPositionʸCMCommand&, const Header&);
        AddPositionʸCMCommand(const Header&);
        ~AddPositionʸCMCommand();
        
    private:
        Centimeter  m_Δy = 0.0;

        AddPositionʸCMCommand(const AddPositionʸCMCommand&) = delete;
        AddPositionʸCMCommand(AddPositionʸCMCommand&&) = delete;
        AddPositionʸCMCommand& operator=(const AddPositionʸCMCommand&) = delete;
        AddPositionʸCMCommand& operator=(AddPositionʸCMCommand&&) = delete;
    };
}
