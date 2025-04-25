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
    class AddScaleʸ : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleʸ, ScaleCommand)
    public:
        AddScaleʸ(const Header&, double);
        
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleʸ(const AddScaleʸ&, const Header&);
        AddScaleʸ(const Header&);
        ~AddScaleʸ();

    private:
        double  m_Δy = 0.0;
        
        AddScaleʸ(const AddScaleʸ&) = delete;
        AddScaleʸ(AddScaleʸ&&) = delete;
        AddScaleʸ& operator=(const AddScaleʸ&) = delete;
        AddScaleʸ& operator=(AddScaleʸ&&) = delete;
    };
}
