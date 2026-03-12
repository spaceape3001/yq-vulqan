////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeˣMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeˣMCommand, SizeCommand)
    public:
        SetMinSizeˣMCommand(const Header&, Meter);
    
        static void init_meta();
        
        Meter  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeˣMCommand(const Header&);
        SetMinSizeˣMCommand(const SetMinSizeˣMCommand&, const Header&);
        ~SetMinSizeˣMCommand();

    private:
        Meter   m_x = 0.;
        
        SetMinSizeˣMCommand(const SetMinSizeˣMCommand&) = delete;
        SetMinSizeˣMCommand(SetMinSizeˣMCommand&&) = delete;
        SetMinSizeˣMCommand& operator=(const SetMinSizeˣMCommand&) = delete;
        SetMinSizeˣMCommand& operator=(SetMinSizeˣMCommand&&) = delete;
    };
}
