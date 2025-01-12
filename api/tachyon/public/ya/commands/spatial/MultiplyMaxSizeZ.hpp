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
    class MultiplyMaxSizeᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyMaxSizeᶻ, SpatialCommand)
    public:
        MultiplyMaxSizeᶻ(const Header&, double);
        
        static void init_info();
        
        double  δz() const { return m_δz; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMaxSizeᶻ(const MultiplyMaxSizeᶻ&, const Header&);
        MultiplyMaxSizeᶻ(const Header&);
        ~MultiplyMaxSizeᶻ();

    private:
        double  m_δz = 0.0;
        
        MultiplyMaxSizeᶻ(const MultiplyMaxSizeᶻ&) = delete;
        MultiplyMaxSizeᶻ(MultiplyMaxSizeᶻ&&) = delete;
        MultiplyMaxSizeᶻ& operator=(const MultiplyMaxSizeᶻ&) = delete;
        MultiplyMaxSizeᶻ& operator=(MultiplyMaxSizeᶻ&&) = delete;
    };
}
