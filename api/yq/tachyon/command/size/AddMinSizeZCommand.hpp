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
    class AddMinSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeᶻCommand, SizeCommand)
    public:
        AddMinSizeᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeᶻCommand(const AddMinSizeᶻCommand&, const Header&);
        AddMinSizeᶻCommand(const Header&);
        ~AddMinSizeᶻCommand();

    private:
        double  m_Δz = 0.0;
        
        AddMinSizeᶻCommand(const AddMinSizeᶻCommand&) = delete;
        AddMinSizeᶻCommand(AddMinSizeᶻCommand&&) = delete;
        AddMinSizeᶻCommand& operator=(const AddMinSizeᶻCommand&) = delete;
        AddMinSizeᶻCommand& operator=(AddMinSizeᶻCommand&&) = delete;
    };
}
