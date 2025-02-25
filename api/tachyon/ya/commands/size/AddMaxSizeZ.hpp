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
    class AddMaxSizeᶻ : public SizeCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeᶻ, SizeCommand)
    public:
        AddMaxSizeᶻ(const Header&, double);
        
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddMaxSizeᶻ(const AddMaxSizeᶻ&, const Header&);
        AddMaxSizeᶻ(const Header&);
        ~AddMaxSizeᶻ();

    private:
        double  m_Δz = 0.0;
        
        AddMaxSizeᶻ(const AddMaxSizeᶻ&) = delete;
        AddMaxSizeᶻ(AddMaxSizeᶻ&&) = delete;
        AddMaxSizeᶻ& operator=(const AddMaxSizeᶻ&) = delete;
        AddMaxSizeᶻ& operator=(AddMaxSizeᶻ&&) = delete;
    };
}
