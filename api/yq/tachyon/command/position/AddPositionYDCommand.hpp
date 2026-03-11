////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʸDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʸDCommand, PositionCommand)
    public:
        AddPositionʸDCommand(const Header&, double Δy);
    
        static void init_meta();
        
        double  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPositionʸDCommand(const AddPositionʸDCommand&, const Header&);
        AddPositionʸDCommand(const Header&);
        ~AddPositionʸDCommand();
        
    private:
        double  m_Δy = 0.0;

        AddPositionʸDCommand(const AddPositionʸDCommand&) = delete;
        AddPositionʸDCommand(AddPositionʸDCommand&&) = delete;
        AddPositionʸDCommand& operator=(const AddPositionʸDCommand&) = delete;
        AddPositionʸDCommand& operator=(AddPositionʸDCommand&&) = delete;
    };
}
