////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionᶻCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionᶻCommand, PositionCommand)
    public:
        AddPositionᶻCommand(const Header&, double Δz);
    
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddPositionᶻCommand(const AddPositionᶻCommand&, const Header&);
        AddPositionᶻCommand(const Header&);
        ~AddPositionᶻCommand();
        
    private:
        double  m_Δz = 0.0;
        
        AddPositionᶻCommand(const AddPositionᶻCommand&) = delete;
        AddPositionᶻCommand(AddPositionᶻCommand&&) = delete;
        AddPositionᶻCommand& operator=(const AddPositionᶻCommand&) = delete;
        AddPositionᶻCommand& operator=(AddPositionᶻCommand&&) = delete;
    };
}
