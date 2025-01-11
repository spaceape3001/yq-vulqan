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
    class MultiplySizeᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplySizeᶻ, SpatialCommand)
    public:
        MultiplySizeᶻ(const Header&, double);
        
        static void init_info();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySizeᶻ(const MultiplySizeᶻ&, const Header&);
        MultiplySizeᶻ(const Header&);
        ~MultiplySizeᶻ();

    private:
        double  m_δz = 0.0;
        
        MultiplySizeᶻ(const MultiplySizeᶻ&) = delete;
        MultiplySizeᶻ(MultiplySizeᶻ&&) = delete;
        MultiplySizeᶻ& operator=(const MultiplySizeᶻ&) = delete;
        MultiplySizeᶻ& operator=(MultiplySizeᶻ&&) = delete;
    };
}
