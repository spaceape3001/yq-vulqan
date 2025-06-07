////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddSizeᶻCommand, SizeCommand)
    public:
        AddSizeᶻCommand(const Header&, double);
        
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddSizeᶻCommand(const AddSizeᶻCommand&, const Header&);
        AddSizeᶻCommand(const Header&);
        ~AddSizeᶻCommand();

    private:
        double  m_Δz = 0.0;
        
        AddSizeᶻCommand(const AddSizeᶻCommand&) = delete;
        AddSizeᶻCommand(AddSizeᶻCommand&&) = delete;
        AddSizeᶻCommand& operator=(const AddSizeᶻCommand&) = delete;
        AddSizeᶻCommand& operator=(AddSizeᶻCommand&&) = delete;
    };
}
