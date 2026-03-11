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
    class SetPositionʷDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʷDCommand, PositionCommand)
    public:
        SetPositionʷDCommand(const Header&, double);
        
        static void init_meta();
        
        double  w() const { return m_w; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʷDCommand(const SetPositionʷDCommand&, const Header&);
        ~SetPositionʷDCommand();
        
    private:
        double  m_w = 0.0;
        
        SetPositionʷDCommand(const SetPositionʷDCommand&);
        SetPositionʷDCommand(SetPositionʷDCommand&&);
        SetPositionʷDCommand& operator=(const SetPositionʷDCommand&);
        SetPositionʷDCommand& operator=(SetPositionʷDCommand&&);
    };
}
