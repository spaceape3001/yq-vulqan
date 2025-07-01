////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/PositionCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class SetPositionʸCommand : public PositionCommand {
        YQ_OBJECT_DECLARE(SetPositionʸCommand, PositionCommand)
    public:
        SetPositionʸCommand(const Header&, double);
        
        static void init_meta();
        
        double  y() const { return m_y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetPositionʸCommand(const SetPositionʸCommand&, const Header&);
        ~SetPositionʸCommand();
    private:
        double  m_y = 0.0;
        
        SetPositionʸCommand(const SetPositionʸCommand&) = delete;
        SetPositionʸCommand(SetPositionʸCommand&&) = delete;
        SetPositionʸCommand& operator=(const SetPositionʸCommand&) = delete;
        SetPositionʸCommand& operator=(SetPositionʸCommand&&) = delete;
    };
}
