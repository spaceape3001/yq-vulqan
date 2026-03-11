////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionᶻDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionᶻDCommand, PositionCommand)
    public:
        AddPositionᶻDCommand(const Header&, double Δz);
    
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        AddPositionᶻDCommand(const AddPositionᶻDCommand&, const Header&);
        AddPositionᶻDCommand(const Header&);
        ~AddPositionᶻDCommand();
        
    private:
        double  m_Δz = 0.0;
        
        AddPositionᶻDCommand(const AddPositionᶻDCommand&) = delete;
        AddPositionᶻDCommand(AddPositionᶻDCommand&&) = delete;
        AddPositionᶻDCommand& operator=(const AddPositionᶻDCommand&) = delete;
        AddPositionᶻDCommand& operator=(AddPositionᶻDCommand&&) = delete;
    };
}
