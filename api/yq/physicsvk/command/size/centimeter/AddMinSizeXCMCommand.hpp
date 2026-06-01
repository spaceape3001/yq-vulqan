////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/units.hpp>
#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddMinSizeˣCMCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeˣCMCommand, SizeCommand)
    public:
        AddMinSizeˣCMCommand(const Header&, Centimeter);
        
        static void init_meta();
        
        Centimeter  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeˣCMCommand(const AddMinSizeˣCMCommand&, const Header&);
        AddMinSizeˣCMCommand(const Header&);
        ~AddMinSizeˣCMCommand();

    private:
        Centimeter  m_Δx = 0.0;
        
        AddMinSizeˣCMCommand(const AddMinSizeˣCMCommand&) = delete;
        AddMinSizeˣCMCommand(AddMinSizeˣCMCommand&&) = delete;
        AddMinSizeˣCMCommand& operator=(const AddMinSizeˣCMCommand&) = delete;
        AddMinSizeˣCMCommand& operator=(AddMinSizeˣCMCommand&&) = delete;
    };
}
