////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyMinSize : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyMinSize, SpatialCommand)
    public:
        MultiplyMinSize(const Header&, double);
        
        static void init_info();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyMinSize(const MultiplyMinSize&, const Header&);
        ~MultiplyMinSize();
        MultiplyMinSize(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyMinSize(const MultiplyMinSize&) = delete;
        MultiplyMinSize(MultiplyMinSize&&) = delete;
        MultiplyMinSize& operator=(const MultiplyMinSize&) = delete;
        MultiplyMinSize& operator=(MultiplyMinSize&&) = delete;
    };
}
