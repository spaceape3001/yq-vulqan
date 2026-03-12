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
    class AddSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeᶻDCommand, SizeCommand)
    public:
        AddSizeᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeᶻDCommand(const AddSizeᶻDCommand&, const Header&);
        AddSizeᶻDCommand(const Header&);
        ~AddSizeᶻDCommand();

    private:
        double  m_Δz = 0.0;
        
        AddSizeᶻDCommand(const AddSizeᶻDCommand&) = delete;
        AddSizeᶻDCommand(AddSizeᶻDCommand&&) = delete;
        AddSizeᶻDCommand& operator=(const AddSizeᶻDCommand&) = delete;
        AddSizeᶻDCommand& operator=(AddSizeᶻDCommand&&) = delete;
    };
}
