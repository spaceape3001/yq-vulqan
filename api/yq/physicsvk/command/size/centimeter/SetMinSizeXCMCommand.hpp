////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's size
    class SetMinSizeˣCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(SetMinSizeˣCMCommand, SizeCommand)
    public:
        SetMinSizeˣCMCommand(const Header&, Centimeter);
    
        static void init_meta();
        
        Centimeter  x() const { return m_x; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetMinSizeˣCMCommand(const Header&);
        SetMinSizeˣCMCommand(const SetMinSizeˣCMCommand&, const Header&);
        ~SetMinSizeˣCMCommand();

    private:
        Centimeter   m_x = 0.;
        
        SetMinSizeˣCMCommand(const SetMinSizeˣCMCommand&) = delete;
        SetMinSizeˣCMCommand(SetMinSizeˣCMCommand&&) = delete;
        SetMinSizeˣCMCommand& operator=(const SetMinSizeˣCMCommand&) = delete;
        SetMinSizeˣCMCommand& operator=(SetMinSizeˣCMCommand&&) = delete;
    };
}
