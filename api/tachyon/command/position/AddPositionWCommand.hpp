////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʷCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʷCommand, PositionCommand)
    public:
        AddPositionʷCommand(const Header&, double Δw);
    
        static void init_meta();
        
        double  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionʷCommand(const AddPositionʷCommand&, const Header&);
        AddPositionʷCommand(const Header&);
        ~AddPositionʷCommand();

    private:
        double  m_Δw = 0.0;
        
        AddPositionʷCommand(const AddPositionʷCommand&) = delete;
        AddPositionʷCommand(AddPositionʷCommand&&) = delete;
        AddPositionʷCommand& operator=(const AddPositionʷCommand&);
        AddPositionʷCommand& operator=(AddPositionʷCommand&&);
    };
}
