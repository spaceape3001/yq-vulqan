////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/SizeCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddMinSizeᶻ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMinSizeᶻ, SizeCommand)
    public:
        AddMinSizeᶻ(const Header&, double);
        
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMinSizeᶻ(const AddMinSizeᶻ&, const Header&);
        AddMinSizeᶻ(const Header&);
        ~AddMinSizeᶻ();

    private:
        double  m_Δz = 0.0;
        
        AddMinSizeᶻ(const AddMinSizeᶻ&) = delete;
        AddMinSizeᶻ(AddMinSizeᶻ&&) = delete;
        AddMinSizeᶻ& operator=(const AddMinSizeᶻ&) = delete;
        AddMinSizeᶻ& operator=(AddMinSizeᶻ&&) = delete;
    };
}
