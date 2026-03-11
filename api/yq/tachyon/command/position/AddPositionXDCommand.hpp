////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class AddPositionˣDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(AddPositionˣDCommand, PositionCommand)
    public:
        AddPositionˣDCommand(const Header&, double Δx);
    
        static void init_meta();
        
        double  Δx() const { return m_Δx; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
    protected:
        
        AddPositionˣDCommand(const AddPositionˣDCommand&, const Header&);
        AddPositionˣDCommand(const Header&);
        ~AddPositionˣDCommand();

    private:
        double  m_Δx = 0.0;
        
        AddPositionˣDCommand(const AddPositionˣDCommand&) = delete;
        AddPositionˣDCommand(AddPositionˣDCommand&&) = delete;
        AddPositionˣDCommand& operator=(const AddPositionˣDCommand&);
        AddPositionˣDCommand& operator=(AddPositionˣDCommand&&);
    };
}
