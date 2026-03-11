////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class SetPositionʸDCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʸDCommand, PositionCommand)
    public:
        SetPositionʸDCommand(const Header&, double);
        
        static void init_meta();
        
        double  y() const { return m_y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʸDCommand(const SetPositionʸDCommand&, const Header&);
        ~SetPositionʸDCommand();
    private:
        double  m_y = 0.0;
        
        SetPositionʸDCommand(const SetPositionʸDCommand&) = delete;
        SetPositionʸDCommand(SetPositionʸDCommand&&) = delete;
        SetPositionʸDCommand& operator=(const SetPositionʸDCommand&) = delete;
        SetPositionʸDCommand& operator=(SetPositionʸDCommand&&) = delete;
    };
}
