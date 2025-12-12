////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/OffsetCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-offset
    class SetOffsetˣCommand : public OffsetCommand {
        YQ_OBJECT_DECLARE(SetOffsetˣCommand, OffsetCommand)
    public:
        SetOffsetˣCommand(const Header&, double);
        
        static void init_meta();
        
        double  x() const { return m_x; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetOffsetˣCommand(const SetOffsetˣCommand&, const Header&);
        ~SetOffsetˣCommand();
        
    private:
        double  m_x = 0.0;
        
        SetOffsetˣCommand(const SetOffsetˣCommand&);
        SetOffsetˣCommand(SetOffsetˣCommand&&);
        SetOffsetˣCommand& operator=(const SetOffsetˣCommand&);
        SetOffsetˣCommand& operator=(SetOffsetˣCommand&&);
    };
}
