////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddSizeˣCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeˣCMCommand, SizeCommand)
    public:
        AddSizeˣCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeˣCMCommand(const AddSizeˣCMCommand&, const Header&);
        AddSizeˣCMCommand(const Header&);
        ~AddSizeˣCMCommand();

    private:
        Centimeter  m_Δx = 0.0;
        
        AddSizeˣCMCommand(const AddSizeˣCMCommand&) = delete;
        AddSizeˣCMCommand(AddSizeˣCMCommand&&) = delete;
        AddSizeˣCMCommand& operator=(const AddSizeˣCMCommand&) = delete;
        AddSizeˣCMCommand& operator=(AddSizeˣCMCommand&&) = delete;
    };
}
