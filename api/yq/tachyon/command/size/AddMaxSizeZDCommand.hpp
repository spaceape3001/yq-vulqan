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
    class AddMaxSizeᶻDCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeᶻDCommand, SizeCommand)
    public:
        AddMaxSizeᶻDCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeᶻDCommand(const AddMaxSizeᶻDCommand&, const Header&);
        AddMaxSizeᶻDCommand(const Header&);
        ~AddMaxSizeᶻDCommand();

    private:
        double  m_Δz = 0.0;
        
        AddMaxSizeᶻDCommand(const AddMaxSizeᶻDCommand&) = delete;
        AddMaxSizeᶻDCommand(AddMaxSizeᶻDCommand&&) = delete;
        AddMaxSizeᶻDCommand& operator=(const AddMaxSizeᶻDCommand&) = delete;
        AddMaxSizeᶻDCommand& operator=(AddMaxSizeᶻDCommand&&) = delete;
    };
}
