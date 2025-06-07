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
    class SetPositionʷCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʷCommand, PositionCommand)
    public:
        SetPositionʷCommand(const Header&, double);
        
        static void init_info();
        
        double  w() const { return m_w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʷCommand(const SetPositionʷCommand&, const Header&);
        ~SetPositionʷCommand();
        
    private:
        double  m_w = 0.0;
        
        SetPositionʷCommand(const SetPositionʷCommand&);
        SetPositionʷCommand(SetPositionʷCommand&&);
        SetPositionʷCommand& operator=(const SetPositionʷCommand&);
        SetPositionʷCommand& operator=(SetPositionʷCommand&&);
    };
}
