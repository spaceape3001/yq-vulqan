////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/spatial/ScaleCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-scale
    class AddScaleˣ : public ScaleCommand {
        YQ_OBJECT_DECLARE(AddScaleˣ, ScaleCommand)
    public:
        AddScaleˣ(const Header&, double);
        
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:
        AddScaleˣ(const AddScaleˣ&, const Header&);
        AddScaleˣ(const Header&);
        ~AddScaleˣ();

    private:
        double  m_Δx = 0.0;
        
        AddScaleˣ(const AddScaleˣ&) = delete;
        AddScaleˣ(AddScaleˣ&&) = delete;
        AddScaleˣ& operator=(const AddScaleˣ&) = delete;
        AddScaleˣ& operator=(AddScaleˣ&&) = delete;
    };
}
