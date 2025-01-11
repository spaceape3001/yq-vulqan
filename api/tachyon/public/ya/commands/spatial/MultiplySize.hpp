////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplySize : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplySize, SpatialCommand)
    public:
        MultiplySize(const Header&, double);
        
        static void init_info();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplySize(const MultiplySize&, const Header&);
        ~MultiplySize();
        MultiplySize(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplySize(const MultiplySize&) = delete;
        MultiplySize(MultiplySize&&) = delete;
        MultiplySize& operator=(const MultiplySize&) = delete;
        MultiplySize& operator=(MultiplySize&&) = delete;
    };
}
