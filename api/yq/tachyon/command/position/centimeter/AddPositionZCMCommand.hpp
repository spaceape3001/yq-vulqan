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
    class AddPositionᶻCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionᶻCMCommand, PositionCommand)
    public:
        AddPositionᶻCMCommand(const Header&, Centimeter Δz);
    
        static void init_meta();
        
        Centimeter  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddPositionᶻCMCommand(const AddPositionᶻCMCommand&, const Header&);
        AddPositionᶻCMCommand(const Header&);
        ~AddPositionᶻCMCommand();
        
    private:
        Centimeter  m_Δz = 0.0;
        
        AddPositionᶻCMCommand(const AddPositionᶻCMCommand&) = delete;
        AddPositionᶻCMCommand(AddPositionᶻCMCommand&&) = delete;
        AddPositionᶻCMCommand& operator=(const AddPositionᶻCMCommand&) = delete;
        AddPositionᶻCMCommand& operator=(AddPositionᶻCMCommand&&) = delete;
    };
}
