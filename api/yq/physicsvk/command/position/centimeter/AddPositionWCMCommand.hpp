////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʷCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʷCMCommand, PositionCommand)
    public:
        AddPositionʷCMCommand(const Header&, Centimeter Δw);
    
        static void init_meta();
        
        Centimeter  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionʷCMCommand(const AddPositionʷCMCommand&, const Header&);
        AddPositionʷCMCommand(const Header&);
        ~AddPositionʷCMCommand();

    private:
        Centimeter  m_Δw = 0.0_m;
        
        AddPositionʷCMCommand(const AddPositionʷCMCommand&) = delete;
        AddPositionʷCMCommand(AddPositionʷCMCommand&&) = delete;
        AddPositionʷCMCommand& operator=(const AddPositionʷCMCommand&);
        AddPositionʷCMCommand& operator=(AddPositionʷCMCommand&&);
    };
}
