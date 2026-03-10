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
    class AddPositionZMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionZMCommand, PositionCommand)
    public:
        AddPositionZMCommand(const Header&, Meter Δz);
    
        static void init_meta();
        
        Meter  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddPositionZMCommand(const AddPositionZMCommand&, const Header&);
        AddPositionZMCommand(const Header&);
        ~AddPositionZMCommand();
        
    private:
        Meter  m_Δz = 0.0;
        
        AddPositionZMCommand(const AddPositionZMCommand&) = delete;
        AddPositionZMCommand(AddPositionZMCommand&&) = delete;
        AddPositionZMCommand& operator=(const AddPositionZMCommand&) = delete;
        AddPositionZMCommand& operator=(AddPositionZMCommand&&) = delete;
    };
}
