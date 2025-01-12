////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class AddMaxSizeᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(AddMaxSizeᶻ, SpatialCommand)
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
