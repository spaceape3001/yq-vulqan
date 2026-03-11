////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetPositionˣDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionˣDCommand, PositionCommand)
    public:
        SetPositionˣDCommand(const Header&, double);
        
        static void init_meta();
        
        double  x() const { return m_x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionˣDCommand(const SetPositionˣDCommand&, const Header&);
        ~SetPositionˣDCommand();
        
    private:
        double  m_x = 0.0;
        
        SetPositionˣDCommand(const SetPositionˣDCommand&);
        SetPositionˣDCommand(SetPositionˣDCommand&&);
        SetPositionˣDCommand& operator=(const SetPositionˣDCommand&);
        SetPositionˣDCommand& operator=(SetPositionˣDCommand&&);
    };
}
