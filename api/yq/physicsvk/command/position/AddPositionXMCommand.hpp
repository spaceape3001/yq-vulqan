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
    class AddPositionˣMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionˣMCommand, PositionCommand)
    public:
        AddPositionˣMCommand(const Header&, Meter Δx);
    
        static void init_meta();
        
        Meter  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionˣMCommand(const AddPositionˣMCommand&, const Header&);
        AddPositionˣMCommand(const Header&);
        ~AddPositionˣMCommand();

    private:
        Meter  m_Δx = 0.0;
        
        AddPositionˣMCommand(const AddPositionˣMCommand&) = delete;
        AddPositionˣMCommand(AddPositionˣMCommand&&) = delete;
        AddPositionˣMCommand& operator=(const AddPositionˣMCommand&);
        AddPositionˣMCommand& operator=(AddPositionˣMCommand&&);
    };
}
