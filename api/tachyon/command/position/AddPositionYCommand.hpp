////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʸCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʸCommand, PositionCommand)
    public:
        AddPositionʸCommand(const Header&, double Δy);
    
        static void init_info();
        
        double  Δy() const { return m_Δy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddPositionʸCommand(const AddPositionʸCommand&, const Header&);
        AddPositionʸCommand(const Header&);
        ~AddPositionʸCommand();
        
    private:
        double  m_Δy = 0.0;

        AddPositionʸCommand(const AddPositionʸCommand&) = delete;
        AddPositionʸCommand(AddPositionʸCommand&&) = delete;
        AddPositionʸCommand& operator=(const AddPositionʸCommand&) = delete;
        AddPositionʸCommand& operator=(AddPositionʸCommand&&) = delete;
    };
}
