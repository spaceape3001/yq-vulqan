////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionʷDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionʷDCommand, PositionCommand)
    public:
        AddPositionʷDCommand(const Header&, double Δw);
    
        static void init_meta();
        
        double  Δw() const { return m_Δw; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionʷDCommand(const AddPositionʷDCommand&, const Header&);
        AddPositionʷDCommand(const Header&);
        ~AddPositionʷDCommand();

    private:
        double  m_Δw = 0.0;
        
        AddPositionʷDCommand(const AddPositionʷDCommand&) = delete;
        AddPositionʷDCommand(AddPositionʷDCommand&&) = delete;
        AddPositionʷDCommand& operator=(const AddPositionʷDCommand&);
        AddPositionʷDCommand& operator=(AddPositionʷDCommand&&);
    };
}
