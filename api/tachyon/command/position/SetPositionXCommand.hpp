////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetPositionˣCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionˣCommand, PositionCommand)
    public:
        SetPositionˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  x() const { return m_x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionˣCommand(const SetPositionˣCommand&, const Header&);
        ~SetPositionˣCommand();
        
    private:
        double  m_x = 0.0;
        
        SetPositionˣCommand(const SetPositionˣCommand&);
        SetPositionˣCommand(SetPositionˣCommand&&);
        SetPositionˣCommand& operator=(const SetPositionˣCommand&);
        SetPositionˣCommand& operator=(SetPositionˣCommand&&);
    };
}
