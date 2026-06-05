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
    class AddPositionˣCMCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionˣCMCommand, PositionCommand)
    public:
        AddPositionˣCMCommand(const Header&, Centimeter Δx);
    
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionˣCMCommand(const AddPositionˣCMCommand&, const Header&);
        AddPositionˣCMCommand(const Header&);
        ~AddPositionˣCMCommand();

    private:
        Centimeter  m_Δx = 0.0;
        
        AddPositionˣCMCommand(const AddPositionˣCMCommand&) = delete;
        AddPositionˣCMCommand(AddPositionˣCMCommand&&) = delete;
        AddPositionˣCMCommand& operator=(const AddPositionˣCMCommand&);
        AddPositionˣCMCommand& operator=(AddPositionˣCMCommand&&);
    };
}
