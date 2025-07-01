////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionˣCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionˣCommand, PositionCommand)
    public:
        AddPositionˣCommand(const Header&, double Δx);
    
        static void init_meta();
        
        double  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionˣCommand(const AddPositionˣCommand&, const Header&);
        AddPositionˣCommand(const Header&);
        ~AddPositionˣCommand();

    private:
        double  m_Δx = 0.0;
        
        AddPositionˣCommand(const AddPositionˣCommand&) = delete;
        AddPositionˣCommand(AddPositionˣCommand&&) = delete;
        AddPositionˣCommand& operator=(const AddPositionˣCommand&);
        AddPositionˣCommand& operator=(AddPositionˣCommand&&);
    };
}
