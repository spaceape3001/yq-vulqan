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
    class AddPositionXMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionXMCommand, PositionCommand)
    public:
        AddPositionXMCommand(const Header&, Meter Δx);
    
        static void init_meta();
        
        Meter  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionXMCommand(const AddPositionXMCommand&, const Header&);
        AddPositionXMCommand(const Header&);
        ~AddPositionXMCommand();

    private:
        Meter  m_Δx = 0.0;
        
        AddPositionXMCommand(const AddPositionXMCommand&) = delete;
        AddPositionXMCommand(AddPositionXMCommand&&) = delete;
        AddPositionXMCommand& operator=(const AddPositionXMCommand&);
        AddPositionXMCommand& operator=(AddPositionXMCommand&&);
    };
}
