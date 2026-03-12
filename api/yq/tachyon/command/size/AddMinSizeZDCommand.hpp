////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/shape/Size1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddMinSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeᶻDCommand, SizeCommand)
    public:
        AddMinSizeᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeᶻDCommand(const AddMinSizeᶻDCommand&, const Header&);
        AddMinSizeᶻDCommand(const Header&);
        ~AddMinSizeᶻDCommand();

    private:
        double  m_Δz = 0.0;
        
        AddMinSizeᶻDCommand(const AddMinSizeᶻDCommand&) = delete;
        AddMinSizeᶻDCommand(AddMinSizeᶻDCommand&&) = delete;
        AddMinSizeᶻDCommand& operator=(const AddMinSizeᶻDCommand&) = delete;
        AddMinSizeᶻDCommand& operator=(AddMinSizeᶻDCommand&&) = delete;
    };
}
