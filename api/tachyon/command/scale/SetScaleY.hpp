////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class SetScaleʸ : public ScaleCommand {
        YQ_OBJECT_DECLARE(SetScaleʸ, ScaleCommand)
    public:
        SetScaleʸ(const Header&, double);
        
        static void init_info();
        
        double  y() const { return m_y; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        SetScaleʸ(const SetScaleʸ&, const Header&);
        ~SetScaleʸ();

    private:
        double m_y;
        
        SetScaleʸ(const SetScaleʸ&) = delete;
        SetScaleʸ(SetScaleʸ&&) = delete;
        SetScaleʸ& operator=(const SetScaleʸ&) = delete;
        SetScaleʸ& operator=(SetScaleʸ&&) = delete;
    };
}
