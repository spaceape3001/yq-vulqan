////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-offset
    class SetOffsetʸCommand : public OffsetCommand {
        YQ_OBJECT_DECLARE(SetOffsetʸCommand, OffsetCommand)
    public:
        SetOffsetʸCommand(const Header&, double);
        
        static void init_meta();
        
        double  y() const { return m_y; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetOffsetʸCommand(const SetOffsetʸCommand&, const Header&);
        ~SetOffsetʸCommand();
    private:
        double  m_y = 0.0;
        
        SetOffsetʸCommand(const SetOffsetʸCommand&) = delete;
        SetOffsetʸCommand(SetOffsetʸCommand&&) = delete;
        SetOffsetʸCommand& operator=(const SetOffsetʸCommand&) = delete;
        SetOffsetʸCommand& operator=(SetOffsetʸCommand&&) = delete;
    };
}
