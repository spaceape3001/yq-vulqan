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
    class AddPositionʷMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʷMCommand, PositionCommand)
    public:
        AddPositionʷMCommand(const Header&, Meter Δw);
    
        static void init_meta();
        
        Meter  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionʷMCommand(const AddPositionʷMCommand&, const Header&);
        AddPositionʷMCommand(const Header&);
        ~AddPositionʷMCommand();

    private:
        Meter  m_Δw = 0.0_m;
        
        AddPositionʷMCommand(const AddPositionʷMCommand&) = delete;
        AddPositionʷMCommand(AddPositionʷMCommand&&) = delete;
        AddPositionʷMCommand& operator=(const AddPositionʷMCommand&);
        AddPositionʷMCommand& operator=(AddPositionʷMCommand&&);
    };
}
