////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddMaxSizeᶻCommand : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeᶻCommand, SizeCommand)
    public:
        AddMaxSizeᶻCommand(const Header&, double);
        
        static void init_meta();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeᶻCommand(const AddMaxSizeᶻCommand&, const Header&);
        AddMaxSizeᶻCommand(const Header&);
        ~AddMaxSizeᶻCommand();

    private:
        double  m_Δz = 0.0;
        
        AddMaxSizeᶻCommand(const AddMaxSizeᶻCommand&) = delete;
        AddMaxSizeᶻCommand(AddMaxSizeᶻCommand&&) = delete;
        AddMaxSizeᶻCommand& operator=(const AddMaxSizeᶻCommand&) = delete;
        AddMaxSizeᶻCommand& operator=(AddMaxSizeᶻCommand&&) = delete;
    };
}
