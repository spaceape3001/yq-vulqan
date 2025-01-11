////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class MultiplyPosition : public SpatialCommand {
        YQ_OBJECT_DECLARE(MultiplyPosition, SpatialCommand)
    public:
        MultiplyPosition(const Header&, double);
        
        static void init_info();
        
        double  δ() const { return m_δ; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        MultiplyPosition(const MultiplyPosition&, const Header&);
        ~MultiplyPosition();
        MultiplyPosition(const Header&);

    private:
        double  m_δ = 0.0;
        
        MultiplyPosition(const MultiplyPosition&) = delete;
        MultiplyPosition(MultiplyPosition&&) = delete;
        MultiplyPosition& operator=(const MultiplyPosition&) = delete;
        MultiplyPosition& operator=(MultiplyPosition&&) = delete;
    };
}
