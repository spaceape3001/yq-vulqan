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
    class AddPositionᶻMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionᶻMCommand, PositionCommand)
    public:
        AddPositionᶻMCommand(const Header&, Meter Δz);
    
        static void init_meta();
        
        Meter  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddPositionᶻMCommand(const AddPositionᶻMCommand&, const Header&);
        AddPositionᶻMCommand(const Header&);
        ~AddPositionᶻMCommand();
        
    private:
        Meter  m_Δz = 0.0;
        
        AddPositionᶻMCommand(const AddPositionᶻMCommand&) = delete;
        AddPositionᶻMCommand(AddPositionᶻMCommand&&) = delete;
        AddPositionᶻMCommand& operator=(const AddPositionᶻMCommand&) = delete;
        AddPositionᶻMCommand& operator=(AddPositionᶻMCommand&&) = delete;
    };
}
